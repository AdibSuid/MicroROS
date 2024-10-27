#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from std_msgs.msg import Int8

class JoystickController(Node):
    def __init__(self):
        super().__init__('var_joy')
        self.subscription = self.create_subscription(
            Joy,
            '/joy',
            self.joy_callback,
            10
        )
        self.linearUT_publisher = self.create_publisher(Int8, '/linearUT', 10)
        self.linearBrush_publisher = self.create_publisher(Int8, '/linearBrush', 10)
        self.Brush_publisher = self.create_publisher(Int8, '/Brush', 10)

    def joy_callback(self, msg):
        # Check if the message has enough buttons
        if len(msg.buttons) >= 6:
            button_A = msg.buttons[0]
            button_B = msg.buttons[1]
            button_X = msg.buttons[2]
            button_Y = msg.buttons[3]
            button_L1 = msg.buttons[4]
            button_L2 = msg.buttons[6]

            # Handle button presses and publish corresponding values on /LEDs topic
            if button_A == 1:
                self.publish_linearUT_value(1)
            elif button_B == 1:
                self.publish_linearUT_value(0)
            elif button_X == 1:
                self.publish_linearUT_value(2)
            elif button_Y == 1:
                self.publish_linearUT_value(3)
            elif button_L1 == 1:
                self.publish_Brush_value(1)
            elif button_L2 == 1:
                self.publish_Brush_value(0)

            # Handle servo control based on axes 6 and 7
            axis_6_value = msg.axes[6]
            axis_7_value = msg.axes[7]

            if axis_7_value == 1:
                self.publish_linearBrush_value(1)
            elif axis_7_value == -1:
                self.publish_linearBrush_value(2)
            elif axis_6_value == 1:
                self.publish_linearBrush_value(3)
            elif axis_6_value == -1:
                self.publish_linearBrush_value(0)

    def publish_linearUT_value(self, value):
        linearUT_msg = Int8()
        linearUT_msg.data = value
        self.linearUT_publisher.publish(linearUT_msg)

    def publish_linearBrush_value(self, value):
        linearBrush_msg = Int8()
        linearBrush_msg.data = value
        self.linearBrush_publisher.publish(linearBrush_msg)
    
    def publish_Brush_value(self, value):
        Brush_msg = Int8()
        Brush_msg.data = value
        self.Brush_publisher.publish(Brush_msg)

def main(args=None):
    rclpy.init(args=args)
    node = JoystickController()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
