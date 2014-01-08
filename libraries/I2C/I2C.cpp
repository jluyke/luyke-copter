#include "I2C.h"

I2C::I2C()
{
    buffer = new byte[6];
}

void I2C::write_register(int device_address, byte start_address, byte val) 
{
    Wire.beginTransmission(device_address); // start transmission to device
    Wire.write(start_address);       // send register address
    Wire.write(val);         // send value to write
    Wire.endTransmission();     // end transmission
}

byte *I2C::read_register(int device_address, byte start_address, int num_of_bytes)
{
    Wire.beginTransmission(device_address);
    Wire.write(start_address); // register to read
    Wire.endTransmission();

    Wire.requestFrom(device_address, num_of_bytes); // read bytes
    while (Wire.available() < num_of_bytes) { Serial.println("waiting 50us"); delayMicroseconds(50); };
    int i = 0;
    while (Wire.available()) {
        buffer[i] = Wire.read();
        i++;
    }
    return buffer;
}