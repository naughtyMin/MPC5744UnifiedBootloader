#include "uds_app_cfg.h"
#include "watchdog_hal.h"
#include "boot.h"

typedef struct
{
    uint32 startAddr;         /*data start address*/
    uint32 dataLen;           /*data len*/
} tDowloadDataInfo;

/*define security access info*/
typedef struct
{
    uint8 subfunctionNumber;    /*subfunction number*/
    uint8 requestSession;       /*request session*/
    uint8 requestIDMode;        /*request id mode*/
    uint8 requestSecurityLevel; /*request security level*/
    void (*pfRoutine)(void);    /*routine*/
} tUDS_SecurityAccessInfo;

/*define write data subfunction*/
typedef struct
{
    uint8 Subfunction;      /*subfunction*/
    uint8 requestSession;   /*request session*/
    uint8 requestIdMode;    /*request id mode*/
    uint8 requestLevel;     /*request level*/
    void (*pfRoutine)(void);/*routine*/
} tUDS_WriteDataByIdentifierInfo;

typedef enum
{
    ERASE_MEMORY_ROUTINE_CONTROL,       /*check erase memory routine control*/
    CHECK_SUM_ROUTINE_CONTROL,          /*check sum routine control*/
    CHECK_DEPENDENCY_ROUTINE_CONTROL,    /*check dependency routine control*/
    GET_VERSION,                        /*get version*/
} tCheckRoutineCtlInfo;

#define DOWLOAD_DATA_ADDR_LEN (4u)      /*dowload data addr len*/
#define DOWLOAD_DATA_LEN (4u)           /*dowload data len*/

/*support function/physical ID request*/
#define ERRO_REQUEST_ID (0u)             /*received ID failled*/
#define SUPPORT_PHYSICAL_ADDR (1u << 0u) /*support physical ID request */
#define SUPPORT_FUNCTION_ADDR (1u << 1u)  /*support function ID request*/

/*********************************************************/
/***********************UDS App Const configuration Information************************/
typedef struct
{
    uint8 CalledPeriod;         /*called uds period*/
    /*security request count. If over this security request count, locked server some time.*/
    uint8 SecurityRequestCnt;
    tUdsTime xLockTime;         /*lock time*/
    tUdsTime xS3Server;         /*s3 server time. */
} tUdsTimeInfo;

/* UDS time control information config table*/
const static tUdsTimeInfo gs_stUdsAppCfg =
{
    1u,
    3u,
    10000u,
    5000u
};

/*uds app time to count*/
#define UdsAppTimeToCount(xTime) ((xTime) / gs_stUdsAppCfg.CalledPeriod)

/*get UDS s3 watermark timer. return s3 * S3_TIMER_WATERMARK_PERCENT / 100*/
uint32 UDS_GetUDSS3WatermarkTimerMs(void)
{
    const uint32 watermarkTimerMs = (gs_stUdsAppCfg.xS3Server * S3_TIMER_WATERMARK_PERCENT) / 100u;

    return (uint32)watermarkTimerMs;
}

#ifdef EN_DELAY_TIME
typedef struct
{
    boolean isReceiveUDSMsg;
    uint32 jumpToAPPDelayTime;
} tJumpAppDelayTimeInfo;

static tJumpAppDelayTimeInfo gs_stJumpAPPDelayTimeInfo = {FALSE, 0u};
#endif

/*********************************************************/
/***********************UDS Information************************/

/**********************UDS Information Static function************************/
static tUdsTime UDS_GetUdsS3ServerTime(void);

static void UDS_SubUdsS3ServerTime(tUdsTime i_SubTime);

static tUdsTime UDS_GetUdsSecurityReqLockTime(void);

static void UDS_SubUdsSecurityReqLockTime(tUdsTime i_SubTime);

typedef struct
{
    uint8 curSessionMode;  /*current session mode. default/program/extend mode*/
    uint8 requsetIdMode;   /*SUPPORT_PHYSICAL_ADDR/SUPPORT_FUNCTION_ADDR*/
    uint8 securityLevel;   /*current security level*/
    tUdsTime xUdsS3ServerTime;      /*uds s3 server time*/
    tUdsTime xSecurityReqLockTime;  /*security request lock time*/
} tUdsInfo;

