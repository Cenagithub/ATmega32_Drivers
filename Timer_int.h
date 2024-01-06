/************************************************/
/* Title       : Timer interface file           */
/* Author      : Mohamed Abdelgawad             */
/* Release     : 1.0                            */
/* Last Update : 11 16, 2023                   */
/************************************************/

#ifndef _TIMER0_INT_H
#define _TIMER0_INT_H


void TIMER0_void_Init(void);

void TIMER0_void_SetTimerReg(u8 Copy_u8Val);

void TIMER0_void_SetCompareVal(u8 Copy_u8Val);

void TIMER0_void_EnableOVInt(void);

void TIMER0_void_DisableOVInt(void);

void TIMER0_void_EnableCTCInt(void);

void TIMER0_void_DisableCTCInt(void);


/***********************************************************************************/


void TIMER2_void_Init(void);
		  
void TIMER2_void_SetTimerReg(u8 Copy_u8Val);
		  
void TIMER2_void_SetCompareVal(u8 Copy_u8Val);
		  
void TIMER2_void_EnableOVInt(void);
		  
void TIMER2_void_DisableOVInt(void);
		  
void TIMER2_void_EnableCTCInt(void);
		  
void TIMER2_void_DisableCTCInt(void);
/***********************************************************************************/

void TIMER1_void_Init();
void TIMER1_void_ICU();
void TIMER1_void_ICU();



#endif