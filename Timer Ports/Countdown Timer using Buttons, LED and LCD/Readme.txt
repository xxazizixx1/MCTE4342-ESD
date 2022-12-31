Assalamualaikum W.B.T, Im Azizi Bin Mohamad Tambi.

This folder (Countdown Timer using Buttons, LED and LCD) contain the codes(in C++), schematic view, circuit view, and list of components used.

Project Description: 
1. In this project, I want to create a countdown timer using Arduino Uno, LED, 4 Buttons, LCD and a Buzzer.
2. This program allows us to set a time for how long the LED will be turned on. Once the timer is done, the LED will turned off and the buzzer will turned on for a few seconds.
3. There are 4 different buttons with each different functionality. 
- Button Set -> Used to set button in hours/minutes/seconds.
- Button Up -> Used to increase the value of time.
- Button Down -> Used to decrease the value of time.
- Button Start -> Start the countdown timer.
4. Once we have adjusted the time that we wanted, the value of the time will be stored in EEPROM and will be read by the arduino.
5. The execution of the program will start after the value stored in EEPROM is read. 

Discussion:
1. EEPROM can be used to store value such as time to make a countdown timer.
2. A new library for the timer is used in this program which is Counttimer.h (can be downloaded at https://github.com/inflop/Countimer)
 