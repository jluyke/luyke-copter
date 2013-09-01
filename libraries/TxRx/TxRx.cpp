#include "Arduino.h"
#include "TxRx.h"

TxRx::TxRx() 
{
	Ch1 = 0;
	Ch2 = 0;
	Ch3 = 0;
	Ch4 = 0;
	Ch5 = 0;
	Ch6 = 0;
}

void TxRx::Receive() 
{
	Ch1 = pulseIn(A0, HIGH, 25000);
	Ch2 = pulseIn(A1, HIGH, 25000);
	Ch3 = pulseIn(A2, HIGH, 25000);
	Ch4 = pulseIn(A3, HIGH, 25000);
}