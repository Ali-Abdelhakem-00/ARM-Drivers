/*
 * STK_interface.h
 *
 *  Created on: Sep 6, 2023
 *      Author: alibo
 */

#ifndef MCAL_STK_STK_INTERFACE_H_
#define MCAL_STK_STK_INTERFACE_H_



void STK_voidInitCLKSource(void);
void STK_voidStartTimerSynch_BUSYWAIT(u32 Copy_u32Ticks);

void STK_voidStartTimerAsynch_IntervalSingle   (u32 Copy_u32Ticks ,  void(*Ptr_To_Fun)(void) );
void STK_voidStartTimerAsynch_IntervalPeriodic (u32 Copy_u32Ticks  , void(*Ptr_To_Fun)(void) );


void STK_voidStopTimer(void);

u32 STK_u32GetElapsedTime(void);
u32 STK_u32GetRemainingTime(void);


#endif /* MCAL_STK_STK_INTERFACE_H_ */
