#!/usr/bin/env python3
import time
import threading

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Pose, PoseArray, Point, PointStamped, PoseWithCovarianceStamped
from fc_msgs.action import FindPath, NavigateToPose
from fc_msgs.srv import LaneProject
from tf_transformations import euler_from_quaternion, quaternion_from_euler
from visualization_msgs.msg import Marker, MarkerArray

from yasmin import CbState
from yasmin import Blackboard
from yasmin import StateMachine
from yasmin import State
from yasmin_ros.action_state import ActionState
from yasmin_ros.service_state import ServiceState
from yasmin_ros.yasmin_node import YasminNode
from yasmin_ros.basic_outcomes import SUCCEED, ABORT, CANCEL
from yasmin_viewer import YasminViewerPub
from nav_msgs.msg import OccupancyGrid

from path_planning.utils import Map
from .utils import LaneProjection
from .basement_point_publisher import BasementPointPublisher

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
        goal = NavigateToPose.Goal()
        trajectory = blackboard.trajectory
        goal.trajectory = trajectory
        return goal

    def handle_result(self, blackboard, result) -> str:
        time.sleep(7) #pick up shell
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
        initial_position: Pose = blackboard.init_pose
        shell_locations: PoseArray = blackboard.shell_locations
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
    
        s = poses[self.count]
        t = poses[(self.count + 1) % len(poses)]
        destination : Pose = blackboard.projection

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
        blackboard.trajectory = result.trajectory
        """
        if result is None:
            return ABORT  # Handle if the action fails
        # Handle the result based on your requirements
        # For example, update blackboard or perform further actions
        blackboard.trajectory = result.trajectory
        
        if self.count == 4 + 1:
            return END
        return HAS_NEXT

class ProjectNextDestination(ServiceState):
    def __init__(self) -> None:
        super().__init__(
            LaneProject,  # srv type
            "/lane_project",  # service name
            self.create_request_handler,  # cb to create the request
            [SUCCEED],  # outcomes. Includes (SUCCEED, ABORT)
            self.response_handler  # cb to process the response
        )

        self.count = 0

        self.node.get_logger().info("Projection Initialized")

    def execute(self, blackboard: Blackboard) -> str:
        """
        output:
        blackboard.projection = projection of next location

        outcomes:
        "in_front": next goal is in front of the car
        "behind": next goal is behind the car
        "end": no more goals to project
        """
        initial_position: Pose = blackboard.init_pose
        shell_locations: PoseArray = blackboard.shell_locations
        car_side: bool = blackboard.car_side #True if car on right side
        shell_sides = blackboard.shell_sides

        poses = shell_locations.poses
        poses = [initial_position] + poses
        
        s = poses[self.count]
        t = poses[(self.count + 1) % len(poses)] 

        projection = self.node.project(t, car_side) 
        blackboard.projection = projection
        self.count += 1
        if self.count == 4 + 1:
            return END
        if is_behind_us(blackboard):
            return "behind"
        return "in_front"

def is_behind_us(blackboard: Blackboard) -> bool:
    """
    Check if the car is behind us
    """
    projection = blackboard.projection
    init_pose = blackboard.init_pose
    if projection.position.x < init_pose.position.x:
        return True
    return False

def turn_around():
    """
    3 point turn
    command to do a 3 point turn to face the opposite direction
    """
    pass

# main
def main():

    print("yasmin_nav2_demo")

    # init ROS 2
    rclpy.init()

    # create state machines
    sm = StateMachine(outcomes=[SUCCEED, ABORT, CANCEL])
    nav_sm = StateMachine(outcomes=[SUCCEED, ABORT, CANCEL])

    # add states

    #this would be basement point publisher
    #transition succeed: navigating
    sm.add_state(
        "GETTING_SHELL_LOCATIONS",
        BasementPointPublisher(),
        transitions={
            SUCCEED: "NAVIGATING"
        }
    )

    # nav_sm.add_state(
    #     "PROJECTING_NEXT_GOAL",
    #     Project(),
    #     transitions={
    #         SUCCEED: "PLANNING_PATH",
    #     }
    # )    
    # nav_sm.add_state(
    #     "PLANNING_PATH",
    #     Plan2State(), #pure pursuit + localization at the same time...
    #     transitions={
    #         END: SUCCEED,
    #         HAS_NEXT: "FOLLOWING_PATH"
    #     }
    # )
    # nav_sm.add_state(
    #     "FOLLOWING_PATH",
    #     Nav2State(), #pure pursuit + localization at the same time...
    #     transitions={
    #         SUCCEED: "PLANNING_PATH", 
    #         CANCEL: CANCEL,
    #         ABORT: ABORT
    #     }
    # )

    ####################### NEW STATE MACHINE ############################
    nav_sm.add_state(
        "PROJECTING_NEXT_GOAL",
        Project(),
        transitions={
            "in_front": "FOLLOWING_LANE",
            "behind": "TURN_AROUND",
            END: SUCCEED,
            CANCEL: CANCEL,
            ABORT: ABORT
        }
    )
    #blackboard.projection: projection of next goal onto the car's lane

    nav_sm.add_state(
        "FOLLOWING_LANE",
        Nav2State(), #PID
        transitions={
            'within_radius': "PLANNING_PATH",
            CANCEL: CANCEL,
            ABORT: ABORT
        }
    )
    nav_sm.add_state(
        "PLANNING_PATH",
        Plan2State(), #BFS
        transitions={
            SUCCEED: "FOLLOWING_PATH",
            CANCEL: CANCEL,
            ABORT: ABORT
        }
    )
    # blackboard.trajectory: new trajectory to follow to the goal
    nav_sm.add_state(
        "FOLLOWING_PATH",
        Nav2State(), #PID
        transitions={
            SUCCEED: "PROJECTING_NEXT_GOAL", 
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

    print('outcome', outcome)

    # shutdown ROS 2
    rclpy.shutdown()


# if __name__ == "__main__":
#     main()



    #TODO
    #create action server
    #figure out how this all fits together 
    #https://docs.ros.org/en/foxy/Tutorials/Intermediate/Writing-an-Action-Server-Client/Py.html

    #TODO 
    #keep track of car's lane 
    #rrt* reversing for crossing lanes 
    #If behind us (no points in front of car?)
        #need more logic for this cause not perfect
    #implement path planning for trajectory right/left
