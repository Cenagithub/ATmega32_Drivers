/************************************************/
/* Title       : Timer program file             */
/* Author      : Mohamed Abdelgawad              */
/* Release     : 1.0                            */
/* Last Update : 11 16, 2023                   */
/************************************************/

#include "../service/STD_TYPES.h"
#include "../service/BIT_MATH.h"
#include "Timer_int.h"
#include "Timer_priv.h"
#include "Timer_config.h"
/********************************    Timer 0    ************************************/
void TIMER0_void_Init(void)
{
	#if(TIMER0_MODE == TIMER_NORMAL)
		CLEAR_BIT(TCCR0 , 6);
		CLEAR_BIT(TCCR0 , 3);
	
	#elif(TIMER0_MODE == TIMER_CTC)
		CLEAR_BIT(TCCR0 , 6);
		SET_BIT(TCCR0 , 3);
		
	#elif(TIMER0_MODE == TIMER_FAST_PWM )
		SET_BIT(TCCR0 , 6);
		SET_BIT(TCCR0 , 3);
		
	#elif(TIMER0_MODE == TIMER_PHASE_PWM )
		SET_BIT(TCCR0 , 6);
		CLEAR_BIT(TCCR0 , 3);
		
	#endif

	#if(TIMER0_COM_EVENT == TIMER_NO_ACTION)
	CLEAR_BIT(TCCR0 , 4);
	CLEAR_BIT(TCCR0 , 5);
	
	
	#elif(TIMER0_COM_EVENT == TIMER_TOGGLE)
	SET_BIT(TCCR0 , 4)
	CLEAR_BIT(TCCR0 , 5);
	#elif(TIMER0_COM_EVENT == TIMER_CLEAR )
	CLEAR_BIT(TCCR0 , 4);
	SET_BIT(TCCR0 , 5);
	#elif(TIMER0_COM_EVENT == TIMER_SET )
	SET_BIT(TCCR0 , 4);
	SET_BIT(TCCR0 , 5);

	
	#endif
	
	#if(TIMER0_PRESCALER == TIMER_DIV_BY_1)
		SET_BIT(TCCR0 , 0);
		CLEAR_BIT(TCCR0 , 1);
		CLEAR_BIT(TCCR0 , 2);
	
	#elif(TIMER0_PRESCALER == TIMER_DIV_BY_8)
		CLEAR_BIT(TCCR0 , 0);
		SET_BIT(TCCR0 , 1);
		CLEAR_BIT(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER_DIV_BY_64 )
		SET_BIT(TCCR0 , 0);
		SET_BIT(TCCR0 , 1);
		CLEAR_BIT(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER_DIV_BY_256 )
		CLEAR_BIT(TCCR0 , 0);
		CLEAR_BIT(TCCR0 , 1);
		SET_BIT(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER_DIV_BY_1024 )
		SET_BIT(TCCR0 , 0);
		CLEAR_BIT(TCCR0 , 1);
		SET_BIT(TCCR0 , 2);
		
	#endif
}

void TIMER0_void_SET_BITTimerReg(u8 Copy_u8Val)
{
	TCNT0 = Copy_u8Val ;
}

void TIMER0_void_SET_BITCompareVal(u8 Copy_u8Val)
{
	OCR0 = Copy_u8Val ;
}

void TIMER0_void_EnableOVInt(void)
{
	SET_BIT(TIMSK , 0);
}

void TIMER0_void_DisableOVInt(void)
{
	CLEAR_BIT(TIMSK , 0);
}

void TIMER0_void_EnableCTCInt(void)
{
	SET_BIT(TIMSK , 1);
}

void TIMER0_void_DisableCTCInt(void)
{
	CLEAR_BIT(TIMSK , 1);
}
/********************************    Timer 2    ************************************/

