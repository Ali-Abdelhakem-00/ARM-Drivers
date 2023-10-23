/*
 * FMI_program.c
 *
 *  Created on: Sep 25, 2023
 *      Author: alibo
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "FMI_interface.h"
#include "FMI_private.h"
#include "FMI_config.h"


void FMI_voidEraseSector(u8 SectorId)
{
	/*wait bsy flag*/

	while( GET_BIT(FLASH->SR , 16) == 1);


	/* unlock flash reg key*/
	while( GET_BIT(FLASH->CR , 31) == 1)
	{
		FLASH->KEYR = KEY1 ;
		FLASH->KEYR = KEY2 ;
	}

	/*  select sector   */
	FLASH->CR &= ( ~((0b1111) << 3) );
	FLASH->CR |= (  SectorId  << 3  );

	/*ACTIVATE sector */
	SET_BIT( FLASH->CR , 1);

	/* start*/
	SET_BIT( FLASH->CR , 16);
	while( GET_BIT(FLASH->SR , 16) == 1 );

	/* stop Erassing*/
	CLR_BIT( FLASH->CR , 1);

	/*END of Operation*/
	SET_BIT( FLASH->SR , 0);
}


void FMI_voidFlash(u32 Copy_u32Address ,  u16* Copy_Ptru16Data ,  u32 Copy_u32NumberOfElment)
{
	// assume u16 data

	/*wait bsy flag*/
	while( GET_BIT(FLASH->SR , 16) );

	/* unlock flash reg key*/
	while( GET_BIT(FLASH->CR , 31) == 1)
	{
		FLASH->KEYR = KEY1 ;
		FLASH->KEYR = KEY2 ;
	}


	FLASH->CR &= ~( (0b11) << 8 ) ;
	FLASH->CR |=  ( (0b01) << 8 ) ;// assume u16 data

	/* Programming =1*/
	SET_BIT( (FLASH->CR) , 0 );


	for(u32 counter = 0 ; counter < Copy_u32NumberOfElment ; counter++ )
	{
		*( (volatile u16*)(Copy_u32Address) ) = Copy_Ptru16Data[counter] ;
		Copy_u32Address += 2;
		while( GET_BIT(FLASH->SR , 16) );
		SET_BIT( FLASH->SR , 0);
	}

	/* stop programming */
	CLR_BIT( FLASH->CR , 0);


}
