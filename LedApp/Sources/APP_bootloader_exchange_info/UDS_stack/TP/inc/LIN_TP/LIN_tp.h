#ifndef __LIN_TP_H__
#define __LIN_TP_H__

#include "LIN_tp_cfg.h"

#ifdef EN_LIN_TP

#include "multi_cyc_fifo.h"

/*uds network man function*/
extern void LINTP_MainFun(void);

/*LIN tp system tick control*/
extern void LINTP_SytstemTickControl(void);


/*Init LIN TP list*/
extern void LINTP_Init(void);

#endif /*#ifdef EN_LIN_TP*/

#endif /*#ifndef __LIN_TP_H__*/

/***************************End file********************************/

