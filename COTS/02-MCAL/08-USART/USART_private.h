/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 24 April 2023							*/
/*	Version : V02									*/
/****************************************************/
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

typedef struct
{
	volatile  u32	 SR 	;
	volatile  u32	 DR 	;
	volatile  u32	 BRR	;
	volatile  u32	 CR1	;
	volatile  u32	 CR2	;
	volatile  u32	 CR3	;
	volatile  u32	 GTPR	;
	
}USART_t;

#define 	MUSART1 	( (volatile USART_t*) 0x40013800)
#define 	MUSART2 	( (volatile USART_t*) 0x40004400)
#define 	MUSART3 	( (volatile USART_t*) 0x40004800)
#define 	MUART4  	( (volatile USART_t*) 0x40004C00)
#define 	MUART5 		( (volatile USART_t*) 0x40005000)

#endif
