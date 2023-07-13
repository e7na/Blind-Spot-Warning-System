/*****************************************************************/
/* Author 	: Essam												 */
/* Version	: V01												 */
/* Date 	: 26 APRIL 2023										 */
/*****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "DELAY_interface.h"
#include "DELAY_private.h"
#include "DELAY_config.h"


void _delay_ms( u32 Copy_u32Time )
{
	MSTK_voidInit();
	MSTK_voidSetBusyWait( Copy_u32Time *1000 );
}

void _delay_us( u32 Copy_u32Time )
{
	MSTK_voidInit();
	MSTK_voidSetBusyWait( Copy_u32Time );
}