import rclpy
from rclpy.node import Node

import cv2
from cv_bridge import CvBridge, CvBridgeError

import numpy as np
from sensor_msgs.msg import Image
from detector import StopSignDetector
from final_challenge2024.msg import StopSign

class SignDetector(Node):
    def __init__(self):
        super().__init__("stop_detector")
        self.detector = StopSignDetector()
        self.publisher = None #TODO
        self.subscriber = self.create_subscription(Image, "/zed/zed_node/rgb/image_rect_color", self.callback, 1)
        self.bridge = CvBridge()

        self.get_logger().info("Stop Detector Initialized")
        self.publisher = self.create_publisher(StopSign,"/stop",1)

    def callback(self, img_msg):
        # Process image with CV Bridge
        image = self.bridge.imgmsg_to_cv2(img_msg, "bgr8")
        is_stop, location = self.detector.predict(image)
        msg = StopSign()
        msg.data = is_stop
        self.publisher.publish(self.publisher)

def main(args=None):
    rclpy.init(args=args)
    detector = SignDetector()
    rclpy.spin(detector)
    rclpy.shutdown()

if __name__=="__main__":
    main()