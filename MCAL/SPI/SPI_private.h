#ifndef UART_PRIV_H_
#define UART_PRIV_H_

#define SPDR  (* (  volatile u8 * ) 0x2F ) 
#define SPSR (* (  volatile u8 * ) 0x2E )
#define SPCR (* (  volatile u8 * ) 0x2D )




#define 
#define 
#define 
#define 


#define SPIF 0
#define WCOL 1

#define SPIE 0
#define SPE  1
#define DORD 2
#define MSTR 3
#define CPOL 4
#define CPHA 5
#define SPR1 6
#define SPR0 7

#define SPI_  0
#define SPI_Data_order1	1



#define SPI_CPOL_FUN0 0
#define SPI_CPOL_FUN1 1

#define SPI_CPHA_FUN0 0 
#define SPI_CPHA_FUN1 1

#define SPI_MASTER 0
#define SPI_SLAVE  1
 
#define SPI_Freq_SCK_4		0
#define SPI_Freq_SCK_16		1
#define SPI_Freq_SCK_64		2
#define SPI_Freq_SCK_128	3
#define SPI_Freq_SCK_2		4
#define SPI_Freq_SCK_8		5
#define SPI_Freq_SCK_32		6


#endif