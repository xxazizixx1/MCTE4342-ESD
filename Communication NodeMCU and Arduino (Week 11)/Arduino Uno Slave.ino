/* Azizi Bin Mohamad Tambi (1919661)
...This code is for Arduino Uno as a Slave... */

//Library
#include <Wire.h>

//Assigning Pin
#define LED 5

//Variables
char a;

void setup()
{
  Wire.begin(8); //Join i2c bus with address 8
  Wire.onReceive(receiveEvent); //Register receive event
  Wire.onRequest(requestEvent); //Register requestEvent
  Serial.begin(9600);
  
  pinMode(LED, OUTPUT) //set LED as an output
}

void loop()
{
  delay(100);
}

//This function is to be executed when data is received from master NODEMCU
void receiveEvent(int x)
{
  while(0<Wire.available())
  {
    a = Wire.read();
    Serial.print(a);      
  }
  Serial.println();
}

//This function will be executed whenever data is requested from master NODEMCU
void requestEvent()
{
  Wire.write("Hello NodeMCU, Im Uno");
  digitalWrite(LED, HIGH);
  delay(2000);
  digitalWrite(LED, LOW);
}