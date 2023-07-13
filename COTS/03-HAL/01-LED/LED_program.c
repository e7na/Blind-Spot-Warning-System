/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 4 Sept 2022							*/
/*	Version : V01									*/
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

void HLED_voidLedInit  (  u8 Copy_u8PORT , u8 Copy_u8PIN )
{
	MGPIO_voidSetPinDirection ( Copy_u8PORT , Copy_u8PIN , OUTPUT_SPEED_2MHZ_PUSH_PULL );
}

void HLED_voidLedTurnON ( u8 Copy_u8PORT , u8 Copy_u8PIN )
{
	MGPIO_voidSetPinValue( Copy_u8PORT , Copy_u8PIN , GPIO_HIGH);
}

void HLED_voidLedTurnOFF( u8 Copy_u8PORT , u8 Copy_u8PIN )
{
	MGPIO_voidSetPinValue ( Copy_u8PORT , Copy_u8PIN , GPIO_LOW);
}


void HLED_voidLedToggle ( u8 Copy_u8PORT , u8 Copy_u8PIN )
{
	MGPIO_voidTogglePinValue( Copy_u8PORT , Copy_u8PIN );
}
