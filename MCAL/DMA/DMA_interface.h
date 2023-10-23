/*
 * DMA_interface.h
 *
 *  Created on: Sep 20, 2023
 *      Author: alibo
 */

#ifndef MCAL_DMA_DMA_INTERFACE_H_
#define MCAL_DMA_DMA_INTERFACE_H_




typedef enum
{
	DMA_CH0, DMA_CH1,  DMA_CH2,  DMA_CH3,DMA_CH4, DMA_CH5,  DMA_CH6,  DMA_CH7
}DMA_ChannelSelect_t;

typedef enum
{
	DMA_ST0, DMA_ST1,  DMA_ST2 ,  DMA_ST3, DMA_ST4 , DMA_ST5,  DMA_ST6,  DMA_ST7
}DMA_StreamSelect_t;
typedef enum
{
	DMA_Mem_SingleTransfer,
	DMA_Mem_INCR4,
	DMA_Mem_INCR8,
	DMA_Mem_INCR16,
}DMA_MemoryBurstTransfer_t;
typedef enum
{
	DMA_Per_SingleTransfer,
	DMA_Per_INCR4,
	DMA_Per_INCR8,
	DMA_Per_INCR16,
}DMA_PeripheralBurstTransfer_t;

typedef enum
{
	DMA_LOW,
	DMA_MEDIUM,
	DMA_HIGH,
	DMA_VERYHIGH,
}DMA_Priority_Level_t;

typedef enum
{
	DMA_Mem_Byte,
	DMA_Mem_Half_Word,
	DMA_Mem_Word
}DMA_MemoryDataSize_t;
typedef enum
{
	DMA_Per_Byte,
	DMA_Per_Half_Word,
	DMA_Per_Word
}DMA_PeripheralDataSize_t;

typedef enum
{
	DMA_Memory_Fixed,
	DMA_Memory_Increment,
}DMA_MemINC_t;

typedef enum
{
	DMA_Peripheral_Fixed,
	DMA_Peripheral_Increment,
}DMA_PerINC_t;
typedef enum
{
	DMA_1_4FullFIFO,
	DMA_1_2FullFIFO,
	DMA3_4FullFIFO,
	DMA_FullFIFO
}DMA_ThresholdSelection_t;
typedef enum
{
	DMA_Peripheral_to_Memory,
	DMA_Memory_to_peripheral,
	DMA_Memory_to_Memory
}DMA_DataTransferDirection_t;
typedef enum
{
	DMA_CircularMode_Disabled,
	DMA_CircularMode_Enabled
}DMA_CircularMode_t;
typedef enum
{
	DMA_DMAIsTheFlowCont,
	DMA_PeripheralIsTheFlowCont

}DMA_PeripheralFlowCont_t;

typedef struct
{
	DMA_StreamSelect_t            DMA_StreamSelect;
	DMA_ChannelSelect_t           DMA_ChannelSelect;
	DMA_MemoryBurstTransfer_t     DMA_MemoryBurstTransfer;
	DMA_PeripheralBurstTransfer_t DMA_PeripheralBurstTransfer;
	DMA_Priority_Level_t          DMA_Priority_Level;
	DMA_MemoryDataSize_t          DMA_MemoryDataSize;
	DMA_PeripheralDataSize_t      DMA_PeripheralDataSize;
	DMA_MemINC_t                  DMA_MemINC;
	DMA_PerINC_t                  DMA_PerINC;
	DMA_DataTransferDirection_t   DMA_DataTransferDirection;
	DMA_CircularMode_t            DMA_CircularMode;
	DMA_ThresholdSelection_t      DMA_ThresholdSelection;
	DMA_PeripheralFlowCont_t      DMA_PeripheralFlowCont;
}DMA_Config_t;


void DMA_voidInit  ( DMA_Config_t *ptrToDMAConfig);
void DMA_SetStream ( u8 Copy_u8StreamID , u32 *ptru32ToSrcAddress , u32 *ptru32ToDestAddress , u16 Copy_u16NumOfDataRegister);
void DMA_EnableStream (u8 Copy_u8StreamID );
void DMA_voidCallBack( DMA_StreamSelect_t StreamNum, void (*PtrToFun) (void));
#endif /* MCAL_DMA_DMA_INTERFACE_H_ */
