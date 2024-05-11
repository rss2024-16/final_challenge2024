import rclpy
import numpy as np
import time

from geometry_msgs.msg import Pose, PoseArray, Point, PointStamped, PoseWithCovarianceStamped
from tf_transformations import euler_from_quaternion
from visualization_msgs.msg import Marker, MarkerArray

from yasmin import Blackboard
from yasmin import State
from yasmin_ros.yasmin_node import YasminNode
from yasmin_ros.basic_outcomes import SUCCEED, ABORT, CANCEL
from nav_msgs.msg import OccupancyGrid

from path_planning.utils import LineTrajectory
from .utils import LaneProjection

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
        self.shell_sub = self.node.create_subscription(PointStamped, "/clicked_point", self.shell_callback, 10)
        self.pose_sub = self.node.create_subscription(PoseWithCovarianceStamped, "/initialpose", self.pose_callback, 1)
        self.map_sub = self.node.create_subscription(OccupancyGrid, "/map", self.map_callback, 1)
        
        self.array = []
        self.shell_sides = {} #Right is True, Left is False
        self.car_side = True #Right is True, Left is False
        self.shell_count = 0
        self.time_to_wait = 5 #seconds
        self.NUM_SHELLS = 3
        self.initial_location = None
        self.occupancy_map = False
        self.lane_projection = LaneProjection()

        self.node.get_logger().info("Shell Publisher Initialized")

    def map_callback(self, msg):
        """
        Store the occupancy map to pass to path plan
        """
        self.node.get_logger().info("basement received :D")
        self.occupancy_map = msg

    def shell_callback(self, point_msg: PointStamped):
        """
        Get new shell
        """
        if self.occupancy_map == False:
            self.node.get_logger().info("Map unset")
            return
        x, y = point_msg.point.x, point_msg.point.y
        self.node.get_logger().info(f"Received point: {x}, {y}")
        side = self.find_which_lane(x, y)
        self.node.get_logger().info(f"Side: {side}")
        self.array.append(Pose(position=Point(x=x, y=y, z=0.0)))
        self.shell_count += 1
        self.shell_sides[self.shell_count] = side

    def find_which_lane(self, x, y):
        """
        Right = True
        Left = False
        """
        def is_clockwise(v1, v2):
            cross_product = np.cross(v1, v2)
            clockwise = np.sign(cross_product)
            return clockwise
        
        lane_traj = LineTrajectory(self.node)
        lane_traj.load("/home/racecar/racecar_ws/src/path_planning/example_trajectories/full-lane.traj")
        # lane_traj.load("/root/racecar_ws/src/path_planning/example_trajectories/full-lane.traj")
         
        nearest_lane_point, nearest_index = self.lane_projection.find_nearest([x,y], lane_traj.points)
        closest_point = lane_traj.points[nearest_index]
        vector_to_shell = np.array([x - closest_point[0], y - closest_point[1]])
        vector_to_lane = np.array([nearest_lane_point[0] - closest_point[0], nearest_lane_point[1] - closest_point[1]])
        clockwise = is_clockwise(vector_to_shell, vector_to_lane)
        if clockwise > 0:
            return True
        else:
            return False

    def pose_callback(self, pose):
        """
        New initial pose (PoseWithCovarianceStamped)
        """
        if self.occupancy_map == False:
            self.node.get_logger().info("Map unset")
            return
        orientation = euler_from_quaternion(
                    (pose.pose.pose.orientation.x,
                    pose.pose.pose.orientation.y,
                    pose.pose.pose.orientation.z,
                    pose.pose.pose.orientation.w)
                    )
        x = pose.pose.pose.position.x
        y = pose.pose.pose.position.y
        self.car_side = self.find_which_lane(x, y)
        self.initial_location = Pose(position=Point(x=x, y=y, z=orientation[2]))

    def execute(self, blackboard: Blackboard) -> str:
        """
        When initial location and shell locations are complete, stores information in blackboard
        also publishes shell locations to "/shell_points"

        outputs:
            blackboard.shell_locations = pose_array
            blackboard.init_pose = self.initial_location
            blackboard.car_side = self.car_side
            blackboard.shell_sides = self.shell_sides
            blackboard.car_position = self.initial_location
            blackboard.occ_map = self.occupancy_map
        """
        waiting = True
        while waiting:
            time.sleep(self.time_to_wait)

            if self.shell_count == self.NUM_SHELLS:
                if self.initial_location is not None:
                    pose_array = PoseArray()
                    pose_array.header.frame_id = "map"
                    pose_array.poses = self.array

                    blackboard.shell_locations = pose_array
                    blackboard.init_pose = self.initial_location
                    blackboard.car_side = self.car_side
                    blackboard.shell_sides = self.shell_sides
                    blackboard.car_position = self.initial_location
                    blackboard.occ_map = self.occupancy_map
                    blackboard.count = 0

                    marker_array = MarkerArray()
                    for i, pose in enumerate(self.array):
                        marker_array.markers.append(self.to_marker([pose.position.x, pose.position.y], i))
                    self.shell_pub.publish(marker_array)

                     # Reset Array and Point Count
                    self.array = []
                    self.shell_count = 0
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

