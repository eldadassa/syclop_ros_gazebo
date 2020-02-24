# syclop_ros_gazebo
This repository contains the src files for ros definitions and drivers of syclop as well as gazebo simulation.

dependencies:
gazebo_dvs_plugin (?) [TODO: add link to rep]
rpg_dvs_ros [TODO: add link to rep]
single_edge2 (gazebo model) [TODO: add model to rep]
ros_control pkg (?)
...

installation:
copy syclop_description, syclop_control and syclop_gazebo directories to your catkin workspace src directory (usualy catkin_ws/src) and build ('catkin build' or 'catkin_make').

syclop-ros-gazebo run setup:

for each step (1-4) open a new terminal source the env file (source ./ros-gazebo.env) and run the cmd:
1. roslaunch syclop_gazebo syclop_world.launch
2. roslaunch syclop_control syclop_control.launch
3. roslaunch syclop_control syclop_rqt.launch (optional)
4. roslaunch syclop_gazebo gazebo_dvs_renderer.launch (optional)
