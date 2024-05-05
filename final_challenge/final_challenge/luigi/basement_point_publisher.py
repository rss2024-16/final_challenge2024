import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Point, PointStamped, Pose, PoseArray

class BasementPointPublisher(Node):
    '''
    Node that publishes a list of "shell" points
    Subscribes to the "Publish Point" topic when you click on the map in RViz
    After 3 points have been chosen, it publishes the 3 points as a PoseArray and resets the array
    '''

    def __init__(self):
        super().__init__("basement_point_publisher")
        self.publisher = self.create_publisher(PoseArray, "/shell_points", 1)
        self.subscriber = self.create_subscription(PointStamped, "/clicked_point", self.callback, 1)

        self.array = []

        self.get_logger().info("Point Publisher Initialized")

    def callback(self, point_msg: PointStamped):
        x,y = point_msg.point.x, point_msg.point.y
        self.get_logger().info(f"Received point: {x}, {y}")
        self.array.append(Pose(position=Point(x=x, y=y, z=0.0)))
        
        if len(self.array) == 3:
            self.publish()

    def publish(self):
        # Publish PoseArray
        pose_array = PoseArray()
        pose_array.header.frame_id = "map"
        pose_array.poses = self.array

        self.publisher.publish(pose_array)

        # Print to Command Line
        points_str = '\n'+'\n'.join([f"({p.position.x},{p.position.y})" for p in self.array])
        self.get_logger().info(f"Published 3 points: {points_str}")

        # Reset Array
        self.array = []
    

# Copyright (C) 2023  Miguel Ángel González Santamarta

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.


import time
from typing import List, Callable, Union, Type

from rclpy.node import Node
from rclpy.subscription import Subscription
from rclpy.qos import QoSProfile

from yasmin import State
from yasmin import Blackboard
from yasmin_ros.yasmin_node import YasminNode
from yasmin_ros.basic_outcomes import CANCEL


class MonitorState(State):

    _node: Node
    _sub: Subscription
    _monitor_handler: Callable

    msg_list: List = []
    msg_queue: int
    timeout: int
    time_to_wait: float = 0.001
    monitoring: bool = False

    def __init__(
        self,
        msg_type: Type, #PointStamped
        topic_name: str, #/clicked_point
        outcomes: List[str], #SUCCEED
        monitor_handler: Callable,
        qos: Union[QoSProfile, int] = 10, 
        msg_queue: int = 10, #3
        timeout: int = None,
        node: Node = None
    ) -> None:

        if not timeout is None:
            outcomes = [CANCEL] + outcomes
        super().__init__(outcomes)

        self._monitor_handler = monitor_handler
        self.msg_queue = msg_queue
        self.timeout = timeout

        if node is None:
            self._node = YasminNode.get_instance()
        else:
            self._node = node

        self._sub = self._node.create_subscription(
            msg_type, topic_name, self.__callback, qos)

    def __callback(self, msg) -> None:

        if self.monitoring:
            self.msg_list.append(msg)

            if len(self.msg_list) >= self.msg_queue:
                self.msg_list.pop(0)

    def execute(self, blackboard: Blackboard) -> str:

        elapsed_time = 0
        self.msg_list = []
        self.monitoring = True
        valid_transition = False

        while not valid_transition:
            time.sleep(self.time_to_wait)

            if not self.timeout is None:

                if elapsed_time >= self.timeout:
                    self.monitoring = False
                    return CANCEL

                elapsed_time += self.time_to_wait

            if self.msg_list:
                outcome = self._monitor_handler(blackboard, self.msg_list[0])
                if outcome is None:
                    self._node.get_logger().warn("Transition undeclared or declared but unhandled.")
                    self.msg_list.pop(0)
                if outcome is not None and outcome in self.get_outcomes():
                    valid_transition = True
                    break

        self.monitoring = False
        return outcome


def main(args=None):
    rclpy.init(args=args)
    node = BasementPointPublisher()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__=="__main__":
    main()