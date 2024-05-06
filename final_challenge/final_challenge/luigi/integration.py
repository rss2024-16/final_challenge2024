#!/usr/bin/env python3
import time
import threading

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Pose, PoseArray, Point, PointStamped, PoseWithCovarianceStamped
from fc_msgs.action import FindPath, NavigateToPose
from tf_transformations import euler_from_quaternion, quaternion_from_euler
from visualization_msgs.msg import Marker, MarkerArray

from yasmin import CbState
from yasmin import Blackboard
from yasmin import StateMachine
from yasmin import State
from yasmin_ros.action_state import ActionState
from yasmin_ros.yasmin_node import YasminNode
from yasmin_ros.basic_outcomes import SUCCEED, ABORT, CANCEL
from yasmin_viewer import YasminViewerPub
from nav_msgs.msg import OccupancyGrid

from .utils import Map

HAS_NEXT = "has_next"
END = "end"

"""
Instructions for launch

git clone https://github.com/uleroboticsgroup/yasmin.git
remove yasmin_demos folder (doesn't build idk why)
cd yasmin
pip3 install -r requirements.txt

cd ..
colcon build

ros2 launch final_challenge sim_luigi_launch.launch.xml
ros2 launch racecar_simulator simulate.launch.xml
ssh -L 6081:localhost:6081 racecar@192.168.1.85
"""
class Nav2State(ActionState):
    def __init__(self) -> None:
        super().__init__(
            NavigateToPose,  # action type
            "navigate_to_pose",  # action name
            self.create_goal_handler,  # cb to create the goal
            None,  # outcomes. Includes (SUCCEED, ABORT, CANCEL)
            self.handle_result  # cb to process the response
        )

    def create_goal_handler(self, blackboard: Blackboard) -> NavigateToPose.Goal:
        print("Naviating Initialized")
        goal = NavigateToPose.Goal()
        trajectory = blackboard.trajectory
        goal.trajectory = trajectory
        return goal

    def handle_result(self, blackboard, result) -> str:
        return SUCCEED


class Plan2State(ActionState):
    def __init__(self) -> None:
        super().__init__(
            FindPath,  # action type
            "plan_path",  # action name
            self.create_goal_handler,  # cb to create the goal
            [END, HAS_NEXT],  # outcomes. Includes (SUCCEED, ABORT, CANCEL)
            self.handle_result  # cb to process the response
        )

        self.count = 0


    def create_goal_handler(self, blackboard: Blackboard) -> FindPath.Goal:
        """
        count = 0: Start -> loc1
        count = 1: Loc 1 -> loc2
        count = 2: Loc 2 -> loc3
        count = 3: Loc 3 -> Start
        """
        print("Planning Path Initialized: " + str(self.count))

        initial_position: Pose = blackboard.init_pose
        shell_locations: PoseArray = blackboard.shell_locations
        print("shell_locations: " + str(shell_locations.poses) + " initial_position: " + str(initial_position.position.x) + " " + str(initial_position.position.y) + " " + str(initial_position.position.z) + " " + str(initial_position.orientation.x) + " " + str(initial_position.orientation.y) + " " + str(initial_position.orientation.z) + " " + str(initial_position.orientation.w) + " " + str(initial_position.position.z))
        # self.node.get_logger().info("shell_locations: " + str(shell_locations.poses) + " initial_position: " + str(initial_position.position.x) + " " + str(initial_position.position.y) + " " + str(initial_position.position.z) + " " + str(initial_position.orientation.x) + " " + str(initial_position.orientation.y) + " " + str(initial_position.orientation.z) + " " + str(initial_position.orientation.w) + " " + str(initial_position.position.z))

        poses = shell_locations.poses
        poses = [initial_position] + poses
        
        s = poses[self.count]
        t = poses[(self.count + 1) % len(poses)]

        goal = FindPath.Goal()
        s_and_t = PoseArray()
        s_and_t.poses = [s, t]
        s_and_t.header.frame_id = "map"
        goal.s_and_t = s_and_t
        self.count += 1
        return goal

    def handle_result(self, blackboard, result: PoseArray) -> str:
        """
        result should be a pose array
        
        """
        if result is None:
            return ABORT  # Handle if the action fails
        # Handle the result based on your requirements
        # For example, update blackboard or perform further actions
        blackboard.trajectory = result.trajectory
        
        if self.count == 4:
            return END
        return HAS_NEXT

