/*
 * FMI_interface.h
 *
 *  Created on: Sep 25, 2023
 *      Author: alibo
 */

#ifndef MCAL_FLASH_FMI_INTERFACE_H_
#define MCAL_FLASH_FMI_INTERFACE_H_


void FMI_voidEraseSector(u8 SectorId);
void FMI_voidFlash(u32 Copy_u32Address ,  u16* Copy_Ptru16Data ,  u32 Copy_u32NumberOfElment);

#endif /* MCAL_FLASH_FMI_INTERFACE_H_ */
