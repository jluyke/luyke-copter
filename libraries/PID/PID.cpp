#include "PID.h"

void PID::Setup(double p, double i, double d) // todo: add in sample time like in pid_v1 to different boards
{
	P = p;
	I = i;
	D = d;
}

double PID::Compute(double setpoint, double filter_input, double gyro_input) // setpoint = 0 for level mode
{
	//int output = 0;
	double error = setpoint - filter_input;
	PTerm = P * error;
	
	//PTerm = 0;
	//ITerm = I * error;
	ITerm += I * error;
	//ITerm = 0;
	
	delta = gyro_input - lastGyro;
	lastGyro = gyro_input;
	// deltaSum = delta1 + delta2 + delta;
	// delta2 = delta1;
	// delta1 = delta;
	// deltaSum = (deltaSum/10);
	// DTerm = deltaSum * D;
	DTerm = (delta/10)/4;
	// Serial.print(PTerm);
	// Serial.print(" ");
	// Serial.print(ITerm);
	// Serial.print(" ");
	// Serial.println(DTerm);
	// PTerm = 0;
	//ITerm = 0;
	//DTerm = 0;

	return PTerm + ITerm - DTerm;
}