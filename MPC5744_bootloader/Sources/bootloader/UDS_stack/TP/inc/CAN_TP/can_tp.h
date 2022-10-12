#ifndef __CAN_TP_H__
#define __CAN_TP_H__

#include "can_tp_cfg.h"

#ifdef EN_CAN_TP

#include "multi_cyc_fifo.h"

/*uds network man function*/
extern void CANTP_MainFun(void);

/*can tp system tick control*/
extern void CANTP_SytstemTickControl(void);

/*Init CAN TP list*/
extern void CANTP_Init(void);

#endif /*#ifdef EN_CAN_TP*/

#endif /*#ifndef __CAN_TP_H__*/

/***************************End file********************************/

