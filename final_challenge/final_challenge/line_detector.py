import rclpy
from rclpy.node import Node

import cv2
from cv_bridge import CvBridge

import numpy as np
from sensor_msgs.msg import Image

class LineDetector(Node):
    def __init__(self):
        super().__init__("line_detector")
        # self.subscriber = self.create_subscription(Image, "/zed/zed_node/rgb/image_rect_color", self.callback, 1)
        self.bridge = CvBridge()
        # self.callback()
        # img = Image()
        img = cv2.imread('/home/racecar/racecar_ws/src/final_challenge2024/final_challenge/final_challenge/start_area_cropped.jpg')
        msg = self.bridge.cv2_to_imgmsg(img, encoding="bgr8")
        self.callback(msg)


    def callback(self,img_msg):
        '''
        code is basically exact replica of:
        https://docs.opencv.org/3.4/d9/db0/tutorial_hough_lines.html

        '''
        t1 = self.get_clock().now().nanoseconds/1e9
        image = self.bridge.imgmsg_to_cv2(img_msg, "bgr8")

        height,width,_ = image.shape
        # print(image.shape)
        midpoint = int( width / 2 )

        gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        _, thresh = cv2.threshold(gray, 200, 255, cv2.THRESH_BINARY)

        dst = cv2.Canny(thresh,50,200,None,3)

        cdstP = cv2.cvtColor(dst, cv2.COLOR_GRAY2BGR)
        # cdstP = np.copy(cdst)

        linesP = cv2.HoughLinesP(dst,1,np.pi/180,50,None,50,10) #these parameters work
        # linesP = cv2.HoughLinesP(dst,1,np.pi/180,75,None,50,10)
        # lines = cv2.HoughLines(dst, 1, np.pi / 180, 150, None, 0, 0)
        # print(linesP)
        # PIXEL_THRESHOLD = 50

        # print(linesP[:,0].shape)
        lines = linesP[:,0]

        left_lines = lines[lines[:,0] <= midpoint]
        right_lines = lines[lines[:,0] > midpoint]
        left_avg = np.mean(left_lines,axis=0)
        right_avg = np.mean(right_lines,axis=0)

        xc1,yc1,xc2,yc2 = np.array( (left_avg + right_avg)//2 ).astype(int)
        # xc1,xc2,yc1,yc2 = np.array( [ np.median(x0), np.median(xf), np.median(y0), np.median(yf) ] ).astype(int)
        cv2.line(cdstP,(xc1,yc1),(xc2,yc2),(255,0,0),3,cv2.LINE_AA)

        if linesP is not None:
            for i in range(0, len(linesP)):
                l = linesP[i][0]

                # x_start = l
        #        rho = lines[i][0][0]
        #        theta = lines[i][0][1]
        #        a = np.cos(theta)
        #        b = np.sin(theta)
        #        x0 = a * rho
        #        y0 = b * rho
        #        pt1 = (int(x0 + 1000*(-b)), int(y0 + 1000*(a)))
        #        pt2 = (int(x0 - 1000*(-b)), int(y0 - 1000*(a)))
                cv2.line(cdstP, (l[0], l[1]), (l[2], l[3]), (0,0,255), 3, cv2.LINE_AA)
        self.get_logger().info(f'Got lines in {self.get_clock().now().nanoseconds/1e9 - t1} seconds')
        cv2.imwrite('/home/racecar/racecar_ws/src/final_challenge2024/final_challenge/final_challenge/lines.jpg',cdstP)

def main(args=None):
    rclpy.init(args=args)
    detector = LineDetector()
    rclpy.spin(detector)
    rclpy.shutdown()

if __name__=="__main__":
    main()