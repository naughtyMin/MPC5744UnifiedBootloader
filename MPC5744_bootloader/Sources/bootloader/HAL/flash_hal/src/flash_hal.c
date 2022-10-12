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
 * @file flash_hal.c
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
 V1.0.0  Tomlin Tang  2019-01-17 15:51:03  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
 */

#include "flash_hal.h"
#include "flash.h"


/*******************************************************************************
 * User Include
 ******************************************************************************/


#define FLASH_TOTAL_BLOCKCOUNT 20
#define FLASH_LOWPART_BLOCKCOUNT 4
#define FLASH_MIDPART_BLOCKCOUNT 2
#define FLASH_HIGHPART_BLOCKCOUNT 6
#define FLASH_256KPART_BLOCKCOUNT 8


//low
#define FLASH_BLOCKPART_LOW_BLOCKNUM_0_START 0x00800000
#define FLASH_BLOCKPART_LOW_BLOCKNUM_0_END	0x00803FFF
#define FLASH_BLOCKPART_LOW_BLOCKNUM_1_START 0x00804000
#define FLASH_BLOCKPART_LOW_BLOCKNUM_1_END 0x00807FFF
#define FLASH_BLOCKPART_LOW_BLOCKNUM_2_START 0x00F98000
#define FLASH_BLOCKPART_LOW_BLOCKNUM_2_END 0x00F9BFFF
#define FLASH_BLOCKPART_LOW_BLOCKNUM_3_START 0x00F9C000
#define FLASH_BLOCKPART_LOW_BLOCKNUM_3_END 0x00F9FFFF

//mid
#define FLASH_BLOCKPART_MID_BLOCKNUM_0_START 0x00808000
#define FLASH_BLOCKPART_MID_BLOCKNUM_0_END 0x0080FFFF
#define FLASH_BLOCKPART_MID_BLOCKNUM_1_START 0x00810000
#define FLASH_BLOCKPART_MID_BLOCKNUM_1_END 0x00817FFF

//high
#define FLASH_BLOCKPART_HIGH_BLOCKNUM_0_START 0x00FA0000
#define FLASH_BLOCKPART_HIGH_BLOCKNUM_0_END 0x00FAFFFF
#define FLASH_BLOCKPART_HIGH_BLOCKNUM_1_START 0x00FB0000
#define FLASH_BLOCKPART_HIGH_BLOCKNUM_1_END 0x00FBFFFF
#define FLASH_BLOCKPART_HIGH_BLOCKNUM_2_START 0x00FC0000
#define FLASH_BLOCKPART_HIGH_BLOCKNUM_2_END 0x00FCFFFF
#define FLASH_BLOCKPART_HIGH_BLOCKNUM_3_START 0x00FD0000
#define FLASH_BLOCKPART_HIGH_BLOCKNUM_3_END 0x00FDFFFF
#define FLASH_BLOCKPART_HIGH_BLOCKNUM_4_START 0x00FE0000
#define FLASH_BLOCKPART_HIGH_BLOCKNUM_4_END 0x00FEFFFF
#define FLASH_BLOCKPART_HIGH_BLOCKNUM_5_START 0x00FF0000
#define FLASH_BLOCKPART_HIGH_BLOCKNUM_5_END 0x00FFFFFF

//256k
#define FLASH_BLOCKPART_256K_BLOCKNUM_0_START 0x01000000
#define FLASH_BLOCKPART_256K_BLOCKNUM_0_END 0x0103FFFF
#define FLASH_BLOCKPART_256K_BLOCKNUM_1_START 0x01040000
#define FLASH_BLOCKPART_256K_BLOCKNUM_1_END 0x0107FFFF
#define FLASH_BLOCKPART_256K_BLOCKNUM_2_START 0x01080000
#define FLASH_BLOCKPART_256K_BLOCKNUM_2_END 0x010BFFFF
#define FLASH_BLOCKPART_256K_BLOCKNUM_3_START 0x010C0000
#define FLASH_BLOCKPART_256K_BLOCKNUM_3_END 0x010FFFFF
#define FLASH_BLOCKPART_256K_BLOCKNUM_4_START 0x01100000
#define FLASH_BLOCKPART_256K_BLOCKNUM_4_END 0x0113FFFF
#define FLASH_BLOCKPART_256K_BLOCKNUM_5_START 0x01140000
#define FLASH_BLOCKPART_256K_BLOCKNUM_5_END 0x0117FFFF
#define FLASH_BLOCKPART_256K_BLOCKNUM_6_START 0x01180000
#define FLASH_BLOCKPART_256K_BLOCKNUM_6_END 0x011BFFFF
#define FLASH_BLOCKPART_256K_BLOCKNUM_7_START 0x011C0000
#define FLASH_BLOCKPART_256K_BLOCKNUM_7_END 0x011FFFFF


