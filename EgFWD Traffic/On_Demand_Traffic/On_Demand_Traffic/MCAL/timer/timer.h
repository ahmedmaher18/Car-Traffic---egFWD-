
#ifndef TIMER_H
#define TIMER_H
#include "../../Utilities/registers.h"
#include "../../Utilities/types.h"
//overflows needed for 1 seconds using prescalar 64 with timer 0
#define NUMBER_OF_OVERFLOWS 61
/* ************************Timer0 1 seconds calculations************************ */
/* prescalar = 64 -> tick = 64 / 10^6
number of ticks needed = 5 / tick
maximum number of ticks = 2^8 as timer0 is 8 bit
overflows = ceil (numbers of ticks / maximum number of ticks) = 61 */
void delay_1s();
// implement any needed number of seconds using for loop
void delay_seconds(uint8_t seconds);
/* ************************Timer1 1 second calculations************************ */
/* prescalar = 64 -> tick = 64 / 10^6
number of ticks needed = 1 / tick
maximum number of ticks = 2^16 as timer1 is 16-bit
since number of ticks < maximum number of ticks therefore no overflows is needed
initial value needed = 0xC2F7  -> therefore C2 in High and F7 in Low */
void timer1_delay_1s();
/* ************************Timer1 5 seconds calculations************************ */
/* prescalar = 256 -> tick = 256 / 10^6 
number of ticks needed = 5 / tick
maximum number of ticks = 2^16 as timer1 is 16-bit
since number of ticks < maximum number of ticks therefore no overflows is needed
initial value needed = maximum ticks - number of ticks needed = 0xB3B5 */
void Timer1_delay_5s();
#endif