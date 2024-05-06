#!/usr/bin/env python
import numpy as np
import rclpy
import rospy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from ackermann_msgs.msg import AckermannDriveStamped
from fc_msgs.msg import StopLightLocation


import math

class SafetyController(Node):
    def __init__(self):
        '''
        The below section on muxes will help you decide which topic your safety controller
        should publish to once deployed on the racecar.

        Make this topic a ROS parameter so that you can easily change it between the simulation and the racecar.
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
        self.SAFETY_TOPIC = '/vesc/low_level/input/safety'
        # self.NAVIGATION_TOPIC = self.get_parameter('navigation_topic').get_parameter_value().string_value
        self.NAVIGATION_TOPIC = '/vesc/low_level/ackermann_cmd'
        # self.STOP_RANGE = self.get_parameter("stop_range").get_parameter_value().double_value
        # self.drive_pub = self.create_publisher(AckermannDriveStamped, DRIVE_TOPIC, 10)

        self.sub_navigation = self.create_subscription(AckermannDriveStamped, self.NAVIGATION_TOPIC, self.navigation_callback, 10)
        self.stoplight_sub = self.create_subscription(StopLightLocation, "/relative_stoplight",self.relative_stoplight_callback, 1)
        self.pub_safety = self.create_publisher(AckermannDriveStamped, self.SAFETY_TOPIC, 10)

        self.get_logger().info('HERE "%s"' % self.SAFETY_TOPIC)

        # is this the current current speed of the car?
        self.VELOCITY = 1.6
        self.STOP_RANGE = 0.75
        self.has_stopped = False
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
        self.relative_x = msg.x_pos
        self.relative_y = msg.y_pos

        pubstr = f"Relative x: {self.relative_x}\nRelative y: {self.relative_y}\n---------------"
        self.get_logger().info(pubstr)

        stop_cmd = AckermannDriveStamped()

        offset = 0.5

        # need to change this function so that the car stops 0.5-1 meters from obstacle
        self.STOP_RANGE = self.VELOCITY**2/45 + offset

        if  msg.x_pos < self.STOP_RANGE:
            # Example threshold, adjust as needed
            # self.get_logger().info('stopping')
            stop_cmd.drive.speed = 0.0
            stop_cmd.drive.steering_angle = 0.0
            rospy.sleep(2.0)

            self.pub_safety.publish(stop_cmd)

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
    safety_controller = SafetyController()
    rclpy.spin(safety_controller)
    safety_controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
