/***************************************************************************//**
* \file CLI.h
* \version 2.0
*
*  This file provides constants and parameter values for the UART component.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CLI_CY_SCB_UART_PDL_H)
#define CLI_CY_SCB_UART_PDL_H

#include "cyfitter.h"
#include "scb/cy_scb_uart.h"

#if defined(__cplusplus)
extern "C" {
#endif

/***************************************
*   Initial Parameter Constants
****************************************/

#define CLI_DIRECTION  (3U)
#define CLI_ENABLE_RTS (0U)
#define CLI_ENABLE_CTS (0U)

/* UART direction enum */
#define CLI_RX    (0x1U)
#define CLI_TX    (0x2U)

#define CLI_ENABLE_RX  (0UL != (CLI_DIRECTION & CLI_RX))
#define CLI_ENABLE_TX  (0UL != (CLI_DIRECTION & CLI_TX))


/***************************************
*        Function Prototypes
***************************************/
/**
* \addtogroup group_general
* @{
*/
/* Component specific functions. */
void CLI_Start(void);

/* Basic functions */
__STATIC_INLINE cy_en_scb_uart_status_t CLI_Init(cy_stc_scb_uart_config_t const *config);
__STATIC_INLINE void CLI_DeInit(void);
__STATIC_INLINE void CLI_Enable(void);
__STATIC_INLINE void CLI_Disable(void);

/* Register callback. */
__STATIC_INLINE void CLI_RegisterCallback(cy_cb_scb_uart_handle_events_t callback);

/* Configuration change. */
#if (CLI_ENABLE_CTS)
__STATIC_INLINE void CLI_EnableCts(void);
__STATIC_INLINE void CLI_DisableCts(void);
#endif /* (CLI_ENABLE_CTS) */

#if (CLI_ENABLE_RTS)
__STATIC_INLINE void     CLI_SetRtsFifoLevel(uint32_t level);
__STATIC_INLINE uint32_t CLI_GetRtsFifoLevel(void);
#endif /* (CLI_ENABLE_RTS) */

__STATIC_INLINE void CLI_EnableSkipStart(void);
__STATIC_INLINE void CLI_DisableSkipStart(void);

#if (CLI_ENABLE_RX)
/* Low level: Receive direction. */
__STATIC_INLINE uint32_t CLI_Get(void);
__STATIC_INLINE uint32_t CLI_GetArray(void *buffer, uint32_t size);
__STATIC_INLINE void     CLI_GetArrayBlocking(void *buffer, uint32_t size);
__STATIC_INLINE uint32_t CLI_GetRxFifoStatus(void);
__STATIC_INLINE void     CLI_ClearRxFifoStatus(uint32_t clearMask);
__STATIC_INLINE uint32_t CLI_GetNumInRxFifo(void);
__STATIC_INLINE void     CLI_ClearRxFifo(void);
#endif /* (CLI_ENABLE_RX) */

#if (CLI_ENABLE_TX)
/* Low level: Transmit direction. */
__STATIC_INLINE uint32_t CLI_Put(uint32_t data);
__STATIC_INLINE uint32_t CLI_PutArray(void *buffer, uint32_t size);
__STATIC_INLINE void     CLI_PutArrayBlocking(void *buffer, uint32_t size);
__STATIC_INLINE void     CLI_PutString(char_t const string[]);
__STATIC_INLINE void     CLI_SendBreakBlocking(uint32_t breakWidth);
__STATIC_INLINE uint32_t CLI_GetTxFifoStatus(void);
__STATIC_INLINE void     CLI_ClearTxFifoStatus(uint32_t clearMask);
__STATIC_INLINE uint32_t CLI_GetNumInTxFifo(void);
__STATIC_INLINE bool     CLI_IsTxComplete(void);
__STATIC_INLINE void     CLI_ClearTxFifo(void);
#endif /* (CLI_ENABLE_TX) */

