/*
 * STK_program.c
 *
 *  Created on: Sep 6, 2023
 *      Author: alibo
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

static void (*Global_PtrToFun_Notification) (void) = NULL;
static u8 Global_u8PeriodicFlag ;
void STK_voidInitCLKSource(void)
{
#if   STK_CLOCK_SOURCE == STK_AHB_8
	CLR_BIT( (STK->STK_CTRL) , CLKSOURCE_BIT);

#elif STK_CLOCK_SOURCE == STK_AHB
	SET_BIT( (STK->STK_CTRL) , CLKSOURCE_BIT);
#endif

}
void STK_voidStartTimerSynch_BUSYWAIT(u32 Copy_u32Ticks)
{
	STK->STK_VAL = 0;
	STK->STK_LOAD = Copy_u32Ticks;
	CLR_BIT(  (STK->STK_CTRL) , TICKINT_BIT );
	SET_BIT(  (STK->STK_CTRL) , ENABLE_BIT  );
	while( ( GET_BIT( (STK->STK_CTRL) ,  FLAG_BIT ) ) == 0 );
	CLR_BIT(  (STK->STK_CTRL) , ENABLE_BIT );
}

void STK_voidStartTimerAsynch_IntervalPeriodic (u32 Copy_u32Ticks  , void(*Ptr_To_Fun)(void) )
{
	Global_PtrToFun_Notification = Ptr_To_Fun ;
	Global_u8PeriodicFlag = 1 ;
	SET_BIT(  (STK->STK_CTRL) , TICKINT_BIT );
	STK->STK_VAL = 0;
	STK->STK_LOAD = Copy_u32Ticks;
	SET_BIT(  (STK->STK_CTRL) , ENABLE_BIT  );
}


void STK_voidStartTimerAsynch_IntervalSingle(u32 Copy_u32Ticks , void(*Ptr_To_Fun)(void) )
{
	Global_PtrToFun_Notification = Ptr_To_Fun;
	Global_u8PeriodicFlag = 0;
	SET_BIT(  (STK->STK_CTRL) , TICKINT_BIT );
	STK->STK_VAL = 0;
	STK->STK_LOAD = Copy_u32Ticks;
	SET_BIT(  (STK->STK_CTRL) , ENABLE_BIT  );

}

u32 STK_u32GetElapsedTime(void)
{
	return ( (STK->STK_LOAD) - (STK->STK_VAL) );
}
u32 STK_u32GetRemainingTime(void)
{
	return (STK->STK_VAL) ;
}

void STK_voidStopTimer(void)
{
	CLR_BIT(  (STK->STK_CTRL) , ENABLE_BIT  );
}




void SysTick_Handler(void)
{
	if(Global_PtrToFun_Notification != NULL)
	{
		Global_PtrToFun_Notification();
	}
	if(Global_u8PeriodicFlag == 0)
	{
		Global_u8PeriodicFlag = 2 ;
		CLR_BIT(  (STK->STK_CTRL) , ENABLE_BIT  );
	}
}


