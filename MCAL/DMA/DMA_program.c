/*
 * DMA_program.c
 *
 *  Created on: Sep 20, 2023
 *      Author: alibo
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"


static void (*PF_Notification[8]) (void) ={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
void DMA_voidInit(DMA_Config_t *ptrToDMAConfig)
{
	CLR_BIT( (DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR) , DMA_EN_BIT );

	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR &= ~(  0b111    << DMA_CHSEL_BIT ) ;
	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR |=  (  ptrToDMAConfig->DMA_ChannelSelect << DMA_CHSEL_BIT ) ;

	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR &= ~(  0b11    << DMA_PRIORITY_BIT ) ;
	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR |=  ( ptrToDMAConfig->DMA_Priority_Level  << DMA_PRIORITY_BIT ) ;

	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR &= ~(  0b11     << DMA_DIR_BIT ) ;
	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR |=  (  ptrToDMAConfig->DMA_DataTransferDirection << DMA_DIR_BIT ) ;

	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR &= ~( 0b1 << DMA_CIRC_BIT );
	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR |=  ( ptrToDMAConfig->DMA_CircularMode << DMA_CIRC_BIT );

	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR &= ~(  0b11    << DMA_MBURST_BIT  ) ;
	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR |=  (  ptrToDMAConfig->DMA_MemoryBurstTransfer  << DMA_MBURST_BIT ) ;

	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR &= ~(  0b11    << DMA_PBURST_BIT  ) ;
	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR |=  ( ptrToDMAConfig->DMA_PeripheralBurstTransfer  << DMA_PBURST_BIT ) ;

	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR &= ~(  0b11     << DMA_MSIZE_BIT ) ;
	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR |=  ( ptrToDMAConfig->DMA_MemoryDataSize << DMA_MSIZE_BIT ) ;

	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR &= ~(  0b11     << DMA_PSIZE_BIT ) ;
	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR |=  (  ptrToDMAConfig->DMA_PeripheralDataSize << DMA_PSIZE_BIT ) ;

	if(ptrToDMAConfig->DMA_DataTransferDirection == DMA_Memory_to_Memory )
	{

		SET_BIT( (DMA2->S[ptrToDMAConfig->DMA_StreamSelect].FCR) , 2 );
	}

	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].FCR &= ~( 0b11 << 0 );
	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].FCR |=  ( ptrToDMAConfig->DMA_ThresholdSelection << 0 );

	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR &= ~( 0b1 << DMA_MINC_BIT );
	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR |=  ( ptrToDMAConfig->DMA_MemINC << DMA_MINC_BIT );

	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR &= ~( 0b1 << DMA_PINC_BIT );
	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR |=  ( ptrToDMAConfig->DMA_PerINC << DMA_PINC_BIT );

	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR &= ~( 0b1 << DMA_PFCTRL_BIT );
	DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR |=  ( ptrToDMAConfig->DMA_PeripheralFlowCont << DMA_PFCTRL_BIT );

	SET_BIT( (DMA2->S[ptrToDMAConfig->DMA_StreamSelect].CR) , DMA_TCIE_BIT ); // complete Int
}


void DMA_SetStream ( u8 Copy_u8StreamID , u32 *ptru32ToSrcAddress , u32 *ptru32ToDestAddress , u16 Copy_u16NumOfDataRegister)
{

	DMA2->S[Copy_u8StreamID].PAR  = (u32)ptru32ToSrcAddress ;
	DMA2->S[Copy_u8StreamID].M0AR = (u32)ptru32ToDestAddress ;
	DMA2->S[Copy_u8StreamID].NDTR = Copy_u16NumOfDataRegister;


}

void DMA_EnableStream (u8 Copy_u8StreamID )
{

	SET_BIT( (DMA2->S[Copy_u8StreamID].CR) , DMA_EN_BIT );
}

void DMA_voidCallBack( DMA_StreamSelect_t StreamNum, void (*PtrToFun) (void) )
{
		PF_Notification[StreamNum] = PtrToFun;
}


void DMA2_Stream0_IRQHandler(void)
{
	if(PF_Notification != NULL)
	{
		PF_Notification[0]();
	}

	SET_BIT( (DMA2->DMA_LIFCR) , 5 ); // CLEAR Complete Flag
}

void DMA2_Stream1_IRQHandler(void)
{
	if(PF_Notification != NULL)
	{
		PF_Notification[1]();
	}

	SET_BIT( (DMA2->DMA_LIFCR) , 11 ); // CLEAR Complete Flag
}