#if (CLI_ENABLE_RX)
/* High level: Ring buffer functions. */
__STATIC_INLINE void     CLI_StartRingBuffer(void *buffer, uint32_t size);
__STATIC_INLINE void     CLI_StopRingBuffer(void);
__STATIC_INLINE void     CLI_ClearRingBuffer(void);
__STATIC_INLINE uint32_t CLI_GetNumInRingBuffer(void);

/* High level: Receive direction functions. */
__STATIC_INLINE cy_en_scb_uart_status_t CLI_Receive(void *buffer, uint32_t size);
__STATIC_INLINE void     CLI_AbortReceive(void);
__STATIC_INLINE uint32_t CLI_GetReceiveStatus(void);
__STATIC_INLINE uint32_t CLI_GetNumReceived(void);
#endif /* (CLI_ENABLE_RX) */

#if (CLI_ENABLE_TX)
/* High level: Transmit direction functions. */
__STATIC_INLINE cy_en_scb_uart_status_t CLI_Transmit(void *buffer, uint32_t size);
__STATIC_INLINE void     CLI_AbortTransmit(void);
__STATIC_INLINE uint32_t CLI_GetTransmitStatus(void);
__STATIC_INLINE uint32_t CLI_GetNumLeftToTransmit(void);
#endif /* (CLI_ENABLE_TX) */

/* Interrupt handler */
__STATIC_INLINE void CLI_Interrupt(void);
/** @} group_general */


/***************************************
*    Variables with External Linkage
***************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t CLI_initVar;
extern cy_stc_scb_uart_config_t const CLI_config;
extern cy_stc_scb_uart_context_t CLI_context;
/** @} group_globals */


/***************************************
*         Preprocessor Macros
***************************************/
/**
* \addtogroup group_macros
* @{
*/
/** The pointer to the base address of the hardware */
#define CLI_HW     ((CySCB_Type *) CLI_SCB__HW)
/** @} group_macros */


/***************************************
*    In-line Function Implementation
***************************************/

/*******************************************************************************
* Function Name: CLI_Init
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_uart_status_t CLI_Init(cy_stc_scb_uart_config_t const *config)
{
   return Cy_SCB_UART_Init(CLI_HW, config, &CLI_context);
}


/*******************************************************************************
* Function Name: CLI_DeInit
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_DeInit(void)
{
    Cy_SCB_UART_DeInit(CLI_HW);
}


/*******************************************************************************
* Function Name: CLI_Enable
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Enable() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_Enable(void)
{
    Cy_SCB_UART_Enable(CLI_HW);
}


/*******************************************************************************
* Function Name: CLI_Disable
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Disable() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_Disable(void)
{
    Cy_SCB_UART_Disable(CLI_HW, &CLI_context);
}


/*******************************************************************************
* Function Name: CLI_RegisterCallback
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_RegisterCallback() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_RegisterCallback(cy_cb_scb_uart_handle_events_t callback)
{
    Cy_SCB_UART_RegisterCallback(CLI_HW, callback, &CLI_context);
}


#if (CLI_ENABLE_CTS)
/*******************************************************************************
* Function Name: CLI_EnableCts
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_EnableCts() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_EnableCts(void)
{
    Cy_SCB_UART_EnableCts(CLI_HW);
}


/*******************************************************************************
* Function Name: Cy_SCB_UART_DisableCts
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_DisableCts() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_DisableCts(void)
{
    Cy_SCB_UART_DisableCts(CLI_HW);
}
#endif /* (CLI_ENABLE_CTS) */


#if (CLI_ENABLE_RTS)
/*******************************************************************************
* Function Name: CLI_SetRtsFifoLevel
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_SetRtsFifoLevel() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_SetRtsFifoLevel(uint32_t level)
{
    Cy_SCB_UART_SetRtsFifoLevel(CLI_HW, level);
}


/*******************************************************************************
* Function Name: CLI_GetRtsFifoLevel
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetRtsFifoLevel() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CLI_GetRtsFifoLevel(void)
{
    return Cy_SCB_UART_GetRtsFifoLevel(CLI_HW);
}
#endif /* (CLI_ENABLE_RTS) */


