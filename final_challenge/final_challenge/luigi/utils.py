#!/usr/bin/env python
import rclpy
from rclpy.node import Node
import numpy as np

from tf_transformations import quaternion_from_euler

from path_planning.utils import LineTrajectory
from geometry_msgs.msg import Pose

class LaneProjection():
    def __init__(self):
        self.left_lane_traj = LineTrajectory(Node('lane_proj1'), "/loaded_trajectory")
        self.right_lane_traj = LineTrajectory(Node('lane_proj2'), "/loaded_trajectory")
        
        self.right_lane_traj.load("/home/racecar/racecar_ws/src/path_planning/example_trajectories/right-lane.traj")
        self.left_lane_traj.load("/home/racecar/racecar_ws/src/path_planning/example_trajectories/left-lane.traj")
            

    def get_segment(self, s, t, right):
        """
        s: start point in map frame
        t: end point in map frame
        right: bool True if right lane is desired, False if left lane is desired
        """
        projected_s_pose = self.project(s, right)
        projected_t_pose = self.project(t, right)

        proj_s = (projected_s_pose.position.x, projected_s_pose.position.y)
        proj_t = (projected_t_pose.position.x, projected_t_pose.position.y)
        
        if right:
            lane_traj = self.right_lane_traj
        else:
            lane_traj = self.left_lane_traj
       
        i = lane_traj.points.index(proj_s)
        j = lane_traj.points.index(proj_t)

        return lane_traj.points[i : j + 1]


    def project(self, location, right):
        """
        Takes in a point from the map frame and projects it to the desired lane
        Inputs:
        location - Pose: point in the map frame
        right - bool: True if right lane is desired, False if left lane is desired
        Returns: 
        projection - Pose: pose in map frame on lane
        """
        # Load in the appropriate lane trajectory
        if right:
            lane_traj = self.right_lane_traj
        else:
            lane_traj = self.left_lane_traj
            
        lane_traj.updatePoints(lane_traj.points[:])

        # Find the nearest point on the trajectory to our location
        loc = (location.position.x, location.position.y)
        nearest_point, nearest_index = self.find_nearest(loc, lane_traj.points)

        # Get the appropriate angle to follow the lane 
        if nearest_index == len(lane_traj.points):
            angle = lane_traj.points[-1][2]
        else:
            angle = lane_traj.points[nearest_index][2]


        projection = Pose()
        # Construct the projected pose
        q = quaternion_from_euler(0, 0, angle)
        projection.position.x = nearest_point[0]
        projection.position.y = nearest_point[1]
        projection.orientation.x = q[0]
        projection.orientation.y = q[1]
        projection.orientation.z = q[2]
        projection.orientation.w = q[3]

        return projection, nearest_index

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

        
        

def main(args=None):
    rclpy.init(args=args)

    service = LaneProjection()

    rclpy.spin(service)

    rclpy.shutdown()

if __name__ == '__main__':
    main()