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

#ifndef BOOT_CFG_H
#define BOOT_CFG_H

/*******************************************************************************
 * User Include
 ******************************************************************************/
#include "includes.h"

/*! 
 * @file: boot_Cfg.h
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
 * Definitions
 ******************************************************************************/

/*set download app successful */
extern void Boot_SetDownloadAppSuccessful(void);


/*Is request enter bootloader?*/
extern boolean Boot_IsRequestEnterBootloader(void);


/*clear request enter bootloader flag*/
extern void Boot_ClearRequestEnterBootloaderFlag(void);

/*Jump to APP.*/
extern void Boot_JumpToApp(const uint32 i_AppAddr);

/*remap multi-core application*/
extern void Boot_RemapApplication(void);

/*when power on, clear all flag in RAM for ECC.*/
extern void Boot_PowerONClearAllFlag(void);

/*Is power on trigger reset?*/
extern boolean Boot_IsPowerOnTriggerReset(void);

#if defined (__cplusplus)
extern "C" {
#endif

/*******************************************************************************
 * API
 ******************************************************************************/


#if defined (__cplusplus)
}
#endif

#endif /* BOOT_CFG_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/
