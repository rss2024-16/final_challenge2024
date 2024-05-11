import rclpy
from rclpy.node import Node

import cv2
from cv_bridge import CvBridge

import numpy as np
from sensor_msgs.msg import Image
# from geometry_msgs.msg import Point
from vs_msgs.msg import ConeLocationPixel, PixelLocation


class LineDetector(Node):
    def __init__(self):
        super().__init__("line_detector")

        self.crop_scale = 0.1

        self.subscriber = self.create_subscription(Image, "/zed/zed_node/rgb_gray/image_rect_gray", self.callback, 1)

        self.publisher = self.create_publisher(PixelLocation, "/line_location",5)

        self.img_view = self.create_publisher(Image,'/line_image',1)
        self.cropped_img = self.create_publisher(Image,'/cropped',1)

        self.bridge = CvBridge()
        

        # self.threshhold = 220
        # self.callback()
        # img = Image()
        # img = cv2.imread('/home/racecar/racecar_ws/src/final_challenge2024/final_challenge/final_challenge/start_area_cropped.jpg')
        # msg = self.bridge.cv2_to_imgmsg(img, encoding="bgr8")
        # self.callback(msg)

    def get_closest_lines(self,lines,shape):
        midpoint = int(shape[0]//2)
        height = shape[1]
        pose = np.array( [midpoint,height] )

        slopes = np.array( [abs( (yc2-yc1)/(xc2-xc1) ) for xc1,yc1,xc2,yc2 in lines] )
        # if len(lines) > 2:
        lines = lines[(slopes > 0.30)]#change 0.35, right now based off of some measurements
        left_lines = lines[lines[:,0] <= (midpoint)]
        right_lines = lines[lines[:,0] > (midpoint)]

        if len(left_lines) == 0 or len(right_lines) == 0:
            return

        diff_left = left_lines[:,:2] - pose
        diff_right = right_lines[:,:2] - pose
        dist_left = ( (diff_left[:,0])**2 + (diff_left[:,1])**2 ) ** (1/2)
        dist_right = ( (diff_right[:,0])**2 + (diff_right[:,1])**2 ) ** (1/2)

        left_closest = left_lines[np.argmin(dist_left)]
        right_closest = right_lines[np.argmin(dist_right)]

        return left_closest,right_closest


    def callback(self,img_msg):
        '''
        code is basically exact replica of:
        https://docs.opencv.org/3.4/d9/db0/tutorial_hough_lines.html


        cropping is much more dynamic with striping - it essentially gets rid of low slope lines
        for example, if you crop every 60 pixels with line radius 11, you would need a line of
        slope 2.1 to reach the 80 px threshold between the crops

        this basically ensures we do not follow a horizontal line in the middle of the
        camera frame

        it also biases closer lines
        '''
        # self.get_logger().info('Got image')
        t1 = self.get_clock().now().nanoseconds/1e9
        image = self.bridge.imgmsg_to_cv2(img_msg, "bgr8")

        # image = cv2.resize(image,(640,480))

        #360 by 640 by 3

        height,width,_ = image.shape

        # crop_mid_scale = 0.6
        # mid_start = int( midpoint*crop_mid_scale )
        # image[:,mid_start:width-mid_start, :] = 0

        #v = 230
        v = 230

        lower = int((1-self.crop_scale)*v)
        higher = 270
        # image[lower:higher,:,:] = 0
        image[:lower,:,:] = 0
        image[higher:, :,:] = 0

        PIXEL_STEP = 80

        RADIUS = 1


        curved_lines = []

        # start_point = int( .4*width )
        # image[:,0:start_point,:] = 0
        # end_point = int( width - start_point )


        # for x in range(start_point,end_point,PIXEL_STEP):
        #     # curved_points = []
        #     # for y in range(0, height):
        #     #     val = (int(x) + int(RADIUS*np.sin(2*np.pi*y/(height/6))), y)
        #     #     curved_points.append(val)
        #     # cv2.polylines(image, np.array([curved_points]), isClosed=False, color=(0, 0, 0), thickness=11)
        #     # curved_lines.append(curved_points)
        #     cv2.line(image,(x,0),(x,height),color = (0,0,0), thickness=10)
        # cv2.line(image,(350,0),(400,height),color=(0,0,0),thickness=60)
        # cv2.circle(image,(335,height-60),radius=120,color=(0,0,0),thickness=-1)

        # self.get_logger().info(f'{curved_lines}')


        # Convert the curve points to numpy array format
        # curve_points = np.array(curve_points, dtype=np.int32)
        # curved_lines = np.array(curved_lines, dtype=np.int32)

        # Draw the curve
        # for line in curved_lines:
            # self.get_logger().info(f'{line}')

        PIXEL_STEP = 40
        start_point = 310
        end_point = 431

        # for x in range(start_point,end_point,PIXEL_STEP):
        #     cv2.line(image,(x,0),(x,height),color = (0,0,0), thickness=11)

        img_msg = self.bridge.cv2_to_imgmsg(image, encoding="bgr8")
        self.cropped_img.publish(img_msg)
        #"stripe" the image to remove horizontal lines

        midpoint = 350#int( width / 2 )

        OFFSET = 15#-10#30

        # image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        # threshold = 220 
        _, thresh = cv2.threshold(image, 220, 255, cv2.THRESH_BINARY)

        dst = cv2.Canny(thresh,50,200,None,3)

        cdstP = cv2.cvtColor(dst, cv2.COLOR_GRAY2BGR)

        linesP = cv2.HoughLinesP(dst,1,np.pi/180,50,None,60,9) #these parameters work

        if linesP is not None:

            closest = self.get_closest_lines(linesP[:,0],(width,height))
            if closest is None:
                self.get_logger().info('fuck')
                return

                threshold =  200
                _, thresh = cv2.threshold(image, threshold, 255, cv2.THRESH_BINARY)

                dst = cv2.Canny(thresh,50,200,None,3)

                cdstP = cv2.cvtColor(dst, cv2.COLOR_GRAY2BGR)

                linesP = cv2.HoughLinesP(dst,1,np.pi/180,50,None,60,9) #these parameters work

                if linesP is not None:

                    closest = self.get_closest_lines(linesP[:,0],(width,height))

                    if closest is None:
                        return
                    else:
                        left_closest, right_closest = closest
                else:
                    return
            else:
                left_closest,right_closest = closest

            # x1,x2,x3,x4 = right_closest
            # self.get_logger().info(f'slope: {(x4-x2)/(x3-x1)}')
            x1r,y1r,x2r,y2r = right_closest
            x1l,y1l,x2l,y2l = left_closest

            slope_right = (y2r-y1r)/(x2r-x1r)
            slope_left = (y2l-y1l)/(x2l-x1l)
            if abs(slope_right) < 0.50 and abs(slope_left) < 0.50:
                self.get_logger().info('BAD LINE DETECTED')
                # return

            mpr = [ (x1r+x2r)/2, (y1r+y2r)/2 ]
            mpl = [ (x1l+x2l)/2, (y1l+y2l)/2 ]

            msg = PixelLocation()
            msg.u1 = mpr[0]
            msg.u2 = mpl[0]
            msg.v1 = mpr[1]
            msg.v2 = mpl[1]
            self.publisher.publish(msg)

            # self.get_logger().info(f'left slope: {(x1l-x2l)/(y2l-y1l)}')
            # self.get_logger().info(f'right slope: {(x1r-x2r)/(y1r-y2r)}')

            avg = [(mpr[0]+mpl[0])/2, (mpl[1]+mpr[1])/2]

            cv2.line(cdstP, (left_closest[0], left_closest[1]), (left_closest[2], left_closest[3]), (0,0,255), 3, cv2.LINE_AA)
            cv2.line(cdstP, (right_closest[0], right_closest[1]), (right_closest[2], right_closest[3]), (0,0,255), 3, cv2.LINE_AA)

            cv2.circle(cdstP,(int(avg[0]+OFFSET),int(avg[1])),radius=5,color=(255,0,0),thickness=1)
            img_msg = self.bridge.cv2_to_imgmsg(cdstP, encoding="bgr8")
            self.img_view.publish(img_msg)

        # linesP = cv2.HoughLinesP(dst,1,np.pi/180,75,None,50,10)
        # lines = cv2.HoughLines(dst, 1, np.pi / 180, 150, None, 0, 0)
        # print(linesP)
        # PIXEL_THRESHOLD = 50

            # print(linesP[:,0].shape)
            # lines = linesP[:,0]


            # left_lines = lines[lines[:,0] <= midpoint]
            # right_lines = lines[lines[:,0] > midpoint]
            # left_avg = np.mean(left_lines,axis=0)
            # right_avg = np.mean(right_lines,axis=0)

            # nr = np.all(np.isnan(right_avg))
            # nl = np.all(np.isnan(left_avg))

            # if not nr and not nl:
            # xc1,yc1,xc2,yc2 = np.array( (left_closest + right_closest)//2 ).astype(float)
            # else:
            #     self.get_logger().info('fuck')
            #     return


            # if xc2 is not None:

            #     msg = ConeLocationPixel()
            #     msg.u = xc2 #publish to line follower
            #     msg.v = yc2

            #     self.publisher.publish(msg)
            #     view = False
            #     if view:
            #         if linesP is not None:
            #             for i in range(0, len(linesP)):
            #                 l = linesP[i][0]
            #                 cv2.line(cdstP, (l[0], l[1]), (l[2], l[3]), (0,0,255), 3, cv2.LINE_AA)

            # xc1,xc2,yc1,yc2 = np.array( [ np.median(x0), np.median(xf), np.median(y0), np.median(yf) ] ).astype(int)
            # cv2.line(cdstP,(xc1,yc1),(xc2,yc2),(255,0,0),3,cv2.LINE_AA)

            #         # x_start = l
            # #        rho = lines[i][0][0]
            # #        theta = lines[i][0][1]
            # #        a = np.cos(theta)
            # #        b = np.sin(theta)
            # #        x0 = a * rho
            # #        y0 = b * rho
            # #        pt1 = (int(x0 + 1000*(-b)), int(y0 + 1000*(a)))
            # #        pt2 = (int(x0 - 1000*(-b)), int(y0 - 1000*(a)))
            #         cv2.line(cdstP, (l[0], l[1]), (l[2], l[3]), (0,0,255), 3, cv2.LINE_AA)
            # self.get_logger().info(f'Got lines in {self.get_clock().now().nanoseconds/1e9 - t1} seconds')
        # cv2.imwrite('/home/racecar/racecar_ws/src/final_challenge2024/final_challenge/final_challenge/lines.jpg',cdstP)

def main(args=None):
    rclpy.init(args=args)
    detector = LineDetector()
    rclpy.spin(detector)
    rclpy.shutdown()

if __name__=="__main__":
    main()

































































































# import rclpy
# from rclpy.node import Node

# import cv2
# from cv_bridge import CvBridge

# import numpy as np
# from sensor_msgs.msg import Image
# # from geometry_msgs.msg import Point
# from vs_msgs.msg import ConeLocationPixel, PixelLocation


# class LineDetector(Node):
#     def __init__(self):
#         super().__init__("line_detector")

#         self.crop_scale = 0.1

#         self.subscriber = self.create_subscription(Image, "/zed/zed_node/rgb_gray/image_rect_gray", self.callback, 1)

#         self.publisher = self.create_publisher(PixelLocation, "/line_location",5)

#         self.img_view = self.create_publisher(Image,'/line_image',1)
#         self.cropped_img = self.create_publisher(Image,'/cropped',1)

#         self.bridge = CvBridge()
        

#         # self.threshhold = 220
#         # self.callback()
#         # img = Image()
#         # img = cv2.imread('/home/racecar/racecar_ws/src/final_challenge2024/final_challenge/final_challenge/start_area_cropped.jpg')
#         # msg = self.bridge.cv2_to_imgmsg(img, encoding="bgr8")
#         # self.callback(msg)

#     def get_closest_lines(self,lines,shape):
#         midpoint = int(shape[0]//2)
#         height = shape[1]
#         pose = np.array( [midpoint,height] )

#         slopes = np.array( [abs( (yc2-yc1)/(xc2-xc1) ) for xc1,yc1,xc2,yc2 in lines] )
#         lines = lines[(slopes > 0.30)]#change 0.35, right now based off of some measurements
#         left_lines = lines[lines[:,0] <= (midpoint)]
#         right_lines = lines[lines[:,0] > (midpoint)]

#         if len(left_lines) == 0 or len(right_lines) == 0:
#             return

#         diff_left = left_lines[:,:2] - pose
#         diff_right = right_lines[:,:2] - pose
#         dist_left = ( (diff_left[:,0])**2 + (diff_left[:,1])**2 ) ** (1/2)
#         dist_right = ( (diff_right[:,0])**2 + (diff_right[:,1])**2 ) ** (1/2)

#         left_closest = left_lines[np.argmin(dist_left)]
#         right_closest = right_lines[np.argmin(dist_right)]

#         return left_closest,right_closest


#     def callback(self,img_msg):
#         '''
#         code is basically exact replica of:
#         https://docs.opencv.org/3.4/d9/db0/tutorial_hough_lines.html


#         cropping is much more dynamic with striping - it essentially gets rid of low slope lines
#         for example, if you crop every 60 pixels with line radius 11, you would need a line of
#         slope 2.1 to reach the 80 px threshold between the crops

#         this basically ensures we do not follow a horizontal line in the middle of the
#         camera frame

#         it also biases closer lines
#         '''
#         # self.get_logger().info('Got image')
#         t1 = self.get_clock().now().nanoseconds/1e9
#         image = self.bridge.imgmsg_to_cv2(img_msg, "bgr8")

#         # image = cv2.resize(image,(640,480))

#         #360 by 640 by 3

#         height,width,_ = image.shape

#         # crop_mid_scale = 0.6
#         # mid_start = int( midpoint*crop_mid_scale )
#         # image[:,mid_start:width-mid_start, :] = 0

#         #v = 230
#         v = 230

#         lower = int((1-self.crop_scale)*v)
#         higher = 270
#         # image[lower:higher,:,:] = 0
#         image[:lower,:,:] = 0
#         image[higher:, :,:] = 0

#         PIXEL_STEP = 80

#         RADIUS = 1


#         curved_lines = []

#         # start_point = int( .4*width )
#         # image[:,0:start_point,:] = 0
#         # end_point = int( width - start_point )


#         # for x in range(start_point,end_point,PIXEL_STEP):
#         #     # curved_points = []
#         #     # for y in range(0, height):
#         #     #     val = (int(x) + int(RADIUS*np.sin(2*np.pi*y/(height/6))), y)
#         #     #     curved_points.append(val)
#         #     # cv2.polylines(image, np.array([curved_points]), isClosed=False, color=(0, 0, 0), thickness=11)
#         #     # curved_lines.append(curved_points)
#         #     cv2.line(image,(x,0),(x,height),color = (0,0,0), thickness=10)
#         # cv2.line(image,(350,0),(400,height),color=(0,0,0),thickness=60)
#         # cv2.circle(image,(335,height-60),radius=120,color=(0,0,0),thickness=-1)

#         # self.get_logger().info(f'{curved_lines}')


#         # Convert the curve points to numpy array format
#         # curve_points = np.array(curve_points, dtype=np.int32)
#         # curved_lines = np.array(curved_lines, dtype=np.int32)

#         # Draw the curve
#         # for line in curved_lines:
#             # self.get_logger().info(f'{line}')

#         PIXEL_STEP = 40
#         start_point = 310
#         end_point = 431

#         # for x in range(start_point,end_point,PIXEL_STEP):
#         #     cv2.line(image,(x,0),(x,height),color = (0,0,0), thickness=11)

#         img_msg = self.bridge.cv2_to_imgmsg(image, encoding="bgr8")
#         self.cropped_img.publish(img_msg)
#         #"stripe" the image to remove horizontal lines

#         midpoint = 350#int( width / 2 )

#         OFFSET = 15#-10#30

#         # image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
#         # threshold = 220 
#         _, thresh = cv2.threshold(image, 220, 255, cv2.THRESH_BINARY)

#         dst = cv2.Canny(thresh,50,200,None,3)

#         cdstP = cv2.cvtColor(dst, cv2.COLOR_GRAY2BGR)

#         linesP = cv2.HoughLinesP(dst,1,np.pi/180,50,None,60,9) #these parameters work

#         if linesP is not None:

#             closest = self.get_closest_lines(linesP[:,0],(width,height))
#             if closest is None:
#                 self.get_logger().info('fuck')
#                 return

#                 # threshold =  200
#                 # _, thresh = cv2.threshold(image, threshold, 255, cv2.THRESH_BINARY)

#                 # dst = cv2.Canny(thresh,50,200,None,3)

#                 # cdstP = cv2.cvtColor(dst, cv2.COLOR_GRAY2BGR)

#                 # linesP = cv2.HoughLinesP(dst,1,np.pi/180,50,None,60,9) #these parameters work

#                 # if linesP is not None:

#                 #     closest = self.get_closest_lines(linesP[:,0],(width,height))

#                 #     if closest is None:
#                 #         return
#                 #     else:
#                 #         left_closest, right_closest = closest
#                 # else:
#                 #     return
#             else:
#                 left_closest,right_closest = closest

#             # x1,x2,x3,x4 = right_closest
#             # self.get_logger().info(f'slope: {(x4-x2)/(x3-x1)}')
#             x1r,y1r,x2r,y2r = right_closest
#             x1l,y1l,x2l,y2l = left_closest

#             slope_right = (y2r-y1r)/(x2r-x1r)
#             slope_left = (y2l-y1l)/(x2l-x1l)
#             if abs(slope_right) < 0.50 and abs(slope_left) < 0.50:
#                 self.get_logger().info('BAD LINE DETECTED')
#                 # return

#             mpr = [ (x1r+x2r)/2, (y1r+y2r)/2 ]
#             mpl = [ (x1l+x2l)/2, (y1l+y2l)/2 ]

#             msg = PixelLocation()
#             msg.u1 = mpr[0]
#             msg.u2 = mpl[0]
#             msg.v1 = mpr[1]
#             msg.v2 = mpl[1]
#             self.publisher.publish(msg)

#             # self.get_logger().info(f'left slope: {(x1l-x2l)/(y2l-y1l)}')
#             # self.get_logger().info(f'right slope: {(x1r-x2r)/(y1r-y2r)}')

#             avg = [(mpr[0]+mpl[0])/2, (mpl[1]+mpr[1])/2]

#             cv2.line(cdstP, (left_closest[0], left_closest[1]), (left_closest[2], left_closest[3]), (0,0,255), 3, cv2.LINE_AA)
#             cv2.line(cdstP, (right_closest[0], right_closest[1]), (right_closest[2], right_closest[3]), (0,0,255), 3, cv2.LINE_AA)

#             cv2.circle(cdstP,(int(avg[0]+OFFSET),int(avg[1])),radius=5,color=(255,0,0),thickness=1)
#             img_msg = self.bridge.cv2_to_imgmsg(cdstP, encoding="bgr8")
#             self.img_view.publish(img_msg)

#         # linesP = cv2.HoughLinesP(dst,1,np.pi/180,75,None,50,10)
#         # lines = cv2.HoughLines(dst, 1, np.pi / 180, 150, None, 0, 0)
#         # print(linesP)
#         # PIXEL_THRESHOLD = 50

#             # print(linesP[:,0].shape)
#             # lines = linesP[:,0]


#             # left_lines = lines[lines[:,0] <= midpoint]
#             # right_lines = lines[lines[:,0] > midpoint]
#             # left_avg = np.mean(left_lines,axis=0)
#             # right_avg = np.mean(right_lines,axis=0)

#             # nr = np.all(np.isnan(right_avg))
#             # nl = np.all(np.isnan(left_avg))

#             # if not nr and not nl:
#             # xc1,yc1,xc2,yc2 = np.array( (left_closest + right_closest)//2 ).astype(float)
#             # else:
#             #     self.get_logger().info('fuck')
#             #     return


#             # if xc2 is not None:

#             #     msg = ConeLocationPixel()
#             #     msg.u = xc2 #publish to line follower
#             #     msg.v = yc2

#             #     self.publisher.publish(msg)
#             #     view = False
#             #     if view:
#             #         if linesP is not None:
#             #             for i in range(0, len(linesP)):
#             #                 l = linesP[i][0]
#             #                 cv2.line(cdstP, (l[0], l[1]), (l[2], l[3]), (0,0,255), 3, cv2.LINE_AA)

#             # xc1,xc2,yc1,yc2 = np.array( [ np.median(x0), np.median(xf), np.median(y0), np.median(yf) ] ).astype(int)
#             # cv2.line(cdstP,(xc1,yc1),(xc2,yc2),(255,0,0),3,cv2.LINE_AA)

#             #         # x_start = l
#             # #        rho = lines[i][0][0]
#             # #        theta = lines[i][0][1]
#             # #        a = np.cos(theta)
#             # #        b = np.sin(theta)
#             # #        x0 = a * rho
#             # #        y0 = b * rho
#             # #        pt1 = (int(x0 + 1000*(-b)), int(y0 + 1000*(a)))
#             # #        pt2 = (int(x0 - 1000*(-b)), int(y0 - 1000*(a)))
#             #         cv2.line(cdstP, (l[0], l[1]), (l[2], l[3]), (0,0,255), 3, cv2.LINE_AA)
#             # self.get_logger().info(f'Got lines in {self.get_clock().now().nanoseconds/1e9 - t1} seconds')
#         # cv2.imwrite('/home/racecar/racecar_ws/src/final_challenge2024/final_challenge/final_challenge/lines.jpg',cdstP)

# def main(args=None):
#     rclpy.init(args=args)
#     detector = LineDetector()
#     rclpy.spin(detector)
#     rclpy.shutdown()

# if __name__=="__main__":
#     main()
