/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
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
/* ###################################################################
**     Filename    : main.c
**     Processor   : MPC574xP
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.00
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including necessary module. Cpu.h contains other modules needed for compiling.*/
#include "Cpu.h"

volatile int exit_code = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "bootloader_main.h"
#include "TP.h"
#include "flash.h"

flexcan_msgbuff_t g_RXCANMsg;

#define FUN_RX_MAILBOX_ID (0u)
#define PHY_RX_MAILBOX_ID (1u)
#define FUN_RX_MSG_ID (0x7FFu)
#define PHY_RX_MSG_ID (0x784u)

#define TX_MAILBOX_ID (2u)

void CAN_ISR_Callback(uint8_t instance,
		flexcan_event_type_t eventType,
					uint32_t buffIdx,
		 flexcan_state_t *flexcanState)
{
	if(FLEXCAN_EVENT_RX_COMPLETE == eventType)
	{
		if(buffIdx == FUN_RX_MAILBOX_ID) {
			TP_DriverWriteDataInTP(g_RXCANMsg.msgId, g_RXCANMsg.dataLen, g_RXCANMsg.data);
			FLEXCAN_DRV_Receive(INST_CANCOM0, FUN_RX_MAILBOX_ID, &g_RXCANMsg);
		}
		else if(buffIdx == PHY_RX_MAILBOX_ID) {
			TP_DriverWriteDataInTP(g_RXCANMsg.msgId, g_RXCANMsg.dataLen, g_RXCANMsg.data);
			FLEXCAN_DRV_Receive(INST_CANCOM0, PHY_RX_MAILBOX_ID, &g_RXCANMsg);
		}
	}
	else if(FLEXCAN_EVENT_TX_COMPLETE == eventType)
	{
		TP_DoTxMsgSuccesfulCallback();
	}
	else
	{}
}

void AbortTransferMsg(void)
{
	FLEXCAN_DRV_AbortTransfer(INST_CANCOM0, 2u);
}

#define MAX_WAIT_TIME_MS (5000u)
unsigned short g_usMaxDelayUdsMsgTime = MAX_WAIT_TIME_MS;
unsigned char g_ucIsRxUdsMsg = FALSE;

/*
 * @brief Initialize FlexCAN driver and configure the bit rate
 */
void FlexCANInit(void)
{
    /*
     * Initialize FlexCAN driver
     *  - 8 byte payload size
     *  - FD enabled
     *  - Bus clock as peripheral engine clock
     */
	/* Configure RX FIFO */

	FLEXCAN_DRV_Init(INST_CANCOM0, &canCom0_State, &canCom0_InitConfig0);
	FLEXCAN_DRV_InstallEventCallback(INST_CANCOM0, &CAN_ISR_Callback, NULL);
	FLEXCAN_DRV_SetRxFifoGlobalMask(INST_CANCOM0, FLEXCAN_RX_FIFO_ID_FORMAT_A, 0);

	/*Config CAN RX function ID message*/
	flexcan_data_info_t dataInfo =
	{
			.data_length = 8U,
			.msg_id_type = FLEXCAN_MSG_ID_STD,
	};
	FLEXCAN_DRV_ConfigRxMb(INST_CANCOM0, FUN_RX_MAILBOX_ID, &dataInfo,FUN_RX_MSG_ID);
	FLEXCAN_DRV_Receive(INST_CANCOM0, FUN_RX_MAILBOX_ID, &g_RXCANMsg);
	FLEXCAN_DRV_SetRxIndividualMask(INST_CANCOM0, FLEXCAN_MSG_ID_STD, FUN_RX_MAILBOX_ID, 0x7FF);

	/*Config CAN RX physical ID message*/
	FLEXCAN_DRV_ConfigRxMb(INST_CANCOM0, PHY_RX_MAILBOX_ID, &dataInfo, PHY_RX_MSG_ID);
	FLEXCAN_DRV_Receive(INST_CANCOM0, PHY_RX_MAILBOX_ID, &g_RXCANMsg);
	FLEXCAN_DRV_SetRxIndividualMask(INST_CANCOM0, FLEXCAN_MSG_ID_STD, PHY_RX_MAILBOX_ID, 0x7FF);

	/*Config CAN TX message*/
	flexcan_data_info_t dataInfo2 =
	{
			.data_length = 8U,
			.msg_id_type = FLEXCAN_MSG_ID_STD,
	};
	FLEXCAN_DRV_ConfigTxMb(INST_CANCOM0, TX_MAILBOX_ID, &dataInfo2, 0x7F0);
	//CAN_ConfigTxBuff(&can_pal1_instance, gs_CANTxMsgInfo.buffIdx, &gs_CANTxMsgInfo.config);


	//INT_SYS_EnableIRQ(CAN0_ORed_0_15_MB_IRQn);
}

static void BSP_init(void)
{
	/*clock init*/
	CLOCK_SYS_Init(&g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT, &g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
	CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

	WATCHDOG_HAL_Init();

	WATCHDOG_HAL_Fed();

	/*GPIO init*/
	PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);

	FlexCANInit();

	/*init flash*/
	InitFlash();


}

void SendMsgMainFun(void)
{
	flexcan_msgbuff_t txMsg;
	uint32 msgId = 0u;
	uint32 msgLen = 0u;
	status_t status = STATUS_SUCCESS;

	flexcan_data_info_t dataInfo =
	{
			.data_length = 8U,
			.msg_id_type = FLEXCAN_MSG_ID_STD,
	};


	status = FLEXCAN_DRV_GetTransferStatus(INST_CANCOM0, TX_MAILBOX_ID);
	if(STATUS_SUCCESS == status)
	{
		if(TRUE == TP_DriverReadDataFromTP(sizeof(txMsg.data), txMsg.data, &txMsg.msgId, &dataInfo.data_length))
		{
		    /* Configure TX message buffer with index TX_MSG_ID and TX_MAILBOX*/
		    FLEXCAN_DRV_ConfigTxMb(INST_CANCOM0, TX_MAILBOX_ID, &dataInfo, txMsg.msgId);

		    /* Execute send non-blocking */
		    FLEXCAN_DRV_Send(INST_CANCOM0, TX_MAILBOX_ID, &dataInfo, txMsg.msgId, txMsg.data);
		}
	}
}
/*! 
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
    BOOTLOADER_MAIN_Init(&BSP_init, NULL_PTR);

	g_usMaxDelayUdsMsgTime = MAX_WAIT_TIME_MS;

	APP_DebugPrintf("-->Enter MPC5744 CAN/CAN FD(500K) bootloader--<\n");

    for(;;) {
    	BOOTLOADER_MAIN_Demo();

		SendMsgMainFun();
    }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;) {
    if(exit_code != 0) {
      break;
    }
  }
  return exit_code;
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
