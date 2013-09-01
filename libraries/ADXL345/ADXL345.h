#ifndef ADXL345_h
#define ADXL345_h

#include "Arduino.h"
#include "I2C.h"

class ADXL345
{
	public:
		ADXL345();
		void Setup();
		void Receive();
		int GetX() { return x; }
		int GetY() { return y; }
		int GetZ() { return z; }
	private:
		I2C i2c;
		byte deviceAddress;
		int x;
		int y;
		int z;
};

#endif