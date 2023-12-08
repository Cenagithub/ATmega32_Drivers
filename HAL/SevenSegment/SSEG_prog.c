#include "../../MCAL/service/STD_types.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "SSEG_int.h"
#include "SSEG_config.h"

void SSEG_voidInit(void)
{
	DIO_voidSetPinDir(SSEG_U8_PORT,DIO_U8_PIN4,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(SSEG_U8_PORT,DIO_U8_PIN5,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(SSEG_U8_PORT,DIO_U8_PIN6,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(SSEG_U8_PORT,DIO_U8_PIN7,DIO_U8_OUTPUT);
	
	DIO_voidSetPinDir(SSEG_U8_EN_PORT,SSEG_U8_EN_SSEG1,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(SSEG_U8_EN_PORT,SSEG_U8_EN_SSEG2,DIO_U8_OUTPUT);
}
void SSEG_voidDisplay(u8 SSEG_u8_SSEG_Num , u8 SSEG_u8_Value)
{
	if(SSEG_u8_SSEG_Num == SSEG_U8_SSEG1)
	{
		DIO_voidSetPinVal(SSEG_U8_EN_PORT,SSEG_U8_EN_SSEG1,DIO_U8_HIGH);
		DIO_voidSetPinVal(SSEG_U8_EN_PORT,SSEG_U8_EN_SSEG2,DIO_U8_LOW);
	}
	else if(SSEG_u8_SSEG_Num == SSEG_U8_SSEG2)
	{
		DIO_voidSetPinVal(SSEG_U8_EN_PORT,SSEG_U8_EN_SSEG2,DIO_U8_HIGH);
		DIO_voidSetPinVal(SSEG_U8_EN_PORT,SSEG_U8_EN_SSEG1,DIO_U8_LOW);
	}
	
	DIO_voidSetPortVal(SSEG_U8_PORT,SSEG_u8_Value << 4);
}