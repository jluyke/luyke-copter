#ifndef PID_h
#define PID_h

#include "Arduino.h" //remove later

class PID
{
	public:
		void setup(double p_input, double i_input, double d_input);
		double compute(double setpoint, double input);
	private:
		double p, i, d;
		double p_term, i_term, d_term;
		double error, delta, last_input;
};

#endif

// http://brettbeauregard.com/blog/2011/04/improving-the-beginners-pid-introduction/