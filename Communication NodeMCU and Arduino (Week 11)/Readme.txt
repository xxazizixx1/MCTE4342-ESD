Assalamualaikum W.B.T, Im Azizi Bin Mohamad Tambi.

This folder (Communication NodeMCU and Arduino) contain the codes(in C++), schematic view, circuit view, and list of components used.

Project Description: 
1. In this project, I want to use establish an I2C communcation between NodeMCU as a master and Arduino Uno as a slave.
2. This simple program allows the NodeMCU and Arduino to interact with each other to send data in a string type.
3. An LED is attached to the arduino Uno where the LED will turned on if it receives data from the master and off again when it is not.

Discussion:
-For the configuration, two wires which is SDA (serial data) and SCL (serial clock) are connected to each other.
-NodeMcu will act as a master while Arduino will act as a slave.
-SDA will be used to exchange data and SCL to ensure synchronous clock between these 2 devices.
-NodeMCU however has a limited of I2C pins, therefore, in this project we only use D1 and D2 pins of NodeMcu.
 