#include "PID.h"

void PID::setup(double p_input, double i_input, double d_input)
{
  p = p_input;
  i = i_input;
  d = d_input;
}

double PID::compute(double setpoint, double input) // todo: remove derivative kick via dt
{
  error = setpoint - input;
  // P
  p_term = (error/(double)100) * p;
  p_term = constrain(p_term, -100, 100);
  // I
  i_term += (i * error)/(double)100;
  i_term = constrain(i_term, -50, 50);
  // D
  delta = input - last_input;
  delta = constrain(delta, -800, 800); // gyro value 800 max per multiwii
  last_input = input;
  d_term = (delta/(double)100) * d;
  d_term = constrain(d_term, -100, 100);
  //
  return p_term + i_term - d_term;
}