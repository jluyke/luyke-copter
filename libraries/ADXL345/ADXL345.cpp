#include "ADXL345.h"

void ADXL345::setup()
{
  delay(10); // from multiwii:
  i2c.write_register(DEVICE_ADDRESS, 0x2D, 1<<3); // power ctrl -- value: set measure bit 3 on
  i2c.write_register(DEVICE_ADDRESS, 0x31, 0x0B); // data_format -- value: set bits 3(full range) and 1 0 on (+/- 16g)
  i2c.write_register(DEVICE_ADDRESS, 0x2C, 0x09); // bw_rate -- value: rate=50hz, bw=20hz
}

void ADXL345::receive()
{
  TWBR = ((F_CPU / 400000L) - 16) / 2; // change I2C clock rate to 400kHz, ADXL435 is ok with this speed
  byte *buf = i2c.read_register(DEVICE_ADDRESS, 0x32, 6);
  x = (buf[1] << 8) | buf[0];
  y = (buf[3] << 8) | buf[2];
  z = (buf[5] << 8) | buf[4];
}