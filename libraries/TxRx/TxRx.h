#ifndef TxRx_h
#define TxRx_h

#define READINGS 5

#include "Arduino.h"

class TxRx
{
	public:
		TxRx();
		void Receive();
		int getCh1() { return Ch1; };
		int getCh2() { return Ch2; };
		int getCh3() { return Ch3; };
		int getCh4() { return Ch4; };
		int getCh5() { return Ch5; };
		int getCh6() { return Ch6; };
	private:
		int Ch1;
		int Ch2;
		int Ch3;
		int Ch4;
		int Ch5;
		int Ch6;
};

#endif