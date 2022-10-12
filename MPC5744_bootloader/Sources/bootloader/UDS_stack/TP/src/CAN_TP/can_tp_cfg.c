#include "includes.h"

#ifdef EN_CAN_TP
#include "can_tp_cfg.h"
#include "multi_cyc_fifo.h"
//#include "can_driver.h"
static tpfAbortTxMsg gs_pfCANTPAbortTxMsg = NULL_PTR;
static tpfNetTxCallBack gs_pfTxMsgSuccessfulCallBack = NULL_PTR;


static uint8 CANTP_TxMsg(const tUdsId i_xTxId,
							  const uint16 i_dataLen, 
							  const uint8* i_pDataBuf, 
							  const tpfNetTxCallBack i_pfNetTxCallBack,
							  const uint32 i_txBlockingMaxtime);

static uint8 CANTP_RxMsg(tUdsId * o_pxRxId,
							   uint8 * o_pRxDataLen,
							   uint8 *o_pRxBuf);

static void CANTP_AbortTxMsg(void);

/*clear CAN TP TX BUS FIFO*/
static boolean CANTP_ClearTXBUSFIFO(void);

/*CANTP fill padding data*/
static boolean CANTP_FillPaddingData(const uint32 i_maxMsgLen, 
									const uint32 i_msgLen, 
									uint8 *m_pMsgBuf, 
									uint32 *o_pTxMsgLen);

/*uds netwrok layer cfg info */
const tUdsCANNetLayerCfg g_stCANUdsNetLayerCfgInfo = 
{
	1u,       /*called can tp period*/
	RX_FUN_ID,   /*can tp rx function ID*/
	RX_PHY_ID,   /*can tp rx phy ID*/
	TX_ID,   /*can tp tx ID*/
	0u,       /*BS = block size*/
	1u,      /*STmin*/
	1000u,      /*N_As*/
	1000u,      /*N_Ar*/
	1000u,     /*N_Bs*/
	0u,       /*N_Br*/
	900u,       /*N_Cs < 0.9 N_Cr*/
	1000u,     /*N_Cr*/
	0u,       /*max blocking time 0ms, > 0u mean waitting send successful. equal 0 is not waitting.*/
	CANTP_TxMsg, /*can tp tx*/
	CANTP_RxMsg, /*can tp rx*/
	CANTP_AbortTxMsg,
};

/*can tp tx message: there not use CAN driver TxFIFO, directly invoked CAN send function*/
static uint8 CANTP_TxMsg(const tUdsId i_xTxId,
							  const uint16 i_dataLen, 
							  const uint8* i_pDataBuf, 
							  const tpfNetTxCallBack i_pfNetTxCallBack,
							  const uint32 i_txBlockingMaxtime)
{
	tLen xCanWriteDataLen = 0u;
	tErroCode eStatus;
	uint8 aMsgBuf[DATA_LEN] = {0};
	tTPTxMsgHeader txMsgInfo;
	const uint32 msgInfoLen = sizeof(tTPTxMsgHeader) + sizeof(aMsgBuf);

	ASSERT(NULL_PTR == i_pDataBuf);

	if(i_dataLen > DATA_LEN)
	{
		return FALSE;
	}

	GetCanWriteLen(TX_BUS_FIFO, &xCanWriteDataLen, &eStatus);
	if((ERRO_NONE == eStatus) && (msgInfoLen <= xCanWriteDataLen))
	{
		txMsgInfo.TxMsgID = i_xTxId;
#ifdef EN_TX_CAN_FD
		txMsgInfo.TxMsgLength = i_dataLen;
#else
		txMsgInfo.TxMsgLength = sizeof(aMsgBuf);
#endif
		txMsgInfo.TxMsgCallBack = (uint32)i_pfNetTxCallBack;
		
		fsl_memcpy(&aMsgBuf[0u], i_pDataBuf, i_dataLen);

		if(TRUE != CANTP_FillPaddingData(DATA_LEN, txMsgInfo.TxMsgLength, aMsgBuf, &txMsgInfo.TxMsgLength))
		{
			return FALSE;
		}
		
		WriteDataInFifo(TX_BUS_FIFO, (uint8 *)&txMsgInfo, sizeof(tTPTxMsgHeader),&eStatus);
		if(ERRO_NONE != eStatus)
		{
			ClearFIFO(TX_BUS_FIFO, &eStatus);
			
			return FALSE;
		}

		WriteDataInFifo(TX_BUS_FIFO, (uint8 *)aMsgBuf, txMsgInfo.TxMsgLength, &eStatus);
		if(ERRO_NONE != eStatus)
		{
			ClearFIFO(TX_BUS_FIFO, &eStatus);
			
			return FALSE;
		}
	}
	
	return TRUE;
}

