#ifndef TxRx_h
#define TxRx_h

#include "Arduino.h"

class TxRx
{
	public:
		void Receive();
		void Update();
		int GetRoll() { return roll; }
		int GetPitch() { return pitch; }
		int GetThrottle() { return throttle-500; }
		int GetYaw() { return yaw; }
	private:
		int ch1;
		int ch2;
		int ch3;
		int ch4;
		int roll;
		int pitch;
		int throttle;
		int yaw;
		//Smoothing variables
		int SmoothThrottle(int th);
		int throttleSmooth[5] = {0, 0, 0, 0, 0};
		int ind = 0;
};

#endif