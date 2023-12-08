/************************************************/
/* Title       : USART Private file             */
/* Author      : Mohamed Abdelgawad             */
/* Release     : 1.0                            */
/* Last Update : 11 26, 2023                   */
/************************************************/

#ifndef UART_PRIV_H_
#define UART_PRIV_H_

#define UDR   (* (  volatile u8 * ) 0x2C ) // on the fly pointer
#define UCSRA (* (  volatile u8 * ) 0x2B )
#define UCSRB (* (  volatile u8 * ) 0x2A )
#define UCSRC (* (  volatile u8 * ) 0x40 )
#define UBRRH (* (  volatile u8 * ) 0x40 )
#define UBRRL (* (  volatile u8 * ) 0x29 )

#define RXC 	7
#define TXC 	6
#define UDRE 	5
#define FE 		4
#define DOR 	3
#define PE 		2
#define U2X 	1
#define MPCM 	0

#define RXCIE 	7
#define TXCIE 	6
#define UDRIE 	5
#define RXEN 	4
#define TXEN 	3
#define UCSZ2 	2
#define RXB8 	1
#define TXB8 	0

#define URSEL 	7
#define UMSEL 	6
#define UPM1 	5
#define UPM0 	4
#define USBS 	3
#define UCSZ1 	2
#define UCSZ0 	1
#define UCPOL 	0


#define DATA_5_BIT 0
#define DATA_6_BIT 1
#define DATA_7_BIT 2
#define DATA_8_BIT 3
#define DATA_9_BIT 4

#define ASYNCHRONOUS 0
#define SYNCHRONOUS  1

#define EVEN 0
#define ODD  1
#define DISABLE 2

#define ONE_BIT 0 
#define TWO_BIT 1




#endif /* UART_PRIV_H_ */