/***********************UDS Information Static Global value************************/
/* UDS support Session mode?¡éRequestId and Security level config */
static tUdsInfo gs_stUdsInfo =
{
    DEFALUT_SESSION,
    ERRO_REQUEST_ID,
    NONE_SECURITY,
    0u,
    0u,
};

static tUdsTime UDS_GetUdsS3ServerTime(void)
{
    return (gs_stUdsInfo.xUdsS3ServerTime);
}

static void UDS_SubUdsS3ServerTime(tUdsTime i_SubTime)
{
    gs_stUdsInfo.xUdsS3ServerTime -= i_SubTime;
}

static tUdsTime UDS_GetUdsSecurityReqLockTime(void)
{
    return (gs_stUdsInfo.xSecurityReqLockTime);
}

static void UDS_SubUdsSecurityReqLockTime(tUdsTime i_SubTime)
{
    gs_stUdsInfo.xSecurityReqLockTime -= i_SubTime;
}

/*Is security request lock timeout?*/
static uint8 UDS_IsSecurityRequestLockTimeout(void)
{
    uint8 status = 0u;

    if(gs_stUdsInfo.xSecurityReqLockTime)
    {
        status = TRUE;
    }
    else
    {
        status = FALSE;
    }

    return status;
}

/***********************UDS Information Global function************************/
/*set current request id  SUPPORT_PHYSICAL_ADDR/SUPPORT_FUNCTION_ADDR */
#define UDS_SetRequestIdType(xRequestIDType) (gs_stUdsInfo.requsetIdMode = (xRequestIDType))

/*restart s3server time*/
void UDS_RestartS3Server(void)
{
    gs_stUdsInfo.xUdsS3ServerTime = UdsAppTimeToCount(gs_stUdsAppCfg.xS3Server);
}

/*set currrent session mode. DEFAULT_SESSION/PROGRAM_SESSION/EXTEND_SESSION */
void UDS_SetCurrentSession(const uint8 i_setSessionMode)
{
    gs_stUdsInfo.curSessionMode = i_setSessionMode;
}

/*********************************************************/
/**********************UDS service configuration and function************************/

/**********************UDS service correlation subfunction define************************/
/*app memcopy*/
static void UDS_AppMemcopy(const void *i_pvSource, const uint8 i_copyLen, void *o_pvDest);

/*app memset*/
static void UDS_AppMemset(const uint8 i_setValue, const uint16 i_len, void *m_pvSource);

/*Is get version?*/
static uint8 UDS_IsGetVersion(const tUdsAppMsgInfo *m_pstPDUMsg);

/*transmitted confirm message callback*/
static void UDS_TXConfrimMsgCallback(uint8 i_status);

/* When do uds service need more time, need call the funciton */
static void UDS_RequestMoreTime(const uint8 UDSServiceID, void (*pcallback)(uint8));

/*do reset mcu*/
static void UDS_DoResetMCU(uint8 i_Txstatus);

/******************************UDS service main function define***************************************/
/*dig session*/
static void UDS_DigSession(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);

/*control DTC setting*/
static void UDS_ControlDTCSetting(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);

/*communication control*/
static void UDS_CommunicationControl(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);

/*routine control*/
static void UDS_RoutineControl(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);

/*Tester present service*/
static void UDS_TesterPresent(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg);

/***********************UDS service Static Global value************************/
/*dig serverice config table*/
const static tUDSService gs_astUDSService[] =
{
    /*diagnose mode control*/
    {
        0x10u,
        DEFALUT_SESSION | PROGRAM_SESSION | EXTEND_SESSION,
        SUPPORT_PHYSICAL_ADDR | SUPPORT_FUNCTION_ADDR,
        NONE_SECURITY,
        UDS_DigSession
    },

    /*communication control*/
    {
        0x28u,
        DEFALUT_SESSION | PROGRAM_SESSION | EXTEND_SESSION,
        SUPPORT_PHYSICAL_ADDR | SUPPORT_FUNCTION_ADDR,
        NONE_SECURITY,
        UDS_CommunicationControl
    },

    /*control DTC setting*/
    {
        0x85u,
        DEFALUT_SESSION | PROGRAM_SESSION | EXTEND_SESSION,
        SUPPORT_PHYSICAL_ADDR | SUPPORT_FUNCTION_ADDR,
        NONE_SECURITY,
        UDS_ControlDTCSetting
    },

    /*routine control*/
    {
        0x31u,
		DEFALUT_SESSION | PROGRAM_SESSION | EXTEND_SESSION,
		SUPPORT_PHYSICAL_ADDR | SUPPORT_FUNCTION_ADDR,
		NONE_SECURITY,
        UDS_RoutineControl
    },

    /*routine control*/
    {
        0x3Eu,
		DEFALUT_SESSION | PROGRAM_SESSION | EXTEND_SESSION,
		SUPPORT_PHYSICAL_ADDR | SUPPORT_FUNCTION_ADDR,
		NONE_SECURITY,
        UDS_TesterPresent
    },		
};

