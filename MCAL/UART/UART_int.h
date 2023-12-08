/************************************************/
/* Title       : USART Interface file           */
/* Author      : Mohamed Abdelgawad             */
/* Release     : 1.0                            */
/* Last Update : 11 26, 2023                   */
/************************************************/

#ifndef UART_INT_H_
#define UART_INT_H_

void UART_voidInit(void);

void UART_voidSendByte(u8 Byte);

u8 UART_u8ReceiveByte(void);

void UART_voidSendString(s8 *String);

void UART_voidRecieveString(s8 *String);

#endif /* UART_INT_H_ */