/*can tp rx message: read rx msg from CAN driver RxFIFO*/
static uint8 CANTP_RxMsg(tUdsId * o_pxRxId,
					  	 uint8 * o_pRxDataLen,
						 uint8 *o_pRxBuf)
{
	tLen xCanRxDataLen = 0u;
	tLen xReadDataLen = 0u;
	tErroCode eStatus;
	tRxMsgInfo stRxCanMsg = {0u};
	uint8 ucIndex = 0u;
	const uint32 headerLen = sizeof(stRxCanMsg.rxDataId) + sizeof(stRxCanMsg.rxDataLen);

	ASSERT(NULL_PTR == o_pxRxId);
	ASSERT(NULL_PTR == o_pRxBuf);
	ASSERT(NULL_PTR == o_pRxDataLen);

	GetCanReadLen(RX_BUS_FIFO, &xCanRxDataLen, &eStatus);
	if((ERRO_NONE == eStatus) && (headerLen <= xCanRxDataLen))
	{
		ReadDataFromFifo(RX_BUS_FIFO, 
				         headerLen,
			            (uint8 *)&stRxCanMsg,
			            &xReadDataLen,
			            &eStatus);

		if((ERRO_NONE == eStatus) && (headerLen <= xCanRxDataLen))
		{
			ReadDataFromFifo(RX_BUS_FIFO, 
							 stRxCanMsg.rxDataLen,
							(uint8 *)&stRxCanMsg.aucDataBuf,
							&xCanRxDataLen,
							&eStatus);

			if(TRUE != CANTP_IsReceivedMsgIDValid(stRxCanMsg.rxDataId))
			{
				return FALSE;
			}
			
			*o_pxRxId = stRxCanMsg.rxDataId;
			*o_pRxDataLen = stRxCanMsg.rxDataLen;

			for(ucIndex = 0u; ucIndex < stRxCanMsg.rxDataLen; ucIndex++)
			{
				o_pRxBuf[ucIndex] = stRxCanMsg.aucDataBuf[ucIndex];
			}

			return TRUE;
		 }
		
	}
	else
	{
		if((0u != xCanRxDataLen) || (ERRO_NONE != eStatus))
		{
			TP_DebugPrintf("\n %s write message in FIFO failed! status = %d, FIFO avaliable Length=%d\n", __func__, eStatus, xCanRxDataLen);
		}
	}

	return FALSE;
}

/*get config CAN TP tx ID*/
tUdsId CANTP_GetConfigTxMsgID(void)
{
	return g_stCANUdsNetLayerCfgInfo.xTxId;
}

/*get config CAN TP recevie function message ID*/
tUdsId CANTP_GetConfigRxMsgFUNID(void)
{
	return g_stCANUdsNetLayerCfgInfo.xRxFunId;
}

/*Is received message valid?*/
boolean CANTP_IsReceivedMsgIDValid(const uint32 i_receiveMsgID)
{
	boolean result = FALSE;
	
	if((i_receiveMsgID == CANTP_GetConfigRxMsgFUNID())
 		|| (i_receiveMsgID == CANTP_GetConfigRxMsgPHYID()))
	{
		result = TRUE;
	}

	return result;
}


