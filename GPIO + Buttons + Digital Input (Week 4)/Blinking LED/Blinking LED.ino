/* By Azizi Bin Mohamad Tambi(1919661)
Remark: ~PORT_D=Red LED(PD0)
*/

#include<avr/io.h>
#include<avr/delay.h>
#define F_CPU 16000000

void flashingLed(unsigned onTime, unsigned offTime); //Declare that we have a function

int main(void)
{
  DDRD = 0x02; //0b0000 0010; assigning PD1 as output.
  
  for(;;) //same as while(1)/while(True)
  {
    flashingLed(2000,500); //Call the blink function and LED will on for 2s and of for 0.5s
  }
}

//This function is to make LED blink
void flashingLed(unsigned onTime, unsigned offTime){
  PORTD = 0x02;  //bit 1 HIGH 0b0000 0010
  _delay_ms(onTime);
  PORTD = 0;	//all bit LOW
  _delay_ms(offTime);
}