void TIMER0_void_Init(void)
{
	#if(TIMER2_MODE == TIMER_NORMAL)
	CLEAR_BIT(TCCR2 , 6);
	CLEAR_BIT(TCCR2 , 3);
	
	#elif(TIMER2_MODE == TIMER_CTC)
	CLEAR_BIT(TCCR2 , 6);
	SET_BIT(TCCR2 , 3);
	
	#elif(TIMER2_MODE == TIMER_FAST_PWM )
	SET_BIT(TCCR2 , 6);
	SET_BIT(TCCR2 , 3);
	
	#elif(TIMER2_MODE == TIMER_PHASE_PWM )
	SET_BIT(TCCR2 , 6);
	CLEAR_BIT(TCCR2 , 3);
	
	#endif

	#if(TIMER2_COM_EVENT == TIMER_NO_ACTION)
	CLEAR_BIT(TCCR2 , 4);
	CLEAR_BIT(TCCR2 , 5);
	
	
	#elif(TIMER2_COM_EVENT == TIMER_TOGGLE)
	SET_BIT(TCCR2 , 4)
	CLEAR_BIT(TCCR2 , 5);
	#elif(TIMER2_COM_EVENT == TIMER_CLEAR )
	CLEAR_BIT(TCCR2 , 4);
	SET_BIT(TCCR2 , 5);
	#elif(TIMER2_COM_EVENT == TIMER_SET )
	SET_BIT(TCCR2 , 4);
	SET_BIT(TCCR2 , 5);

	
	#endif
	
	#if(TIMER2_PRESCALER == TIMER_DIV_BY_1)
	SET_BIT(TCCR2 , 0);
	CLEAR_BIT(TCCR2 , 1);
	CLEAR_BIT(TCCR2 , 2);
	
	#elif(TIMER2_PRESCALER == TIMER_DIV_BY_8)
	CLEAR_BIT(TCCR2 , 0);
	SET_BIT(TCCR2 , 1);
	CLEAR_BIT(TCCR2 , 2);
	#elif(TIMER2_PRESCALER == TIMER_DIV_BY_64 )
	SET_BIT(TCCR2 , 0);
	SET_BIT(TCCR2 , 1);
	CLEAR_BIT(TCCR2 , 2);
	#elif(TIMER2_PRESCALER == TIMER_DIV_BY_256 )
	CLEAR_BIT(TCCR2 , 0);
	CLEAR_BIT(TCCR2 , 1);
	SET_BIT(TCCR2 , 2);
	#elif(TIMER2_PRESCALER == TIMER_DIV_BY_1024 )
	SET_BIT(TCCR2 , 0);
	CLEAR_BIT(TCCR2 , 1);
	SET_BIT(TCCR2 , 2);
	
	#endif
}

void TIMER2_void_SET_BITTimerReg(u8 Copy_u8Val)
{
	TCNT2 = Copy_u8Val ;
}

void TIMER2_void_SET_BITCompareVal(u8 Copy_u8Val)
{
	OCR2 = Copy_u8Val ;
}

void TIMER2_void_EnableOVInt(void)
{
	SET_BIT(TIMSK , 6);
}

void TIMER2_void_DisableOVInt(void)
{
	CLEAR_BIT(TIMSK , 6);
}

void TIMER2_void_EnableCTCInt(void)
{
	SET_BIT(TIMSK , 7);
}

void TIMER0_void_DisableCTCInt(void)
{
	CLEAR_BIT(TIMSK , 7);
}
/********************************    Timer 1    ************************************/

