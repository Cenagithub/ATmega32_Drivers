#include "../service/STD_types.h"
#include "../service/BIT_Math.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_int.h"

void SPI_voidInit(void)
{
	// master
	#if SPI_U8_MASTER_SLAVE == SPI_U8_MASTER
	SET_BIT(SPCR , 4);
	#elif SPI_U8_MASTER_SLAVE == SPI_U8_SLAVE
	CLEAR_BIT(SPCR , 4);
	#endif
	
	//LSB
	SET_BIT(SPCR , 5);
	
	//POL Idle low
	CLEAR_BIT(SPCR , 3);
	
	//phase Leading
	CLEAR_BIT(SPCR , 2);
	
	// speed Fosc / 4
	CLEAR_BIT(SPCR , 0);
	CLEAR_BIT(SPCR , 1);
	
	// disable interrupt
	SPI_voidIntDisable();
	
	//enable spi
	SET_BIT(SPCR , 6);
}
u8 SPI_u8DataTransfere(u8 Local_u8Data)
{
	SPDR = Local_u8Data;
	while(GET_BIT(SPSR , 7) == 0);
	return SPDR;
}

void SPI_voidIntEnable(void)
{
	SET_BIT(SPCR,7);
}

void SPI_voidIntDisable(void)
{
	CLEAR_BIT(SPCR,7);
}