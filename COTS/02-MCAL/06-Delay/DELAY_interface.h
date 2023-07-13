/*****************************************************************/
/* Author 	: Essam												 */
/* Version	: V01												 */
/* Date 	: 26 APRIL 2023										 */
/*****************************************************************/
#ifndef DELAY_INTERFACE_H
#define DELAY_INTERFACE_H

/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	_delay_ms
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	u32(delayTime in msec), none
   Return			 	:	void
   Function Description :	Busy wait delay in milli seconds
*/

void _delay_ms( u32 Copy_u32Time );
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	_delay_us
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	u32(delayTime in usec), none
   Return			 	:	void
   Function Description :	Busy wait delay in micro seconds
*/
void _delay_us( u32 Copy_u32Time );
/*==============================================================================================================*/

/*==============================================================================================================*/
#endif
