#include "uds_app.h"
#include "TP.h"
#include "Boot.h"
#include "fls_app.h"
#include "uds_alg_hal.h"

/*********************************************************/

/*UDS init*/
void UDS_Init(void)
{
#ifdef EN_DELAY_TIME
    gs_stJumpAPPDelayTimeInfo.jumpToAPPDelayTime = UdsAppTimeToCount(DELAY_MAX_TIME_MS);
#endif

    /*UDS alg hal init*/
    UDS_ALG_HAL_Init();
}

/*uds main function. ISO14229*/
void UDS_MainFun(void)
{
    uint8 UDSSerIndex = 0u;
    uint8 UDSSerNum = 0u;
    tUdsAppMsgInfo stUdsAppMsg = {0u, 0u, {0u}, NULL_PTR};
    uint8 isFindService = FALSE;
    uint8 SupSerItem = 0u;
    tUDSService *pstUDSService = NULL_PTR;

#ifdef EN_ALG_SW
    UDS_ALG_HAL_AddSWTimerTickCnt();
#endif

    if(TRUE == UDS_IsS3ServerTimeout())
    {
        /*If s3 server timeout, back default session mode.*/
        UDS_SetCurrentSession(DEFALUT_SESSION);

        /*set security level. If S3server timeout, clear current security.*/
        UDS_SetSecurityLevel(NONE_SECURITY);

        Flash_InitDowloadInfo();
    }

//	/*从APP中跳转过来的，且第一次到这*/
//	if(Boot_IsRequestEnterBootloader()) {
//		//因为从APP调过来后，RAM被清除了，这里恢复收到了10服务
//		stUdsAppMsg.xUdsId = 0x784;
//		stUdsAppMsg.xDataLen = 2;
//		stUdsAppMsg.aDataBuf[0] = 0x10;
//		stUdsAppMsg.aDataBuf[1] = 0x2;
//		//清除APP跳转标志
//		MTSPR(256, 0xA5);
//	}
//	else {
		/*read data from can tp*/
		    if(TRUE == TP_ReadAFrameDataFromTP(&stUdsAppMsg.xUdsId,
		                                        &stUdsAppMsg.xDataLen,
		                                        stUdsAppMsg.aDataBuf))
		    {
		        UDS_SetIsRxUdsMsg(TRUE);

		        if(TRUE != UDS_IsCurDefaultSession())
		        {
		            /*restart s3server time*/
		            UDS_RestartS3Server();
		        }

		        /*save request id type.*/
		        UDS_SaveRequestIdType(stUdsAppMsg.xUdsId);
		    }
		    else
		    {
		        return;
		    }
//	}


    /*get UDS service Information, start PTR and service item*/
    pstUDSService = UDS_GetUDSServiceInfo(&SupSerItem);

    /*get UDS service ID*/
    UDSSerNum = stUdsAppMsg.aDataBuf[0u];

    while((UDSSerIndex < SupSerItem) && (NULL_PTR != pstUDSService))
    {
        if(UDSSerNum == pstUDSService[UDSSerIndex].serNum)
        {
            isFindService = TRUE;

            if(TRUE != UDS_IsCurRxIdCanRequest(pstUDSService[UDSSerIndex].supReqMode))
            {
                /*received ID cann't request this service.*/
                UDS_SetNegativeErroCode(stUdsAppMsg.aDataBuf[0u], SNS, &stUdsAppMsg);

                break;
            }

            if(TRUE != UDS_IsCurSessionCanRequest(pstUDSService[UDSSerIndex].sessionMode))
            {
                /*currnet session mode cann't request ths service.*/
                UDS_SetNegativeErroCode(stUdsAppMsg.aDataBuf[0u], SNS, &stUdsAppMsg);

                break;
            }

            if(TRUE != UDS_IsCurSecurityLevelRequest(pstUDSService[UDSSerIndex].reqLevel))
            {
                /*current security level cann't request this service.*/
                UDS_SetNegativeErroCode(stUdsAppMsg.aDataBuf[0u], SNS, &stUdsAppMsg);

                break;
            }

            stUdsAppMsg.pfUDSTxMsgServiceCallBack = NULL_PTR;

            /*find service, and do it.*/
            if(NULL_PTR != pstUDSService[UDSSerIndex].pfSerNameFun)
            {
                pstUDSService[UDSSerIndex].pfSerNameFun((tUDSService *)&pstUDSService[UDSSerIndex], &stUdsAppMsg);
            }
            else
            {
                /*current security level cann't request this service.*/
                UDS_SetNegativeErroCode(stUdsAppMsg.aDataBuf[0u], SNS, &stUdsAppMsg);
            }

            break;
        }

        UDSSerIndex++;
    }

    if(TRUE != isFindService)
    {
        /*response not support service.*/
        UDS_SetNegativeErroCode(stUdsAppMsg.aDataBuf[0u], SNS, &stUdsAppMsg);
    }

    if(0u != stUdsAppMsg.xDataLen)
    {
        stUdsAppMsg.xUdsId = TP_GetConfigTxMsgID();

        (void)TP_WriteAFrameDataInTP(stUdsAppMsg.xUdsId,
                                     stUdsAppMsg.pfUDSTxMsgServiceCallBack,
                                     stUdsAppMsg.xDataLen,
                                     stUdsAppMsg.aDataBuf);
    }
}


