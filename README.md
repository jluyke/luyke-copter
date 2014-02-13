luyke-quadcopter - work in progress
================

About
-----
This is my personal project and hobby, built and coded from scratch. It is my attempt to learn as much as I can about the fundamentals of circuits, sensors, and C++, all while having fun.

I am using the Arduino Duemilanove (the latest version is the Uno), and its libraries use C/C++. The "custom headers" in the main .ino file are the ones in this repository. For the logic of the loop() method where I used "input(); update(); thrust();", I took the model of a game loop: "input, update, render."

Build
-----
- 1x [Arduino](http://arduino.cc/en/Main/ArduinoBoardUno)
- 1x [GY-80 IMU](http://multiwii.org/gy-80-chinese-10dof-and-arduino-pro-mini-hooking-and-testing/) (on ebay)
- 1x [HK X650F Frame](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=29600)
- 4x [Turnigy Motors 800Kv](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=39037)
- 4x [HK ESC 30A](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=13429) (or [Turnigy ESC 30A](http://www.hobbyking.com/hobbyking/store/__25365__Turnigy_Multistar_30_Amp_Multi_rotor_Brushless_ESC_2_4S.html))
- 1x [Zippy 4000mAh 3s](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=21360) (or 2x)
- 1x [HK Tx&Rx 4ch](http://www.hobbyking.com/hobbyking/store/__15142__Hobby_King_2_4Ghz_4Ch_Tx_Rx_V2_Mode_2_USA_Warehouse_.html)
- 1x [HK ESC Card](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=13431) (or [Turnigy ESC Card](http://www.hobbyking.com/hobbyking/store/__27135__Turnigy_Multistar_ESC_Programming_Card.html))
- 1x [Props LH](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=22450) and 1x [Props RH](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=22451)
- 1x [DC Jack](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=34756) and [Servo Wire](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=5489) (for connecting Arduino to battery, removed yellow wire)
- 1x [Arduino Jumper Wires](http://www.hobbyking.com/hobbyking/store/__26891__Arduino_Bread_Board_Jumper_Set_with_7_color_Length_Wires_with_Pin_Ends.html) (for connecting everything to Arduino)
- 1x [M2M Servo Lead](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=21758) (used on Rx receiver, then used with jumper wires)
- 1x [Breadboard](http://www.hobbyking.com/hobbyking/store/__26933__Arduino_Prototype_Shield_w_Expansion_Breadboard.html) (for white breadboard)
- 1x [Low Voltage Alarm](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=18987)
- 1x [HK Charger/Balancer](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=14857) and [HK Power Supply](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=11758)
####I used these as well:
- [Solder Wire](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=21263)
- [XT60 Connectors](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=9572)
- [XT90 Connectors](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=24707)
- [12AWG Wire Black](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=9674)
- [12AWG Wire Red](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=9673)
- [Heat Shrink Tube](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=3834)

Contact
-------
[@jluyke](https://twitter.com/jluyke) on Twitter

Todo
----
- Make HMC5883L sensor library
- Make BMP085 sensor library