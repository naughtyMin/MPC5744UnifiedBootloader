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

#ifndef CRC_HAL_H
#define CRC_HAL_H

#include "includes.h"

/*******************************************************************************
 * User Include
 ******************************************************************************/

/*! 
 * @file: CRC.h
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
 V1.0.0  Tomlin Tang  2019-01-18 14:10:55  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
 */

/*!
 * @addtogroup CRC
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#if defined (__cplusplus)
extern "C" {
#endif

#define CRC_SEED_INIT_VALUE	0xffff
typedef uint32 tCrc;

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
extern boolean CRC_HAL_Init(void);


/*! @}*/
/*!
 * @name Create CRC
 * Initial this module.
 *
 * To disable this module, you need call another function (see \ref Uninitialize "Disable Module")
 */
/*! @{*/

/*!
 * @brief To create CRC.
 *
 * This function returns the state of the initial.
 *
 * @param[in] instance instance number
 * @param[in] data buf
 * @param[in] data len
 * @param[out] CRC value
 * @return the initial state.
 */
extern void CRC_HAL_CreatHardwareCrc(const uint8 *i_pucDataBuf, const uint32 i_ulDataLen, uint32 *m_pCurCrc);
/*! @}*/

/*FUNCTION**********************************************************************
 *
 * Function Name : CRC_HAL_StartSoftwareCrc
 * Description   : This function use end software lookup table or calculate  to create crc.
 *
 * Implements : CreatCrc_Activity
 *END**************************************************************************/
extern void CRC_HAL_StartSoftwareCrc(uint32 *m_pCurCrc);

/*FUNCTION**********************************************************************
 *
 * Function Name : CRC_HAL_CreatHardwareCrc
 * Description   : This function use software lookup table or calculate  to create crc..
 *
 * Implements : CreatCrc_Activity
 *END**************************************************************************/
void CRC_HAL_CreatSoftwareCrc(const uint8_t *i_pucDataBuf, const uint32_t i_ulDataLen, uint32_t *m_pCurCrc);

/*FUNCTION**********************************************************************
 *
 * Function Name : CRC_HAL_EndSoftwareCrc
 * Description   : This function use end software lookup table or calculate  to create crc..
 *
 * Implements : CreatCrc_Activity
 *END**************************************************************************/
extern void CRC_HAL_EndSoftwareCrc(uint32 *m_pCurCrc);

/*FUNCTION**********************************************************************
 *
 * Function Name : CRC_HAL_CalculateCRCOnce
 * Description   : Calcualte CRC once
 *
 * Implements : CreatCrc_Activity
 *END**************************************************************************/
extern void CRC_HAL_CalculateCRCOnce(const uint8_t *i_pucDataBuf, const uint32_t i_ulDataLen, uint32_t *m_pCurCrc);

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
void CRC_HAL_Deinit(void);

/*! @}*/

#if defined (__cplusplus)
}
#endif

/*! @}*/

#endif /* CRC_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/
