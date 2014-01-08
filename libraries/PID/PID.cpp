#include "PID.h"

void PID::setup(double p_input, double i_input, double d_input) // todo: add in sample time like in pid_v1 to different boards
{
	p = p_input;
	i = i_input;
	d = d_input;
}

double PID::compute(double setpoint, double filter_input, double gyro_input) // setpoint = 0 for level mode
{
	//int output = 0;
	double error = setpoint - filter_input;
	p_term = p * error;
	
	//PTerm = 0;
	//ITerm = I * error;
	i_term += i * error;
	//ITerm = 0;
	
	delta = gyro_input - last_gyro;
	last_gyro = gyro_input;
	// deltaSum = delta1 + delta2 + delta;
	// delta2 = delta1;
	// delta1 = delta;
	// deltaSum = (deltaSum/10);
	// DTerm = deltaSum * D;
	d_term = (delta/10)/4;
	// Serial.print(PTerm);
	// Serial.print(" ");
	// Serial.print(ITerm);
	// Serial.print(" ");
	// Serial.println(DTerm);
	// PTerm = 0;
	//ITerm = 0;
	//DTerm = 0;

	return p_term + i_term - d_term;
}