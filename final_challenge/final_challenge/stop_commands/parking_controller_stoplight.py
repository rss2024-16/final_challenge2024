#!/usr/bin/env python
import numpy as np
import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from sensor_msgs.msg import LaserScan
from ackermann_msgs.msg import AckermannDriveStamped
from fc_msgs.msg import StopLightLocation


import math

class SafetyControllerStopLight(Node):
    def __init__(self):
        '''
        The below section on muxes will help you decide which topic your safety controller
        should publish to once deployed on the racecar.

        Make this topic a ROS parameter so that you can easily change it between the simulation and the racecar.

        Stop light coords (x,y):

        trial 1
        (-10.182207107543945,16.615497589111328)
        (-29.70228385925293,34.01771545410156)
        (-54.72879409790039,23.176416397094727)

        trial 2
        (-10.16142463684082,16.551956176757812)
        (-30.105144500732422,33.97337341308594)
        (-54.410980224609375,22.996463775634766)


        '''
        super().__init__("safety_controller")

        # # Declare parameters to make them available for use
        # self.declare_parameter("scan_topic", "default")
        self.declare_parameter("safety_topic", "default")
        self.declare_parameter("navigation_topic", "default")
        self.declare_parameter("stop_range", "default")

        # Fetch constants from the ROS parameter server
        # self.SCAN_TOPIC = self.get_parameter('scan_topic').get_parameter_value().string_value
        # self.SCAN_TOPIC = '/scan'
        # self.SAFETY_TOPIC = self.get_parameter('safety_topic').get_parameter_value().string_value
        self.DRIVE_TOPIC = '/vesc/high_level/input/nav0'
        # self.NAVIGATION_TOPIC = self.get_parameter('navigation_topic').get_parameter_value().string_value
        self.NAVIGATION_TOPIC = '/vesc/low_level/ackermann_cmd'
        # self.STOP_RANGE = self.get_parameter("stop_range").get_parameter_value().double_value
        # self.drive_pub = self.create_publisher(AckermannDriveStamped, DRIVE_TOPIC, 10)

        self.sub_navigation = self.create_subscription(AckermannDriveStamped, self.NAVIGATION_TOPIC, self.navigation_callback, 10)
        self.stoplight_sub = self.create_subscription(StopLightLocation, "/relative_stoplight",self.relative_stoplight_callback, 1)
        self.pub_drive = self.create_publisher(AckermannDriveStamped, self.DRIVE_TOPIC, 10)
        self.odom_sub = self.create_subscription(Odometry, "/pf/pose/odom", self.localization_radius_callback, 1)

        self.get_logger().info('HERE "%s"' % self.SAFETY_TOPIC)

        # is this the current current speed of the car?
        self.VELOCITY = 1.6
        self.STOP_RANGE = 0.75

        self.stoplight_present = False

        # self.VELOCITY = 4.0
        # self.VELOCITY = 0.0


    def navigation_callback(self, msg: AckermannDriveStamped):
        '''
        Process navigation commands here
        For now, let's just pass them through
        '''
        # self.pub_safety.publish(msg)
        # self.VELOCITY = msg.drive.speed
        pass


    def relative_stoplight_callback(self, msg):
        '''
        Process homography data to detect stop signs and/or stop signs
        If a stop sign and/or stop light is detected, issue a stop command
        '''

        # not sure what homography actually returns

        self.stoplight_present = True

        pubstr = f"Relative x: {self.relative_x}\nRelative y: {self.relative_y}\n---------------"
        self.get_logger().info(pubstr)


    def localization_radius_callback(self,msg):

        self.relative_x = msg.pose.pose.orientation.x
        self.relative_y = msg.pose.pose.orientation.y

        pose = [self.relative_x, self.relative_y]

        stoplight_present = self.relative_stoplight_callback()

        stop_cmd = AckermannDriveStamped()
        offset = 0.5

        distances = []

        # need to change this function so that the car stops 0.5-1 meters from obstacle
        self.STOP_RANGE = self.VELOCITY**2/45 + offset

        # map coordinates
        trial_1: [(-10.18,16.615497589111328),
                (-29.70228385925293,34.01771545410156),
                (-54.72879409790039,23.176416397094727)] # type: ignore

        trial_2: [(-10.16142463684082,16.551956176757812),
                (-30.105144500732422,33.97337341308594),
                (-54.410980224609375,22.996463775634766)] # type: ignore

        # convert map coords from world frame to robot frame

        # loop through each of the coordinates for the stop lights
        for coord in trial_1:
            # calculate the euclidean distance between the robot's pose and the coordinates
            difference = lambda coord, pose: np.linalg.norm(np.array([coord[0] - pose[0], coord[1] - pose[1]]))
            distances.append(difference)

        # check if any of the calculated distances are less than a meter
        for dist in distances:
            if dist <= 1 and stoplight_present == True:
                # self.get_logger().info('stopping')
                stop_cmd.drive.speed = 0.0
                stop_cmd.drive.steering_angle = 0.0
                self.pub_drive.publish(stop_cmd)
            else:
                pass

        # else:
        #     stop_cmd.drive.speed = self.VELOCITY
        #     stop_cmd.drive.steering_angle = 0.0
        # self.get_logger().info('stop_range: "%s"' % self.STOP_RANGE)
        # stop_cmd.drive.steering_angle_velocity = 0.0
        # stop_cmd.drive.acceleration = 0.0 # a= -v^2/2(d-d')
        # stop_cmd.drive.jerk = 0.0
        # self.get_logger().info('HELP "%s"' % stop_cmd.drive.speed)

        # self.get_logger().info('stop_range: "%s"' % self.STOP_RANGE)
        # stop_cmd.drive.steering_angle_velocity = 0.0
        # stop_cmd.drive.acceleration = 0.0 # a= -v^2/2(d-d')
        # stop_cmd.drive.jerk = 0.0
        # self.get_logger().info('HELP "%s"' % stop_cmd.drive.speed)

def main():

    rclpy.init()
    safety_controller_stoplight = SafetyControllerStopLight()
    rclpy.spin(safety_controller_stoplight)
    safety_controller_stoplight.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
