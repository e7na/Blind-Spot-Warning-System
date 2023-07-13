/*********************************************************************************/
/* Author    : Essam                                                   		     */
/* Version   : V01                                                               */
/* Date      : 21 Aug 2022                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

 /* Define CallBack Global Variable */
static  void (*MSTK_CallBack)(void);

 /* Define Variable for interval mode */
static  u8 Copy_u8ModeOfInterval;

	
void MSTK_voidInit(void)
{
		/*Disable STK Interrupt - Disable STK -  Apply AHB as clock source   */
	#if	MSTK_CLK_SOURCE == MSTK_SRC_AHB 
		MSTK -> CTRL = 0x00000004;
	#else
		/*Disable STK Interrupt - Disable STK -  Apply AHB/8 as clock source */	
		MSTK -> CTRL = 0;
	#endif

}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	MSTK -> LOAD = Copy_u32Ticks ;
		/* Start Timer*/
	SET_BIT(MSTK->CTRL , 0);
		/*Wait for raising flag*/
	while( (GET_BIT(MSTK->CTRL,16)) == 0);
	
		/*Stop timer*/
	CLR_BIT(MSTK->CTRL , 0);
	MSTK -> LOAD =  0 ;
	MSTK -> VAL  =  0 ;
}



void MSTK_voidSetIntervalSingle( u32 Copy_u32Ticks , void (*Copy_ptr)(void) )
{	 /*Load Ticks to load register*/
	MSTK -> LOAD = Copy_u32Ticks ;
	 /* Start Timer */
	SET_BIT(MSTK -> CTRL , 0 );
	 /* Save CallBack */
	MSTK_CallBack = Copy_ptr;
	 /*Set Mode to single */
	Copy_u8ModeOfInterval = MSTK_SINGLE_INTERVAL ;
	 /*Enable timer Interrupt*/
	SET_BIT( MSTK -> CTRL , 1 );	
}


void MSTK_voidSetInervalPeriodic( u32 Copy_u32Ticks , void (*Copy_ptr) (void) )
{
	 /* Start Counting from the begining if a new timer has called */
	 CLR_BIT( MSTK -> CTRL , 0 );
	 MSTK -> VAL = 0;
	
	 /*Load Ticks to load Register*/
	MSTK -> LOAD = Copy_u32Ticks ;
	 /*Start Timer*/
	SET_BIT( MSTK -> CTRL , 0 );
	 /*Save CallBack*/
	MSTK_CallBack = Copy_ptr ;
	 /*Set mode to periodic*/
	Copy_u8ModeOfInterval = MSTK_PERIOD_INTERVAL;
	 /*Enable timer Interrupt*/
	SET_BIT( MSTK -> CTRL ,1);
}


void MSTK_voidStopInterval(void)
{
	/*Disable Timer Interrupt*/
	CLR_BIT( MSTK ->CTRL , 1 );
	/*Stop Timer*/
	CLR_BIT(MSTK->CTRL , 0);
	MSTK -> LOAD =  0 ;
	MSTK -> VAL  =  0 ;
}



u32  MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	Local_u32ElapsedTime = (MSTK -> LOAD) - (MSTK ->VAL);
	
	return Local_u32ElapsedTime;
}

u32  MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainigTime;
	Local_u32RemainigTime = MSTK -> VAL ;
	return Local_u32RemainigTime;
}




void SysTick_Handler(void)
{
	u8 Local_u32Temporary;
	
	if( Copy_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		 /*Disable STK Interrupt*/
		CLR_BIT( MSTK -> CTRL , 1);
		 /*Stop Timer*/
		CLR_BIT(MSTK->CTRL , 0);
		MSTK -> LOAD =  0 ;
		MSTK -> VAL  =  0 ;
	}
	/*CallBack Notification*/
	MSTK_CallBack();
	
	/*Clear Interrupt Flag*/
	Local_u32Temporary = GET_BIT( MSTK -> CTRL ,16);
}




