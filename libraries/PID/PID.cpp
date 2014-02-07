#include "PID.h"

PID::PID(double p_input, double i_input, double d_input) 
{
  p = p_input;
  i = i_input;
  d = d_input;
}

float PID::compute(float setpoint, float input)
{
  error = setpoint - input;
  error += error * i;
  // timing - todo: remove derivative kick via dt
  // current_time = micros();
  current_time = millis();
  cycle_time = current_time - previous_time;
  previous_time = current_time;
  // p
  p_term = (error/(float)100) * p;
  p_term = constrain(p_term, -100, 100);
  // i
  i_term += (i * error)/(float)100;
  i_term = constrain(i_term, -100, 100);
  // d
  delta = input - last_input;
  delta = constrain(delta, -800, 800); // "gyro value 800 max" - multiwii
  last_input = input;
  // "add moving average here to reduce noise" - multiwii
  delta_sum = delta1 + delta2 + delta;
  delta2 = delta1;
  delta1 = delta;
  d_term = (delta_sum/(float)200) * d;
  d_term = constrain(d_term, -150, 150);
  return p_term + i_term - d_term;
}