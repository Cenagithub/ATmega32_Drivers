

#define SPDR *((volatile u8*)0x2F)   
#define SPSR *((volatile u8*)0x2E)  
#define SPCR *((volatile u8*)0x2D) 





#define SPI_U8_MSB       15
#define SPI_U8_LSB       17


#define SPI_U8_FOSC_2    2 
#define SPI_U8_FOSC_4    4
#define SPI_U8_FOSC_8    8
#define SPI_U8_FOSC_16   16
#define SPI_U8_FOSC_32   32
#define SPI_U8_FOSC_64   64
#define SPI_U8_FOSC_128  128

#define SPI_U8_MASTER       0
#define SPI_U8_SLAVE        1

#define SPI_U8_IDLE_LOW     3
#define SPI_U8_IDLE_HIGH    5

#define SPI_U8_LEADING      7
#define SPI_U8_TAILLING     9

