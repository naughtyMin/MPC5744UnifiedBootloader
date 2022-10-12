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
 * @file timer_hal.c
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
 V1.0.0  Tomlin Tang  2019-01-17 15:30:01  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
 */

#include "timer_hal.h"

/*******************************************************************************
 * User Include
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
static uint16 gs_1msCnt = 0u;
static uint16 gs_100msCnt = 0u;

void ETIMER0_Ch3_IRQHandler(void)
{
	TIMER_HAL_1msPeriod();
	ETIMER_DRV_ClearInterruptStatus(INST_ETIMER1,ETIMER_CH_IRQ_FLAGS_TCF1,3);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : TIMER_HAL_Init
 * Description   : This function initial this module.
 *
 * Implements : TIMER_HAL_Init_Activity
 *END**************************************************************************/
void TIMER_HAL_Init(void)
{
	/* initialize ETIMERx peripheral */
	ETIMER_DRV_Init(INST_ETIMER1);
	/* setup ETIMERx channels */
	ETIMER_DRV_InitChannel(INST_ETIMER1, 3, &eTmr0Ch3Cfg);
	/* Enable ETIMER0 channel 3 interrupt and install an ISR */
	IRQn_Type etimer0_ch3_irq_id = ETIMER_DRV_GetInterruptNumber(0,ETIMER_IRQ_CH3);
	INT_SYS_InstallHandler(etimer0_ch3_irq_id, &ETIMER0_Ch3_IRQHandler, (isr_t*) 0);
	INT_SYS_EnableIRQ(etimer0_ch3_irq_id);
	/* enable interrupts */
	ETIMER_DRV_EnableInterruptSource(INST_ETIMER1,ETIMER_CH_IRQ_FLAGS_TCF1,3);
	/* start channel operation */
	ETIMER_DRV_StartTimerChannels(INST_ETIMER1, ETIMER_ENABLE_CH3);
}

/*Timer 1ms period called*/
void TIMER_HAL_1msPeriod(void)
{
    uint16 cntTmp = 0u;

    /*Just for check time overflow or not?*/
    cntTmp = gs_1msCnt + 1u;
    if(0u != cntTmp)
    {
        gs_1msCnt++;
    }

    cntTmp = gs_100msCnt + 1u;
    if(0u != cntTmp)
    {
        gs_100msCnt++;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : TIMER_HAL_Is1msTickTimeout
 * Description   : This function is check timeout. If timeout return TRUE, else return FALSE.
 *
 * Implements : Is1msTickTimeout_Activity
 *END**************************************************************************/
boolean  TIMER_HAL_Is1msTickTimeout(void)
{
    boolean result = FALSE;

    if(gs_1msCnt > 0)
    {
        result = TRUE;

        gs_1msCnt = 0u;
    }

    return result;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : TIMER_HAL_Is10msTickTimeout
 * Description   : This function is check timeout or not. If timeout return TRUE, else return FALSE.
 *
 * Implements : Is10msTickTimeout_Activity
 *END**************************************************************************/

boolean TIMER_HAL_Is100msTickTimeout(void)
{
    boolean result = FALSE;

    if(gs_100msCnt >= 100u)
    {
        result = TRUE;

        gs_100msCnt = 0u;
    }

    return result;
}

/*get timer tick cnt for random seed.*/
uint32 TIMER_HAL_GetTimerTickCnt(void)
{
	/*This two variables not init before used, because it used for generate random*/
	uint32 hardwareTimerTickCnt;
	uint32 timerTickCnt;
	
#if 0
	/*For S32K1xx get timer counter(LPTIMER), get timer count will trigger the period incorrect.*/
	hardwareTimerTickCnt = LPTMR_DRV_GetCounterValueByCount(INST_LPTMR1);
#endif

	timerTickCnt = ((hardwareTimerTickCnt & 0xFFFFu)) | (timerTickCnt << 16u);


	return timerTickCnt;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : TIMER_HAL_Deinit
 * Description   : This function initial this module.
 *
 * Implements : TIMER_HAL_Deinit_Activity
 *END**************************************************************************/
void TIMER_HAL_Deinit(void)
{


}
/******************************************************************************
 * EOF
 *****************************************************************************/
