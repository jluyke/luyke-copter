#include "Motors.h"
#include "Arduino.h"
 //delete arduino.h
void Motors::Setup()
{
	pidInputPitch = 0;
	pidSetpointPitch = 0;
	pitchPID.SetOutputLimits(-PID_LIMIT,PID_LIMIT);
	pitchPID.SetSampleTime(1);
	pitchPID.SetMode(AUTOMATIC);
	//
	pidInputRoll = 0;
	pidSetpointRoll = 0;
	rollPID.SetOutputLimits(-PID_LIMIT,PID_LIMIT);
	rollPID.SetSampleTime(1);
	rollPID.SetMode(AUTOMATIC);
	//
	pidInputGyroX = 0;
	pidSetpointGyroX = 0;
	gyroXPID.SetOutputLimits(-PID_LIMIT,PID_LIMIT);
	gyroXPID.SetSampleTime(1);
	gyroXPID.SetMode(AUTOMATIC);
	//
	pidInputGyroY = 0;
	pidSetpointGyroY = 0;
	gyroYPID.SetOutputLimits(-PID_LIMIT,PID_LIMIT);
	gyroYPID.SetSampleTime(1);
	gyroYPID.SetMode(AUTOMATIC);
}

void Motors::CalcThrustSensorAssisted(float sensorPitch, float sensorRoll, int gyroX, int gyroY, int txPitch, int txRoll, int txThrottle, int txYaw)
{
	pidInputPitch = sensorPitch;
	pidInputRoll = sensorRoll;
	pitchPID.Compute();
	rollPID.Compute();
	//
	pidInputGyroX = gyroX;
	pidInputGyroY = gyroY;
	gyroXPID.Compute();
	gyroYPID.Compute();
	//
	txYaw = 0;
	pidOutputPitch *= 0;
	pidOutputRoll *= 0;
	//pidOutputGyroX = 0;
	//pidOutputGyroY = 0;
	//Serial.print(sensorPitch);
	//Serial.print(" ");
	//Serial.println(sensorRoll);
	//Serial.print(pidOutputPitch);
	//Serial.print(" ");
	//Serial.println(pidOutputRoll);
	Serial.print(gyroX);
	Serial.print(" ");
	Serial.println(gyroY);
	int min = 900;
	if (txThrottle > min) {
		//frontLeftThrust = txThrottle - pidOutputPitch - pidOutputRoll - txYaw;
		//frontRightThrust = txThrottle - pidOutputPitch + pidOutputRoll + txYaw;
		//rearLeftThrust = txThrottle + pidOutputPitch - pidOutputRoll + txYaw;
		//rearRightThrust = txThrottle + pidOutputPitch + pidOutputRoll - txYaw;
		//pidOutputPitch *= 1;
		//pidOutputRoll *= 1;
		frontRightThrust = txThrottle + pidOutputGyroX + pidOutputGyroY - pidOutputPitch + pidOutputRoll;
		rearLeftThrust = txThrottle - pidOutputGyroX - pidOutputGyroY + pidOutputPitch - pidOutputRoll;
		//Serial.print(pidOutputGyroX + pidOutputGyroY - pidOutputPitch + pidOutputRoll);
		//Serial.print(" ");
		//Serial.println(-pidOutputGyroX - pidOutputGyroY + pidOutputPitch - pidOutputRoll);
	} else {
		frontLeftThrust = min;
		frontRightThrust = min;
		rearLeftThrust = min;
		rearRightThrust = min;
	}
}

void Motors::CalcThrustManual(int txPitch, int txRoll, int txThrottle, int txYaw)
{
	frontLeftThrust = txThrottle + txPitch - txRoll - txYaw;
	frontRightThrust = txThrottle + txPitch + txRoll + txYaw;
	rearLeftThrust = txThrottle - txPitch - txRoll + txYaw;
	rearRightThrust = txThrottle - txPitch + txRoll - txYaw;
}