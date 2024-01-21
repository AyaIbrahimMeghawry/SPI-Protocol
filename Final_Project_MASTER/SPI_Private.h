/*****************************************************************************************/
/*                 AUTHOR :  Aya Ibrahim Meghawry                                       */
/*                 DATA   :  Dec 30, 2023                                                    */
/*                 TITLE  :  SPI Private                                   */
/*****************************************************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/***************SPI Control Register*************/

#define		SPCR			*((volatile u8 *)(0x2D))
/***************SPCR bits*************/
   // SPI Prescaler Bit0 and Bit1
#define     SPCR_SPR0		0x00
#define     SPCR_SPR1		0x01
   // Clock Phase Bit2
#define     SPCR_CPHA		0x02
   // Clock Polarity Bit3
#define     SPCR_CPOL		0x03
   // choose if MASTER or slave bit4
#define     SPCR_MSTR		0x04
   // Data OverRun (form LSB to MSB ) or opposite Bit5
#define     SPCR_DORD		0x05
   // SPI Enable Bit6
#define     SPCR_SPE		0x06
   // SPI Interrupt Enable Bit7
#define     SPCR_SPI		0x07


/************SPI Status Register******************/
#define		SPSR			*((volatile u8 *)(0x2E))
/************SPSR bits******************/
   // Double SPI Speed Bit0
#define		SPSR_SPI2X		0x00

   // SPI Interrupt Flag Bit7
#define     SPSR_SPIF       0x07

/************SPI Data Register********************/
#define		SPDR			*((volatile u8 *)(0x2F))


#endif
