/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 4 Sept 2022							*/
/*	Version : V01									*/
/****************************************************/
#ifndef	BUZZER_INTERFACE_H
#define BUZZER_INTERFACE_H


/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	HBUZZER_voidBUZZERInit
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	U8(Port),u8(Pin No)/ none
   Return			 	:	void
   Function Description :	Initialize BUZZER
*/
void HBUZZER_voidBUZZERInit ( u8 Copy_u8PORT , u8 Copy_u8PIN );
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	HBUZZER_voidBUZZERTurnON
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	U8(Port),u8(Pin No)/ none
   Return			 	:	void
   Function Description :	Turn BUZZER ON
*/
void HBUZZER_voidBUZZERTurnON( u8 Copy_u8PORT , u8 Copy_u8PIN );
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	HBUZZER_voidBUZZERTurnOFF
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	U8(Port),u8(Pin No)/ none
   Return			 	:	void
   Function Description :	Turn BUZZER OFF
*/
void HBUZZER_voidBUZZERTurnOFF( u8 Copy_u8PORT , u8 Copy_u8PIN );
/*==============================================================================================================*/

/*==============================================================================================================*/


#endif
