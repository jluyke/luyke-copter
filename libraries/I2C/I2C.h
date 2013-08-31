#ifndef I2C_h
#define I2C_h

#include "Arduino.h"

class I2C
{
	public:
		I2C();
		void WriteRegister(int deviceAddress, byte address, byte val);
		int ReadRegister(int deviceAddress, byte address);
	private:
};

#endif