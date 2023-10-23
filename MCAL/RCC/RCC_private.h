/*
 * RCC_private.h
 *
 *  Created on: Sep 3, 2023
 *      Author: alibo
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#define  SW0          0
#define  SW1          1


#define ENABALE             1
#define DISABLE             0

#define HSION_BIT               0
#define HSEON_BIT               16
#define HSEBYP_BIT              18 // bypass
#define CSSON_BIT               19
#define PLLON_BIT               24

#define RCC_HSE_SELECT      0
#define RCC_HSI_SELECT      1
#define RCC_PLL_SELECT      2

#define RCC_BASE_ADDRESS      0x40023800

typedef struct
{
	volatile u32 CR;
	volatile u32 PLLCFGR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 AHB1RSTR;
	volatile u32 AHB2RSTR;
	volatile u32 RESERVED1;
	volatile u32 RESERVED2;
	volatile u32 APB1RSTR;
	volatile u32 APB2RSTR;
	volatile u32 RESERVED3;
	volatile u32 RESERVED4;
	volatile u32 AHB1ENR;
	volatile u32 AHB2ENR;
	volatile u32 RESERVED5;
	volatile u32 RESERVED6;
	volatile u32 APB1ENR;
	volatile u32 APB2ENR;
	volatile u32 RESERVED7;
	volatile u32 RESERVED8;
	volatile u32 AHB1LPENR;
	volatile u32 AHB2LPENR;
	volatile u32 RESERVED9;
	volatile u32 RESERVED10;
	volatile u32 APB1LPENR;
	volatile u32 APB2LPENR;
	volatile u32 RESERVED11;
	volatile u32 RESERVED12;
	volatile u32 BDCR;
	volatile u32 CSR;
	volatile u32 RESERVED13;
	volatile u32 RESERVED14;
	volatile u32 SSCGR;
	volatile u32 PLLI2SCFGR;
	volatile u32 RESERVED15;
	volatile u32 DCKCFGR;
}RCC_MemMap_t;

#define RCC    ( (volatile  RCC_MemMap_t *)RCC_BASE_ADDRESS )

#endif /* RCC_PRIVATE_H_ */
