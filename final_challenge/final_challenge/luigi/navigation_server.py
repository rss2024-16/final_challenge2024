import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node

from geometry_msgs.msg import Pose,PoseArray

from fc_msgs.action import NavigateToPose
from .PID import PID
import time
import numpy as np

class NavigationActionServer(Node):

    def __init__(self):
        super().__init__('navigation_action_server')
        self._action_server = ActionServer(
            self,
            NavigateToPose,
            'navigate_to_pose',
            self.execute_callback)
        
        self.node = PID()
        self.traj_pub = self.create_publisher(PoseArray, "/trajectory/current", 1)
        self.get_logger().info('Navigation Action Server Initialized')
            
    def execute_callback(self, goal_handle):
        self.get_logger().info('Server Navigating...')

        trajectory : PoseArray = goal_handle.request.trajectory 
        follow_lane = goal_handle.request.follow_lane
        goal = goal_handle.request.goal
        self.node.follow_lane = follow_lane
        self.node.goal = np.array([goal.position.x, goal.position.y, 0])

        self.get_logger().info(f"Follow Lane: {follow_lane}")
        # self.node.get_logger().info(f"Follow Lane: {follow_lane}")
        # self.node.get_logger().info(f"Trajectory: {trajectory}")
        # self.node.get_logger().info(f"Driving to Shell: {self.node.driving_to_shell}")

        self.traj_pub.publish(trajectory) #now the pursuit should start running

        feedback_msg = NavigateToPose.Feedback()

        while self.node.success is None:
            # feedback_msg.outcome = "navigating"
            # self.get_logger().info('Feedback: {0}'.format(feedback_msg.outcome))
            # goal_handle.publish_feedback(feedback_msg)
            time.sleep(1)
            # pass

        if self.node.success:
            self.node.get_logger().info('success!')
            self.node.reset_success()
            feedback_msg.outcome = "success"
            self.get_logger().info('Feedback: {0}'.format(feedback_msg.outcome))
            goal_handle.publish_feedback(feedback_msg)
            goal_handle.succeed()
            result = NavigateToPose.Result()
            result.car_position = self.node.car_position
            return NavigateToPose.Result()
        else:
            self.node.reset_success()
            feedback_msg.outcome = "fail"
            self.get_logger().info('Feedback: {0}'.format(feedback_msg.outcome))
            goal_handle.publish_feedback(feedback_msg)
            goal_handle.abort()
            return NavigateToPose.Result()


def main(args=None):
    rclpy.init(args=args)

    navigation_action_server = NavigationActionServer()

    rclpy.spin(navigation_action_server)


    