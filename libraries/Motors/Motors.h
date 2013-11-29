#ifndef Motors_h
#define Motors_h

#define PID_LIMIT 200

#include "Arduino.h"
#include "PID_v1.h"

class Motors
{
	public:
		void Setup();
		void CalcThrustSensorAssisted(float sensorPitch, float sensorRoll, int gyroX, int gyroY, int txPitch, int txRoll, int txThrottle, int txYaw);
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
		double pidSetpointGyroX, pidInputGyroX, pidOutputGyroX;
		PID gyroXPID = PID(&pidInputGyroX, &pidOutputGyroX, &pidSetpointGyroX, 0.03, 0.3, 0, DIRECT);
		double pidSetpointGyroY, pidInputGyroY, pidOutputGyroY;
		PID gyroYPID = PID(&pidInputGyroY, &pidOutputGyroY, &pidSetpointGyroY, 0.03, 0.3, 0, DIRECT);
		//
		double pidSetpointPitch, pidInputPitch, pidOutputPitch;
		PID pitchPID = PID(&pidInputPitch, &pidOutputPitch, &pidSetpointPitch, 0.2, 10, 0, DIRECT);
		double pidSetpointRoll, pidInputRoll, pidOutputRoll;
		PID rollPID = PID(&pidInputRoll, &pidOutputRoll, &pidSetpointRoll, 0.2, 10, 0, DIRECT);
};

#endif