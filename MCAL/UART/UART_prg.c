/************************************************/
/* Title       : USART Program file             */
/* Author      : Mohamed Abdelgawad             */
/* Release     : 1.0                            */
/* Last Update :11 26, 2023                   */
/************************************************/



#include "../service/STD_TYPES.h"
#include "../service/BIT_MATH.h"

#include "UART_int.h"
#include "UART_priv.h"
#include "UART_config.h"

void UART_voidInit(void)
{
	
	/*Choose one stop bit */
	CLEAR_BIT(UCSRC , USBS);
	
	
#if(UART_DATA_FRAME	  == DATA_5_BIT)
CLEAR_BIT(UCSRB , UCSZ2) ;
CLEAR_BIT(UCSRC , UCSZ1);
CLEAR_BIT(UCSRC , UCSZ0);
#elif(UART_DATA_FRAME == DATA_6_BIT)
CLEAR_BIT(UCSRB , UCSZ2) ;
CLEAR_BIT(UCSRC , UCSZ1);
SET_BIT(UCSRC , UCSZ0);
#elif(UART_DATA_FRAME == DATA_7_BIT)
CLEAR_BIT(UCSRB , UCSZ2) ;
SET_BIT(UCSRC , UCSZ1);
CLEAR_BIT(UCSRC , UCSZ0);
#elif(UART_DATA_FRAME == DATA_8_BIT)
CLEAR_BIT(UCSRB , UCSZ2) ;
SET_BIT(UCSRC , UCSZ1);
SET_BIT(UCSRC , UCSZ0);
#elif(UART_DATA_FRAME == DATA_9_BIT)
SET_BIT(UCSRB , UCSZ2) ;
SET_BIT(UCSRC , UCSZ1);
SET_BIT(UCSRC , UCSZ0);
#endif
	
#if(UART_MODE == ASYNCHRONOUS)
CLEAR_BIT(UCSRC , UMSEL);
#elif(UART_MODE == SYNCHRONOUS)
SET_BIT(UCSRC , UMSEL);


#endif

#if(UART_PARITY == EVEN)
SET_BIT(UCSRC,UPM1);
CLEAR_BIT(UCSRC,UPM0);

#elif(UART_PARITY == ODD)
SET_BIT(UCSRC,UPM1);
SET_BIT(UCSRC,UPM0);

#elif(UART_PARITY == DISABLE)
CLEAR_BIT(UCSRC,UPM1);
CLEAR_BIT(UCSRC,UPM0);
#endif
	
#if(UART_STOP_BIT == ONE_BIT)
CLEAR_BIT(UCSRC , USBS);
#elif(UART_STOP_BIT == TWO_BIT)
SET_BIT(UCSRC , USBS);
#endif
	
	
u16 speed = 103;
// 0b00000000 010101010
UBRRH = (speed>>8); // write zero on the last bit to choose UBRRH
UBRRL = (u8)speed;

/*Enable rx and tx*/
SET_BIT(UCSRB , RXEN) ;
SET_BIT(UCSRB , TXEN) ;
/*disable interrupt*/
// CLEAR_BIT(UCSRB , RXCIE);
// CLEAR_BIT(UCSRB , UDRIE);

}

void UART_voidSendByte(u8 Byte)
{
	while(GET_BIT(UCSRA , UDRE) == 0); // stuck here to check if flag is one to sure the UDR is empty
	UDR = Byte ;
}

void UART_voidSendString(s8 *String)
{
	u8 count = 0;
	while(String[count] != '\0')
	{
		UART_voidSendByte(String[count]);
		count++;
	}
}

void UART_voidRecieveString(s8 *String)
{
	u8 count = 0;
	while(1)
	{
		String[count] = UART_u8ReceiveByte();
		if(String[count] == '\n')
		{
			break;
		}
		else
		{
			count++;
		}
	}
}


u8 UART_u8ReceiveByte(void)
{
	while(GET_BIT(UCSRA , RXC) == 0);
	return UDR ;
}