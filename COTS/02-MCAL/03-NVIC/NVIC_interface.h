/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 3 August 2022							*/
/*	Version : V01									*/
/****************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_voidEnableInterrupt 	(u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag 	(u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);
u8 	 MNVIC_u8GetActiveFlag	 	(u8 Copy_u8IntNumber);

void MNVIC_voidInit(void);
void MNVIC_voidSetPriority(u8 Copy_u8PeripheralIdx , u8 Copy_u8Priority);


	/* Unused MACROS For Unused Function  */
/*================================================*/
/*
#define		GROUP3		0x05FA0300  //4 bits for Group & 0 bit for Sub	
#define		GROUP4		0x05FA0400  //3 bits for Group & 1 bit for Sub	
#define		GROUP5		0x05FA0500  //2 bits for Group & 2 bit for Sub	
#define		GROUP6		0x05FA0600  //1 bits for Group & 3 bit for Sub	
#define		GROUP7		0x05FA0700  //0 bits for Group & 4 bit for Sub	
*/

#endif
