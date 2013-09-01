#include "ADXL345.h"
#include "Arduino.h"
#include "Wire.h"
#include "I2C.h"

ADXL345::ADXL345() 
{
	deviceAddress = 0x53;
}

void ADXL345::SetupADXL345()
{
	byte dataFormat = 0x31;
	byte powerCTL = 0x2D; //Power Control Register
	i2c.WriteRegister(deviceAddress, 0x31, 0x09); //Put the ADXL345 into Full Resolution Mode
	i2c.WriteRegister(deviceAddress, 0x2D, 0x08); //Put the ADXL345 into Measurement Mode by writing 0x08 to the POWER_CTL register.
}

void ADXL345::UpdateAccelValues()
{
	byte xLSB = i2c.ReadRegister(deviceAddress, 0x32);
	byte xMSB = i2c.ReadRegister(deviceAddress, 0x33);
	x = ((xMSB << 8) | xLSB);

	byte yLSB = i2c.ReadRegister(deviceAddress, 0x34);
	byte yMSB = i2c.ReadRegister(deviceAddress, 0x35);
	y = ((yMSB << 8) | yLSB);
	
	byte zLSB = i2c.ReadRegister(deviceAddress, 0x36);
	byte zMSB = i2c.ReadRegister(deviceAddress, 0x37);
	z = ((zMSB << 8) | zLSB);
}

// Based on: https://github.com/jenschr/Arduino-libraries/blob/master/ADXL345/examples/ADXL345_no_library/BareBones_ADXL345.pde
// http://www.analog.com/static/imported-files/data_sheets/ADXL345.pdf