#ifndef I2C_h
#define I2C_h

#include "Arduino.h"
#include "Wire.h"

class I2C
{
	public:
		I2C();
		void WriteRegister(int device_address, byte start_address, byte val); //change int to byte?
		byte *ReadRegister(int device_address, byte start_address, int num_of_bytes);
	private:
		byte *buffer;
};

#endif

// http://codeyoung.blogspot.com/2009/11/adxl345-accelerometer-breakout-board.html