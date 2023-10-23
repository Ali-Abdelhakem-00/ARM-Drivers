/*
 * EXTI_private.h
 *
 *  Created on: Sep 5, 2023
 *      Author: alibo
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

#define EXTI_BASE_ADDRESS      0x40013C00
typedef struct
{
	volatile u32 EXTI_IMR   ;
	volatile u32 EXTI_EMR   ;
	volatile u32 EXTI_RTSR  ;
	volatile u32 EXTI_FTSR  ;
	volatile u32 EXTI_SWIER ;
	volatile u32 EXTI_PR    ;
}EXTI_MemMap_t;

#define EXTI        ( ( volatile EXTI_MemMap_t*)  EXTI_BASE_ADDRESS)

/*****************************************************************************************************/

#define SYSCFG_BASE_ADDRESS    0x40013800
typedef struct
{
	volatile u32 SYSCFG_MEMRMP   ;
	volatile u32 SYSCFG_PMC      ;
	volatile u32 SYSCFG_EXTICR[4];
	volatile u32 SYSCFG_CMPCR    ;
}SYSCFG_MemMap_t;

#define SYSCFG   ( ( volatile SYSCFG_MemMap_t*) SYSCFG_BASE_ADDRESS)


#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
