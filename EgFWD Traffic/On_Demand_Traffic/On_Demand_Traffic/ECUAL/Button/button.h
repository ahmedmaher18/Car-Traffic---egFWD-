
// **************************************************HEADER FILE GUARD**************************************************
#ifndef BUTTON_H
#define BUTTON_H
// **************************************************INCLUDES**************************************************

#include "../../MCAL/DIO/DIO.h"
#include "../../Utilities/types.h"

// **************************************************DEFINES**************************************************
#define BUTTON_1_PORT PORT_D
#define BUTTON_1_PIN PIN2 
// **************************************************FUNCTIONS PROTOTYPE**************************************************

void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);   // initialization

void BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value);  // button read

#endif