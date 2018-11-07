/*
 * TEST_20181107.c
 *
 * Created: 2018-11-07 오후 3:43:28
 * Author : kccistc
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

static volatile uint8_t tim;

ISR(TIMER0_OVF_vect)
{
	tim ++;
	tim %= 64; 
	
}

int main(void)
{
	TCCR0 |= ((1<<CS02) | (1<<CS01) | (1<<CS00)); //1024 64 1초
	TIMSK |= (1 << TOIE0);
	
	DDRD=0xff;
 
 
	sei();

  while(1)
  {
		if(tim==20)
		
		{
		
			PORTD=0xff;

		}
		else
		{
			PORTD=0x00;
			
		}
		
  }
  
   
}

