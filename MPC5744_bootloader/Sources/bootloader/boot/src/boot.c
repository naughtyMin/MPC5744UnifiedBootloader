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
 * @file boot.c
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
 V1.0.0  Tomlin Tang  2019-01-21 13:46:20  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
 */

#include "boot.h"


/*******************************************************************************
 * User Include
 ******************************************************************************/
#include "includes.h"
#include "fls_app.h"
#include "uds_app.h"

/*******************************************************************************
 * Variables
 ******************************************************************************/
static boolean Boot_IsAPPValid(void)
{
	boolean bResult = FALSE;

	/*check app code flash status. If app code update successfull, this api return TRUE, else return FALSE.*/
	bResult = Flash_IsReadAppInfoFromFlashValid();
	
	if(TRUE == bResult)
	{
		bResult = Flash_IsAppInFlashValid();
	}

	return bResult;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Boot_JumpToAppOrNot
 * Description   : This function is jump to app or not. If app valid and APP not request enter bootloader, then jump to APP.
 *			     Some MCU call this function need in startup, because jump to APP need to before init Peripheral (clock...).
 *
 * Implements : 
 *END*************************************************************************/
void Boot_JumpToAppOrNot(void)
{
	uint32 resetHandlerAddr = 0u;

	if((TRUE == Boot_IsAPPValid()) && (TRUE != Boot_IsRequestEnterBootloader()))
	{
		Boot_RemapApplication();
		
		resetHandlerAddr = Flash_GetResetHandlerAddr();
		
		Boot_JumpToApp(resetHandlerAddr);
	}
}

/*request bootloader mode check*/
boolean Boot_CheckReqBootloaderMode(void)
{
	boolean ret = FALSE;

	if(TRUE == Boot_IsRequestEnterBootloader())
	{
		Boot_ClearRequestEnterBootloaderFlag();

		/*write a message to host based on TP*/
		if(TRUE == UDS_TxMsgToHost())
		{
			ret = TRUE;
			APP_DebugPrintf("\n Enter bootloader mode\n");
		}
		else
		{
			APP_DebugPrintf("\n Enter bootloader mode and transmit confirm message failed!\n");
		}
	}

	return ret;
}


/******************************************************************************
 * EOF
 *****************************************************************************/
