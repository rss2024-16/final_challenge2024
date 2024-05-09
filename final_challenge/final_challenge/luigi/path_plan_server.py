import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node

from fc_msgs.action import FindPath
from geometry_msgs.msg import Point, PointStamped, Pose, PoseArray

from .trajectory_planner import PathPlan
from .utils import LineTrajectory
from yasmin_ros.yasmin_node import YasminNode

class PathPlanActionServer(Node):

    def __init__(self):
        super().__init__('path_planning_action_server')
        self._action_server = ActionServer(
            self,
            FindPath,
            'plan_path',
            self.execute_callback)
        self.node = PathPlan()
        self.get_logger().info('Path Planning Action Server Initialized')

    def execute_callback(self, goal_handle):
        self.get_logger().info('Server finding path...')

        s_and_t = goal_handle.request.s_and_t #PoseArray
        follow_lane = goal_handle.request.follow_lane
        car_side = goal_handle.request.car_side

        s = [s_and_t.poses[0].position.x, s_and_t.poses[0].position.y, None]
        t = [s_and_t.poses[1].position.x, s_and_t.poses[1].position.y, None]

        if follow_lane: #LOAD LANE
            trajectory = LineTrajectory(Node(), "/loaded_trajectory")
            if car_side:
                trajectory.load("/home/racecar/racecar_ws/src/path_planning/example_trajectories/right-lane.traj")
            else:
                trajectory.load("/home/racecar/racecar_ws/src/path_planning/example_trajectories/left-lane.traj")
            trajectory.updatePoints(trajectory.points[:])
            path = trajectory.points

        else: #BFS
            self.node.plan_path(s, t)
            path = self.node.path_pose_array

        if path is None:
            goal_handle.abort()
            return FindPath.Result()
        
        goal_handle.succeed()
        result = FindPath.Result()
        result.trajectory = path
        return result


def main(args=None):
    rclpy.init(args=args)

    path_plan_action_server = PathPlanActionServer()

    rclpy.spin(path_plan_action_server)


# if __name__ == '__main__':
#     main()