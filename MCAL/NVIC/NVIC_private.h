/*
 * NVIC_private.h
 *
 *  Created on: Sep 5, 2023
 *      Author: alibo
 */

#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_

#define VECTKEY               0x05FA0000

#define NVIC_BASE_ADDRESS     0xE000E100

typedef struct
{
	volatile u32 NVIC_ISER[32]; // 8 ISER used   24 unused
    volatile u32 NVIC_ICER[32];
    volatile u32 NVIC_ISPR[32];
    volatile u32 NVIC_ICPR[32];
    volatile u32 NVIC_IAPR[32];
    volatile u32 RESERVED [32];
    volatile u8  NVIC_IPR [128];// u8 to access the exact priority byte
}NVIC_MemMap_t;

#define NVIC          ( (volatile NVIC_MemMap_t*) NVIC_BASE_ADDRESS )

/*********************************************************************************************************************************/



            /* System Control Block*/
#define SCB_BASE_ADDRESS      0xE000ED00

typedef struct
{
	volatile u32 CPUID	 ;
	volatile u32 ICSR	 ;
	volatile u32 VTOR	 ;
	volatile u32 AIRCR   ;
	volatile u32 SCR	 ;
	volatile u32 CCR	 ;
	volatile u32 SHPR1	 ;
	volatile u32 SHPR2	 ;
	volatile u32 SHPR3	 ;
	volatile u32 SHCSR	 ;
	volatile u32 CFSR	 ;// MMSR(2) , BFSR(2) , UFSR(2)
	volatile u32 HFSR	 ;
	volatile u32 RESERVED;
	volatile u32 MMAR	 ;
	volatile u32 BFAR	 ;
	volatile u32 AFSR	 ;
}SCB_MemMap_t;

#define SCB		( (volatile SCB_MemMap_t *) SCB_BASE_ADDRESS)

#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
