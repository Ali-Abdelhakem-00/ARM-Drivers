/*
 * ssd_program.c
 *
 *  Created on: Aug 4, 2023
 *      Author: alibo
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

#include"../../MCAL/GPIO/GPIO_interface.h"
#include"ssd_interface.h"
#define ARM_DELAY(d)             do{ u32 i=d ; while(i--) { asm ("NOP"); } } while(0);


void SSD_void_Init   (SSD_Type * u8_copy_ptr_to_StructSSD)
{
	 GPIO_voidSetPortMode( ( u8_copy_ptr_to_StructSSD->SSD_port) , GPIO_OUTPUT);
	switch(u8_copy_ptr_to_StructSSD-> common_state)
	{
	case state_anode:
		GPIO_voidSetPortValue( (u8_copy_ptr_to_StructSSD->SSD_port) , 0xffff );
		break;

	case state_cathode:
		GPIO_voidSetPortValue( (u8_copy_ptr_to_StructSSD->SSD_port) , 0x0000 );
		break;

	default:break;
	}

}
void SSD_void_Enable (SSD_Type   *u8_copy_ptr_to_StructSSD,u8 copy_number)
{
	switch(u8_copy_ptr_to_StructSSD-> common_state)
	{
	case state_anode:
		GPIO_voidSetPortValue( (u8_copy_ptr_to_StructSSD->SSD_port) , numbers_arr[copy_number] );

		break;

	case state_cathode:
		GPIO_voidSetPortValue( (u8_copy_ptr_to_StructSSD->SSD_port) , ~numbers_arr[copy_number] );
		break;

	default:break;
	}

}
void SSD_void_Disable(SSD_Type   *u8_copy_ptr_to_StructSSD)
{
	switch(u8_copy_ptr_to_StructSSD-> common_state)
	{
	case state_anode:
		GPIO_voidSetPortValue( (u8_copy_ptr_to_StructSSD->SSD_port) , 0xffff );
		break;

	case state_cathode:
		GPIO_voidSetPortValue( (u8_copy_ptr_to_StructSSD->SSD_port) , 0x0000 );
		break;

	default:break;
	}

}


void SSD_void_DisplayNumber_2SSD_SamePort (SSD_Type *copy_p_SSD_Type_1Anode ,  SSD_Type *copy_p_SSD_Type_2Cathod , u8 copy_number)
{
  int left = (copy_number/10);
  int right = (copy_number%10);
  GPIO_voidSetPinValueAtomic( (copy_p_SSD_Type_2Cathod->SSD_port) , GPIO_PIN7 , GPIO_PIN_LOW) ;
  SSD_void_Enable(  copy_p_SSD_Type_2Cathod , right );
  ARM_DELAY(100000);
  GPIO_voidSetPinValueAtomic( (copy_p_SSD_Type_1Anode->SSD_port) , GPIO_PIN7 , GPIO_PIN_HIGH) ;
	SSD_void_Enable( copy_p_SSD_Type_1Anode ,left );
	 ARM_DELAY(1000);

}

