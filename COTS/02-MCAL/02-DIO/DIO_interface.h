/*********************************************************************************/
/* Author    : Essam                                                   		     */
/* Version   : V02                                                               */
/* Date      : 27 April 2022                                                     */
/*********************************************************************************/

#ifndef		DIO_INTERFACE_H
#define		DIO_INTERFACE_H


/*	*/
#define		GPIO_LOW		0
#define		GPIO_HIGH		1

/* Select 8 High Pins,Low Pins */
#define 	GPIO_POS_LOW	0
#define 	GPIO_POS_HIGH	1



#define 	GPIO_INPUT		0
#define		GPIO_OUTPUT		1


#define HIGH_PORTL 			0x00FF /* Set from bit 0 to 15 */
#define HIGH_PORTH		    0xFF00 /* Set from bit 16 to 31 */
	
	/* DEFINE GPIO	PORTS */
//===============================
#define		GPIOA	0
#define		GPIOB	1
#define		GPIOC	2

	/*	DEFINE GPIO PINS */
//===============================
#define		PIN0	0
#define		PIN1	1
#define		PIN2	2
#define		PIN3	3
#define		PIN4	4
#define		PIN5	5
#define		PIN6	6
#define		PIN7	7
#define		PIN8	8
#define		PIN9	9
#define		PIN10	10
#define		PIN11	11
#define		PIN12	12
#define		PIN13	13
#define		PIN14	14
#define		PIN15	15

	 /*  DEFINE PIN MODES	*/
//=====================================
		 /* INPUT MODES */
	/*==============================*/	
#define		INPUT_ANALOG		0b0000
#define		INPUT_FLOATING		0b0100
#define		INPUT_PULL_UP_DOWN	0b1000	

		    /* OUTPUT MODES */	
	/*==============================*/	
				/*10MHZ_SPEED*/
			//====================
#define		OUTPUT_SPEED_10MHZ_PUSH_PULL				0b0001
#define		OUTPUT_SPEED_10MHZ_OPEN_DRAIN				0b0101
#define		OUTPUT_SPEED_10MHZ_AF_PUSH_PULL				0b1001
#define		OUTPUT_SPEED_10MHZ_AF_OPEN_DRAIN			0b1101

				/*2MHZ_SPEED*/
			//====================
#define		OUTPUT_SPEED_2MHZ_PUSH_PULL					0b0010
#define		OUTPUT_SPEED_2MHZ_OPEN_DRAIN				0b0110
#define		OUTPUT_SPEED_2MHZ_AF_PUSH_PULL				0b1010
#define		OUTPUT_SPEED_2MHZ_AF_OPEN_DRAIN				0b1110

				/*50MHZ_SPEED*/
			//====================
#define		OUTPUT_SPEED_50MHZ_PUSH_PULL				0b0011
#define		OUTPUT_SPEED_50MHZ_OPEN_DRAIN				0b0111
#define		OUTPUT_SPEED_50MHZ_AF_PUSH_PULL				0b1011
#define		OUTPUT_SPEED_50MHZ_AF_OPEN_DRAIN			0b1111



/*
   Function Name     	:	MGPIO_voidSetPinDirection
   Characteristics   	:	Non Reentrant , Synchronous
   Parameters In/out 	:	u8(PortName),u8(PinNumber),u8(Mode:input , output) / None
   Return			 	:	void
   Function Description :	Set the direction of Pin with frequency speed
*/
void	MGPIO_voidSetPinDirection	(u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Mode);
/*============================================================================================================*/


/*
   Function Name     	:	MGPIO_voidSetPinValue
   Characteristics   	:	Non Reentrant , Synchronous
   Parameters In/out 	:	u8(PortName),u8(PinNumber),u8(Value:High , Low) / None
   Return			 	:	void
   Function Description :	Set the output value for the selected pin (Low ,High)
*/
void	MGPIO_voidSetPinValue	(u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Value);

/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	MGPIO_voidTogglePinValue
   Characteristics   	:	Non Reentrant , Synchronous
   Parameters In/out 	:	u8(PortName),u8(PinNumber) / None
   Return			 	:	void
   Function Description :	Toggle the pin value to opposite value
*/
void 	MGPIO_voidTogglePinValue(u8 Copy_u8PORT , u8 Copy_u8PIN );

/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	MGPIO_u8GetPinValue
   Characteristics   	:	Non Reentrant , Synchronous
   Parameters In/out 	:	u8(PortName),u8(PinNumber) / u8(PinValue)
   Return			 	:	u8
   Function Description :	get the value of the pin
*/
u8		MGPIO_u8GetPinValue		(u8 Copy_u8PORT , u8 Copy_u8PIN );
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	MGPIO_voidSetPortDirection
   Characteristics   	:	Non Reentrant , Synchronous
   Parameters In/out 	:	u8(PortName),u8(portPosition),u8(Mode) / None
   Return			 	:	void
   Function Description :	Set the direction of 8 pins in the same port
*/

void	MGPIO_voidSetPortDirection ( u8 Copy_u8Port , u8 Copy_u8Position , u8 Copy_u8Mode   );
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	MGPIO_voidSetPortValue
   Characteristics   	:	Non Reentrant , Synchronous
   Parameters In/out 	:   u8(PortName),u8(portPosition),u8(Mode) / None
   Return			 	:   void
   Function Description :   Set the value of 8 pins in the same port
*/

void	MGPIO_voidSetPortValue( u8 Copy_u8Port , u8 Copy_u8Position , u16 Copy_u8Value );
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	MGPIO_u16GetPortValue
   Characteristics   	:	Non Reentrant , Synchronous
   Parameters In/out 	:   u8(PortName),u8(portPosition),u8(Mode) / u16(portValues)
   Return			 	:   u16
   Function Description :   Set the direction of 8 pins in the same port
*/
u16 MGPIO_u16GetPortValue( u8 Copy_u8Port , u8 Copy_u8Position );
/*==============================================================================================================*/

#endif
