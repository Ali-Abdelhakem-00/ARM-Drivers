/*
 * RCC_interface.h
 *
 *  Created on: Sep 3, 2023
 *      Author: alibo
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define RCC_AHB1     1
#define RCC_APB1     2
#define RCC_APB2     3
/* AHB PRESCALER */
#define RCC_AHB_NOTDIVIDED             0
#define RCC_AHB_DIV_BY2                1
#define RCC_AHB_DIV_BY4                2
#define RCC_AHB_DIV_BY8                3

/*  AHB1  PERIPHERAL      */
#define RCC_AHB1_GPIOA           0
#define RCC_AHB1_GPIOB           1
#define RCC_AHB1_GPIOC           2
#define RCC_AHB1_DMA1_EN         21
#define RCC_AHB1_DMA2_EN         22


/* APB2 PERIPHERAL  */
#define RCC_APB2_UART1           4
#define RCC_APB2_UART6           5
#define RCC_APB2_SPI1            12
#define RCC_APB2_SPI4            13
#define RCC_APB2_SYSCF           14

/*  APB1 PERIPHERAL */
#define RCC_APB1_UART2           17
#define RCC_APB1_TIMER2          0
#define RCC_APB1_TIMER3          1
#define RCC_APB1_TIMER4          2
#define RCC_APB1_TIMER5          3

void RCC_voidInit (void);

u8 RCC_u8StateEnablePeripheralClock (u8 Copy_u8BusId , u8 Copy_u8PeripheralId);

u8 RCC_u8StateDisablePeripheralClock (u8 Copy_u8BusId , u8 Copy_u8PeripheralId);

#endif /* RCC_INTERFACE_H_ */
