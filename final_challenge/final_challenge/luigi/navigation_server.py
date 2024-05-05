import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node

from fc_msgs.action import FindPath
from geometry_msgs.msg import Point, PointStamped, Pose, PoseArray

from .trajectory_planner import PathPlan
from fc_msgs.action import NavigateToPose
from .yeet import PurePursuit
import time
from yasmin_ros.yasmin_node import YasminNode
from std_msgs.msg import String


class NavigationActionServer(Node):

    def __init__(self):
        super().__init__('navigation_action_server')
        self._action_server = ActionServer(
            self,
            NavigateToPose,
            'navigate_to_pose',
            self.execute_callback)
        
        self.node = PurePursuit()
        self.traj_pub = self.create_publisher(PoseArray,
                                                "/trajectory/current",
                                                1)
        self.get_logger().info('Navigation Action Server Initialized')
            
    def execute_callback(self, goal_handle):
        self.get_logger().info('Server Navigating...')

        trajectory = goal_handle.request.trajectory #PoseArray

        self.traj_pub.publish(trajectory) #now the pursuit should start running

        feedback_msg = NavigateToPose.Feedback()

        while self.node.success is None:
            # feedback_msg.outcome = "navigating"
            # self.get_logger().info('Feedback: {0}'.format(feedback_msg.outcome))
            # goal_handle.publish_feedback(feedback_msg)
            time.sleep(1)
            # pass

        if self.node.success:
            self.node.reset_success()
            feedback_msg.outcome = "success"
            self.get_logger().info('Feedback: {0}'.format(feedback_msg.outcome))
            goal_handle.publish_feedback(feedback_msg)
            time.sleep(1) #pick up shell
            goal_handle.succeed()
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


    