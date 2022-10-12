/*
** ###################################################################
**     Processor:           MPC5744P
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright (c) 2015 Freescale Semiconductor, Inc.
**     Copyright 2016-2017 NXP
**     All rights reserved.
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
**
**
** ###################################################################
*/

/**
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.9, An object should be defined at block
 * scope if its identifier only appears in a single function.
 * An object with static storage duration declared at block scope cannot be
 * accessed directly from outside the block.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 11.4, Conversion between a pointer and
 * integer type.
 * The cast is required to initialize a pointer with an unsigned int define,
 * representing a memory-mapped address.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 11.6, Cast from pointer to unsigned int.
 * The cast is required to initialize a pointer with an unsigned int define,
 * representing a memory-mapped address.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External could be made static.
 * Function is defined for usage by application code.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External could be made static.
 * Function is defined for usage by application code.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 11.1, Conversions shall not be performed
 * between a pointer to a function and any other type.
 * This is required in order to write the prefix of the interrupt vector table.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.9, An object should be defined at block
 * scope if its identifier only appears in a single function.
 * All variables with this problem are defined in the linker files.
 *
 */

/*!
 * @file MPC5744P
 * @version 1.0
 * @date 2017-02-14
 * @brief Device specific configuration file for MPC5744P (implementation file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#include <stdint.h>
#include "system_MPC5744P.h"


/* ----------------------------------------------------------------------------
   -- Core clock
   ---------------------------------------------------------------------------- */

uint32_t SystemCoreClock = DEFAULT_SYSTEM_CLOCK;

/*FUNCTION**********************************************************************
 *
 * Function Name : SystemInit
 * Description   : Typically this function initializes interrupt controller
 * for current core and grants access to peripherals for DMA.
 * SystemInit is called from startup_device file.
 *
 * Implements    : SystemInit_Activity
 *END**************************************************************************/