/* Lock State , shift is in the setlock function*/
#define LOCK_LOW_BLOCKS               0x00003FFFU  //lock0
#define LOCK_MID_BLOCKS               0x0000FFFFU  //lock0
#define LOCK_HIGH_BLOCKS              0x0000FFFFU  //lock1
#define LOCK_FIRST256_BLOCKS          0xFFFFFFFFU  //lock2
//#define UNLOCK_SECOND256_BLOCKS         0x0000FFFFU  //lock3

#define UNLOCK_LOW_BLOCKS               0x00000000U
#define UNLOCK_MID_BLOCKS               0x00000000U
#define UNLOCK_HIGH_BLOCKS              0x00000000U
#define UNLOCK_FIRST256_BLOCKS          0x00000000U
//#define UNLOCK_SECOND256_BLOCKS         0x00000000U


#define NUMBER_OF_WORD_BLANK_CHECK      0x90
#define NUMBER_OF_WORD_PGM_VERIFY       0x80
#define NUMBER_OF_WORD_CHECK_SUM        0x120

/* Platform Flash */
#define FLASH_FMC                       PFLASH_BASE
#define FLASH_PFCR1                     0x000000000U
#define FLASH_PFCR2                     0x000000004U
#define FLASH_FMC_BFEN_MASK             0x000000001U



//Block part and number structure
typedef struct
{
	uint32_t BlockPart; //Low,Mid,High or 256K
	uint32_t BlockNum; //Block 0...n
}Flash_BlockPartAndNum;



uint32_t Flash_Block_Lock[4]={
	LOCK_LOW_BLOCKS
	,LOCK_MID_BLOCKS
	,LOCK_HIGH_BLOCKS
	,LOCK_FIRST256_BLOCKS
};

uint32_t Flash_Block_UnLock[4]={
	UNLOCK_LOW_BLOCKS
	,UNLOCK_MID_BLOCKS
	,UNLOCK_HIGH_BLOCKS
	,UNLOCK_FIRST256_BLOCKS
};

//every part block count
uint32_t Flash_Block_Count[4]={
	FLASH_LOWPART_BLOCKCOUNT
	,FLASH_MIDPART_BLOCKCOUNT
	,FLASH_HIGHPART_BLOCKCOUNT
	,FLASH_256KPART_BLOCKCOUNT
};



//low space block start array
uint32_t Flash_Block_Low_Start_Array[FLASH_LOWPART_BLOCKCOUNT]={
	FLASH_BLOCKPART_LOW_BLOCKNUM_0_START
	,FLASH_BLOCKPART_LOW_BLOCKNUM_1_START
    ,FLASH_BLOCKPART_LOW_BLOCKNUM_2_START
    ,FLASH_BLOCKPART_LOW_BLOCKNUM_3_START
};

//mid space block start array
uint32_t Flash_Block_Mid_Start_Array[FLASH_MIDPART_BLOCKCOUNT]={

//mid
    FLASH_BLOCKPART_MID_BLOCKNUM_0_START
    ,FLASH_BLOCKPART_MID_BLOCKNUM_1_START
};

//high space block start array
uint32_t Flash_Block_High_Start_Array[FLASH_HIGHPART_BLOCKCOUNT]={
//high
    FLASH_BLOCKPART_HIGH_BLOCKNUM_0_START
    ,FLASH_BLOCKPART_HIGH_BLOCKNUM_1_START
    ,FLASH_BLOCKPART_HIGH_BLOCKNUM_2_START
    ,FLASH_BLOCKPART_HIGH_BLOCKNUM_3_START
    ,FLASH_BLOCKPART_HIGH_BLOCKNUM_4_START
    ,FLASH_BLOCKPART_HIGH_BLOCKNUM_5_START

};

