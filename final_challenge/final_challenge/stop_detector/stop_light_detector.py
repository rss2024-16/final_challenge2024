#!/usr/bin/env python

import rclpy
from rclpy.node import Node
import numpy as np
import cv2
from cv_bridge import CvBridge, CvBridgeError

from sensor_msgs.msg import Image
from geometry_msgs.msg import Point #geometry_msgs not in CMake file
from fc_msgs.msg import StopLightPixel

from std_msgs.msg import Float32


# import your color segmentation algorithm; call this function in ros_image_callback!
from stop_light_segmentation import sl_color_segmentation

class StopLightDetector(Node):
   """
   A class for applying your cone detection algorithms to the real robot.
   Subscribes to: /zed/zed_node/rgb/image_rect_color (Image) : the live RGB image from the onboard ZED camera.
   Publishes to: /relative_cone_px (StopLightPixel) : the coordinates of the cone in the image frame (units are pixels).
   """
   def __init__(self):
       super().__init__("stoplight_detector")
       # toggle line follower vs cone parker
       self.LineFollower = False

       # Subscribe to ZED camera RGB frames
       self.stoplight_pub = self.create_publisher(StopLightPixel, "/relative_stoplight_px", 10)
       self.image_sub = self.create_subscription(Image, "/zed/zed_node/rgb/image_rect_color", self.image_callback, 5)
       self.debug_pub = self.create_publisher(Image, "/stoplight_debug_img", 10)
       self.dist_pub = self.create_publisher(Float32,'/look_ahead',10)
       self.bridge = CvBridge() # Converts between ROS images and OpenCV Images

       self.get_logger().info("Stop Light Detector Initialized")

   def image_callback(self, image_msg):
       # Apply your imported color segmentation function (cd_color_segmentation) to the image msg here
       # From your bounding box, take the center pixel on the bottom
       # (We know this pixel corresponds to a point on the ground plane)
       # publish this pixel (u, v) to the /relative_cone_px topic; the homography transformer will
       # convert it to the car frame.


       #################################


       image = self.bridge.imgmsg_to_cv2(image_msg, "bgr8")

       #344,178.5
       height = image.shape[1]

       look_ahead = 2.5
       self.dist_pub.publish(float(look_ahead))
       v = self.get_parameter('look_ahead_v').value

       if v == 0:
           v = 168.7

    #    lower = int(.9*v)
       upper = int(1.1*v)
       if upper > height:
           upper = height
       # image_cropped = image[lower:upper,:,:]
       image_copy = np.copy(image)
    #    image_copy[0:lower,:,:] = 0
       image_copy[upper:,:,:] = 0

       x, y, w, h, img = sl_color_segmentation(image_copy,None)

       if x is not None:
           #send the bottom center pixel
           center_pixel = StopLightPixel()
           center_pixel.u = float(x + w/2)
           center_pixel.v = float(y + h/2)

           self.stoplight_pub.publish(center_pixel)

           debug_msg = self.bridge.cv2_to_imgmsg(img, "bgr8")
           self.debug_pub.publish(debug_msg)


def main(args=None):
   rclpy.init(args=args)
   cone_detector = StopLightDetector()
   rclpy.spin(cone_detector)
   rclpy.shutdown()


if __name__ == '__main__':
   main()
