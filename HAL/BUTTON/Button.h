#ifndef BUTTON_H_
#define BUTTON_H_

extern u8 button0_State;
extern u8 button1_State;
extern u8 button2_State;
void Button_Init();
void Check_Button0_Clicked(u8 * button0_State);
void Check_Button1_Clicked(u8 * button1_State);
void Check_Button2_Clicked(u8 * button02_State);

#endif