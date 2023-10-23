/*
 * LED_interface.h
 *
 *  Created on: Aug 3, 2023
 *      Author: alibo
 */

#ifndef HAL_LED_INTERFACE_H_
#define HAL_LED_INTERFACE_H_



//SET_PIN_DIRECTION already done in LED_voidInit

#define ACTIVE_HIGH   1
#define ACTIVE_LOW    0

typedef struct
{
	u8 Port;
	u8 Pin;
    u8 Active_State;
}LED_Type;



void LED_voidInit             (LED_Type *copy_ptrToStruct);
void LED_voidON               (LED_Type *copy_ptrToStruct);
void LED_voidOFF              (LED_Type *copy_ptrToStruct);
void LED_viodLedsFlashing     (LED_Type *copy_ptrToStruct);
void LED_voidShiftingLeft     (LED_Type *copy_ptrToStruct);
void LED_voidShiftingRight    (LED_Type *copy_ptrToStruct);
void LED_void2LEDSConverging  (LED_Type *copy_ptrToStruct);
void LED_void2LEDSDiverging   (LED_Type *copy_ptrToStruct);
void LED_voidLEDS_ConvAndDive (LED_Type *copy_ptrToStruct);
void LED_voidPingPong         (LED_Type *copy_ptrToStruct);
void LED_voidIncrementing     (LED_Type *copy_ptrToStruct);
#endif /* HAL_LED_INTERFACE_H_ */
