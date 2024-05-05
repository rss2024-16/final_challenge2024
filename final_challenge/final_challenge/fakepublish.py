import rclpy
from rclpy.node import Node

from sensor_msgs.msg import Image
import cv2

from cv_bridge import CvBridge

class FakeImagePub(Node):
    def __init__(self):
        super().__init__('fake_image_pub')

        self.bridge = CvBridge()

        self.publisher = self.create_publisher(Image, "/zed/zed_node/rgb_gray/image_rect_gray", 5)

        self.timer_cb = self.create_timer(5.0/10.0, self.pub_image)

        prefix = '/home/racecar/racecar_ws/src/final_challenge2024/final_challenge/final_challenge/'
        image = cv2.imread(prefix+'close_slant.jpg')
        # image = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        self.msg = self.bridge.cv2_to_imgmsg(image, encoding="bgr8")
        # self.callback(msg)

    def pub_image(self):
        self.publisher.publish(self.msg)

def main(args=None):
    rclpy.init(args=args)
    pub = FakeImagePub()
    rclpy.spin(pub)
    rclpy.shutdown()

if __name__=="__main__":
    main()