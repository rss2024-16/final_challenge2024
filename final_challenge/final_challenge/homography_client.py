#!/usr/bin/env python

import rclpy
from rclpy.node import Node
import numpy as np

from fc_msgs.srv import UvToXy, XyToUv


class HomographyClient(Node):
    def __init__(self):
        super().__init__("homography_client")
        self.cli = self.create_client(UvToXy, 'uv_to_xy')
        self.cli2 = self.create_client(XyToUv,'xy_to_uv')
        while not self.cli.wait_for_service():
            self.get_logger().info('waiting')
        self.req = UvToXy.Request()
        self.req2 = XyToUv.Request()
    
    def send_request(self,u,v):
        self.req.u = u
        self.req.v = v

        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self,self.future)
        res = self.future.result()
        return res.x,res.y
    
    def send_request_2(self,x,y):
        self.req2.x = x
        self.req2.y = y

        self.future = self.cli2.call_async(self.req2)
        rclpy.spin_until_future_complete(self,self.future)
        res = self.future.result()
        return res.u,res.v

    def main():
        rclpy.init()
        homography_client = HomographyClient()
        homography_client.destroy_node()
        rclpy.shutodwn()

    if __name__ == '__main__':
        main()