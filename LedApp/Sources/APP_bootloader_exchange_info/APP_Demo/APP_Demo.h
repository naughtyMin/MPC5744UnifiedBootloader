/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2018 NXP
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

#ifndef APP_DEMO_H
#define APP_DEMO_H


/*******************************************************************************
 * User Include
 ******************************************************************************/

/*! 
 * @file: APP_Demo.h
 *
 * @brief: Add your description here for this file.
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section Rule_5-5 Rule: 5.5 (Required)
 * Violates MISRA 2012 Required Rule 5.5, identifier clash
 * The supported compilers use more than 31 significant characters for identifiers.
 *
 * @par Version Histroy
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  Tomlin Tang  2020-12-29 09:17:00  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
 */
/*FUNCTION**********************************************************************
 *
 * Function Name : APP_Demo_Init
 * Description	 : APP Demo Init
 *END**************************************************************************/
extern void APP_Demo_Init(void);

/*FUNCTION**********************************************************************
 *
 * Function Name : APP_Demo_MainFun
 * Description   : APP main function called by main
 *END**************************************************************************/
extern void APP_Demo_MainFun(void);

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#if defined (__cplusplus)
extern "C" {
#endif

/*******************************************************************************
 * API
 ******************************************************************************/
 
/*! @}*/
/*!
 * @name Converter
 * Converter specific methods. These are used to configure and use the A/D
 * Converter specific functionality, including:
 *  - clock input and divider
 *  - sample time in A/D clocks
 *  - resolution
 *
 * To start a conversion, a control channel (see \ref chan_config "Channel Configuration")
 * and a trigger source must be configured. Once a conversion is started, the user
 * application can wait for it to be finished by calling the ADC_DRV_WaitConvDone() function.
 *
 * Only the first control channel can be triggered by software.
 *
 */
/*! @{*/


/*! @}*/

#if defined (__cplusplus)
}
#endif

/*! @}*/

#endif /* APP_DEMO_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/
