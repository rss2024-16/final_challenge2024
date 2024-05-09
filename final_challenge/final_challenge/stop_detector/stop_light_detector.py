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
# from final_challenge.stop_detector.stop_light_segmentation import sl_color_segmentation

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
      # From your bounding box, take the center pixel on the bottom
      # (We know this pixel corresponds to a point on the ground plane)
      # publish this pixel (u, v) to the /relative_cone_px topic; the homography transformer will
      # convert it to the car frame.
      
        image = self.bridge.imgmsg_to_cv2(image_msg, "bgr8")

      #344,178.5
        height = image.shape[1]

        look_ahead = 2.5
        self.dist_pub.publish(float(look_ahead))
        v = self.get_parameter('look_ahead_v').value

        if v == 0:
            v = 168.7

      # lower = int(.9*v)
        upper = int(1.1*v)
        if upper > height:
            upper = height
        # image_cropped = image[lower:upper,:,:]
        image_copy = np.copy(image)
        # image_copy[0:lower,:,:] = 0
        image_copy[upper:,:,:] = 0
        # Crop the left boundary of the image
        image_copy[:, :upper, :] = 0
        # image_copy[upper:, :upper, :] = 0
        x, y, w, h, img = sl_color_segmentation(image_copy,None)

        if x is not None:
            #send the bottom center pixel
            center_pixel = StopLightPixel()
            center_pixel.u = float(x + w/2)
            center_pixel.v = float(y + h/2)

            self.stoplight_pub.publish(center_pixel)

            debug_msg = self.bridge.cv2_to_imgmsg(img, "bgr8")
            self.debug_pub.publish(debug_msg)

def sl_color_segmentation(img, template):
	"""
	Implement the cone detection using color segmentation algorithm
	Input:
		img: np.3darray; the input image with a cone to be detected. BGR.
		template_file_path; Not required, but can optionally be used to automate setting hue filter values.
	Return:
		x, y: Top left of the bounding box
		w, h: Width and height of the bounding box
	"""
	template = None
	########## YOUR CODE STARTS HERE ##########
	# # Use the template to set filter values
	# template_image = cv2.imread(template)
	# template_hsv = cv2.cvtColor(template_image, cv2.COLOR_BGR2HSV)
	# hue_values = template_hsv[:, :, 0]

	# # Calculate the minimum and maximum hue values in the template
	# min_hue_value = np.min(hue_values)
	# max_hue_value = np.max(hue_values)

	# # Calculate lower and upper bounds
	# threshold = 3
	# lower_bound = (max(min_hue_value - threshold, 0), 100, 100)
	# upper_bound = (min(max_hue_value + threshold, 180), 255, 255)

	# Set thresholds manually
	# ORANGE_THRESHOLD = ([5, 200, 140], [35, 255, 255])

	# RED_THRESHOLD = [
	# 	([0, 160, 100], [10, 255, 255]),
    #     ([160, 160, 100], [180, 255, 255])
	# ]

	RED_THRESHOLD = [
		([0, 0, 230], [50, 255, 255]),
        ([130, 0, 230], [178, 230, 255])
	]

    # Set lower and upper bounds for cone
	lower_bound = np.array(RED_THRESHOLD[0][0])
	upper_bound = np.array(RED_THRESHOLD[0][1])

	mask1 = cv2.inRange(hsv, lower_bound, upper_bound)

	lower_bound2 = np.array(RED_THRESHOLD[1][0])
	upper_bound2 = np.array(RED_THRESHOLD[1][1])

    # Blur
	#img = cv2.GaussianBlur(img, (5,5), 0)
	#img = cv2.medianBlur(img, 5)
	img = cv2.blur(img, (4,4))
	img = cv2.bilateralFilter(img, 5, 75, 75)

	# Mask out our colors

	mask2 = cv2.inRange(hsv, lower_bound2, upper_bound2)

	mask = mask1 | mask2

	#image_print(mask)
	#image_print(img)

    # Convert bgr to hsv
	hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

	# Find contours from masks
	contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

	# If we have contours
	if len(contours) != 0:

		# Find the biggest countour by area
		c = max(contours, key = cv2.contourArea)

		# Get a bounding rectangle around that contour
		x, y, w, h = cv2.boundingRect(c)

		# Add circle and destination point
		cv2.rectangle(img, (x,y), (x+w,y+h), (0,0,255), 2)
		# cv2.circle(img, (int(x+w/2), y+h), radius=1, color=(0, 0, 255), thickness=-1)

		#return ((x,y), (x+w,y+h)) # Use for testing with the cv_test.py

        # TODO: use stereo camera here to convert pixel coordinates to return relative coordinates in world frame

		return x, y, w, h, img # Actual return

	return None, None, None, None, None

def main(args=None):
    rclpy.init(args=args)
    cone_detector = StopLightDetector()
    rclpy.spin(cone_detector)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
