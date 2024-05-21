/*
 * DIO_prog.c
 *
 * Created: 14/05/2024 11:31:56
 *  Author: T
 */ 
#include "../../Liberaries/STD_TYPES.h"
#include "../../Liberaries/BIT_MATH.h"
#include "../../Liberaries/ERROR_TYPES.h"
#include "DIO_register.h"
#include "DIO_config.h"
#include "DIO_priv.h"

//#include "DIO_interface.h"



ES_T DIO_enuInit(void)
{
	ES_T Local_enu_ErrorState= ES_NOT_OK ;
	//	0bPA7PA6PA5PA4PA3PA2PA1PA0
	DDRA=0x01;
	PORTA=0x01;
	//DDRA= INIT_DDR_DIRECTION;
	//PORTA= INIT_PORT_VALUE;

	//DDRA=CONC(DIO_u8PA7_DIR,DIO_u8PA6_DIR,DIO_u8PA5_DIR,DIO_u8PA4_DIR,DIO_u8PA3_DIR,DIO_u8PA2_DIR,DIO_u8PA1_DIR,DIO_u8PA0_DIR);

	//PORTA=CONC(DIO_u8PA7_VALUE,DIO_u8PA6_VALUE,DIO_u8PA5_VALUE,DIO_u8PA4_VALUE,DIO_u8PA3_VALUE,DIO_u8PA2_VALUE,DIO_u8PA1_VALUE,DIO_u8PA0_VALUE);

	return Local_enu_ErrorState;
}

ES_T DIO_enuSetPinDirection(uint8 copy_u8PortID , uint8 copy_u8PinID , uint8 copy_u8Direction)
{
	ES_T Local_enu_ErrorState= ES_NOT_OK ;
	if(copy_u8PinID<=DIO_u8PIN7)
	{
		if(copy_u8Direction == DIO_u8PIN_INPUT)
		{
			switch(copy_u8PortID)
			{
				case DIO_u8PORTA :
				DDRA &=~(1<<copy_u8PinID);
				// CLEAR_BIT_VALUE(DDRA,copy_u8PinID);
				break;
				case DIO_u8PORTB : CLEAR_BIT_VALUE(DDRB,copy_u8PinID);
				break;
				case DIO_u8PORTC : CLEAR_BIT_VALUE(DDRC,copy_u8PinID);
				break;
				case DIO_u8PORTD : CLEAR_BIT_VALUE(DDRD,copy_u8PinID);
				break;
				default :Local_enu_ErrorState= ES_OUT_OF_RANGE;
				break;
			}
		}
		else if (copy_u8Direction== DIO_u8OUTPUT)
		{
			switch(copy_u8PortID)
			{
				case DIO_u8PORTA : SET_BIT_VALUE(DDRA,copy_u8PinID);
				break;
				case DIO_u8PORTB : SET_BIT_VALUE(DDRB,copy_u8PinID);
				break;
				case DIO_u8PORTC : SET_BIT_VALUE(DDRC,copy_u8PinID);
				break;
				case DIO_u8PORTD : SET_BIT_VALUE(DDRD,copy_u8PinID);
				break;
				default :Local_enu_ErrorState= ES_OUT_OF_RANGE;
				break;
			}
		}


		else
		{
			Local_enu_ErrorState= ES_NOT_OK;

		}
	}

	else
	{
		Local_enu_ErrorState= ES_OUT_OF_RANGE;
	}

	return Local_enu_ErrorState;
}

ES_T DIO_enuSetPinValue (uint8 copy_u8PortID , uint8 copy_u8PinID , uint8 copy_u8Value)
{
	ES_T Local_enu_ErrorState= ES_NOT_OK ;
	if(copy_u8PinID<=DIO_u8PIN7)
	{
		if(copy_u8Value == DIO_u8PIN_LOW)
		{
			switch(copy_u8PortID)
			{
				case DIO_u8PORTA : CLEAR_BIT_VALUE(PORTA,copy_u8PinID);
				break;
				case DIO_u8PORTB : CLEAR_BIT_VALUE(PORTB,copy_u8PinID);
				break;
				case DIO_u8PORTC : CLEAR_BIT_VALUE(PORTC,copy_u8PinID);
				break;
				case DIO_u8PORTD : CLEAR_BIT_VALUE(PORTD,copy_u8PinID);
				break;
				default :Local_enu_ErrorState= ES_OUT_OF_RANGE;
				break;
			}
		}
		else if(copy_u8Value == DIO_u8PIN_HIGH)
		{
			switch(copy_u8PortID)
			{
				case DIO_u8PORTA : SET_BIT_VALUE(PORTA,copy_u8PinID);
				break;
				case DIO_u8PORTB : SET_BIT_VALUE(PORTB,copy_u8PinID);
				break;
				case DIO_u8PORTC : SET_BIT_VALUE(PORTC,copy_u8PinID);
				break;
				case DIO_u8PORTD : SET_BIT_VALUE(PORTD,copy_u8PinID);
				break;
				default :Local_enu_ErrorState= ES_OUT_OF_RANGE;
				break;
			}
		}


		else
		{
			Local_enu_ErrorState= ES_NOT_OK;

		}
	}
	else
	{
		Local_enu_ErrorState= ES_OUT_OF_RANGE;
	}

	return Local_enu_ErrorState;
}


ES_T DIO_enuTogglePinValue (uint8 copy_u8PortID , uint8 copy_u8PinID)
{
	ES_T Local_enu_ErrorState= ES_NOT_OK ;
	if(copy_u8PinID<=DIO_u8PIN7)
	{
		switch(copy_u8PortID)
		{
			case DIO_u8PORTA : TOGGLE_BIT_VALUE(PORTA,copy_u8PinID);
			break;
			case DIO_u8PORTB : TOGGLE_BIT_VALUE(PORTB,copy_u8PinID);
			break;
			case DIO_u8PORTC : TOGGLE_BIT_VALUE(PORTC,copy_u8PinID);
			break;
			case DIO_u8PORTD : TOGGLE_BIT_VALUE(PORTD,copy_u8PinID);
			break;
			default :Local_enu_ErrorState= ES_OUT_OF_RANGE;
			break;
		}

	}

	else
	{
		Local_enu_ErrorState= ES_OUT_OF_RANGE;
	}


	return Local_enu_ErrorState;
}