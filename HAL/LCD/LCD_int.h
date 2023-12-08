/*****************************************/
/*  Author : Mohamed Abdelgawad			 */
/*	Date   : 14-11-2023   		   		 */
/*	Version: 0.1				         */
/*	File   : LCD_int.h		             */
/*****************************************/

#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_
#include "../../MCAL/service/STD_types.h"
void LCD_voidInit(void);
void LCD_voidSendData(u8 LCD_u8_Data);
void LCD_voidSendCommand(u8 LCD_u8_Command);
void LCD_voidSendString(s8 Local_u8String[]);
void LCD_voidClearLCD(void);

#endif