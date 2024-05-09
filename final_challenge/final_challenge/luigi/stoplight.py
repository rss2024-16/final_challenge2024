import rclpy
from rclpy.node import Node
import numpy as np
import cv2
from cv_bridge import CvBridge, CvBridgeError

from sensor_msgs.msg import Image
from geometry_msgs.msg import Point
from fc_msgs.msg import StopLightPixel
from ackermann_msgs.msg import AckermannDriveStamped
from nav_msgs.msg import Odometry

class StopLight(Node):
    """
    A class for applying your cone detection algorithms to the real robot.
    Subscribes to: /zed/zed_node/rgb/image_rect_color (Image) : the live RGB image from the onboard ZED camera.
    Publishes to: /relative_cone_px (StopLightPixel) : the coordinates of the cone in the image frame (units are pixels).
    """

    def __init__(self):
        super().__init__("stop_light")

        # Subscribe to ZED camera RGB frames
        self.image_sub = self.create_subscription(Image, "/zed/zed_node/rgb/image_rect_color", self.image_callback, 5)
        self.pose_sub = self.create_subscription(Odometry, "/pf/pose/odom", self.pose_callback, 1)
        self.debug_pub = self.create_publisher(Image, "/stoplight_debug_img", 10)
        self.safety_pub = self.create_publisher(AckermannDriveStamped, "/vesc/low_level/input/safety", 10)
        self.bridge = CvBridge() # Converts between ROS images and OpenCV Images

        self.stoplights = [(-10.16142463684082,16.551956176757812),
                            (-30.105144500732422,33.97337341308594),
                            (-54.410980224609375,22.996463775634766)]

        self.ON_DISTANCE = 1.5

        # At 0.75 meters, 127 is lower and 137 is upper exactly
        self.LOWER = 117
        self.UPPER = 147

        self.pose = (0.0, 0.0)

        self.get_logger().info("Stop Light Detector Initialized")

    def pose_callback(self, odometry_msg):
        # Unpack the odom message
        x = odometry_msg.pose.pose.position.x
        y = odometry_msg.pose.pose.position.y

        self.pose = (x, y)

    def image_callback(self, image_msg):
        # From your bounding box, take the center pixel on the bottom
        # (We know this pixel corresponds to a point on the ground plane)
        # publish this pixel (u, v) to the /relative_cone_px topic; the homography transformer will
        # convert it to the car frame.

        # Minimum distance from robot to each stoplight
        min_dist = min(np.sqrt((self.pose[0] - x_i)**2 + (self.pose[1] - y_i)**2) for x_i, y_i in self.stoplights)

        #if min_dist <= self.ON_DISTANCE:
        if True:

            image = self.bridge.imgmsg_to_cv2(image_msg, "bgr8")

            image_cropped = image[self.LOWER:self.UPPER,:,:]

            detected, y, h, image_marked = sl_color_segmentation(image_cropped, None)

            debug_msg = self.bridge.cv2_to_imgmsg(image_marked, "bgr8")
            self.debug_pub.publish(debug_msg)

            if detected:
                self.get_logger().info(f"Y value: {y}, height: {h}")

                stop_cmd = AckermannDriveStamped()
                stop_cmd.drive.speed = 0.0
                stop_cmd.drive.steering_angle = 0.0
                self.safety_pub.publish(stop_cmd)

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
	img_blur = cv2.blur(img, (4,4))
	img_blur = cv2.bilateralFilter(img_blur, 5, 75, 75)

    # Convert bgr to hsv
	hsv = cv2.cvtColor(img_blur, cv2.COLOR_BGR2HSV)

	RED_THRESHOLD = [
		([0, 160, 100], [10, 255, 255]),
        ([160, 160, 100], [180, 255, 255])
	]

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

		return True, y, h, img

	return False, None, None, img

def main(args=None):
    rclpy.init(args=args)
    light_detector = StopLight()
    rclpy.spin(light_detector)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
