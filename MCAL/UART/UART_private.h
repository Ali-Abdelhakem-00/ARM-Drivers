/*
 * UART_private.h
 *
 *  Created on: Sep 17, 2023
 *      Author: alibo
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_


#define     UART1_BASEADDRESS          0x40011000
#define     UART2_BASEADDRESS          0x40004400
#define     UART6_BASEADDRESS          0x40011400
typedef struct
{
	volatile u32 USART_SR;
	volatile u32 USART_DR;
	volatile u32 USART_BRR;
	volatile u32 USART_CR1;
	volatile u32 USART_CR2;
	volatile u32 USART_CR3;
	volatile u32 USART_GTPR;

}UART_MemMap_t;

#define UART1     ( (volatile UART_MemMap_t*)UART1_BASEADDRESS)
#define UART2     ( (volatile UART_MemMap_t*)UART2_BASEADDRESS)
#define UART6     ( (volatile UART_MemMap_t*)UART6_BASEADDRESS)

// SR
#define TXE_BIT     7
#define TC_BIT      6
#define RXNE_BIT    5

//CR1
#define OVER8_BIT        15
#define UARTENA_BIT      13
#define WORDLENGTH_BIT   12
#define PCE_BIT          10
#define PS_BIT           9
#define PEINTE_BIT       8
#define TXEINTE_BIT      7
#define TCINTE_BIT       6
#define RXNEINTE_BIT     5
#define IDLEINTE_BIT     4
#define TE_BIT           3
#define RE_BIT           2


//CR2
#define STOP_BIT         12

//CR3
#define SAMPLE_BIT       11

#define UART_DIV_SAMPLING16(_PCLK_, _BAUD_)            (((_PCLK_)*25U)/(4U*(_BAUD_)))
#define UART_DIVMANT_SAMPLING16(_PCLK_, _BAUD_)        (UART_DIV_SAMPLING16((_PCLK_), (_BAUD_))/100U)
#define UART_DIVFRAQ_SAMPLING16(_PCLK_, _BAUD_)        (((UART_DIV_SAMPLING16((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) * 100U)) * 16U + 50U) / 100U)
/* UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + (UART DIVFRAQ & 0xF0) + (UART DIVFRAQ & 0x0FU) */
#define UART_BRR_SAMPLING16(_PCLK_, _BAUD_)            (((UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) << 4U) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0xF0U)) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0x0FU))

#define UART_DIV_SAMPLING8(_PCLK_, _BAUD_)             (((_PCLK_)*25U)/(2U*(_BAUD_)))
#define UART_DIVMANT_SAMPLING8(_PCLK_, _BAUD_)         (UART_DIV_SAMPLING8((_PCLK_), (_BAUD_))/100U)
#define UART_DIVFRAQ_SAMPLING8(_PCLK_, _BAUD_)         (((UART_DIV_SAMPLING8((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) * 100U)) * 8U + 50U) / 100U)
/* UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + ((UART DIVFRAQ & 0xF8) << 1) + (UART DIVFRAQ & 0x07U) */
#define UART_BRR_SAMPLING8(_PCLK_, _BAUD_)             (((UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) << 4U) + \
                                                        ((UART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0xF8U) << 1U)) + \
                                                        (UART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0x07U))


#endif /* MCAL_UART_UART_PRIVATE_H_ */
