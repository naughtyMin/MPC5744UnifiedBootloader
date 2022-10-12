/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : wdg_pal1.h
**     Project     : LedApp
**     Processor   : MPC5744P_257
**     Component   : wdg_pal
**     Version     : Component SDK_S32_PA_11, Driver 01.00, CPU db: 3.00.000
**     Repository  : SDK_S32_PA_11
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-03, 11:36, # CodeGen: 4
**     Contents    :
**         WDG_Init             - status_t WDG_Init(const wdg_instance_t * const instance, const wdg_config_t *...
**         WDG_Deinit           - status_t WDG_Deinit(const wdg_instance_t * const instance);
**         WDG_GetDefaultConfig - void WDG_GetDefaultConfig(wdg_config_t * const config);
**         WDG_Refresh          - void WDG_Refresh(const wdg_instance_t * const instance);
**         WDG_SetInt           - status_t WDG_SetInt(const wdg_instance_t * const instance, bool enable);
**         WDG_SetTimeout       - status_t WDG_SetTimeout(const wdg_instance_t * const instance, uint32_t value);
**         WDG_SetWindow        - status_t WDG_SetWindow(uint32_t instance, bool enable, uint32_t Value);
**         WDG_GetCounter       - status_t WDG_GetCounter(const wdg_instance_t * const instance, uint32_t *...
**         WDG_ClearIntFlag     - void WDG_ClearIntFlag(const wdg_instance_t * const instance);
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
** @file wdg_pal1.h
** @version 01.00
*/         
/*!
**  @addtogroup wdg_pal1_module wdg_pal1 module documentation
**  @{
*/         

/*!
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, global macro not referenced
 * There are global macros defined to be used by the integrator and another one used as include guard.
 */

#ifndef WDG_PAL1_H
#define WDG_PAL1_H

/* MODULE wdg_pal1. */

/* Include inherited beans */
#include "clockMan1.h"
#include "Cpu.h"



/*! @brief Number of user configuration */
#define WDG_PAL1_NUM_OF_USER_CFG    (1U)

/*! @brief Structure storing PAL instance information */
extern const wdg_instance_t wdg_pal1_Instance;

/*! @brief Serial module configurations */
extern const wdg_config_t watchdog1_Config0;




#endif
/* ifndef WDG_PAL1_H */
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

