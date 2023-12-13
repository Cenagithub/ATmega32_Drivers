

#ifndef SCHEDULAR_PRIV_H_
#define SCHEDULAR_PRIV_H_

typedef struct 
{
	u16 Periodicity ; 
	void(*TaskFunc)(void);
}Task_t ;

#endif
