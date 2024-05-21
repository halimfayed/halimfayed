/*
 * graduation project for amit.c
 *
 * Created: 11/02/2024 19:51:24
 * Author : T
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#include "APP/APP.h"

/* For internal PWM "Timer0" : Just copy & paste ! */
// modes :
// Timer0FastPWM
// Timer0PhaseCorrectPWM

// freq :

// ClockValue_16000KHZ			>> 62.5 KHz
// ClockValue_2000KHZ			>> 7.8	KHZ

int main(void)
{
	/* Internal PWM SIGNAl */

	PWM_Drawer_internal_init(Timer0FastPWM,ClockValue_16000KHZ,80);

	/* External PWM SIGNAl */

	PWM_Drawer_external_init();

	while (1)
	{
		PWM_Get_Signal();	//Signal measurement
		PWM_Draw_Signal();	//Sign drawing
	}
}
