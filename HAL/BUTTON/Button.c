
#define F_CPU 16000000UL
#include <util/delay.h>
#include "../../MCAL/service/STD_types.h"
#include "../../MCAL/DIO/DIO_int.h"


void Button_Init(){
	DIO_voidSetPinDir(DIO_U8_PORTD,2,DIO_U8_INPUT);
	DIO_voidSetPinDir(DIO_U8_PORTD,6,DIO_U8_INPUT);
	DIO_voidSetPinDir(DIO_U8_PORTB,0,DIO_U8_INPUT);
}
void Check_Button0_Clicked(u8 * button0_State){
	switch(*button0_State){
		case 0:
			if(DIO_u8GetPinVal(DIO_U8_PORTD,2)){
				_delay_ms(20);
				if(DIO_u8GetPinVal(DIO_U8_PORTD,2)) *button0_State = 1;
			}
			break;
		case 1:	
			if(!(DIO_u8GetPinVal(DIO_U8_PORTD,2)))
			*button0_State = 10;
			break;
		default:break;
	}
}

void Check_Button1_Clicked(u8 * button1_State){
	switch(*button1_State){
		case 0:
		if(DIO_u8GetPinVal(DIO_U8_PORTD,6)){
			_delay_ms(20);
			if(DIO_u8GetPinVal(DIO_U8_PORTD,6)) *button1_State = 1;
		}
		break;
		case 1:
		if(!(DIO_u8GetPinVal(DIO_U8_PORTD,6)))
		*button1_State = 10 ;
		break;
		default:break;
	}
}

void Check_Button2_Clicked(u8 * button2_State){
	switch(*button2_State){
		case 0:
		if(DIO_u8GetPinVal(DIO_U8_PORTB,0)){
			_delay_ms(20);
			if(DIO_u8GetPinVal(DIO_U8_PORTB,0)) *button2_State = 1;
		}
		break;
		case 1:
		if(!(DIO_u8GetPinVal(DIO_U8_PORTB,0)))
		*button2_State = 10 ;
		break;
		default:break;
	}
}