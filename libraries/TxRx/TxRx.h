#ifndef TxRx_h
#define TxRx_h

#include "Arduino.h"

class TxRx
{
	public:
		void Receive();
		void Update();
		/* Unused
		int GetCh1() { return ch1; };
		int GetCh2() { return ch2; };
		int GetCh3() { return ch3; };
		int GetCh4() { return ch4; };
		*/
		int GetRoll() { return roll; }
		int GetPitch() { return pitch; }
		int GetThrottle() { return throttle; }
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
		int SmoothThrottle(int th);
		int throttleSmooth[5] = {0, 0, 0, 0, 0};
		int ind = 0;
};

#endif