/*
 * IR_program.c
 *
 *  Created on: Sep 16, 2023
 *      Author: alibo
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"
#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"

volatile u8 Global_u32Counter=0;
volatile u8 FrameFlag=0;
volatile u8 data=0;
volatile u32 Frame[40]={0};

void IR_Get_Data (void)
{

	for(u8 counter=0; counter<8 ; counter++)
	{
		if( (Frame[17+counter] >= 2000) && (Frame[17+counter] < 2500) )
		{
			SET_BIT(data, counter);
		}
		else
		{
			CLR_BIT(data, counter);
		}
	}
	IR_APP(data);

	FrameFlag = 0;
	Global_u32Counter=0;
}

void IR_Get_Frame(void)
{

	if(FrameFlag==0)
	{
		STK_voidStartTimerAsynch_IntervalSingle(10000,IR_Get_Data);
		FrameFlag=1;
	}else
	{
		Frame[Global_u32Counter]=STK_u32GetElapsedTime();
		STK_voidStartTimerAsynch_IntervalSingle(10000,IR_Get_Data);
		Global_u32Counter++;
	}
}