void SystemInit(void) 
{
/**************************************************************************/
                      /* FPU ENABLE*/
/**************************************************************************/
#ifdef ENABLE_FPU
//TODO: Support FPU
#endif /* ENABLE_FPU */
#if INIT_INTERRUPT_CONTROLLER

  /* Software vector mode used for core 0 */
  INTC->BCR &= ~(INTC_BCR_HVEN0_MASK);
  /* Lower core 0's INTC current priority to 0 */
  INTC->CPR0 = 0U;

  /* Initialize core's spr IVPR register*/
  MTSPR(63,(uint32_t)&VTABLE);
#endif

/**************************************************************************/
            /* GRANT ACCESS TO PERIPHERALS FOR DMA MASTER */
/**************************************************************************/
#if ENABLE_DMA_ACCESS_TO_PERIPH
  /* DMA trusted for read/writes in supervisor & user modes on peripheral bridge A */
  AIPS_A->MPRA |= AIPS_MPRA_MPL2_MASK;
  AIPS_A->MPRA |= AIPS_MPRA_MTW2_MASK;
  AIPS_A->MPRA |= AIPS_MPRA_MTR2_MASK;
  /* DMA trusted for read/writes in supervisor & user modes on peripheral bridge B */
  AIPS_B->MPRA |= AIPS_MPRA_MPL2_MASK;
  AIPS_B->MPRA |= AIPS_MPRA_MTW2_MASK;
  AIPS_B->MPRA |= AIPS_MPRA_MTR2_MASK;
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SystemCoreClockUpdate
 * Description   : This function must be called whenever the core clock is changed
 * during program execution. It evaluates the clock register settings and calculates
 * the current core clock.
 *
 * Implements    : SystemCoreClockUpdate_Activity
 *END**************************************************************************/
void SystemCoreClockUpdate(void) 
{
    uint32_t SYSClock = 0U;
    uint32_t PLL_0Clock = 0U;
    uint32_t PLL_1Clock = 0U;
    uint32_t divPLL_0_PHI_0, divPLL_0_PHI_1, divPLL_1_PHI_0, predivPLL_0, multiPLL_0, multiPLL_1;
    bool validSystemClockSource = true;
    bool validPLL_0ClockSource = true;
    bool validPLL_1ClockSource = true;

    /* Multiplication factor divider for PLL0 and PLL1 */
    multiPLL_0 = (PLLDIG->PLL0DV & PLLDIG_PLL0DV_MFD_MASK) >> PLLDIG_PLL0DV_MFD_SHIFT;
    multiPLL_1 = (PLLDIG->PLL1DV & PLLDIG_PLL1DV_MFD_MASK) >> PLLDIG_PLL1DV_MFD_SHIFT;

    /* Input clock pre-divider */
    if (((PLLDIG->PLL0DV & PLLDIG_PLL0DV_PREDIV_MASK) >> PLLDIG_PLL0DV_PREDIV_SHIFT) != 0u) 
    {
        predivPLL_0 = (PLLDIG->PLL0DV & PLLDIG_PLL0DV_PREDIV_MASK) >> PLLDIG_PLL0DV_PREDIV_SHIFT;
    }
    else 
    {
        predivPLL_0 = 0;
        validPLL_0ClockSource = false;
    }

    /* PHI reduced frequency divider */
    divPLL_0_PHI_0 = (PLLDIG->PLL0DV & PLLDIG_PLL0DV_RFDPHI_MASK) >> PLLDIG_PLL0DV_RFDPHI_SHIFT;
    divPLL_0_PHI_1 = (PLLDIG->PLL0DV & PLLDIG_PLL0DV_RFDPHI1_MASK) >> PLLDIG_PLL0DV_RFDPHI1_SHIFT;
    divPLL_1_PHI_0 = (PLLDIG->PLL1DV & PLLDIG_PLL1DV_RFDPHI_MASK) >> PLLDIG_PLL1DV_RFDPHI_SHIFT;

    /* PLL0 out clock */
    if ((MC_CGM->AC3_SC & MC_CGM_AC3_SC_SELCTL_MASK) == 0U) 
    {
        PLL_0Clock = CPU_INT_FAST_CLK_HZ;
    }
    else
    {
        PLL_0Clock = CPU_EXT_FAST_CLK_HZ;
    }

    /* PLL1 out clock */
    switch ((MC_CGM->AC4_SC & MC_CGM_AC4_SC_SELCTL_MASK) >> MC_CGM_AC4_SC_SELCTL_SHIFT) 
    {
        case 0x1:
            PLL_1Clock = CPU_EXT_FAST_CLK_HZ;
            break;
        case 0x3:
            if (validPLL_0ClockSource)
            {
                if (predivPLL_0 != 0u)
                {
                    PLL_1Clock = PLL_0Clock * multiPLL_0 / (predivPLL_0 * divPLL_0_PHI_1);
                }
            }
            else 
            {
                validPLL_1ClockSource = false;
                break;
            }
            break;
        default:
            validPLL_1ClockSource = false;
            break;
    }

    /* System out clock */
    switch ((MC_ME->GS & MC_ME_GS_S_SYSCLK_MASK) >> MC_ME_GS_S_SYSCLK_SHIFT) 
    {
        case 0x0:
            /* 16MHz IRCOSC */
            SYSClock = CPU_INT_FAST_CLK_HZ;
            break;
        case 0x1:
            /* XOSC */
            SYSClock = CPU_EXT_FAST_CLK_HZ;
            break;
        case 0x2:
            /* primary PLL */
            if (validPLL_0ClockSource && (predivPLL_0 != 0U)) 
            {
                SYSClock = PLL_0Clock * multiPLL_0 / (predivPLL_0 * divPLL_0_PHI_0);
            }
            else 
            {
                validSystemClockSource = false;
            }
            break;
        case 0x4:
            /* secondary PLL */
            if (validPLL_1ClockSource) 
            {
                SYSClock = PLL_1Clock * multiPLL_1/divPLL_1_PHI_0;
            }
            else 
            {
                validSystemClockSource = false;
            }
            break;
        default:
            validSystemClockSource = false;
            break;
    }

    if (validSystemClockSource == true) 
    {
        SystemCoreClock = SYSClock;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SystemSoftwareReset
 * Description   : This function is used to initiate a 'functional' reset event
 * to the microcontroller. The reset module will do a state machine from
 * PHASE1->PHASE2->PHASE3->IDLE.
 *
 * Implements    : SystemSoftwareReset_Activity
 *END**************************************************************************/
void SystemSoftwareReset(void)
{
    MC_ME->MCTL = FEATURE_MC_ME_KEY;
    MC_ME->MCTL = MC_ME_MCTL_TARGET_MODE(0x00) | FEATURE_MC_ME_KEY_INV;
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
