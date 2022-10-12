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
 * @file CRC.c
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
 V1.0.0  Tomlin Tang  2019-01-18 14:10:55  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
 */

#include "CRC_hal.h"

#ifdef EN_CRC_HARDWARE
#include "cpu.h"
#include "crc_cfg.h"
#endif

/*******************************************************************************
 * User Include
 ******************************************************************************/

#ifdef EN_CRC_SOFTWARE
/*
  *crc table dnp crc table 
  *Poly: 0x3D65
  *Init:  0x0000
  *RefIn:true
  *RefOut:true
  *XorOut:0xFFFF
*/
static const uint16 g_dnpCrcTable[256u] = {
0x0000, 0x365e, 0x6cbc, 0x5ae2, 0xd978, 0xef26, 0xb5c4, 0x839a,
0xff89, 0xc9d7, 0x9335, 0xa56b, 0x26f1, 0x10af, 0x4a4d, 0x7c13,
0xb26b, 0x8435, 0xded7, 0xe889, 0x6b13, 0x5d4d, 0x07af, 0x31f1,
0x4de2, 0x7bbc, 0x215e, 0x1700, 0x949a, 0xa2c4, 0xf826, 0xce78,
0x29af, 0x1ff1, 0x4513, 0x734d, 0xf0d7, 0xc689, 0x9c6b, 0xaa35,
0xd626, 0xe078, 0xba9a, 0x8cc4, 0x0f5e, 0x3900, 0x63e2, 0x55bc,
0x9bc4, 0xad9a, 0xf778, 0xc126, 0x42bc, 0x74e2, 0x2e00, 0x185e,
0x644d, 0x5213, 0x08f1, 0x3eaf, 0xbd35, 0x8b6b, 0xd189, 0xe7d7,
0x535e, 0x6500, 0x3fe2, 0x09bc, 0x8a26, 0xbc78, 0xe69a, 0xd0c4,
0xacd7, 0x9a89, 0xc06b, 0xf635, 0x75af, 0x43f1, 0x1913, 0x2f4d,
0xe135, 0xd76b, 0x8d89, 0xbbd7, 0x384d, 0x0e13, 0x54f1, 0x62af,
0x1ebc, 0x28e2, 0x7200, 0x445e, 0xc7c4, 0xf19a, 0xab78, 0x9d26,
0x7af1, 0x4caf, 0x164d, 0x2013, 0xa389, 0x95d7, 0xcf35, 0xf96b,
0x8578, 0xb326, 0xe9c4, 0xdf9a, 0x5c00, 0x6a5e, 0x30bc, 0x06e2,
0xc89a, 0xfec4, 0xa426, 0x9278, 0x11e2, 0x27bc, 0x7d5e, 0x4b00,
0x3713, 0x014d, 0x5baf, 0x6df1, 0xee6b, 0xd835, 0x82d7, 0xb489,
0xa6bc, 0x90e2, 0xca00, 0xfc5e, 0x7fc4, 0x499a, 0x1378, 0x2526,
0x5935, 0x6f6b, 0x3589, 0x03d7, 0x804d, 0xb613, 0xecf1, 0xdaaf,
0x14d7, 0x2289, 0x786b, 0x4e35, 0xcdaf, 0xfbf1, 0xa113, 0x974d,
0xeb5e, 0xdd00, 0x87e2, 0xb1bc, 0x3226, 0x0478, 0x5e9a, 0x68c4,
0x8f13, 0xb94d, 0xe3af, 0xd5f1, 0x566b, 0x6035, 0x3ad7, 0x0c89,
0x709a, 0x46c4, 0x1c26, 0x2a78, 0xa9e2, 0x9fbc, 0xc55e, 0xf300,
0x3d78, 0x0b26, 0x51c4, 0x679a, 0xe400, 0xd25e, 0x88bc, 0xbee2,
0xc2f1, 0xf4af, 0xae4d, 0x9813, 0x1b89, 0x2dd7, 0x7735, 0x416b,
0xf5e2, 0xc3bc, 0x995e, 0xaf00, 0x2c9a, 0x1ac4, 0x4026, 0x7678,
0x0a6b, 0x3c35, 0x66d7, 0x5089, 0xd313, 0xe54d, 0xbfaf, 0x89f1,
0x4789, 0x71d7, 0x2b35, 0x1d6b, 0x9ef1, 0xa8af, 0xf24d, 0xc413,
0xb800, 0x8e5e, 0xd4bc, 0xe2e2, 0x6178, 0x5726, 0x0dc4, 0x3b9a,
0xdc4d, 0xea13, 0xb0f1, 0x86af, 0x0535, 0x336b, 0x6989, 0x5fd7,
0x23c4, 0x159a, 0x4f78, 0x7926, 0xfabc, 0xcce2, 0x9600, 0xa05e,
0x6e26, 0x5878, 0x029a, 0x34c4, 0xb75e, 0x8100, 0xdbe2, 0xedbc,
0x91af, 0xa7f1, 0xfd13, 0xcb4d, 0x48d7, 0x7e89, 0x246b, 0x1235,
}; 

