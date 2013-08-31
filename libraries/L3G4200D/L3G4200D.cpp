#include "L3G4200D.h"
#include "Arduino.h"
#include "Wire.h"
#include "I2C.h"

L3G4200D::L3G4200D()
{
	deviceAddress = 0x69;
}

void L3G4200D::SetupL3G4200D(int scale)
{
	i2c.WriteRegister(deviceAddress, CTRL_REG1, 0b00001111); // Enable x, y, z and turn off power down:
	i2c.WriteRegister(deviceAddress, CTRL_REG2, 0b00000000); // If you'd like to adjust/use the HPF
	i2c.WriteRegister(deviceAddress, CTRL_REG3, 0b00001000); // Configure CTRL_REG3 to generate data ready interrupt on INT2
	if (scale == 250) { // CTRL_REG4 controls the full-scale range, among other things:
		i2c.WriteRegister(deviceAddress, CTRL_REG4, 0b00000000);
	} else if(scale == 500) {
		i2c.WriteRegister(deviceAddress, CTRL_REG4, 0b00010000);
	} else if(scale == 2000) {
		i2c.WriteRegister(deviceAddress, CTRL_REG4, 0b00110000);
	}
	i2c.WriteRegister(deviceAddress, CTRL_REG5, 0b00000000); // CTRL_REG5 controls high-pass filtering of outputs
}

void L3G4200D::UpdateGyroValues()
{
	byte xLSB = i2c.ReadRegister(deviceAddress, 0x28);
	byte xMSB = i2c.ReadRegister(deviceAddress, 0x29);
	x = ((xMSB << 8) | xLSB);

	byte yLSB = i2c.ReadRegister(deviceAddress, 0x2A);
	byte yMSB = i2c.ReadRegister(deviceAddress, 0x2B);
	y = ((yMSB << 8) | yLSB);

	byte zLSB = i2c.ReadRegister(deviceAddress, 0x2C);
	byte zMSB = i2c.ReadRegister(deviceAddress, 0x2D);
	z = ((zMSB << 8) | zLSB);
}

// Based on: http://bildr.org/2011/06/l3g4200d-arduino/
// http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00265057.pdf