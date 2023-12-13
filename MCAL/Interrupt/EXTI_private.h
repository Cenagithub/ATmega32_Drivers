/*****************************************/
/*	Author :  Mohamed Abdelgawad		 */
/*	Date   :  	  12-11-2023    		 */
/*	Version: 0.1				         */
/*	File   : EXTI_private.h		         */
/*****************************************/


#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_


#define SREG_Reg *((volatile u8*)0x5F) 
#define MCUCR *((volatile u8*)0x55)
#define MCUCSR *((volatile u8*)0x54)
#define GICR *((volatile u8*)0x5B)
#define GIFR *((volatile u8*)0x5A)


#define	EXTI0_U8_RISING     0
#define	EXTI0_U8_FALLING    1
#define	EXTI0_U8_ANY_CHANGE 2
#define EXTI0_U8_LOW_LEVEL  3

#define	EXTI1_U8_RISING     0
#define	EXTI1_U8_FALLING    1
#define	EXTI1_U8_ANY_CHANGE 2
#define EXTI1_U8_LOW_LEVEL  3

#define	EXTI2_U8_RISING     0
#define	EXTI2_U8_FALLING    1
#define	EXTI2_U8_ANY_CHANGE 2
#define EXTI2_U8_LOW_LEVEL  3

#endif