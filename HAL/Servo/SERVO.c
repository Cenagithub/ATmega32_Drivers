#define F_CPU 16000000UL
#include <util/delay.h>
#include "../../MCAL/service/STD_types.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/Timer/Timer_int.h"

void Servo_Init(){
	void DIO_voidSetPinDir(PORTD,DIO_U8_PIN7,DIO_U8_OUTPUT);
	void DIO_voidSetPinVal(PORTD,DIO_U8_PIN7,DIO_U8_LOW);
}

void Servo_0_Degree_Delay(){
	
	void DIO_voidSetPinVal(PORTD,DIO_U8_PIN7,DIO_U8_HIGH);
	_delay_us(500);
	void DIO_voidSetPinVal(PORTD,DIO_U8_PIN7,DIO_U8_LOW);
	_delay_ms(19.5);
}

void Servo_90_Degree_Delay(){
	
	void DIO_voidSetPinVal(PORTD,DIO_U8_PIN7,DIO_U8_HIGH);
	_delay_us(1500);
	void DIO_voidSetPinVal(PORTD,DIO_U8_PIN7,DIO_U8_LOW);
	_delay_ms(18.5);
}
void Servo_180_Degree_Delay(){
	
	void DIO_voidSetPinVal(PORTD,DIO_U8_PIN7,DIO_U8_HIGH);
	_delay_us(2500);
	void DIO_voidSetPinVal(PORTD,DIO_U8_PIN7,DIO_U8_LOW);
	_delay_ms(17.5);
} 