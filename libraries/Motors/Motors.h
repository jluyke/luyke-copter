#ifndef Motors_h
#define Motors_h

#define PID_LIMIT 200

#include "Arduino.h"
#include "PID.h"

class Motors
{
	public:
		void Setup();
		void CalcThrustSensorAssisted(float cfilterPitch, float cfilterRoll, int gyroX, int gyroY, int txPitch, int txRoll, int txThrottle, int txYaw);
		void CalcThrustManual(int txPitch, int txRoll, int txThrottle, int txYaw);
		int GetFrontLeftThrust() { return frontLeftThrust; }
		int GetFrontRightThrust() { return frontRightThrust; }
		int GetRearLeftThrust() { return rearLeftThrust; }
		int GetRearRightThrust() { return rearRightThrust; }
	private:
		int frontLeftThrust;
		int frontRightThrust;
		int rearLeftThrust;
		int rearRightThrust;
		//
		PID pidOutputPitch;
		PID pidOutputRoll;
		double pidCFilterPitch;
		double pidCFilterRoll;
		int motor_standby_speed;
};

#endif