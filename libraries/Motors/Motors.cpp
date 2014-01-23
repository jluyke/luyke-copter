#include "Motors.h"

void Motors::setup()
{
  setup_acro_pids(0.5,0,5);
  setup_level_pids(25,0,500);
  standby_speed = 900;
}

void Motors::setup_acro_pids(double p, double i, double d)
{
  pid_acro_pitch.setup(p,i,d);
  pid_acro_roll.setup(p,i,d);
}

void Motors::setup_level_pids(double p, double i, double d)
{
  pid_level_pitch.setup(p,i,d);
  pid_level_roll.setup(p,i,d);
}

void Motors::calc_thrust_level_mode(float comp_filter_pitch, float comp_filter_roll, int gyro_x, int gyro_y, int tx_pitch, int tx_roll, int tx_throttle, int tx_yaw)
{
  total_pitch = pid_acro_pitch.compute(0,-gyro_y) + pid_level_pitch.compute(0,comp_filter_pitch);
  total_roll = pid_acro_roll.compute(0,-gyro_x) + pid_level_roll.compute(0,comp_filter_roll);
  // Serial.print(total_pitch);
  // Serial.print(" ");
  // Serial.println(total_roll);
  if (tx_throttle > standby_speed) {
    tx_yaw = 0;
    //front_left_thrust = tx_throttle + (total_pitch - total_roll) - tx_yaw;
    front_right_thrust = tx_throttle + (total_pitch + total_roll) + tx_yaw;
    rear_left_thrust = tx_throttle + (-total_pitch - total_roll) + tx_yaw;
    //rear_right_thrust = tx_throttle + (-total_pitch + total_roll) - tx_yaw;
  } else {
    front_left_thrust = standby_speed;
    front_right_thrust = standby_speed;
    rear_left_thrust = standby_speed;
    rear_right_thrust = standby_speed;
  }
}

void Motors::calc_thrust_debug(int tx_pitch, int tx_roll, int tx_throttle, int tx_yaw) // do not try to fly with this
{
  front_left_thrust = tx_throttle + tx_pitch - tx_roll - tx_yaw;
  front_right_thrust = tx_throttle + tx_pitch + tx_roll + tx_yaw;
  rear_left_thrust = tx_throttle - tx_pitch - tx_roll + tx_yaw;
  rear_right_thrust = tx_throttle - tx_pitch + tx_roll - tx_yaw;
}