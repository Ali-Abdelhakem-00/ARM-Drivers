/*
 * LEDMATRIX_interface.h
 *
 *  Created on: Sep 13, 2023
 *      Author: alibo
 */

#ifndef HAL_LEDMATRIX_LEDMATRIX_INTERFACE_H_
#define HAL_LEDMATRIX_LEDMATRIX_INTERFACE_H_

void LEDMAT_voidInit(void);
void LEDMAT_voidDispalyData      (u8 *u8Ptr , u8 NumOfSeconds );
void LEDMAT_voidDisplayMovingData(u8 *u8Ptr , u8 ArrSize );


#endif /* HAL_LEDMATRIX_LEDMATRIX_INTERFACE_H_ */
