#ifndef PID_h
#define PID_h

#include "Arduino.h"

class PID
{
  public:
    PID(double p_input, double i_input, double d_input);
    float compute(float setpoint, float input);
  private:
    float p, i, d;
    float p_term, i_term, d_term;
    float error, delta, last_input;
    float delta_sum, delta1, delta2;
    uint32_t current_time, cycle_time, previous_time;
};

#endif

// References
// http://brettbeauregard.com/blog/2011/04/improving-the-beginners-pid-introduction/

// Usage
// PID *pid_acro_pitch = new PID(0.1, 0.005, 1);
// float total_pitch = pid_acro_pitch->compute(0, -gyro_y);