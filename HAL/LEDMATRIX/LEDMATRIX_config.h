/*
 * LEDMATRIX_config.h
 *
 *  Created on: Sep 13, 2023
 *      Author: alibo
 */


#ifndef HAL_LEDMATRIX_LEDMATRIX_CONFIG_H_
#define HAL_LEDMATRIX_LEDMATRIX_CONFIG_H_

#define ROW_PORT              GPIO_PORTA


#define COL_PORT_PINB0               GPIO_PORTB  , GPIO_PIN0
#define COL_PORT_PINB1               GPIO_PORTB  , GPIO_PIN1

#define COL_PORT_PINA8               GPIO_PORTB  , GPIO_PIN2
#define COL_PORT_PINA9               GPIO_PORTB  , GPIO_PIN3
#define COL_PORT_PINA10              GPIO_PORTB  , GPIO_PIN4
#define COL_PORT_PINA11              GPIO_PORTB  , GPIO_PIN5
#define COL_PORT_PINA12              GPIO_PORTB  , GPIO_PIN6
#define COL_PORT_PINA15              GPIO_PORTB  , GPIO_PIN7


u8 COL_PORTANDPINS_ARR  [8][2] =
{
		{COL_PORT_PINB0},
		{COL_PORT_PINB1},
		{COL_PORT_PINA8},
		{COL_PORT_PINA9},
		{COL_PORT_PINA10},
		{COL_PORT_PINA11},
		{COL_PORT_PINA12},
		{COL_PORT_PINA15},
};


#endif /* HAL_LEDMATRIX_LEDMATRIX_CONFIG_H_ */
