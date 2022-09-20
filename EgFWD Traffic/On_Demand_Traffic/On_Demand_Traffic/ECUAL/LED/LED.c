
#include "LED.h"

void LED_init(uint8_t ledPort, uint8_t ledPin)
{
	DIO_init(ledPort , ledPin, OUT); // initialize pin as output
}

void LED_on(uint8_t ledPort, uint8_t ledPin)
{
	DIO_write(ledPort , ledPin, HIGH); // write high to LED pin
}

void LED_off(uint8_t ledPort, uint8_t ledPin)
{
	DIO_write(ledPort , ledPin, LOW); // write low to LED pin
}

void LED_toggle(uint8_t ledPort, uint8_t ledPin)
{
	DIO_toggle(ledPort , ledPin); // change LED status by using toggle function
}

