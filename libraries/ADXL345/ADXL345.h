#ifndef ADXL345_h
#define ADXL345_h

#define DEVICE_ADDRESS 0x53

#include "I2C.h"

class ADXL345
{
	public:
		void setup();
		void receive();
		int get_x() { return x; }
		int get_y() { return y; }
		int get_z() { return z; }
	private:
		I2C i2c;
		int x;
		int y;
		int z;
};

#endif

// http://www.analog.com/static/imported-files/data_sheets/ADXL345.pdf
// https://github.com/jenschr/Arduino-libraries/blob/master/ADXL345/examples/ADXL345_no_library/BareBones_ADXL345.pde