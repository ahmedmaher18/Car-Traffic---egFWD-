
#include "application.h"
void app_init()
{
	// configuring output pins:
	
	DIO_init(PORT_A, PIN0, OUT);
	DIO_init(PORT_A, PIN1, OUT);
	DIO_init(PORT_A, PIN2, OUT);
	DIO_init(PORT_B, PIN0, OUT);
	DIO_init(PORT_B, PIN1, OUT);
	DIO_init(PORT_B, PIN2, OUT);
	// initializing used variables
	
	carTrafficStatus = GREEN;
	backFromPedestrian = NO;
	direction = DOWN;
	// Interrupts setup
	
	sei();         // Enabling Global Interrupts
	MCUCR|= (1<<1) | (1<<0);  // Rising Edge Setup
	GICR|=(1<<6); // External Interrupt Request 0 Enable
}

void setTrafficLight(uint8_t traffic, uint8_t color)
{
	if (traffic == CAR_TRAFFIC) // read if we need to change car traffic or pedestrian traffic
	{
	switch(color) // see which color to implement the changes
	{
		case GREEN:
		LED_on(CAR_PORT, GREEN);
		LED_off(CAR_PORT, YELLOW);
		LED_off(CAR_PORT, RED);
		break;
		case YELLOW:
		LED_off(CAR_PORT, GREEN);
		LED_off(CAR_PORT , RED);
		blinkYellowTraffic(CAR_TRAFFIC);
		break;
		case RED:
		LED_off(CAR_PORT,GREEN);
		LED_off(CAR_PORT,YELLOW);
		LED_on(CAR_PORT, RED);
		break;
	}
	}
	else if(traffic == PEDESTRIAN_TRAFFIC) // implementing same functionality but on pedestrian traffic
	{
		switch(color)
		{
			case GREEN:
			LED_on(PEDESTRIAN_PORT, GREEN);
			LED_off(PEDESTRIAN_PORT, YELLOW);
			LED_off(PEDESTRIAN_PORT, RED);
			break;
			case YELLOW:
			LED_off(PEDESTRIAN_PORT, GREEN);
			LED_off(PEDESTRIAN_PORT , RED);
			blinkYellowTraffic(PEDESTRIAN_TRAFFIC);
			break;
			case RED:
			LED_off(PEDESTRIAN_PORT,GREEN);
			LED_off(PEDESTRIAN_PORT,YELLOW);
			LED_on(PEDESTRIAN_PORT, RED);
			break;
		}
	}
}

void blinkYellowTraffic(uint8_t mode) 
{
	
	uint8_t counter = 5; // counter to keep toggling Yellow led every second for 5 seconds
	for (int i = 0; i<counter; i++)
	{
		// if we are in pedestrian mode we want to toggle both yellow traffic but the car traffic in both cases will be toggled
		if (mode == PEDESTRIAN_TRAFFIC) 
		{
		LED_toggle(PEDESTRIAN_PORT, YELLOW);
		}
		LED_toggle(CAR_PORT, YELLOW);
		// 1 second delay to blink
		timer1_delay_1s();
		// if the ISR interrupted this function we want to break it as soon as possible to get back to green color in car traffic
		if (backFromPedestrian == YES) 
		{
			return;
		}
		
	}
	
}


void normalMode()
{
	
	while(1)
	{	
		// see which car traffic color turn is it
			switch(carTrafficStatus)
		{
			case GREEN:
			setTrafficLight(CAR_TRAFFIC,GREEN); // turns on the green light
			Timer1_delay_5s(); // 5 seconds delay
			/* if we are back from interrupt the variable will be yes then we will need to break the switch statement
			 to start over */
			if (backFromPedestrian == YES) 
			{
				backFromPedestrian = NO; 
				break;
			}
			// if not then we continue normally and set the yellow traffic turn
				carTrafficStatus = YELLOW;
				break;
			
			case YELLOW:
			setTrafficLight(CAR_TRAFFIC,YELLOW); // implements the blinking with delay
			/* if we are back from interrupt the variable will be yes then we will need to break the switch statement
			 to start over */
			if (backFromPedestrian == YES)
			{
				backFromPedestrian = NO;
				break;
			}
			// if direction is down then its the red traffic turn
			else if(direction == DOWN)
			{
				carTrafficStatus = RED;
				break;
			}
			// if the direction is up then it is the green traffic turn
			else if(direction == UP)
			{
				carTrafficStatus = GREEN;
				direction = DOWN;
				break;
			}
			case RED:
			setTrafficLight(CAR_TRAFFIC,RED); // turns on red traffic
			Timer1_delay_5s(); // delay 5 seconds
			/* if we are back from interrupt the variable will be yes then we will need to break the switch statement
			 to start over */
			if (backFromPedestrian == YES)
			{
				backFromPedestrian = NO;
				break;
			}
			// else it will be yellow turn and we set the direction is up
			else
			{
				carTrafficStatus = YELLOW;
				direction = UP;
				break;
			}
		}
	}
}

void pedestrianMode()
{
	// get the car traffic status that the program interrupted
	if(carTrafficStatus == RED)
	{
		
		setTrafficLight(PEDESTRIAN_TRAFFIC, GREEN); // set green in pedestrian traffic and then 
		Timer1_delay_5s(); // 5 seconds delay
		LED_off(CAR_PORT, RED); // turn off red in car traffic
		setTrafficLight(PEDESTRIAN_TRAFFIC, YELLOW); // both yellow traffic will be blinking
		setTrafficLight(PEDESTRIAN_TRAFFIC, RED); // set pedestrian traffic to red until someone pushes the button again
		carTrafficStatus = GREEN; // set the status to green to return to green in car traffic
		backFromPedestrian = YES; // set to yes so that the switch statement is broken as soon as possible so that car traffic returns to green
		return;
	}
	else if((carTrafficStatus == YELLOW) || (carTrafficStatus == GREEN))
	{
		// turn off both car traffic that are possible to be on
		LED_off(CAR_PORT, GREEN);
		LED_off(CAR_PORT, YELLOW);
		setTrafficLight(PEDESTRIAN_TRAFFIC, YELLOW); // blinking of both yellow traffic
		setTrafficLight(PEDESTRIAN_TRAFFIC, GREEN); // set pedestrian traffic to green
		setTrafficLight(CAR_TRAFFIC, RED); // set car traffic to green
		Timer1_delay_5s(); // delay 5 seconds
		LED_off(CAR_PORT, RED); // urn off car traffic
		setTrafficLight(PEDESTRIAN_TRAFFIC, YELLOW); // both yellow traffic blinking again
		setTrafficLight(PEDESTRIAN_TRAFFIC, RED); // set pedestrian traffic to red until the button is pressed again
		carTrafficStatus = GREEN; // set status to green to return to green in car traffic
		backFromPedestrian = YES; // set to yes so that the switch statement is broken as soon as possible so that car traffic returns to green
		return;
	}
	
}

// interrupt service routine
ISR(EXT_INT_0)
{
	pedestrianMode();
}