/* By Azizi Bin Mohamad Tambi (1919661)
...This code is for Slave Arduino... */

//Library 
#include<SPI.h>                             

//Pin definition
#define LEDpin 7           
#define buttonpin 2

//Variables
volatile boolean received;
volatile byte Slavereceived,Slavesend;

int buttonvalue;
int x;

void setup()
{
  Serial.begin(9600);
  pinMode(LEDpin,INPUT);               
  pinMode(buttonpin,OUTPUT);                 
  pinMode(MISO,OUTPUT); //Sets MISO as OUTPUT (Have to Send data to Master IN 
 
  SPCR |= _BV(SPE);     //Turn on SPI in Slave Mode
  received = false;
  SPI.attachInterrupt();  //Turn on Interrupt for SPI communication
}


ISR (SPI_STC_vect)  //Interrupt routine function 
{
  Slavereceived = SPDR;  //Store received value from master
  received = true;       //Sets received as True 
}


void loop()
{ 
  if(received)  //If value is received from master, the slave will decide on what to do to the led.
  {
    if (Slavereceived==1) 
      {
        digitalWrite(LEDpin,HIGH); 
        Serial.println("Slave LED ON");
      }
  }
  else
  {
    digitalWrite(LEDpin,LOW);         
    Serial.println("Slave LED OFF");
  }
      
    buttonvalue = digitalRead(buttonpin);  //Reads the status of the pin 2   

  if (buttonvalue == HIGH)//Send value of X to master
  {
    x=1;        
  }
  else
  {
    x=0;
  }
  
  Slavesend=x;                             
  SPDR = Slavesend; //Sends the x value to master via SPDR 

  delay(1000);
 
}