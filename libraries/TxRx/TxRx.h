#ifndef TxRx_h
#define TxRx_h

#include "Arduino.h"

class TxRx
{
  public:
    void receive();
    void update();
    int get_roll() { return roll; }
    int get_pitch() { return pitch; }
    int get_throttle() { return throttle; }
    int get_yaw() { return yaw; }
  private:
    int rx_ch1;
    int rx_ch2;
    int rx_ch3;
    int rx_ch4;
    int roll;
    int pitch;
    int throttle;
    int yaw;
    uint8_t read_switcher;
};

#endif