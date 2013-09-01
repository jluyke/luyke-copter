#include "Motors.h"

void Motors::CalcThrustSensorAssisted(float sensPitch, float sensRoll, int txPitch, int txRoll, int txThrottle, int txYaw)
{ //this algorithm sucks for balancing
	//float targetPitch = txPitch; //change later with tx values
	//float targetRoll = txRoll;
	float targetPitch = 0;
	float targetRoll = 0;
	
	txYaw = 0;
	//txThrottle = 55;
	
	float lastPitchDiff = pitchDiff;
	float lastRollDiff = rollDiff;
	pitchDiff = (targetPitch - sensPitch) * 300;
	rollDiff = (targetRoll - sensRoll) * 300;
	float setPitch = (pitchDiff + ((pitchDiff - lastPitchDiff)*1)) / 5000;
	float setRoll = (rollDiff + ((rollDiff - lastRollDiff)*1)) / 5000;
	
	if (txThrottle > 25) {
		frontLeftThrust = txThrottle - setPitch - setRoll - txYaw;
		frontRightThrust = txThrottle - setPitch + setRoll + txYaw;
		rearLeftThrust = txThrottle + setPitch - setRoll + txYaw;
		rearRightThrust = txThrottle + setPitch + setRoll - txYaw;
	} else {
		frontLeftThrust = 25;
		frontRightThrust = 25;
		rearLeftThrust = 25;
		rearRightThrust = 25;
	}
}

void Motors::CalcThrustManual(int txPitch, int txRoll, int txThrottle, int txYaw)
{
	frontLeftThrust = txThrottle + txPitch - txRoll - txYaw;
	frontRightThrust = txThrottle + txPitch + txRoll + txYaw;
	rearLeftThrust = txThrottle - txPitch - txRoll + txYaw;
	rearRightThrust = txThrottle - txPitch + txRoll - txYaw;
}