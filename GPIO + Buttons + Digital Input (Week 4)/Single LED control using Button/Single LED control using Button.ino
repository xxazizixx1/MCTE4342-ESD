/* By Azizi Bin Mohamad Tambi(1919661)
Remark: ~PORT_B=Red LED(PB0), Button (PB1)
*/

#include<avr/io.h>
#include<avr/delay.h>
#define F_CPU 16000000

int main(void)
{
  DDRB = 0x01; 		//0x0000 0001(0 is input, 1 i output)
  PORTB = 0x02;		//0x0000 0010(Setting up the initial state for LED and button)
  
  //By using AND gate, we create a MASK for button A(0x02)
  PINB = 0x02;
  
  while(1)
  {
    if(PINB & 0x02){
       _delay_ms(10);  	//Here, we use delay as debouncing. 
      PORTB |= 0x01;	//Using OR gate, we create a new MASK (0x0000 0111)
    }else{
      _delay_ms(10);
      PORTB &= 0xFE;	//We then create a new MASK again using AND gate 
    }
  }
}

//We use debouncing because arduino run codes line by line and it cannot multitask. 