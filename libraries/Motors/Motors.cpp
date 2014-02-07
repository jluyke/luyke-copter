#include "Motors.h"

void Motors::setup_pids()
{
  // Acro mode
  pid_acro_pitch = new PID(0.1, 0.005, 1);
  pid_acro_roll = new PID(0.1, 0.005, 1);
  // Level mode
  pid_level_pitch = new PID(20, 0.1, 200);
  pid_level_roll = new PID(20, 0.1, 200);
}

void Motors::calc_thrust_level_mode(float angle_pitch, float angle_roll, int gyro_x, int gyro_y, int tx_pitch, int tx_roll, int tx_throttle, int tx_yaw)
{
  total_pitch = pid_acro_pitch->compute(0, -gyro_y) + pid_level_pitch->compute(0, angle_pitch);
  total_roll = pid_acro_roll->compute(0, -gyro_x) + pid_level_roll->compute(0, angle_roll);
  // Serial.print(total_pitch);
  // Serial.print(" ");
  // Serial.println(total_roll);
  if (tx_throttle > STANDBY_SPEED) {
    // front_left_thrust = tx_throttle + (total_pitch - total_roll) - tx_yaw; // disabled for testing
    front_right_thrust = tx_throttle + (total_pitch + total_roll) + tx_yaw;
    rear_left_thrust = tx_throttle + (-total_pitch - total_roll) + tx_yaw;
    // rear_right_thrust = tx_throttle + (-total_pitch + total_roll) - tx_yaw;
  } else {
    front_left_thrust = STANDBY_SPEED;
    front_right_thrust = STANDBY_SPEED;
    rear_left_thrust = STANDBY_SPEED;
    rear_right_thrust = STANDBY_SPEED;
  }
}

void Motors::calc_thrust_debug(int tx_pitch, int tx_roll, int tx_throttle, int tx_yaw) // do not try to fly with this
{
  front_left_thrust = tx_throttle + tx_pitch - tx_roll - tx_yaw;
  front_right_thrust = tx_throttle + tx_pitch + tx_roll + tx_yaw;
  rear_left_thrust = tx_throttle - tx_pitch - tx_roll + tx_yaw;
  rear_right_thrust = tx_throttle - tx_pitch + tx_roll - tx_yaw;
}