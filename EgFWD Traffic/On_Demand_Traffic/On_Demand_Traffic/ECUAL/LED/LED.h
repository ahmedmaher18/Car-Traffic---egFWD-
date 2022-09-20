
// **************************************************HEADER FILE GUARD**************************************************

#ifndef LED_H
#define LED_H

// **************************************************INCLUDES**************************************************

#include "../../MCAL/DIO/DIO.h"
#include "../../Utilities/types.h"

// **************************************************FUNCTIONS PROTOTYPE**************************************************

// initialize port direction of LED to output
void LED_init(uint8_t ledPort, uint8_t ledPin);
// set the LED pin to high to turn it on
void LED_on(uint8_t ledPort, uint8_t ledPin);
// set the LED pin to low to turn it off
void LED_off(uint8_t ledPort, uint8_t ledPin);
// toggle the LED pin to change its status
void LED_toggle(uint8_t ledPort, uint8_t ledPin);


#endif