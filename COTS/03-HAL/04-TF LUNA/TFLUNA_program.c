/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 27 April 2023							*/
/*	Version : V02									*/
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "DELAY_interface.h"

#include "TFLUNA_interface.h"
#include "TFLUNA_private.h"
#include "TFLUNA_config.h"


u8  volatile iterator = 0;
u8   DataCome[10];



void 	HTFL_VoidInit					( 	void	)
{

	/* 1- Set USART CALL BACK */



	u8 LOC_u8ResetCmd[] 	  		= {0x5A, 0x04 ,0x02 ,0x00 };
	u8 LOC_u8SetBaudRate9600Cmd[]   = {0x5A, 0x08 ,0x06, 0x80, 0x25, 0x00, 0x00, 0x00};
	u8 LOC_u8SetBaudRate115200Cmd[] = {0x5A , 0x08 , 0x06 ,0x00 , 0xC2 ,0x01 , 0x00 ,0x00};
	u8 LOC_u8Freq100HzCmd[]			= {0x5A, 0x06 ,0x03, 0x64, 0x00, 0x00};
	u8 LOC_u8Freq10HzCmd[]	   		= {0x5A, 0x06 ,0x03, 0x0A, 0x00, 0x00};
	u8 LOC_u8Freq0HzCmd[]	  	    = {0x5A, 0x06 ,0x03, 0x00, 0x00, 0x00};
	u8 LOC_u8DataFormatCmd[]   		= {0x5A, 0x05 ,0x05, 0x01, 0x00};
	u8 LOC_u8SaveSettingsCmd[] 		= {0x5A ,0x04 , 0x11 ,0x00};


		/* 2- Send Reset Command */
	//MUSART1_VoidSendStringSync(LOC_u8ResetCmd);
	MUSART1_VoidSendChars(  LOC_u8ResetCmd	,sizeof(LOC_u8ResetCmd));


	HTFL_VoidClearBuffer();

#if TFLUNA_BUAD_RATE ==  BAUD_RATE_115200
		/* 3- Set Baud Rate to 115200 */
	MUSART1_VoidSendChars(  LOC_u8SetBaudRate115200Cmd	,sizeof(LOC_u8SetBaudRate115200Cmd));
	HTFL_VoidClearBuffer();

#elif TFLUNA_BUAD_RATE == BAUD_RATE_9600
		/* 3- Set Baud Rate to 9600 */
	MUSART1_VoidSendChars(  LOC_u8SetBaudRate115200Cmd	,sizeof(LOC_u8SetBaudRate115200Cmd));
		HTFL_VoidClearBuffer();

#else
	#error ("WRONG BAUD RATE");

#endif
		/* 4- Set Data Format to 9 byte Cm */

	MUSART1_VoidSendChars(  LOC_u8DataFormatCmd	,sizeof(LOC_u8DataFormatCmd));

	HTFL_VoidClearBuffer();


	/* 5- Set sample Freq to 0 Hz */
#if TFLUNA_FPS == FPS_0HZ

		MUSART1_VoidSendChars(  LOC_u8Freq0HzCmd	,sizeof(LOC_u8Freq0HzCmd));


		HTFL_VoidClearBuffer();
#elif TFLUNA_FPS	== FPS_10HZ
		MUSART1_VoidSendChars(  LOC_u8Freq10HzCmd	,sizeof(LOC_u8Freq0HzCmd));
		HTFL_VoidClearBuffer();
#elif TFLUNA_FPS	== FPS_100HZ
		MUSART1_VoidSendChars(  LOC_u8Freq100HzCmd	,sizeof(LOC_u8Freq0HzCmd));
		HTFL_VoidClearBuffer();
#else
	#error("WRONG FPS");
#endif



		/* 6- Save Settings */

	MUSART1_VoidSendChars(  LOC_u8SaveSettingsCmd	,sizeof(LOC_u8SaveSettingsCmd));

	_delay_ms(200);


}

u16 	HTFL_u16GetDistanceCm				(	void 	)
{
	u8 LOC_u8Iterator =0;	/* Used for loop iterations */
	HTFL_VoidClearBuffer();
	u8 LOC_u8TriggerCmd[] ={0x5A ,0x04 ,0x04 ,0x00};
	u16 LOC_u16DistanceCm=0;


	/* Send Trigger CMD */
	MUSART1_VoidSendChars(  LOC_u8TriggerCmd	,sizeof(LOC_u8TriggerCmd));

	for(LOC_u8Iterator=0;LOC_u8Iterator<9;LOC_u8Iterator++ )
		DataCome[LOC_u8Iterator] = USART1_receiveByte(); /* Receive the detected Frame*/


	for (LOC_u8Iterator=0; LOC_u8Iterator <10 ;LOC_u8Iterator++)
	{
		if( DataCome[LOC_u8Iterator-1] == 0x59 && DataCome[LOC_u8Iterator] == 0x59 )
		{
			/* Get the Byte 2 , Byte 3 if the Header frame is correct */
			LOC_u16DistanceCm = ( (DataCome[LOC_u8Iterator+2] << 8) | DataCome[LOC_u8Iterator+1] ) ;
		}
	}


	return  LOC_u16DistanceCm;
}


void	HTFL_VoidClearBuffer			(	void	)
{
	u8 LOC_u8Iterator =0 ;
	iterator =0;
	
	for (LOC_u8Iterator = 0; LOC_u8Iterator < 10 ; LOC_u8Iterator++)
	{
		DataCome[LOC_u8Iterator] = 0 ;
	}
}