/************************************************************
**	Description :	using software lookup table to create crc. Input data in @ i_pucDataBuf
**	and data len in @ i_ulDataLen. When create crc successful
**	return CRC.
************************************************************/
static void CreatSoftwareCrc16(const uint8 *i_pDataBuf, const uint32 i_dataLen, uint32 *m_pCurCrc);
#endif

#ifdef EN_CRC_HARDWARE
/************************************************************
**	Description :	init hardware crc
**	data 			NULL
**	return 			Null
************************************************************/
static void Crc_Init(void);

/************************************************************
**	Description :	using MCU hardware to create crc. Input data in @ i_pucDataBuf
**	and data len in @ i_ulDataLen. When create crc successful
**	return CRC.
************************************************************/
static void CreatHardwareCrc16(const uint8_t *i_pucDataBuf, const uint32_t i_ulDataLen, uint32_t *m_pCurCrc);
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : CRC_Init
 * Description   : This function initial this module.
 *
 * Implements : CRC_Init_Activity
 *END**************************************************************************/
boolean CRC_HAL_Init(void)
{
#ifdef EN_CRC_HARDWARE
	Crc_Init();
#endif


    return TRUE;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CRC_HAL_CreatHardwareCrc
 * Description   : This function use MCU hardware to create crc.
 *
 * Implements : CreatCrc_Activity
 *END**************************************************************************/
void CRC_HAL_CreatHardwareCrc(const uint8 *i_pucDataBuf, const uint32 i_ulDataLen, uint32 *m_pCurCrc)
{
#ifdef EN_CRC_HARDWARE
	CreatHardwareCrc16(i_pucDataBuf, i_ulDataLen, m_pCurCrc);
#elif (defined EN_CRC_SOFTWARE)
	CreatSoftwareCrc16(i_pucDataBuf, i_ulDataLen, m_pCurCrc);
#else
	#error "Non CRC module enabled!"
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CRC_HAL_CreatHardwareCrc
 * Description   : This function use software lookup table or calculate  to create crc..
 *
 * Implements : CreatCrc_Activity
 *END**************************************************************************/
void CRC_HAL_CreatSoftwareCrc(const uint8_t *i_pucDataBuf, const uint32_t i_ulDataLen, uint32_t *m_pCurCrc)
{
#ifdef EN_CRC_SOFTWARE
	CreatSoftwareCrc16(i_pucDataBuf, i_ulDataLen, m_pCurCrc);
#elif EN_CRC_HARDWARE
	CreatHardwareCrc16(i_pucDataBuf, i_ulDataLen, m_pCurCrc);
#else
	#error "Pls define EN_CRC_SOFTWARE or EN_CRC_HARDWARE!"
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CRC_Deinit
 * Description   : This function initial this module.
 *
 * Implements : CRC_Deinit_Activity
 *END**************************************************************************/
void CRC_HAL_Deinit(void)
{


}

#ifdef EN_CRC_SOFTWARE
/************************************************************
**	Description :	using software lookup table to create crc. Input data in @ i_pucDataBuf
**	and data len in @ i_ulDataLen. When create crc successful
**	return CRC.
************************************************************/
static void CreatSoftwareCrc16(const uint8 *i_pDataBuf, const uint32 i_dataLen, uint32 *m_pCurCrc)
{
    uint16 crc = 0u; 
    uint32 index = 0u;

    crc = *m_pCurCrc;

    for(index = 0u; index < i_dataLen; index++)
    {
        crc = ( crc >> 8 ) ^ g_dnpCrcTable[( crc ^ i_pDataBuf[index]) & 0x00ff] ;
    }

   *m_pCurCrc = crc;
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : CRC_HAL_StartSoftwareCrc
 * Description   : This function use end software lookup table or calculate  to create crc.
 *
 * Implements : CreatCrc_Activity
 *END**************************************************************************/
void CRC_HAL_StartSoftwareCrc(uint32 *m_pCurCrc)
{
	ASSERT(NULL_PTR == m_pCurCrc);

	*m_pCurCrc = 0u;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CRC_HAL_EndSoftwareCrc
 * Description   : This function use end software lookup table or calculate  to create crc..
 *
 * Implements : CreatCrc_Activity
 *END**************************************************************************/
void CRC_HAL_EndSoftwareCrc(uint32 *m_pCurCrc)
{
	uint32 crc = *m_pCurCrc;

	if(NULL_PTR != m_pCurCrc)
	{
		*m_pCurCrc = (uint32)((~crc) & 0xFFFFu);
	}
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CRC_HAL_CalculateCRCOnce
 * Description   : Calcualte CRC once
 *
 * Implements : CreatCrc_Activity
 *END**************************************************************************/
void CRC_HAL_CalculateCRCOnce(const uint8_t *i_pucDataBuf, const uint32_t i_ulDataLen, uint32_t *m_pCurCrc)
{
	CRC_HAL_StartSoftwareCrc(m_pCurCrc);
#ifdef EN_CRC_SOFTWARE 
	CreatSoftwareCrc16(i_pucDataBuf, i_ulDataLen, m_pCurCrc);
#elif EN_CRC_HARDWARE
	EN_CRC_HARDWARE(i_pucDataBuf, i_ulDataLen, m_pCurCrc);
#else
	#error "Pls define EN_CRC_HARDWARE or EN_CRC_SOFTWARE"
#endif

	CRC_HAL_EndSoftwareCrc(m_pCurCrc);
}

#ifdef EN_CRC_HARDWARE
/************************************************************
**	Description :	using MCU hardware to create crc. Input data in @ i_pucDataBuf
**	and data len in @ i_ulDataLen. When create crc successful
**	return CRC.
************************************************************/
static void CreatHardwareCrc16(const uint8_t *i_pucDataBuf, const uint32_t i_ulDataLen, uint32_t *m_pCurCrc)
{
    /* Write your local variable definition here */
    uint32_t result = 0u;

#if (defined FALSH_ADDRESS_CONTINUE) && (FALSH_ADDRESS_CONTINUE == TRUE)
    crc1_UserConfig0.seed = *m_pCurCrc;
#endif	//end of MCU_USE_PAGING

    /* Init crc hardware */
    CRC_DRV_Init(INST_CRC1, &crc1_UserConfig0);


    /* Calculate CRC value for CRC_data with configuration of 16 of 32bit wide result */
    CRC_DRV_WriteData(INST_CRC1, i_pucDataBuf, i_ulDataLen);
    result = CRC_DRV_GetCrcResult(INST_CRC1);

    *m_pCurCrc = result;
}

/************************************************************
**	Description :	init hardware crc
**	data 			NULL
**	return 			Null
************************************************************/
static void Crc_Init(void)
{
#ifdef USING_HARDWARE_CRC
    /* call crc init before system clock init */
    PCC->PCCn[PCC_CRC_INDEX] |= PCC_PCCn_CGC_MASK;

    /* Init crc hardware */
    CRC_DRV_Init(INST_CRC1, &crc1_InitConfig0);

    /* Config user crcWidth, seed, polynomial, writeTranspose, readTranspose, complementChecksum */
    //CRC_DRV_Configure(INST_CRC1, &crc1_UserConfig0);

#endif //end of USING_HARDWARE_CRC
}
#endif
/******************************************************************************
 * EOF
 *****************************************************************************/
