/*****************************************/
/*	Author :  Mohamed Abdelgawad		 */
/*	Date   :  	  12-11-2023    		 */
/*	Version: 0.1				         */
/*	File   : EXTI_prog.c	             */
/*****************************************/
#include "../service/STD_types.h"
#include "../service/BIT_MATH.h"
#include "../DIO/DIO_int.h"
#include "EXTI_int.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


/***********      Interrupt 0     ***********/
void EXTI0_voidInit(void)
{
	#if EXTI0_U8_ISC == EXTI0_U8_LOW_LEVEL
	CLEAR_BIT(MCUCR,0);
	CLEAR_BIT(MCUCR,1);
	#elif EXTI0_U8_ISC == EXTI0_U8_RISING
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);	
	#elif EXTI0_U8_ISC == EXTI0_U8_FALLING
	CLEAR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);	
	#elif EXTI0_U8_ISC == EXTI0_U8_ANY_CHANGE
	SET_BIT(MCUCR,0);
	CLEAR_BIT(MCUCR,1);	
	#endif
}
void EXTI0_voidEnable(void)
{
	SET_BIT(GICR , 6); // PIE 0
}
void EXTI0_voidDisable(void)
{
	CLEAR_BIT(GICR , 6);
}

void EXTI0_voidSetPull_Up(void){
	
	DIO_voidSetPinVal(DIO_U8_PORTD,2,DIO_U8_HIGH);
	
}

void EXTI0_voidSetDir(void){
	
	DIO_voidSetPinDir(DIO_U8_PORTD,2,DIO_U8_INPUT);
}
	/***********      Interrupt 1     ***********/
void EXTI1_voidInit(void)
{
	#if EXTI0_U8_ISC == EXTI0_U8_LOW_LEVEL
	CLEAR_BIT(MCUCR,2);
	CLEAR_BIT(MCUCR,3);
	#elif EXTI0_U8_ISC == EXTI0_U8_RISING
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	#elif EXTI0_U8_ISC == EXTI0_U8_FALLING
	CLEAR_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	#elif EXTI0_U8_ISC == EXTI0_U8_ANY_CHANGE
	SET_BIT(MCUCR,2);
	CLEAR_BIT(MCUCR,3);
	#endif
}
void EXTI1_voidEnable(void)
{
	SET_BIT(GICR , 7); // PIE 0
}
void EXTI1_voidDisable(void)
{
	CLEAR_BIT(GICR , 7);
}

void EXTI1_voidSetPull_Up(void){
	
	DIO_voidSetPinVal(DIO_U8_PORTD,2,DIO_U8_HIGH);
	
}

void EXTI1_voidSetDir(void){
	
	DIO_voidSetPinDir(DIO_U8_PORTD,2,DIO_U8_INPUT);
}
	/***********      Interrupt 2     ***********/
void EXTI2_voidInit(void)
{
	
	#if EXTI0_U8_ISC == EXTI0_U8_RISING
	CLEAR_BIT(MCUCSR,6);
	#elif EXTI0_U8_ISC == EXTI0_U8_FALLING
	SET_BIT(MCUCSR,6);
	#endif
}
void EXTI2_voidEnable(void)
{
	SET_BIT(GICR , 5); // PIE 0
}
void EXTI2_voidDisable(void)
{
	CLEAR_BIT(GICR , 5);
}

void EXTI2_voidSetPull_Up(void){
	
	DIO_voidSetPinVal(DIO_U8_PORTD,2,DIO_U8_HIGH);
	
}

void EXTI2_voidSetDir(void){
	
	DIO_voidSetPinDir(DIO_U8_PORTD,2,DIO_U8_INPUT);
}