/*
 * UART_program.c
 *
 *  Created on: Sep 17, 2023
 *      Author: alibo
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

static void (*UART1_GlobalPtrToFunNotif)(void)=NULL;
static void (*UART2_GlobalPtrToFunNotif)(void)=NULL;
static void (*UART6_GlobalPtrToFunNotif)(void)=NULL;

void UART_Init(UART_CONFIG_t *Ptr_To_UART_CONFIG  )
{
	switch ( Ptr_To_UART_CONFIG->UART_Selection )
	{
	case UART1_Selection:
		 UART1 ->USART_SR = 0; // clear all flags
		switch(Ptr_To_UART_CONFIG->OverSampling)
		{
		case OverSampling_By16:
			UART1->USART_BRR = UART_BRR_SAMPLING16 ( PCK , (Ptr_To_UART_CONFIG->BaudRate) );
			break;
		case OverSampling_By8:
			UART1->USART_BRR = UART_BRR_SAMPLING8  ( PCK , (Ptr_To_UART_CONFIG->BaudRate) );
			break;
		}

		UART1->USART_CR1 |=  ( (Ptr_To_UART_CONFIG->OverSampling)    <<  OVER8_BIT );
		UART1->USART_CR1 |=  ( (Ptr_To_UART_CONFIG->WordLength)      <<  WORDLENGTH_BIT );
		UART1->USART_CR1 |=  ( (Ptr_To_UART_CONFIG->ParitySelection) <<  PS_BIT );
		UART1->USART_CR1 |=  ( (Ptr_To_UART_CONFIG->ParityEnable)    <<  PCE_BIT );
		switch (Ptr_To_UART_CONFIG ->UART_TX_RXselection )
		{
		case TX_Only_Enable:  SET_BIT( (UART1->USART_CR1) , TE_BIT);
			break;
		case RX_Only_Enable:  SET_BIT( (UART1->USART_CR1) , RE_BIT);
			break;
		case TX_RX_Enable:    SET_BIT( (UART1->USART_CR1) , TE_BIT);
		                      SET_BIT( (UART1->USART_CR1) , RE_BIT);
			break ;

		}
	   UART1->USART_CR2 &= ~( 0b11  << STOP_BIT  );
       UART1->USART_CR2 |=  ( (Ptr_To_UART_CONFIG->StopBits)  << STOP_BIT  );
       UART1->USART_CR3 |=  ( (Ptr_To_UART_CONFIG->SamplingBits) << SAMPLE_BIT);

       if(Ptr_To_UART_CONFIG ->UART_Mode == UART_Mode_Interrupt)
       {
    	  // SET_BIT( (UART1->USART_CR1) , TXEINTE_BIT  );
    	  // SET_BIT( (UART1->USART_CR1) , TCINTE_BIT   );
    	 //  SET_BIT( (UART1->USART_CR1) , RXNEINTE_BIT );
    	     SET_BIT( (UART1->USART_CR1) , PEINTE_BIT   );
       }
       SET_BIT( UART1->USART_CR1 ,  UARTENA_BIT );
	break;

	case UART2_Selection:
		 UART2 ->USART_SR = 0; // clear all flags
		switch(Ptr_To_UART_CONFIG->OverSampling)
		{
		case OverSampling_By16:
			UART2->USART_BRR = UART_BRR_SAMPLING16 ( PCK , (Ptr_To_UART_CONFIG->BaudRate) );
			break;
		case OverSampling_By8:
			UART2->USART_BRR = UART_BRR_SAMPLING8  ( PCK , (Ptr_To_UART_CONFIG->BaudRate) );
			break;
		}

		UART2->USART_CR1 |=  ( (Ptr_To_UART_CONFIG->OverSampling)      <<  OVER8_BIT );
		UART2->USART_CR1 |=  ( (Ptr_To_UART_CONFIG->WordLength)      <<  WORDLENGTH_BIT );
		UART2->USART_CR1 |=  ( (Ptr_To_UART_CONFIG->ParitySelection) <<  PS_BIT );
		UART2->USART_CR1 |=  ( (Ptr_To_UART_CONFIG->ParityEnable)   <<  PCE_BIT );
		switch (Ptr_To_UART_CONFIG ->UART_TX_RXselection )
		{
		case TX_Only_Enable:  SET_BIT( (UART2->USART_CR1) , TE_BIT);
			break;
		case RX_Only_Enable:  SET_BIT( (UART2->USART_CR1) , RE_BIT);
			break;
		case TX_RX_Enable:    SET_BIT( (UART2->USART_CR1) , TE_BIT);
		                      SET_BIT( (UART2->USART_CR1) , RE_BIT);
			break ;

		}
		UART2->USART_CR2 &= ~( 0b11  << STOP_BIT  );
		UART2->USART_CR2 |=  ( (Ptr_To_UART_CONFIG->StopBits)  << STOP_BIT  );
	    UART2->USART_CR3 |=  ( (Ptr_To_UART_CONFIG->SamplingBits) << SAMPLE_BIT);
	    SET_BIT( UART2->USART_CR1 ,  UARTENA_BIT );
	break;


	case UART6_Selection:
		 UART6 ->USART_SR = 0; // clear all falgs
		switch(Ptr_To_UART_CONFIG->OverSampling)
		{
		case OverSampling_By16:
			UART6->USART_BRR = UART_BRR_SAMPLING16 ( PCK , (Ptr_To_UART_CONFIG->BaudRate) );
			break;
		case OverSampling_By8:
			UART6->USART_BRR = UART_BRR_SAMPLING8  ( PCK , (Ptr_To_UART_CONFIG->BaudRate) );
			break;
		}

		UART6->USART_CR1 |=  ( (Ptr_To_UART_CONFIG->OverSampling)      <<  OVER8_BIT );
		UART6->USART_CR1 |=  ( (Ptr_To_UART_CONFIG->WordLength)      <<  WORDLENGTH_BIT );
		UART6->USART_CR1 |=  ( (Ptr_To_UART_CONFIG->ParitySelection) <<  PS_BIT );
		UART6->USART_CR1 |=  ( (Ptr_To_UART_CONFIG->ParityEnable)   <<  PCE_BIT );
		switch (Ptr_To_UART_CONFIG ->UART_TX_RXselection )
		{
		case TX_Only_Enable:  SET_BIT( (UART6->USART_CR1) , TE_BIT);
			break;
		case RX_Only_Enable:  SET_BIT( (UART6->USART_CR1) , RE_BIT);
			break;
		case TX_RX_Enable:    SET_BIT( (UART6->USART_CR1) , TE_BIT);
		                      SET_BIT( (UART6->USART_CR1) , RE_BIT);
			break ;

		}
		UART6->USART_CR2 &= ~( 0b11  << STOP_BIT  );
		UART6->USART_CR2 |=  ( (Ptr_To_UART_CONFIG->StopBits)  << STOP_BIT  );
	    UART6->USART_CR3 |=  ( (Ptr_To_UART_CONFIG->SamplingBits) << SAMPLE_BIT);
	    SET_BIT( UART6->USART_CR1 ,  UARTENA_BIT );

	break;
	}

}
void UART_u8SendData_Sync(u8 Copy_u8Data , u8 UART_NUM)
{
	switch (UART_NUM)
	{
	case UART1_Selection:
		while (  GET_BIT( (UART1->USART_SR) ,  TXE_BIT) == 0 );
		UART1->USART_DR = Copy_u8Data ;
		break;

	case UART2_Selection:
		while (  GET_BIT( (UART2->USART_SR) ,  TXE_BIT) == 0 );
		UART2->USART_DR = Copy_u8Data ;
		break;

	case UART6_Selection:
		while (  GET_BIT( (UART6->USART_SR) ,  TXE_BIT) == 0 );
		UART6->USART_DR = Copy_u8Data ;
		break;
	}

}
u8 UART_ReceiveData_Sync( u8 UART_NUM)
{
	u8 ReceivedData =0  ;
	switch (UART_NUM)
	{
	case UART1_Selection:
		while (  GET_BIT( (UART1->USART_SR) ,  RXNE_BIT) == 0 );
		ReceivedData=  UART1->USART_DR;
		break;

	case UART2_Selection:
		while (  GET_BIT( (UART2->USART_SR) ,  RXNE_BIT) == 0 );
		ReceivedData=  UART2->USART_DR;
		break;

	case UART6_Selection:
		while (  GET_BIT( (UART6->USART_SR) ,  RXNE_BIT) == 0 );
		ReceivedData=  UART6->USART_DR;
		break;
	}
	return ReceivedData;
}





void UART_u8SendData_Async(u8 Copy_u8Data , u8 UART_NUM)
{

	switch (UART_NUM)
	{
	case UART1_Selection:
		UART1->USART_DR = Copy_u8Data ;
		break;

	case UART2_Selection:
		UART2->USART_DR = Copy_u8Data ;
		break;

	case UART6_Selection:
		UART6->USART_DR = Copy_u8Data ;
		break;
	}
}

u8 UART_ReceiveData_Async(u8 UART_NUM)
{
	u8 ReceivedData =0  ;
	switch (UART_NUM)
	{
	    case UART1_Selection:
		    ReceivedData =  ( UART1->USART_DR ) ;
		break;

	    case UART2_Selection:
	    	ReceivedData =  ( UART2->USART_DR ) ;
		break;

    	case UART6_Selection:
    		ReceivedData =  ( UART6->USART_DR ) ;
		break;
	}
	return ReceivedData;
}


static u8 UART_ReceiveFlag = 0;

void UART1_voidCallBackFun ( void (*Ptr_To_Func)(void) )
{
	if(Ptr_To_Func != NULL && UART_ReceiveFlag == 0)
	{
		  UART_ReceiveFlag = 1;
		  UART1_GlobalPtrToFunNotif = Ptr_To_Func;
	}
	SET_BIT( (UART1->USART_CR1) , RXNEINTE_BIT );
}
void UART2_voidCallBackFun ( void (*Ptr_To_Func)(void) )
{
	if(Ptr_To_Func != NULL)
	{
		  UART2_GlobalPtrToFunNotif = Ptr_To_Func;
	}
}
void UART6_voidCallBackFun ( void (*Ptr_To_Func)(void) )
{
	if(Ptr_To_Func != NULL)
	{
		  UART6_GlobalPtrToFunNotif = Ptr_To_Func;
	}
}



void USART1_IRQHandler(void)
{

	if(UART1_GlobalPtrToFunNotif != NULL)
	{
		UART1_GlobalPtrToFunNotif();
	}
//	CLR_BIT( (UART1->USART_CR1) , RXNEINTE_BIT );
	UART_ReceiveFlag = 0;
}

void USART2_IRQHandler(void)
{

	if(UART2_GlobalPtrToFunNotif != NULL)
	{
		UART2_GlobalPtrToFunNotif();
	}

}

void USART6_IRQHandler(void)
{

	if(UART6_GlobalPtrToFunNotif != NULL)
	{
		UART6_GlobalPtrToFunNotif();
	}

}

void UART_SendString (u8 *Copy_Ptru8_To_String , u8 UART_NUM)
{
	u8 local_iterator = 0;
	if(Copy_Ptru8_To_String != NULL)
	{
		while( Copy_Ptru8_To_String[local_iterator] != '\0' )
		{
			UART_u8SendData_Sync(Copy_Ptru8_To_String[local_iterator] , UART_NUM);
			local_iterator++;

		}
	}
}

void UART_ReceiveString(u8 *Copy_Ptru8_To_String, u8 UART_NUM)
{
	u8 local_iterator = 0;
	if(Copy_Ptru8_To_String != NULL)
	{
		while( Copy_Ptru8_To_String[local_iterator] != '\0' )
		{
			Copy_Ptru8_To_String[local_iterator] = UART_ReceiveData_Sync(UART_NUM) ;
			local_iterator++;
		}
	}
}

