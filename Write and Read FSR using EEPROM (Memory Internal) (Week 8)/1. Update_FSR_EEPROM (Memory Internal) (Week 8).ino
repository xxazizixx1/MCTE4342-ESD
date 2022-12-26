//By Azizi Bin Mohamad Tambi (1919661)

/***This code is used to update the value of the FSR to the EEPROM of the Arduino***/
/*** Use this code to update the value only ***/

//Library for EEPROM
#include <EEPROM.h>

//Define pin for FSR
#define fsrPin A0

//Variable definition
int address = 0;
int valFSR;

void setup() {
  pinMode(fsrPin, INPUT);
}
 
void loop() {
  
  valFSR = analogRead(fsrPin) / 4; //Calculate the value of FSR. Divide by 4 because 1023 / 4 =255
 
  EEPROM.update(address, valFSR); //Update the EEPROM everytime. These values will remain although the board is off
 
  address = address + 1;
  if (address == EEPROM.length()) {
    address = 0;
  } 
  delay(100);
}