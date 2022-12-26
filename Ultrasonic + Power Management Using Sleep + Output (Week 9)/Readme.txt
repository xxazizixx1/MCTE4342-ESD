Assalamualaikum W.B.T, Im Azizi Bin Mohamad Tambi.

This folder (Read FSR+LDR write on TXT file (Memory External)) contain the codes(in C++), schematic view, circuit view, and list of components used.

Project Description: 
1. In this project, we want to use ultrasonic sensor to measure distance and saves power consumption of the arduino.
2. The ultrasonic sensor will measure distance every 8 seconds. 
3. To reduce power consumption, we first make all the pins from pin number 4 to pin A5 to become an output.
4. Then, we implement sleep function for the arduino to enter deep sleep mode for 8 seconds.
5. The library for the sleep function can be downloaded from https://github.com/rocketscream/Low-Power

Discussion:
1. In this project, we only use software method to reduce power consumption of the arduino uno.
2. To reduce power, we can also use hardware method such as reducing the component used and more.
3. The power consumption in this project can be further reduced by increasing the time for the arduino to sleep.