import rclpy
from rclpy.node import Node
import numpy as np

from geometry_msgs.msg import Point, PointStamped, Pose, PoseArray
import time

import rclpy
from geometry_msgs.msg import Pose, PoseArray, Point, PointStamped, PoseWithCovarianceStamped
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

from path_planning.utils import Map, LineTrajectory

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

        self.lane_pub = self.node.create_publisher(MarkerArray, "/lane", 1)
        
        self.array = []
        self.shell_sides = {} #Right is True, Left is False
        self.car_side = True #Right is True, Left is False
        self.point_count = 0
        self.time_to_wait = 5
        self.NUM_SHELLS = 3

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
        """
        Get new shell
        """
        if self.occ_map == False:
            self.node.get_logger().info("Map unset")
            return
        x, y = point_msg.point.x, point_msg.point.y
        self.node.get_logger().info(f"Received point: {x}, {y}")
        side = self.find_which_lane(x, y)
        self.node.get_logger().info(f"Side: {side}")
        self.array.append(Pose(position=Point(x=x, y=y, z=0.0)))
        self.point_count += 1
        self.shell_sides[self.point_count] = side

    def find_which_lane(self, x, y):
        """
        Right or left lane
        """
        self.node.get_logger().info("Finding which lane")
        lane_traj = LineTrajectory(self.node, "/testing_visualisation")
        lane_traj.load("/home/racecar/racecar_ws/src/path_planning/example_trajectories/full-lane.traj")
        nearest_lane_point, nearest_index = self.find_nearest([x,y], lane_traj.points)
        
        closest_point = lane_traj.points[nearest_index]
        vector_to_shell = np.array([x - closest_point[0], y - closest_point[1]])
        vector_to_lane = np.array([nearest_lane_point[0] - closest_point[0], nearest_lane_point[1] - closest_point[1]])
                                  
        angle, clockwise = self.angle_between(vector_to_shell, vector_to_lane)
        if clockwise > 0:
            return True
        else:
            return False

    def angle_between(self, v1, v2):
        dot_product = np.dot(v1, v2)
        cross_product = np.cross(v1, v2)
        
        angle = np.arctan2(np.linalg.norm(cross_product), dot_product)
        clockwise = np.sign(cross_product)
        
        return np.degrees(angle), clockwise

    def find_nearest(self, point, segments):
        """
        Finds the index of the next point on the segments and returns it
        """        
        min_distance = float('inf')
        nearest_point = None
        nearest_index = None
        
        # Iterate over each line segment in the list
        for i in range(len(segments) - 1):
            segment_start = (segments[i][0], segments[i][1])
            segment_end = (segments[i + 1][0], segments[i + 1][1])
            
            # Calculate the nearest point on the segment to the given point
            point_on_segment = self.nearest_point_on_segment(segment_start, segment_end, point)
            
            # Calculate the distance from the given point to the nearest point on the segment
            dx = point[0] - point_on_segment[0]
            dy = point[1] - point_on_segment[1]
            dist = np.linalg.norm(np.array([dx, dy]))
            
            # Update the minimum distance and the nearest point if necessary
            if dist < min_distance:
                min_distance = dist
                nearest_point = point_on_segment
                nearest_index = i
        
        return nearest_point, nearest_index

    def nearest_point_on_segment(self, segment_start, segment_end, point):
        """
        Finds the nearest point on a line segment defined by a start and end point and returns it
        """
        # Calculate the vector from the start to end of the segment
        segment_vector = (segment_end[0] - segment_start[0], segment_end[1] - segment_start[1])
        
        # Calculate the vector from the start of the segment to the given point
        point_vector = (point[0] - segment_start[0], point[1] - segment_start[1])
        
        # Calculate the dot product between the segment vector and the point vector
        segment_length_squared = segment_vector[0] ** 2 + segment_vector[1] ** 2
        if segment_length_squared == 0:
            # The segment is a single point
            return segment_start

        dot_product = (point_vector[0] * segment_vector[0] + point_vector[1] * segment_vector[1]) / segment_length_squared
        
        # Clamp the dot product to the range [0,1]
        t = max(0, min(1, dot_product))
        
        # Calculate the nearest point on the segment
        nearest_x = segment_start[0] + t * segment_vector[0]
        nearest_y = segment_start[1] + t * segment_vector[1]
        nearest_point = (nearest_x, nearest_y)
        
        return nearest_point

    def pose_cb(self, pose):
        """
        New initial pose (PoseWithCovarianceStamped)
        """
        if self.occ_map == False:
            self.node.get_logger().info("Map unset")
            return
        self.node.get_logger().info("Pose")
        orientation = euler_from_quaternion((
        pose.pose.pose.orientation.x,
        pose.pose.pose.orientation.y,
        pose.pose.pose.orientation.z,
        pose.pose.pose.orientation.w))
        self.s = [pose.pose.pose.position.x,pose.pose.pose.position.y,orientation[2]]
        self.car_side = self.find_which_lane(self.s[0], self.s[1])
        self.initial_location = Pose(position=Point(x=self.s[0], y=self.s[1], z=orientation[2]))

    def execute(self, blackboard: Blackboard) -> str:
        """
        When initial location and shell locations are complete, stores information in blackboard
        also publishes shell locations to "/shell_locations"

        blackboard.shell_locations = pose_array
        blackboard.init_pose = self.initial_location
        """
        waiting = True
        while waiting:
            time.sleep(self.time_to_wait)

            if self.point_count == self.NUM_SHELLS:
                if self.initial_location is not None:
                    pose_array = PoseArray()
                    pose_array.header.frame_id = "map"
                    pose_array.poses = self.array

                    blackboard.shell_locations = pose_array
                    blackboard.init_pose = self.initial_location
                    blackboard.car_side = self.car_side
                    blackboard.shell_sides = self.shell_sides
                    blackboard.car_position = self.initial_location

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


def main(args=None):
    rclpy.init(args=args)
    node = BasementPointPublisher()

    rclpy.spin(node)
    
    rclpy.shutdown()

# if __name__=="__main__":
#     main()