/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 24 April 2023							*/
/*	Version : V02									*/
/****************************************************/
#ifndef	TFLUNA_INTERFACE_H
#define TFLUNA_INTERFACE_H


 #define  BAUD_RATE_9600  			1
 #define  BAUD_RATE_115200			2


 #define  FPS_0HZ					0
 #define  FPS_10HZ					1
 #define  FPS_100HZ					2



/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	HTFL_VoidInit
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	none, none
   Return			 	:	void
   Function Description :	Initialize TF Luna LiDAR
*/
void 	HTFL_VoidInit					( 	void	);
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	HTFL_u16GetDistanceCm
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	None/ u16(measuredDistance)
   Return			 	:	U16
   Function Description :	Get the measured distance in cm
*/
u16 	HTFL_u16GetDistanceCm			(	void 	);
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	HTFL_VoidClearBuffer
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	none, none
   Return			 	:	void
   Function Description :	Clear buffer after every measuring time
*/
void	HTFL_VoidClearBuffer			(	void	);
/*==============================================================================================================*/

/*==============================================================================================================*/

#endif