/*get config CAN TP recevie physical message ID*/
tUdsId CANTP_GetConfigRxMsgPHYID(void)
{
	return g_stCANUdsNetLayerCfgInfo.xRxPhyId;

}

/*Get CAN TP config Tx  handle*/
tNetTxMsg CANTP_GetConfigTxHandle(void)
{
	return g_stCANUdsNetLayerCfgInfo.pfNetTxMsg;
}

/*Get CAN TP config Rx  handle*/
tNetRx CANTP_GetConfigRxHandle(void)
{
	return g_stCANUdsNetLayerCfgInfo.pfNetRx;
}

/*abort CAN BUS tx message*/
static void CANTP_AbortTxMsg(void)
{
	TP_DebugPrintf("CANTP_AbortTxMsg\n");
	
	if(NULL_PTR != gs_pfCANTPAbortTxMsg)
	{
		(gs_pfCANTPAbortTxMsg)();

		gs_pfTxMsgSuccessfulCallBack = NULL_PTR;
	}

	if(TRUE != CANTP_ClearTXBUSFIFO())
	{
		TP_DebugPrintf("CANTP_AbortTxMsg: Clear TX BUS FIFO failed!\n");
	}


}

/*register abort tx message to BUS*/
void CANTP_RegisterAbortTxMsg(const tpfAbortTxMsg i_pfAbortTxMsg)
{
	gs_pfCANTPAbortTxMsg = (tpfAbortTxMsg)i_pfAbortTxMsg;
}


/*write data in CAN TP*/
boolean CANTP_DriverWriteDataInCANTP(const uint32 i_RxID, const uint32 i_dataLen, const uint8 *i_pDataBuf)
{
	tLen xCanWriteDataLen = 0u;
	tErroCode eStatus;
	tRxMsgInfo stRxCanMsg;
	const uint32 headerLen = sizeof(stRxCanMsg.rxDataId) + sizeof(stRxCanMsg.rxDataLen);

	ASSERT(NULL_PTR == i_pDataBuf);

	GetCanWriteLen(RX_BUS_FIFO, &xCanWriteDataLen, &eStatus);
	if((ERRO_NONE == eStatus) && ((i_dataLen + headerLen) <= xCanWriteDataLen))
	{
		stRxCanMsg.rxDataId = i_RxID;
		stRxCanMsg.rxDataLen = i_dataLen;

		WriteDataInFifo(RX_BUS_FIFO, (uint8 *)&stRxCanMsg, headerLen, &eStatus);
		if(ERRO_NONE != eStatus)
		{
			return FALSE;
		}

		WriteDataInFifo(RX_BUS_FIFO, (uint8 *)i_pDataBuf, stRxCanMsg.rxDataLen, &eStatus);
		if(ERRO_NONE != eStatus)
		{
			return FALSE;
		}		
	}

	return TRUE;	
}

/*Driver read data from LINTP*/
boolean CANTP_DriverReadDataFromCANTP(const uint32 i_readDataLen, uint8 *o_pReadDataBuf, tTPTxMsgHeader *o_pstTxMsgHeader)
{
	boolean result = FALSE;
	tLen xCanRxDataLen = 0u;
	tErroCode eStatus;
	tTPTxMsgHeader txMsgInfo;
	const uint32 msgInfoLen = sizeof(tTPTxMsgHeader);

	ASSERT(NULL_PTR == o_pReadDataBuf);
	ASSERT(NULL_PTR == o_pstTxMsgHeader);	
	ASSERT(0u == i_readDataLen);
	
	GetCanReadLen(TX_BUS_FIFO, &xCanRxDataLen, &eStatus);
	if((ERRO_NONE == eStatus) && (xCanRxDataLen > msgInfoLen))
	{
		/*read header an*/
		ReadDataFromFifo(TX_BUS_FIFO, 
						 sizeof(tTPTxMsgHeader),
						(uint8 *)&txMsgInfo,
						&xCanRxDataLen,
						&eStatus);
		if((ERRO_NONE == eStatus) && (xCanRxDataLen == sizeof(tTPTxMsgHeader)))
		{
			result = TRUE;
		}

		if(TRUE == result)
		{
			
			ReadDataFromFifo(TX_BUS_FIFO, 
							 i_readDataLen,
							o_pReadDataBuf,
							&xCanRxDataLen,
							&eStatus);
			if((ERRO_NONE == eStatus) && (i_readDataLen >= txMsgInfo.TxMsgLength))
			{
				result = TRUE;

				*o_pstTxMsgHeader = txMsgInfo;

				/*storage callback, if user want to TX message callback please call TP_DoTxMsgSuccesfulCallback or self call callback*/
				gs_pfTxMsgSuccessfulCallBack = (tpfNetTxCallBack)txMsgInfo.TxMsgCallBack;
			}
		}
	}

	return result;
}


