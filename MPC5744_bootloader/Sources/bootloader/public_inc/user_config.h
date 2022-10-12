#ifndef __USER_CONFIG_H__
#define __USER_CONFIG_H__

/****************************core define ***********************/
/*the macro must >=1*/
#define CORE_NO (1u)
#if (defined CORE_NO) && (CORE_NO < 1)
#undef CORE_NO
#define CORE_NO (1u)
#elif (!defined CORE_NO)
#define CORE_NO (1u)
#endif
/************************************************************/

/****************************ASSERT and DEBUG IO/TIMER**********/
/*Enable debug IO*/
#define EN_DEBUG_IO

/*Enable debug timer*/
//#define EN_DEBUG_TIMER

/*define assert*/
#define EN_ASSERT

/*enable debug flash module*/
#define EN_DEBUG_FLS_MODULE
#define EN_UDS_DEBUG
#define EN_TP_DEBUG
#define EN_APP_DEBUG

/********Config APP information data stroage in none FLASH***/
//#define EN_APP_INFO_DATA_IN_NONE_FLASH
/************************************************************/

/*used CRC or not*/
//#define DebugBootloader_NOTCRC

/*
* If enable EN_FAST_CALCULATE_CRC, please fill following parameter
*/
#ifndef MAX_ONCE_CHECKSUM_SIZE
/*default max once checksum size byte*/
#define MAX_ONCE_CHECKSUM_SIZE (100000u)
//#define MAX_ONCE_CHECKSUM_SIZE (100u)
#endif

/*enable debug FIFO*/
//#define EN_DEBUG_FIFO

#if (defined EN_DEBUG_FLS_MODULE) || (defined EN_UDS_DEBUG) || (defined EN_TP_DEBUG) || (defined EN_APP_DEBUG) || (defined EN_DEBUG_FIFO)
#ifndef EN_DEBUG_PRINT
/*Enable print*/
#define EN_DEBUG_PRINT
#endif
#else
/*Enable print or not*/
//#define EN_DEBUG_PRINT
#endif
/************************************************************/

/************************UDS algthorim access config***************/
/*enable algthorim access with software*/
#define EN_ALG_SW

/*enable algthorim access with hardware*/
#define EN_ALG_HW

/*AES seed length*/
#define AES_SEED_LEN (16u)

/************************************************************/

/******************TP enable and define message ID****************/
/*only one TP can enable, if multi TP enable will trigger error!*/
#define EN_CAN_TP
//#define EN_LIN_TP
//#define EN_ETHERNET_TP
//#define EN_OTHERS_TP

#ifdef EN_CAN_TP
#define	RX_FUN_ID (0x7FFu)   /*can tp rx function ID*/
#define	RX_PHY_ID (0x784u)   /*can tp rx phy ID*/
#define	TX_ID (0x7F0u)       /*can tp tx ID*/
#define RX_ID_MASK (0x700u)  /*CAN TP rx mask*/
/*Enable TX CAN FD or not. If enable CAN FD, CAN TP transmit SF message will over 8 Bytes*/
//#define EN_TX_CAN_FD
#endif

#ifdef EN_LIN_TP
#define RX_BOARD_ID (0x7Fu) /*LIN TP rx board ID -- all messages, response unexpected, but supported*/
#define	RX_FUN_ID (0x7Eu)   /*LIN tp rx function ID -- don't need  response/only support SF*/
#define	RX_PHY_ID (0x55u)   /*LIN tp rx phy ID*/
#define	TX_ID (0x35u)       /*LIN tp tx ID (master NAD ID)*/
#endif
/***********************************************************/

/***********************CRC config****************************/
/*enable CRC module with hardware*/
//#define EN_CRC_HARDWARE

/*enable CRC module with software*/
#define EN_CRC_SOFTWARE

/*FLASH address continue or not*/
#define FALSH_ADDRESS_CONTINUE (FALSE)
/***********************************************************/

/********************FIFO define*******************************/
/*RX message from BUS FIFO ID*/
#define RX_BUS_FIFO        ('r')  /*RX bus fifo*/

#ifdef EN_CAN_TP
#define RX_BUS_FIFO_LEN (300u)     /*RX BUS FIFO length*/
#elif (defined EN_LIN_TP)
#define RX_BUS_FIFO_LEN (50)      /*RX BUS FIFO length*/
#else
#define RX_BUS_FIFO_LEN (50u)     /*RX BUS FIFO length*/
#endif

#ifdef EN_CAN_TP
/*TX message to BUS FIFO ID*/
#define TX_BUS_FIFO        ('t')  /*RX bus fifo*/
#define TX_BUS_FIFO_LEN (100u)     /*RX BUS FIFO length*/
#elif (defined EN_LIN_TP)
/*TX message to BUS FIFO ID*/
#define TX_BUS_FIFO        ('t')  /*RX bus fifo*/
#define TX_BUS_FIFO_LEN (50u)     /*RX BUS FIFO length*/
#else

#endif
/***********************************************************/

/**********************FOTA A/B config************************/
//#define EN_SUPPORT_APP_B
typedef enum
{
	APP_A_TYPE = 0u,         /*APP A type*/
		
#ifdef EN_SUPPORT_APP_B
    APP_B_TYPE = 1u,         /*APP B type*/
#endif

	APP_INVLID_TYPE = 0xFFu, /*APP invalid type*/
}tAPPType;

#ifdef EN_SUPPORT_APP_B
/*enable,  newest is invalid, jump to old app*/
#define EN_NEWEST_APP_INVALID_JUMP_OLD_APP
#endif
/***********************************************************/

/*******************Global interrupt define************************/
/*disable all interrupts*/
#define DisableAllInterrupts() INT_SYS_DisableIRQGlobal()

/*enable all interrupts*/
#define EnableAllInterrupts() INT_SYS_EnableIRQGlobal()
/***********************************************************/

/*******************MCU type for flash erase a sector time***********/
/*MCU type for erase flash time*/
#define MCU_S12Z (1)
#define MCU_S32K14x (2)
#define MCU_S32K11x (3)
#define MCU_MPC5744 (4)

#define MCU_TYPE (MCU_MPC5744)
/***********************************************************/

/******Jump to APP delay time when have not received uds message*******/
//#define EN_DELAY_TIME
#define DELAY_MAX_TIME_MS (5000u)

/***********************************************************/

#endif /*__USER_CONFIG_H__*/

/************************End file********************************/

