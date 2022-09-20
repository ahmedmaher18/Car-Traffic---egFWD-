/*
 * On_Demand_Traffic.c
 *
 * Created: 9/3/2022 7:41:13 PM
 * Author : Ahmed
 */ 

#define F_CPU 16000000UL
#include "Application/application.h"
int main(void)
{
	app_init();
   
    while (1) 
    {	
		
		normalMode();
		
	}
}

