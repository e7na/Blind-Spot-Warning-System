/*********************************************************************************/
/* Author    : Essam                 		                                     */
/* Version   : V02                                                               */
/* Date      : 29 Aug 2022                                                       */
/*********************************************************************************/

#include	"BIT_MATH.h"
#include	"STD_TYPES.h"

#include	"DIO_interface.h"
#include	"DIO_private.h"
#include	"DIO_config.h"


void	MGPIO_voidSetPinDirection(u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Mode)
{
	switch(Copy_u8PORT)
	{
		case GPIOA :
					if ( Copy_u8PIN <= 7)
					{
						GPIOA_CRL &= ~((0b1111)<< (Copy_u8PIN * 4) ); //Reset the pin before appliyng mode
						GPIOA_CRL |=  ((Copy_u8Mode)<< (Copy_u8PIN * 4) );	//Set Pin Mode
					}
					else if ( Copy_u8PIN <= 15)
					{
						Copy_u8PIN	-= 8 ; 
						GPIOA_CRH &= ~((0b1111)<< (Copy_u8PIN * 4) );
						GPIOA_CRH |=  ((Copy_u8Mode)<< (Copy_u8PIN * 4) );
					}
					break;
					
		case GPIOB :
					if ( Copy_u8PIN <= 7)
					{
						GPIOB_CRL &= ~((0b1111)<< (Copy_u8PIN * 4) ); //Reset the pin before appliyng mode
						GPIOB_CRL |=  ((Copy_u8Mode)<< (Copy_u8PIN * 4) );	//Set Pin Mode
					}
					else if ( Copy_u8PIN <= 15)
					{
						Copy_u8PIN	-= 8 ; 
						GPIOB_CRH &= ~((0b1111)<< (Copy_u8PIN * 4) );
						GPIOB_CRH |=  ((Copy_u8Mode)<< (Copy_u8PIN * 4) );
					}
					break;
		case GPIOC :
					if ( Copy_u8PIN <= 7)
					{
						GPIOC_CRL &= ~((0b1111)<< (Copy_u8PIN * 4) ); //Reset the pin before appliyng mode
						GPIOC_CRL |= ((Copy_u8Mode)<< (Copy_u8PIN * 4) );	//Set Pin Mode
					}
					else if ( Copy_u8PIN <= 15)
					{
						Copy_u8PIN	-= 8 ; 
						GPIOC_CRH &= ~((0b1111)<< (Copy_u8PIN * 4) );
						GPIOC_CRH |=  ((Copy_u8Mode)<< (Copy_u8PIN * 4) );
					}
					break;
		default: break;
	}
}


void  MGPIO_voidSetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Value)
{
	 switch(Copy_u8PORT)
	{
		case GPIOA :
					if (Copy_u8Value == GPIO_HIGH)
					{
						SET_BIT(GPIOA_ODR , Copy_u8PIN); 
					}
					else if (Copy_u8Value==GPIO_LOW)
					{
						CLR_BIT(GPIOA_ODR , Copy_u8PIN);
					}
					break;
		case GPIOB :
					if (Copy_u8Value == GPIO_HIGH)
					{
						SET_BIT(GPIOB_ODR , Copy_u8PIN); 
					}
					else if (Copy_u8Value== GPIO_LOW)
					{
						CLR_BIT(GPIOB_ODR , Copy_u8PIN);
					}
					break;
		case GPIOC :
					if (Copy_u8Value == GPIO_HIGH)
					{
						SET_BIT(GPIOC_ODR , Copy_u8PIN); 
					}
					else if (Copy_u8Value== GPIO_LOW)
					{
						CLR_BIT(GPIOC_ODR , Copy_u8PIN);
					}
					break;
		default : break;
	}
}

void 	MGPIO_voidTogglePinValue (u8 Copy_u8PORT , u8 Copy_u8PIN )
{
	switch(Copy_u8PORT)
	{
		case GPIOA  :	TOG_BIT(GPIOA_ODR , Copy_u8PIN);    break;
		case GPIOB 	:	TOG_BIT(GPIOB_ODR , Copy_u8PIN); 	break;
		case GPIOC 	:	TOG_BIT(GPIOC_ODR , Copy_u8PIN);    break;
		default : break;
	}
}

