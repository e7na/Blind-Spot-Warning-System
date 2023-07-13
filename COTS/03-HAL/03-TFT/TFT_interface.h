/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 18 Oct. 2022							*/
/*	Version : V01									*/
/****************************************************/
#ifndef	TFT_INTERFACE_H
#define TFT_INTERFACE_H





/* Colours */
#define     TFT_BLACK        0x0000
#define     TFT_WHITE        0xffff
#define     TFT_RED          0xf800
#define     TFT_BLUE         0x39df
#define     TFT_YELLOW       0xffc0
#define     TFT_ORANGE       0xfd20
#define     TFT_PURPLE       0xf1df
#define     TFT_GREEN        0x1427

/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	HTFT_voidInit
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	none, none
   Return			 	:	void
   Function Description :	Initialize TFT LCD
*/
void HTFT_voidInit(void);
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	HTFT_voidDisplayImage
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	Const u16*(const array of u16)/ none
   Return			 	:	void
   Function Description :	Display image in TFT screen
*/
void HTFT_voidDisplayImage(const u16* Copy_Image);
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	TFT_voidDrawRectangle
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	u16(x_axis),u16(y_axis),u16(width),u16(height),u16(color)/ none
   Return			 	:	void
   Function Description :	Draw Line ,Square or Rectangle in TFT screen
*/

void TFT_voidDrawRectangle (u16 copy_u16X ,u16 copy_u16Y , u16 copy_u16Width , u16 copy_u16Hight , u16 copy_u16Color );
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	TFT_voidFillDisplay
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	u16(fillColor)/none
   Return			 	:	void
   Function Description :	Fill the entire TFT screen with the input color
*/
void TFT_voidFillDisplay (u16 copy_u16Colour);
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	TFT_voidPrintChar
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	s8(charecter),u16(x_axis),u16(y_axis),u8(charSize),u16(charColor),u16(backColor)/ none
   Return			 	:	Void
   Function Description :	Draw a Character on TFT screen
*/
void TFT_voidPrintChar(s8 copy_s8Char , u16 copy_u16X , u16 copy_u16Y, u8 copy_u8Size , u16 copy_u16Color, u16 copy_u16BackColor);
/*==============================================================================================================*/

/*==============================================================================================================*/
/*
   Function Name     	:	TFT_voidPrintText
   Characteristics   	:	Non-Reentrant ,Synchronous
   Parameters In/out 	:	Ptrtos8(arr of charecter),u16(x_axis),u16(y_axis),u8(charSize),u16(charColor),u16(backColor)/ none
   Return			 	:	void
   Function Description :	Print Text on TFT screen
*/
void TFT_voidPrintText(s8 *copy_s8Text , u16 copy_u16X , u16 copy_u16Y, u8 copy_u8Size , u16 copy_u16Color, u16 copy_u16BackColor);

/*==============================================================================================================*/

#endif
