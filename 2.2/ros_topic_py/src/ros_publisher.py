#!/usr/bin/env python

import rospy
from std_msgs.msg import Int32

def talker():
    pub = rospy.Publisher('number', Int32 , queue_size=1)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    to_pub = 0
    while not rospy.is_shutdown():
        
        pub.publish(to_pub)
        
        to_pub = to_pub + 1
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass