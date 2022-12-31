/* Azizi Bin Mohamad Tambi (1919661)
...This code is for Arduino Uno as a Slave... */

//Library
#include <Wire.h>

//Variables
char a;

void setup() {
 Serial.begin(9600); 
 Wire.begin(D1, D2); //join i2c bus with SDA=D1 and SCL=D2 of NodeMCU 
}

void loop() {
 Wire.beginTransmission(8); //begin with device address 8 
 Wire.write("Hello Arduino, Im NodeMCU");  // sends hello string
 Wire.endTransmission();    // stop transmitting

 Wire.requestFrom(8, 21); // request & read data of size 21 from slave 
 
 while(Wire.available()){
    a = Wire.read();
  Serial.print(a);
 }
 Serial.println();
 delay(1000);
}