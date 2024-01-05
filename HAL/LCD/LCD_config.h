/*****************************************/
/*	Author : Mohamed Abdelgawad			 */
/*	Date   : 14-11-2023  		   		 */
/*	Version: 0.1				         */
/*	File   : LCD_config.h		         */
/*****************************************/
#ifndef _LCD_CONFIG_H_
#define _LCD_CONFIG_H_

/*
#define LCD_u8_RS_PORT 		DIO_u8_PORTB
#define LCD_u8_D0_PORT      DIO_u8_PORTB
#define LCD_u8_D1_PORT      DIO_u8_PORTB
#define LCD_u8_D2_PORT      DIO_u8_PORTB
#define LCD_u8_D3_PORT      DIO_u8_PORTB
#define LCD_u8_D4_PORT      DIO_u8_PORTB
#define LCD_u8_D5_PORT      DIO_u8_PORTB
#define LCD_u8_D6_PORT      DIO_u8_PORTB
#define LCD_u8_D7_PORT      DIO_u8_PORTB


#define LCD_u8_RS_PIN 		DIO_u8_PIN0
#define LCD_u8_RW_PIN 		DIO_u8_PIN0
#define LCD_u8_E_PIN 		DIO_u8_PIN0

#define LCD_u8_D0_PIN       DIO_u8_PIN0
#define LCD_u8_D1_PIN       DIO_u8_PIN0
#define LCD_u8_D2_PIN       DIO_u8_PIN0
#define LCD_u8_D3_PIN       DIO_u8_PIN0
#define LCD_u8_D4_PIN       DIO_u8_PIN0
#define LCD_u8_D5_PIN       DIO_u8_PIN0
#define LCD_u8_D6_PIN       DIO_u8_PIN0
#define LCD_u8_D7_PIN       DIO_u8_PIN0
*/

#define LCD_U8_DATA_PORT		DIO_U8_PORTA
#define LCD_U8_CONTROL_PORT		DIO_U8_PORTB

#define LCD_U8_RS DIO_U8_PIN1
#define LCD_U8_RW DIO_U8_PIN2
#define LCD_U8_EN DIO_U8_PIN3
/*
LCD_u8_FOUR_BIT
LCD_u8_EIGHT_BIT
*/
#define LCD_u8_MODE 		LCD_u8_FOUR_BIT
#endif