#include "TxRx.h"
#include "Arduino.h"

void TxRx::Receive() 
{
	ch1 = pulseIn(A0, HIGH, 25000);
	ch2 = pulseIn(A1, HIGH, 25000);
	ch3 = pulseIn(A2, HIGH, 25000);
	ch4 = pulseIn(A3, HIGH, 25000);
}

void TxRx::Update()
{
	roll = 85 - map(ch1, 1500, 2400, 0, 180);
	pitch = 82 - map(ch2, 1500, 2400, 0, 180);
	throttle = SmoothThrottle(ch3);
	throttle = map(throttle, 1500, 2400, 0, 180);
	
	yaw = 82 - map(ch4, 1500, 2400, 0, 180);
	roll /= 8;
	pitch /= 8;
	yaw /= 8;
	if (throttle < 25) {
		throttle = 25;
		roll = 0;
		pitch = 0;
		yaw = 0;
	}
}

int TxRx::SmoothThrottle(int th)
{
	int avg;
	throttleSmooth[ind] = th;
	for (int i = 0; i < 5; i++) {
		avg += throttleSmooth[i];
	}
	ind++;
	if (ind == 5) { ind = 0; }
	return avg/5;
}