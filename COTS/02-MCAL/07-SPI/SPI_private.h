/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 17 Oct. 2022							*/
/*	Version : V01									*/
/****************************************************/
#ifndef SPI_PRIAVTE_H
#define SPI_PRIAVTE_H	


typedef struct
{
	volatile u32 CR1	;
	volatile u32 CR2	;
	volatile u32 SR 	;
	volatile u32 DR 	;
	volatile u32 CRCPR  ;
	volatile u32 RXCRCR	;
	volatile u32 TXCRCR ;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR	;
}SPI_t;

#define		MSPI1		((SPI_t*) 	0x40013000) /* Pointer to struct */

#endif