/*
 * NVIC_interface.h
 *
 *  Created on: Sep 5, 2023
 *      Author: alibo
 */

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

#define _4BitsGroup                  0b000
#define _3BitsGroup_1BitSub          0b100
#define _2BitsGroup_2BitsSub         0b101
#define _1BitGroup_3BitsSub          0b110
#define _4BitsSub                    0b111

/*  Copy_u8PriorityOption
 *
 * 1) _4BitsGroup
 * 2) _3BitsGroup_1BitSub
 * 3) _2BitsGroup_2BitsSub
 * 4) _4BitsSub
 */

typedef enum {
   NVIC_POS_WWDG                = 0 ,
   NVIC_POS_EXTI16              = 1 ,
   NVIC_POS_EXTI21              = 2 ,
   NVIC_POS_EXTI22              = 3 ,
   NVIC_POS_FLASH               = 4 ,
   NVIC_POS_RCC                 = 5 ,
   NVIC_POS_EXTI0               = 6 ,
   NVIC_POS_EXTI1               = 7 ,
   NVIC_POS_EXTI2               = 8 ,
   NVIC_POS_EXTI3               = 9 ,
   NVIC_POS_EXTI4               = 10,
   NVIC_POS_DMA1_STREAM0        = 11,
   NVIC_POS_DMA1_STREAM1        = 12,
   NVIC_POS_DMA1_STREAM2        = 13,
   NVIC_POS_DMA1_STREAM3        = 14,
   NVIC_POS_DMA1_STREAM4        = 15,
   NVIC_POS_DMA1_STREAM5        = 16,
   NVIC_POS_DMA1_STREAM6        = 17,
   NVIC_POS_ADC                 = 18,
   NVIC_POS_EXTI9_5             = 23,
   NVIC_POS_TIM1_BRK_TIM9       = 24,
   NVIC_POS_TIM1_UP_TIM10       = 25,
   NVIC_POS_TIM1_TRG_COM_TIM11  = 26,
   NVIC_POS_TIM1_CC             = 27,
   NVIC_POS_TIM2                = 28,
   NVIC_POS_TIM3                = 29,
   NVIC_POS_TIM4                = 30,
   NVIC_POS_I2C1_EV             = 31,
   NVIC_POS_I2C1_ER             = 32,
   NVIC_POS_I2C2_EV             = 33,
   NVIC_POS_I2C2_ER             = 34,
   NVIC_POS_SPI1                = 35,
   NVIC_POS_SPI2                = 36,
   NVIC_POS_USART1              = 37,
   NVIC_POS_USART2              = 38,
   NVIC_POS_EXTI15_10           = 40,
   NVIC_POS_EXTI17              = 41,
   NVIC_POS_EXTI18              = 42,
   NVIC_POS_DMA1_STREAM7        = 47,
   NVIC_POS_SDIO                = 49,
   NVIC_POS_TIM5                = 50,
   NVIC_POS_SPI3                = 51,
   NVIC_POS_DMA2_STREAM0        = 56,
   NVIC_POS_DMA2_STREAM1        = 57,
   NVIC_POS_DMA2_STREAM2        = 58,
   NVIC_POS_DMA2_STREAM3        = 59,
   NVIC_POS_DMA2_STREAM4        = 60,
   NVIC_POS_OTG_FS              = 67,
   NVIC_POS_DMA2_STREAM5        = 68,
   NVIC_POS_DMA2_STREAM6        = 69,
   NVIC_POS_DMA2_STREAM7        = 70,
   NVIC_POS_USART6              = 71,
   NVIC_POS_I2C3_EV             = 72,
   NVIC_POS_I2C3_ER             = 73,
   NVIC_POS_FPU                 = 81,
   NVIC_POS_SPI4                = 84,
}Peripheral_Postion_t;

void NVIC_voidEnableInterrupt    ( u8 Peripheral_Postion    );
void NVIC_voidDisableInterrupt   ( u8 Peripheral_Postion    );
void NVIC_voidEnablePendingFlag  ( u8 Peripheral_Postion    );
void NVIC_voidDisablePendingFlag ( u8 Peripheral_Postion    );
u8   NVIC_u8GETActiveFlag        ( u8 Peripheral_Postion    );
void NVIC_voidSetPariorityConfig    ( u8 Copy_u8PriorityOption );
void NVIC_voidSetPriority        ( u8 Peripheral_Postion , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority );


#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
