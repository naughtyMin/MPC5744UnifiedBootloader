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
/*!
 * @file bootloader_main.c
 * 
 * @brief: Add your description here for this file.
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section Rule_X-Y Rule: X.Y (Advisory/Required)
 * Violates MISRA 2012 Advisory Rule X.Y, Rule description here.
 *
 * @par Version Histroy
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  Tomlin Tang  2019-03-25 11:50:56  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
 */

#include "bootloader_main.h"


/*******************************************************************************
 * User Include
 ******************************************************************************/
#include "includes.h"
#include "uds_app.h"
#include "TP.h"
#include "fls_app.h"
#include "timer_hal.h"
#include "watchdog_hal.h"
#include "boot.h"
#include "CRC_HAL.h"

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*print bootloader version*/
static void BOOTLOADER_MAIN_PrintVersion(void);

/*FUNCTION**********************************************************************
 *
 * Function Name : BOOTLOADER_MAIN_Init
 * Description   : This function initial this module.
 *
 * Implements : BOOTLOADER_MAIN_Init_Activity
 *END**************************************************************************/
void BOOTLOADER_MAIN_Init(void (*pfBSP_Init)(void), void (*pfAbortTxMsg)(void))
{
	/*Is power on ?*/
	if(TRUE == Boot_IsPowerOnTriggerReset())
	{
		Boot_PowerONClearAllFlag();
	}

	/*Check jump to APP or not.*/
	Boot_JumpToAppOrNot();
	
	/*User Init: clock CAN Lin etc..*/
	if(NULL_PTR != pfBSP_Init)
	{
		/*do BSP init*/
		(*pfBSP_Init)();
	}
	
	BOOTLOADER_DEBUG_Init();

    if(TRUE != CRC_HAL_Init())
    {
    	APP_DebugPrintf("CRC_HAL_Init failed!\n");
    }
    
	//WATCHDOG_HAL_Init();

    WATCHDOG_HAL_Deinit();

	TIMER_HAL_Init();

	TP_Init();

	if(TRUE != FLASH_HAL_APPAddrCheck())
	{
		APP_DebugPrintf("\n FLASH_HAL_APPAddrCheck check error!\n");
	}

	UDS_Init();

	Boot_CheckReqBootloaderMode();

	TP_RegisterAbortTxMsg(pfAbortTxMsg);

	FLASH_APP_Init();

	/*Print bootloader version*/
	//BOOTLOADER_MAIN_PrintVersion();
}

/*FUNCTION**********************************************************************
 *
 * Function Name : BOOTLOADER_MAIN_Demo
 * Description   : This function initial this module.
 *
 * Implements : BOOTLOADER_MAIN_Demo_Activity
 *END**************************************************************************/
void BOOTLOADER_MAIN_Demo(void)
{
#ifdef EN_DEBUG_IO
	static uint16 timerCnt1Ms = 0u;
#endif
	
	if(TRUE == TIMER_HAL_Is1msTickTimeout())
	{
		TP_SystemTickCtl();
		
		UDS_SystemTickCtl();

#ifdef EN_DEBUG_IO		
		/*toggle LED*/
		timerCnt1Ms++;
		if(250u == timerCnt1Ms)
		{
			timerCnt1Ms = 0u;

			Debug_ToggleDebugIO();
		}
#endif
	}

	/*fed watchdog every 100ms*/
	if(TRUE == TIMER_HAL_Is100msTickTimeout())
	{
		WATCHDOG_HAL_Fed();
	}

	TP_MainFun();

	UDS_MainFun();

	Flash_OperateMainFunction();	
}

/*print bootloader version*/
static void BOOTLOADER_MAIN_PrintVersion(void)
{
	uint8 aBootloaderSWVersion[] = BOOTLOADER_SW_VERSION;

	APP_DebugPrintf("\nBootloader SW version:%d.%d.%d\n", aBootloaderSWVersion[1u], aBootloaderSWVersion[2u], aBootloaderSWVersion[3u]);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : BOOTLOADER_MAIN_Deinit
 * Description   : This function initial this module.
 *
 * Implements : BOOTLOADER_MAIN_Deinit_Activity
 *END**************************************************************************/
void BOOTLOADER_MAIN_Deinit(void)
{

	
}
/******************************************************************************
 * EOF
 *****************************************************************************/
