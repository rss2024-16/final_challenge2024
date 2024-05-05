import rclpy
from rclpy.node import Node

import cv2
from cv_bridge import CvBridge

import numpy as np
from sensor_msgs.msg import Image
# from geometry_msgs.msg import Point
from vs_msgs.msg import ConeLocationPixel
# from vs_msgs.srv import UvToXy

class LineDetector(Node):
    def __init__(self):
        super().__init__("line_detector")

        self.crop_scale = 0.1

        self.subscriber = self.create_subscription(Image, "/zed/zed_node/rgb_gray/image_rect_gray", self.callback, 1)
        
        self.publisher = self.create_publisher(ConeLocationPixel,"/relative_cone_px",5)

        self.img_view = self.create_publisher(Image,'/line_image',1)
        self.cropped_img = self.create_publisher(Image,'/cropped',1)

        # self.client = self.create_client(UvToXy,'uv_to_xy')
        # self.req = UvToXy.Request()
        
        self.bridge = CvBridge()
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
        lines = lines[(slopes > 0.2)]
        left_lines = lines[lines[:,0] <= midpoint]
        right_lines = lines[lines[:,0] > midpoint]

        diff_left = left_lines[:,:2] - pose
        diff_right = right_lines[:,:2] - pose
        dist_left = ( (diff_left[:,0])**2 + (diff_left[:,1])**2 ) ** (1/2)
        dist_right = ( (diff_right[:,0])**2 + (diff_right[:,1])**2 ) ** (1/2)

        left_closest = left_lines[np.argmin(dist_left)]
        right_closest = right_lines[np.argmin(dist_right)]

        return left_closest,right_closest
    
    # def send_request(self,u,v):
    #     self.req.u = int(u)
    #     self.req.v = int(v)

    #     self.future = self.client.call(self.req)
    #     # self.get_logger().info('sent call')
    #     # rclpy.spin_until_future_complete(self,self.future)
    #     # rclpy.spin_once(self.future)
    #     self.get_logger().info('received response')
    #     res = self.future.result()
    #     return res.x,res.y

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
        self.get_logger().info('Got image')
        t1 = self.get_clock().now().nanoseconds/1e9
        image = self.bridge.imgmsg_to_cv2(img_msg, "bgr8")

        image = cv2.resize(image,(640,480))

        height,width,_ = image.shape

        # midpoint = width // 2
        v = 100

        lower = int((1-self.crop_scale)*v)
        image[:lower,:,:] = 0

        PIXEL_STEP = 80

        RADIUS = 1


        curved_lines = []

        start_point = int( .25*width )
        # image[:,0:start_point,:] = 0
        end_point = int( width - start_point )

        
        for x in range(start_point,end_point,PIXEL_STEP):
            # curved_points = []
            # for y in range(0, height):
            #     val = (int(x) + int(RADIUS*np.sin(2*np.pi*y/(height/6))), y)
            #     curved_points.append(val)
            # cv2.polylines(image, np.array([curved_points]), isClosed=False, color=(0, 0, 0), thickness=11)
            # curved_lines.append(curved_points)
            cv2.line(image,(x,0),(x,height),color = (0,0,0), thickness=10)

        # self.get_logger().info(f'{curved_lines}')


        # Convert the curve points to numpy array format
        # curve_points = np.array(curve_points, dtype=np.int32)
        # curved_lines = np.array(curved_lines, dtype=np.int32)

        # Draw the curve
        # for line in curved_lines:
            # self.get_logger().info(f'{line}')

        img_msg = self.bridge.cv2_to_imgmsg(image, encoding="bgr8")
        self.cropped_img.publish(img_msg)
        #"stripe" the image to remove horizontal lines

        midpoint = int( width / 2 )

        image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        
        _, thresh = cv2.threshold(image, 200, 255, cv2.THRESH_BINARY)

        dst = cv2.Canny(thresh,50,200,None,3)

        cdstP = cv2.cvtColor(dst, cv2.COLOR_GRAY2BGR)

        linesP = cv2.HoughLinesP(dst,1,np.pi/180,50,None,80,9) #these parameters work

        if linesP is not None:

            closest = self.get_closest_lines(linesP[:,0],(width,height))
            if closest is None:
                self.get_logger().info('fuck')
                return
            else:
                left_closest,right_closest = closest
            
            xc1r,yc1r,xc2r,yc2r = right_closest
            xc1l,yc1l,xc2l,yc2l = left_closest

            avg = [ (xc2r+xc2l)/2, (yc2l+yc2r)/2 ]



            msg = ConeLocationPixel()
            msg.u = float(avg[0]) #publish to homography transformer
            msg.v = float(avg[1])

            self.publisher.publish(msg)

            

            cv2.line(cdstP, (left_closest[0], left_closest[1]), (left_closest[2], left_closest[3]), (0,0,255), 3, cv2.LINE_AA)
            cv2.line(cdstP, (right_closest[0], right_closest[1]), (right_closest[2], right_closest[3]), (0,0,255), 3, cv2.LINE_AA)

            cv2.circle(cdstP,(int(avg[0]),int(avg[1])),radius=5,color=(255,0,0),thickness=1)
            img_msg = self.bridge.cv2_to_imgmsg(cdstP, encoding="bgr8")
            self.img_view.publish(img_msg)

            view = False
            if view:
                if linesP is not None:
                    for i in range(0, len(linesP)):
                        l = linesP[i][0]
                        cv2.line(cdstP, (l[0], l[1]), (l[2], l[3]), (0,0,255), 3, cv2.LINE_AA)

            self.get_logger().info(f'Got lines in {self.get_clock().now().nanoseconds/1e9 - t1} seconds')
        # cv2.imwrite('/home/racecar/racecar_ws/src/final_challenge2024/final_challenge/final_challenge/lines.jpg',cdstP)

def main(args=None):
    rclpy.init(args=args)
    detector = LineDetector()
    rclpy.spin(detector)
    rclpy.shutdown()

if __name__=="__main__":
    main()