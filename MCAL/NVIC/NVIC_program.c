/*
 * NVIC_program.c
 *
 *  Created on: Sep 5, 2023
 *      Author: alibo
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

static u32  NVIC_u32GlobalProrityOption  ;

void NVIC_voidEnableInterrupt( u8 Peripheral_Postion )
{
	u8 NVIC_Register_NUM = Peripheral_Postion / 32 ;
	u8 INTERRUPT_BIT_NUM = Peripheral_Postion % 32 ;

	NVIC->NVIC_ISER[NVIC_Register_NUM]  =  ( 1 <<  INTERRUPT_BIT_NUM ) ;
}

void NVIC_voidDisableInterrupt   ( u8 Peripheral_Postion )
{
	u8 NVIC_Register_NUM = Peripheral_Postion / 32 ;
	u8 INTERRUPT_BIT_NUM = Peripheral_Postion % 32 ;

	NVIC->NVIC_ICER[NVIC_Register_NUM]  =  ( 1 <<  INTERRUPT_BIT_NUM ) ;
}
void NVIC_voidEnablePendingFlag ( u8 Peripheral_Postion )
{
	u8 NVIC_Register_NUM = Peripheral_Postion / 32 ;
	u8 INTERRUPT_BIT_NUM = Peripheral_Postion % 32 ;

	NVIC->NVIC_ISPR[NVIC_Register_NUM]  =  ( 1 <<  INTERRUPT_BIT_NUM ) ;
}

void NVIC_voidDisablePendingFlag ( u8 Peripheral_Postion )
{
	u8 NVIC_Register_NUM = Peripheral_Postion / 32 ;
	u8 INTERRUPT_BIT_NUM = Peripheral_Postion % 32 ;

	NVIC->NVIC_ICPR[NVIC_Register_NUM]  =  ( 1 <<  INTERRUPT_BIT_NUM ) ;
}


u8 NVIC_u8GETActiveFlag (u8 Peripheral_Postion)
{
	u8 Local_Return_Flag = 255;
	u8 NVIC_Register_NUM = Peripheral_Postion / 32 ;
	u8 INTERRUPT_BIT_NUM = Peripheral_Postion % 32 ;
	Local_Return_Flag = GET_BIT(  (NVIC->NVIC_IAPR[NVIC_Register_NUM]) , INTERRUPT_BIT_NUM );
	return Local_Return_Flag;

}

void NVIC_voidSetPariorityConfig    ( u8 Copy_u8PriorityOption)
{
	NVIC_u32GlobalProrityOption  =  VECTKEY | ( Copy_u8PriorityOption << 8 );
	SCB ->AIRCR = NVIC_u32GlobalProrityOption;
}

void NVIC_voidSetPriority        ( u8 Peripheral_Postion , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority )
{
	u8 Local_u8Priority = Copy_u8SubPriority | (Copy_u8GroupPriority << ((NVIC_u32GlobalProrityOption - 0x05FA0300)/256));


		NVIC->NVIC_IPR[Peripheral_Postion]  = Local_u8Priority << 4 ;

}

