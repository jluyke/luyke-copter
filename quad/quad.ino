#include <Wire.h>
#include <Servo.h>
//Custom headers
#include <TxRx.h>
#include <I2C.h>
#include <L3G4200D.h>
#include <ADXL345.h>
#include <Motors.h>
#include <ComplementaryFilter.h>

TxRx txrx;
L3G4200D gyro;
ADXL345 accel;
Motors motors;
ComplementaryFilter filter;

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
  
  //delay(1000);
  
  //Serial.begin(9600);
  //Serial.println("initializing");
}

void loop()
{ 
  Input();
  UpdateSensorAssisted();
  //UpdateManual();
  Thrust();
  //delay(1);
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
  
  filter.UpdateWithFilter(accel.GetX(), accel.GetY(), gyro.GetX(), gyro.GetY()); //-260 to 260
  
  float offsetPitch = -20;
  float offsetRoll = 10;
  motors.CalcThrustSensorAssisted(filter.GetPitch()+offsetPitch, filter.GetRoll()+offsetRoll, txrx.GetPitch(), txrx.GetRoll(), txrx.GetThrottle(), txrx.GetYaw());
  
  //Serial.print("frontleft="); Serial.print(motors.GetFrontLeftThrust()); Serial.print(" frontright="); Serial.print(motors.GetFrontRightThrust());
  //Serial.print(" rearleft="); Serial.print(motors.GetRearLeftThrust()); Serial.print(" rearright="); Serial.println(motors.GetRearRightThrust());
  
  //Serial.print(filter.GetPitch() + offsetPitch);
  //Serial.print(" ");
  //Serial.println(filter.GetRoll() + offsetRoll);
  
  /*Serial.print("gyro: ");
  Serial.print(gyro.GetX());
  Serial.print(" ");
  Serial.print(gyro.GetY());
  Serial.print(" ");
  Serial.print(gyro.GetZ());
  Serial.print(" accel: ");
  Serial.print(accel.GetX());
  Serial.print(" ");
  Serial.print(accel.GetY());
  Serial.print(" ");
  Serial.println(accel.GetZ());*/
}

void UpdateManual() 
{
  txrx.Update();
  motors.CalcThrustManual(txrx.GetPitch(), txrx.GetRoll(), txrx.GetThrottle(), txrx.GetYaw());
  
  //Serial.print("frontleft="); Serial.print(motors.GetFrontLeftThrust()); Serial.print(" frontright="); Serial.print(motors.GetFrontRightThrust());
  //Serial.print(" rearleft="); Serial.print(motors.GetRearLeftThrust()); Serial.print(" rearright="); Serial.println(motors.GetRearRightThrust());
}

void Thrust() 
{
  frontLeftEsc.write(motors.GetFrontLeftThrust());
  frontRightEsc.write(motors.GetFrontRightThrust());
  rearLeftEsc.write(motors.GetRearLeftThrust());
  rearRightEsc.write(motors.GetRearRightThrust());
}
