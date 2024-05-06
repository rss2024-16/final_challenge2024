import cv2
import numpy as np
import rclpy
from rclpy.node import Node
from PIL import Image, ImageDraw

def image_print(img):
	"""
	Helper function to print out images, for debugging. Pass them in as a list.
	Press any key to continue.
	"""
	cv2.imshow("image", img)
	cv2.waitKey(0)
	cv2.destroyAllWindows()

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
