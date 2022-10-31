/* By Azizi Bin Mohamad Tambi(1919661)
Remark: ~PORT_D as output(All LED) =Red(PD0),Yellow(PD1),Green(PD2),Red(PD3),Yellow(PD4),Green(PD5),Red(PD6),Yellow(PD7)
		    ~PORT_B as input (All Button) =Button A(PB4), Button B(PB5)
*/
#include <avr/io.h>
#include <avr/delay.h>
#define F_CPU 16000000        //atmega328p uses 16Mhz processor

int main(void)
{
  uint16_t shift = 1;         //create an integer to shift the led by 1
  
  DDRD = 0xFF;                //0b1111 1111, Here, we define all port D to be output
  DDRB &= 0xCF;               //0b1100 1111, Here, we define only PB4 and PB5 as an input
  
  PORTB = (1<<PORTB4) | (1<<PORTB5);      //activate the pull-up resistor in PB4 and PB5
  
  while(1)                    //while true
  {
    if((PINB & (1 << PINB4)) == 0) //if the pin is shifted, which is LOW, increment the LED by 1
    {
      _delay_ms(300);         //small delay as hard debounce
      if(shift >= 0x80)
      {
        shift = 1;
      }
      else
      {
        shift *= 2;
      }
    }
    
    if((PINB & (1 << PINB5)) == 0)        //if the pin is shifted, which is LOW, decrement the LED by 1
    {
      _delay_ms(300);          //use small delay as a hard debouncing
      if(shift <= 1)
      {
        shift = 0x80;
      }
      else
      {
        shift /= 2;
      }
    }
    PORTD = shift;
  }
}