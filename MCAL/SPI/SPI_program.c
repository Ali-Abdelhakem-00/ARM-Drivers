/*
 * SPI_program.c
 *
 *  Created on: Sep 18, 2023
 *      Author: alibo
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"



void SPI_voidMasterInit(SPI_config  *ptrToSPI_config)
{

	GPIO_PinConfig_t MOSI1 ={.Port = GPIO_PORTA,.Pin= GPIO_PIN7, .Mode = GPIO_ALTERNATE_FUNCTION,.AlternateMode = GPIO_ALTER_SPI1_4};
	GPIO_PinConfig_t MISO1 ={.Port = GPIO_PORTA,.Pin= GPIO_PIN6, .Mode = GPIO_ALTERNATE_FUNCTION,.AlternateMode = GPIO_ALTER_SPI1_4};
	GPIO_PinConfig_t SCK1  ={.Port = GPIO_PORTA,.Pin= GPIO_PIN5, .Mode = GPIO_ALTERNATE_FUNCTION,.AlternateMode = GPIO_ALTER_SPI1_4};

	GPIO_voidInit(&MOSI1);
	GPIO_voidInit(&MISO1);
	GPIO_voidInit(&SCK1);

	u16 Local_CR1REG = 0 ;
	Local_CR1REG |= ( (ptrToSPI_config->ClockPolarity)   << ClockPolarity_BIT   );
	Local_CR1REG |= ( (ptrToSPI_config->ClockPhase)      << ClockPhase_BIT      );
	Local_CR1REG |= ( (ptrToSPI_config->LSB_OR_MSB)      << LSBFirst_BIT        );
	Local_CR1REG |= ( (ptrToSPI_config->DataFrameFormat) << DataFrameFormat_BIT );
	Local_CR1REG |= ( 1 << SSM_BIT );   // FOR TFT
	Local_CR1REG |= ( 1 << SSI_BIT );   // FOR TFT
	switch(ptrToSPI_config->MasterSlave_Select)
	{
	case Master:
		Local_CR1REG |=( (ptrToSPI_config->MasterSlave_Select) << MasterSelection_BIT );
		Local_CR1REG |=( (ptrToSPI_config->CLK_Control)        << BR_ControlCLK_BIT   );
		break;
	case SLave:
		Local_CR1REG |=( (ptrToSPI_config->MasterSlave_Select) << MasterSelection_BIT);
		break;
	}
	Local_CR1REG |= ( 1<< SPIEable_BIT );
	SPI ->SPI_CR1 = Local_CR1REG;

}

void SPI_voidSlaveInit(SPI_config  *ptrToSPI_config)
{
	GPIO_PinConfig_t MOSI1 ={.Port = GPIO_PORTA,.Pin= GPIO_PIN7, .Mode = GPIO_ALTERNATE_FUNCTION,.AlternateMode = GPIO_ALTER_SPI1_4};
	GPIO_PinConfig_t MISO1 ={.Port = GPIO_PORTA,.Pin= GPIO_PIN6, .Mode = GPIO_ALTERNATE_FUNCTION,.AlternateMode = GPIO_ALTER_SPI1_4};
	GPIO_PinConfig_t SCK1  ={.Port = GPIO_PORTA,.Pin= GPIO_PIN5, .Mode = GPIO_ALTERNATE_FUNCTION,.AlternateMode = GPIO_ALTER_SPI1_4};
	GPIO_PinConfig_t NSS1  ={.Port = GPIO_PORTA,.Pin= GPIO_PIN4, .Mode = GPIO_ALTERNATE_FUNCTION,.AlternateMode = GPIO_ALTER_SPI1_4};
	GPIO_voidInit(&MOSI1);
	GPIO_voidInit(&MISO1);
	GPIO_voidInit(&SCK1);
	GPIO_voidInit(&NSS1);



	u16 Local_CR1REG = 0 ;
	Local_CR1REG |= ( (ptrToSPI_config->ClockPolarity)   << ClockPolarity_BIT   );
	Local_CR1REG |= ( (ptrToSPI_config->ClockPhase)      << ClockPhase_BIT      );
	Local_CR1REG |= ( (ptrToSPI_config->LSB_OR_MSB)      << LSBFirst_BIT        );
	Local_CR1REG |= ( (ptrToSPI_config->DataFrameFormat) << DataFrameFormat_BIT );
	Local_CR1REG |= ( 1 << SSM_BIT );   // FOR TFT
	Local_CR1REG |= ( 1 << SSI_BIT );   // FOR TFT
	switch(ptrToSPI_config->MasterSlave_Select)
	{
	case Master:
		Local_CR1REG |=( (ptrToSPI_config->MasterSlave_Select) << MasterSelection_BIT );
		Local_CR1REG |=( (ptrToSPI_config->CLK_Control)        << BR_ControlCLK_BIT   );
		break;
	case SLave:
		Local_CR1REG |=( (ptrToSPI_config->MasterSlave_Select) << MasterSelection_BIT );
		break;
	}
	Local_CR1REG |= ( 1<< SPIEable_BIT );
	SPI ->SPI_CR1 = Local_CR1REG;

}

u8 SPI_u8TransmitReceive(u8 Copy_u8SendData)
{

	SPI->SPI_DR = Copy_u8SendData;

	while(  GET_BIT( (SPI-> SPI_SR) , BusyFlag_BIT ) == 1 ) ;

	return SPI->SPI_DR ;

}


