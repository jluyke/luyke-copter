#ifndef TxRx_h
#define TxRx_h

#include "Arduino.h"

class TxRx
{
	public:
		void Receive();
		int GetCh1() { return ch1; };
		int GetCh2() { return ch2; };
		int GetCh3() { return ch3; };
		int GetCh4() { return ch4; };
	private:
		int ch1;
		int ch2;
		int ch3;
		int ch4;
};

#endif