#include <iostream>
#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <auv_msgs/NavSts.h>
#include <cola2_navigation/PressureSensor.h>
#include <cola2_navigation/FastraxIt500Gps.h>
#include <cola2_navigation/TeledyneExplorerDvl.h>
#include <geometry_msgs/TwistWithCovarianceStamped.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>


void call_navi_imu (const sensor_msgs::Imu& msg) {

	ROS_WARN_STREAM ("Navigation: Imu: " << "Orientacion (x="  << msg.orientation.x << ", y=" << msg.orientation.y << ", z=" 
		<< msg.orientation.z << ", w=" << msg.orientation.w <<  ");  " 
		<< "Velocidad angular (x=" << msg.angular_velocity.x << ", y=" << msg.angular_velocity.y << ", z=" << msg.angular_velocity.z 
		<< ");  "
	    << "Aceleracion lineal (x=" << msg. linear_acceleration.x << ", y=" << msg. linear_acceleration.y << ", z="
	    << msg.linear_acceleration.z << ")");
}

void call_nav_sts (const auv_msgs::NavSts& msg) {

	ROS_WARN_STREAM ("Navigation: Nav Sts");
}

void call_preassure (const cola2_navigation::PressureSensor& msg) {

	ROS_WARN_STREAM ("Navigation: Pressure Sensor");
}

void call_gps (const cola2_navigation::FastraxIt500Gps& msg) {

	ROS_WARN_STREAM ("Navigation: GPS");
}

void call_dvl (const cola2_navigation::TeledyneExplorerDvl& msg) {

	ROS_WARN_STREAM ("Navigation: Teledyne Explorer DVL");
}

void call_pose (const geometry_msgs::PoseWithCovarianceStamped& msg) {

	ROS_INFO_STREAM ("EKF: Pose Update");
}

void call_velocity (const geometry_msgs::TwistWithCovarianceStamped& msg) {

	ROS_INFO_STREAM ("EKF: Velocity Update");
}

void call_imu_input (const sensor_msgs::Imu& msg) {

	ROS_INFO_STREAM ("EKF: Imu Input");
}

void call_odometry (const nav_msgs::Odometry& msg) {

	ROS_INFO_STREAM ("EKF: Odometry");
}






int main(int argc, char **argv)
{
	ros::init (argc, argv, "collector_node");
	ros::NodeHandle nh;

	ros::Subscriber sub1 = nh.subscribe ("cola2_navigation/imu", 1000, &call_navi_imu);
	ros::Subscriber sub2 = nh.subscribe ("cola2_navigation/nav_sts", 1000, &call_nav_sts);
	ros::Subscriber sub3 = nh.subscribe ("cola2_navigation/pressure_sensor", 1000, &call_preassure);
	ros::Subscriber sub4 = nh.subscribe ("cola2_navigation/fastrax_it_500_gps", 1000, &call_gps);
	ros::Subscriber sub5 = nh.subscribe ("cola2_navigation/teledyne_explorer_dvl", 1000, &call_dvl);
	ros::Subscriber sub6 = nh.subscribe ("pose_ekf_slam/pose_update", 1000, &call_pose);
	ros::Subscriber sub7 = nh.subscribe ("pose_ekf_slam/velocity_update", 1000, &call_velocity);
	ros::Subscriber sub8 = nh.subscribe ("pose_ekf_slam/imu_input", 1000, &call_imu_input);
	ros::Subscriber sub9 = nh.subscribe ("pose_ekf_slam/odometry", 1000, &call_odometry);

	ros::spin();

	return 0;
}