/*Get bootloader version*/
const static uint8 gs_aGetVersion[] = {0x31u, 0x01, 0x03, 0xFFu};

/**********************UDS service correlation main function realizing************************/
/*dig session*/
static void UDS_DigSession(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg)
{
    uint8 requestSubfunction = 0u;

    ASSERT(NULL_PTR == m_pstPDUMsg);
    ASSERT(NULL_PTR == i_pstUDSServiceInfo);

    requestSubfunction = m_pstPDUMsg->aDataBuf[1u];

    /*set send postive message*/
    m_pstPDUMsg->aDataBuf[0u] = i_pstUDSServiceInfo->serNum + 0x40u;
    m_pstPDUMsg->aDataBuf[1u] = requestSubfunction;
    m_pstPDUMsg->xDataLen = 2u;

    /*sub function*/
    switch(requestSubfunction)
    {
    case 0x01u :  /*default mode*/
    case 0x81u :
        UDS_SetCurrentSession(DEFALUT_SESSION);

        if(0x81u == requestSubfunction)
        {
            m_pstPDUMsg->xDataLen = 0u;
        }

        break;

    case 0x02u :  /*program mode*/
    case 0x82u :
        UDS_SetCurrentSession(PROGRAM_SESSION);

       	m_pstPDUMsg->xDataLen = 0u;

		/*request more time*/
		UDS_RequestMoreTime(i_pstUDSServiceInfo->serNum, &UDS_DoResetMCU);

        break;

    case 0x03u :  /*extend mode*/
    case 0x83u :
        UDS_SetCurrentSession(EXTEND_SESSION);

        if(0x83u == requestSubfunction)
        {
            m_pstPDUMsg->xDataLen = 0u;
        }

        /*restart s3server time*/
        UDS_RestartS3Server();
        break;

    default :
        UDS_SetNegativeErroCode(i_pstUDSServiceInfo->serNum, SFNS, m_pstPDUMsg);
        break;
    }
}

/*control DTC setting*/
static void UDS_ControlDTCSetting(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg)
{
    uint8 requestSubfunction = 0u;

    ASSERT(NULL_PTR == m_pstPDUMsg);
    ASSERT(NULL_PTR == i_pstUDSServiceInfo);

    requestSubfunction = m_pstPDUMsg->aDataBuf[1u];

    switch(requestSubfunction)
    {
	    case 0x01u :
	    case 0x02u :
	        m_pstPDUMsg->aDataBuf[0u] = i_pstUDSServiceInfo->serNum + 0x40u;
	        m_pstPDUMsg->aDataBuf[1u] = requestSubfunction;
	        m_pstPDUMsg->xDataLen = 2u;
	        break;

	    case 0x81u :
	    case 0x82u :
	        m_pstPDUMsg->xDataLen = 0u;
	        break;

	    default :
	        UDS_SetNegativeErroCode(i_pstUDSServiceInfo->serNum, SFNS, m_pstPDUMsg);
	        break;
    }
}

/*communication control*/
static void UDS_CommunicationControl(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg)
{
    uint8 requestSubfunction = 0u;

    ASSERT(NULL_PTR == m_pstPDUMsg);
    ASSERT(NULL_PTR == i_pstUDSServiceInfo);

    requestSubfunction = m_pstPDUMsg->aDataBuf[1u];

    switch(requestSubfunction)
    {
    case 0x0u :
    case 0x03u :
        m_pstPDUMsg->aDataBuf[0u] = i_pstUDSServiceInfo->serNum + 0x40u;
        m_pstPDUMsg->aDataBuf[1u] = requestSubfunction;
        m_pstPDUMsg->xDataLen = 2u;

        break;

    case 0x80u :
    case 0x83u :
        /*don't transmit uds message.*/
        m_pstPDUMsg->aDataBuf[0u] = 0u;
        m_pstPDUMsg->xDataLen = 0u;

        break;

    default :
        UDS_SetNegativeErroCode(i_pstUDSServiceInfo->serNum, SFNS, m_pstPDUMsg);

        break;
    }
}

