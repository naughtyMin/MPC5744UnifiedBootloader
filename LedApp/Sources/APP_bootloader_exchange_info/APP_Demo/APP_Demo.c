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
/*!
 * @file APP_Demo.c
 * 
 * @brief: Add your description here for this file.
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section Rule_11-4 Rule: 11.4 (Advisory)
 * Violates MISRA 2012 Advisory Rule 11.4, Conversion between a pointer and integer type.
 * The cast is required to initialize a pointer with an unsigned long define, representing an address.
 *
 * @section Rule_11-6 Rule: 11.6 (Required)
 * Violates MISRA 2012 Required Rule 11.6, Cast from unsigned int to pointer.
 * The cast is required to initialize a pointer with an unsigned long define, representing an address.
 *
 * @par Version Histroy
<pre><b>
Version:   Author:       Date&&Time:      Revision Log: </b>
 V1.0.0  Tomlin Tang  2020-12-29 09:17:00  First Creat
When you update, please do not forgot to del me and add your info at here.
</pre>
 */

#include "APP_Demo.h"
#include "Cpu.h"
#include "UDS_app.h"
#include "TP.h"
#include "bootloader_debug.h"


/*******************************************************************************
 * User Include
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* User includes (#include below this line is not maintained by Processor Expert) */
#define FUN_RX_MAILBOX_ID (0u)
#define PHY_RX_MAILBOX_ID (1u)
#define FUN_RX_MSG_ID (0x7FFu)
#define PHY_RX_MSG_ID (0x784u)
#define TX_MAILBOX_ID (2u)

flexcan_msgbuff_t g_RXCANMsg;

/*CAN RX and TX message call back handle*/
static void CAN_ISR_Callback(uint8_t instance,
		flexcan_event_type_t eventType,
					uint32_t buffIdx,
		 flexcan_state_t *flexcanState);

static void BSP_Init(void);

static void SendMsgMainFun(void);


/*FUNCTION**********************************************************************
 *
 * Function Name : APP_Demo_Init
 * Description   : APP Demo Init
 *END**************************************************************************/
void APP_Demo_Init(void)
{
	BSP_Init();

	UDS_Init();

	TP_Init();

	Boot_CheckDownlaodAPPStatus();

	WATCHDOG_HAL_Fed();

	APPDebugPrintf("Welcome enter MPC5744 CAN/CAN FD(Nomial:500K, data:500K) APP demo!\n");
}

/*FUNCTION**********************************************************************
 *
 * Function Name : APP_Demo_MainFun
 * Description   : APP main function called by main
 *END**************************************************************************/
void APP_Demo_MainFun(void)
{
	static uint16 ledCnt = 0u;

	if(TRUE == TIMER_HAL_Is1msTickTimeout())
	{
		TP_SystemTickCtl();

		UDS_SystemTickCtl();

		ledCnt++;
	}

	if(ledCnt >= 250u)
	{
		ToggleDebugIO();

		ledCnt = 0u;
	}

	if(TRUE == TIMER_HAL_Is100msTickTimeout())
	{
		WATCHDOG_HAL_Fed();
	}

	TP_MainFun();

	UDS_MainFun();

	SendMsgMainFun();
}

/*CAN RX and TX message call back handle*/
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

void SendMsgMainFun(void)
{
	//flexcan_msgbuff_t txMsg;
	uint8 data[64] = {0};
	uint32 msgId = 0u;
	uint32 dataLen = 0u;
	status_t status = STATUS_SUCCESS;

	flexcan_data_info_t dataInfo =
	{
			.data_length = 8U,
			.msg_id_type = FLEXCAN_MSG_ID_STD,
	};

	/*USPRG0=0x3C means the program reset in BOOT*/
//	if((MFSPR(256) == 0x3C)) {
//		data[0] = 0x02;
//		data[1] = 0x51;
//		data[2] = 0x01;
//		msgId = 0x7F0;
//		dataLen = 3;
//		/* Configure TX message buffer with index TX_MSG_ID and TX_MAILBOX*/
//		FLEXCAN_DRV_ConfigTxMb(INST_CANCOM0, TX_MAILBOX_ID, &dataInfo, msgId);
//
//		/* Execute send non-blocking */
//		FLEXCAN_DRV_Send(INST_CANCOM0, TX_MAILBOX_ID, &dataInfo, msgId, data);
//
//		while(FLEXCAN_DRV_GetTransferStatus(INST_CANCOM0, TX_MAILBOX_ID) != STATUS_SUCCESS);
//
//		//清除APP跳转标志
//		MTSPR(256, 0x0);
//	}


	status = FLEXCAN_DRV_GetTransferStatus(INST_CANCOM0, TX_MAILBOX_ID);
	if(STATUS_SUCCESS == status)
	{
		if(TRUE == TP_DriverReadDataFromTP(sizeof(data), data, &msgId, &dataLen))
		{
		    /* Configure TX message buffer with index TX_MSG_ID and TX_MAILBOX*/
		    FLEXCAN_DRV_ConfigTxMb(INST_CANCOM0, TX_MAILBOX_ID, &dataInfo, msgId);

		    /* Execute send non-blocking */
		    FLEXCAN_DRV_Send(INST_CANCOM0, TX_MAILBOX_ID, &dataInfo, msgId, data);
		}
	}
}

/*
 * @brief Initialize FlexCAN driver and configure the bit rate
 */
static void FlexCANInit(void)
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

	/* Configure TX message buffer with index TX_MSG_ID and TX_MAILBOX*/
	FLEXCAN_DRV_ConfigTxMb(INST_CANCOM0, TX_MAILBOX_ID, &dataInfo2, 0x7F0);
	//CAN_ConfigTxBuff(&can_pal1_instance, gs_CANTxMsgInfo.buffIdx, &gs_CANTxMsgInfo.config);

	//INT_SYS_EnableIRQ(CAN0_ORed_0_15_MB_IRQn);
}


static void BSP_Init(void)
{
	CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT, g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
	CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

	PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);

	FlexCANInit();

//	INT_SYS_EnableIRQ(CAN0_ORed_0_15_MB_IRQn);
//
//	INT_SYS_EnableIRQGlobal();
	
	WATCHDOG_HAL_Init();

	TIMER_HAL_Init();

	BOOTLOADER_DEBUG_Init();
}

/******************************************************************************
 * EOF
 *****************************************************************************/
