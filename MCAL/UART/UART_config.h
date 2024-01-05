/************************************************/
/* Title       : USART configuration file       */
/* Author      : Mohamed Abdelgawad             */
/* Release     : 1.0                            */
/* Last Update : 11 26, 2023                   */
/************************************************/

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/* UART Data frame
	5-BIT
	6-BIT
	7-BIT
	8-BIT
	9-BIT
*/
#define UART_DATA_FRAME	   DATA_9_BIT


 /* UART Mode
 
 Asynchronous
 Synchronous

*/
 
 #define UART_MODE		ASYNCHRONOUS
 
 /* UART parity bit
	
	Even	
	Odd
	DISABLE
*/
 
 #define UART_PARITY	EVEN
 
 
 
 /* UART stop bit
	
	1-bit
	2-bit
*/ 
 
#define UART_STOP_BIT	ONE_BIT

 

#endif /* UART_CONFIG_H_ */
