/*
 * OS_porgram.c
 *
 *  Created on: Sep 10, 2023
 *      Author: alibo
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/STK/STK_interface.h"
#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"


Task SystemTask[MAX_NUM_OF_TASKS] = {0};
u8 TaskTiming[MAX_NUM_OF_TASKS]={0};
Task EmptyTask = {0};

void OS_voidStartOS(u32 Copy_u32TickTime)
{
	STK_voidCallBackFun(OS_voidScheduler);
	STK_voidStartTimerAsynch_IntervalPeriodic( Copy_u32TickTime );
}
u8 OS_u8CreateTask( void(*Copy_Handler)(void) , u8 Copy_Periodicity , u8 Copy_Priority , u8 Copy_FirstDelay)
{
	u8 Local_u8ErrorState = 0;
	// verify the passed priority is within the range
	if(Copy_Priority < MAX_NUM_OF_TASKS )
	{
		if(SystemTask [Copy_Priority].Task_Handler == 0 )
		{
			//create task
			SystemTask[Copy_Priority].Task_Handler     =  Copy_Handler;
			SystemTask[Copy_Priority].Task_Periodicity =  Copy_Periodicity;
			SystemTask[Copy_Priority].Task_FirstDelay  =  Copy_FirstDelay;
			TaskTiming[Copy_Priority] = Copy_Periodicity - 1 ;
			SystemTask[Copy_Priority].Task_State = Ready;
		}
		else
		{
			// reserved index
			Local_u8ErrorState = 2 ;
		}
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}
	// access priority
	return Local_u8ErrorState;
}

void OS_voidScheduler(void)
{
	// Loop on All Tasks In System
	for(u8 Local_u8counter = 0;Local_u8counter < MAX_NUM_OF_TASKS ; Local_u8counter++)
	{
		//Check if there is a task in this index
		if(SystemTask [Local_u8counter].Task_Handler != 0)
		{
			if(SystemTask[Local_u8counter].Task_State == Ready)
			{
				if(SystemTask[Local_u8counter].Task_FirstDelay == 0)
				{
					// execute the task
					SystemTask[Local_u8counter].Task_Handler();
					SystemTask[Local_u8counter].Task_FirstDelay = TaskTiming[Local_u8counter];
				}
				else
				{
					SystemTask[Local_u8counter].Task_FirstDelay -- ;
				}
			}
		}
	}
}

u8 OS_u8DeleteTask( u8 Copy_Priority )
{
	u8 Local_u8ErrorState = 0 ;
	if(SystemTask[Copy_Priority].Task_Handler != 0)
	{
		SystemTask[Copy_Priority] = EmptyTask ;
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;
}

u8 OS_u8SuspendTask (u8 Copy_Priority)
{
	u8 Local_u8ErrorState = 0 ;
	if(SystemTask[Copy_Priority].Task_Handler != 0)
	{
		SystemTask[Copy_Priority].Task_State = Suspended ;
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;
}



u8 OS_u8ResumeTask(u8 Copy_Priority)
{
	u8 Local_u8ErrorState = 0 ;
	if(SystemTask[Copy_Priority].Task_Handler != 0)
	{
		SystemTask[Copy_Priority].Task_State = Ready ;
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;
}
