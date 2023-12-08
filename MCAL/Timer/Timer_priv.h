/************************************************/
/* Title       : Timer Private file             */
/* Author      : Mohamed Abdelgawad             */
/* Release     : 1.0                            */
/* Last Update : 11 16, 2023                   */
/************************************************/


#ifndef _TIMER0_PRIV
#define _TIMER0_PRIV
/************ Timer 0-2 /8 BIT *******/ 
#define TIMER_NORMAL 		1
#define TIMER_CTC 			2
#define TIMER_FAST_PWM 	3
#define TIMER_PHASE_PWM 	4

#define TIMER_DIV_BY_1			1
#define TIMER_DIV_BY_8			8
#define TIMER_DIV_BY_64			64
#define TIMER_DIV_BY_256		256
#define TIMER_DIV_BY_1024		1024

#define Timer_Pre_STOP                     0
#define Timer_Pre_External_T1_Falling      6
#define Timer_Pre_External_T1_Raising      7


#define TIMER_NO_ACTION		100
#define TIMER_TOGGLE		12
#define TIMER_SET			20
#define TIMER_CLEAR			25

#define Timer1_IC_Noise_Canceller			1
#define Timer1_IC_Edge_Select				2
#define Timer1_MODE							3
#define Timer1_PRESCALER					4
#define Compare_Output_Mode_A				5
#define Compare_Output_Mode_B				6



/************ Timer 1 /16 BIT *******/ 


#define    TIMER1_NORMAL                               0
#define    TIMER1_PWM_Phase_8bit					   1
#define    TIMER1_PWM_Phase_9bit					   2
#define    TIMER1_PWM_Phase_10bit					   3
#define    TIMER1_CTC_OCR1A                            4
#define    TIMER1_Fast_PWM_8bit                        5
#define    TIMER1_Fast_PWM_9bit                        6
#define    TIMER1_Fast_PWM_10bit                       7
#define    TIMER1_PWM_Phase_Frequency_Correct_ICR1     8
#define    TIMER1_PWM_Phase_Frequency_Correct_OCR1A    9
#define    TIMER1_PWM_Phase__ICR1					   10
#define    TIMER1_PWM_Phase__OCR1A					   11
#define    TIMER1_CTC_ICR1                             12
#define    TIMER1_FastPWM_ICR1                         14
#define    TIMER1_FastPWM_OCR1A                        15

#define Enabled                      1
#define Disabled                     0

#define Timer1_IC_Raising_Edge       1
#define Timer1_IC_Falling_Edge       0

#define SREG            *((volatile u8 *)0x5F)
#define TIMSK			*((volatile u8*)0X59)
#define TIFR			*((volatile u8*)0X58)

/*Timer0*/
#define TCCR0			*((volatile u8*)0X53)
#define TCNT0			*((volatile u8*)0X52)
#define OCR0			*((volatile u8*)0X5C)

/*Timer1*/
#define TCCR1A			*((volatile u8*)0X4F)
#define TCCR1B			*((volatile u8*)0X4E)
#define TCNT1H          *((volatile u8 *)(0x4D))
#define TCNT1L          *((volatile u8 *)(0x4C))
#define TCNT1			*((volatile u16*)0X4C)    /* u16 for HIGH & LOW */
#define OCR1AL          *((volatile u8 *)(0x4A))
#define OCR1AH          *((volatile u8 *)(0x4B))
#define OCR1A			*((volatile u16*)0X4A)
#define OCR1BL          *((volatile u8 *)(0x48))
#define OCR1BH          *((volatile u8 *)(0x49))
#define OCR1B			*((volatile u16*)0X48)
#define ICR1H           *((volatile u8 *)(0x47))
#define ICR1L           *((volatile u8 *)(0x46))
#define ICR1			*((volatile u16*)0X46)

/*Timer2*/

#define TCCR2			*((volatile u8*)0X45)
#define TCNT2			*((volatile u8*)0X44)
#define TCNT2			*((volatile u8*)0X44)
#define OCR2			*((volatile u8*)0X43)

#define WDTCR        *((volatile u8 *)(0x41))

#endif
