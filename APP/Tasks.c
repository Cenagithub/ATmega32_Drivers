/*
 * ADC_TIMER.c
 *
 * Created: 11/24/2023 8:43:17 AM
 *  Author: cena
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include "../MCAL/service/STD_types.h"
#include "../MCAL/service/BIT_math.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../MCAL/ADC/ADC_config.h"
#include "../MCAL/Interrupt/EXTI_int.h"
#include "../MCAL/Interrupt/GIE_int.h"
#include "../MCAL/Timer/Timer_int.h"
#include "../MCAL/TWI/TWI_int.h"
#include "../MCAL/UART/UART_int.h"

#include "../HAL/SevenSegment/SSEG_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/KEYPAD/KEYPAD_int.h"
#include "../HAL/BUTTON/Button.h"
#include "../HAL/LED/LED.h"
#include "../HAL/LCD/LCD_int.h"

#include "../MCAL/Schedular/Schedular_int.h"

void Task22_RTOS2_SSEG_LED()
{
	u8 count = 0;
	u8 counter =0;
	void SSEG(void)
	{
		if(count<=9)
		{
			SSEG_voidDisplay(1,count);
			//_delay_ms(1000);
			count++;
		}
		else if (count>9)
		{
			count=1;
		}
	}
	void LED(void)
	{
		if(counter== 0)
		{
			DIO_voidSetPinVal(DIO_U8_PORTC,2,DIO_U8_HIGH);
			DIO_voidSetPinVal(DIO_U8_PORTC,7,DIO_U8_LOW);
			DIO_voidSetPinVal(DIO_U8_PORTD,3,DIO_U8_LOW);
			counter++;
		}
		else if(counter== 1)
		{
			DIO_voidSetPinVal(DIO_U8_PORTC,2,DIO_U8_LOW);
			DIO_voidSetPinVal(DIO_U8_PORTC,7,DIO_U8_HIGH);
			DIO_voidSetPinVal(DIO_U8_PORTD,3,DIO_U8_LOW);
			counter++;

		}
		else if(counter== 2)
		{
			DIO_voidSetPinVal(DIO_U8_PORTC,2,DIO_U8_LOW);
			DIO_voidSetPinVal(DIO_U8_PORTC,7,DIO_U8_LOW);
			DIO_voidSetPinVal(DIO_U8_PORTD,3,DIO_U8_HIGH);
			counter= 0;

		}

	}


	void Kill(void)
	{
		RTOS_KillTask(2);
	}

	int main (void)
	{
		LED0_Init();
		LED1_Init();
		LED2_Init();
		SSEG_voidInit();
		
		// fixed priority
		RTOS_CreatTask(1000,&SSEG,0);
		RTOS_CreatTask(10000,&LED ,1);


		RTOS_Start();
		GIE_voidEnable();
		
		while(1)
		{
			
			
		}
		



	}
}

void Task21_RTOS1_LED()
{
	void LED_1(void)
	{

		DIO_voidTogglePin(DIO_U8_PORTC ,DIO_U8_PIN2); //
	}
	void LED_2(void)
	{
		DIO_voidTogglePin(DIO_U8_PORTC ,DIO_U8_PIN7);

	}
	void LED_3(void)
	{
		DIO_voidTogglePin(DIO_U8_PORTD ,DIO_U8_PIN3);

	}

	void Kill(void)
	{
		RTOS_KillTask(3);
	}

	int main (void)
	{
		DIO_voidSetPinDir(DIO_U8_PORTC,DIO_U8_PIN7,DIO_U8_OUTPUT);
		DIO_voidSetPinDir(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_OUTPUT);
		DIO_voidSetPinDir(DIO_U8_PORTD,DIO_U8_PIN3,DIO_U8_OUTPUT);

		// fixed priority
		RTOS_CreatTask(1000,&LED_1 ,0);
		RTOS_CreatTask(2000,&LED_2 ,1);
		RTOS_CreatTask(3000,&LED_3 ,3);
		//RTOS_CreatTask(4000,&Kill ,0);

		RTOS_Start();
		GIE_voidEnable();


		while(1)
		{

		}

	}
}



void Task_20_Interrupt_with_3_LED()
{
	 DIO_voidSetPinDir(DIO_U8_PORTD,DIO_U8_PIN3,DIO_U8_OUTPUT);
	 DIO_voidSetPinDir(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_OUTPUT);
	 DIO_voidSetPinDir(DIO_U8_PORTC,DIO_U8_PIN7,DIO_U8_OUTPUT);
	 TIMER0_void_Init();
	 TIMER0_void_SetTimerReg(247);
	 TIMER0_void_EnableOVInt();
	 GIE_voidEnable();
	 while (1)
	 {
	 }
}
 
void Task_20_isr()
{
	

		static u8 counter = 0;
		counter++;
		
		
		if(counter == 62)
		{
			
			DIO_voidSetPinVal(DIO_U8_PORTD,DIO_U8_PIN3,DIO_U8_HIGH);
			
			
			
		}
		if(counter == 62*2)
		{
			
			
			DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN7,DIO_U8_HIGH);
			
			

		}
		
		if(counter == 62*3)
		{
			
			DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_HIGH);
			
			
			counter=0;

		}
		
		
		//TIMER0_void_SetTimerReg(247);
		

}
void TASK19_Username_Pass_UART_Bluetooth(){
	 
	 UART_voidInit();
	 
	 u8 count=0;
	 u8 Username[7]="Mohamed";
	 u8 Password[5]="12345";
	 u8 RecieveUser[8];
	 u8 RecievePass[8];
	 
	 while(1)
	 {

		UART_voidSendString("Enter Username : ");
		UART_voidSendByte('\n');
		UART_voidRecieveString(RecieveUser);
		
		u8 Userchecker = memcmp(RecieveUser,Username,7);
		
		UART_voidSendString("Enter Password : ");
		UART_voidSendByte('\n');
		UART_voidRecieveString(RecievePass);

		u8 passchecker = memcmp(RecievePass,Password,5);
		
		if((passchecker == 0)&&(Userchecker ==0))
		{
			UART_voidSendString("Success \n ");
			
		}
		else
		{
			if(count ==3)
			{
				UART_voidSendString("System Locked \n");
				
			}
			else
			{
				UART_voidSendString("Try Again.. \n");
				count++;
			}
		}
		
	}
 }
 
void TASK18_LCD_EEPROM(){
	
	s8 arr[10];

	TWI_voidInit();
	EEPROM_voidInit();
	LCD_voidInit();

/*
 *
 * Write data to EEPROM character by character
 *
 * */
	EEPROM_VoidWriteByte(0x0000 , 'A');
	_delay_ms(5);
	EEPROM_VoidWriteByte(0x0001 , 'b');
	_delay_ms(5);
	EEPROM_VoidWriteByte(0x0002 , 'd');
	_delay_ms(5);
	EEPROM_VoidWriteByte(0x0003 , 'e');
	_delay_ms(5);
	EEPROM_VoidWriteByte(0x0004 , 'l');
	_delay_ms(5);
	EEPROM_VoidWriteByte(0x0005 , 'g');
	_delay_ms(5);
	EEPROM_VoidWriteByte(0x0006 , 'a');
	_delay_ms(5);
	EEPROM_VoidWriteByte(0x0007 , 'w');
	_delay_ms(5);
	EEPROM_VoidWriteByte(0x0008 , 'a');
	_delay_ms(5);	
	EEPROM_VoidWriteByte(0x0009 , 'd');
	_delay_ms(5);	
	

	_delay_ms(3000);

	/*
	 *
	 * Read data from EEPROM character by character
	 * And store it to the array
	 * */


	 arr[0]  =  EEPROM_u8ReadByte(0x0000);
	// _delay_ms(1);
	 arr[1]  =  EEPROM_u8ReadByte(0x0001);
	// _delay_ms(1);
	 arr[2]  =  EEPROM_u8ReadByte(0x0002);
	// _delay_ms(1);
	 arr[3]  =  EEPROM_u8ReadByte(0x0003);
	 //_delay_ms(1);
	 arr[4]  =  EEPROM_u8ReadByte(0x0004);
	 //_delay_ms(1);
	 arr[5]  =  EEPROM_u8ReadByte(0x0005);
	 //_delay_ms(1);
	 arr[6]  =  EEPROM_u8ReadByte(0x0006);
	 //_delay_ms(1);
	 arr[7]  =  EEPROM_u8ReadByte(0x0007);
	 //_delay_ms(1);
	 arr[8]  =  EEPROM_u8ReadByte(0x0008);
	 //_delay_ms(1);
	 arr[9]  =  EEPROM_u8ReadByte(0x0009);
	 //_delay_ms(1);
	
	 /*
	  * Display the data in he array through LCD
	  *
	  * */
	LCD_voidSendData(arr[0]);
	LCD_voidSendData(arr[1]);
	LCD_voidSendData(arr[2]);
	LCD_voidSendData(arr[3]);
	LCD_voidSendData(arr[4]);
	LCD_voidSendData(arr[5]);
	LCD_voidSendData(arr[6]);
	LCD_voidSendData(arr[7]);
	LCD_voidSendData(arr[8]);
	LCD_voidSendData(arr[9]);
	while(1)
	{

	}


	return 0 ;
}
void TASK17_UART_led_bluetooth()
{
UART_voidInit();
LED0_Init();
LED1_Init();
LED2_Init();
u8 Recieve;

while(1)
{
	Recieve = UART_u8ReceiveByte();
	switch(Recieve)
	{
		case '0':
		LED0_On();
		break;

		case '1':
		LED0_Off();
		break;
		case '2':
		LED1_On();
		break;

		case '3':
		LED1_Off();
		break;
		case '4':
		LED2_On();
		break;

		case '5':
		LED2_Off();
		break;
		default:
		UART_voidSendByte(' ');
		break;
	}
	
}
}
	
	
void TASK16_TIMER_FASTPWM_LED(){
	
	 ADC_voidInit();
	 DIO_voidSetPinDir(DIO_U8_PORTB, DIO_U8_PIN3,DIO_U8_OUTPUT);
	 u8 digital = 2;
	 u8 old_digital = 2;
	 digital = ADC_u8Convert(ADC_U8_Channel1);
	 old_digital = digital;
	 TIMER0_void_SetCompareVal(digital);
	 TIMER0_void_Init();
	 TIMER0_void_EnableCTCInt();
	 GIE_voidEnable();
	 while (1)
	 {
		 digital = ADC_u8Convert( ADC_U8_Channel1);
		 if((abs(digital-old_digital) > 10))
		 {
			 old_digital = digital;
			 TIMER0_void_SetCompareVal(old_digital);
		 }
	 } 
}

