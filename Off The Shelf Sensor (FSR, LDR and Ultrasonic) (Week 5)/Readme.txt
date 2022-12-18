Assalamualaikum W.B.T, Im Azizi Bin Mohamad Tambi.

This folder (Off The Shelf Sensors) contain the codes(in C++), schematic view, circuit view, and list of components used.

Project Description: 
1. In this project, I use a 3 different sensors which are Ultrasonic Sensor, Force Sensing Resistor (FSR) and Light Dependent Resistor (LDR).
2. What I wanted to create here is a simple program that will be able to measure the value read by all these 3 sensors and also introduce the sensors usage. 

Discussion:
1. For ultrasonic sensor, we can use it to measure distance as the sensor emits an ultrasound at 40kHz which travels to the air and if there is an object in its path, it will bounce back.
2. Ultrasonic sensor have an angle of 15 degree and it is able to detect from 2cm until 450cm.
3. The echo pin of the ultrasonic sensor is connected to digital pin 2 while the trigger pin is connected to digital pin 3 of arduino uno.
4. For FSR, we can use it to detect physical pressure and weight.
5. How FSR work is that when the value of pressure is increased, the resistance inside the film will decrease.
6. In this experiment, the FSR is connected to Analog pin 0 of arduino uno.
7. For LDR, or also called as photoresistor, it is used to measure the intensity of light.
8. The resistance of LDR increases when the intensity of light decreases.
9. In this experiment, the LDR is connected to Analog pin 1 of arduino uno.

Problem encounter:
1. I encountered an error for getting a correct threshold value for FSR due to incorrect usage of resistor. At first, the resistor used was 1K ohm which made the FSR give an inaccurate value based on the threshold made. This was fixed by changing the value of resistor to 10K ohm. 