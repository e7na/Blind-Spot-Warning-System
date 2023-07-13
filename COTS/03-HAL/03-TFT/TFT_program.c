/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 18 Oct. 2022							*/
/*	Version : V01									*/
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

void HTFT_voidInit(void)
{
	/* GPIO slave pin init */
	MGPIO_voidSetPinDirection(TFT_SLAVE_PIN ,OUTPUT_SPEED_10MHZ_PUSH_PULL);
		/* Reset Pulse */
	MGPIO_voidSetPinValue(TFT_RST_PIN ,GPIO_HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN ,GPIO_LOW);
	MSTK_voidSetBusyWait(2);
	MGPIO_voidSetPinValue(TFT_RST_PIN ,GPIO_HIGH);
	MSTK_voidSetBusyWait(100);	
	MGPIO_voidSetPinValue(TFT_RST_PIN ,GPIO_LOW);
	MSTK_voidSetBusyWait(100);	
	MGPIO_voidSetPinValue(TFT_RST_PIN ,GPIO_HIGH);
	MSTK_voidSetBusyWait(120000);
	
		/* Sleep Out Command */
	voidWriteCommand(0x11);
	
		/* Wait 150 msec*/
	MSTK_voidSetBusyWait(150000);
	
		/* Color Mode Command */
	voidWriteCommand(0x3A);
	voidWriteData	(0x05);
	
		/* Display On Command */
	voidWriteCommand(0x29);	
	

}
void HTFT_voidDisplayImage(const u16* Copy_Image)
{
	u16 counter ;
	
		/* Set X Address */
	voidWriteCommand(0x2A);
		/* Start X Point*/
	voidWriteData(0);
	voidWriteData(0);
		/* End X Point */
	voidWriteData(0);
	voidWriteData(127);

		/* Set Y Address */
	voidWriteCommand(0x2B);
		/* Start Y Point*/
	voidWriteData(0);
	voidWriteData(0);
		/* End Y Point */
	voidWriteData(0);
	voidWriteData(159);
	
		/* RAM Write */
	voidWriteCommand(0x2C);
	
	for(counter = 0; counter <20480 ; counter++ )
	{
			/* Write the High Byte for One Pixle */
		voidWriteData( Copy_Image[counter] >> 8     );
			/* Write the Low Byte for One Pixle */
		voidWriteData( Copy_Image[counter] & 0x00ff );
	}
}


static void voidWriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Temp;
	
		/* Set A0 Pin to Low */
	MGPIO_voidSetPinValue(TFT_A0_PIN ,GPIO_LOW);
	
	/* Set CS Pin to Low */
	MGPIO_voidSetPinValue(TFT_SLAVE_PIN ,GPIO_LOW);
		/* Send Command Over SPI */
	MSPI1_voidSendReceiveSynch(Copy_u8Command , &Local_u8Temp);
	/* Set CS Pin to HIGH */
	MGPIO_voidSetPinValue(TFT_SLAVE_PIN ,GPIO_HIGH);
}


static void voidWriteData(u8 Copy_u8Data)
{
	u8 Local_u8Temp;
		/* Set A0 Pin to High */
	MGPIO_voidSetPinValue(TFT_A0_PIN ,GPIO_HIGH);
		
		/* Set CS Pin to Low */
	MGPIO_voidSetPinValue(TFT_SLAVE_PIN ,GPIO_LOW);
		/* Send Data Over SPI */
	MSPI1_voidSendReceiveSynch(Copy_u8Data , &Local_u8Temp);
		/* Set CS Pin to HIGH */
	MGPIO_voidSetPinValue(TFT_SLAVE_PIN ,GPIO_HIGH);
}




void TFT_voidDrawRectangle (u16 copy_u16X ,u16 copy_u16Y , u16 copy_u16Width , u16 copy_u16Hight , u16 copy_u16Color ){
	u16 loacal_u16EndX = copy_u16X + copy_u16Width - 1;
	u16 loacal_u16EndY = copy_u16Y + copy_u16Hight - 1;

	/* Set area of addresses */
	voidSetAddress(copy_u16X ,loacal_u16EndX,copy_u16Y ,loacal_u16EndY );

	/* Draw the Rectangle*/
	for (u16 i = 0 ; i < (copy_u16Width *copy_u16Hight ) ; i++){
		voidSetColour(copy_u16Color);
	}
}


