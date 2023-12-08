/*****************************************/
/*	Author :  Mohamed Abdelgawad		 */
/*	Date   :  	  12-11-2023    		 */
/*	Version: 0.1				         */
/*	File   : EXTI_config.h		         */
/*****************************************/
#ifndef _EXTI_CONFIG_H_
#define _EXTI_CONFIG_H_


/*
options:

	EXTI0_U8_RISING
	
	EXTI0_U8_FALLING
	
	EXTI0_U8_ANY_CHANGE
	
	EXTI0_U8_LOW_LEVEL
*/

#define EXTI0_U8_ISC   EXTI0_U8_ANY_CHANGE

/*
options:

	EXTI1_U8_RISING
	
	EXTI1_U8_FALLING
	
	EXTI1_U8_ANY_CHANGE
	
	EXTI1_U8_LOW_LEVEL
*/
#define EXTI1_ISC EXTI1_U8_RISING

/*
options:

	EXTI1_U8_RISING
	
	EXTI1_U8_FALLING
	
	EXTI1_U8_ANY_CHANGE
	
	EXTI1_U8_LOW_LEVEL
*/
#define EXTI2_ISC EXTI2_U8_RISING

#endif
	
