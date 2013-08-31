#ifndef L3G4200D_h
#define L3G4200D_h

#define CTRL_REG1 0x20
#define CTRL_REG2 0x21
#define CTRL_REG3 0x22
#define CTRL_REG4 0x23
#define CTRL_REG5 0x24

#include "Arduino.h"
#include "I2C.h"

class L3G4200D
{
	public:
		L3G4200D();
		void SetupL3G4200D(int scale); // Configure L3G4200  - 250, 500 or 2000 deg/sec
		void UpdateGyroValues();
		int GetX() { return x; }
		int GetY() { return y; }
		int GetZ() { return z; }
	private:
		I2C i2c;
		byte deviceAddress;
		int x;
		int y;
		int z;
};

#endif