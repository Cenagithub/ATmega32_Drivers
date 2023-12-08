/*
 * before_ADC.c
 *
 * Created: 11/24/2023 8:42:02 AM
 *  Author: cena
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include "../MCAL/service/STD_types.h"
#include "../MCAL/service/BIT_math.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../MCAL/ADC/ADC_config.h"
#include "../MCAL/Interrupt/EXTI_int.h"
#include "../MCAL/Timer/Timer_int.h"

#include "../HAL/SevenSegment/SSEG_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/KEYPAD/KEYPAD_int.h"
#include "../HAL/BUTTON/Button.h"
#include "../HAL/LED/LED.h"





void Task6_Password_Checker()
{
	LCD_voidInit();
	KEYPAD_voidInit();
	u8 x='\0';
	u8 registered_username[4] = "1234";
	u8 registered_password[4] = "5432";
	while(1)
	{
		u8 username[6] = "";
		u8 password[6] = "";
		u8 username_counter = 0;
		u8 password_counter = 0;
		u8 username_check = 0;
		u8 password_check = 0;
		LCD_voidSendString("User:");
		while(username_counter <= 6)
		{
			x='\0';
			x = KEYPAD_u8GetButton();
			if(x == '\0') continue;

			
			if(x >= '0' && x <='9')
			{
				LCD_voidSendData(x);
				username[username_counter] = x;
				username_counter++;
			}
			else if(x == '*' && username_counter > 0)
			{
				
				username[username_counter] = '\0';
				username_counter--;
			}
			else if(x >= 'A' && x <='D')
			{
				for(int i=0;i<username_counter;i++){
					if(username[i] == registered_username[i])
					continue;
					else username_check = 1;
				}
				break;
			}
			if(username_counter > 5)
			{
				username_check = 1;break;
			}
		}
		
		LCD_voidClearLCD();
		if(username_check == 1)
		{
			LCD_voidSendString("Wrong User");
			_delay_ms(3000);
			L();
		}
		else if(username_check == 0)
		{
			LCD_voidSendString("Correct User");
			_delay_ms(3000);
			LCD_voidClearLCD();
			LCD_voidSendString("Password:");
			while(password_counter <= 6)
			{
				x='\0';
				x = KEYPAD_u8GetButton();
				if(x == '\0') continue;
				_delay_ms(50);
				if(x >= '0' && x <='9')
				{
					LCD_voidSendData(x);
					password[password_counter] = x;
					password_counter++;
				}
				else if(x == '*' && password_counter >0)
				{
					
					password[password_counter] = '\0';
					password_counter--;
				}
				else if(password_counter > 0 && x >= 'A' && x <='D')
				{
					for(int i = 0;i<password_counter;i++){
						if(password[i] == registered_password[i])
						continue;
						else password_check = 1;
					}
					break;
				}
				if(password_counter >4)
				{
					password_check = 1;break;
				}
			}
			LCD_voidClearLCD();
			if(password_check == 1)
			{
				LCD_voidSendData("Wrong Password");
				_delay_ms(3000);
				LCD_voidClearLCD();
			}
			else if(password_check == 0)
			{
				LCD_voidSendData("Correct Password");
				_delay_ms(3000);
				LCD_voidSendData("Welcome 1234");
				_delay_ms(3000);
				LCD_voidClearLCD();
			}
		}
	}
}

void Task5_Keypad_With_LCD() 
{
	u8 button;
	
	LCD_voidInit();
	KEYPAD_voidInit();
	
	
	
	while (1)
	{
		
		button = KEYPAD_u8GetButton();
		
		if(button != '\0')
		{
			LCD_voidSendData(button);
			while(KEYPAD_u8GetButton() != '\0');
			
		}
	}
}

void Task4_Traffic_Light()
{
	///TASK4: 3 led Traffic ,7seg number red 10s yelDIO_U8_LOW 10s green 10s
	LED0_Init();
	LED1_Init();
	LED2_Init();
	SSEG_voidInit();
	u8 count = 9,color = 1;
	
	DIO_voidSetPinVal(DIO_U8_PORTC,2,DIO_U8_LOW);
	DIO_voidSetPinVal(DIO_U8_PORTC,7,DIO_U8_LOW);
	DIO_voidSetPinVal(DIO_U8_PORTD,3,DIO_U8_HIGH);
	while(1){
		if(count==0){
			SSEG_voidDisplay(1,count);
			_delay_ms(1000);
			count = 9;
			switch(color){
				case 1:
					color++;
					DIO_voidSetPinVal(DIO_U8_PORTC,2,DIO_U8_HIGH);
					DIO_voidSetPinVal(DIO_U8_PORTC,7,DIO_U8_LOW);
					DIO_voidSetPinVal(DIO_U8_PORTD,3,DIO_U8_LOW);
					break;
				case 2:
					color++;
					DIO_voidSetPinVal(DIO_U8_PORTC,2,DIO_U8_LOW);
					DIO_voidSetPinVal(DIO_U8_PORTC,7,DIO_U8_HIGH);
					DIO_voidSetPinVal(DIO_U8_PORTD,3,DIO_U8_LOW);
					break;
				case 3:
					color++;
					DIO_voidSetPinVal(DIO_U8_PORTC,2,DIO_U8_LOW);
					DIO_voidSetPinVal(DIO_U8_PORTC,7,DIO_U8_LOW);
					DIO_voidSetPinVal(DIO_U8_PORTD,3,DIO_U8_HIGH);
					break;
				case 4:
					color = 1;
					break;
					
				default:break;
			}
		}
		while(count>0){
			SSEG_voidDisplay(1,count);
			_delay_ms(1000);
			count--;
		}
	}
}

void Task3_SevenSegment_with_Keypad()
{
	SSEG_voidInit();
	SSEG_voidDisplay(0,0);
	SSEG_voidDisplay(1,0);
	u8 x ='\0';
	while(1){
		x = KEYPAD_u8GetButton();
		_delay_ms(50);
		if((x > 47) && (x < 58)){
			SSEG_voidDisplay(1, (x - 48));
		}
	}
}

void Task2_SevenSegment_with_3Buttons()
{
	
	SSEG_voidInit();
	Button_Init();
	u8 button0_State =0;
	u8 button1_State =0;
	u8 button2_State =0;
	u8 count=0;
	SSEG_voidDisplay(1,0);
	while(1)
	{
		SSEG_voidDisplay(1,count);
		Check_Button0_Clicked(& button0_State);
		Check_Button1_Clicked(& button1_State);
		Check_Button2_Clicked(& button2_State);
		if((button0_State == 10)){///Increase Button Pressed
			if(count<=9)count++;
			button0_State = 0;
		}
		if((button1_State == 10)){ ///Decrease Button Pressed
			if(count > 0) count--;
			button1_State = 0;
		}
		if((button2_State == 10)){///Reset Button Pressed
			if(count > 0) count = 0;
			button2_State = 0;
		}
	}
}

void Task1_SevenSegment_Timer()
{
	
	int i = 0;
	SSEG_voidInit();
	while(1)
	{
		if(i<=9)
		{
			SSEG_voidDisplay(1,i);
			_delay_ms(1000);
			i++;
		}
		else if (i>9)
		{
			i=0;
		}
	}
}