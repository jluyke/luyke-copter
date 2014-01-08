#ifndef Motors_h
#define Motors_h

#define PID_LIMIT 200

#include "PID.h"

class Motors
{
	public:
		void setup();
		void calc_thrust_sensor_assisted(float comp_filter_pitch, float comp_filter_roll, int gyro_x, int gyro_y, int tx_pitch, int tx_roll, int tx_throttle, int tx_yaw);
		void calc_thrust_manual(int tx_pitch, int tx_roll, int tx_throttle, int tx_yaw);
		int get_front_left_thrust() { return front_left_thrust; }
		int get_front_right_thrust() { return front_right_thrust; }
		int get_rear_left_thrust() { return rear_left_thrust; }
		int get_rear_right_thrust() { return rear_right_thrust; }
	private:
		int front_left_thrust;
		int front_right_thrust;
		int rear_left_thrust;
		int rear_right_thrust;
		//
		PID pid_pitch;
		PID pid_roll;
		double pid_computed_pitch_error;
		double pid_computed_roll_error;
		int motor_standby_speed;
};

#endif