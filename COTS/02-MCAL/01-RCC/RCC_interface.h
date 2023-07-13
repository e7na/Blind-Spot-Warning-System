/*****************************************************************/
/* Author 	: Essam												 */
/* Version	: V01												 */
/* Date 	: 30 March 2022										 */
/*****************************************************************/
#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H


#define RCC_AHP		0	
#define RCC_APB1	1	
#define RCC_APB2	2


/*
   Function Name     	:	MRCC_voidInitSysClock
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	none,none
   Return			 	:	void
   Function Description :	Initializing the whole system clock
*/
void MRCC_voidInitSysClock(void);


/* ==========================================================================*/


/*
   Function Name     	: 	MRCC_voidEnableClock
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	u8(BusID),u8(PeripheralID) / none
   Return			 	:	void
   Function Description :	Enable clock for the selected peripheral
*/
void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);

/*=============================================================================*/


/*
   Function Name     	:	MRCC_voidDisableClock
   Characteristics   	:   Non-Reentrant ,Synchronous
   Parameters In/out 	:   u8(BusID),u8(PeripheralID) / none
   Return			 	:   void
   Function Description :	Disable clock for the selected peripheral
*/

void MRCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);

#endif
