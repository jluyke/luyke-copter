#include "Motors.h"

void Motors::setup()
{
	double p = 1;
	double i = 0.01;
	double d = 0.1;
	pid_pitch.setup(p,i,d);
	pid_roll.setup(p,i,d);
	standby_speed = 900;
}

void Motors::calc_thrust_sensor_assisted(float comp_filter_pitch, float comp_filter_roll, int gyro_x, int gyro_y, int tx_pitch, int tx_roll, int tx_throttle, int tx_yaw)
{
	pid_computed_pitch_error = pid_pitch.compute(0,comp_filter_pitch,-gyro_y);
	pid_computed_roll_error = pid_roll.compute(0,comp_filter_roll,-gyro_x);
	// Serial.print(pid_computed_pitch_error);
	// Serial.print(" ");
	// Serial.println(pid_computed_roll_error);

	if (tx_throttle > standby_speed) {
		tx_yaw = 0;
		//front_left_thrust = tx_throttle + (pid_computed_pitch_error - pid_computed_roll_error) - tx_yaw;
		front_right_thrust = tx_throttle + (pid_computed_pitch_error + pid_computed_roll_error) + tx_yaw;
		rear_left_thrust = tx_throttle + (-pid_computed_pitch_error - pid_computed_roll_error) + tx_yaw;
		//rear_right_thrust = tx_throttle + (-pid_computed_pitch_error + pid_computed_roll_error) - tx_yaw;
	} else {
		front_left_thrust = standby_speed;
		front_right_thrust = standby_speed;
		rear_left_thrust = standby_speed;
		rear_right_thrust = standby_speed;
	}
}

void Motors::calc_thrust_manual(int tx_pitch, int tx_roll, int tx_throttle, int tx_yaw)
{
	front_left_thrust = tx_throttle + tx_pitch - tx_roll - tx_yaw;
	front_right_thrust = tx_throttle + tx_pitch + tx_roll + tx_yaw;
	rear_left_thrust = tx_throttle - tx_pitch - tx_roll + tx_yaw;
	rear_right_thrust = tx_throttle - tx_pitch + tx_roll - tx_yaw;
}