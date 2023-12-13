
#include <avr/interrupt.h>
#include "../service/STD_types.h"
#include "Schedular_int.h"
#include "Schedular_Config.h"
#include "Schedular_Priv.h"
#include "../Timer/Timer_Int.h"

Task_t SysTask[Task_Number]={{NULL}};

ISR(TIMER0_OVF_vect)
{
	static u8 OVFs = 0;
	OVFs++;
	if(OVFs == 63)
	{		
		static u16 Tick_Counter = 0 ;
		Tick_Counter++;
		for( u8 i = 0 ; i < Task_Number ; i++)
		{
			if (SysTask[i].TaskFunc != NULL)
			{
				if(Tick_Counter % SysTask[i].Periodicity == 0 /*&&(SysTask[i].i)*/ )
				{
					SysTask[i].TaskFunc();
				}
				else
				{
				}
			}
		}
		
		OVFs = 0;
		TIMER0_void_SetTimerReg(128);
	}
	
}


void RTOS_Start(void)
{
	TIMER0_void_Init();
	TIMER0_void_SetTimerReg(128); // half
	TIMER0_void_EnableOVInt();
}


void RTOS_CreatTask(u16 Copy_Periodicity , void(*pfun)(void),u8 Priority)
{
    if(SysTask[Priority].TaskFunc == NULL && Priority < Task_Number)
	{
		SysTask[Priority].Periodicity = Copy_Periodicity;
		SysTask[Priority].TaskFunc = pfun;
	}
}


void RTOS_KillTask(u8 Priority)
{
	SysTask[Priority].TaskFunc = NULL;
}


