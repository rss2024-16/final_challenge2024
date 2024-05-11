import rclpy
from rclpy.node import Node

import cv2
from cv_bridge import CvBridge, CvBridgeError

import numpy as np
from sensor_msgs.msg import Image
from final_challenge.stop_detector.detector import Detector
import time
from nav_msgs.msg import Odometry
from ackermann_msgs.msg import AckermannDriveStamped

from enum import Enum

class State(Enum):
    DETECT = 1
    WAIT = 2

class LightDetector(Node):
    def __init__(self):
        super().__init__("light_detector")
        self.detector = Detector("traffic light")

        self.image_sub = self.create_subscription(Image, "/zed/zed_node/rgb/image_rect_color", self.image_callback, 5)
        self.pose_sub = self.create_subscription(Odometry, "/pf/pose/odom", self.pose_callback, 1)
        self.sub_navigation = self.create_subscription(AckermannDriveStamped, "/vesc/input/navigation", self.navigation_callback, 10)

        self.box_publisher = self.create_publisher(Image,"/stoplight_debug_img",10)
        self.traffic_light_publisher = self.create_publisher(Image,"/stoplight_debug_img_2",10)
        self.safety_pub = self.create_publisher(AckermannDriveStamped, "/vesc/low_level/input/safety", 10)
        self.bridge = CvBridge()

        self.stoplights = [(-10.16142463684082,16.551956176757812),
                            (-32.105144500732422,33.97337341308594),
                            (-54.410980224609375,22.996463775634766)]

        self.ON_DISTANCE = 2.5

        self.pose = (0.0, 0.0)
        self.time_elapsed = 0.0

        self.curr_speed = 0
        self.curr_steer_angle = 0

        self.start_time = 0
        self.end_time = 0
        self.buffer = 2 #seconds
        self.state = State.DETECT

        self.get_logger().info("Stop Light Detector Initialized")

    def navigation_callback(self, msg):
        self.curr_speed = msg.drive.speed
        self.curr_steer_angle = msg.drive.steering_angle

    def pose_callback(self, odometry_msg):
        # Unpack the odom message
        x = odometry_msg.pose.pose.position.x
        y = odometry_msg.pose.pose.position.y

        self.pose = (x, y)

    def image_callback(self, img_msg):
        self.get_logger().info(f'{self.state}')
        # Minimum distance from robot to each stoplight
        min_dist = min(np.sqrt((self.pose[0] - x_i)**2 + (self.pose[1] - y_i)**2) for x_i, y_i in self.stoplights)
        
        if min_dist <= self.ON_DISTANCE:
        # if True:

            # Slow down
            if self.state == State.DETECT:
                slow_cmd = AckermannDriveStamped()
                slow_cmd.drive.speed = max(self.curr_speed / 2, 1)
                slow_cmd.drive.steering_angle = self.curr_steer_angle
                self.safety_pub.publish(slow_cmd)

            if self.state == State.WAIT:
                if time.time() < self.end_time:
                    stop_cmd = AckermannDriveStamped()
                    stop_cmd.drive.speed = 0.0
                    # stop_cmd.drive.steering_angle = 0.0
                    self.safety_pub.publish(stop_cmd)
                else:
                    self.state = State.DETECT

            # Process image with CV Bridge
            image = self.bridge.imgmsg_to_cv2(img_msg, "bgr8")

            # Crazy ml shit
            is_stop, location = self.detector.predict(image)
            location = [int(coord) for coord in location]

            if is_stop:
                # BOTTOM:TOP, LEFT:RIGHT, 
                segment_img = image[location[1]:location[3] - int((2/3)*(location[3] - location[1])), location[0]:location[2], :]

                detected, image_marked, w, h = sl_color_segmentation(segment_img, None)

                debug_msg_2 = self.bridge.cv2_to_imgmsg(image_marked, "bgr8")
                self.traffic_light_publisher.publish(debug_msg_2)

                stop_area = abs((location[3] - location[1]) * (location[2] - location[0]))
                light_area = w * h if w is not None else 0

                if detected and light_area >= stop_area / 10:
                    self.get_logger().info('in detected')
                    self.state = State.WAIT
                    self.start_time = time.time()
                    self.end_time = self.start_time + self.buffer


            debug_img = cv2.rectangle(image, (location[0], location[1]), (location[2], location[3]), (0,0,255), 10)
            debug_msg = self.bridge.cv2_to_imgmsg(debug_img, "bgr8")
            self.box_publisher.publish(debug_msg)
        
        else:
            self.state = State.DETECT


def main(args=None):
    rclpy.init(args=args)
    detector = LightDetector()
    rclpy.spin(detector)
    rclpy.shutdown()

if __name__=="__main__":
    main()


def timer(seconds):
    start_time = time.time()  # Get the current time
    end_time = start_time + seconds  # Calculate the end time
    
    # Loop until the current time exceeds the end time
    while time.time() < end_time:
        time.sleep(1)  # Wait for 1 second



def sl_color_segmentation(img, template):
    """
    Input:
    img: np.3darray; the input image. BGR.
    template_file_path; Not required, but can optionally be used to automate setting hue filter values.
    Return:
    detected True or False
    """
    # Blur
    #img = cv2.GaussianBlur(img, (5,5), 0)
    #img = cv2.medianBlur(img, 5)
    # img_blur = cv2.blur(img, (4,4))
    # img_blur = cv2.bilateralFilter(img_blur, 5, 75, 75)

    # Convert bgr to hsv
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

    # RED_THRESHOLD = [
    # 	([3, 160, 140], [10, 255, 255]),
    #     ([160, 160, 140], [180, 255, 255])
    # ]	
    RED_THRESHOLD = [
        ([0, 220, 240], [35, 255, 255]),
        ([29, 20, 240], [31, 255, 255])
    ]
    # RED_THRESHOLD = [
    #     ([0, 0, 150], [40, 30, 255]),
    #     ([170, 0, 150], [180, 30, 255])
    # ]
    

    # Set lower and upper bounds for stoplight
    lower_bound = np.array(RED_THRESHOLD[0][0])
    upper_bound = np.array(RED_THRESHOLD[0][1])
    lower_bound2 = np.array(RED_THRESHOLD[1][0])
    upper_bound2 = np.array(RED_THRESHOLD[1][1])

    # Mask out our colors
    mask1 = cv2.inRange(hsv, lower_bound, upper_bound)
    mask2 = cv2.inRange(hsv, lower_bound2, upper_bound2)
    mask = mask1 | mask2

    # Find contours from masks
    contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    # If we have contours
    if len(contours) != 0:

        # Find the biggest countour by area
        c = max(contours, key = cv2.contourArea)

        # Get a bounding rectangle around that contour
        x, y, w, h = cv2.boundingRect(c)



        # Add rectangle
        cv2.rectangle(img, (x,y), (x+w,y+h), (0,0,255), 2)

        return True, img, w, h

    return False, img, None, None