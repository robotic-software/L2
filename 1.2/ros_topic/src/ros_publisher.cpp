//
#include "ros/ros.h" //include ros header file
#include "std_msgs/Int32.h"  //header file of the message to publish
#include <iostream>

int main(int argc, char **argv) {

	//
	ros::init(argc, argv,"ros_topic_publisher");
	ros::NodeHandle nh;
	//Publish an integer on topic called number
	ros::Publisher topic_pub =
	nh.advertise<std_msgs::Int32>("/numbers", 10);


	/*
		//---
		Do calculation
		//--- 1 second

		wait for 1 second

		loop time: 2 second
	*/
	
	ros::Rate rate(10); //Rate
	int count = 0;

	while (ros::ok() /* true */) {

		std_msgs::Int32 msg; 

		msg.data = count++;
		ROS_INFO("%d",msg.data); //printf

		topic_pub.publish(msg);
		
		rate.sleep();
	}
	return 0;
}
