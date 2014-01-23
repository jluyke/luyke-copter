#include "ComplementaryFilter.h"

void ComplementaryFilter::update_filter(int acc_x_input, int acc_y_input, int gyro_x_input, int gyro_y_input)
{
  low_pass_filter(acc_x_input, acc_y_input);
  high_pass_filter(gyro_x_input, gyro_y_input);
  pitch = (1 - ALPHA) * (pitch + filtered_gyro_x * DT) + (ALPHA * filtered_acc_x);
  roll = (1 - ALPHA) * (roll + filtered_gyro_y * DT) + (ALPHA * filtered_acc_y);
}

void ComplementaryFilter::low_pass_filter(int x, int y) // accelerometer values
{
  filtered_acc_x = (1 - ALPHA) * x + (ALPHA * filtered_acc_x);
  filtered_acc_y = (1 - ALPHA) * y + (ALPHA * filtered_acc_y);
}

void ComplementaryFilter::high_pass_filter(int x, int y) // gyroscope values
{
  filtered_gyro_x = (1 - ALPHA) * filtered_gyro_x + (1 - ALPHA) * (x - last_gyro_x_input);
  filtered_gyro_y = (1 - ALPHA) * filtered_gyro_y + (1 - ALPHA) * (y - last_gyro_y_input);
  last_gyro_x_input = x;
  last_gyro_y_input = y;
}