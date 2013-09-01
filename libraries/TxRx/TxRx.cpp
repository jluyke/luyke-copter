#include "TxRx.h"
#include "Arduino.h"

void TxRx::Receive() 
{
	ch1 = pulseIn(A0, HIGH, 25000);
	ch2 = pulseIn(A1, HIGH, 25000);
	ch3 = pulseIn(A2, HIGH, 25000);
	ch4 = pulseIn(A3, HIGH, 25000);
}