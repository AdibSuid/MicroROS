import launch
import launch.actions
import launch.substitutions
import launch_ros.actions

def generate_launch_description():
    return launch.LaunchDescription([
        launch.actions.ExecuteProcess(
            cmd=['ros2', 'run', 'micro_ros_agent', 'micro_ros_agent', 'serial', '--dev', '/dev/ttyUSB0'],
            output='screen',
        ),
        launch.actions.ExecuteProcess(
            cmd=['ros2', 'launch', 'teleop_twist_joy', 'teleop-launch.py'],
            output='screen',
        ),
        launch.actions.ExecuteProcess(
            cmd=['ros2', 'run', 'MicroROS', 'var_joy.py'],
            output='screen',
        ),
    ])
