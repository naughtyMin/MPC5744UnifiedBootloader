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

#ifndef UDS_ALG_HAL_H
#define UDS_ALG_HAL_H

#include "includes.h"

/*******************************************************************************
 * User Include
 ******************************************************************************/

/*! 
 * @file: UDS_alg.h
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
 V1.0.0  Tomlin Tang  2019-01-18 14:10:34  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
 */

/*!
 * @addtogroup UDS_alg_hal
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*!
 * @brief TODO:Input brief here.
 * \n <b>Bold font</b>
 * \n <i>Italics</i>
 *  - List item 1
 *  - List item 2
 *
 * Implements : uds_alg_instance_t_Class
 */


#if defined (__cplusplus)
extern "C" {
#endif

/*******************************************************************************
 * API
 ******************************************************************************/
 
/*! @}*/
/*!
 * @name Initialize
 * Initial this module.
 *
 * To disable this module, you need call another function (see \ref Uninitialize "Disable Module")
 */
/*! @{*/

/*!
 * @brief To initial this module.
 *
 * This function returns the state of the initial.
 *
 * @param[in] instance instance number
 * @return the initial state.
 */
void UDS_ALG_HAL_Init(void);

/*!
 * @brief To UDS encrypt data.
 *
 * This function returns encrypt data status.
 *
 * @param[in] i_pPlainText point plaintext
 * @param[in] i_dataLen point plaintext data lenght
 * @param[out]  o_pCipherText point ciphertext
 * @return encrypt data status.
 */
extern boolean UDS_ALG_HAL_EncryptData(const uint8 *i_pPlainText, const uint32 i_dataLen, uint8 *o_pCipherText);

/*!
 * @brief To UDS decrypt data.
 *
 * This function returns decrypt data status.
 *
 * @param[in] i_pCipherText point ciphertext
 * @param[in] i_dataLen point ciphertext data lenght
 * @param[out]  o_pPlainText point plaintext
 * @return decrypt data status.
 */
extern boolean UDS_ALG_HAL_DecryptData(const uint8 *i_pCipherText, const uint32 i_dataLen, uint8 *o_pPlainText);

/*!
 * @brief To UDS get random data.
 *
 * This function returns get random data status.
 *
 * @param[in] i_needRandomLen need random data len
 * @param[out]  o_pRandomBuf point random data buff
 * @return get random data status.
 */
extern boolean UDS_ALG_HAL_GetRandom(const uint32 i_needRandomDataLen, uint8 *o_pRandomDataBuf);

/*UDS software timer tick*/
extern void UDS_ALG_HAL_AddSWTimerTickCnt(void);


/*! @}*/

/*!
 * @anchor Uninitialize
 * @name Disable Module
 * TODO:Some description here.
 */
/*! @{*/

/*!
 * @brief uninitial this module.
 *
 * TODO:Some description here.
 *
 * @param[in] instance instance number
 */
void UDS_ALG_HAL_Deinit(void);

/*! @}*/

#if defined (__cplusplus)
}
#endif

/*! @}*/

#endif /* UDS_ALG_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/
