/*
 * SPI_interface.h
 *
 *  Created on: Sep 18, 2023
 *      Author: alibo
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

typedef enum
{
	SPI_8Bit,
	SPI_16Bit
}DataFrameFormat_t;

typedef enum
{
	MSB,
	LSB
}LSB_OR_MSB_t;

typedef enum
{
	SLave,
	Master,
}MasterSlave_Select_t;

typedef enum
{
	fosc_2,
	fosc_4,
	fosc_8,
	fosc_16,
	fosc_32,
	fosc_64,
	fosc_128,
	fosc_256,
}CLK_Control_t;
typedef enum
{
	IDLE_0,
	IDLE_1
}ClockPolarity_t;

typedef enum
{
	FirstClockTransition,
	SecondClockTransition  // choose
}ClockPhase_t;

typedef struct
{
	MasterSlave_Select_t  MasterSlave_Select;
	DataFrameFormat_t     DataFrameFormat;
	LSB_OR_MSB_t          LSB_OR_MSB;
	CLK_Control_t         CLK_Control;
	ClockPolarity_t       ClockPolarity;
	ClockPhase_t          ClockPhase;
}SPI_config;

void SPI_voidMasterInit(SPI_config  *ptrToSPI_config);

void SPI_voidSlaveInit(SPI_config  *ptrToSPI_config);

u8 SPI_u8TransmitReceive(u8 Copy_u8SendData);


#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
