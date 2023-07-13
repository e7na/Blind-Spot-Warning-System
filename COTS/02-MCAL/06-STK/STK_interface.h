/*********************************************************************************/
/* Author    : Essam                                                   		     */
/* Version   : V01                                                               */
/* Date      : 21 Aug 2022                                                       */
/*********************************************************************************/

#ifndef	STK_INTERFACE_H
#define	STK_INTERFACE_H

/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	MSTK_voidInit
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	none, none
   Return			 	:	void
   Function Description :	Initialize SysTick Core Peripheral
*/
void MSTK_voidInit(void);
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	MSTK_voidSetBusyWait
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	u32(ticksNumber), none
   Return			 	:	void
   Function Description :	Block the system for ticksNumber time synchronously
*/
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	MSTK_voidSetIntervalSingle
   Characteristics   	:	Non-Reentrant, Asynchronous
   Parameters In/out 	:	u32(TicksNumber),Pointer to function/ none
   Return			 	:	void
   Function Description :	Counting number of ticks asynchronously then firing call back function just ONCE
*/
void MSTK_voidSetIntervalSingle( u32 Copy_u32Ticks , void (*Copy_ptr) (void) );
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	MSTK_voidSetInervalPeriodic
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	none, none
   Return			 	:	void
   Function Description :	Counting number of ticks asynchronously then firing call back function PERIODICLY
*/
void MSTK_voidSetInervalPeriodic( u32 Copy_u32Ticks , void (*Copy_ptr) (void) );
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	MSTK_voidStopInterval
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	none, none
   Return			 	:	void
   Function Description :	Stop the timer counting
*/
void MSTK_voidStopInterval(void);
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	MSTK_u32GetElapsedTime
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	None/u32(ElapsedTime)
   Return			 	:	U32
   Function Description :	Calculate then return the elapsed time from timer start counting
*/
u32  MSTK_u32GetElapsedTime(void);
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	MSTK_u32GetRemainingTime
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	none, u32(RemainingTime)
   Return			 	:	U32
   Function Description :	Calculate then return the remaining time in the timer value register
*/
u32  MSTK_u32GetRemainingTime(void);

/*==============================================================================================================*/
/*==============================================================================================================*/
#endif
