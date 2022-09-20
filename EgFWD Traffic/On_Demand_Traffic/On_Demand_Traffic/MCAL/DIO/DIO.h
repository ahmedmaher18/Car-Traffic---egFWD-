
// **************************************************INCLUDES**************************************************
#include <stdint.h>
#include "../../Utilities/registers.h"
#include "../../Utilities/types.h"

// **************************************************HEADER FILE GUARD**************************************************
#ifndef DIO_H_
#define DIO_H

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
// **************************************************DEFINES**************************************************

// direction defines
#define IN 0
#define OUT 1

// value defines
#define LOW 0
#define HIGH 1

// **************************************************FUNCTIONS PROTOTYPE**************************************************

void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction);// Initialize dio direction
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value); //write data to dio
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber); //toggle dio
void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value); //read dio







#endif