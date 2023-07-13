/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 24 April 2023							*/
/*	Version : V02									*/
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

#define THRESHOLD_VALUE  9000000UL

	/* Call Back */
void (*MUSART1_CallBack) (void ) ;

void	MUSART1_VoidInit		(  void	 )
{
		/* Calculating  Mantissa and Fraction to Set BRR Value */
	u32 LOC_u32Mantissa = ( F_CPU ) / ( 16 * USART1_BAUD_RATE );
	u32 LOC_u32Fraction = ( ( (F_CPU * 100) / (16 * USART1_BAUD_RATE) )% 100) *16 ;
	
	if (LOC_u32Fraction > 1500 )
	{
		LOC_u32Mantissa +=1;
		LOC_u32Fraction = 0;
	}
	
	#if USART1_STATUS == UART1_ENABLE 
		MUSART1 -> SR = 0 ; 
		
		#if 	USART1_WORD_LENGTH == _8BIT_WORD_LENGTH
			CLR_BIT( MUSART1 -> CR1 , 12 );
			
		#elif   USART1_WORD_LENGTH == _9BIT_WORD_LENGTH
			SET_BIT( MUSART1 -> CR1 , 12 );
			
		#endif 
	
	
		#if 	USART1_PARITY == PARITY_DISABLE
			CLR_BIT( MUSART1 -> CR1 , 10);
			
		#elif 	USART1_PARITY == EVEN_PARITY
			SET_BIT( MUSART1 -> CR1 , 10);
			CLR_BIT( MUSART1 -> CR1 , 9);
			
		#elif 	USART1_PARITY == ODD_PARITY
			SET_BIT( MUSART1 -> CR1 , 10);
			SET_BIT( MUSART1 -> CR1 , 9);
		
		#endif
		
		#if 	USART1_INTERRUPT ==  INT_DISABLE
			CLR_BIT( MUSART1 -> CR1 , 5);
			CLR_BIT( MUSART1 -> CR1 , 6);
			CLR_BIT( MUSART1 -> CR1 , 7);
		
		#elif	 USART1_INTERRUPT == TXE_INT_ENABLE
			SET_BIT( MUSART1 -> CR1 , 7);
			
		#elif    USART1_INTERRUPT == TCE_INT_ENABLE
			SET_BIT( MUSART1 -> CR1 , 6);	 
			
		#elif    USART1_INTERRUPT == RXNE_INT_ENABLE
			SET_BIT( MUSART1 -> CR1 , 5);
		
		#endif
		
		#if 	USART1_TRANSMITTER == TRANSMITTER_DISABLE
			CLR_BIT( MUSART1 -> CR1 , 3);
		
		#elif   USART1_TRANSMITTER == TRANSMITTER_ENABLE
			SET_BIT( MUSART1 -> CR1 , 3);
			
		#endif 
		
		
		#if 	USART1_RECEIVER == RECEIVER_DISABLE
			CLR_BIT( MUSART1 -> CR1 , 2);
			
		#elif   USART1_RECEIVER == RECEIVER_ENABLE
			SET_BIT( MUSART1 -> CR1 , 2);
			
		#endif 
		
		
		#if 	USART1_STOP_BITS == ONE_STOP_BIT	
			CLR_BIT( MUSART1 -> CR2 , 12);
			CLR_BIT( MUSART1 -> CR2 , 13);
		
		#elif 	USART1_STOP_BITS == HALF_STOP_BIT
			SET_BIT( MUSART1 -> CR2 , 12);
			CLR_BIT( MUSART1 -> CR2 , 13);
			
		#elif 	USART1_STOP_BITS == TWO_STOP_BIT 
			CLR_BIT( MUSART1 -> CR2 , 12);
			SET_BIT( MUSART1 -> CR2 , 13);
			
		#elif 	USART1_STOP_BITS == ONE_AND_HALF_STOP_BIT	
			SET_BIT( MUSART1 -> CR2 , 12);
			SET_BIT( MUSART1 -> CR2 , 13);
			
		#endif
		
			/* SET BRR Value */
		MUSART1 -> BRR = ( LOC_u32Mantissa << 4 ) | ( LOC_u32Fraction /100 );
	
			/*  Enable UART    */
		SET_BIT(MUSART1 -> CR1 , 13);
		
	
	#elif USART1_STATUS == UART1_DISABLE
		CLR_BIT( MUSART1 -> CR1 , 0); /* Send BREAK */
		
	#endif 
			
}

