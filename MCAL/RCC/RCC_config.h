/*
 * RCC_config.h
 *
 *  Created on: Sep 3, 2023
 *      Author: alibo
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*
 ENABALE
 DISABLE
 */
#define RCC_HSI_ENABLE      DISABEL
#define RCC_HSE_ENABLE      ENABALE
#define RCC_PLL_ENABLE      DISABEL

/*
 * RCC_CLOCK_SOURCE
 * 1. RCC_HSE_SELECT
 * 2. RCC_HSI_SELECT
 * 3. RCC_PLL_SELECT
 */

#define RCC_CLOCK_SOURCE     RCC_HSE_SELECT
#define RCC_CLOCK_PRESCALER  RCC_AHB_NOTDIVIDED
#endif /* RCC_CONFIG_H_ */
