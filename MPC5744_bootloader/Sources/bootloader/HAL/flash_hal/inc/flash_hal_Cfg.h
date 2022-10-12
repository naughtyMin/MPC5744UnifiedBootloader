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

#ifndef FLASH_HAL_CFG_H
#define FLASH_HAL_CFG_H
#include "includes.h"

/*******************************************************************************
 * User Include
 ******************************************************************************/

/*! 
 * @file: flash_hal_Cfg.h
 *
 * @brief: Add your description here for this file.
 *
 * @par Version Histroy
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  Tomlin Tang  2019-01-17 15:51:03  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
typedef uint32 tLogicalAddr;

typedef struct
{
	tLogicalAddr xBlockStartLogicalAddr; /*block start logical addr*/
	tLogicalAddr xBlockEndLogicalAddr;	 /*block end logical addr*/
}BlockInfo_t;


#if defined (__cplusplus)
extern "C" {
#endif

/*program data buf max length*/
#define MAX_FLASH_DATA_LEN (200u)

#if 0
/*startup address*/
#define STARTUP_ADDR (0xFFFEu) 
#endif

/*******************************************************************************
 * API
 ******************************************************************************/

/*check flash config valid or not?*/
extern boolean FLASH_HAL_APPAddrCheck(void);

/*Get configure flash information*/
extern	boolean FLASH_HAL_GetFlashConfigInfo(const tAPPType i_appType,BlockInfo_t ** o_ppBlockInfo, uint32 *o_pItemLen);

/*get application information(storage start address, block size)*/
extern 	boolean FLASH_HAL_GetAPPInfo(const tAPPType i_appType, uint32 *o_pAppInfoStartAddr, uint32 *o_pBlockSize);

/*get secotr length*/
extern uint32 FLASH_HAL_GetFlashLengthToSectors(const uint32 i_startFlashAddr, const uint32 i_len);

/*get flash driver start and length*/
extern boolean FLASH_HAL_GetFlashDriverInfo(uint32 *o_pFlashDriverAddrStart, uint32 *o_pFlashDriverEndAddr);

/*get reset handler information*/
extern void FLASH_HAL_GetRestHanlderInfo(boolean *o_pIsEnableWriteResetHandlerInFlash, uint32 *o_pResetHanderOffset, uint32* o_pResetHandlerLength);

/*Get storage reset handler infomation*/
extern uint32 FLASH_HAL_GetStorageRestHandlerAddr(void);

/*Is enable write reset handler in flash?*/
extern boolean FLASH_HAL_IsEnableStorageResetHandlerInFlash(void);

/*get reset handler addr length*/
extern uint32 FLASH_HAL_GetResetHandlerLen(void);

/*Get config core no*/
extern uint32 FLASH_HAL_GetConfigCoreNo(void);

/*Get config core application mirror address*/
extern boolean FLASH_HAL_GetMultiCoreMirrorAddr(const tAPPType i_appType, const uint32 i_coreNo, uint32 *o_pMirrorAddr);

/*Get core remap address*/
extern boolean FLASH_HAL_GetMultiCoreRemapAddr(const tAPPType i_appType, const uint32 i_coreNo, uint32 *o_pReampAddr);

/*logical address to physical address*/
extern uint32 FLASH_HAL_LogicalToPhysicalAddr(const uint32 i_logicalAddr);

/*global address to logical address*/
extern uint32 FLASH_HAL_PhysicalToLogicalAddr(const uint32 i_globalAddr);

/*get erase flash sector max time*/
extern uint32 FLASH_HAL_GetEraseFlashASectorMaxTimeMs(void);

/*get total how much sectors in flash*/
extern uint32 FLASH_HAL_GetTotalSectors(const tAPPType i_appType);

/*sector number to flash address*/
extern boolean FLASH_HAL_SectorNumberToFlashAddress(const tAPPType i_appType, const uint32 i_secotrNo, uint32 *o_pFlashAddr);

/*get 1 sector = bytes*/
extern uint32 FLASH_HAL_Get1SectorBytes(void);

#if defined (__cplusplus)
}
#endif

#endif /* FLASH_HAL_CFG_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/
