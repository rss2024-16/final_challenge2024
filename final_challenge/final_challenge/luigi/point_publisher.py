import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Point, PointStamped, Pose, PoseArray
from lane_projection import project_point

class PointPublisher(Node):

    def __init__(self):
        super().__init__("point_pub")
        self.publisher = self.create_publisher(PoseArray, "/shell_points", 1)
        self.subscriber = self.create_subscription(PointStamped, "/clicked_point", self.callback, 1)

        self.projected = None

        self.get_logger().info("Point Publisher Initialized")

    def callback(self, point_msg: PointStamped):
        x,y = point_msg.point.x, point_msg.point.y
        self.get_logger().info(f"Received point: {x}, {y}")

        self.projected = project_point(node=self, location=point_msg, right=True)
        
        self.get_logger().info("Done with point")
        
        self.publish()

    def publish(self):
        # Publish PoseArray
        pose_array = PoseArray()
        pose_array.header.frame_id = "map"
        pose_array.poses = [self.projected]

        self.publisher.publish(pose_array)

        # Reset point
        self.projected = None

def main(args=None):
    rclpy.init(args=args)
    node = PointPublisher()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__=="__main__":
    main()