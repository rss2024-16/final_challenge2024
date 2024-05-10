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
from fc_msgs.action import FindPath, NavigateToPose

class PlanTurn(ActionState):
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

        self.node.get_logger().info(f's pose: {s}')
        goal = FindPath.Goal()
        s_and_t = PoseArray()
        s_and_t.poses = [s, t]
        s_and_t.header.frame_id = "map"
        goal.s_and_t = s_and_t
        goal.follow_lane = self.follow_lane
        goal.right = car_side
        goal.map = blackboard.occ_map
        goal.car_idx = blackboard.car_idx
        goal.projection_idx = blackboard.projection_idx
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
    
class NavTurn(ActionState):
    def __init__(self) -> None:
        super().__init__(
            NavigateToPose,  # action type
            "navigate_to_pose",  # action name
            self.create_goal_handler,  # cb to create the goal
            None,  # outcomes. Includes (SUCCEED, ABORT, CANCEL)
            self.handle_result  # cb to process the response
        )
        self.follow_lane = None
        self.node = Node('fuck_you')

    def create_goal_handler(self, blackboard: Blackboard) -> NavigateToPose.Goal:
        print(f'traj {blackboard.trajectory}')
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
        self.node.get_logger().info(f'result pos: {result.car_position}')
        if not self.follow_lane: #at shell location
            time.sleep(7) #pick up shell
            return SUCCEED
        else: #within radius
            blackboard.follow_lane = False
            return SUCCEED