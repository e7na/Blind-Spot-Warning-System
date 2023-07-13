/*********************************************************************************/
/* Author    : Essam                                                      */
/* Version   : V01                                                               */
/* Date      : 27 April 2022                                                     */
/*********************************************************************************/

#ifndef		DIO_PIVATE_H
#define		DIO_PIVATE_H

	/*	GPIO PORTS BASE ADDRESSES	*/
#define		GPIOA_BASE_ADDRESS		0x40010800	
#define		GPIOB_BASE_ADDRESS		0x40010C00
#define		GPIOC_BASE_ADDRESS		0x40011000

	/*	PORTA REGISTER ADDRESSES*/
#define		GPIOA_CRL		*((u32 *) (GPIOA_BASE_ADDRESS+0x00))
#define		GPIOA_CRH		*((u32 *) (GPIOA_BASE_ADDRESS+0x04))
#define		GPIOA_IDR		*((u32 *) (GPIOA_BASE_ADDRESS+0x08))
#define		GPIOA_ODR		*((u32 *) (GPIOA_BASE_ADDRESS+0x0C))
#define		GPIOA_BSR		*((u32 *) (GPIOA_BASE_ADDRESS+0x10))
#define		GPIOA_BRR		*((u32 *) (GPIOA_BASE_ADDRESS+0x14))
#define		GPIOA_LCK		*((u32 *) (GPIOA_BASE_ADDRESS+0x18))

	/*	PORTB REGISTER ADDRESSES*/
#define		GPIOB_CRL		*((u32 *) (GPIOB_BASE_ADDRESS+0x00))
#define		GPIOB_CRH		*((u32 *) (GPIOB_BASE_ADDRESS+0x04))
#define		GPIOB_IDR		*((u32 *) (GPIOB_BASE_ADDRESS+0x08))
#define		GPIOB_ODR		*((u32 *) (GPIOB_BASE_ADDRESS+0x0C))
#define		GPIOB_BSR		*((u32 *) (GPIOB_BASE_ADDRESS+0x10))
#define		GPIOB_BRR		*((u32 *) (GPIOB_BASE_ADDRESS+0x14))
#define		GPIOB_LCK		*((u32 *) (GPIOB_BASE_ADDRESS+0x18))

	/*	PORTC REGISTER ADDRESSES*/
#define		GPIOC_CRL		*((u32 *) (GPIOC_BASE_ADDRESS+0x00))
#define		GPIOC_CRH		*((u32 *) (GPIOC_BASE_ADDRESS+0x04))
#define		GPIOC_IDR		*((u32 *) (GPIOC_BASE_ADDRESS+0x08))
#define		GPIOC_ODR		*((u32 *) (GPIOC_BASE_ADDRESS+0x0C))
#define		GPIOC_BSR		*((u32 *) (GPIOC_BASE_ADDRESS+0x10))
#define		GPIOC_BRR		*((u32 *) (GPIOC_BASE_ADDRESS+0x14))
#define		GPIOC_LCK		*((u32 *) (GPIOC_BASE_ADDRESS+0x18))



#endif