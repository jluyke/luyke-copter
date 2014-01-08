#ifndef TxRx_h
#define TxRx_h

#include "Arduino.h"

class TxRx
{
	public:
		void receive();
		void update();
		int get_roll() { return roll; }
		int get_pitch() { return pitch; }
		int get_throttle() { return throttle; }
		int get_yaw() { return yaw; }
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
		//int SmoothThrottle(int th);
		//int throttleSmooth[5] = {0, 0, 0, 0, 0};
		//int ind = 0;
};

#endif