//256k space block start array
uint32_t Flash_Block_256K_Start_Array[FLASH_256KPART_BLOCKCOUNT]={
//256k
    FLASH_BLOCKPART_256K_BLOCKNUM_0_START
    ,FLASH_BLOCKPART_256K_BLOCKNUM_1_START
    ,FLASH_BLOCKPART_256K_BLOCKNUM_2_START
    ,FLASH_BLOCKPART_256K_BLOCKNUM_3_START
    ,FLASH_BLOCKPART_256K_BLOCKNUM_4_START
    ,FLASH_BLOCKPART_256K_BLOCKNUM_5_START
    ,FLASH_BLOCKPART_256K_BLOCKNUM_6_START
    ,FLASH_BLOCKPART_256K_BLOCKNUM_7_START

};


//low space block end array
uint32_t Flash_Block_Low_End_Array[FLASH_LOWPART_BLOCKCOUNT]={
	FLASH_BLOCKPART_LOW_BLOCKNUM_0_END
	,FLASH_BLOCKPART_LOW_BLOCKNUM_1_END
    ,FLASH_BLOCKPART_LOW_BLOCKNUM_2_END
    ,FLASH_BLOCKPART_LOW_BLOCKNUM_3_END
};

//mid space block end array
uint32_t Flash_Block_Mid_End_Array[FLASH_MIDPART_BLOCKCOUNT]={

//mid
    FLASH_BLOCKPART_MID_BLOCKNUM_0_END
    ,FLASH_BLOCKPART_MID_BLOCKNUM_1_END
};

//high space block end array
uint32_t Flash_Block_High_End_Array[FLASH_HIGHPART_BLOCKCOUNT]={
//high
    FLASH_BLOCKPART_HIGH_BLOCKNUM_0_END
    ,FLASH_BLOCKPART_HIGH_BLOCKNUM_1_END
    ,FLASH_BLOCKPART_HIGH_BLOCKNUM_2_END
    ,FLASH_BLOCKPART_HIGH_BLOCKNUM_3_END
    ,FLASH_BLOCKPART_HIGH_BLOCKNUM_4_END
    ,FLASH_BLOCKPART_HIGH_BLOCKNUM_5_END

};

//256k space block end array
uint32_t Flash_Block_256K_End_Array[FLASH_256KPART_BLOCKCOUNT]={
//256k
    FLASH_BLOCKPART_256K_BLOCKNUM_0_END
    ,FLASH_BLOCKPART_256K_BLOCKNUM_1_END
    ,FLASH_BLOCKPART_256K_BLOCKNUM_2_END
    ,FLASH_BLOCKPART_256K_BLOCKNUM_3_END
    ,FLASH_BLOCKPART_256K_BLOCKNUM_4_END
    ,FLASH_BLOCKPART_256K_BLOCKNUM_5_END
    ,FLASH_BLOCKPART_256K_BLOCKNUM_6_END
    ,FLASH_BLOCKPART_256K_BLOCKNUM_7_END

};



uint32_t pflash_pfcr1, pflash_pfcr2;
uint32_t g_usrCnt = 0U;



/*******************************************************************************
 * Variables
 ******************************************************************************/
//static boolean FLASH_HAL_Init(void);
//
//static boolean FLASH_HAL_Erase(const uint32 startAddr, const uint32 endAddr);
//
//static flash_block_select_t Flash_GetSelectBlock(uint32_t startAddr, uint32_t endAddr);
//
//static boolean FLASH_HAL_WriteData(const uint32 i_startAddr,
//								 const uint32 *i_pDataBuf,
//								 const uint32 i_dataLen);
//
//static uint32 FLASH_HAL_ReadData(const uint32 i_addr);
//
//static void FLASH_HAL_Deinit(void);

