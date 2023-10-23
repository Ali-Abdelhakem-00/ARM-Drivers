/*
 * OS_interface.h
 *
 *  Created on: Sep 10, 2023
 *      Author: alibo
 */

#ifndef SERVIES_OS_INTERFACE_H_
#define SERVIES_OS_INTERFACE_H_

void OS_voidStartOS(u32 Copy_u32TickTime);
u8 OS_u8CreateTask( void(*Copy_Handler)(void) , u8 Copy_Periodicity , u8 Copy_Priority , u8 Copy_FirstDelay);

u8 OS_u8DeleteTask( u8 Copy_Priority );
u8 OS_u8SuspendTask (u8 Copy_Priority);
u8 OS_u8ResumeTask(u8 Copy_Priority);
#endif /* SERVIES_OS_INTERFACE_H_ */
