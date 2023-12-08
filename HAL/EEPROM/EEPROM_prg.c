/*
 * EEPROM_prg.c
 *
 *  Created on: 1 , 12 , 2023
 *      Author: Mohamed Abdelgawad
 */
#include "../../MCAL/service/STD_types.h"
#include "../../MCAL/service/BIT_math.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "EEPROM_int.h"
#include "EEPROM_priv.h"
#include "EEPROM_config.h"
#include "../../MCAL/TWI/TWI_int.h"


//2408
void EEPROM_voidInit(void)
{
	TWI_voidInit();
}

//0b11100000000
//0b00000p2p1p0 000000000
void EEPROM_VoidWriteByte(u16 Copy_Location , u8 Copy_Data)
{
	u8 SLA_W = 0b10100000 ; 	//0b1010 0,0,0, 0
	u8 B8 = GET_BIT(Copy_Location , 8);
	u8 B9 = GET_BIT(Copy_Location , 9);
	u8 B10 = GET_BIT(Copy_Location , 10);
	SLA_W |= ((B8<<1) | (B9<<2) | (B10<<3));
	//0b10101110
	TWI_voidSendStart();
	if(True == TWI_u8CheckStatus(StrConTx))
	{
		TWI_voidSendByte(SLA_W);
		if(True == TWI_u8CheckStatus(SlA_W_Ack))
		{
			TWI_voidSendByte((u8)Copy_Location);
			if(True == TWI_u8CheckStatus(Data_TX_Ack)) // rest of address (8 bits)
			{
				TWI_voidSendByte(Copy_Data);
				if(True == TWI_u8CheckStatus(Data_TX_Ack))
				{
					TWI_voidSendStop();
				}
			}
		}
	}
}

u8 EEPROM_u8ReadByte(u16 Copy_Location)
{

	u8 RetVal = 0;
	u8 SLA_W = 0b10100000;
	u8 SLA_R ;
	u8 B8 = GET_BIT(Copy_Location , 8);
	u8 B9 = GET_BIT(Copy_Location , 9);
	u8 B10 = GET_BIT(Copy_Location , 10);
	SLA_W |= (B8<<1) | (B9<<2) | (B10<<3);
	SLA_R = SLA_W + 1 ;
	//0b10101111
	TWI_voidSendStart();
	if(True == TWI_u8CheckStatus(StrConTx))
	{
		TWI_voidSendByte(SLA_W);
		if(True == TWI_u8CheckStatus(SlA_W_Ack))
		{
			TWI_voidSendByte((u8)  Copy_Location);
			if(True == TWI_u8CheckStatus(Data_TX_Ack))
			{
				TWI_voidSendStart();
				if(True == TWI_u8CheckStatus(RepStrConTx))
				{
					TWI_voidSendByte(SLA_R);
					if(True == TWI_u8CheckStatus(SLA_R_W_ACK)) //0x40
					{
						RetVal = TWI_u8ReceiveByteWithNoAck();
						
						TWI_voidSendStop();
					}
				}
			}
		}
	}

	return RetVal ;
}

