#include "I2C.h"

void I2C::write_register(uint8_t device_address, byte start_address, byte val) 
{
  Wire.beginTransmission(device_address);
  Wire.write(start_address); // send register address
  Wire.write(val); // send value to register
  Wire.endTransmission();
}

byte *I2C::read_register(uint8_t device_address, byte start_address, uint8_t num_of_bytes)
{
  // setup register to read
  Wire.beginTransmission(device_address);
  Wire.write(start_address);
  Wire.endTransmission();
  // start request
  Wire.requestFrom(device_address, num_of_bytes);
  while (Wire.available() < num_of_bytes) { Serial.println("waiting 50us - should not happen"); delayMicroseconds(50); };
  byte *buffer = new byte[num_of_bytes];
  for (uint8_t counter = 0; counter < num_of_bytes; counter++) {
    buffer[counter] = Wire.read();
  }
  return buffer;
}