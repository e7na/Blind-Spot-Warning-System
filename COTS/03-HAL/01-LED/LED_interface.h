/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 4 Sept 2022							*/
/*	Version : V01									*/
/****************************************************/
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "STD_TYPES.h"

/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	HLED_voidLedInit
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	U8(Port),u8(Pin No)/ none
   Return			 	:	void
   Function Description :	Initialize LED
*/
	void HLED_voidLedInit ( u8 Copy_u8PORT , u8 Copy_u8PIN );
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	HLED_voidLedTurnON
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	U8(Port),u8(Pin No)/ none
   Return			 	:	void
   Function Description :	Turn LED ON
*/

void HLED_voidLedTurnON( u8 Copy_u8PORT , u8 Copy_u8PIN );
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	HLED_voidLedTurnOFF
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	U8(Port),u8(Pin No)/ none
   Return			 	:	void
   Function Description :	Turn LED OFF
*/

void HLED_voidLedTurnOFF( u8 Copy_u8PORT , u8 Copy_u8PIN );
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	HLED_voidLedToggle
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	U8(Port),u8(Pin No)/ none
   Return			 	:	void
   Function Description :	Toggle LED state
*/

void HLED_voidLedToggle( u8 Copy_u8PORT , u8 Copy_u8PIN );
/*==============================================================================================================*/

/*==============================================================================================================*/


#endif
