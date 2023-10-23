/*
 * STP_config.c
 *
 *  Created on: Sep 12, 2023
 *      Author: alibo
 */



#include "../../LIB/STD_TYPES.h"


#include "../../MCAL/GPIO/GPIO_interface.h"



GPIO_PinConfig_t DataSerial={
		.Port = GPIO_PORTA ,
		.Pin= GPIO_PIN0 ,
		.Mode = GPIO_OUTPUT ,
		.Output_Type =GPIO_OUTPUT_PUSH_PULL,
		.Output_Speed = GPIO_LOW_SPEED,
		.Pin_Value = GPIO_PIN_LOW
};

GPIO_PinConfig_t Shift={
		.Port = GPIO_PORTA ,
		.Pin= GPIO_PIN1 ,
		.Mode = GPIO_OUTPUT ,
		.Output_Type =GPIO_OUTPUT_PUSH_PULL,
		.Output_Speed = GPIO_LOW_SPEED,
		.Pin_Value = GPIO_PIN_LOW
};

GPIO_PinConfig_t Latch={
		.Port = GPIO_PORTA ,
		.Pin= GPIO_PIN2 ,
		.Mode = GPIO_OUTPUT ,
		.Output_Type =GPIO_OUTPUT_PUSH_PULL,
		.Output_Speed = GPIO_LOW_SPEED,
		.Pin_Value = GPIO_PIN_LOW
};
