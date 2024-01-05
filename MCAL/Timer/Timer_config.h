/************************************************/
/* Title       : Timer configuration file       */
/* Author      : Mohamed Abdelgawad              */
/* Release     : 1.0                            */
/* Last Update : 11 16, 2023                  */
/************************************************/

#ifndef _TIMER0_CONFIG_H
#define _TIMER0_CONFIG_H

//____________________TIMER0______________
/*Range
#define TIMER0_NORMAL 		
#define TIMER0_CTC 			
#define TIMER0_FAST_PWM 	
#define TIMER0_PHASE_PWM 	
*/

#define TIMER0_MODE TIMER_NORMAL

/*Range
#define TIMER0_DIV_BY_1			
#define TIMER0_DIV_BY_8			
#define TIMER0_DIV_BY_64		
#define TIMER0_DIV_BY_256		
#define TIMER0_DIV_BY_1024		
*/
#define TIMER0_PRESCALER  TIMER_DIV_BY_1024


/*Range
#define TIMER0_NO_ACTION	
#define TIMER0_TOGGLE		
#define TIMER0_SET	     //inverted 
#define TIMER0_CLEAR	// Non-inverted					
*/

#define TIMER0_COM_EVENT   TIMER_NO_ACTION


//____________________TIMER2______________
/*Range
#define TIMER2_NORMAL
#define TIMER2_CTC
#define TIMER2_FAST_PWM
#define TIMER2_PHASE_PWM
*/

#define TIMER2_MODE TIMER_NORMAL
			 
/*Range		 
#define TIMER2_DIV_BY_1
#define TIMER2_DIV_BY_8
#define TIMER2_DIV_BY_64
#define TIMER2_DIV_BY_256
#define TIMER2_DIV_BY_1024
*/			 
#define TIMER2_PRESCALER  TIMER_DIV_BY_1024
			 
			 
/*Range		 
#define TIMER2_NO_ACTION
#define TIMER2_TOGGLE
#define TIMER2_SET	     //inverted
#define TIMER2_CLEAR	// Non-inverted
*/			 
			 
#define TIMER2_COM_EVENT   TIMER_NO_ACTION


//_____________TIMER1______________

#define Timer1_IC_Noise_Canceller      Disabled
#define Timer1_IC_Edge_Select          Timer1_IC_Falling_Edge
#define Timer1_MODE                   TIMER1_NORMAL
#define Timer1_PRESCALER              TIMER_DIV_BY_1024
#define Compare_Output_Mode_A          TIMER_NO_ACTION
#define Compare_Output_Mode_B          TIMER_NO_ACTION
#endif
