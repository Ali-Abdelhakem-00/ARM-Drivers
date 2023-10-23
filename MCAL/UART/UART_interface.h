/*
 * UART_interface.h
 *
 *  Created on: Sep 17, 2023
 *      Author: alibo
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_
typedef enum
{
OverSampling_By16,
OverSampling_By8
}Over_Sampling_t;
typedef enum
{
	ThreeSampleBit,
	OneSampleBit
}SamplingBits_t;

typedef enum
{
	STBit_8BitData,
	STBit_9BitData
}WordLength_t;

typedef enum
{
	Parity_Disable,
	Parity_Enable
}ParityEnable_t;

typedef enum
{
	EvenParity,
	OddParity
}ParitySelection_t;
typedef enum
{
	_1StopBit,
	_05StopBit,
	_2StopBit,
	_15StopBit
}Stop_Bit_t;
typedef enum
{
	UART1_Selection,
	UART2_Selection,
	UART6_Selection
}UART_Selection_t;

typedef enum
{
	TX_Only_Enable ,
	RX_Only_Enable ,
	TX_RX_Enable,

}TX_RX_ENABLE_DISABLE_t;
typedef enum
{
	UART_Mode_Interrupt,
	UART_Mode_Polling
}UART_Mode_t;

typedef struct
{
	UART_Mode_t            UART_Mode;
	Over_Sampling_t        OverSampling;
	SamplingBits_t         SamplingBits;
	WordLength_t           WordLength;
	Stop_Bit_t             StopBits;
	ParityEnable_t         ParityEnable;
	ParitySelection_t      ParitySelection;
	UART_Selection_t       UART_Selection;
	TX_RX_ENABLE_DISABLE_t UART_TX_RXselection;
	u32                    BaudRate;

}UART_CONFIG_t;
void UART_Init(UART_CONFIG_t *Ptr_To_UART_CONFIG  );

void UART_u8SendData_Sync(u8 Copy_u8Data , u8 UART_NUM);
u8 UART_ReceiveData_Sync (u8 UART_NUM);

void UART_SendString    (u8 *Copy_Ptru8_To_String , u8 UART_NUM);
void UART_ReceiveString (u8 *Copy_Ptru8_To_String, u8 UART_NUM);

void UART_u8SendData_Async(u8 Copy_u8Data , u8 UART_NUM);
u8 UART_ReceiveData_Async (u8 UART_NUM);



void UART1_voidCallBackFun ( void (*Ptr_To_Func)(void) );
void UART2_voidCallBackFun ( void (*Ptr_To_Func)(void) );
void UART6_voidCallBackFun ( void (*Ptr_To_Func)(void) );


#endif /* MCAL_UART_UART_INTERFACE_H_ */
