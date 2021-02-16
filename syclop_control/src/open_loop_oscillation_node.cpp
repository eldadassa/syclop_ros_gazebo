#include "ros/ros.h"
#include "std_msgs/Float64.h"

#include <cmath>

#define PI 3.14159265

#define CMD_RATE_DEFAULT 100
#define OSC_FREQ_DEFAULT 2.0
#define OSC_AMP_DEFAULT 8.0

int main(int argc, char **argv)
{
//ROS_INFO("initalizing open loop oscillations with the following parameters:\n");
 //ROS_INFO("command rate: %d sec(-1)\n", CMD_RATE);
 //ROS_INFO("oscillation freq: %.1f Hz\n", OSC_FREQ);
 //ROS_INFO("oscillation amp: %.2f rad*sec(-1)\n",OSC_AMP);

  //Initializing node
  ros::init(argc, argv, "open_loop_oscillation");

  ros::NodeHandle n;
  ros::Publisher cmd_pub = n.advertise<std_msgs::Float64>("/syclop/pan_position_controller/command", 1);

  int iTmp = 0;
  double dTmp = 0.0;
  int cmd_rate =  CMD_RATE_DEFAULT;
  if (n.getParam("cmd_rate", iTmp)) {
     cmd_rate = iTmp;
  }
  double osc_freq = OSC_FREQ_DEFAULT;
  if (n.getParam("osc_freq", dTmp)) {
     osc_freq = dTmp;
  }
  double osc_amp = OSC_AMP_DEFAULT;
  if (n.getParam("osc_amp", dTmp)) {
     osc_amp = dTmp;
  }
  ROS_INFO("initalizing open loop oscillations with the following parameters:\n %d, %f, %f", cmd_rate, osc_freq, osc_amp);

  ros::Rate loop_rate(cmd_rate);

  std_msgs::Float64 msg;
  double cmd = 0.0;
  ros::Time curr_time(0.0);
  //ros::Duration osc_duration_in_sec(0.0);
  double osc_duration_in_sec(0.0);
  ros::Time init_time =ros::Time::now();
  long sent_cmd_count = 0;
  while (ros::ok())
  {
     curr_time =ros::Time::now();
     osc_duration_in_sec = (curr_time-init_time).toSec();
    // cmd = OSC_AMP*cos(OSC_FREQ*osc_duration_in_sec*2*PI);
     cmd = osc_amp*cos(osc_freq*osc_duration_in_sec*2*PI);

     msg.data = cmd;
     //ROS_INFO("%s", msg.data.c_str());
     cmd_pub.publish(msg);
     sent_cmd_count++;

     ros::spinOnce();
     loop_rate.sleep();
  }

  ROS_INFO("open loop oscillations node is being terminated\n");
 // ROS_INFO("%ld coomands were sent\n", sent_cmd_count);
  return 0;
}
