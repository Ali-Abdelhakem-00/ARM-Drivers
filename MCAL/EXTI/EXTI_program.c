/*
 * EXTI_program.c
 *
 *  Created on: Sep 5, 2023
 *      Author: alibo
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (*PF_Notification[16]) (void) ={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
void EXTI_voidEnableInterrupt (u8 EXTI_Port , u8 EXTI_Num , EXTI_Sense_Mode_t InterruptSenseMode)
{

	SYSCFG ->SYSCFG_EXTICR[ (EXTI_Num/4) ] &=  ~(  0b1111    <<   4*( EXTI_Num  % 4 )  );
	SYSCFG ->SYSCFG_EXTICR[ (EXTI_Num/4) ] |=   (  EXTI_Port <<   4*( EXTI_Num  % 4 )  );

	EXTI->EXTI_IMR |= ( 1 << EXTI_Num );

	if(InterruptSenseMode == EXTI_SENSE_RISING_TRIGGER )
	{
	    SET_BIT(  (EXTI ->EXTI_RTSR ) , (EXTI_Num) );
	}
	else if (InterruptSenseMode == EXTI_SENSE_FALLING_TRIGGER)
	{
		SET_BIT(  (EXTI ->EXTI_FTSR ) , (EXTI_Num) );
	}
	else if(InterruptSenseMode == EXTI_SENSE_ON_CHANGE )
	{
		SET_BIT(  (EXTI ->EXTI_RTSR ) , (EXTI_Num) );
		SET_BIT(  (EXTI ->EXTI_FTSR ) , (EXTI_Num) );
	}
}
void EXTI_voidEnableEvent     (u8 EXTI_Port , u8 EXTI_Num , EXTI_Sense_Mode_t EventSenseMode)
{
	SYSCFG ->SYSCFG_EXTICR[ (EXTI_Num/4) ] &=  ~(  0b1111    <<   4*( EXTI_Num  % 4 )  );
	SYSCFG ->SYSCFG_EXTICR[ (EXTI_Num/4) ] |=   (  EXTI_Port <<   4*( EXTI_Num  % 4 )  );

	EXTI->EXTI_EMR |= ( 1 << EXTI_Num);

	if(EventSenseMode == EXTI_SENSE_RISING_TRIGGER )
	{
		SET_BIT(  (EXTI ->EXTI_RTSR ) , (EXTI_Num) );
		CLR_BIT(  (EXTI ->EXTI_FTSR ) , (EXTI_Num) );
	}
	else if (EventSenseMode == EXTI_SENSE_FALLING_TRIGGER)
	{
		SET_BIT(  (EXTI ->EXTI_FTSR ) , (EXTI_Num) );
		CLR_BIT(  (EXTI ->EXTI_RTSR ) , (EXTI_Num) );
	}
	else if(EventSenseMode == EXTI_SENSE_ON_CHANGE )
	{
		SET_BIT(  (EXTI ->EXTI_RTSR ) , (EXTI_Num) );
		SET_BIT(  (EXTI ->EXTI_FTSR ) , (EXTI_Num) );
	}
}

void EXTI_voidChangeSenseMode          ( u8 EXTI_Num , EXTI_Sense_Mode_t SenseMode)
{
	if(SenseMode == EXTI_SENSE_RISING_TRIGGER )
	{
		SET_BIT(  (EXTI ->EXTI_RTSR ) , (EXTI_Num) );
		CLR_BIT(  (EXTI ->EXTI_FTSR ) , (EXTI_Num) );
	}
	else if (SenseMode == EXTI_SENSE_FALLING_TRIGGER)
	{
		SET_BIT(  (EXTI ->EXTI_FTSR ) , (EXTI_Num) );
		CLR_BIT(  (EXTI ->EXTI_RTSR ) , (EXTI_Num) );
	}
	else if(SenseMode == EXTI_SENSE_ON_CHANGE )
	{
		SET_BIT(  (EXTI ->EXTI_RTSR ) , (EXTI_Num) );
		SET_BIT(  (EXTI ->EXTI_FTSR ) , (EXTI_Num) );
	}
}

/*u8 EXTI_u8GetPIF (u8 EXTI_Port , u8 EXTI_Num , EXTI_Sense_Mode_t EventSenseMode)
{



}*/

void EXTI_voidEnableSoftwareInterrupt_PIF(u8 EXTI_Num )
{
	EXTI ->EXTI_SWIER |=  ( 1 << EXTI_Num);
}

void  EXTI_voidSetCallBack(u8 Copy_InterruptId,void (*PF)(void))
{

	switch(Copy_InterruptId)
	{

	case EXTI_LINE0:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_LINE0]=PF;
		}
		break;
	case EXTI_LINE1:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_LINE1]=PF;
		}
		break;
	case EXTI_LINE2:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_LINE2]=PF;
		}
		break;

	case EXTI_LINE3:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_LINE3]=PF;
		}
		break;
	case EXTI_LINE4:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_LINE4]=PF;
		}
		break;
	case EXTI_LINE5:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_LINE5]=PF;
		}
		break;
	case EXTI_LINE6:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_LINE6]=PF;
		}
		break;
	case EXTI_LINE7:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_LINE7]=PF;
		}
		break;
	case EXTI_LINE8:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_LINE8]=PF;
		}
		break;
	case EXTI_LINE9:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_LINE9]=PF;
		}
		break;
	case EXTI_LINE10:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_LINE10]=PF;
		}
		break;
	case EXTI_LINE11:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_LINE11]=PF;
		}
		break;
	case EXTI_LINE12:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_LINE12]=PF;
		}
		break;
	case EXTI_LINE13:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_LINE13]=PF;
		}
		break;

	case EXTI_LINE14:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_LINE14]=PF;
		}
		break;


	case EXTI_LINE15:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_LINE15]=PF;
		}
		break;
	}


}


void EXTI0_IRQHandler(void)
{

	if(PF_Notification[0]!=NULL)
	{

		PF_Notification[0]();
		SET_BIT(EXTI->EXTI_PR,0);

	}
}

void EXTI1_IRQHandler(void)
{

	if(PF_Notification[1]!=NULL)
	{

		PF_Notification[1]();
		SET_BIT(EXTI->EXTI_PR,1);

	}
}


void EXTI2_IRQHandler(void)
{


	if(PF_Notification[2]!=NULL)
	{

		PF_Notification[2]();
		SET_BIT(EXTI->EXTI_PR,2);

	}
}


void EXTI3_IRQHandler(void)
{

	if(PF_Notification[3]!=NULL)
	{

		PF_Notification[3]();
		SET_BIT(EXTI->EXTI_PR,3);
	}
}



void EXTI4_IRQHandler(void)
{

	if(PF_Notification[4]!=NULL)
	{

		PF_Notification[4]();
		SET_BIT(EXTI->EXTI_PR,4);

	}
}



void EXTI9_5_IRQHandler(void)
{

	for(u8 i=5 ;i<=9 ;i++)
	{
		if(PF_Notification[i]!=NULL && GET_BIT(EXTI->EXTI_PR,i))
			{

				PF_Notification[i]();
				SET_BIT(EXTI->EXTI_PR,i);
			}
	}



}


void EXTI15_10_IRQHandler(void)
{

	for(u8 i=10 ;i<=15 ;i++)
	{
		if(PF_Notification[i]!=NULL && GET_BIT(EXTI->EXTI_PR,i))
			{

				PF_Notification[i]();
				SET_BIT(EXTI->EXTI_PR,i);
			}
	}
}
