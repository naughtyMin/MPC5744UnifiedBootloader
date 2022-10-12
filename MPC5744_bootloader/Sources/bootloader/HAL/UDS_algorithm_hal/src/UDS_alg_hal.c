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
 * @file UDS_alg.c
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
 V1.0.0  Tomlin Tang  2019-01-18 14:10:34  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
 */

#include "UDS_alg_hal.h"
#include "timer_hal.h"
#include "AES.h"

/*******************************************************************************
 * User Include
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
const static uint8 gs_aKey[] = {0x00u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u,
                      0x08u, 0x09u, 0x0au, 0x0bu, 0x0cu, 0x0du, 0x0eu, 0x0fu}; 

#ifdef EN_ALG_SW
/*here is not init, because this used for software random*/
static uint32 gs_UDS_SWTimerTickCnt;

#endif


/*FUNCTION**********************************************************************
 *
 * Function Name : UDS_ALG_HAL_Init
 * Description   : This function initial this module.
 *
 * Implements : UDS_ALG_hal_Init_Activity
 *END**************************************************************************/
void UDS_ALG_HAL_Init(void)
{
}

/*FUNCTION**********************************************************************
 *
 * Function Name : UDS_ALG_HAL_EncryptData
 * Description   : This function is encrpt data.
 *
 * Implements : UDS_ALG_hal_Init_Activity
 *END**************************************************************************/
 boolean UDS_ALG_HAL_EncryptData(const uint8 *i_pPlainText, const uint32 i_dataLen, uint8 *o_pCipherText)
{
	boolean ret = FALSE;

#ifdef EN_ALG_SW
	aes((sint8 *)i_pPlainText, i_dataLen, (sint8 *)&gs_aKey[0], (sint8 *)o_pCipherText);
#endif

	


	return ret;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : UDS_ALG_HAL_DecryptData
 * Description   : This function is decrypt data.
 *
 * Implements : UDS_ALG_hal_Init_Activity
 *END**************************************************************************/
 boolean UDS_ALG_HAL_DecryptData(const uint8 *i_pCipherText, const uint32 i_dataLen, uint8 *o_pPlainText)
{
	boolean ret = FALSE;

#ifdef EN_ALG_SW
	deAes((sint8 *)i_pCipherText, i_dataLen, (sint8 *)&gs_aKey[0], (sint8 *)o_pPlainText);	
#endif

	


	return ret;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : UDS_ALG_HAL_GetRandom
 * Description   : This function is get random.
 *
 * Implements : UDS_ALG_hal_Init_Activity
 *END**************************************************************************/
boolean UDS_ALG_HAL_GetRandom(const uint32 i_needRandomDataLen, uint8 *o_pRandomDataBuf)
{
	boolean ret = TRUE;
	uint8 index = 0u;
	uint8 *pRandomTmp = NULL_PTR;
	uint32 random = (uint32)&index;

	if((0u == i_needRandomDataLen) || (NULL_PTR == o_pRandomDataBuf))
	{
		ret = FALSE;
	}

#ifdef EN_ALG_SW
#if 1
	random = TIMER_HAL_GetTimerTickCnt();
	
	random |= (gs_UDS_SWTimerTickCnt << 16u);
	fsl_srand(random);

	if(TRUE == ret)
	{		
		pRandomTmp = (uint8 *)&random;
		
		for(index = 0u; index < i_needRandomDataLen; index++)
		{
			if(((index & 0x03u) == 0x03u))
			{
				/*get random*/
				random = fsl_rand();
			}
			
			o_pRandomDataBuf[index] = pRandomTmp[index & 0x03];
		}
	}
#else
	random = 0u;
	for(index = 0; index < i_needRandomDataLen; index++)
	{
		o_pRandomDataBuf[index] = random;

		random += 0x11u;
	}

#endif

#endif

	return ret;

}

/*UDS software timer tick*/
void UDS_ALG_HAL_AddSWTimerTickCnt(void)
{
#ifdef EN_ALG_SW
	gs_UDS_SWTimerTickCnt++;
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : UDS_ALG_HAL_Deinit
 * Description   : This function initial this module.
 *
 * Implements : UDS_ALG_Deinit_Activity
 *END**************************************************************************/
void UDS_ALG_HAL_Deinit(void)
{


}

/******************************************************************************
 * EOF
 *****************************************************************************/
