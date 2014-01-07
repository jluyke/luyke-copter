#ifndef PID_h
#define PID_h

#include "Arduino.h"

class PID
{
	public:
		void Setup(double p, double i, double d);
		double Compute(double setpoint, double filter_input, double gyro_input);
	private:
		double P;
		double I;
		double D;
		double PTerm, ITerm, DTerm;
		double delta, lastGyro, deltaSum, delta2, delta1;
};

#endif