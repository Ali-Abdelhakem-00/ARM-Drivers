/*
 * SPI_private.h
 *
 *  Created on: Sep 18, 2023
 *      Author: alibo
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_


#define SPI1_BASE_ADDRESS       0x40013000

typedef struct
{
	volatile u32 SPI_CR1;
	volatile u32 SPI_CR2;
	volatile u32 SPI_SR;
	volatile u32 SPI_DR;
	volatile u32 SPI_CRCPR;
	volatile u32 SPI_RXCRCR;
	volatile u32 SPI_TXCRCR;
	volatile u32 SPI_I2SCFGR;
	volatile u32 SPI_I2SPR;
}SPI_MemMap_t;

#define SPI           ( (volatile SPI_MemMap_t* ) SPI1_BASE_ADDRESS )

/* CR1 */
#define DataFrameFormat_BIT     11
#define SSM_BIT                 9
#define SSI_BIT                 8
#define LSBFirst_BIT            7
#define SPIEable_BIT            6
#define BR_ControlCLK_BIT       3
#define MasterSelection_BIT     2
#define ClockPolarity_BIT       1
#define ClockPhase_BIT          0
/* CR2 */


/* SR */
#define BusyFlag_BIT            7
#define TXBufferEmpty_BIT       1
#define RXBufferNotEmpty_BIT    0



#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
