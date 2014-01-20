#include "PID.h"

void PID::setup(double p_input, double i_input, double d_input) // todo: add in sample time like in pid_v1 to different boards
{
	p = p_input;
	i = i_input;
	d = d_input;
}

double PID::compute(double setpoint, double filter_input, double gyro_input) // setpoint = 0 for level mode
{
	double error = setpoint - filter_input;

	p_term = p * error;

	i_term += i * error;
	
	delta = gyro_input - last_gyro;
	last_gyro = gyro_input;
	delta_sum = delta1 + delta2 + delta;
	delta2 = delta1;
	delta1 = delta;
	d_term = (delta_sum/(double)20) * d;
  d_term *= abs(d_term);

	// d_term = ((delta/(double)10)/(double)4) * d; // alternative to above

	// p_term = 0;
	// i_term = 0;
	// d_term = 0;
  p_term = constrain(p_term, -50, 50);
  i_term = constrain(i_term, -50, 50);
  d_term = constrain(d_term, -100, 100);
	return p_term + i_term - d_term;
}