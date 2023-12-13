

#ifndef SCHEDULAR_INT_H_
#define SCHEDULAR_INT_H_

void RTOS_CreatTask(u16 Copy_Periodicity , void(*pfun)(void),u8 Priority); // service
void RTOS_Schaduler(void); //ISR
void RTOS_Start(void); // service timer initialization
void RTOS_KillTask(u8 Priority); // service

#endif
