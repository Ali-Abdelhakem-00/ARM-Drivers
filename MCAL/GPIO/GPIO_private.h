/*
 * GPIO_private.h
 *
 *  Created on: Sep 4, 2023
 *      Author: alibo
 */

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_

#define GPIOA_BASE_ADDRESS        0x40020000   //AHB1

#define GPIOB_BASE_ADDRESS        0x40020400   //AHB1

#define GPIOC_BASE_ADDRESS        0x40020800   //AHB1
typedef struct
{
	volatile u32 GPIO_MODER;
	volatile u32 GPIO_OTYPER;
	volatile u32 GPIO_OSPEEDR;
	volatile u32 GPIO_PUPDR;
	volatile u32 GPIO_IDR;
	volatile u32 GPIO_ODR;
	volatile u32 GPIO_BSRR;
	volatile u32 GPIO_LCKR;
	volatile u32 GPIO_AFRL;
	volatile u32 GPIO_AFRH;
}GPIO_MemMap_t;

#define GPIOA         ((volatile GPIO_MemMap_t*)  GPIOA_BASE_ADDRESS)
#define GPIOB         ((volatile GPIO_MemMap_t*)  GPIOB_BASE_ADDRESS)
#define GPIOC         ((volatile GPIO_MemMap_t*)  GPIOC_BASE_ADDRESS)
#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