/*******************************************************************************
* Function Name: CLI_EnableSkipStart
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_EnableSkipStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_EnableSkipStart(void)
{
    Cy_SCB_UART_EnableSkipStart(CLI_HW);
}


/*******************************************************************************
* Function Name: CLI_DisableSkipStart
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_DisableSkipStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_DisableSkipStart(void)
{
    Cy_SCB_UART_DisableSkipStart(CLI_HW);
}


#if (CLI_ENABLE_RX)
/*******************************************************************************
* Function Name: CLI_Get
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Get() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CLI_Get(void)
{
    return Cy_SCB_UART_Get(CLI_HW);
}


/*******************************************************************************
* Function Name: CLI_GetArray
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetArray() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CLI_GetArray(void *buffer, uint32_t size)
{
    return Cy_SCB_UART_GetArray(CLI_HW, buffer, size);
}


/*******************************************************************************
* Function Name: CLI_GetArrayBlocking
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetArrayBlocking() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_GetArrayBlocking(void *buffer, uint32_t size)
{
    Cy_SCB_UART_GetArrayBlocking(CLI_HW, buffer, size);
}


/*******************************************************************************
* Function Name: CLI_GetRxFifoStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetRxFifoStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CLI_GetRxFifoStatus(void)
{
    return Cy_SCB_UART_GetRxFifoStatus(CLI_HW);
}


/*******************************************************************************
* Function Name: CLI_ClearRxFifoStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_ClearRxFifoStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_ClearRxFifoStatus(uint32_t clearMask)
{
    Cy_SCB_UART_ClearRxFifoStatus(CLI_HW, clearMask);
}


/*******************************************************************************
* Function Name: CLI_GetNumInRxFifo
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetNumInRxFifo() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CLI_GetNumInRxFifo(void)
{
    return Cy_SCB_UART_GetNumInRxFifo(CLI_HW);
}


/*******************************************************************************
* Function Name: CLI_ClearRxFifo
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_ClearRxFifo() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_ClearRxFifo(void)
{
    Cy_SCB_UART_ClearRxFifo(CLI_HW);
}
#endif /* (CLI_ENABLE_RX) */


#if (CLI_ENABLE_TX)
/*******************************************************************************
* Function Name: CLI_Put
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Put() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CLI_Put(uint32_t data)
{
    return Cy_SCB_UART_Put(CLI_HW,data);
}


/*******************************************************************************
* Function Name: CLI_PutArray
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_PutArray() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CLI_PutArray(void *buffer, uint32_t size)
{
    return Cy_SCB_UART_PutArray(CLI_HW, buffer, size);
}


/*******************************************************************************
* Function Name: CLI_PutArrayBlocking
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_PutArrayBlocking() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_PutArrayBlocking(void *buffer, uint32_t size)
{
    Cy_SCB_UART_PutArrayBlocking(CLI_HW, buffer, size);
}


/*******************************************************************************
* Function Name: CLI_PutString
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_PutString() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_PutString(char_t const string[])
{
    Cy_SCB_UART_PutString(CLI_HW, string);
}


/*******************************************************************************
* Function Name: CLI_SendBreakBlocking
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_SendBreakBlocking() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_SendBreakBlocking(uint32_t breakWidth)
{
    Cy_SCB_UART_SendBreakBlocking(CLI_HW, breakWidth);
}


/*******************************************************************************
* Function Name: CLI_GetTxFifoStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetTxFifoStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CLI_GetTxFifoStatus(void)
{
    return Cy_SCB_UART_GetTxFifoStatus(CLI_HW);
}


/*******************************************************************************
* Function Name: CLI_ClearTxFifoStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_ClearTxFifoStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_ClearTxFifoStatus(uint32_t clearMask)
{
    Cy_SCB_UART_ClearTxFifoStatus(CLI_HW, clearMask);
}


/*******************************************************************************
* Function Name: CLI_GetNumInTxFifo
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetNumInTxFifo() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CLI_GetNumInTxFifo(void)
{
    return Cy_SCB_UART_GetNumInTxFifo(CLI_HW);
}


/*******************************************************************************
* Function Name: CLI_IsTxComplete
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_IsTxComplete() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE bool CLI_IsTxComplete(void)
{
    return Cy_SCB_UART_IsTxComplete(CLI_HW);
}


/*******************************************************************************
* Function Name: CLI_ClearTxFifo
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_ClearTxFifo() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_ClearTxFifo(void)
{
    Cy_SCB_UART_ClearTxFifo(CLI_HW);
}
#endif /* (CLI_ENABLE_TX) */


