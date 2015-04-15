#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char *argv[]) {
	ros::init(argc, argv, "naza_gps");
	ros::NodeHandle n;

	ros::Publisher naza_pub = n.advertise<std_msgs::String>("gps", 100);
	ros::Rate loop_rate(10);
	int count;
	while (ros::ok()) {
		std_msgs::String msg;
		std::stringstream ss;
		ss << "NAZA GPS " << count;
		msg.data = ss.str();
		ROS_INFO("SENDING SHIT %d", count);
		
		naza_pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
		count++;
	}
	ros::shutdown();

	return 0;
}
