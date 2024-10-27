# MicroROS
MicroROS package to manually control two-wheeled differential drive robot using teleop with Ubuntu 22.04 & ROS2 Humble

## Getting Started
1. Create & go to your new workspace (if you don't have one):
   ```bash
   mkdir ros2_ws
   cd ros2_ws
   mkdir src
   cd src

2. Or go to your workspace (if you already have one):
   ```bash
   cd ros2_ws
   cd src
   
Note: Replace ros2_ws with your workspace name.
   
3. Clone this repository to your ROS2 workspace:
   ```bash
   git clone https://github.com/AdibSuid/MicroROS.git
  
4. Clone teleop_twist_joy repository to your ROS2 workspace:
   ```bash
   git clone https://github.com/ros2/teleop_twist_joy.git -b humble

5. Clone micro-ROS-Agent repository to your ROS2 workspace:
   ```bash
   git clone https://github.com/micro-ROS/micro-ROS-Agent.git -b humble

6. Build the ROS2 package and install dependencies:
   ```bash
   cd  ..
   rosdep install --from-paths src --ignore-src -r -y
   colcon build --symlink-install

Note: You have to source your workspace **everytime** you want to launch the package by using this command:
   ```bash
   source install/local_setup.bash

or you can auto source your workspace with this command:
   ```bash
   echo "source ~/ros2_ws/install/setup.bash" >> ~/.bashrc

& apply the changes immediately by run this command:
   ```bash
   ~/.bashrc

7. Upload the microros sketch to ESP32 using Arduino IDE. The file name is var_esp32_microros.ino
8. Connect joystick controller to the robot pc.
9. Launch the MicroROS robot:
   ```bash
   ros2 launch MicroROS var_launch.py

## Troubleshooting Guide
1. If the microros agent doesn't connect, unplug & plug the ESP32 back or press boot button. You can check if the    microros agent have successfully connected or not by open a new terminal & run
   ```bash
   ros2 topic list
  If the microros agent successfully connected, it should display like this in the terminal:
   ```bash
   
