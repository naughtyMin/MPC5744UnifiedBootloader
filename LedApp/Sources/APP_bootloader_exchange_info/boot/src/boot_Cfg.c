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
 * @file boot_Cfg.c
 * 
 * @brief: Add your description here for this file.
 *
 * @par Version Histroy
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  Tomlin Tang  2019-01-31 09:51:53  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
 */


/*******************************************************************************
 * User Include
 ******************************************************************************/
#include "boot_cfg.h"

#include "CRC_hal.h"

/*******************************************************************************
 * Variables
 ******************************************************************************/
typedef struct
{
	uint8 infoDataLen;             /*Exchange inforamtion length must N * 4.*/
	uint8 requestEnterBootloader;  /*Request enter bootloader mode flag*/
	uint8 downloadAPPSuccessful;   /*downlaod APP successful flag*/
	uint32 infoStartAddr;          /*exchange information start address*/
	uint32 requestEnterBootloaderAddr; /*Request enter bootloader flag address */
	uint32 downloadAppSuccessfulAddr;  /*download APP successful flag address*/
}tBootInfo;

const static tBootInfo gs_stBootInfo = {
	16u,    /*Exchange inforamtion length must N * 4.*/
	0x5Au,  
	0xA5u,
	0x4005FFF0u,
	0x4005FFF1u,
	0x4005FFF0u,
};

/*get information storage CRC*/
#define GetInfoStorageCRC() (*(uint16 *)(gs_stBootInfo.infoStartAddr + 14))

/*set information CRC */
#define SetInforCRC(xCrc) ((*(uint16 *)(gs_stBootInfo.infoStartAddr + 14)) = (uint16)(xCrc))

/*Is information valid?*/
static boolean Boot_IsInfoValid(void);

/*calculate information CRC*/
static uint16 Boot_CalculateInfoCRC(void);

/*set download app successful */
void SetDownloadAppSuccessful(void)
{
	uint16 infoCrc = 0u;

	*((uint8 *)gs_stBootInfo.downloadAppSuccessfulAddr) = gs_stBootInfo.downloadAPPSuccessful;

	infoCrc = Boot_CalculateInfoCRC();
	SetInforCRC(infoCrc);
}

/*Is request enter bootloader?*/
void Boot_RequestEnterBootloader(void)
{
	uint16 infoCrc = 0u;

	*((uint8 *)gs_stBootInfo.requestEnterBootloaderAddr) = gs_stBootInfo.requestEnterBootloader;

	infoCrc = Boot_CalculateInfoCRC();
	SetInforCRC(infoCrc);
}

/*Is download APP successful?*/
boolean Boot_IsDownloadAPPSccessful(void)
{
	boolean result = FALSE;

	if(TRUE == Boot_IsInfoValid())
	{
		if(gs_stBootInfo.downloadAPPSuccessful == *((uint8 *)gs_stBootInfo.downloadAppSuccessfulAddr))
		{
			result = TRUE;
		}
	}
	
	return result;	
}

/*clear download APP successful flag*/
void ClearDownloadAPPSuccessfulFlag(void)
{
	uint16 infoCrc = 0u;

	*((uint8 *)gs_stBootInfo.downloadAppSuccessfulAddr) = 0u;

	infoCrc = Boot_CalculateInfoCRC();
	SetInforCRC(infoCrc);
}

/*Is information valid?*/
static boolean Boot_IsInfoValid(void)
{
	uint16 infoCrc = 0u;
	uint16 storageCrc = 0u;
	boolean result = FALSE;
	
	infoCrc = Boot_CalculateInfoCRC();

	storageCrc = GetInfoStorageCRC();

	if(storageCrc == infoCrc)
	{
		result = TRUE;
	}

	return result;
}

/*calculate information CRC*/
static uint16 Boot_CalculateInfoCRC(void)
{
	uint32 infoCrc = 0u;

	CRC_HAL_CalculateCRCOnce((const uint8 *)gs_stBootInfo.infoStartAddr, gs_stBootInfo.infoDataLen - 2u, &infoCrc);

	return (uint16)infoCrc;
}


/******************************************************************************
 * EOF
 *****************************************************************************/
