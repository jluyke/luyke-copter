#include <Wire.h>
#include <Servo.h>
#include <PID_v1.h>
//Custom headers
#include <TxRx.h>
#include <I2C.h>
#include <L3G4200D.h>
#include <ADXL345.h>
#include <ComplementaryFilter.h>
#include <Motors.h>

TxRx txrx;
L3G4200D gyro;
ADXL345 accel;
ComplementaryFilter filter;
Motors motors;

Servo frontLeftEsc;
Servo frontRightEsc;
Servo rearLeftEsc;
Servo rearRightEsc;

void setup()
{
  Wire.begin();
  
  frontLeftEsc.attach(5);
  frontRightEsc.attach(6);
  rearLeftEsc.attach(9);
  rearRightEsc.attach(10);
  
  gyro.Setup(2000);
  accel.Setup();
  motors.Setup();
  
  Serial.begin(9600);
  Serial.println("initializing");
}

void loop()
{
  Input();
  UpdateSensorAssisted();
  //UpdateManual();
  Thrust();
  delay(1);
}

void Input() 
{
  txrx.Receive();
  gyro.Receive();
  accel.Receive();
}

void UpdateSensorAssisted()
{
  txrx.Update();
  //Serial.println(txrx.GetPitch());
  filter.UpdateWithFilter(accel.GetX(), accel.GetY(), gyro.GetX(), gyro.GetY()); //-260 to 260
  
  float offsetPitch = -8;
  float offsetRoll = 5;
  motors.CalcThrustSensorAssisted(filter.GetPitch()+offsetPitch, filter.GetRoll()+offsetRoll, gyro.GetX(), gyro.GetY(), txrx.GetPitch(), txrx.GetRoll(), txrx.GetThrottle(), txrx.GetYaw());
  
  //Serial.println(txrx.GetThrottle());
  
  //Serial.print("frontleft="); Serial.print(motors.GetFrontLeftThrust()); Serial.print(" frontright="); Serial.print(motors.GetFrontRightThrust());
  //Serial.print(" rearleft="); Serial.print(motors.GetRearLeftThrust()); Serial.print(" rearright="); Serial.println(motors.GetRearRightThrust());
  
  //Serial.print(filter.GetPitch() + offsetPitch);
  //Serial.print(" ");
  //Serial.println(filter.GetRoll() + offsetRoll);
}

void UpdateManual()
{
  txrx.Update();
  motors.CalcThrustManual(txrx.GetPitch(), txrx.GetRoll(), txrx.GetThrottle(), txrx.GetYaw());
}

void Thrust()
{
  //frontLeftEsc.writeMicroseconds(motors.GetFrontLeftThrust());
  frontLeftEsc.writeMicroseconds(900);
  frontRightEsc.writeMicroseconds(motors.GetFrontRightThrust());
  rearLeftEsc.writeMicroseconds(motors.GetRearLeftThrust());
  //rearRightEsc.writeMicroseconds(motors.GetRearRightThrust());
}

