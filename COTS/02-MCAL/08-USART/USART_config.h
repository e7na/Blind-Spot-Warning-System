/****************************************************/
/*	Author  : Essam								    */
/*	Date	: 24 April 2023							*/
/*	Version : V02									*/
/****************************************************/
#ifndef USART_CONFIG_H
#define USART_CONFIG_H

#define F_CPU					8000000UL

#define USART1_STATUS            UART1_ENABLE		/* Options :  UART1_DISABLE
															      URT1_ENABLE	   	   	   */

#define USART1_BAUD_RATE         (u32)115200			/* Select BAUD RATE: ex. 9600 , 115200 */


#define USART1_WORD_LENGTH       _8BIT_WORD_LENGTH	/* Options :  _8BIT_WORD_LENGTH	
															      _9BIT_WORD_LENGTH	 		*/
																		
#define USART1_PARITY            PARITY_DISABLE		/* Options :  EVEN_PARITY		
															      ODD_PARITY		
																  PARITY_DISABLE	 		*/
																  
#define USART1_INTERRUPT         INT_DISABLE			/* Options :  INT_DISABLE
																  TXE_INT_ENABLE
																  TCE_INT_ENABLE 
																  RXNE_INT_ENABLE	  		*/

#define USART1_TRANSMITTER       TRANSMITTER_ENABLE	/* Options :  TRANSMITTER_ENABLE
															      TRANSMITTER_DISABLE 		*/
																	
#define USART1_RECEIVER          RECEIVER_ENABLE	/* Options :  RECEIVER_ENABLE	
															      RECEIVER_DISABLE			*/
	
#define USART1_STOP_BITS         ONE_STOP_BIT 		/* Options :  ONE_STOP_BIT	
															      HALF_STOP_BIT
																  TWO_STOP_BIT 
																  ONE_AND_HALF_STOP_BIT	 	 */
																  

#endif
