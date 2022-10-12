#ifndef __UDS_APP_CFG_H__
#define __UDS_APP_CFG_H__

/*********************Include headers************************/
#include "includes.h"
#include "TP.h"
/**********************************************************/

/****************************Bootloader version***************************/
#define APP_TYPE (0x0Au)
#define APP_SW_VERSION {APP_TYPE, 0x01, 0x0, 0x00}
#define APP_HW_VERSION {APP_TYPE, 0x01, 0x0, 0x00}
/********************************************************************/

typedef uint16 tUdsTime;

typedef struct
{
    tUdsId xUdsId;
    tUdsLen xDataLen;
    uint8 aDataBuf[150u];
    /*tx message call back*/
    void (*pfUDSTxMsgServiceCallBack)(uint8);
} tUdsAppMsgInfo;

typedef struct UDSServiceInfo
{
    uint8 serNum;     /*service num. eg 0x3e/0x87...*/
    uint8 sessionMode;/*default session / program session / extend session*/
    uint8 supReqMode; /*support physical / function addr*/
    uint8 reqLevel;   /*request level.Lock/unlock*/
    void (*pfSerNameFun)(struct UDSServiceInfo*, tUdsAppMsgInfo *);
} tUDSService;

/*********************************************************/

/*S3 timer watermark time percent*/
#ifndef S3_TIMER_WATERMARK_PERCENT
#define S3_TIMER_WATERMARK_PERCENT (90u)
#endif

#if (S3_TIMER_WATERMARK_PERCENT <= 0) || (S3_TIMER_WATERMARK_PERCENT >= 100)
#error "S3_TIMER_WATERMARK_PERCENT should config (0, 100]"
#endif

/*uds negative value define*/
#define NEGTIVE_ID (0x7Fu)
#define	SNS (0x11u)          /*service not support*/
#define	SFNS (0x12u)        /*subfunction not support*/
#define	IMLOIF (0x13u)       /*incorrect message length or invalid format*/
#define	BRR (0x21u)          /*busy repeat request*/
#define	CNC (0x22u)          /*conditions not correct*/
#define	RSE (0x24u)          /*request 	sequence error*/
#define	ROOR (0x31u)         /*request out of range*/
#define	SAD (0x33u)          /*security access denied*/
#define	IK (0x35u)           /*invalid key*/
#define	ENOA (0x36u)         /*exceed number of attempts*/
#define	RCRRP (0x78u)        /*request correctly received-response pending*/

/*define session mode*/
#define DEFALUT_SESSION (1u << 0u)       /*default session*/
#define PROGRAM_SESSION (1u << 1u)       /*program session*/
#define EXTEND_SESSION (1u << 2u)        /*extend session*/

/*security request*/
#define NONE_SECURITY (1u << 0u)                          /*none security can request*/
#define SECURITY_LEVEL_1 ((1 << 1u) | NONE_SECURITY)      /*security level 1 request*/
#define SECURITY_LEVEL_2 ((1u << 2u) | SECURITY_LEVEL_1)  /*security level 2 request*/

/*********************************************************/
/*set currrent session mode. DEFAULT_SESSION/PROGRAM_SESSION/EXTEND_SESSION */
extern void UDS_SetCurrentSession(const uint8 i_setSessionMode);

/*Is current session DEFAULT return TRUE, else return FALSE.*/
extern uint8 UDS_IsCurDefaultSession(void);

/*Is S3server timeout?*/
extern uint8 UDS_IsS3ServerTimeout(void);

/*restart s3server time*/
extern void UDS_RestartS3Server(void);

/*Is current session can request?*/
extern uint8 UDS_IsCurSessionCanRequest(uint8 i_sessionMode);

/*save received request id. If receved physical/function/none phy 
and function ID set rceived physicali/function/erro ID.*/
extern void UDS_SaveRequestIdType(const uint32 i_serRequestID);

/*Is current received id can request?*/
extern uint8 UDS_IsCurRxIdCanRequest(uint8 i_serRequestIdMode);

/*set security level*/
extern void UDS_SetSecurityLevel(const uint8 i_setSecurityLevel);

/*Is current security level can request?*/
extern uint8 UDS_IsCurSecurityLevelRequest(uint8 i_securityLevel);

/* Get UDS config Service information */
tUDSService* UDS_GetUDSServiceInfo(uint8 *m_pSupServItem);

/* If Rx UDS msg, set g_ucIsRxUdsMsg TURE */
extern void UDS_SetIsRxUdsMsg(const uint8 i_setValue);

extern uint8 UDS_IsRxUdsMsg(void);

/*set negative erro code*/
extern void UDS_SetNegativeErroCode(const uint8 i_UDSServiceNum, 
                                const uint8 i_erroCode,
                                tUdsAppMsgInfo *m_pstPDUMsg);

/*uds time control*/
extern void UDS_SystemTickCtl(void);

/*write message to host basd on UDS for request enter bootloader mode*/
extern boolean UDS_TxMsgToHost(void);


#endif /*__UDS_APP_CFG_H__*/
/***************************End file********************************/