void TASK15_TIMER_CTC_ADC_POTENIOMETER(){
	ADC_voidInit();
	DIO_voidSetPinDir(DIO_U8_PORTB, DIO_U8_PIN3,DIO_U8_OUTPUT);
	u8 digital = 2;
	u8 old_digital = 2;
	digital = ADC_u8Convert(ADC_U8_Channel1);
	old_digital = digital;
	TIMER0_void_SetCompareVal(digital);
	TIMER0_void_Init();
	TIMER0_void_EnableCTCInt();
	GIE_voidEnable();
	while (1)
	{
		digital = ADC_u8Convert(ADC_U8_Channel1);
		if((abs(digital-old_digital) > 10))
		{
			old_digital = digital;
			TIMER0_void_SetCompareVal(digital);
		}
	}
}
void TASK14_TIMER_CTC_Freq(){
    
	
	 DIO_voidSetPinDir(DIO_U8_PORTA, DIO_U8_PIN0,DIO_U8_OUTPUT);
	 DIO_voidSetPinDir(DIO_U8_PORTA, DIO_U8_PIN0,DIO_U8_LOW);
	TIMER0_void_Init();
	TIMER0_void_SetCompareVal(200);
	TIMER0_void_EnableCTCInt();
	GIE_voidEnable();
	while (1)
	{
	}
}
void TASK14_ISR(){
	  //TIMER0_void_SetCompareVal(195);
	  static u32 Loop_counter = 0;
	  static u8 flag = 0;
	  Loop_counter++;
	  if(Loop_counter == 1){
		  Loop_counter = 0;
		  if(flag == 0){
			  DIO_voidSetPinDir(DIO_U8_PORTA, DIO_U8_PIN0,DIO_U8_HIGH);
			  flag = 1;
		  }
		  else if (flag == 1){
			  DIO_voidSetPinDir(DIO_U8_PORTD, DIO_U8_PIN7,DIO_U8_LOW);
			  flag = 0;
		  }
	  }
}
void TASK13_TIMER_SQRWAVE_NORMAL(){

	LED1_Init();
	
	 DIO_voidSetPinDir(DIO_U8_PORTD, DIO_U8_PIN7,DIO_U8_OUTPUT);
	 DIO_voidSetPinDir(DIO_U8_PORTD, DIO_U8_PIN7,DIO_U8_LOW);
	  TIMER0_void_Init();
	  //TIMER0_void_SetTimerReg(200);
	  TIMER0_void_EnableOVInt();
	  GIE_voidEnable();
	  while (1)
	  {
	  }
}
void TASK13_ISR(){
	static u32 Loop_counter = 0;
	static u8 flag = 0;
	Loop_counter++;
	if(Loop_counter == 13){
		Loop_counter = 0;
		//TIMER0_void_SetTimerReg(195);
		if(flag == 0){
		 DIO_voidSetPinDir(DIO_U8_PORTD, DIO_U8_PIN7,DIO_U8_HIGH);

			flag = 1;
		}
		else if (flag == 1){
			DIO_voidSetPinDir(DIO_U8_PORTD, DIO_U8_PIN7,DIO_U8_LOW);
			flag = 0;
		}
	}
}
void TASK12_TIMER_LED(){
	 LED1_Init();
	 
	 TIMER0_void_Init();
	 TIMER0_void_SetTimerReg(247);
	 TIMER0_void_EnableOVInt();
	 GIE_voidEnable();
	 while(1){}
}
void TASK12_ISR(){
	
	 static u8 counter = 0;
	 static u8 flag = 0;
	 counter++;
	 if(counter == 62){
		 if(flag == 0){
			 LED1_On();
			 flag = 1;
		 }
		 else if (flag == 1){
			 LED1_Off();
			 flag = 0;
		 }
		 counter = 0;
		 TIMER0_void_SetTimerReg(247);
	 }
}
void TASK11_KEYPAD_LCD_INTERRUPT(){
	
	 LCD_voidInit();
	 LED1_Init();
	 EXTI0_voidSetDir();
	 EXTI0_voidSetPull_Up();
	 LED0_Off();
	 EXTI0_voidInit();
	 EXTI0_voidEnable();
	 GIE_voidEnable();
	 while(1)
	 {   
	 }
	
}
void TASK11_ISR(){
	
		
		KEYPAD_voidInit();
		u8 x='\0';
		x= KEYPAD_u8GetButton();
		LCD_voidSendData(x);
	
}
void Task10_INTERRUPT_LED_BUTTON()
{
	
	DIO_voidSetPinDir(DIO_U8_PORTD,DIO_U8_PIN2,DIO_U8_INPUT); //INT0 input
	DIO_voidSetPinDir(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_OUTPUT); //activate pull up
	DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_LOW); //LED output
	
	EXTI0_voidInit();
	EXTI0_voidEnable(); //PIE
	GIE_voidEnable(); //GIE
	while(1)
	{
		
	}
	return 0 ;
	 
}
void TASK10_ISR_EXTI()
{
	
		static u8 flag = 0;

		if(flag == 0)
		{
			DIO_voidSetPinVal(DIO_U8_PORTC , DIO_U8_PIN2, DIO_U8_HIGH);
			flag = 1;
		}
		else
		{
			DIO_voidSetPinVal(DIO_U8_PORTC , DIO_U8_PIN2, DIO_U8_LOW);
			flag = 0;
		}
	
	
	
}

