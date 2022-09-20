
// **************************************************HEADER GUARD**************************************************

#ifndef APPLICATION_H_
#define APPLICATION_H_
// **************************************************INCLUDES**************************************************
#include "../ECUAL/LED/LED.h"
#include "../Utilities/Interrupts.h"
#include "../MCAL/timer/timer.h"
// **************************************************DEFINES**************************************************
// Traffic Colors and pin numbers
#define GREEN 0
#define YELLOW 1
#define RED 2

//Car Traffic PORT
#define CAR_PORT PORT_A

//Pedestrian Traffic Port
#define PEDESTRIAN_PORT PORT_B

//Logic for checking pedestrian mode used in backFromPedestrian variable
#define NO 0
#define YES 1

//directions of traffic to differentiate yellow to red and yellow to green used in direction variable
#define DOWN 0
#define UP 1  

//Type of traffic to help implementing setTrafficLight function
#define CAR_TRAFFIC 0
#define PEDESTRIAN_TRAFFIC 1
// **************************************************DECLARATIONS**************************************************
volatile uint8_t carTrafficStatus; // current color of car traffic
volatile uint8_t backFromPedestrian; // logic variable to send communication from pedestrian mode when finished to normal mode
uint8_t direction; // determine the direction of traffic to differentiate between yellow traffic going to red and yellow traffic to green
// **************************************************FUNCTIONS PROTOTYPE**************************************************
// Initialize parameters needed
void app_init();

// calls normal mode from main
void app_start();

/* the function takes which traffic to set its light and the color then it sets this color and turns off the other */
void setTrafficLight(uint8_t traffic, uint8_t color);

/* the function implements the yellow traffic with an on period of 1sec and off period of 1sec */
void blinkYellowTraffic(uint8_t mode);

// the pedestrian mode handles both the cars and pedestrian traffic with delay when the push button is pressed 
void pedestrianMode();

/* the normal mode function implements the cars traffic and the delays between the lights except for the yellow color
as the blink function implements the delay */
void normalMode();
#endif