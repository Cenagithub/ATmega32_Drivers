#ifndef SPI_INT_H_
#define SPI_INT_H_

void SPI_voidInit(void);

 u8 SPI_u8Transfere(u8);

void SPI_enable(void);
void Spi_Disable(void);

void SPI_interrupt_enable(void);
void Spi_interrupt_Disable(void);

#endif /* SPI_INT_H_ */