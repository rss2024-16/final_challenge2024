import rclpy
from rclpy.node import Node
from yasmin import StateMachine, State
from std_msgs.msg import String

class CityDrivingStateMachine(Node):

    def __init__(self):
        super().__init__('city_driving_state_machine')
        self.state_machine = StateMachine()

        # Define states
        start_state = State('Start', self.start_callback)
        navigate_state = State('Navigate', self.navigate_callback)
        approach_stop_sign_state = State('Approach_Stop_Sign', self.approach_stop_sign_callback)
        stop_at_sign_state = State('Stop_At_Sign', self.stop_at_sign_callback)
        pick_up_shell_state = State('Pick_Up_Shell', self.pick_up_shell_callback)
        return_to_start_state = State('Return_to_Start', self.return_to_start_callback)

        # Add states to the state machine
        self.state_machine.add_state(start_state)
        self.state_machine.add_state(navigate_state)
        self.state_machine.add_state(approach_stop_sign_state)
        self.state_machine.add_state(stop_at_sign_state)
        self.state_machine.add_state(pick_up_shell_state)
        self.state_machine.add_state(return_to_start_state)

        # Define transitions
        self.state_machine.add_transition(start_state, navigate_state)
        self.state_machine.add_transition(navigate_state, approach_stop_sign_state)
        self.state_machine.add_transition(approach_stop_sign_state, stop_at_sign_state)
        self.state_machine.add_transition(stop_at_sign_state, navigate_state)
        self.state_machine.add_transition(navigate_state, pick_up_shell_state)
        self.state_machine.add_transition(pick_up_shell_state, return_to_start_state)

        # Start the state machine
        self.state_machine.start()

    def start_callback(self):
        self.get_logger().info('Starting the City Driving State Machine')

    def navigate_callback(self):
        self.get_logger().info('Navigating through the course')

    def approach_stop_sign_callback(self):
        self.get_logger().info('Approaching a stop sign')

    def stop_at_sign_callback(self):
        self.get_logger().info('Stopping at the stop sign')

    def pick_up_shell_callback(self):
        self.get_logger().info('Picking up a shell')

    def return_to_start_callback(self):
        self.get_logger().info('Returning to the start')

def main(args=None):
    rclpy.init(args=args)
    city_driving_state_machine = CityDrivingStateMachine()
    rclpy.spin(city_driving_state_machine)
    city_driving_state_machine.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
