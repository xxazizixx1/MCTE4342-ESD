Assalamualaikum W.B.T, Im Azizi Bin Mohamad Tambi.

This folder (SPI Master-Slave Arduino with LED) contain the codes(in C++), schematic view, circuit view, and list of components used.

Project Description: 
In this project, I used 2 arduino uno, LEDs and Buttons and I use Serial Peripheral Interface (SPI) communication.

For the Master Arduino: 
- The button is connected as an input and the green led is connected as an output.
- When this button is pressed, it will send a value of 1 to the slave Arduino.
- This Master arduino will constantly receiving the value sent by slave arduino so that it can change the status of the green Led.
- The green led will only turned on if the master arduino receive a value of 1 from slave arduino. The value will be 1 if the button connected to slave arduino is pressed.

For the Slave Arduino:
- The button is connected as an OUTPUT while the red LED is connected as an input for this configuration.
- The red LED will turned on if the slave arduino received the value of 1 from master arduino.
- The button in the other hand will act as an output where it will send a value of 1 to master arduino when it is pressed.
 
Discussion:
-SPI bus is a system for serial communication which use 4 conductors. 
-1 conductor is for data receiving, 1 is for sending data, 1 is for synchronization and 1 is for selecting a device.
-This configuration is a full duplex connection, meaning both master and slave receive and send data simultaneously.
-In this project, we use four of the following wires,

SCK - Serial Clock driven by master (Pin 13)
MOSI - Master output/Slave input driven by master (Pin 12)
MISO - Master input/Slave output driven by master (Pin 11)
SS - Slave-selection wire (Pin 10)
