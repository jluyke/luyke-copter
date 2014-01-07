#ifndef ADXL345_h
#define ADXL345_h

#define DEVICE_ADDRESS 0x53

#include "I2C.h"

class ADXL345
{
	public:
		void Setup();
		void Receive();
		int GetX() { return x; }
		int GetY() { return y; }
		int GetZ() { return z; }
	private:
		I2C i2c;
		int x;
		int y;
		int z;
};

#endif

// Based on: https://github.com/jenschr/Arduino-libraries/blob/master/ADXL345/examples/ADXL345_no_library/BareBones_ADXL345.pde
// http://www.analog.com/static/imported-files/data_sheets/ADXL345.pdf