/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef BOOTLOADER_DEBUG_H
#define BOOTLOADER_DEBUG_H


/*******************************************************************************
 * User Include
 ******************************************************************************/
#include "includes.h"

#ifdef EN_DEBUG_IO
#include "debug_IO.h"
#endif /*#ifdef EN_DEBUG_IO*/

#ifdef EN_DEBUG_TIMER
#include "debug_timer.h"
#endif /*#ifdef EN_DEBUG_TIMER*/

/*! 
 * @file: bootloader_debug.h
 *
 * @brief: Add your description here for this file.
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section Rule_X-Y Rule: X.Y (Required)
 * Violates MISRA 2012 Required Rule X.Y, Rule description here.
 *
 * @par Version Histroy
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  Tomlin Tang  2019-01-17 15:52:56  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
 */

/*!
 * @addtogroup bootloader_debug
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#if defined (__cplusplus)
extern "C" {
#endif

/*******************************************************************************
 * API
 ******************************************************************************/
#ifdef EN_DEBUG_IO
#define InitDebugIO() DEBUG_IO_Init()
#define SetDebugIOHigh() DEBUG_IO_SetDebugIOHigh()
#define SetDebugIOLow() DEBUG_IO_SetDebugIOLow()
#define ToggleDebugIO() DEBUG_IO_ToggleDebugIO()
#else
#define InitDebugIO() 
#define SetDebugIOHigh() 
#define SetDebugIOLow() 
#define ToggleDebugIO() 
#endif /*#ifdef EN_DEBUG_IO*/



#ifdef EN_DEBUG_TIMER
#define InitDebugTimer() DEBUG_TIMER_Init()
#define GetDegbuTimerValue() DEBUG_TIMER_GetTimerValue()
#else
#define InitDebugTimer() 
#define GetDegbuTimerValue() 
#endif /*#ifdef EN_DEBUG_TIMER*/

#ifdef EN_DEBUG_PRINT
#define DEBUG_LOG_BUF_SIZE (200u)
extern void Bootloader_DebugPrintInit(void);
extern void Bootloader_DebugPrint(const char *fmt, ...);

#define InitDebugPrint() Bootloader_DebugPrintInit()
//LPUART_DRV_Init(INST_LPUART1, &lpuart1_State, &lpuart1_InitConfig0);
#define DebugPrintf(fmt, args...) Bootloader_DebugPrint(fmt, ##args)
#else
/*Some MCU cannot called printf lib. E.g., S12Gxxx*/
#define InitDebugPrint()
#define DebugPrintf(fmt, args...)
#endif


extern 	void BOOTLOADER_DEBUG_Init(void);

/*! @}*/

#if defined (__cplusplus)
}
#endif

/*! @}*/

#endif /* BOOTLOADER_DEBUG_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/