class BasementPointPublisher(State):
    '''
    Yasmin state node that publishes a list of "shell" points
    Subscribes to the "Publish Point" topic when you click on the map in RViz
    After 3 points have been chosen, it publishes the 3 points as a PoseArray and resets the array
    '''

    def __init__(self):
        super().__init__(outcomes=[SUCCEED])
        # self.node = YasminNode("basement_point_publisher")
        self.node = YasminNode() #yasmin node has multithreading so that the excute function can be called synchronously with publisher/subscriber
        self.shell_pub = self.node.create_publisher(MarkerArray, "/shell_points", 1)
        self.shell_sub = self.node.create_subscription(PointStamped, "/clicked_point", self.callback, 10)
        self.pose_sub = self.node.create_subscription(PoseWithCovarianceStamped, "/initialpose", self.pose_cb, 1)
        self.map_sub = self.node.create_subscription(OccupancyGrid, "/map", self.map_cb, 1)
        
        self.array = []
        self.point_count = 0
        self.time_to_wait = 5

        self.node.get_logger().info("Point Publisher Initialized")

        self.initial_location = None
        self.occ_map = False

    def map_cb(self, msg):
        #height x width -> 1300 x 1730 = 2,249,000
        #msg.data len -> 2,249,000
        #msg.data vals -> -1, 0, or 100 (0 means free space)
        self.node.get_logger().info("basement received :D")
        self.occ_map = True

    def callback(self, point_msg: PointStamped):
        if self.occ_map == False:
            self.node.get_logger().info("Map unset")
            return
        x, y = point_msg.point.x, point_msg.point.y
        self.node.get_logger().info(f"Received point: {x}, {y}")
        self.array.append(Pose(position=Point(x=x, y=y, z=0.0)))
        self.point_count += 1

    def publish_shell_locations(self):
        pose_array = PoseArray()
        pose_array.header.frame_id = "map"
        pose_array.poses = self.array

        self.publisher.publish(pose_array)
        
    def pose_cb(self, pose):
        """
        New initial pose (PoseWithCovarianceStamped)
        """
        if self.occ_map == False:
            self.node.get_logger().info("Waiting for map...")
            return
        self.node.get_logger().info("Pose")
        orientation = euler_from_quaternion((
        pose.pose.pose.orientation.x,
        pose.pose.pose.orientation.y,
        pose.pose.pose.orientation.z,
        pose.pose.pose.orientation.w))
        self.s = [pose.pose.pose.position.x,pose.pose.pose.position.y,orientation[2]]
        
        self.initial_location = Pose(position=Point(x=self.s[0], y=self.s[1], z=orientation[2]))

    def execute(self, blackboard: Blackboard) -> str:
        """
        When initial location and shell locations are complete, stores information in blackboard
        also publishes shell locations to "/shell_locations"
        """
        waiting = True
        while waiting:
            time.sleep(self.time_to_wait)

            if self.point_count == 3 :
                if self.initial_location is not None:
                    pose_array = PoseArray()
                    pose_array.header.frame_id = "map"
                    pose_array.poses = self.array

                    blackboard.shell_locations = pose_array
                    blackboard.init_pose = self.initial_location

                    marker_array = MarkerArray()
                    for i, pose in enumerate(self.array):
                        marker_array.markers.append(self.to_marker([pose.position.x, pose.position.y], i))

                    self.shell_pub.publish(marker_array)

                     # Reset Array and Point Count
                    self.array = []
                    self.point_count = 0
                    return SUCCEED
                else:
                    self.node.get_logger().info("Set initial pose first!")
            else:
                self.node.get_logger().info("Waiting for more shell locations... use Publish Point in RVIZ")

    def to_marker(self,position,id = 1,rgb=[1.0,0.0,0.0],scale=0.25):
        marker = Marker()
        marker.header.frame_id = "/map"  # Set the frame id
        marker.header.stamp = self.node.get_clock().now().to_msg()
        # marker.ns = "/followed_trajectory/trajectory"
        marker.id = id
        marker.type = Marker.SPHERE
        marker.action = Marker.ADD
        marker.pose.position.x = position[0]
        marker.pose.position.y = position[1]
        marker.pose.position.z = 0.0
        marker.pose.orientation.x = 0.0
        marker.pose.orientation.y = 0.0
        marker.pose.orientation.z = 0.0
        marker.pose.orientation.w = 1.0
        marker.scale.x = scale
        marker.scale.y = scale
        marker.scale.z = scale
        marker.color.a = 1.0
        marker.color.r = rgb[0]
        marker.color.g = rgb[1]
        marker.color.b = rgb[2]

        return marker


# main
def main():

    print("yasmin_nav2_demo")

    # init ROS 2
    rclpy.init()

    global lock

    lock = threading.Lock()

    # create state machines
    sm = StateMachine(outcomes=[SUCCEED, ABORT, CANCEL])
    nav_sm = StateMachine(outcomes=[SUCCEED, ABORT, CANCEL])

    # add states

    #this would be basement point publisher
    #transition succeed: navigating
    # sm.add_state(
    #     "GETTING_SHELL_LOCATIONS",
    #     CbState([SUCCEED], get_shell_locations),
    #     transitions={
    #         SUCCEED: "NAVIGATING"
    #     }
    # )
    sm.add_state(
        "GETTING_SHELL_LOCATIONS",
        BasementPointPublisher(),
        transitions={
            SUCCEED: "NAVIGATING"
        }
    )

    #this would be trajectory planning + following
    nav_sm.add_state(
        "PLANNING_PATH",
        Plan2State(), #pure pursuit + localization at the same time...
        transitions={
            END: SUCCEED,
            HAS_NEXT: "FOLLOWING_PATH"
        }
    )
    nav_sm.add_state(
        "FOLLOWING_PATH",
        Nav2State(), #pure pursuit + localization at the same time...
        transitions={
            SUCCEED: "PLANNING_PATH", 
            CANCEL: CANCEL,
            ABORT: ABORT
        }
    )

    sm.add_state(
        "NAVIGATING",
        nav_sm,
        transitions={
            SUCCEED: SUCCEED,
            CANCEL: CANCEL,
            ABORT: ABORT
        }
    )

    # pub FSM info
    YasminViewerPub("LUIGI_MANSION", sm)

    # execute FSM
    blackboard = Blackboard()
    outcome = sm(blackboard)

    # while True:
    #     current_state = sm.get_current_state()
    #     print(f"Current state: {current_state}")
    #     time.sleep(5)  # Pause execution for 5 seconds
    print(outcome)

    # shutdown ROS 2
    rclpy.shutdown()


# if __name__ == "__main__":
#     main()



    #TODO
    #create action server
    #figure out how this all fits together 
    #https://docs.ros.org/en/foxy/Tutorials/Intermediate/Writing-an-Action-Server-Client/Py.html