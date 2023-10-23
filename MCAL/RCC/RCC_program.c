/*
 * RCC_program.c
 *
 *  Created on: Sep 3, 2023
 *      Author: alibo
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInit (void)
{
	// Clock security system ON
	SET_BIT( RCC->CR , CSSON_BIT );

	//BY pass select NOTbypass
	CLR_BIT( RCC->CR , HSEBYP_BIT );

	//select Prescaler

#if RCC_CLOCK_PRESCALER == RCC_AHB_DIV_BY2

	SET_BIT(RCC->CFGR  , 7);
#elif  RCC_CLOCK_PRESCALER == RCC_AHB_NOTDIVIDED
	CLR_BIT(RCC->CFGR  , 7);
#endif


	//Select clock source
#if    RCC_CLOCK_SOURCE == RCC_HSE_SELECT
	SET_BIT( RCC->CFGR , SW0 );
	CLR_BIT( RCC->CFGR , SW1 );
#elif  RCC_CLOCK_SOURCE == RCC_HSI_SELECT
	CLR_BIT( RCC->CFGR , SW0 );
	CLR_BIT( RCC->CFGR , SW1 );
#elif  RCC_CLOCK_SOURCE == RCC_PLL_SELECT
	CLR_BIT( RCC->CFGR , SW0 );
	SET_BIT( RCC->CFGR , SW1 );
#endif



	//Enable Clock source
#if    RCC_HSI_ENABLE == ENABALE
	SET_BIT( RCC->CR , HSION_BIT );
#elif  RCC_HSI_ENABLE == DISABLE
	CLR_BIT( RCC->CR , HSION_BIT );
#endif

#if    RCC_HSE_ENABLE == ENABALE
	SET_BIT( RCC->CR , HSEON_BIT );
#elif  RCC_HSE_ENABLE == DISABLE
	CLR_BIT( RCC->CR , HSEON_BIT );
#endif

#if    RCC_PLL_ENABLE == ENABALE
	SET_BIT( RCC->CR , PLLON_BIT );
#elif  RCC_PLL_ENABLE == DISABLE
	CLR_BIT( RCC->CR , PLLON_BIT );
#endif

}

u8 RCC_u8StateEnablePeripheralClock (u8 Copy_u8BusId , u8 Copy_u8PeripheralId)
{
	u8 local_state = STD_OK;
	if( (Copy_u8BusId <= RCC_APB2)  && ( Copy_u8PeripheralId <32) )
	{
		switch(Copy_u8BusId)
		{
		case RCC_AHB1:
			SET_BIT( RCC->AHB1ENR  , Copy_u8PeripheralId );
			break;

		case RCC_APB1:
			SET_BIT( RCC->APB1ENR  , Copy_u8PeripheralId );
			break;

		case RCC_APB2:
			SET_BIT( RCC->APB2ENR  , Copy_u8PeripheralId );
			break;

		default :
			local_state = STD_NOTOK;
			break;
		}
	}
	else
	{
		local_state = STD_NOTOK;
	}
	return local_state;
}


u8 RCC_u8StateDisablePeripheralClock (u8 Copy_u8BusId , u8 Copy_u8PeripheralId)
{
	u8 local_state = STD_OK;
	if( (Copy_u8BusId <= RCC_APB2)  && ( Copy_u8PeripheralId <32) )
	{
		switch(Copy_u8BusId)
		{
		case RCC_AHB1:
			CLR_BIT( RCC->AHB1ENR  , Copy_u8PeripheralId );
			break;

		case RCC_APB1:
			CLR_BIT( RCC->APB1ENR  , Copy_u8PeripheralId );
			break;

		case RCC_APB2:
			CLR_BIT( RCC->APB2ENR  , Copy_u8PeripheralId );
			break;

		default :
			local_state = STD_NOTOK;
			break;
		}
	}
	else
	{
		local_state = STD_NOTOK;
	}
	return local_state;
}


