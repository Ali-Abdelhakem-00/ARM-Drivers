/*
 * TFT_interface.h
 *
 *  Created on: Sep 19, 2023
 *      Author: alibo
 */

#ifndef HAL_TFT_TFT_INTERFACE_H_
#define HAL_TFT_TFT_INTERFACE_H_



void TFT_voidInit(void);
void TFT_voidDisplayImage(const  u16*Ptr_u16Image);
void TFT_voidFillColor(u16 Copy_u16Color);
#endif /* HAL_TFT_TFT_INTERFACE_H_ */