/*do tx message successful callback*/
void CANTP_DoTxMsgSuccessfulCallBack(void)
{
	if(NULL_PTR != gs_pfTxMsgSuccessfulCallBack)
	{
		(gs_pfTxMsgSuccessfulCallBack)();

		gs_pfTxMsgSuccessfulCallBack = NULL_PTR;
	}
}

/*clear CAN TP TX BUS FIFO*/
static boolean CANTP_ClearTXBUSFIFO(void)
{
	boolean result = FALSE;
	tErroCode eStatus = ERRO_NONE;

	ClearFIFO(TX_BUS_FIFO, &eStatus);
	if(ERRO_NONE == eStatus)
	{
		result = TRUE;
	}

	return result;
}

/*CANTP fill padding data*/
static boolean CANTP_FillPaddingData(const uint32 i_maxMsgLen, 
									const uint32 i_msgLen, 
									uint8 *m_pMsgBuf, 
									uint32 *o_pTxMsgLen)
{
	boolean res = FALSE;

#ifdef EN_TX_CAN_FD
	const uint8 aValidMsgLen[] = {8u, 12u, 16u, 20u, 24u, 32u, 48u, 64u};
	uint8 maxIndex = 0u;
#endif

#ifdef EN_TX_CAN_FD
	uint8 index = 0u;
#endif

	uint32 txMsgLen = 0u;

	if((i_maxMsgLen < i_msgLen) || (NULL_PTR == m_pMsgBuf) || (NULL_PTR == o_pTxMsgLen))
	{
		return FALSE;
	}

#ifdef EN_TX_CAN_FD
	maxIndex =  sizeof(aValidMsgLen) / sizeof(aValidMsgLen[0u]);
	index = 0u;
	res = FALSE;
	while(index < maxIndex)
	{
		if(i_msgLen <= aValidMsgLen[index])
		{
			txMsgLen = aValidMsgLen[index];
			
			res = TRUE;
		}
		else 
		{
			if((index + 1u) < maxIndex)
			{
				if(i_msgLen <= aValidMsgLen[index + 1u])
				{
					txMsgLen = aValidMsgLen[index + 1u];

					res = TRUE;
				}
			}
		}
	
		index++;

		if(TRUE == res)
		{
			break;
		}
	}

#else
	if(i_msgLen <= STANDARD_CAN_DL)
	{
		txMsgLen = STANDARD_CAN_DL;
		
		res = TRUE;
	}
#endif

	if((TRUE == res))
	{
		if(i_maxMsgLen >= txMsgLen)
		{
			*o_pTxMsgLen = txMsgLen;

			if(txMsgLen > i_msgLen)
			{
				fsl_memset(&m_pMsgBuf[i_msgLen], 0u, (txMsgLen - i_msgLen));
			}
		}
		else
		{
			res = FALSE;
			
			TP_DebugPrintf("CANTP_FillPaddingData, tx message length=%d is not right!\n", txMsgLen);
		}
	}
	
	return res;
}

#endif /*#ifdef EN_CAN_TP*/

/***************************End file********************************/
