/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 17 Oct. 2022							*/
/*	Version : V01									*/
/****************************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

	/* Write the Slave PIN in a pair PORT ,PIN */
#define 	MSPI1_SLAVE_PIN 	 GPIOA,3

#define 	MSP1_STATUS          MSPI_ENABLE				/* OPTIONS : 1- MSPI_DISABLE
																		 2- MSPI_ENABLE			 */
	
#define 	MSPI1_CLOCK_MODE     MSPI_MODE3					/* OPTIONS : 1- MSPI_MODE0
																	     2- MSPI_MODE1
																	     3- MSPI_MODE2
																	     4- MSPI_MODE3			*/
	
#define 	MSPI1_MASTER_SLAVE   MSPI_MASTER				/* OPTIONS : 1- MSPI_MASTER
																		 2- MSPI_SLAVE 			*/
	
#define 	MSPI1_PRESCALLER     MSPI_FPCLK_DIVIDED_BY_2	/* OPTIONS: MSPI_FPCLK_DIVIDED_BY_2
																		MSPI_FPCLK_DIVIDED_BY_4
																		MSPI_FPCLK_DIVIDED_BY_8
																		MSPI_FPCLK_DIVIDED_BY_16
																		MSPI_FPCLK_DIVIDED_BY_32
																		MSPI_FPCLK_DIVIDED_BY_64
																		MSPI_FPCLK_DIVIDED_BY_128
																		MSPI_FPCLK_DIVIDED_BY_256	*/
	
#define 	MSPI1_DATA_ORDER     MSPI_MSB_FIRST				/* OPTIONS : 1- MSPI_MSB_FIRST
																     	 2- MSPI_LSB_FIRST		 */
	
#define 	MSPI1_SS_MANAGE      SW_SLAVE_MANAGEMENT		/* OPTIONS : 1- HW_SLAVE_MANAGEMENT
																	 	 2- SW_SLAVE_MANAGEMENT	 */
	
#define 	MSPI1_DATA_SIZE      MSPI_8BIT_DATA				/* OPTIONS : 1- MSPI_8BIT_DATA
																	 	 2- MSPI_16BIT_DATA  	 */

	
#define 	MSPI1_INT_STATUS     MSPI_INT_DISABLE			/* OPTIONS : 1- MSPI_INT_DISABLE
																	 	 2- MSPI_TXE_INT_ENABLE
																	 	 3- MSPI_RXNE_INT_ENABLE */

#endif
