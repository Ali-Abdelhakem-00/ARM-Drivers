/*
 * FMI_private.h
 *
 *  Created on: Sep 25, 2023
 *      Author: alibo
 */

#ifndef MCAL_FLASH_FMI_PRIVATE_H_
#define MCAL_FLASH_FMI_PRIVATE_H_

#define FLASH_BASE_ADDRESS  0x40023C00
#define KEY1  0x45670123
#define KEY2  0xCDEF89AB




typedef struct
{
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 OPTCR;
}FMI_MemMap_t;

#define FLASH        ( (volatile FMI_MemMap_t*)  FLASH_BASE_ADDRESS)

#endif /* MCAL_FLASH_FMI_PRIVATE_H_ */
