#!/usr/bin/env python3
import time
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Pose, PoseArray

from yasmin import CbState
from yasmin import Blackboard
from yasmin import StateMachine
from yasmin import State
from yasmin_ros.action_state import ActionState
from yasmin_ros.yasmin_node import YasminNode
from yasmin_ros.basic_outcomes import SUCCEED, ABORT, CANCEL
from yasmin_viewer import YasminViewerPub

from .utils import LaneProjection
from .basement_point_publisher import BasementPointPublisher
from fc_msgs.action import FindPath, NavigateToPose

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
        self.follow_lane = None

    def create_goal_handler(self, blackboard: Blackboard) -> NavigateToPose.Goal:
        self.follow_lane = blackboard.follow_lane
        goal = NavigateToPose.Goal()
        goal.trajectory = blackboard.trajectory
        goal.follow_lane = self.follow_lane
        goal.goal = blackboard.goal
        return goal

    def handle_result(self, blackboard, result) -> str:
        if result is None:
            return ABORT  # Handle if the action fails
        blackboard.car_position = result.car_position
        if not self.follow_lane: #at shell location
            time.sleep(7) #pick up shell
            return SUCCEED
        else: #within radius
            blackboard.follow_lane = False
            return SUCCEED

class Plan2State(ActionState):
    def __init__(self) -> None:
        super().__init__(
            FindPath,  # action type
            "plan_path",  # action name
            self.create_goal_handler,  # cb to create the goal
            None,  # outcomes. Includes (SUCCEED, ABORT, CANCEL)
            self.handle_result  # cb to process the response
        )
        self.follow_lane = None
        self.count = None

    def create_goal_handler(self, blackboard: Blackboard) -> FindPath.Goal:
        """
        count = 0: Start -> loc1
        count = 1: Loc 1 -> loc2
        count = 2: Loc 2 -> loc3
        count = 3: Loc 3 -> Start
        """
        initial_position: Pose = blackboard.init_pose
        shell_locations: PoseArray = blackboard.shell_locations
        self.follow_lane : bool = blackboard.follow_lane
        car_side = blackboard.car_side
        self.count = blackboard.count
            
        poses = shell_locations.poses
        poses = [initial_position] + poses

        if self.follow_lane:
            s = poses[self.count]
            t = blackboard.projection
        else:
            s = blackboard.car_position
            t = blackboard.goal

        goal = FindPath.Goal()
        s_and_t = PoseArray()
        s_and_t.poses = [s, t]
        s_and_t.header.frame_id = "map"
        goal.s_and_t = s_and_t
        goal.follow_lane = self.follow_lane
        goal.right = car_side
        goal.map = blackboard.occ_map
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
        if not self.follow_lane:
            blackboard.count = self.count + 1
        blackboard.trajectory = result.trajectory
        # print('trajectory', blackboard.trajectory)
        return SUCCEED
    
class Project(State):
    '''
    Yasmin state node that projects the next goal location to the car's current lane
    '''
    def __init__(self):
        super().__init__(outcomes=["in_front", "behind", "end", CANCEL, ABORT])
        self.node = YasminNode() #yasmin node has multithreading so that the excute function can be called synchronously with publisher/subscriber
        self.node = Node("Logger")
        self.count = 0
        self.project = LaneProjection()

    def execute(self, blackboard: Blackboard) -> str:
        """
        output:
        blackboard.projection = projection of next location
        blackboard.goal = actual goal (shell or start)
        blackboard.follow_lane = True
        
        outcomes:
        "in_front": next goal is in front of the car
        "behind": next goal is behind the car
        "end": no more goals to project
        """
        self.node.get_logger().info("Projecting next goal")
        initial_position: Pose = blackboard.init_pose
        shell_locations: PoseArray = blackboard.shell_locations
        car_side: bool = blackboard.car_side #True if car on right side
        shell_sides = blackboard.shell_sides

        poses = shell_locations.poses
        poses = [initial_position] + poses
        
        s = poses[self.count]
        t = poses[(self.count + 1) % len(poses)] 
        projection, projection_index = self.project.project(t, car_side) 
        _, car_index = self.project.project(s, car_side)

        blackboard.projection = projection
        blackboard.goal = t
        blackboard.follow_lane = True

        if self.count == 4:
            return "end"
        # if projection_index < car_index:
        #     return "behind"
        self.count += 1
        return "in_front"


def turn_around(blackboard):
    """
    3 point turn
    command to do a 3 point turn to face the opposite direction
    """
    return SUCCEED

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
            "in_front": "PLANNING_LANE",
            "behind": "TURN_AROUND",
            "end": SUCCEED,
            CANCEL: CANCEL,
            ABORT: ABORT
        }
    )
    # blackboard.projection: projection of next goal onto the car's lane
    # blackboard.goal = t
    # blackboard.follow_lane = True
    nav_sm.add_state(
        "TURN_AROUND",
        CbState([SUCCEED],turn_around),
        transitions={
            SUCCEED: "PROJECTING_NEXT_GOAL",
            CANCEL: CANCEL,
            ABORT: ABORT
        }
    )
    #blackboard.car_side switch
    nav_sm.add_state(

        "PLANNING_LANE",
        Plan2State(),
        transitions={
            SUCCEED: "FOLLOWING_LANE",
            CANCEL: CANCEL,
            ABORT: ABORT
        }
    )
    #blackboard.trajectory: new trajectory depending on car lane
    nav_sm.add_state(
        "FOLLOWING_LANE",
        Nav2State(), #PID
        transitions={
            SUCCEED: "PLANNING_PATH",
            CANCEL: CANCEL,
            ABORT: ABORT
        }
    )
    #blackboard.follow_lane = False
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

    #ros2 launch zed_wrapper zed_camera.launch.py camera_model:=zed2
