#include "Motors.h"

void Motors::Setup()
{
	double p = 2*0;
	double i = 0.1*0;
	double d = 60;
	pidOutputPitch.Setup(p,i,d);
	pidOutputRoll.Setup(p,i,d);
	motor_standby_speed = 900;
}

void Motors::CalcThrustSensorAssisted(float cfilterPitch, float cfilterRoll, int gyroX, int gyroY, int txPitch, int txRoll, int txThrottle, int txYaw)
{
	pidCFilterPitch = pidOutputPitch.Compute(0,cfilterPitch,-gyroY);
	pidCFilterRoll = pidOutputRoll.Compute(0,cfilterRoll,-gyroX);

	if (txThrottle > motor_standby_speed) {
		txYaw = 0;
		//frontLeftThrust = txThrottle - pidOutputPitch - pidOutputRoll - txYaw;
		frontRightThrust = txThrottle + (pidCFilterPitch + pidCFilterRoll) + txYaw;
		rearLeftThrust = txThrottle + (-pidCFilterPitch - pidCFilterRoll) + txYaw;
		//rearRightThrust = txThrottle + pidOutputPitch + pidOutputRoll - txYaw;
	} else {
		frontLeftThrust = motor_standby_speed;
		frontRightThrust = motor_standby_speed;
		rearLeftThrust = motor_standby_speed;
		rearRightThrust = motor_standby_speed;
	}
}

void Motors::CalcThrustManual(int txPitch, int txRoll, int txThrottle, int txYaw)
{
	//Serial.println(txThrottle);
	frontLeftThrust = txThrottle + txPitch - txRoll - txYaw;
	frontRightThrust = txThrottle + txPitch + txRoll + txYaw;
	rearLeftThrust = txThrottle - txPitch - txRoll + txYaw;
	rearRightThrust = txThrottle - txPitch + txRoll - txYaw;
}