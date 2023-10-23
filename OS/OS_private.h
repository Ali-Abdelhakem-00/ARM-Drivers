/*
 * OS_private.h
 *
 *  Created on: Sep 10, 2023
 *      Author: alibo
 */

#ifndef SERVIES_OS_PRIVATE_H_
#define SERVIES_OS_PRIVATE_H_


typedef struct
{
	void (*Task_Handler)(void);
	u32 Task_Periodicity;
	u8 Task_FirstDelay;
	u8 Task_State;
}Task;

typedef enum
{
Ready,
Suspended,

}TaskState;
void OS_voidScheduler(void);

#endif /* SERVIES_OS_PRIVATE_H_ */
