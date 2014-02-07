#ifndef I2C_h
#define I2C_h

#include "Arduino.h"
#include "Wire.h"

class I2C
{
  public:
    void write_register(uint8_t device_address, byte start_address, byte val);
    byte *read_register(uint8_t device_address, byte start_address, uint8_t num_of_bytes);
};

#endif

// References
// http://codeyoung.blogspot.com/2009/11/adxl345-accelerometer-breakout-board.html

// Usage
// byte *buf = i2c.read_register(DEVICE_ADDRESS, 0x32, 6);
// ... do stuff
// delete buf;