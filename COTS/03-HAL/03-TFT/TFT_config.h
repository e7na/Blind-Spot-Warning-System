/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 18 Oct. 2022							*/
/*	Version : V01									*/
/****************************************************/
#ifndef TFT_CONFIG_H
#define TFT_CONFIG_H

	/* Write pin in a pair PORT,PIN */
#define 	TFT_A0_PIN 		GPIOA,PIN1

	/* Write pin in a pair PORT,PIN */
#define 	TFT_RST_PIN 	GPIOA,PIN2 

/* Write pin in pair port,pin */
#define    TFT_SLAVE_PIN   GPIOA,3   // slave select pin

/* Configure TFT size */
#define    TFT_MAX_X       127
#define    TFT_MAX_Y       159


#endif
