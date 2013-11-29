#include "TxRx.h"

void TxRx::Receive() 
{
	ch1 = pulseIn(A0, HIGH, 25000);
	ch2 = pulseIn(A1, HIGH, 25000);
	ch3 = pulseIn(A2, HIGH, 25000);
	ch4 = pulseIn(A3, HIGH, 25000);
}

void TxRx::Update()
{
	roll = 0;//ch1;
	pitch = 0;//ch2;
	throttle = SmoothThrottle(ch3);
	yaw = 0;//ch4;
	//roll = ch1;
	//pitch = ch2;
	//yaw = ch4;
	//roll /= 8;
	//pitch /= 8;
	//yaw /= 8;
}

int TxRx::SmoothThrottle(int th)
{
	int avg = 0;
	throttleSmooth[ind] = th;
	for (int i = 0; i < 5; i++) {
		avg += throttleSmooth[i];
	}
	ind++;
	if (ind == 5) { ind = 0; }
	return avg/5;
}