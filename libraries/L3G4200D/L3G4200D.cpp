#include "L3G4200D.h"

void L3G4200D::setup()
{
	delay(100);
	i2c.write_register(DEVICE_ADDRESS, CTRL_REG1, 0x8F); //multiwii reg1
	i2c.write_register(DEVICE_ADDRESS, CTRL_REG5, 0x02); //multiwii reg5
	// i2c.WriteRegister(deviceAddress, CTRL_REG1, 0b00001111); // Enable x, y, z and turn off power down:
	// i2c.WriteRegister(deviceAddress, CTRL_REG2, 0b00011001); // High Pass Filter
	// i2c.WriteRegister(deviceAddress, CTRL_REG3, 0b00000000); // Configure CTRL_REG3 to generate data ready interrupt on INT2
	// if (scale == 250) { // CTRL_REG4 controls the full-scale range, among other things
	// 	i2c.WriteRegister(deviceAddress, CTRL_REG4, 0b00000000);
	// } else if (scale == 500) {
	// 	i2c.WriteRegister(deviceAddress, CTRL_REG4, 0b00010000);
	// } else if (scale == 2000) {
	// 	i2c.WriteRegister(deviceAddress, CTRL_REG4, 0b10110000);
	// }
	// i2c.WriteRegister(deviceAddress, CTRL_REG5, 0b00010011); // CTRL_REG5 controls high-pass filtering of outputs
}

void L3G4200D::receive()
{
	TWBR = ((F_CPU / 400000L) - 16) / 2; // change I2C clock rate to 400kHz
	byte *buf = i2c.read_register(DEVICE_ADDRESS, 0x80|0x28, 6);
	x = (buf[1] << 8) | buf[0];
	y = (buf[3] << 8) | buf[2];
	z = (buf[5] << 8) | buf[4];
}