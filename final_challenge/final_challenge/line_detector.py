import rclpy
from rclpy.node import Node

import cv2
from cv_bridge import CvBridge

import numpy as np
from sensor_msgs.msg import Image
# from geometry_msgs.msg import Point
from vs_msgs.msg import ConeLocation
from visual_interface.srv import UvToXy

class LineDetector(Node):
    def __init__(self):
        super().__init__("line_detector")

        self.crop_scale = 0.1

        self.subscriber = self.create_subscription(Image, "/zed/zed_node/rgb_gray/image_rect_gray", self.callback, 1)
        
        self.publisher = self.create_publisher(ConeLocationPixel,'/relative_cone',5)

        self.img_view = self.create_publisher(Image,'/line_image',1)

        self.client = self.create_client(UvToXy,'uv_to_xy')
        self.req = UvToXy.Request()
        
        self.bridge = CvBridge()
        # self.callback()
        # img = Image()
        # img = cv2.imread('/home/racecar/racecar_ws/src/final_challenge2024/final_challenge/final_challenge/start_area_cropped.jpg')
        # msg = self.bridge.cv2_to_imgmsg(img, encoding="bgr8")
        # self.callback(msg)
    
    def get_closest_lines(self,lines,shape):
        midpoint = int(shape[0]//2)
        height = shape[1]

        slopes = np.array( [abs( (yc2-yc1)/(xc2-xc1) ) for xc1,yc1,xc2,yc2 in lines] )
        lines = lines[(slopes > 0.2)]
        left_lines = lines[lines[:,0] <= midpoint]
        right_lines = lines[lines[:,0] > midpoint]

        if len(left_lines) == 0 or len(right_lines) == 0:
            return

        pose = np.array( [midpoint,height] )

        dist = lambda p1,p2: ( (p1[0]-p2[0])**2 + (p1[1]-p2[1])**2 )**(1/2)

        left_closest = None
        left_distance = float('inf')
        right_closest = None
        right_distance = float('inf')

        for ll in left_lines:
            xc1,yc1,xc2,yc2 = ll
            d = dist( pose, (xc1,yc1) )
            if d < left_distance:
                left_closest = ll
                left_distance = d

        for rl in right_lines:
            xc1,yc1,xc2,yc2 = rl
            d = dist( pose, (xc1,yc1) )
            if d < right_distance:
                right_closest = rl
                right_distance = d

        return left_closest,right_closest
    
    def send_request(self,u,v):
        self.req.u = u
        self.req.v = v

        self.future = self.client.call_async(self.req)
        rclpy.spin_until_future_complete(self,self.future)
        res = self.future.result()
        return res.x,res.y

    def callback(self,img_msg):
        '''
        code is basically exact replica of:
        https://docs.opencv.org/3.4/d9/db0/tutorial_hough_lines.html

        '''
        self.get_logger().info('Got image')
        t1 = self.get_clock().now().nanoseconds/1e9
        image = self.bridge.imgmsg_to_cv2(img_msg, "bgr8")

        height,width,_ = image.shape

        midpoint = width // 2
        crop_mid_scale = 0.6
        mid_start = int( midpoint*crop_mid_scale )
        image[:,mid_start:width-mid_start, :] = 0

        v = 200

        lower = int((1-self.crop_scale)*v)
        # # upper = int((1+self.crop_scale)*v)
        # upper = height
        # if upper > height:
        #     upper = height

        # # image_copy = np.copy(image)
        image[:lower,:,:] = 0
        # image[upper:,:,:] = 0        

        # crop_sides = int(width * .2)
        # # crop_height = int(height // 2)
        # # image[:crop_height, :, :] = 0
        # image[:,:crop_sides, :] = 0
        # image[:,width-crop_sides:, :] = 0
        # print(image.shape)

        # image = image[(image[:,0,])>0,(image[:,1])>0,:]
        # width = image.shape[0]
        midpoint = int( width / 2 )

        # image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        _, thresh = cv2.threshold(image, 200, 255, cv2.THRESH_BINARY)

        dst = cv2.Canny(thresh,50,200,None,3)

        # if not np.isnan(dst):

        cdstP = cv2.cvtColor(dst, cv2.COLOR_GRAY2BGR)

        linesP = cv2.HoughLinesP(dst,1,np.pi/180,50,None,50,10) #these parameters work

        if linesP is not None:

            closest = self.get_closest_lines(linesP[:,0],(width,height))
            if closest is None:
                self.get_logger().info('fuck')
                return
            else:
                left_closest,right_closest = closest
            
            # x1,x2,x3,x4 = right_closest
            # self.get_logger().info(f'slope: {(x4-x2)/(x3-x1)}')
            xc1r,yc1r,xc2r,yc2r = right_closest
            xc1l,yc1l,xc2l,yc2l = left_closest

            xr,yr = self.send_request(xc1r,yc1r)
            xl,yl = self.send_request(xc1l,yc1l)
            avg = [ (xr+xl)/2, (yr+yl)/2 ]

            msg = ConeLocation()
            msg.x = avg[0] #publish to line follower
            msg.y = avg[1]

            self.publisher.publish(msg)

            

            cv2.line(cdstP, (left_closest[0], left_closest[1]), (left_closest[2], left_closest[3]), (0,0,255), 3, cv2.LINE_AA)
            cv2.line(cdstP, (right_closest[0], right_closest[1]), (right_closest[2], right_closest[3]), (0,0,255), 3, cv2.LINE_AA)
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

            #     cv2.circle(cdstP,(int(xc2),int(yc2)),radius=5,color=(255,0,0),thickness=1)
            #     img_msg = self.bridge.cv2_to_imgmsg(cdstP, encoding="bgr8")
            #     self.img_view.publish(img_msg)

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
            self.get_logger().info(f'Got lines in {self.get_clock().now().nanoseconds/1e9 - t1} seconds')
        # cv2.imwrite('/home/racecar/racecar_ws/src/final_challenge2024/final_challenge/final_challenge/lines.jpg',cdstP)

def main(args=None):
    rclpy.init(args=args)
    detector = LineDetector()
    rclpy.spin(detector)
    rclpy.shutdown()

if __name__=="__main__":
    main()