/*routine control*/
static void UDS_RoutineControl(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg)
{
    uint8 ret = FALSE;
    uint32 ReceivedCrc = 0u;
	uint8 aSWVersion[] = APP_SW_VERSION;
	uint8 aHWVersion[] = APP_HW_VERSION;
	uint8 offset = 0u;

    ASSERT(NULL_PTR == m_pstPDUMsg);
    ASSERT(NULL_PTR == i_pstUDSServiceInfo);

    UDS_RestartS3Server();
	
	/*Is get version*/
	if(TRUE == UDS_IsGetVersion(m_pstPDUMsg))
	{
		m_pstPDUMsg->aDataBuf[0u] = i_pstUDSServiceInfo->serNum + 0x40u;
		m_pstPDUMsg->xDataLen = 4u;

		/*fill sofware information*/
		offset = m_pstPDUMsg->xDataLen;
		m_pstPDUMsg->aDataBuf[offset] = sizeof(aSWVersion);
		offset += 1u;
		
		fsl_memcpy(&m_pstPDUMsg->aDataBuf[offset], aSWVersion, sizeof(aSWVersion));
		offset += sizeof(aSWVersion);

		/*fill hardware version*/
		m_pstPDUMsg->aDataBuf[offset] = sizeof(aHWVersion);
		offset += 1u;
		
		fsl_memcpy(&m_pstPDUMsg->aDataBuf[offset], aHWVersion, sizeof(aHWVersion));
		offset += sizeof(aHWVersion);

		m_pstPDUMsg->xDataLen = offset;
	}
	
    else
    {
        /*don't have this routine control ID*/
        UDS_SetNegativeErroCode(i_pstUDSServiceInfo->serNum, SFNS, m_pstPDUMsg);
    }
}

/*Tester present service*/
static void UDS_TesterPresent(struct UDSServiceInfo* i_pstUDSServiceInfo, tUdsAppMsgInfo *m_pstPDUMsg)
{
    uint8 requestSubfunction = 0u;

    ASSERT(NULL_PTR == m_pstPDUMsg);
    ASSERT(NULL_PTR == i_pstUDSServiceInfo);

    requestSubfunction = m_pstPDUMsg->aDataBuf[1u];

    /*sub function*/
    switch(requestSubfunction)
    {
	    case 0x00u :  /*zero subFunction*/
	        /*set send postive message*/
	        m_pstPDUMsg->aDataBuf[0u] = i_pstUDSServiceInfo->serNum + 0x40u;
	        m_pstPDUMsg->aDataBuf[1u] = requestSubfunction;
	        m_pstPDUMsg->xDataLen = 2u;
	        break;

	    case 0x80u :  /*program mode*/
	        m_pstPDUMsg->xDataLen = 0u;
	        break;

	    default :
	        UDS_SetNegativeErroCode(i_pstUDSServiceInfo->serNum, SFNS, m_pstPDUMsg);
	        break;
    }
}

/*do reset mcu*/
static void UDS_DoResetMCU(uint8 Txstatus)
{
    if(TX_MSG_SUCCESSFUL == Txstatus)
    {
    	/*request enter bootloader mode*/
    	//Boot_RequestEnterBootloader();
    	/*USPRG0=0x5A means the program reset in APP*/
    	MTSPR(256, 0x5A);

        /*reset ECU*/
        WATCHDOG_HAL_SystemRest();
        while(1)
        {
            /*wait watch dog reset mcu*/
        }
    }
}

/**********************UDS service correlation other function realizing************************/
/* get uds service config information */
tUDSService* UDS_GetUDSServiceInfo(uint8 *m_pSupServItem)
{
    ASSERT(NULL_PTR == m_pSupServItem);
    
    *m_pSupServItem = sizeof(gs_astUDSService) / sizeof(gs_astUDSService[0u]);

    return (tUDSService*) &gs_astUDSService[0u];
}

/* If Rx UDS msg, set UDS layer received message TURE */
void UDS_SetIsRxUdsMsg(const uint8 i_setValue)
{

}

uint8 UDS_IsRxUdsMsg(void)
{
    return TRUE;
}

