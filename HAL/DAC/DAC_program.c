/*
 * DAC_program.c
 *
 *  Created on: Sep 13, 2023
 *      Author: alibo
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"
#include "../../song2.h"
#include "DAC_interface.h"

void DAC_voidInit(void)
{
	GPIO_voidSetPortMode(GPIO_PORTA , GPIO_OUTPUT);
}
void DAC_voidSendData(void)
{
	static u32 local_counter = 0 ;
	GPIO_voidSetPortValue(GPIO_PORTA , song_raw[local_counter] );
	local_counter++ ;
	if ( local_counter == song_raw_len)
	{
		local_counter = 0 ;
	}

}

