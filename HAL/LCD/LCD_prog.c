/*****************************************/
/*	Author : Mohamed Abdelgawad			 */
/*	Date   : 14-11-2023  		   		 */
/*	Version: 0.1				         */
/*	File   : LCD_prog.c		             */
/*****************************************/

#define  F_CPU 16000000UL
#include "../../MCAL/service/STD_types.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "LCD_int.h"
#include "LCD_private.h"
#include "LCD_config.h"
#include <util/delay.h>


void LCD_voidInit(void)
{
	DIO_voidSetPinDir(LCD_U8_DATA_PORT, DIO_U8_PIN4 ,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(LCD_U8_DATA_PORT, DIO_U8_PIN5 ,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(LCD_U8_DATA_PORT, DIO_U8_PIN6 ,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(LCD_U8_DATA_PORT, DIO_U8_PIN7 ,DIO_U8_OUTPUT);
	
	DIO_voidSetPinDir(LCD_U8_CONTROL_PORT, LCD_U8_RS ,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(LCD_U8_CONTROL_PORT, LCD_U8_RW ,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_OUTPUT);
	
	_delay_ms(35);
	LCD_voidSendCommand(0x33);
	_delay_ms(2);
	LCD_voidSendCommand(0x32);
	_delay_ms(2);
	LCD_voidSendCommand(0x28);
	_delay_ms(2);
	LCD_voidSendCommand(0x0c);
	_delay_ms(2);
	LCD_voidSendCommand(0x06);
	_delay_ms(2);
	LCD_voidSendCommand(0x01);
	_delay_ms(2);
}
void LCD_voidSendData(u8 LCD_u8_Data)
{
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_RS ,DIO_U8_HIGH);
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_RW ,DIO_U8_LOW);
	
	DIO_voidSetPortVal(LCD_U8_DATA_PORT , LCD_u8_Data);
	
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_LOW);
	_delay_ms(1);
	
	DIO_voidSetPortVal(LCD_U8_DATA_PORT , LCD_u8_Data << 4);
	
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_LOW);
	_delay_ms(1);
}

void LCD_voidSendCommand(u8 LCD_u8_Command)
{
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_RS ,DIO_U8_LOW);
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_RW ,DIO_U8_LOW);
	
	DIO_voidSetPortVal(LCD_U8_DATA_PORT , LCD_u8_Command);
	
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_LOW);
	_delay_ms(1);
	
	DIO_voidSetPortVal(LCD_U8_DATA_PORT , LCD_u8_Command << 4);
	
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_LOW);
	_delay_ms(1);
}

void LCD_voidSendString(s8 Local_u8String[])
{
	u8 i = 0;
	while(Local_u8String[i] != '\0')
	{
		LCD_voidSendData(Local_u8String[i]);
		i++;
	}
}

void LCD_voidClearLCD(void)
{
	LCD_voidSendCommand(0b00000001);
}