void Task9_Potentiometer_LCD_with_LED()
{
	LED0_Init();
	LED1_Init();
	LED2_Init();
	LCD_voidInit();
	ADC_voidInit();
	
	u8 digital = 0;
	float analog = 0;
	float temp = 0;
	s8 string[20];
	
	DIO_voidSetPinDir(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_U8_PORTC,DIO_U8_PIN1,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_OUTPUT);
	
	
	while (1)
	{
		digital = ADC_u8Convert(ADC_U8_Channel1);
		analog = digital * (5.0/256.0);
		temp = (analog/0.01);
		
		dtostrf(temp,5,10,string);
		LCD_voidSendString(string);
		_delay_ms(200);
		LCD_voidClearLCD();
		
		if(temp<166.6 && temp> 0)
		{
			DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_HIGH);
			
			DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN1,DIO_U8_LOW);
			DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_LOW);
			
		}
		
		else if(temp<=333.33 && temp > 166.6)
		{
			DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN1,DIO_U8_HIGH);
			
			DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_LOW);
			DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_LOW);
		}
		
		else if(temp<500 && temp > 333.33)
		{
			DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_HIGH);
			
			DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN1,DIO_U8_LOW);
			DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_LOW);
		}
	}
}
void Task8_Potentiometer()
{
	
	  ADC_voidInit();
	  LCD_voidInit();
	  u8 digital = 0;
	  float analog = 0;
	  s8 string[20];
	  while (1)
	  {
		  digital = ADC_u8Convert(ADC_U8_Channel1);
		  analog = digital * (5.0/256.0)*100;
		
		  dtostrf(analog,5,10,string);
		  LCD_voidSendString(string);
		  _delay_ms(200);
		  LCD_voidClearLCD();
	  }
}


