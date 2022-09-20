
#include "timer.h"

void delay_1s()
{
	// timer initializations
	uint8_t overflowCounter = 0;
	TCNT0 = 0x00;
	TCCR0 |= (1<<0) | (1<<1); // start the timer (prescalar = 64)
	while(overflowCounter < NUMBER_OF_OVERFLOWS)
	{
		//wait for the timer flag
		while ((TIFR & (1<<0)) == 0);
		
		//Clear the flag
		TIFR |= (1<<0);	
		
		overflowCounter++;
	}
	
	TCCR0 = 0x00;
	
}
void delay_seconds(uint8_t seconds)
{
	for(int i = 0; i < seconds; i++)
	{
		delay_1s();
	}
}

void timer1_delay_1s()
{
	// timer initializations
	TCCR1B = 0x00;
	TCNT1H = 0xC2;
	TCNT1L = 0xF7;
	TIFR |= (1<<2); // clear the flag
	TCCR1B |= ((1<<1) | (1<<0)); // start timer (prescalar = 64)
	while ((TIFR & (1<<2)) == 0);  // wait for flag
	
	TCCR1B = 0x00; // stop the timer
}

void Timer1_delay_5s()
{
	// timer initializations
	TCNT1H = 0xB3;
	TCNT1L = 0xB5;
	TIFR |= (1<<2); // clear the flag
	TCCR1B |= (1<<2); // start timer (prescalar = 256)
	
	while ((TIFR & (1<<2)) == 0); // wait for flag
	
	TCCR1B = 0x00; // stop the timer
	
}
