/*
 * STK_private.h
 *
 *  Created on: Sep 6, 2023
 *      Author: alibo
 */

#ifndef MCAL_STK_STK_PRIVATE_H_
#define MCAL_STK_STK_PRIVATE_H_

#define STK_AHB_8     0
#define STK_AHB       1



#define ENABLE_BIT       0
#define CLKSOURCE_BIT    2
#define TICKINT_BIT      1
#define FLAG_BIT         16

#define STK_BASE_ADDRESS         0xE000E010

typedef struct
{
	volatile u32 STK_CTRL  ;
	volatile u32 STK_LOAD  ;
	volatile u32 STK_VAL   ;
	volatile u32 STK_CALIB ;
}STK_MemMap_t;


#define STK       ( (volatile STK_MemMap_t*) STK_BASE_ADDRESS )

#endif /* MCAL_STK_STK_PRIVATE_H_ */
