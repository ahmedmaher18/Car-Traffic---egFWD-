
#include "button.h"


void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin)   // Initialize button
{
	DIO_init(buttonPin, buttonPort, IN);
}

void BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value)
{
	DIO_read(buttonPin, buttonPort, value); // value is 1 if button is pressed as we are using pull-down configuration
}