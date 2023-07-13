/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 3 August 2022							*/
/*	Version : V01									*/
/****************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

    /* NVIC_BASE_ADDRESS */
/*=============================*/
#define		NVIC_BASE_ADDRESS	0xE000E100

	/*	SCB_BASE_ADDRESS */
/*=============================*/
//#define		SCB_BASE_ADDRESS	0xE000ED00

     /* NVIC REGISTERS ADDRESSES*/  
/*===================================*/
#define		NVIC_ISER0		*((u32*) (NVIC_BASE_ADDRESS + 0x000)) /* Enable External interrupts from 0 to 31*/
#define		NVIC_ISER1		*((u32*) (NVIC_BASE_ADDRESS + 0x004)) /* Enable External interrupts from 32 to 59*/
														   
#define 	NVIC_ICER0		*((u32*) (NVIC_BASE_ADDRESS + 0x080))	/*Interrupts Clear Enable External from 0 to 31*/
#define 	NVIC_ICER1		*((u32*) (NVIC_BASE_ADDRESS + 0x084))	/*Interrupts Clear Enable External from 32 to 59*/
														   
#define		NVIC_ISPR0		*((u32*) (NVIC_BASE_ADDRESS + 0x100)) /* External interrupts Set Pending flag from 0 to 31*/
#define		NVIC_ISPR1		*((u32*) (NVIC_BASE_ADDRESS + 0x104)) /* External interrupts Set Pending from 32 to 59*/
														   
#define		NVIC_ICPR0		*((u32*) (NVIC_BASE_ADDRESS + 0x180)) /* External interrupts Clear Pending Flag from 0 to 31*/
#define		NVIC_ICPR1		*((u32*) (NVIC_BASE_ADDRESS + 0x184)) /* External interrupts Clear Pending Flag from 32 to 59*/

#define		NVIC_IABR0		*((volatile u32*) (NVIC_BASE_ADDRESS + 0x200)) /* (Read Only)External interrupts Active Bit Register from 0 to 31*/
#define		NVIC_IABR1		*((volatile u32*) (NVIC_BASE_ADDRESS + 0x204)) /* (Read Only)External interrupts Active Bit Register from 32 to 59*/
																	
#define		NVIC_IPR		((volatile u8*) (NVIC_BASE_ADDRESS + 0x300))

//#define		SCB_AIRCR		*((u32*) (SCB_BASE_ADDRESS+0x0C))

	/*	NVIC Group and Sub Distribution  */
/*==========================================*/
#define	MNVIC_GROUP_4_SUB_0		0x05FA0300
#define	MNVIC_GROUP_3_SUB_1		0x05FA0400
#define	MNVIC_GROUP_2_SUB_2		0x05FA0500
#define	MNVIC_GROUP_1_SUB_3		0x05FA0600
#define	MNVIC_GROUP_0_SUB_4		0x05FA0700
#endif