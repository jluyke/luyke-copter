#ifndef L3G4200D_h
#define L3G4200D_h

#define DEVICE_ADDRESS 0x69

#include "I2C.h"

class L3G4200D
{
  public:
    void setup();
    void receive();
    int get_x() { return x; }
    int get_y() { return y; }
    int get_z() { return z; }
  private:
    I2C i2c;
    int x, y, z;
    int x_last, y_last, z_last;
    int x_temp, y_temp, z_temp;
};

#endif

// References
// http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00265057.pdf
// http://bildr.org/2011/06/l3g4200d-arduino/
// Registers: http://forum.arduino.cc/index.php?topic=183407.15

// Usage
// L3G4200D gyro;
// gyro.setup();
// gyro.receive();
// gyro.get_x(); ...etc