/*set negative erro code*/
void UDS_SetNegativeErroCode(const uint8 i_UDSServiceNum,
                         const uint8 i_erroCode,
                         tUdsAppMsgInfo *m_pstPDUMsg)
{
    ASSERT(NULL_PTR == m_pstPDUMsg);

    m_pstPDUMsg->aDataBuf[0u] = NEGTIVE_ID;
    m_pstPDUMsg->aDataBuf[1u] = i_UDSServiceNum;
    m_pstPDUMsg->aDataBuf[2u] = i_erroCode;
    m_pstPDUMsg->xDataLen = 3u;
}

/*Is current session DEFAULT return TRUE, else return FALSE.*/
uint8 UDS_IsCurDefaultSession(void)
{
    uint8 isCurDefaultSessionStatus = FALSE;

    if(DEFALUT_SESSION == gs_stUdsInfo.curSessionMode)
    {
        isCurDefaultSessionStatus = TRUE;
    }
    else
    {
        isCurDefaultSessionStatus = FALSE;
    }

    return isCurDefaultSessionStatus;
}

/*Is S3server timeout?*/
uint8 UDS_IsS3ServerTimeout(void)
{
    uint8 TimeoutStatus = FALSE;

    if(0u == gs_stUdsInfo.xUdsS3ServerTime)
    {
        TimeoutStatus = TRUE;
    }
    else
    {
        TimeoutStatus = FALSE;
    }

    return TimeoutStatus;
}

/*Is current session can request?*/
uint8 UDS_IsCurSessionCanRequest(uint8 i_sessionMode)
{
    uint8 status = FALSE;

    if((i_sessionMode & gs_stUdsInfo.curSessionMode) == gs_stUdsInfo.curSessionMode)
    {
        status = TRUE;
    }
    else
    {
        status = FALSE;
    }

    return status;
}

/*save received request id. If receved physical/function/none phy and function ID set rceived physicali/function/erro ID.*/
void UDS_SaveRequestIdType(const uint32 i_serRequestID)
{
    if(i_serRequestID == TP_GetConfigRxMsgPHYID())
    {
        UDS_SetRequestIdType(SUPPORT_PHYSICAL_ADDR);
    }
    else if(i_serRequestID == TP_GetConfigRxMsgFUNID())
    {
        UDS_SetRequestIdType(SUPPORT_FUNCTION_ADDR);
    }
    else
    {
        UDS_SetRequestIdType(ERRO_REQUEST_ID);
    }
}

/*Is current received id can request?*/
uint8 UDS_IsCurRxIdCanRequest(uint8 i_serRequestIdMode)
{
    uint8 status = 0u;

    if((i_serRequestIdMode & gs_stUdsInfo.requsetIdMode) == gs_stUdsInfo.requsetIdMode)
    {
        status = TRUE;
    }
    else
    {
        status = FALSE;
    }

    return status;
}

/*set security level*/
void UDS_SetSecurityLevel(const uint8 i_setSecurityLevel)
{
    gs_stUdsInfo.securityLevel = i_setSecurityLevel;
}

/*Is current security level can request?*/
uint8 UDS_IsCurSecurityLevelRequest(uint8 i_securityLevel)
{
    uint8 status = 0u;

    if((i_securityLevel & gs_stUdsInfo.securityLevel) == gs_stUdsInfo.securityLevel)
    {
        status = TRUE;
    }
    else
    {
        status = FALSE;
    }

    return status;
}

/**********************UDS service correlation subfunction realizing************************/
/*app memcopy*/
static void UDS_AppMemcopy(const void *i_pvSource, const uint8 i_copyLen, void *o_pvDest)
{
    ASSERT(NULL_PTR == i_pvSource);
    ASSERT(NULL_PTR == o_pvDest);
    
    fsl_memcpy(o_pvDest, i_pvSource, i_copyLen);
}

/*app memset*/
static void UDS_AppMemset(const uint8 i_setValue, const uint16 i_len, void *m_pvSource)
{
    ASSERT(NULL_PTR == m_pvSource);
    
    fsl_memset(m_pvSource, i_setValue, i_len);
}

