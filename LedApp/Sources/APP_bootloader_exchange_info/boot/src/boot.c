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
#include "UDS_app.h"

/*******************************************************************************
 * User Include
 ******************************************************************************/
#include "includes.h"

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*download APP successful mode check*/
boolean Boot_CheckDownlaodAPPStatus(void)
{
	boolean ret = FALSE;
//
	if(MFSPR(256) == 0x3C)
	{
		//clear flag
		MTSPR(256, 0x0);
//		ClearDownloadAPPSuccessfulFlag();

		/*write a message to host based on TP*/
		if(TRUE == UDS_TxMsgToHost())
		{
			ret = TRUE;
			APPDebugPrintf("\n Downlaod APP successful!\n");
		}
		else
		{
			APPDebugPrintf("\n Enter APP mode and transmit confirm message failed!\n");
		}
	}
//
	return ret;
}


/******************************************************************************
 * EOF
 *****************************************************************************/
