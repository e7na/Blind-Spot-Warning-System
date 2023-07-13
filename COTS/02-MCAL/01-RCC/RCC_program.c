/*****************************************************************/
/* Author 	: Essam												 */
/* Version	: V01												 */
/* Date 	: 30 March 2022										 */
/*****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void MRCC_voidInitSysClock(void)
{
	#if		RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR 	 = 0x00010000; /*Enable HSE with no bypass*/
		RCC_CFGR = 0x00000001;
	#elif	RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR   = 0x00050000; /*Enable HSE with bypass*/
		RCC_CFGR = 0x00000001;
		
	#elif	RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR   = 0x00000081; /*Enable HSI*/
		RCC_CFGR = 0x00000000;
		
	#elif	RCC_CLOCK_TYPE == RCC_PLL	
		#if	  RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2  /* Enable HSI with PLLDivided by 2*/
			RCC_CR   = 0x01000081;
			RCC_CFGR = 0x00000000;
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2	/* Enable HSE with PLL Divided by 2*/
			#if RCC_CLOCK_TYPE == RCC_HSE_RC
			RCC_CR   = 0x01050000;
			#elif RCC_PLL_INPUT == RCC_HSE_CRYSTAL	/* Enable HSE Crystal with PLL */
			RCC_CR   = 0x01010000;
			#endif
			RCC_CFGR = 0x00030001;		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
			#if RCC_CLOCK_TYPE == RCC_HSE_RC		/* Enable HSE RC with PLL*/
			RCC_CR   = 0x01050000;
			#elif RCC_PLL_INPUT == RCC_HSE_CRYSTAL	/* Enable HSE Crystal with PLL*/
			RCC_CR   = 0x01010000;
			#endif
			RCC_CFGR = 0x00010001;
		#endif

	/* Multiplication Factor for PLL*/
	#if	RCC_CLOCK_TYPE	== RCC_PLL
		#if RCC_PLL_MUL_VAL   == 2
			RCC_CFGR |= 0x00000000;
		#elif RCC_PLL_MUL_VAL == 3
			RCC_CFGR |= 0x00040000;
		#elif RCC_PLL_MUL_VAL == 4
			RCC_CFGR |= 0x00080000;
		#elif RCC_PLL_MUL_VAL == 5
			RCC_CFGR |= 0x000C0000;
		#elif RCC_PLL_MUL_VAL == 6
			RCC_CFGR |= 0x00100000;
		#elif RCC_PLL_MUL_VAL == 7
			RCC_CFGR |= 0x00140000;
		#elif RCC_PLL_MUL_VAL == 8
			RCC_CFGR |= 0x00180000;
		#elif RCC_PLL_MUL_VAL == 9
			RCC_CFGR |= 0x001C0000;
		#elif RCC_PLL_MUL_VAL == 10
			RCC_CFGR |= 0x00200000;
		#elif RCC_PLL_MUL_VAL == 11
			RCC_CFGR |= 0x00240000;
		#elif RCC_PLL_MUL_VAL == 12
			RCC_CFGR |= 0x00280000;
		#elif RCC_PLL_MUL_VAL == 13
			RCC_CFGR |= 0x002C0000;
		#elif RCC_PLL_MUL_VAL == 14
			RCC_CFGR |= 0x00300000;
		#elif RCC_PLL_MUL_VAL == 15
			RCC_CFGR |= 0x00340000;
		#elif RCC_PLL_MUL_VAL == 16
			RCC_CFGR |= 0x00380000;
		#elif RCC_PLL_MUL_VAL == 16
			RCC_CFGR |= 0x003C0000;
			
		#endif
		
	#endif
		
	#else	
		#error("You chose wrong Clock type")
	#endif
}



void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if (Copy_u8PerId <=31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHP	: SET_BIT(RCC_AHBENR,Copy_u8PerId); 		break;			
			case RCC_APB1	: SET_BIT(RCC_APB1ENR,Copy_u8PerId);		break;
			case RCC_APB2	: SET_BIT(RCC_APB2ENR,Copy_u8PerId); 		break;
		}
	}
	
	else
	{
		/*return Error*/
	}
}


void MRCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if (Copy_u8PerId <=31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHP	: CLR_BIT(RCC_AHBENR,Copy_u8PerId); 		break;			
			case RCC_APB1	: CLR_BIT(RCC_APB1ENR,Copy_u8PerId);		break;
			case RCC_APB2	: CLR_BIT(RCC_APB2ENR,Copy_u8PerId); 		break;
		}
	}
	
	else
	{
		/*return Error*/
	}
}
