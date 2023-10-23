/*
 * LEDMATRIX_program.c
 *
 *  Created on: Sep 13, 2023
 *      Author: alibo
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"

#include "LEDMATRIX_interface.h"
#include "LEDMATRIX_private.h"
#include "LEDMATRIX_config.h"

void LEDMAT_voidInit(void)
{
	for(u8 local_counter=0 ; local_counter<8 ; local_counter++  )
	{
		GPIO_voidSetPinMode      ( ROW_PORT , local_counter , GPIO_OUTPUT );


		GPIO_voidSetPinMode      ( COL_PORTANDPINS_ARR[local_counter][0], COL_PORTANDPINS_ARR[local_counter][1] , GPIO_OUTPUT);
		GPIO_voidSetPinOutputType( COL_PORTANDPINS_ARR[local_counter][0], COL_PORTANDPINS_ARR[local_counter][1] , GPIO_OUTPUT_OPEN_DRAIN);
		GPIO_voidSetInputPull    ( COL_PORTANDPINS_ARR[local_counter][0], COL_PORTANDPINS_ARR[local_counter][1] , GPIO_PULL_UP );
	}
}

static void LEDMAT_voidDisableCOL(void)
{
	for(u8 local_counter=0 ; local_counter<8 ; local_counter++  )
	{
		GPIO_voidSetPinValueAtomic( COL_PORTANDPINS_ARR[local_counter][0], COL_PORTANDPINS_ARR[local_counter][1] , GPIO_PIN_HIGH);
	}
}


void LEDMAT_voidDispalyData(u8 *u8Ptr , u8 NumOfSeconds )
{

	for(u8 local_Time = 0 ; local_Time <50*NumOfSeconds ; local_Time ++ )
	{
		for(u8 local_counter = 0 ; local_counter < 8 ; local_counter ++)
		{

			LEDMAT_voidDisableCOL();
			GPIO_voidSetPortValue8Pins( ROW_PORT , u8Ptr[local_counter ]);
			GPIO_voidSetPinValueAtomic( COL_PORTANDPINS_ARR[local_counter][0], COL_PORTANDPINS_ARR[local_counter][1] , GPIO_PIN_LOW);
			STK_voidStartTimerSynch_BUSYWAIT(7812); // refer to 2.5 msec  in 25mhz
			// 2500  to 2.5 msec  in HSI DIV2
		}
	}
}
void LEDMAT_voidDisplayMovingData(u8 *u8Ptr , u8 ArrSize )
{
	u8 index = 0 ;
	for(u8 i = 0 ; i<ArrSize - 8 ; i++)
	{
		for(u8 local_Delay = 0 ; local_Delay < 10 ; local_Delay ++ )
		{
			for(u8 local_counter = 0 ; local_counter < 8 ; local_counter ++)
			{
				index = ( (i+local_counter) % ArrSize );

				LEDMAT_voidDisableCOL();
				GPIO_voidSetPortValue8Pins( ROW_PORT , u8Ptr[index]);
				GPIO_voidSetPinValueAtomic(COL_PORTANDPINS_ARR[local_counter][0], COL_PORTANDPINS_ARR[local_counter][1] , GPIO_PIN_LOW);
				STK_voidStartTimerSynch_BUSYWAIT(7812);
			}
		}
	}
}