#if (CLI_ENABLE_RX)
/*******************************************************************************
* Function Name: CLI_StartRingBuffer
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_StartRingBuffer() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_StartRingBuffer(void *buffer, uint32_t size)
{
    Cy_SCB_UART_StartRingBuffer(CLI_HW, buffer, size, &CLI_context);
}


/*******************************************************************************
* Function Name: CLI_StopRingBuffer
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_StopRingBuffer() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_StopRingBuffer(void)
{
    Cy_SCB_UART_StopRingBuffer(CLI_HW, &CLI_context);
}


/*******************************************************************************
* Function Name: CLI_ClearRingBuffer
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_ClearRingBuffer() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_ClearRingBuffer(void)
{
    Cy_SCB_UART_ClearRingBuffer(CLI_HW, &CLI_context);
}


/*******************************************************************************
* Function Name: CLI_GetNumInRingBuffer
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetNumInRingBuffer() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CLI_GetNumInRingBuffer(void)
{
    return Cy_SCB_UART_GetNumInRingBuffer(CLI_HW, &CLI_context);
}


/*******************************************************************************
* Function Name: CLI_Receive
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Receive() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_uart_status_t CLI_Receive(void *buffer, uint32_t size)
{
    return Cy_SCB_UART_Receive(CLI_HW, buffer, size, &CLI_context);
}


/*******************************************************************************
* Function Name: CLI_GetReceiveStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetReceiveStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CLI_GetReceiveStatus(void)
{
    return Cy_SCB_UART_GetReceiveStatus(CLI_HW, &CLI_context);
}


/*******************************************************************************
* Function Name: CLI_AbortReceive
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_AbortReceive() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_AbortReceive(void)
{
    Cy_SCB_UART_AbortReceive(CLI_HW, &CLI_context);
}


/*******************************************************************************
* Function Name: CLI_GetNumReceived
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetNumReceived() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CLI_GetNumReceived(void)
{
    return Cy_SCB_UART_GetNumReceived(CLI_HW, &CLI_context);
}
#endif /* (CLI_ENABLE_RX) */


#if (CLI_ENABLE_TX)
/*******************************************************************************
* Function Name: CLI_Transmit
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Transmit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_uart_status_t CLI_Transmit(void *buffer, uint32_t size)
{
    return Cy_SCB_UART_Transmit(CLI_HW, buffer, size, &CLI_context);
}


/*******************************************************************************
* Function Name: CLI_GetTransmitStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetTransmitStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CLI_GetTransmitStatus(void)
{
    return Cy_SCB_UART_GetTransmitStatus(CLI_HW, &CLI_context);
}


/*******************************************************************************
* Function Name: CLI_AbortTransmit
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_AbortTransmit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_AbortTransmit(void)
{
    Cy_SCB_UART_AbortTransmit(CLI_HW, &CLI_context);
}


/*******************************************************************************
* Function Name: CLI_GetNumLeftToTransmit
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_GetNumLeftToTransmit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CLI_GetNumLeftToTransmit(void)
{
    return Cy_SCB_UART_GetNumLeftToTransmit(CLI_HW, &CLI_context);
}
#endif /* (CLI_ENABLE_TX) */


/*******************************************************************************
* Function Name: CLI_Interrupt
****************************************************************************//**
*
* Invokes the Cy_SCB_UART_Interrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CLI_Interrupt(void)
{
    Cy_SCB_UART_Interrupt(CLI_HW, &CLI_context);
}

#if defined(__cplusplus)
}
#endif

#endif /* CLI_CY_SCB_UART_PDL_H */


/* [] END OF FILE */
