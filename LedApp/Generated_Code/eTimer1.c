/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : eTimer1.c
**     Project     : LedApp
**     Processor   : MPC5744P_257
**     Component   : etimer
**     Version     : Component SDK_S32_PA_11, Driver 01.00, CPU db: 3.00.000
**     Repository  : SDK_S32_PA_11
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-03, 11:30, # CodeGen: 3
**
**     Copyright 1997 - 2015 Freescale Semiconductor, Inc. 
**     Copyright 2016-2017 NXP 
**     All Rights Reserved.
**     
**     THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
**     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
**     OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
**     IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
**     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
**     SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
**     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
**     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
**     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
**     THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file eTimer1.c
** @version 01.00
*/         
/*!
**  @addtogroup eTimer1_module eTimer1 module documentation
**  @{
*/         

/* MODULE eTimer1. */

/**
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External could be made static.
 * Function is defined for usage by application code.
 */

#include "eTimer1.h"

/*! eTimer1 Channel 0 configuration structure */
const etimer_user_channel_config_t eTmr0Ch3Cfg = {
   .countMode = ETIMER_CNTMODE_PRIMARY,
   .inputFilter = 
   {
       .samples = ETIMER_FILT_CNT_3,
       .rate = 0,
   },
   .primaryInput = 
   {
       .source = ETIMER_IN_SRC_CLK_DIV_1,
       .polarity = ETIMER_POLARITY_POSITIVE,
   },
   .secondaryInput = 
   {
       .source = ETIMER_IN_SRC_CNT0_IN,
       .polarity = ETIMER_POLARITY_POSITIVE,
   },
   .outputPin = 
   {
       .enable = false,
       .polarity = ETIMER_POLARITY_POSITIVE,
   },
   .countDirection = ETIMER_COUNT_UP,
   .compareValues = 
   {
       16000,
       0,
   },
   .compareLoading = 
   {
       ETIMER_CLC_NEVER,
       ETIMER_CLC_CNTR_WITH_CMPLD_WHEN_COMP1,
   },
   .compareOutputControl = ETIMER_OUTMODE_SOFTWARE,
   .compareMode = ETIMER_CMPMODE_COMP1_UP_COMP2_UP,
   .captureControl = 
   {
       ETIMER_CPTMODE_DISABLED,
       ETIMER_CPTMODE_DISABLED,
   },
   .captureWords = 0,
   .interruptEnableMask = 0,
   .oneshotCapture = false,
   .countOnce = false,
   .redundant = false,
   .masterMode = false,
   .coChannelForce = false,
   .coChannelInit = ETIMER_COINIT_NONE,
   .coChannelVal = false,
   .countLength = true,
};

const etimer_dma_channel_t eTimer1_etimer_dma_channel0 = {
  .enable = false,
  .request = ETIMER_DMA_CH0_CAPT1,
};


/* END eTimer1. */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.1 [05.21]
**     for the NXP C55 series of microcontrollers.
**
** ###################################################################
*/

