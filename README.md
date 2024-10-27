# MicroROS
MicroROS package to manually control two wheeled differential drive robot using teleop with Ubuntu 22.04 & ROS2 Humble

Getting Started
1. Create & go to your new workspace (if you don't have one):
   ```bash
   mkdir ros2_ws
   cd ros2_ws
   mkdir src
   cd src

   or

3. Go to your workspace (if you already have one):
   cd <yourworkspacename>
   cd src
   
4. Clone this repository to your ROS2 workspace:
   git clone https://github.com/AdibSuid/MicroROS.git
  
5. Clone teleop_twist_joy repository to your ROS2 workspace:
   git clone https://github.com/ros2/teleop_twist_joy.git -b humble

6. Clone micro-ROS-Agent repository to your ROS2 workspace:
   git clone https://github.com/micro-ROS/micro-ROS-Agent.git -b humble

7. Build the ROS2 package and install dependencies:
   cd  ..
   rosdep install --from-paths src --ignore-src -r -y
   colcon build --symlink-install
   source install/local_setup.bash

8. Upload the microros sketch to ESP32 using Arduino IDE.
9. Launch the MicroROS robot:
   ros2 launch MicroROS var_launch.py
