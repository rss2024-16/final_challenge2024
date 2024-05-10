import rclpy
from rclpy.node import Node

import cv2
from cv_bridge import CvBridge, CvBridgeError

import numpy as np
from sensor_msgs.msg import Image
from final_challenge.stop_detector.detector import Detector
from fc_msgs.msg import StopSign

from vs_msgs.srv import UvToXy

class SignDetector(Node):
    def __init__(self):
        super().__init__("stop_detector")
        self.detector = Detector('stop sign')
        self.subscriber = self.create_subscription(Image, "/zed/zed_node/rgb/image_rect_color", self.callback, 5)
        # self.publisher = self.create_publisher(StopSign,"/stop",1)
        self.bridge = CvBridge()
        self.box_publisher = self.create_publisher(Image,"/stoplight_bb",1)

        self.get_logger().info("Stop Detector Initialized")

    def callback(self, img_msg):

        # Process image with CV Bridge
        image = self.bridge.imgmsg_to_cv2(img_msg, "bgr8")
        is_stop, location = self.detector.predict(image)
        # msg = StopSign()
        # msg.is_stop = is_stop
        #this probs needs debugging
        location = [int(coord) for coord in location]

        # msg.bounding_box = location
        # self.publisher.publish(msg)

        img = cv2.rectangle(image, (location[0], location[1]), (location[2], location[3]), (0,0,255), 10)

        stop_bb_msg = self.bridge.cv2_to_imgmsg(img, "bgr8")

        self.box_publisher.publish(stop_bb_msg)


def main(args=None):
    rclpy.init(args=args)
    detector = SignDetector()
    rclpy.spin(detector)
    rclpy.shutdown()

if __name__=="__main__":
    main()
