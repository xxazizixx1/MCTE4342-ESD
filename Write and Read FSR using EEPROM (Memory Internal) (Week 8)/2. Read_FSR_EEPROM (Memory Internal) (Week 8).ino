//By Azizi Bin Mohamad Tambi (1919661)

/***This code is used to read the value of the FSR inside the EEPROM of the Arduino***/
/*** Use this code to READ the value only ***/

//Library for EEPROM
#include <EEPROM.h>

//Define pin for FSR
#define fsrPin A0

//Variable definition
int address = 0;
int valFSR; 
 
void setup() {
  Serial.begin(9600);
  pinMode(fsrPin, INPUT);
  
  while(!Serial) //while not connected
  {
    Serial.print("...");
  }
}
 
void loop() {
  valFSR = analogRead(fsrPin)/4;
  valFSR = EEPROM.read(address);  //Read value from the EEPROM
  
  Serial.print(address);
  Serial.print("\t");
  Serial.print(valFSR, DEC);
  Serial.println();
  
  address = address + 1;
  if(address == EEPROM.length())
  {
    address = 0;
  }
  
  delay(500);
}