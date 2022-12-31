Assalamualaikum W.B.T, Im Azizi Bin Mohamad Tambi.

This folder (Interrupt using Button) contain the codes(in C++), schematic view, circuit view, and list of components used.

Project Description: 
1. In this project, I want to create an external interrupt using Arduino Uno, LED, 2 buttons and LCD.
2. This program works in a way that the timer will increase every seconds and by using different buttons (button1 and button2) we can apply interrupts to turn the LED on or off.
3. Button 1 will cause the LED to turn off and the LCD will display interrupt 1 despite without stopping the timer.
4. Button 2 will cause the LED to turn on and the LCD will display interrupt 2 without stopping the timer. 

Discussion:
1. attachInterrupt() function can be used as an interrupt to turn on and off the Led without resetting the counter.
2. Different board has different pins that is usable for interrupts. For uno, only pin 2 and 3 are usable for interrupts.
