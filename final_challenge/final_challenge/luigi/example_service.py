
import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Point, PointStamped, Pose, PoseArray

from fc_msgs.srv import LaneProject

# class ExampleService(Node):

#     def __init__(self):
#         super().__init__("point_pub")
#         self.publisher = self.create_publisher(PoseArray, "/shell_points", 1)
#         self.subscriber = self.create_subscription(PointStamped, "/clicked_point", self.callback, 1)

#         # Create service and sub node, you have to do this or it will never get a result
#         self.sub_node = rclpy.create_node('sub_node')
#         self.cli = self.sub_node.create_client(LaneProject, 'lane_project')
#         while not self.cli.wait_for_service(timeout_sec=1.0):
#             self.get_logger().info('service not available, waiting again...')
#         self.req = LaneProject.Request()

#         self.projected = None

#         self.get_logger().info("Point Publisher Initialized")

#     def callback(self, point_msg: PointStamped):
#         x,y = point_msg.point.x, point_msg.point.y
#         self.get_logger().info(f"Received point: {x}, {y}")

#         # Create the request
#         self.req.location = point_msg
#         self.req.right = False      # Which lane to project to (True is right, False is left)

#         # Wait until you recieve a response
#         future = self.cli.call_async(self.req)
#         rclpy.spin_until_future_complete(self.sub_node, future)
#         response = future.result()

#         self.projected = response.projection
#         self.get_logger().info("Done with point")
        
#         self.publish()

#     def publish(self):
#         # Publish PoseArray
#         pose_array = PoseArray()
#         pose_array.header.frame_id = "map"
#         pose_array.poses = [self.projected]

#         self.publisher.publish(pose_array)

#         # Reset Array
#         self.projected = None


class ProjectionClient(Node):

    def __init__(self):
        super().__init__("projection_client")
        self.publisher = self.create_publisher(PoseArray, "/shell_points", 1)
        self.subscriber = self.create_subscription(PointStamped, "/clicked_point", self.callback, 1)

        # Create service and sub node, you have to do this or it will never get a result
        self.sub_node = rclpy.create_node('sub_node')
        self.cli = self.sub_node.create_client(LaneProject, 'lane_project')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = LaneProject.Request()

        self.projected = None

        self.get_logger().info("Shell Projection Initialized")

    def callback(self, point_msg: PointStamped):
        x,y = point_msg.point.x, point_msg.point.y
        self.get_logger().info(f"Received point: {x}, {y}")

        # Create the request
        self.req.location = point_msg
        self.req.right = False      # Which lane to project to (True is right, False is left)

        # Wait until you recieve a response
        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self.sub_node, future)
        response = future.result()

        self.projected = response.projection
        self.get_logger().info("Done with point")
        
        self.publish()

    def publish(self):
        # Publish PoseArray
        pose_array = PoseArray()
        pose_array.header.frame_id = "map"
        pose_array.poses = [self.projected]

        self.publisher.publish(pose_array)

        # Reset Array
        self.projected = None


def main(args=None):
    rclpy.init(args=args)
    node = ExampleService()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__=="__main__":
    main()