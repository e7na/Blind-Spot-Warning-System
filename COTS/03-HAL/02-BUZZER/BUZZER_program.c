/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 4 Sept 2022							*/
/*	Version : V01									*/
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"


#include "BUZZER_interface.h"
#include "BUZZER_private.h"
#include "BUZZER_config.h"



void HBUZZER_voidBUZZERInit ( u8 Copy_u8PORT , u8 Copy_u8PIN )
{
		MGPIO_voidSetPinDirection ( Copy_u8PORT , Copy_u8PIN , OUTPUT_SPEED_2MHZ_PUSH_PULL );
}

void HBUZZER_voidBUZZERTurnON( u8 Copy_u8PORT , u8 Copy_u8PIN )
{
	MGPIO_voidSetPinValue( Copy_u8PORT , Copy_u8PIN , GPIO_HIGH);
}

void HBUZZER_voidBUZZERTurnOFF( u8 Copy_u8PORT , u8 Copy_u8PIN )
{
	MGPIO_voidSetPinValue ( Copy_u8PORT , Copy_u8PIN , GPIO_LOW);
}
