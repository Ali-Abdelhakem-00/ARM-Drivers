/*
 * EXTI_interface.h
 *
 *  Created on: Sep 5, 2023
 *      Author: alibo
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

typedef enum
{
	EXTI_SENSE_RISING_TRIGGER,
	EXTI_SENSE_FALLING_TRIGGER,
	EXTI_SENSE_ON_CHANGE
}EXTI_Sense_Mode_t;

typedef enum
{
EXTI_PORTA,
EXTI_PORTB,
EXTI_PORTC
}EXTI_Port_t;
typedef enum
{
	EXTI_LINE0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15,
}EXTI_NUM_t;

void EXTI_voidEnableInterrupt            (u8 EXTI_Port , u8 EXTI_Num , EXTI_Sense_Mode_t InterruptSenseMode);
void EXTI_voidEnableEvent                (u8 EXTI_Port , u8 EXTI_Num , EXTI_Sense_Mode_t EventSenseMode);
void EXTI_voidChangeSenseMode            (u8 EXTI_Num  , EXTI_Sense_Mode_t SenseMode);
void EXTI_voidEnableSoftwareInterrupt_PIF(u8 EXTI_Num );
void  EXTI_voidSetCallBack(u8 Copy_InterruptId,void (*PF)(void));
/*u8 EXTI_u8GetPIF                         (u8 EXTI_Port , u8 EXTI_Num );*/

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
