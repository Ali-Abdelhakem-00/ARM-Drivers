/*
 * STP_program.c
 *
 *  Created on: Sep 12, 2023
 *      Author: alibo
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"
#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

extern GPIO_PinConfig_t DataSerial ;
extern GPIO_PinConfig_t Shift ;
extern GPIO_PinConfig_t Latch ;


void STP_voidInit(void)
{

	GPIO_voidInit(&DataSerial);
	GPIO_voidInit(&Shift);
	GPIO_voidInit(&Latch);

}
void STP_voidShift(void)
{
	GPIO_voidSetPinValueAtomic(Shift.Port , Shift.Pin , GPIO_PIN_HIGH );
	STK_voidStartTimerSynch_BUSYWAIT(1);
	GPIO_voidSetPinValueAtomic(Shift.Port , Shift.Pin , GPIO_PIN_LOW );
	STK_voidStartTimerSynch_BUSYWAIT(1);
}


void STP_voidLatch(void)
{
	GPIO_voidSetPinValueAtomic(Latch.Port , Latch.Pin , GPIO_PIN_HIGH );
	STK_voidStartTimerSynch_BUSYWAIT(1);
	GPIO_voidSetPinValueAtomic(Latch.Port , Latch.Pin , GPIO_PIN_LOW );
	STK_voidStartTimerSynch_BUSYWAIT(1);

}
void STP_voidSendDataWithArr( u8 *PtrToData  , u8 CopyRegisterNum )
{
	for(u8 local_counter = 0 ; local_counter < 8 * CopyRegisterNum ; local_counter++ )
	{

		GPIO_voidSetPinValueAtomic( DataSerial.Port , DataSerial.Pin , GET_BIT( PtrToData[local_counter/8] , local_counter%8) );
		STP_voidShift();
	}
	STP_voidLatch();
}
void STP_voidSendData( u32 Data )
{
	for(u8 local_counter = 0 ; local_counter < 8 * NUMBER_OF_REGISTERS ; local_counter++ )
	{

		GPIO_voidSetPinValueAtomic( DataSerial.Port , DataSerial.Pin , GET_BIT( Data , local_counter) );
		STP_voidShift();
	}
	STP_voidLatch();
}