//get addressrage select block
static flash_block_select_t Flash_GetSelectBlock(uint32_t startAddr, uint32_t endAddr)
{
	flash_block_select_t blockSelect={.lowBlockSelect=0,.midBlockSelect=0,.highBlockSelect=0,.first256KBlockSelect = 0,.second256KBlockSelect=0};
	uint8_t i;

	for(i=0;i<FLASH_LOWPART_BLOCKCOUNT;i++)
	{

		if( !(startAddr>Flash_Block_Low_End_Array[i] || endAddr<Flash_Block_Low_Start_Array[i] ) )
		{
			blockSelect.lowBlockSelect |= 1<<i;
		}

	}

	for(i=0;i<FLASH_MIDPART_BLOCKCOUNT;i++)
		{

			if( !(startAddr>Flash_Block_Mid_End_Array[i] || endAddr<Flash_Block_Mid_Start_Array[i] ) )
			{
				blockSelect.midBlockSelect |= 1<<i;
			}

		}

	for(i=0;i<FLASH_HIGHPART_BLOCKCOUNT;i++)
			{

				if( !(startAddr>Flash_Block_High_End_Array[i] || endAddr<Flash_Block_High_Start_Array[i] ) )
				{
					blockSelect.highBlockSelect |= 1<<i;
				}

			}

	for(i=0;i<FLASH_256KPART_BLOCKCOUNT;i++)
			{

				if( !(startAddr>Flash_Block_256K_End_Array[i] || endAddr<Flash_Block_256K_Start_Array[i] ) )
				{
					blockSelect.first256KBlockSelect |= 1<<i;
				}

			}

	//no more 256K block for second256KBlockSelect;



	return blockSelect;
}

/**************************************************************
*                          Disable Flash Cache                *
***************************************************************/
static void DisableFlashControllerCache(uint32_t flashConfigReg,
                                 uint32_t disableVal,
                                 uint32_t *origin_pflash_pfcr)
{
    /* Read the values of the register of flash configuration */
    *origin_pflash_pfcr = REG_READ32(FLASH_FMC + flashConfigReg);

    /* Disable Caches */
    REG_BIT_CLEAR32(FLASH_FMC + flashConfigReg, disableVal);
}

/*****************************************************************
*               Restore configuration register of FCM            *
******************************************************************/
static void RestoreFlashControllerCache(uint32_t flashConfigReg,
                                 uint32_t pflash_pfcr)
{
    REG_WRITE32(FLASH_FMC + flashConfigReg, pflash_pfcr);
}

static void SendMsgInErase(void)
{
	flexcan_msgbuff_t txMsg;

	flexcan_data_info_t dataInfo =
	{
			.data_length = 8U,
			.msg_id_type = FLEXCAN_MSG_ID_STD,
	};

	txMsg.msgId = 0x3F0;
	txMsg.data[0] = 0x03;
	txMsg.data[1] = 0x7F;
	txMsg.data[2] = 0x31;
	txMsg.data[3] = 0x78;
	txMsg.data[4] = 0x0;
	txMsg.data[5] = 0x0;
	txMsg.data[6] = 0x0;
	txMsg.data[7] = 0x0;

	/* Configure TX message buffer with index TX_MSG_ID and TX_MAILBOX*/
	FLEXCAN_DRV_ConfigTxMb(INST_CANCOM0, 2, &dataInfo, txMsg.msgId);

	/* Execute send non-blocking */
	FLEXCAN_DRV_Send(INST_CANCOM0, 2, &dataInfo, txMsg.msgId, txMsg.data);

	while(FLEXCAN_DRV_GetTransferStatus(INST_CANCOM0, 2) == STATUS_SUCCESS);

}

