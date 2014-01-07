#include <Wire.h>
#include <Servo.h>
//Custom headers:
#include <TxRx.h>
#include <I2C.h>
#include <L3G4200D.h>
#include <ADXL345.h>
#include <ComplementaryFilter.h>
#include <Motors.h>
#include <PID.h>

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
  filter.UpdateWithFilter(accel.GetX()-21, accel.GetY()+17, gyro.GetX(), gyro.GetY()); //offset by -21 and 17
//  Serial.print(accel.GetX());
//  Serial.print(" ");
//  Serial.println(accel.GetY());
//  Serial.print(gyro.GetX());
//  Serial.print(" ");
//  Serial.println(gyro.GetY());
//  Serial.print(filter.GetPitch());
//  Serial.print(" ");
//  Serial.println(filter.GetRoll());
//  int limit = 17;
//  if (filter.GetPitch() > limit || filter.GetPitch() < -limit || filter.GetRoll() > limit || filter.GetRoll() < -limit) {
//    Serial.print(accel.GetX());
//    Serial.print(" ");
//    Serial.print(accel.GetY());
//    Serial.print(" ****************** ");
//    Serial.print(gyro.GetX());
//    Serial.print(" ");
//    Serial.println(gyro.GetY());
//  }
  motors.CalcThrustSensorAssisted(filter.GetPitch(), filter.GetRoll(), gyro.GetX(), gyro.GetY(), txrx.GetPitch(), txrx.GetRoll(), txrx.GetThrottle(), txrx.GetYaw());
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
  rearRightEsc.writeMicroseconds(900);
  //rearRightEsc.writeMicroseconds(motors.GetRearRightThrust());
}

