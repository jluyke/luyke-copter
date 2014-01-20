#ifndef PID_h
#define PID_h

#include "Arduino.h" //remove later

class PID
{
	public:
		void setup(double p_input, double i_input, double d_input);
		double compute(double setpoint, double filter_input, double gyro_input);
	private:
		double p, i, d;
		double p_term, i_term, d_term;
		double delta, last_gyro, delta_sum, delta2, delta1;
};

#endif