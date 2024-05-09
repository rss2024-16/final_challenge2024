import rclpy
from ackermann_msgs.msg import AckermannDriveStamped
from geometry_msgs.msg import PoseArray, Pose
from rclpy.node import Node
from nav_msgs.msg import Odometry
from visualization_msgs.msg import Marker, MarkerArray
from std_msgs.msg import Float32

from tf_transformations import euler_from_quaternion
import tf2_ros

import numpy as np

from path_planning.utils import LineTrajectory
import math
import time

# from yasmin_ros.yasmin_node import YasminNode

"""
TODO:
np argmin optimize for time
bug if goal pose is facing forward
xdot sometimes gives answer if initial trajectory is also ahead of goal

error plots
Make sure you mention your method for tuning the controller to closely track trajectories. 
(Hint: include error plots from rqt_plot)

y distance from closest segment
slope
lookahead
speed

ros2 launch path_planning sim_yeet.launch.xml
"""

class PID(Node):
    """ 
    Implements Pure Pursuit trajectory tracking with a fixed lookahead and speed.
    """

    def __init__(self, goal=True):
        super().__init__('pid_controller')
        self.declare_parameter('odom_topic', "default")
        self.declare_parameter('drive_topic', "default")

        # self.odom_topic = self.get_parameter('odom_topic').get_parameter_value().string_value
        # self.drive_topic = self.get_parameter('drive_topic').get_parameter_value().string_value
        self.odom_topic = "/pf/pose/odom"
        self.drive_topic = "/vesc/input/navigation"
        #self.drive_topic = '/drive'

        self.driving_to_shell = goal

        self.points = None
        self.current_pose = None
        self.intersections = None
        self.turning_markers = []
        self.goal = None

        self._succeed = None
        
        self.MAX_TURN = 0.34

        self.trajectory = LineTrajectory("/followed_trajectory")

        self.traj_sub = self.create_subscription(PoseArray,
                                                 "/trajectory/current",
                                                 self.trajectory_callback,
                                                 1)
        self.drive_pub = self.create_publisher(AckermannDriveStamped,
                                               self.drive_topic,
                                               1)
        
        self.pose_sub = self.create_subscription(Odometry, self.odom_topic, self.pose_callback, 1)

        self.transform = lambda theta: np.array([ [np.cos(theta), -np.sin(theta), 0],
                                             [np.sin(theta), np.cos(theta), 0],
                                             [0, 0, 1]
                                            ])
        
        self.get_logger().info('initialized')
        
        # self.relative_point_pub = self.create_publisher(MarkerArray,'/relative',1)
        # self.circle = self.create_publisher(MarkerArray, '/circle_marker', 1)
        self.intersection = self.create_publisher(Marker,'/intersection',1)
        # self.closest = self.create_publisher(Marker,'/closest',1)
        # self.segments = self.create_publisher(MarkerArray, '/segments', 1)
        # self.turning_points = self.create_publisher(MarkerArray, '/turning_points', 1)
        self.previous_angles = []

        self.previous_errors = []

        self.all_controls = []


        self.distance_check = False
        self.last_time = None
        self.last_error = None
        self.last_integral = None
        self.integral_count = 0

        self.last_point = None

        self.traveled_points = set()

    @property
    def success(self): return self._succeed

    def reset_success(self): self._succeed = None

    def distance(self, p1, p2):
        return np.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

    def find_minimum_distance(self, v, w, p):
        """
        returns the minimum distance between point p and the line segment vw
        """
        distance_squared = (v[0] - w[0])**2 + (v[1] - w[1])**2
        if distance_squared == 0.0:
            return self.distance(p, v)
        # self.get_logger().info(f"distance squared: {distance_squared}")
        t = max(0, min(1, np.dot(p - v, w - v) / distance_squared))
        projection = v + t * (w - v)
        return self.distance(p, projection)
    
    def find_closest_point(self,R):
        differences = self.points - self.current_pose
        relative_points = np.array([np.matmul(i,R) for i in differences])
        distances = ( (relative_points[:,0])**2 + relative_points[:,1]**2 ) ** (1/2)
        closest = np.argmin(distances)
        
        return relative_points[closest], distances[closest], closest

    def find_closest_point_on_trajectory(self, relative_points, reverse=False):
        """
        Find the point on the trajectory nearest to the car's position.
        relative points: the points on trajectory, converted into the car's frame of reference
        """
        closest_point , index, closest_segment = None, 0, None
        min_distance = float('inf')
        
        xdot = np.dot(relative_points[:,0], 1) #dot will return 0 if difference is negative (pt is behind)

        #TODO optimize using argmin??
        for i in range(len(relative_points) - 1):
            segment_start = relative_points[i]
            segment_end = relative_points[i + 1]
            
            if tuple(self.points[i]) not in self.traveled_points: #in front of car
                distance = self.find_minimum_distance(segment_start, segment_end, np.array([0,0,0]))
                if distance < min_distance:
                    min_distance = distance
                    closest_point = segment_start
                    closest_segment = (segment_start, segment_end)
                    index = i

        # distances = self.find_minimum_distance_array(self.segments, np.array([0,0,0]))
        # self.get_logger().info(f"array: {distances}")
        # self.get_logger().info(f"min distance: {min_distance}")
        
        distance_to_goal = self.distance(np.array([0,0,0]), relative_points[-1]) #distance to goal pose

        # closest_intersect = self.closest_intersect()
        # if closest_intersect is not None:
        #     closest_point_intersect = closest_intersect[0]
        #     closest_global = np.matmul(closest_point_intersect, np.linalg.inv(R)) + self.current_pose
        #     self.closest.publish(self.to_marker(closest_global, 0, [0.0, 0.0, 1.0], 0.5))
        
        # if closest_intersect is not None:
        #     closest_intersect_distance = closest_intersect[1]
        # else:
        #     closest_intersect_distance = None

        if distance_to_goal < 0.5: 
            # self.get_logger().info("close enough to goal")
            self._succeed = True
            return True, None, None
        elif closest_point is None:
            # self.get_logger().info("no points in front of car")
            self._succeed = False
            return False, None, None
        
        # self.publish_marker_array(self.relative_point_pub, np.array([closest_point]), R, self.current_pose, rgb=[1.0, 0.0, 0.0])
        return closest_point, index, distance_to_goal
        
    def pose_callback(self, odometry_msg):
        """
        publishes pure pursuit upon odom callback
        """
        x = odometry_msg.pose.pose.position.x
        y = odometry_msg.pose.pose.position.y

        orientation = euler_from_quaternion((
        odometry_msg.pose.pose.orientation.x,
        odometry_msg.pose.pose.orientation.y,
        odometry_msg.pose.pose.orientation.z,
        odometry_msg.pose.pose.orientation.w))

        theta = orientation[2]
        R = self.transform(theta)
        self.current_pose = np.array([x,y,theta])  #car's coordinates in global frame
        # theta += np.pi

        drive_cmd = AckermannDriveStamped()
        if self.points is not None:
            closest_point, dist, idx = self.find_closest_point(R)
            
            # self.get_logger().info("index: " + str(index))
            # self.get_logger().info("distance to goal: " + str(distance_to_goal))

            distance_to_goal = self.distance(np.array([0,0,0]), self.goal-self.current_pose)
            if self.driving_to_shell and distance_to_goal < 3.0:
                drive_cmd.drive.speed = 0.0
                drive_cmd.drive.steering_angle = 0.0
                self.drive_pub.publish(drive_cmd)
                self._succeed = True
            elif distance_to_goal< 0.5:
                drive_cmd.drive.speed = 0.0
                drive_cmd.drive.steering_angle = 0.0
                self.drive_pub.publish(drive_cmd)
                self._succeed = True
            else:
                # if self.last_point is None:
                #     self.last_point = self.points[0]
                #     self.traveled_points.add(tuple(self.points[0]))
                if dist < 0.5: #probs different irl
                    # self.traveled_points.add(tuple(closest_point))
                    self.points = np.delete(self.points,idx,axis=0)
                # self.get_logger().info(f'{self.traveled_points}')
                global_intersect = np.matmul(closest_point, np.linalg.inv(R)) + self.current_pose
                self.intersection.publish(self.to_marker(global_intersect, 0, [0.0, 1.0, 0.0], 0.5))
                # pt = self.points[index]
                # norm_track_theta = (pt[2] + np.pi) % (2 * np.pi) - np.pi
                # norm_theta = (theta + np.pi) % (2 * np.pi) - np.pi
                # error_from_trajectory = closest_point[1]
                # slope = closest_point[1]/closest_point[0] #y /x 
                speed = 2.0
                # error = (norm_track_theta - norm_theta)
                # if error > np.pi:
                #     error -= np.pi
                # elif error < -np.pi:
                #     error += np.pi
                error = 0
                # error = np.arctan2( np.sin(closest_point[2]-theta), np.cos(closest_point[2]-theta) )
                # error = error - 2*np.pi if error > np.pi else error + np.pi
                # error = (error + np.pi) % (2 * np.pi) - np.pi

                theta_xc = np.arctan2(closest_point[1], speed)
                self.get_logger().info(f'track: {closest_point[2]}, theta: {theta}')
                self.get_logger().info(f'heading: {error} cross track: {theta_xc}')

                error += theta_xc

                drive_cmd = AckermannDriveStamped()

                #what worked for speed 3.0 - Kp 0.7, Kd = Kp/6.0, Ki = 0 (didnt test), turning angle += -0.04


                ####### BOT TUNING DO NOT CHANGE #########
                Kp = .25# previous Kp is 0.635
                Kd = Kp / 6.0
                Ki = 0#-Kp / 2.0
                # # self.previous_errors.append(error)

                ############# SIM PARAMS ##########
                # Kp = .25
                # Kd = Kp/6.0
                # Ki = 0


                P = Kp* ( error )
                if self.last_time is not None:
                    dt = self.get_clock().now().nanoseconds/1e9 - self.last_time
                    I = self.last_integral + Ki*error*dt
                    self.integral_count += 1
                    D = Kd * (error-self.last_error)/dt
                else:
                    I = 0
                    D = 0

                control = P + I + D
                self.get_logger().info(f'{error}')
                self.get_logger().info(f'P: {round(P,3)} I: {round(I,3)} D: {round(D,3)}')
                self.previous_errors.append(error)
                self.all_controls.append((P,I,D))

                turning_angle = control
                # turning_angle += -0.045
                turning_angle += -0.03

                # self.get_logger().info(f'{turning_angle}')
                            
                if abs(turning_angle) > self.MAX_TURN:
                    turning_angle = self.MAX_TURN if turning_angle > 0 else -self.MAX_TURN


                if closest_point[0] < 0:
                    speed = -1.6
                    turning_angle = -turning_angle

                drive_cmd.drive.speed = speed
                drive_cmd.drive.steering_angle = turning_angle

                self.drive_pub.publish(drive_cmd)
                self.last_time = self.get_clock().now().nanoseconds/1e9
                self.last_error = error
                self.last_integral = I
                if self.integral_count == 15:
                    self.last_integral = 0
                    self.integral_count = 0


            self.drive_pub.publish(drive_cmd)

    def reset_distances(self):
        distances = []
        num_points = len(self.points)

        for i in range(num_points):
            if i == 0:
                distances.append(0)
            else:
                p0 = self.points[i - 1]
                p1 = self.points[i]
                delta = np.array([p0[0] - p1[0], p0[1] - p1[1]])
                distances.append(distances[i - 1] + np.linalg.norm(delta))
        return distances
        
    def trajectory_callback(self, msg):
        """
        msg: PoseArray
        geometry_msgs/msg/Pose[] poses
            geometry_msgs/msg/Point position
            geometry_msgs/msg/Quaternion orientation
        """
        self.get_logger().info(f"Receiving new trajectory {len(msg.poses)} points")

        # self.points = np.array([(i.position.x,i.position.y,position) for i in msg.poses]) #no theta 
        # self.get_intersections()
        # self.goal = self.points[-1]

        self.trajectory.clear()
        self.trajectory.fromPoseArray(msg)
        self.points = np.array(self.trajectory.points)
        if self.points.shape[-1] != 3:
            self.get_logger().info('hi')
            # self.points = self.reset_distances()
            # self.update
            self.trajectory.updatePoints(self.points)
            self.points = np.array(self.trajectory.points)
        self.goal = self.points[-1]
        self.trajectory.publish_viz(duration=0.0)

        self.initialized_traj = True

    def to_marker(self,position,id = 1,rgb=[1.0,0.0,0.0],scale=0.25):
        marker = Marker()
        marker.header.frame_id = "/map"  # Set the frame id
        marker.header.stamp = self.get_clock().now().to_msg()
        marker.ns = "/followed_trajectory/trajectory"
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
    follower = PID()
    try:
        rclpy.spin(follower)
    except KeyboardInterrupt:
        drive_cmd = AckermannDriveStamped()
        drive_cmd.drive.speed = 0.0
        drive_cmd.drive.steering_angle = 0.0
        follower.drive_pub.publish(drive_cmd)
    rclpy.shutdown()



    