static void UserCallBack(void)
{
    /* increase g_usrCnt */
    g_usrCnt++;
    if(g_usrCnt > 0x20000) {
    	g_usrCnt = 0;
    	WATCHDOG_HAL_Fed();
    	SendMsgInErase();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLASH_HAL_Init
 * Description   : This function initial this module.
 *
 * Implements : FLASH_HAL_Init_Activity
 *END**************************************************************************/
static boolean FLASH_HAL_Init(void)
{
	InitFlashAPI();

    return TRUE;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLASH_HAL_Lock
 * Description   : This function lock from startAddr to endAddr
 *
 * Implements : FLASH_HAL_Init_Activity
 *END**************************************************************************/
static boolean FLASH_HAL_Lock(const uint32 startAddr, const uint32 endAddr)
{
	status_t ret = STATUS_SUCCESS;

	flash_block_select_t blockSelect={.lowBlockSelect=0,.midBlockSelect=0,.highBlockSelect=0,.first256KBlockSelect = 0,.second256KBlockSelect=0};

	//UnLock block
	blockSelect = Flash_GetSelectBlock(startAddr, endAddr);

	//UnLock all block in range
	if(blockSelect.lowBlockSelect!=0)
	{
		ret = SetLock(0, Flash_Block_Lock[0]);
		if (STATUS_SUCCESS != ret)
			return ret;

	}

	if(blockSelect.midBlockSelect!=0)
	{
		ret = SetLock(1, Flash_Block_Lock[1]);
		if (STATUS_SUCCESS != ret)
			return ret;

	}

	if(blockSelect.highBlockSelect!=0)
	{
		ret = SetLock(2, Flash_Block_Lock[2]);
		if (STATUS_SUCCESS != ret)
			return ret;

	}

	if(blockSelect.first256KBlockSelect!=0)
	{
		ret = SetLock(3, Flash_Block_Lock[3]);
		if (STATUS_SUCCESS != ret)
			return ret;

	}


	/* Restore flash controller cache */
	RestoreFlashControllerCache(FLASH_PFCR1, pflash_pfcr1);
	RestoreFlashControllerCache(FLASH_PFCR2, pflash_pfcr2);


	return ret == STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLASH_HAL_Unlock
 * Description   : This function unlock from startAddr to endAddr
 *
 * Implements : FLASH_HAL_Init_Activity
 *END**************************************************************************/
static boolean FLASH_HAL_Unlock(const uint32 startAddr, const uint32 endAddr)
{
	status_t ret = STATUS_SUCCESS;
	uint32_t blkLockState;         /* block lock status to be retrieved */
	flash_block_select_t blockSelect={.lowBlockSelect=0,.midBlockSelect=0,.highBlockSelect=0,.first256KBlockSelect = 0,.second256KBlockSelect=0};


	/* Invalidate flash controller cache */
	DisableFlashControllerCache(FLASH_PFCR1, FLASH_FMC_BFEN_MASK, &pflash_pfcr1);
	DisableFlashControllerCache(FLASH_PFCR2, FLASH_FMC_BFEN_MASK, &pflash_pfcr2);

	/* Flash Initialization */
	ret = FLASH_DRV_Init();
	DEV_ASSERT(ret == STATUS_SUCCESS);

	/**************************************************************************/
	/* Lock to protect UTest address space                                    */
	/**************************************************************************/
	ret = GetLock(C55_BLOCK_UTEST, &blkLockState);

	if (!(blkLockState & 0x00000001U))
	{
		ret = SetLock(C55_BLOCK_UTEST, 0x1U);
		if (STATUS_SUCCESS != ret)
		{
			return ret;
		}
	}

	blockSelect = Flash_GetSelectBlock(startAddr, endAddr);

	//UnLock all block in range
	if(blockSelect.lowBlockSelect!=0)
	{
		ret = SetLock(0, Flash_Block_UnLock[0]);
		if (STATUS_SUCCESS != ret)
			return ret;

	}

	if(blockSelect.midBlockSelect!=0)
		{
			ret = SetLock(1, Flash_Block_UnLock[1]);
			if (STATUS_SUCCESS != ret)
				return ret;

		}

	if(blockSelect.highBlockSelect!=0)
			{
				ret = SetLock(2, Flash_Block_UnLock[2]);
				if (STATUS_SUCCESS != ret)
					return ret;

			}

	if(blockSelect.first256KBlockSelect!=0)
			{
				ret = SetLock(3, Flash_Block_UnLock[3]);
				if (STATUS_SUCCESS != ret)
					return ret;

			}


	return ret == STATUS_SUCCESS;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : FLASH_HAL_EraseSector
 * Description   : This function is erase flash sectors.
 * Parameters	  :  i_startAddr input for start flash address
                        i_noEraseSectors input number of erase sectors
 * Implements : FLASH_HAL_Init_Activity
 *END**************************************************************************/
static boolean FLASH_HAL_Erase(const uint32 startAddr, const uint32 endAddr)
{
	status_t ret = STATUS_SUCCESS;
	flash_state_t opResult;
	flash_block_select_t blockSelect;

	/**************************************************************************/
	/* Call FLASH_DRV_Erase, FLASH_DRV_BlankCheck, FLASH_DRV_Program,         */
	/* FLASH_DRV_ProgramVerify, FLASH_DRV_CheckSum functions                  */
	/**************************************************************************/
//	blockSelect.lowBlockSelect = 0x0U;
//	blockSelect.midBlockSelect = 0x0U;
//	blockSelect.highBlockSelect = 0x4U;
//	blockSelect.first256KBlockSelect = 0x0U;
//	blockSelect.second256KBlockSelect = 0x0U;
	blockSelect = Flash_GetSelectBlock(startAddr,endAddr);
	g_usrCnt = 0U;

	/* Erase block */
	ret = EraseFlash(ERS_OPT_MAIN_SPACE, &blockSelect);
//	ret = FLASH_DRV_Erase(ERS_OPT_MAIN_SPACE, &blockSelect);

	if (STATUS_SUCCESS == ret)
	{
		do
		{
			/* The user can do any tasks while check status function is still in progress */
			UserCallBack();
			ret = CheckEraseStatus(&opResult);
		}while(ret == STATUS_FLASH_INPROGRESS);
	}

	if (STATUS_SUCCESS != ret)
	{
		return ret;
	}

	return ret == STATUS_SUCCESS;

}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLASH_HAL_WriteData
 * Description   : This function is write data in flash. if write write data successfull return TRUE, else return FALSE.
 * Parameters	  :  i_startAddr input for start flash address
                        i_pDataBuf write data buf
                        i_dataLen write data len
 * Implements : FLASH_HAL_Init_Activity
 *END**************************************************************************/

static boolean FLASH_HAL_WriteData(const uint32 startAddr,
								 const uint32 *buffer,
								 const uint32 dataLen)
{
	DisableAllInterrupts();
	status_t ret = STATUS_SUCCESS;
	uint32_t dest;                 /* destination address */
	uint32_t size;                 /* size applicable */
	uint32_t source;               /* source address for program and verify */
	uint32_t numOfWordCycle;
	flash_state_t opResult;
	uint32_t failedAddress;        /* save the failed address in flash */
	uint32_t sum;                  /* check sum result */
	flash_context_data_t pCtxData;

	/* Program to beginning of block */
	dest = startAddr;
	size = dataLen*C55_WORD_SIZE;
	source = (uint32_t)buffer;
	g_usrCnt = 0U;

	ret = ProgramFLASH(&pCtxData,
							dest,
							size,
							source);

//	ret = FLASH_DRV_Program(&pCtxData,
//							dest,
//							size,
//							source);

	if (STATUS_SUCCESS == ret)
	{
		do
		{
			/* The user can do any tasks while check status function is still in progress */
			UserCallBack();
			ret = CheckFlashProgramStatus(&pCtxData, &opResult);
//			ret = FLASH_DRV_CheckProgramStatus(&pCtxData, &opResult);
		}while(ret == STATUS_FLASH_INPROGRESS);
	}

	if (STATUS_SUCCESS != ret)
	{
		return ret;
	}

	numOfWordCycle = NUMBER_OF_WORD_PGM_VERIFY;
	/* Program verify */
	ret = FLASHProgramVerify(dest,
							  size,
							  source,
							  numOfWordCycle,
							  &failedAddress,
							  NULL_CALLBACK);

//	ret = FLASH_DRV_ProgramVerify(dest,
//								  size,
//								  source,
//								  numOfWordCycle,
//								  &failedAddress,
//								  NULL_CALLBACK);

	if (STATUS_SUCCESS != ret)
	{
		return ret;
	}

	numOfWordCycle = NUMBER_OF_WORD_CHECK_SUM;
	/* Check sum */

	ret = FLASHCheckSum(dest,
						 size,
						 numOfWordCycle,
						 &sum,
						 NULL_CALLBACK);


//	ret = FLASH_DRV_CheckSum(dest,
//							 size,
//							 numOfWordCycle,
//							 &sum,
//							 NULL_CALLBACK);

	EnableAllInterrupts();

	if ((STATUS_SUCCESS != ret) && (sum != 0U))
	{
		return ret;
	}

	return ret == STATUS_SUCCESS;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : FLASH_HAL_ReadData
 * Description   : This function is read data in RAM. if read data successfull return TRUE, else return FALSE.
 * Parameters	  :  i_startAddr input for start flash address
                        i_readLen read data length
                        o_pDataBuf read data buf
 * Implements : FLASH_HAL_Init_Activity
 *END**************************************************************************/
static boolean FLASH_HAL_ReadData(const uint32 i_addr)
{
	FLS_DebugPrintf("\n %s\n", __func__);

    //ReadFlashMemory(i_startAddr, i_readLen, o_pDataBuf);
    
	return TRUE;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : FLASH_HAL_Deinit
 * Description   : This function initial this module.
 *
 * Implements : FLASH_HAL_Deinit_Activity
 *END**************************************************************************/
static void FLASH_HAL_Deinit(void)
{
	FLS_DebugPrintf("\n %s\n", __func__);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLASH_HAL_RegisterFlashAPI
 * Description   : This function is register flash API. The API maybe download from host and storage in RAM.
 * 
 *END**************************************************************************/
boolean FLASH_HAL_RegisterFlashAPI(tFlashOperateAPI *o_pstFlashOperateAPI)
{
	boolean result = FALSE;

	if(NULL_PTR != o_pstFlashOperateAPI)
	{
		o_pstFlashOperateAPI->pfFlashInit = FLASH_HAL_Init;
		o_pstFlashOperateAPI->pfFlashLock = FLASH_HAL_Lock;
		o_pstFlashOperateAPI->pfFlashErase = FLASH_HAL_Erase;
		o_pstFlashOperateAPI->pfFlashProgram = FLASH_HAL_WriteData;
		o_pstFlashOperateAPI->pfFlashRead = FLASH_HAL_ReadData;
		o_pstFlashOperateAPI->pfFlashUnlock = FLASH_HAL_Unlock;
		o_pstFlashOperateAPI->pfFlashDeinit = FLASH_HAL_Deinit;

		result = TRUE;
	}

	return result;
}

#ifdef EN_APP_INFO_DATA_IN_NONE_FLASH
/*FUNCTION**********************************************************************
 *
 * Function Name : FLASH_HAL_WriteAPPInfoData
 * Description   : This function is write data in EEPROM or DFLASH. if write write data successfull return TRUE, else return FALSE.
 * Parameters	  : i_startAddr input for start flash address
                    i_pDataBuf write data buf
                    i_dataLen write data len
 * Implements : FLASH_HAL_Init_Activity
 *END**************************************************************************/
boolean FLASH_HAL_WriteAPPInfoData(const uint32 i_startAddr,
								 const uint8 *i_pDataBuf, 
								 const uint32 i_dataLen)
{
    boolean writeStatus = FALSE;

	if((NULL_PTR == i_pDataBuf) || (0u == i_dataLen))
	{
		
	}
	
	return writeStatus;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : FLASH_HAL_ReadAPPInfoData
 * Description   : This function is read data in RAM. if read data successfull return TRUE, else return FALSE.
 * Parameters	  :  i_startAddr input for start flash address
                        i_readLen read data length
                        o_pDataBuf read data buf
 * Implements : FLASH_HAL_Init_Activity
 *END**************************************************************************/
boolean FLASH_HAL_ReadAPPInfoData(const uint32 i_startAddr,
 								 const uint32 i_readLen, 
 					    		 uint8 *o_pDataBuf)
{
	boolean readStatus = FALSE;

	if((0u == i_readLen) || (NULL_PTR == o_pDataBuf))
	{
		return FALSE;
	}
    
	return readStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLASH_HAL_EraseAPPInfoData
 * Description   : This function is erase APP information data.
 * Parameters	  :  i_startAddr input for start flash address
                        i_noEraseSectors input number of erase sectors
 * Implements : FLASH_HAL_Init_Activity
 *END**************************************************************************/
boolean FLASH_HAL_EraseAPPInfoData(const uint32 i_startAddr, const uint32 i_eraseLength)
{
	boolean eraseStatus = FALSE;

	if(0u == i_eraseLength)
	{
		return FALSE;
	}

	return eraseStatus;
}


#endif

/******************************************************************************
 * EOF
 *****************************************************************************/
