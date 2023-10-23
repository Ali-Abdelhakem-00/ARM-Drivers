/*
 * SERVO_program.c
 *
 *  Created on: Oct 4, 2023
 *      Author: alibo
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/TIMER/TIMER_interface.h"

#include "SERVO_interface.h"
#include "SERVO_private.h"
#include "SERVO_config.h"


void SERVO_voidInit(void)
{
	GPIO_PinConfig_t Timer4Ch4PIN = {.Port = GPIO_PORTB,.Pin = GPIO_PIN9 ,.Mode = GPIO_ALTERNATE_FUNCTION,.AlternateMode = GPIO_ALTER_TIM3_TIM5 };
	GPIO_voidInit(&Timer4Ch4PIN);

    TIMER4_voidInit();

}


void SERVO_u8SendAngle(u8 Copy_u8Angle)
{
	if( Copy_u8Angle >0 && Copy_u8Angle <=180)
	{
	u16 Local_CCRValue = ( (Copy_u8Angle + 45 ) * 100 ) / 9 ;
	TIMER4_u16SetCompareValue(Local_CCRValue);
	}
	else
	{
		TIMER4_u16SetCompareValue(500);
	}
}