u8	 MGPIO_u8GetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN )
{
	u8	LOC_u8Result = 0;
	
	switch(Copy_u8PORT)
	{
		case GPIOA :	LOC_u8Result = GET_BIT(GPIOA_IDR,Copy_u8PIN);  break;
		case GPIOB :	LOC_u8Result = GET_BIT(GPIOB_IDR,Copy_u8PIN);  break;
		case GPIOC :	LOC_u8Result = GET_BIT(GPIOC_IDR,Copy_u8PIN);  break;
		default : break;
	}
	return LOC_u8Result ;
}


void MGPIO_voidSetPortDirection ( u8 Copy_u8Port , u8 Copy_u8Position , u8 Copy_u8Mode   )
{
	switch( Copy_u8Port ){

	case GPIOA:

		if      ( Copy_u8Position == GPIO_POS_LOW  ) { GPIOA_CRL = ( 0x11111111 * Copy_u8Mode ) ; }
		else if ( Copy_u8Position == GPIO_POS_HIGH ) { GPIOA_CRH = ( 0x11111111 * Copy_u8Mode ) ; }

		break;
	case GPIOB:

		if      ( Copy_u8Position == GPIO_POS_LOW  ) { GPIOB_CRL = ( 0x11111111 * Copy_u8Mode ) ; }
		else if ( Copy_u8Position == GPIO_POS_HIGH ) { GPIOB_CRH = ( 0x11111111 * Copy_u8Mode ) ; }

		break;
	case GPIOC:

		if      ( Copy_u8Position == GPIO_POS_LOW  ) { GPIOC_CRL = ( 0x11111111 * Copy_u8Mode ) ; }
		else if ( Copy_u8Position == GPIO_POS_HIGH ) { GPIOC_CRH = ( 0x11111111 * Copy_u8Mode ) ; }

		break;
	default :break;
	}
}
void MGPIO_voidSetPortValue( u8 Copy_u8Port , u8 Copy_u8Position , u16 Copy_u8Value )
{
	switch( Copy_u8Port ){

	case GPIOA:

		if      ( Copy_u8Position == GPIO_POS_LOW  ){ GPIOA_ODR &= 0xFF00; }
		else if ( Copy_u8Position == GPIO_POS_HIGH ){ GPIOA_ODR &= 0x00FF; }

		GPIOA_ODR |= Copy_u8Value ;

		break;
	case GPIOB:

		if      ( Copy_u8Position == GPIO_POS_LOW  ){ GPIOB_ODR &= 0xFF00; }
		else if ( Copy_u8Position == GPIO_POS_HIGH ){ GPIOB_ODR &= 0x00FF; }

		GPIOB_ODR |= Copy_u8Value ;

		break;
	case GPIOC:

		if      ( Copy_u8Position == GPIO_POS_LOW  ){ GPIOC_ODR &= 0xFF00; }
		else if ( Copy_u8Position == GPIO_POS_HIGH ){ GPIOC_ODR &= 0x00FF; }

		GPIOC_ODR |= Copy_u8Value ;

		break;
	default:break;
	
	}
}
u16  MGPIO_u16GetPortValue  ( u8 Copy_u8Port , u8 Copy_u8Position                   )
{
	u16 LOC_u16Result = 0;

	switch( Copy_u8Port ){

	case GPIOA:

		LOC_u16Result = GPIOA_IDR;
		if      ( Copy_u8Position == GPIO_POS_LOW  ){ LOC_u16Result &= 0x00FF ; }
		else if ( Copy_u8Position == GPIO_POS_HIGH ){ LOC_u16Result &= 0xFF00 ; }

		break;
	
	case GPIOB:

		LOC_u16Result = GPIOB_IDR;
		if      ( Copy_u8Position == GPIO_POS_LOW  ){ LOC_u16Result &= 0x00FF ; }
		else if ( Copy_u8Position == GPIO_POS_HIGH ){ LOC_u16Result &= 0xFF00 ; }

		break;
	
	case GPIOC:

		LOC_u16Result = GPIOC_IDR;
		if      ( Copy_u8Position == GPIO_POS_LOW  ){ LOC_u16Result &= 0x00FF ; }
		else if ( Copy_u8Position == GPIO_POS_HIGH ){ LOC_u16Result &= 0xFF00 ; }

		break;
	default : break;
	}

	return LOC_u16Result ;
}
