#!/usr/bin/env python

import rclpy
from rclpy.node import Node
import numpy as np

import cv2
from cv_bridge import CvBridge, CvBridgeError

from fc_msgs.srv import UvToXy, XyToUv

#The following collection of pixel locations and corresponding relative
#ground plane locations are used to compute our homography matrix

# PTS_IMAGE_PLANE units are in pixels
# see README.md for coordinate frame description

######################################################
## DUMMY POINTS -- ENTER YOUR MEASUREMENTS HERE
PTS_IMAGE_PLANE = [[340, 213],
                   [254, 227],
                   [525, 258],
                   [346, 182]] # dummy points
######################################################

# 340, 213 -> 27, 2.5
# 254, 227 -> 20, 11
# 525, 258 -> 12, -11
# 346, 182 -> 54, 0



# PTS_GROUND_PLANE units are in inches
# car looks along positive x axis with positive y axis to left

######################################################
## DUMMY POINTS -- ENTER YOUR MEASUREMENTS HERE
PTS_GROUND_PLANE = [[27, 2.5],
                    [20, 11],
                    [12, -11],
                    [54, 0]] # dummy points
######################################################

METERS_PER_INCH = 0.0254

class HomographyService(Node):
    def __init__(self):
        super().__init__("homography_service")

        if not len(PTS_GROUND_PLANE) == len(PTS_IMAGE_PLANE):
            rclpy.logerr("ERROR: PTS_GROUND_PLANE and PTS_IMAGE_PLANE should be of same length")

        #Initialize data into a homography matrix

        np_pts_ground = np.array(PTS_GROUND_PLANE)
        np_pts_ground = np_pts_ground * METERS_PER_INCH
        np_pts_ground = np.float32(np_pts_ground[:, np.newaxis, :])

        np_pts_image = np.array(PTS_IMAGE_PLANE)
        np_pts_image = np_pts_image * 1.0
        np_pts_image = np.float32(np_pts_image[:, np.newaxis, :])

        self.h, err = cv2.findHomography(np_pts_image, np_pts_ground)

        self.srv = self.create_service(UvToXy, 'uv_to_xy', self.transformUvToXy)
        self.srv2 = self.create_service(XyToUv, 'xy_to_uv',self.transormXyToUv)
    
    def transformUvToXy(self, request, response):
        u = request.u
        v = request.v

        homogeneous_point = np.array([[u], [v], [1]])
        xy = np.dot(self.h, homogeneous_point)
        scaling_factor = 1.0 / xy[2, 0]
        homogeneous_xy = xy * scaling_factor
        x = homogeneous_xy[0, 0]
        y = homogeneous_xy[1, 0]
        response.x = x
        response.y = y

        return response

    def transormXyToUv(self, request, response):
        x = request.x
        y = request.y

        homogeneous_point = np.array([[x], [y], [1]])
        uv = np.dot(np.linalg.inv(self.h), homogeneous_point)
        scaling_factor = 1.0 / uv[2, 0]
        homogeneous_uv = uv * scaling_factor
        
        u = homogeneous_uv[0, 0]
        v = homogeneous_uv[1, 0]
        response.u = int(u)
        response.v = int(v)

        return response

def main():
    rclpy.init()
    homography_service = HomographyService()
    rclpy.spin(homography_service)
    rclpy.shutodwn()

if __name__ == '__main__':
    main()