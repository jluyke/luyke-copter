#include "L3G4200D.h"

void L3G4200D::setup()
{
  delay(10);
  i2c.write_register(DEVICE_ADDRESS, 0x20, 0x8F); // multiwii reg1
  i2c.write_register(DEVICE_ADDRESS, 0x24, 0x02); // multiwii reg5
}

void L3G4200D::receive()
{
  TWBR = ((F_CPU / 400000L) - 16) / 2; // change I2C clock rate to 400kHz
  byte *buf = i2c.read_register(DEVICE_ADDRESS, 0x80|0x28, 6);
  x = (buf[1] << 8) | buf[0];
  y = (buf[3] << 8) | buf[2];
  z = (buf[5] << 8) | buf[4];
  delete buf;
  // weighted gyro from multiwii
  x_temp = (x * 3) + x_last;
  x_last = x;
  x = x_temp;
  y_temp = (y * 3) + y_last;
  y_last = y;
  y = y_temp;
  z_temp = (z * 3) + z_last;
  z_last = z;
  z = z_temp;
}