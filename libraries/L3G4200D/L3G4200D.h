#ifndef L3G4200D_h
#define L3G4200D_h

#define DEVICE_ADDRESS 0x69
#define CTRL_REG1 0x20
#define CTRL_REG2 0x21
#define CTRL_REG3 0x22
#define CTRL_REG4 0x23
#define CTRL_REG5 0x24

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
		int x;
		int y;
		int z;
};

#endif

// http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00265057.pdf
// http://bildr.org/2011/06/l3g4200d-arduino/
// Registers: http://forum.arduino.cc/index.php?topic=183407.15