///*
// * test.c
// *
// *  Created on: 2022Äê9ÔÂ20ÈÕ
// *      Author: DELL
// */
//#include "Cpu.h"
//#include "test.h"
//
//flexcan_msgbuff_t g_RXCANMsg;
//
///*CAN RX and TX message call back handle*/
//void CAN_ISR_Callback(uint8_t instance,
//		flexcan_event_type_t eventType,
//					uint32_t buffIdx,
//		 flexcan_state_t *flexcanState)
//{
//	if(FLEXCAN_EVENT_RX_COMPLETE == eventType)
//	{
//		if(buffIdx == FUN_RX_MAILBOX_ID) {
//			//TP_DriverWriteDataInTP(g_RXCANMsg.msgId, g_RXCANMsg.dataLen, g_RXCANMsg.data);
//			FLEXCAN_DRV_Receive(INST_CANCOM0, FUN_RX_MAILBOX_ID, &g_RXCANMsg);
//		}
//		else if(buffIdx == PHY_RX_MAILBOX_ID) {
//			//TP_DriverWriteDataInTP(g_RXCANMsg.msgId, g_RXCANMsg.dataLen, g_RXCANMsg.data);
//			FLEXCAN_DRV_Receive(INST_CANCOM0, PHY_RX_MAILBOX_ID, &g_RXCANMsg);
//		}
//	}
//	else if(FLEXCAN_EVENT_TX_COMPLETE == eventType)
//	{
//		//TP_DoTxMsgSuccesfulCallback();
//	}
//	else
//	{}
//}
//
//void SendMsgMainFun(void)
//{
//	flexcan_msgbuff_t txMsg;
//	uint32_t msgId = 0u;
//	uint32_t msgLen = 0u;
//	status_t status = STATUS_SUCCESS;
//
//    flexcan_data_info_t dataInfo =
//    {
//    		.is_remote = false,
//            .msg_id_type = FLEXCAN_MSG_ID_STD,
//			.data_length = 8,
//    };
//
//
//    status = FLEXCAN_DRV_GetTransferStatus(INST_CANCOM0, TX_MAILBOX_ID);
//	if(STATUS_SUCCESS == status)
//	{
////		if(TRUE == TP_DriverReadDataFromTP(sizeof(txMsg.data), txMsg.data, &txMsg.msgId, &dataInfo.data_length))
////		{
//		    /* Configure TX message buffer with index TX_MSG_ID and TX_MAILBOX*/
//		    FLEXCAN_DRV_ConfigTxMb(INST_CANCOM0, TX_MAILBOX_ID, &dataInfo, txMsg.msgId);
//
//		    /* Execute send non-blocking */
//		    FLEXCAN_DRV_Send(INST_CANCOM0, TX_MAILBOX_ID, &dataInfo, txMsg.msgId, txMsg.data);
////		}
//	}
//}
//
//static void FlexCANInit(void)
//{
//	/* Configure RX FIFO */
//
//	FLEXCAN_DRV_Init(INST_CANCOM0, &canCom0_State, &canCom0_InitConfig0);
//	FLEXCAN_DRV_InstallEventCallback(INST_CANCOM0, &CAN_ISR_Callback, NULL);
//	//INT_SYS_EnableIRQ(CAN0_ORed_0_15_MB_IRQn);
//	FLEXCAN_DRV_SetRxFifoGlobalMask(INST_CANCOM0, FLEXCAN_RX_FIFO_ID_FORMAT_A, 0);
//
//	/*Config CAN RX function ID message*/
//	flexcan_data_info_t dataInfo =
//	{
//			.data_length = 8U,
//			.msg_id_type = FLEXCAN_MSG_ID_STD,
//	};
//	FLEXCAN_DRV_ConfigRxMb(INST_CANCOM0, FUN_RX_MAILBOX_ID, &dataInfo,FUN_RX_MSG_ID);
//	FLEXCAN_DRV_Receive(INST_CANCOM0, FUN_RX_MAILBOX_ID, &g_RXCANMsg);
//	FLEXCAN_DRV_SetRxIndividualMask(INST_CANCOM0, FLEXCAN_MSG_ID_STD, FUN_RX_MAILBOX_ID, 0x7FF);
//
//	/*Config CAN RX physical ID message*/
//	FLEXCAN_DRV_ConfigRxMb(INST_CANCOM0, PHY_RX_MAILBOX_ID, &dataInfo, PHY_RX_MSG_ID);
//	FLEXCAN_DRV_Receive(INST_CANCOM0, PHY_RX_MAILBOX_ID, &g_RXCANMsg);
//	FLEXCAN_DRV_SetRxIndividualMask(INST_CANCOM0, FLEXCAN_MSG_ID_STD, PHY_RX_MAILBOX_ID, 0x7FF);
//
//	/*Config CAN TX message*/
//	flexcan_data_info_t dataInfo2 =
//	{
//			.data_length = 8U,
//			.msg_id_type = FLEXCAN_MSG_ID_STD,
//	};
//	FLEXCAN_DRV_ConfigTxMb(INST_CANCOM0, TX_MAILBOX_ID, &dataInfo2, 0x7F0);
//}
//
////ETIMER
//static uint16_t gs_1msCnt = 1u;
//static uint16_t gs_100msCnt = 100u;
//
///*FUNCTION**********************************************************************
// *
// * Function Name : TIMER_HAL_Is1msTickTimeout
// * Description   : This function is check timeout. If timeout return TRUE, else return FALSE.
// *
// * Implements : Is1msTickTimeout_Activity
// *END**************************************************************************/
//uint8_t  TIMER_HAL_Is1msTickTimeout(void)
//{
//	uint8_t result = false;
//
//    if(gs_1msCnt == 0)
//    {
//        result = true;
//
//        gs_1msCnt = 1;
//    }
//
//    return result;
//}
//
///*FUNCTION**********************************************************************
// *
// * Function Name : TIMER_HAL_Is10msTickTimeout
// * Description   : This function is check timeout or not. If timeout return TRUE, else return FALSE.
// *
// * Implements : Is10msTickTimeout_Activity
// *END**************************************************************************/
//
//uint8_t TIMER_HAL_Is100msTickTimeout(void)
//{
//	uint8_t result = false;
//
//    if(gs_100msCnt == 0)
//    {
//        result = true;
//
//        gs_100msCnt = 100;
//    }
//
//    return result;
//}
//
///*Timer 1ms period called*/
//void TIMER_HAL_1msPeriod(void)
//{
//	uint16_t cntTmp = 0u;
//
//    /*Just for check time overflow or not?*/
//	if(gs_1msCnt > 0) {
//		gs_1msCnt--;
//	}
//
//	if(gs_100msCnt > 0) {
//		gs_100msCnt--;
//	}
//}
//
//void ETIMER0_Ch3_IRQHandler(void)
//{
//	TIMER_HAL_1msPeriod();
//	ETIMER_DRV_ClearInterruptStatus(INST_ETIMER1,ETIMER_CH_IRQ_FLAGS_TCF1,3);
//}
//
//void eTimerInit(void)
//{
//	/* initialize ETIMERx peripheral */
//	ETIMER_DRV_Init(INST_ETIMER1);
//	/* setup ETIMERx channels */
//	ETIMER_DRV_InitChannel(INST_ETIMER1, 3, &eTmr0Ch3Cfg);
//	/* Enable ETIMER0 channel 3 interrupt and install an ISR */
//	IRQn_Type etimer0_ch3_irq_id = ETIMER_DRV_GetInterruptNumber(0,ETIMER_IRQ_CH3);
//	INT_SYS_InstallHandler(etimer0_ch3_irq_id, &ETIMER0_Ch3_IRQHandler, (isr_t*) 0);
//	INT_SYS_EnableIRQ(etimer0_ch3_irq_id);
//	/* enable interrupts */
//	ETIMER_DRV_EnableInterruptSource(INST_ETIMER1,ETIMER_CH_IRQ_FLAGS_TCF1,3);
//	/* start channel operation */
//	ETIMER_DRV_StartTimerChannels(INST_ETIMER1, ETIMER_ENABLE_CH3);
//}
//
//void testInit(void) {
//	CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT, g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
//	CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);
//
//	PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);
//
//	FlexCANInit();
//	eTimerInit();
//
//	/* Initialize UART PAL over LINFlexD */
//	UART_Init(&uart_pal1_instance, &uart_pal1_Config0);
//	char welcomeMsg[] = "Hello World\n";
//	/* Send a welcome message */
//	UART_SendDataBlocking(&uart_pal1_instance, (uint8_t *)welcomeMsg, strlen(welcomeMsg), 200);
//
//	/* Initialize FCCU configuration */
//	FCCU_DRV_Init(INST_FCCU1, fccu1_Control0, fccu1_NcfConfig0);
//	/* Initialize WDG PAL */
//	WDG_Init(&wdg_pal1_Instance, &watchdog1_Config0);
//
//	CLEAR_LEDR;
//	CLEAR_LEDG;
//	CLEAR_LEDB;
//}
//
//void delay(uint32_t time) {
//	for(volatile uint32_t i = 0; i < time; ++i) {
//
//	}
//}
//
//void testApp(void) {
//	static int count = 0;
//	if(TIMER_HAL_Is1msTickTimeout()) {
//
//	}
//
//	if(TIMER_HAL_Is100msTickTimeout()) {
////		FLEXCAN_DRV_Receive(INST_CANCOM0, PHY_RX_MAILBOX_ID, &g_RXCANMsg);
////		if(g_RXCANMsg.msgId == PHY_RX_MSG_ID && g_RXCANMsg.data[0] == 0xCD) {
////			CLEAR_LEDR;
////		}
////		else {
////			SET_LEDR;
////		}
//		if(count == 10) {
//			TOOGLE_LEDR;
//			SendMsgMainFun();
//			char welcomeMsg[] = "Hello World\n";
//			/* Send a welcome message */
//			//UART_SendDataBlocking(&uart_pal1_instance, (uint8_t *)welcomeMsg, strlen(welcomeMsg), 200);
//			count = 0;
//		}
//		else {
//			count++;
//		}
//
//		/* Reset WDG PAL counter */
//		WDG_Refresh(&wdg_pal1_Instance);
//
//	}
//	//delay(0Xfffff);
//}
//