void MUSART1_VoidSendChars(  u8 *Copy_Ptr	,u8 Copy_u8size	)
{
	u8 LOC_u8Iterator = 0;
	while (  LOC_u8Iterator  < Copy_u8size )
	{
			/* Transmit String Char by Char */
		MUSART1_VoidSendCharSync( Copy_Ptr [LOC_u8Iterator] );
		LOC_u8Iterator++;
	}
}


void	MUSART1_VoidSendCharSync 		 ( u8  Copy_u8Char		) 
{
		/* Assign character to be sent in Data Register */
	MUSART1 -> DR = Copy_u8Char;
		/* Wait until Transmission is Completed */
 	while(GET_BIT( MUSART1 -> SR , 6) == 0);
		/* Clear Transmission Complete Flag */
	CLR_BIT(MUSART1 -> SR , 6);
}


//void 	MUSART1_VoidSendStringSync		 ( u8 *Copy_PtrString 	)
//{
//	u8 LOC_u8Iterator = 0;
//	while ( Copy_PtrString[ LOC_u8Iterator ] != '\0' )
//	{
//			/* Transmit String Char by Char */
//		MUSART1_VoidSendCharSync( Copy_PtrString [LOC_u8Iterator] );
//		LOC_u8Iterator++;
//	}
//}



u8 		MUSART1_u8RecieveCharSync	 (		void	 		) 
{
	u8  LOC_u8Data 	   = 0 ; 
	u32 LOC_u32TimeOut = 0 ;
		/* Clear Received Data Completed Flag */
	CLR_BIT( MUSART1 -> SR , 5);
	
	while( ( GET_BIT( MUSART1 -> SR , 5 ) == 0) && (LOC_u32TimeOut < THRESHOLD_VALUE) )
	{
		LOC_u32TimeOut ++ ;
	}
	
	if( LOC_u32TimeOut == THRESHOLD_VALUE )
	{
		LOC_u8Data = 255 ;
	}
	else 
	{
		LOC_u8Data = MUSART1 -> DR ;
	}
	return LOC_u8Data ;
}

u8 String[30];
u8 	 *	MUSART1_PtrReceiveString_Sync(  	void	 	    )
{	
	u8 LOC_u8Iterator = 0 , LOC_u8DataCome ;
	
		/* 13 in ASCii = Carriage Return which is (\r\n) that means */
		/*	new Line and the end of the sent string */
	while( (LOC_u8DataCome = MUSART1_u8RecieveCharSync() ) != 13 )
	{
		String[ LOC_u8Iterator ] = LOC_u8DataCome ;
		LOC_u8Iterator++ ;
	}
	String[ LOC_u8Iterator ] = '\0' ;
	
	return String ;
}


void 	MUSART1_VoidClearFlags 		 (  	void	 	    ) 
{
	MUSART1 -> SR = 0 ;
}

u8		MUSART1_u8ReadDataRegister	 (		void 			) 
{
		return ( MUSART1 -> DR );
}

void 	MUSART1_VoidSetCallBack		 ( void (*ptr) (void)	)
{
	MUSART1_CallBack = ptr ;
}


void USART1_IRQHandler( void )
{
	MUSART1 -> SR = 0 ;
	MUSART1_CallBack() ;
}

u8 USART1_receiveByte()
{
    while(GET_BIT(MUSART1->SR,5) == 0); // Wait until RXNE flag is set
    return ((u8)(MUSART1->DR)); // Return the received byte
}

