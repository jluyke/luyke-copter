// official headers
#include <Wire.h>
#include <Servo.h>
// custom headers
#include <TxRx.h>
#include <I2C.h>
#include <ADXL345.h>
#include <L3G4200D.h>
#include <ComplementaryFilter.h>
#include <PID.h>
#include <Motors.h>

TxRx txrx;
ADXL345 accel;
L3G4200D gyro;
ComplementaryFilter filter;
Motors motors;

Servo front_left_esc;
Servo front_right_esc;
Servo rear_left_esc;
Servo rear_right_esc;

void setup()
{
  Wire.begin();
  
  front_left_esc.attach(5);
  front_right_esc.attach(6);
  rear_left_esc.attach(9);
  rear_right_esc.attach(10);
  
  gyro.setup();
  accel.setup();
  motors.setup();
  
  Serial.begin(9600);
  Serial.println("initializing");
}

void loop()
{
  input();
  update();
  thrust();
  delay(1);
}

void input() 
{
  txrx.receive();
  gyro.receive();
  accel.receive();
}

void update()
{
  txrx.update();
  filter.update_filter(accel.get_x()-21, accel.get_y()+17, gyro.get_x(), gyro.get_y()); //offset by -21 and 17
  motors.calc_thrust_sensor_assisted(filter.get_pitch(), filter.get_roll(), gyro.get_x(), gyro.get_y(), txrx.get_pitch(), txrx.get_roll(), txrx.get_throttle(), txrx.get_yaw());
//  motors.calc_thrust_manual(txrx.get_pitch(), txrx.get_roll(), txrx.get_throttle(), txrx.get_yaw()); 

//  Serial.print(accel.get_x());
//  Serial.print(" ");
//  Serial.println(accel.get_y());
//  Serial.print(gyro.get_x());
//  Serial.print(" ");
//  Serial.println(gyro.get_y());
//  Serial.print(filter.get_pitch());
//  Serial.print(" ");
//  Serial.println(filter.get_roll());
}

void thrust()
{
  //front_left_esc.writeMicroseconds(motors.get_front_left_thrust());
  front_left_esc.writeMicroseconds(900);
  front_right_esc.writeMicroseconds(motors.get_front_right_thrust());
  rear_left_esc.writeMicroseconds(motors.get_rear_left_thrust());
  rear_right_esc.writeMicroseconds(900);
  //rear_right_esc.writeMicroseconds(motors.get_rear_right_thrust());
}

