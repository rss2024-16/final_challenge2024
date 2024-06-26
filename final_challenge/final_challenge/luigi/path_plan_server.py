import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node

from fc_msgs.action import FindPath

from .trajectory_planner import PathPlan
from path_planning.utils import LineTrajectory, Map

class PathPlanActionServer(Node):

    def __init__(self):
        super().__init__('path_planning_action_server')
        self._action_server = ActionServer(
            self,
            FindPath, #action
            'plan_path', #action name
            self.execute_callback)
        self.node = PathPlan()
        self.get_logger().info('Path Planning Action Server Initialized')

    def execute_callback(self, goal_handle):
        self.get_logger().info('Server finding path...')

        s_and_t = goal_handle.request.s_and_t #PoseArray
        follow_lane = goal_handle.request.follow_lane
        car_side = goal_handle.request.right
        map = goal_handle.request.map
        car_idx = goal_handle.request.car_idx
        proj_idx = goal_handle.request.projection_idx
        # self.get_logger().info(f'{s_and_t}')

        trajectory = LineTrajectory(Node("lane_trajectory"), "/lane_trajectory")
        if car_side:
            self.node.get_logger().info("Right Lane Trajectory")
            trajectory.load("/home/racecar/racecar_ws/src/path_planning/example_trajectories/right-lane.traj")
            # trajectory.load("/root/racecar_ws/src/path_planning/example_trajectories/right-lane.traj")
        else:
            self.node.get_logger().info("Left Lane Trajectory")
            trajectory.load("/home/racecar/racecar_ws/src/path_planning/example_trajectories/left-lane.traj")
            # trajectory.load("/root/racecar_ws/src/path_planning/example_trajectories/left-lane.traj")
        self.get_logger().info(f'Car idx: {car_idx}, Proj idx: {proj_idx}, total_points: {len(trajectory.points)}') 
        trajectory.updatePoints(trajectory.points[car_idx:proj_idx])
        path = trajectory.toPoseArray()

        # else: #BFS
        #     self.node.occ_map = Map(map)
        #     # self.get_logger().info(f'{s}')
        #     s = [s_and_t.poses[0].position.x, s_and_t.poses[0].position.y, None]
        #     t = [s_and_t.poses[1].position.x, s_and_t.poses[1].position.y, None]
        #     success = self.node.plan_path(s, t)
        #     path = self.node.path_pose_array

        #     if success is None:
        #         goal_handle.abort()
        #         return FindPath.Result()
        
        self.node.get_logger().info('Path Found...')
        goal_handle.succeed()
        result = FindPath.Result()
        result.trajectory = path
        return result

def main(args=None):
    rclpy.init(args=args)

    path_plan_action_server = PathPlanActionServer()

    rclpy.spin(path_plan_action_server)
