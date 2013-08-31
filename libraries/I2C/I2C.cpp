#include "I2C.h"
#include "Arduino.h"
#include "Wire.h"


I2C::I2C() 
{
	//
}

void I2C::WriteRegister(int deviceAddress, byte address, byte val) 
{
    Wire.beginTransmission(deviceAddress); // start transmission to device 
    Wire.write(address);       // send register address
    Wire.write(val);         // send value to write
    Wire.endTransmission();     // end transmission
}

int I2C::ReadRegister(int deviceAddress, byte address)
{
    Wire.beginTransmission(deviceAddress);
    Wire.write(address); // register to read
    Wire.endTransmission();

    Wire.requestFrom(deviceAddress, 3); // read a byte
    
	int v = 0;
	if (Wire.available()) {
    	v = Wire.read();
    }
    return v;
}