#ifndef Motors_h
#define Motors_h

class Motors
{
	public:
		void CalcThrustSensorAssisted(float sensPitch, float sensRoll, int txPitch, int txRoll, int txThrottle, int txYaw);
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
		float pitchDiff;
		float rollDiff;
};

#endif