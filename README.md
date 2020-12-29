# syclop_ros_gazebo
This repository contains the src files for ros definitions and drivers of syclop as well as gazebo simulation.

## Dependencies:
* [gazebo_dvs_plugin](https://github.com/HBPNeurorobotics/gazebo_dvs_plugin).
* [RPG DVS ROS](https://github.com/uzh-rpg/rpg_dvs_ros).
* single_edge2 (gazebo model) [TODO: add model to rep].
* ros_control pkg (?)
* ...

## Install:

First, follow the instructions in [gazebo_dvs_plugin](https://github.com/HBPNeurorobotics/gazebo_dvs_plugin) to install dvs ros drivers and Gazebo plugin.

Then, clone this package (syclop_description, syclop_control and syclop_gazebo directories) into your workspace (e.g. catkin_ws/src) and rebuild ('catkin build' or 'catkin_make').

## syclop-ros-gazebo run setup:

for each step (1-4) open a new terminal source the env file (source ./ros-gazebo.env) and run the cmd:
1. roslaunch syclop_gazebo syclop_world.launch
2. roslaunch syclop_control syclop_control.launch
3. roslaunch syclop_control syclop_rqt.launch (optional)
4. roslaunch syclop_gazebo gazebo_dvs_renderer.launch (optional)
