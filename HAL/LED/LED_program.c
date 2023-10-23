/*
 * LED_program.c
 *
 *  Created on: Aug 3, 2023
 *      Author: alibo
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

#include"../../MCAL/GPIO/GPIO_interface.h"
#include"LED_interface.h"

#define ARM_DELAY(d)             do{ u32 i=d ; while(i--) { asm ("NOP"); } } while(0);
void LED_voidInit  (LED_Type *copy_ptrToStruct)
{
	GPIO_voidSetPinMode( (copy_ptrToStruct->Port) , (copy_ptrToStruct->Pin) , GPIO_OUTPUT);
	switch (copy_ptrToStruct -> Active_State)
	{
	case ACTIVE_HIGH:
		GPIO_voidSetPinValueAtomic ((copy_ptrToStruct->Port) , (copy_ptrToStruct->Pin), GPIO_PIN_LOW);
		break;

	case ACTIVE_LOW:
		GPIO_voidSetPinValueAtomic ((copy_ptrToStruct->Port) , (copy_ptrToStruct->Pin), GPIO_PIN_HIGH);
		break;
	default:
		break;
	}
}



void LED_voidON    (LED_Type *copy_ptrToStruct)
{
	switch (copy_ptrToStruct -> Active_State)
	{
	case ACTIVE_HIGH:
		GPIO_voidSetPinValueAtomic ( (copy_ptrToStruct->Port) , (copy_ptrToStruct->Pin) , GPIO_PIN_HIGH);
		break;


	case ACTIVE_LOW:
		GPIO_voidSetPinValueAtomic ( (copy_ptrToStruct->Port) , (copy_ptrToStruct->Pin), GPIO_PIN_LOW);
		break;
	default:
		break;
	}

}


void LED_voidOFF   (LED_Type *copy_ptrToStruct)
{
	switch (copy_ptrToStruct -> Active_State)
	{
	case ACTIVE_HIGH:
		GPIO_voidSetPinValueAtomic ( (copy_ptrToStruct->Port) , (copy_ptrToStruct->Pin), GPIO_PIN_LOW);
		break;


	case ACTIVE_LOW:
		GPIO_voidSetPinValueAtomic ( (copy_ptrToStruct->Port) , (copy_ptrToStruct->Pin) , GPIO_PIN_HIGH);
		break;
	default:
		break;
	}
}


void LED_viodLedsFlashing(LED_Type *copy_ptrToStruct)
{
	for(u8 local_counter=0; local_counter<8; local_counter++ )
	{
		LED_voidON(&copy_ptrToStruct[local_counter]);
	}
	ARM_DELAY(1000000);

	for(u8 local_counter=0; local_counter<8; local_counter++ )
	{
		LED_voidOFF(&copy_ptrToStruct[local_counter]);
	}
	ARM_DELAY(1000000);
	/*GPIO_voidSetPortValueAtomic( (copy_ptrToStruct->Port) , 65535);
	ARM_DELAY(1000000);
	GPIO_voidSetPortValueAtomic( (copy_ptrToStruct->Port) , 0  );
	ARM_DELAY(1000000);*/
}


void LED_voidShiftingLeft(LED_Type *copy_ptrToStruct)
{
	for(u8 Local_counter = 0 ;  Local_counter< 8 ; Local_counter ++)
	{

		LED_voidON ( &copy_ptrToStruct[Local_counter] );
		ARM_DELAY(1000000);
		LED_voidOFF( &copy_ptrToStruct[Local_counter] );
	}
}


void LED_voidShiftingRight(LED_Type *copy_ptrToStruct)
{
	for(u8 Local_counter = 8 ;  Local_counter>0 ; Local_counter --)
	{
		LED_voidON ( &copy_ptrToStruct[Local_counter-1] );
		ARM_DELAY(1000000);
		LED_voidOFF( &copy_ptrToStruct[Local_counter-1] );
	}
}

void LED_void2LEDSConverging(LED_Type *copy_ptrToStruct)
{//7 0        61   52  43
	for(u8 Local_counter = 0 ;  Local_counter< 4 ; Local_counter ++)
	{

		LED_voidON ( &copy_ptrToStruct[Local_counter] );
		LED_voidON ( &copy_ptrToStruct[7-Local_counter] );
		ARM_DELAY(1000000);
		LED_voidOFF ( &copy_ptrToStruct[Local_counter] );
		LED_voidOFF ( &copy_ptrToStruct[7-Local_counter] );
	}
}
void LED_void2LEDSDiverging (LED_Type *copy_ptrToStruct)
{
	for(u8 Local_counter = 0 ;  Local_counter< 4 ; Local_counter ++)
	{

		LED_voidON ( &copy_ptrToStruct[ (Local_counter+4)] );
		LED_voidON ( &copy_ptrToStruct[ (3-Local_counter)] );
		ARM_DELAY(1000000);
		LED_voidOFF ( &copy_ptrToStruct[ (Local_counter+4)] );
		LED_voidOFF ( &copy_ptrToStruct[ (3-Local_counter)] );
	}

}
void LED_voidLEDS_ConvAndDive(LED_Type *copy_ptrToStruct)
{
	for(u8 Local_counter = 0 ;  Local_counter< 4 ; Local_counter ++)
	{

		LED_voidON ( &copy_ptrToStruct[Local_counter] );
		LED_voidON ( &copy_ptrToStruct[7-Local_counter] );
		ARM_DELAY(1000000);
		LED_voidOFF ( &copy_ptrToStruct[Local_counter] );
		LED_voidOFF ( &copy_ptrToStruct[7-Local_counter] );
	}
	for(u8 Local_counter = 0 ;  Local_counter< 4 ; Local_counter ++)
	{

		LED_voidON ( &copy_ptrToStruct[ (Local_counter+4)] );
		LED_voidON ( &copy_ptrToStruct[ (3-Local_counter)] );
		ARM_DELAY(1000000);
		LED_voidOFF ( &copy_ptrToStruct[ (Local_counter+4)] );
		LED_voidOFF ( &copy_ptrToStruct[ (3-Local_counter)] );
	}
}

void LED_voidPingPong(LED_Type *copy_ptrToStruct)
{
	for(u8 Local_counter = 0 ;  Local_counter< 8 ; Local_counter ++)
	{

		LED_voidON ( &copy_ptrToStruct[Local_counter] );
		ARM_DELAY(1000000);
		LED_voidOFF( &copy_ptrToStruct[Local_counter] );
	}
	for(u8 Local_counter = 8 ;  Local_counter>0 ; Local_counter --)
	{
		LED_voidON ( &copy_ptrToStruct[Local_counter-1] );
		ARM_DELAY(1000000);
		LED_voidOFF( &copy_ptrToStruct[Local_counter-1] );
	}
}
void LED_voidIncrementing(LED_Type *copy_ptrToStruct)
{
	for(u8 Local_counter = 0 ;  Local_counter< 8 ; Local_counter ++)
	{
		LED_voidON ( &copy_ptrToStruct[Local_counter] );
		ARM_DELAY(1000000);
	}
}
