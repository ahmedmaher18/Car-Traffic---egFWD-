
#ifndef INTERRUPTS_H
#define INTERRUPTS_H
#include "registers.h"
// **************************************************INTERRUPT VECTORS**************************************************
// External Interrupts:
// - External Interrupt Request 0
#define EXT_INT_0 __vector_1
// - External Interrupt Request 1
#define EXT_INT_1 __vector_2
// - External Interrupt Request 2
#define EXT_INT_2 __vector_3

// **************************************************INTERRUPT VECTORS**************************************************
// Enabling Global Interrupts
#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
// disable global interrupts
#define cli()  __asm__ __volatile__ ("cli" ::: "memory")
// definition of ISR
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used)); \
void INT_VECT(void)

#endif