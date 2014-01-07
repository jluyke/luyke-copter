#include "ADXL345.h"

void ADXL345::Setup()
{
	// byte dataFormat = 0x31;
	// byte powerCTL = 0x2D; //Power Control Register
	//i2c.WriteRegister(deviceAddress, dataFormat, 0x09); //Put the ADXL345 into Full Resolution Mode
	//i2c.WriteRegister(deviceAddress, powerCTL, 0x08); //Put the ADXL345 into Measurement Mode by writing 0x08 to the POWER_CTL register.
	// FROM MULTIWII:
	delay(10);
	i2c.WriteRegister(DEVICE_ADDRESS, 0x2D, 1<<3); // power ctrl -- value: set measure bit 3 on
	i2c.WriteRegister(DEVICE_ADDRESS, 0x31, 0x0B); // data_format -- value: set bits 3(full range) and 1 0 on (+/- 16g)
	i2c.WriteRegister(DEVICE_ADDRESS, 0x2C, 0x09); // bw_rate -- value: rate=50hz, bw=20hz
}

void ADXL345::Receive()
{
	TWBR = ((F_CPU / 400000L) - 16) / 2; // change I2C clock rate to 400kHz, ADXL435 is ok with this speed
	byte *buf = i2c.ReadRegister(DEVICE_ADDRESS, 0x32, 6);
	x = (buf[1] << 8) | buf[0];
	y = (buf[3] << 8) | buf[2];
	z = (buf[5] << 8) | buf[4];
}