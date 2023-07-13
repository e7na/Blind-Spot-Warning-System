/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 3 August 2022							*/
/*	Version : V01									*/
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


	/*  Dummy Function and Future Removable	*/
/*==============================================*/
void MNVIC_voidInit(void)
{
	#define SCB_AIRCR	*((u32*)0xE000ED0C)
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}


void MNVIC_voidSetPriority(u8 Copy_u8PeripheralIdx , u8 Copy_u8Priority)
{
	if( Copy_u8PeripheralIdx <60)
	{
		NVIC_IPR[Copy_u8PeripheralIdx] = Copy_u8Priority;
	}		
	else
	{
		/* Return Error*/
	}
}

void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber)
{
	if( Copy_u8IntNumber <=31)
	{
		/* (1: SET , 0:No effect)*/
		/* Because SET_BIT does OR operation (Read -> Change -> Writeback) */

		NVIC_ISER0 = (1 << Copy_u8IntNumber);
	}
	else if( Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -=32;	
		NVIC_ISER1 = (1 << Copy_u8IntNumber) ;
	}
	else
	{
		/*Return Error */
	}
}

void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber)
{
	if( Copy_u8IntNumber <=31)
	{
		/* (1: SET , 0:No effect)*/
		/* Because SET_BIT does OR operation (Read -> Change -> Writeback) */

		NVIC_ICER0 = (1 << Copy_u8IntNumber);
	}
	else if( Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -=32;
		NVIC_ICER1 = (1 << Copy_u8IntNumber) ;
	}
	else
	{
		/*Return Error */
	}
}

void MNVIC_voidSetPendingFlag (u8 Copy_u8IntNumber)
{
	if( Copy_u8IntNumber <=31)
	{
		/* (1: SET , 0:No effect)*/
		/* Because SET_BIT does OR operation (Read -> Change -> Writeback) */

		NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	}
	else if( Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -=32;
		NVIC_ISPR1 = (1 << Copy_u8IntNumber) ;
	}
	else
	{
		/*Return Error */
	}
}


void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber)
{
	if( Copy_u8IntNumber <=31)
	{
		/* (1: SET , 0:No effect)*/
		/* Because SET_BIT does OR operation (Read -> Change -> Writeback) */

		NVIC_ICPR0 = (1 << Copy_u8IntNumber);
	}
	else if( Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -=32;
		NVIC_ICPR1 = (1 << Copy_u8IntNumber) ;
	}
	else
	{
		/*Return Error */
	}
}

u8 MNVIC_u8GetActiveFlag (u8 Copy_u8IntNumber)
{
	u8 Local_u8Result;
	if( Copy_u8IntNumber <=31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	}
	else if( Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -=32;
		Local_u8Result = GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
	}
	else
	{
		/*Return Error */
	}
	return Local_u8Result;
}


	/*	Unused Function */
/*=============================*/

//void MNVIC_voidSetPriority(s8 copy_s8IntID ,u8 copy_u8GroupPriority ,u8 copy_u8SubPriority ,u32 copy_u32GROUP)
//{							/*0x05FA0300  3Group & 1 Sub priority */
//	u8 local_u8Priority = copy_u8SubPriority|(copy_u8GroupPriority<<((copy_u32GROUP - 0x05FA0300)/256));

	/* Core Peripheral		*/

	/* External Peripheral	*/
//	if(copy_s8IntID >= 0)
//	{
//		IPR[copy_s8IntID] = local_u8Priority << 4 ;
//	}
//	SCB_AIRCR = copy_u32GROUP;
//}
 