/*check routine control right?*/
static uint8 UDS_IsCheckUDS_RoutineControlRight(const tCheckRoutineCtlInfo i_eCheckRoutineCtlId,
                                        const tUdsAppMsgInfo *m_pstPDUMsg)
{
    uint8 Index = 0u;
    uint8 FindCnt = 0u;
    uint8 *pDestRoutineCltId = NULL_PTR;

    ASSERT(NULL_PTR == m_pstPDUMsg);

    switch(i_eCheckRoutineCtlId)
    {
		case GET_VERSION:
			pDestRoutineCltId = (uint8 *)&gs_aGetVersion[0u];
			FindCnt = sizeof(gs_aGetVersion);

			break;

	    default :

	        return FALSE;

        /*This is not have break*/
    }

    if((NULL_PTR == pDestRoutineCltId) || (m_pstPDUMsg->xDataLen < FindCnt))
    {
        return FALSE;
    }

    while(Index < FindCnt)
    {
        if(m_pstPDUMsg->aDataBuf[Index] != pDestRoutineCltId[Index])
        {
            return FALSE;
        }

        Index++;
    }

    return TRUE;
}

/*Is get version?*/
static uint8 UDS_IsGetVersion(const tUdsAppMsgInfo *m_pstPDUMsg)
{
	ASSERT(NULL_PTR == m_pstPDUMsg);
	
	return UDS_IsCheckUDS_RoutineControlRight(GET_VERSION, m_pstPDUMsg);
}

typedef void (*tpfFlashOperateMoreTimecallback)(uint8);

/* For erasing or programming flash were timeout callback */
static tpfFlashOperateMoreTimecallback gs_pfFlashOperateMoreTimecallback = NULL_PTR;

static void RequestMoreTimeCallback(uint8 i_TxStatus)
{
    if(TX_MSG_SUCCESSFUL == i_TxStatus)
    {
        UDS_RestartS3Server();
    }

    if(NULL_PTR != gs_pfFlashOperateMoreTimecallback)
    {
        (gs_pfFlashOperateMoreTimecallback)(i_TxStatus);
        gs_pfFlashOperateMoreTimecallback = NULL_PTR;
    }
}

static void UDS_RequestMoreTime(const uint8 UDSServiceID, void (*pcallback)(uint8))
{
    tUdsAppMsgInfo stMsgBuf = {0};

    ASSERT(NULL_PTR == pcallback);

    stMsgBuf.xUdsId = TP_GetConfigTxMsgID();
    UDS_SetNegativeErroCode(UDSServiceID, RCRRP, &stMsgBuf);
    stMsgBuf.pfUDSTxMsgServiceCallBack = &RequestMoreTimeCallback;
    gs_pfFlashOperateMoreTimecallback = pcallback;

    (void)TP_WriteAFrameDataInTP(stMsgBuf.xUdsId, stMsgBuf.pfUDSTxMsgServiceCallBack,
                                 stMsgBuf.xDataLen, stMsgBuf.aDataBuf);
}

/*********************************************************/
/**********************UDS service other module call function realizing************************/

/*transmitted confirm message callback*/
static void UDS_TXConfrimMsgCallback(uint8 i_status)
{
    if(TX_MSG_SUCCESSFUL == i_status)
    {
        UDS_SetCurrentSession(PROGRAM_SESSION);
        UDS_SetSecurityLevel(NONE_SECURITY);

        /*restart s3server time*/
        UDS_RestartS3Server();
    }
}

/*write message to host basd on UDS for request enter bootloader mode*/
boolean UDS_TxMsgToHost(void)
{
    tUdsAppMsgInfo stUdsAppMsg = {0u, 0u, {0u}, NULL_PTR};
    boolean ret = FALSE;

    stUdsAppMsg.xUdsId = TP_GetConfigTxMsgID();
    stUdsAppMsg.xDataLen = 2u;
    stUdsAppMsg.aDataBuf[0u] = 0x51u;
    stUdsAppMsg.aDataBuf[1u] = 0x01u;
    stUdsAppMsg.pfUDSTxMsgServiceCallBack = UDS_TXConfrimMsgCallback;

    ret = TP_WriteAFrameDataInTP(stUdsAppMsg.xUdsId, stUdsAppMsg.pfUDSTxMsgServiceCallBack,
                                 stUdsAppMsg.xDataLen, stUdsAppMsg.aDataBuf);

    return ret;
}

/*uds time control*/
void UDS_SystemTickCtl(void)
{
    if(UDS_GetUdsS3ServerTime())
    {
        UDS_SubUdsS3ServerTime(1u);
    }

    if(UDS_GetUdsSecurityReqLockTime())
    {
        UDS_SubUdsSecurityReqLockTime(1u);
    }
}

/***************************End file********************************/


