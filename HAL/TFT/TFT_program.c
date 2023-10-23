/*
 * TFT_program.c
 *
 *  Created on: Sep 19, 2023
 *      Author: alibo
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"
#include "../../MCAL/SPI/SPI_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

static void TFT_SendCommand(u8 Copy_u8Value)
{
	GPIO_voidSetPinValueAtomic( TFT_A0_PORT , TFT_A0_PIN , GPIO_PIN_LOW);
	SPI_u8TransmitReceive(Copy_u8Value);
}
static void TFT_SendData   (u8 Copy_u8Value)
{
	GPIO_voidSetPinValueAtomic( TFT_A0_PORT , TFT_A0_PIN , GPIO_PIN_HIGH);
	SPI_u8TransmitReceive(Copy_u8Value);
}
void TFT_voidInit(void)
{
	GPIO_PinConfig_t ResetPin ={.Port = GPIO_PORTA ,.Pin= GPIO_PIN1, .Mode = GPIO_OUTPUT };
	GPIO_PinConfig_t A0Pin    ={.Port = GPIO_PORTA ,.Pin= GPIO_PIN0, .Mode = GPIO_OUTPUT };
	GPIO_voidInit(&ResetPin);
	GPIO_voidInit(&A0Pin);

	//RESET PULSE
	GPIO_voidSetPinValueAtomic( TFT_RESET_PORT, TFT_RESET_PIN, GPIO_PIN_HIGH);
	STK_voidStartTimerSynch_BUSYWAIT(100);

	GPIO_voidSetPinValueAtomic( TFT_RESET_PORT, TFT_RESET_PIN, GPIO_PIN_LOW);
	STK_voidStartTimerSynch_BUSYWAIT(1);

	GPIO_voidSetPinValueAtomic( TFT_RESET_PORT, TFT_RESET_PIN, GPIO_PIN_HIGH);
	STK_voidStartTimerSynch_BUSYWAIT(100);

	GPIO_voidSetPinValueAtomic( TFT_RESET_PORT, TFT_RESET_PIN, GPIO_PIN_LOW);
	STK_voidStartTimerSynch_BUSYWAIT(100);

	GPIO_voidSetPinValueAtomic( TFT_RESET_PORT, TFT_RESET_PIN, GPIO_PIN_HIGH);
	STK_voidStartTimerSynch_BUSYWAIT(120000);

	// SLEEPOUT MODE
	TFT_SendCommand(0x11);

	// WAIT 150 msec
	STK_voidStartTimerSynch_BUSYWAIT(150000);

	//COLO MODE
	TFT_SendCommand(0x3A);;
	TFT_SendData(0x05);
	//DISPLAY ON
	TFT_SendCommand(0x29);
}

void TFT_voidDisplayImage(const  u16*Ptr_u16Image)
{
	// set x address
	TFT_SendCommand(0x2A);

	TFT_SendData(0);
	TFT_SendData(0);
	TFT_SendData(0);
	TFT_SendData(127);

	//set y address
	TFT_SendCommand(0x2B);

	TFT_SendData(0);
	TFT_SendData(0);
	TFT_SendData(0);
	TFT_SendData(159);

	// Ram Write
	TFT_SendCommand(0x2C);

	u8 data ;
	for( u16 local_u16counter= 0 ; local_u16counter < 20480 ; local_u16counter++ )
	{
		data = Ptr_u16Image[local_u16counter] >> 8  ;
		TFT_SendData(data);
		data = Ptr_u16Image[local_u16counter] ;
		TFT_SendData(data);
	}
}


void TFT_voidFillColor(u16 Copy_u16Color)
{
	// set x address
	TFT_SendCommand(0x2A);

	TFT_SendData(0);
	TFT_SendData(0);
	TFT_SendData(0);
	TFT_SendData(127);

	//set y address
	TFT_SendCommand(0x2B);

	TFT_SendData(0);
	TFT_SendData(0);
	TFT_SendData(0);
	TFT_SendData(159);

	// Ram Write
	TFT_SendCommand(0x2C);

	u8 data ;
	for( u16 local_u16counter= 0 ; local_u16counter < 20480 ; local_u16counter++ )
	{
		data = Copy_u16Color ;
		TFT_SendData(data);
		data = Copy_u16Color ;
		TFT_SendData(data);
	}

}