void TIMER1_void_Init(void)
{
	#if(TIMER0_MODE == TIMER1_NORMAL)
	CLEAR_BIT(TCCR1A , 0);	//WGM10 //NAME_PIN
	CLEAR_BIT(TCCR1A , 1);	//WGM11
	CLEAR_BIT(TCCR1B , 3);	//WGM12
	CLEAR_BIT(TCCR1B , 4);	//WGM13
	
	#elif(TIMER0_MODE == TIMER1_PWM_Phase_8bit)
	SET_BIT(TCCR1A , 0);	//WGM10
	CLEAR_BIT(TCCR1A , 1);	//WGM11
	CLEAR_BIT(TCCR1B , 3);	//WGM12
	CLEAR_BIT(TCCR1B , 4);	//WGM13
	#elif(TIMER0_MODE == TIMER1_PWM_Phase_9bit )
	CLEAR_BIT(TCCR1A , 0);	//WGM10
	SET_BIT(TCCR1A , 1);	//WGM11
	CLEAR_BIT(TCCR1B , 3);	//WGM12
	CLEAR_BIT(TCCR1B , 4);	//WGM13
	#elif(TIMER0_MODE == TIMER1_PWM_Phase_10bit )
	SET_BIT(TCCR1A , 0);	//WGM10
	SET_BIT(TCCR1A , 1);	//WGM11
	CLEAR_BIT(TCCR1B , 3);	//WGM12
	CLEAR_BIT(TCCR1B , 4);	//WGM13
	#elif(TIMER0_MODE == TIMER1_CTC_OCR1A)
	CLEAR_BIT(TCCR1A , 0);	//WGM10
	CLEAR_BIT(TCCR1A , 1);	//WGM11
	SET_BIT(TCCR1B , 3);	//WGM12
	CLEAR_BIT(TCCR1B , 4);	//WGM13
	#elif(TIMER0_MODE == TIMER1_Fast_PWM_8bit )
	SET_BIT(TCCR1A , 0);	//WGM10
	CLEAR_BIT(TCCR1A , 1);	//WGM11
	SET_BIT(TCCR1B , 3);	//WGM12
	CLEAR_BIT(TCCR1B , 4);	//WGM13
	#elif(TIMER0_MODE == TIMER1_Fast_PWM_9bit )
	CLEAR_BIT(TCCR1A , 0);	//WGM10
	SET_BIT(TCCR1A , 1);	//WGM11
	SET_BIT(TCCR1B , 3);	//WGM12
	CLEAR_BIT(TCCR1B , 4);	//WGM13
	#elif(TIMER0_MODE == TIMER1_Fast_PWM_10bit)
	SET_BIT(TCCR1A , 0);	//WGM10
	SET_BIT(TCCR1A , 1);	//WGM11
	SET_BIT(TCCR1B , 3);	//WGM12
	CLEAR_BIT(TCCR1B , 4);	//WGM13
	#elif(TIMER0_MODE == TIMER1_PWM_Phase_Frequency_Correct_ICR1 )
	CLEAR_BIT(TCCR1A , 0);	//WGM10
	CLEAR_BIT(TCCR1A , 1);	//WGM11
	CLEAR_BIT(TCCR1B , 3);	//WGM12
	SET_BIT(TCCR1B , 4);	//WGM13
	#elif(TIMER0_MODE == TIMER1_PWM_Phase_Frequency_Correct_OCR1A )
	SET_BIT(TCCR1A , 0);	//WGM10
	CLEAR_BIT(TCCR1A , 1);	//WGM11
	CLEAR_BIT(TCCR1B , 3);	//WGM12
	SET_BIT(TCCR1B , 4);	//WGM13
	#elif(TIMER0_MODE == TIMER1_PWM_Phase__ICR1)
	CLEAR_BIT(TCCR1A , 0);	//WGM10
	SET_BIT(TCCR1A , 1);	//WGM11
	CLEAR_BIT(TCCR1B , 3);	//WGM12
	SET_BIT(TCCR1B , 4);	//WGM13
	#elif(TIMER0_MODE == TIMER1_PWM_Phase__OCR1A )
	SET_BIT(TCCR1A , 0);	//WGM10
	SET_BIT(TCCR1A , 1);	//WGM11
	CLEAR_BIT(TCCR1B , 3);	//WGM12
	SET_BIT(TCCR1B , 4);	//WGM13
	#elif(TIMER0_MODE == TIMER1_CTC_ICR1 )
	CLEAR_BIT(TCCR1A , 0);	//WGM10
	CLEAR_BIT(TCCR1A , 1);	//WGM11
	SET_BIT(TCCR1B , 3);	//WGM12
	SET_BIT(TCCR1B , 4);	//WGM13
	
	#elif(TIMER0_MODE == TIMER1_FastPWM_ICR1 )
	SET_BIT(TCCR1A , 0);	//WGM10
	CLEAR_BIT(TCCR1A , 1);	//WGM11
	SET_BIT(TCCR1B , 3);	//WGM12
	SET_BIT(TCCR1B , 4);	//WGM13
	#elif(TIMER0_MODE == TIMER1_FastPWM_OCR1A )
	SET_BIT(TCCR1A , 0);	//WGM10
	SET_BIT(TCCR1A , 1);	//WGM11
	SET_BIT(TCCR1B , 3);	//WGM12
	SET_BIT(TCCR1B , 4);	//WGM13
	
	#endif
	
	    /***********************   Timer1 PreScaler   **************************/

	#if(TIMER0_PRESCALER == Timer_Pre_STOP)
	CLEAR_BIT(TCCR1B , 0);	  //CS10
	CLEAR_BIT(TCCR1B , 1);	  //CS11
	CLEAR_BIT(TCCR1B , 2);	  //CS12
	
	#if(TIMER0_PRESCALER == TIMER_DIV_BY_1)
	SET_BIT(TCCR1B , 0);		 //CS10
	CLEAR_BIT(TCCR1B , 1);		 //CS11
	CLEAR_BIT(TCCR1B , 2);		 //CS12
	
	#elif(TIMER0_PRESCALER == TIMER_DIV_BY_8)
	CLEAR_BIT(TCCR1B , 0);		   //CS10
	SET_BIT(TCCR1B , 1);		   //CS11
	CLEAR_BIT(TCCR1B , 2);;		   //CS12
	#elif(TIMER0_PRESCALER == TIMER_DIV_BY_64 )
	SET_BIT(TCCR1B , 0);		  //CS10
	SET_BIT(TCCR1B , 1);		  //CS11
	CLEAR_BIT(TCCR1B , 2);		  //CS12
	#elif(TIMER0_PRESCALER == TIMER_DIV_BY_256 )
	CLEAR_BIT(TCCR1B , 0);		  //CS10
	CLEAR_BIT(TCCR1B , 1);		  //CS11
	SET_BIT(TCCR1B , 2);		  //CS12
	#elif(TIMER0_PRESCALER == TIMER_DIV_BY_1024 )
	SET_BIT(TCCR1B , 0);		  //CS10
	CLEAR_BIT(TCCR1B , 1);		  //CS11
	SET_BIT(TCCR1B , 2);		  //CS12
	#if(TIMER0_PRESCALER == Timer_Pre_External_T1_Falling)
	CLEAR_BIT(TCCR1B , 0);		  //CS10
	SET_BIT(TCCR1B , 1);		  //CS11
	SET_BIT(TCCR1B , 2);		  //CS12
	#if(TIMER0_PRESCALER == Timer_Pre_External_T1_Raising)
	SET_BIT(TCCR1B , 0);		   //CS10
	SET_BIT(TCCR1B , 1);		   //CS11
	SET_BIT(TCCR1B , 2);		   //CS12
	#endif
	
	    /**********************  Input Capture  Options  **********************/


	#if (Timer1_IC_Edge_Select == Timer1_IC_Raising_Edge)
	SET_BIT(TCCR1B,6); //ICES1
	#elif (Timer1_IC_Edge_Select == Timer1_IC_Falling_Edge)
	CLEAR_BIT(TCCR1B,6); //ICES1
	#endif
	
	#if (Timer1_IC_Noise_Canceller == Disabled)
	CLEAR_BIT(TCCR1B,7); //CNC1
	#elif (Timer1_IC_Noise_Canceller == Enabled)
	SET_BIT(TCCR1B,7); //CNC1
	#endif
	
	 /***********************   Timer1 OCR1A Pin   **************************/
	 #if  (Compare_Output_Mode_A == TIMER_NO_ACTION)
	 CLEAR_BIT(TCCR1A,7);
	 CLEAR_BIT(TCCR1A,6);
	 #elif  (Compare_Output_Mode_A == TIMER_TOGGLE)
	 CLEAR_BIT(TCCR1A,7);
	 SET_BIT(TCCR1A,6);
	 #elif  (Compare_Output_Mode_A == TIMER_SET)
	 SET_BIT(TCCR1A,7);
	 CLEAR_BIT(TCCR1A,6);
	 #elif  (Compare_Output_Mode_A == TIMER_CLEAR)
	 SET_BIT(TCCR1A,7);
	 SET_BIT(TCCR1A,6);
	 #endif

	 /***********************   Timer1 OCR1B Pin   **************************/
	 #if  (Compare_Output_Mode_B == TIMER_NO_ACTION)
	 CLEAR_BIT(TCCR1A,7); //COM1A1
	 CLEAR_BIT(TCCR1A,6); //COM1A0
	 #elif  (Compare_Output_Mode_B ==TIMER_TOGGLE)//TOGGLE FOR OC1A ONLY Data sheet
	 CLEAR_BIT(TCCR1A,7);//COM1A1
	 SET_BIT(TCCR1A,6); //COM1A0
	 #elif  (Compare_Output_Mode_B == TIMER_SET)
	 SET_BIT(TCCR1A,7);//COM1A1
	 CLEAR_BIT(TCCR1A,6); //COM1A0
	 #elif  (Compare_Output_Mode_B == TIMER_CLEAR)
	 SET_BIT(TCCR1A,7);//COM1A1
	 SET_BIT(TCCR1A,6); //COM1A0
	 #endif
	
	
	void Timer1_Enable_Input_Capture_Interrupt()  
	  {		SET_BIT(TIMSK,5);     } // TIMSK
	void Timer1_Disable_Input_Capture_Interrupt() 
	  {    CLEAR_BIT(TIMSK,5);     } // TIMSK

	void Timer1_Enable_Compare_A_Interrupt()     
	   {      SET_BIT(TIMSK,4);     } // TIMSK
	void Timer1_Disable_Compare_A_Interrupt()   
	    {    CLEAR_BIT(TIMSK,4);     } // TIMSK

	void Timer1_Enable_Compare_B_Interrupt()      
	  {      SET_BIT(TIMSK,3);     } // TIMSK
	void Timer1_Disable_Compare_B_Interrupt()    
	   {    CLEAR_BIT(TIMSK,3);     } // TIMSK

	void Timer1_Enable_Overflow_Interrupt()       
	  {      SET_BIT(TIMSK,2);     } // TIMSK
	void Timer1_Disable_Overflow_Interrupt()      
	  {    CLEAR_BIT(TIMSK,2);     } // TIMSK

	u8 Timer1_Read_IC_Interrupt_Flag()        
	   {    return GET_BIT(TIFR,5); } // TIFR
	u8 Timer1_Read_OCA_Interrupt_Flag()      
	    {    return GET_BIT(TIFR,4); } // TIFR
	u8 Timer1_Read_OCB_Interrupt_Flag()      
	    {    return GET_BIT(TIFR,3); } // TIFR
	u8 Timer1_Read_OVF_Interrupt_Flag()    
	      {    return GET_BIT(TIFR,2); } // TIFR
	u16	Timer1_Read_IC_Reg()                   
	  { return ((ICR1H << 8) | ICR1L);} // ICR1H/L

