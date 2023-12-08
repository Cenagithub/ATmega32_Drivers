#include "../../MCAL/service/STD_types.h"
#include "../../MCAL/DIO/DIO_int.h"

void LED0_Init(){
	DIO_voidSetPinDir(DIO_U8_PORTC,2,DIO_U8_OUTPUT);
	}
void LED1_Init(){
	DIO_voidSetPinDir(DIO_U8_PORTC,7,DIO_U8_OUTPUT);
	}
void LED2_Init(){
	DIO_voidSetPinDir(DIO_U8_PORTD,3,DIO_U8_OUTPUT);
	}

void LED0_On(){
	DIO_voidSetPinVal(DIO_U8_PORTC,2,DIO_U8_HIGH);
}

void LED1_On(){
	DIO_voidSetPinVal(DIO_U8_PORTC,7,DIO_U8_HIGH);
}

void LED2_On(){
	DIO_voidSetPinVal(DIO_U8_PORTD,3,DIO_U8_HIGH);
}

void LED2_Off(){
	DIO_voidSetPinVal(DIO_U8_PORTD,3,DIO_U8_LOW);
}

void LED0_Off(){
	DIO_voidSetPinVal(DIO_U8_PORTC,2,DIO_U8_LOW);
}

void LED1_Off(){
	DIO_voidSetPinVal(DIO_U8_PORTC,7,DIO_U8_LOW);
}