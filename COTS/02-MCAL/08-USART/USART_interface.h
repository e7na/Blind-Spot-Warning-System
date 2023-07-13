/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 24 April 2023							*/
/*	Version : V02									*/
/****************************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

	/* USART1 STATUS*/
#define UART1_DISABLE			0	
#define URT1_ENABLE				1

	/* USART WORD LENGTH */
#define _8BIT_WORD_LENGTH		0
#define _9BIT_WORD_LENGTH		1

	/* USART PARITY */
#define EVEN_PARITY				0
#define ODD_PARITY				1
#define PARITY_DISABLE			2

	/* USART INTERRUPT */
#define INT_DISABLE				0
#define TXE_INT_ENABLE			1	
#define TCE_INT_ENABLE 			2
#define RXNE_INT_ENABLE			3

	/* USART TRANSMITTER */
#define TRANSMITTER_DISABLE		0
#define TRANSMITTER_ENABLE		1

	/* USART RECIEVER */
#define RECEIVER_DISABLE		0
#define RECEIVER_ENABLE			1

	/* USART STOP BIT */
#define ONE_STOP_BIT			0
#define HALF_STOP_BIT			1
#define TWO_STOP_BIT 			2
#define ONE_AND_HALF_STOP_BIT	3



							/* APIs */
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	MUSART1_VoidInit
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	none, none
   Return			 	:	void
   Function Description :	Initialize USART Peripheral
*/
void	MUSART1_VoidInit			 (      void 			) ;
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	MUSART1_VoidSendCharSync
   Characteristics   	:	Non-Reentrant, Synchronous
   Parameters In/out 	:	U8(char to be sent)/ none
   Return			 	:	void
   Function Description :	Send a character through USART serial synchronously
*/
void	MUSART1_VoidSendCharSync	 ( u8  Copy_u8Char		) ;
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:
   Characteristics   	:
   Parameters In/out 	:
   Return			 	:
   Function Description :
*/
/*void 	MUSART1_VoidSendStringSync	 ( u8 *Copy_PtrString 	) ;*/

/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:   MUSART1_u8RecieveCharSync
   Characteristics   	:   Non-Reentrant ,Synchronous
   Parameters In/out 	:   None/ u8(received character)
   Return			 	:   U8
   Function Description :   Receive character sent through USART synchronously with threshold time
*/
u8 		MUSART1_u8RecieveCharSync	 (		void	 		) ;
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	MUSART1_PtrReceiveString_Sync
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	None/ptr u8(receivedString)
   Return			 	:	U8*
   Function Description :	Receive string synchronously
*/
u8 	 *	MUSART1_PtrReceiveString_Sync(  	void	 	    ) ;
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	MUSART1_VoidClearFlags
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	none, none
   Return			 	:	void
   Function Description :	Clear USART interrupt flags
*/
void 	MUSART1_VoidClearFlags 		 (  	void	 	    ) ;
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	MUSART1_u8ReadDataRegister
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	None/u8(byte saved at data reg)
   Return			 	:	U8
   Function Description :	Read the byte saved in USART data register
*/
u8		MUSART1_u8ReadDataRegister	 (		void 			) ;
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	MUSART1_VoidSendChars
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	PointerU8(SendtString),u8(stringSize)/ none
   Return			 	:	void
   Function Description :	Send a string of characters through USART serial synchronously
*/
void    MUSART1_VoidSendChars		 (  u8 *Copy_Ptr,u8 Copy_u8size) ;
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	USART1_receiveByte
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	None/ u8(received character)
   Return			 	:	U8
   Function Description :	Receive character sent through USART synchronously
*/
u8 USART1_receiveByte(void);
/*==============================================================================================================*/


/*
   Function Name     	:	MUSART1_VoidSetCallBack
   Characteristics   	:	Reentrant, Synchronous
   Parameters In/out 	:	Ptr to function/none
   Return			 	:	void
   Function Description :	Firing call back function in USART interrupt firing
*/
void 	MUSART1_VoidSetCallBack		 ( void (*ptr) (void)	);
/*==============================================================================================================*/

/*==============================================================================================================*/

#endif