void TFT_voidFillDisplay (u16 copy_u16Colour){
	TFT_voidDrawRectangle(0 , 0 ,TFT_MAX_X , TFT_MAX_Y , copy_u16Colour);
}

void TFT_voidPrintChar(s8 copy_s8Char , u16 copy_u16X , u16 copy_u16Y, u8 copy_u8Size , u16 copy_u16Color , u16 copy_u16BackColor)
{
	/* Get array index */
	u8 local_u8CharIndex = 0 ;
	if (( copy_s8Char >= ' ' )){
		local_u8CharIndex = copy_s8Char - 32 ;
	}

	/* Background */
	TFT_voidDrawRectangle( copy_u16X, copy_u16Y ,copy_u8Size*TFT_CHARACTER_WIDTH ,copy_u8Size*TFT_CHARACTER_HIGHT ,copy_u16BackColor);

	for (u8 i = 0; i <TFT_CHARACTER_WIDTH ; i++ ){
		for (u8 j = 0 ; j <TFT_CHARACTER_HIGHT ; j++){
			if (TFT_font[local_u8CharIndex][i] & (1 << j)){
				if (copy_u8Size == 1){
					voidDrawPixel(copy_u16X+i , copy_u16Y+j , copy_u16Color);
				}
				else {
					u16 local_x = copy_u16X+(i*copy_u8Size) ;
					u16 local_y = copy_u16Y+(j*copy_u8Size) ;
					TFT_voidDrawRectangle( local_x, local_y ,copy_u8Size ,copy_u8Size ,copy_u16Color);
				}
			}
		}
	}
}


void TFT_voidPrintText(s8 *copy_s8Text , u16 copy_u16X , u16 copy_u16Y, u8 copy_u8Size , u16 copy_u16Color, u16 copy_u16BackColor)
{
	while (*copy_s8Text){
		TFT_voidPrintChar(*copy_s8Text , copy_u16X ,copy_u16Y ,copy_u8Size ,copy_u16Color,copy_u16BackColor );
		copy_u16X += (copy_u8Size *TFT_CHARACTER_WIDTH)  ;
		copy_s8Text++;
	}
}



static void voidDrawPixel (u16 copy_u16X , u16 copy_u16Y , u16 copy_u16Colour)
{
	if ( (copy_u16X < TFT_MAX_X ) && (copy_u16Y < TFT_MAX_Y )){

		/* Set address of the pixel */
		voidSetAddress(copy_u16X  , copy_u16X+1 , copy_u16Y , copy_u16Y+1);

		/* Write pixel colour */
		voidSetColour(copy_u16Colour);
	}
}



static void voidSetAddress (u16 copy_u16StartX ,u16 copy_u16EndX , u16 copy_u16StartY , u16 copy_u16EndY)
{
	if ( (copy_u16StartX < TFT_MAX_X ) && (copy_u16StartY < TFT_MAX_Y )){
		/* Set x Address */
		voidWriteCommand(0x2A);
		/* Start byte */
		voidWriteData((copy_u16StartX >> 8));  // MS byte
		voidWriteData(copy_u16StartX);

		/* Stop byte */
		voidWriteData((copy_u16EndX >> 8));
		voidWriteData(copy_u16EndX);

		/* Set x Address */
		voidWriteCommand(0x2B);
		/* Start byte */
		voidWriteData((copy_u16StartY >> 8));  // MS byte
		voidWriteData(copy_u16StartY);
		/* Stop byte */
		voidWriteData((copy_u16EndY >> 8));
		voidWriteData(copy_u16EndY);

		/* RAM write */
		voidWriteCommand(0x2C);
	}
}

static void voidSetColour(u16 copy_u16Colour)
{

	/* Write pixel */
	u8 high_byte = (copy_u16Colour >> 8);
	u8 low_byte = (copy_u16Colour & 0xff);
	voidWriteData(high_byte);
	voidWriteData(low_byte);
}
