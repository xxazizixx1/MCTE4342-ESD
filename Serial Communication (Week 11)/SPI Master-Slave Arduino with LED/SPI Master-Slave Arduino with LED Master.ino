/* By Azizi Bin Mohamad Tambi (1919661)
...This code is for Master Arduino... */

//Library 
#include<SPI.h>                             

//Pin definition
#define LED 7           
#define button 2

//Variables
int buttonvalue;
int x;

void setup (void)
{
  Serial.begin(9600); //Starts Serial Communication at Baud Rate 115200 
  pinMode(button,INPUT);                 
  pinMode(LED,OUTPUT);                    
  
  SPI.begin();  //Begins the SPI commnuication
  SPI.setClockDivider(SPI_CLOCK_DIV8);    //Sets clock for SPI communication at 8 (16/8=2Mhz). Arduino has 16Mhz speed 
  digitalWrite(SS,HIGH); // Setting SlaveSelect as HIGH (So master doesnt connnect with slave)

}


void loop(void)
{
  byte Mastersend,Mastereceive;          
  buttonvalue = digitalRead(button);  //Reads the status of the pin 2
  
  if(buttonvalue == HIGH) //To send the value of X to slave
  {
    x = 1;
  }

  else
  {
    x = 0;
  }
  
  digitalWrite(SS, LOW);                  //Starts communication with Slave connected to master  
  Mastersend = x;                            
  Mastereceive=SPI.transfer(Mastersend); //Send the mastersend value to slave also receives value from slave  

  if(Mastereceive == 1)                   //If master receive value of 1 from slave
  {
    digitalWrite(LED,HIGH);              //Sets pin 7 HIGH
    Serial.println("Master LED ON");
  }

  else
  {
   digitalWrite(LED,LOW);               //Sets pin 7 LOW
   Serial.println("Master LED OFF");
  }
  delay(1000);
}