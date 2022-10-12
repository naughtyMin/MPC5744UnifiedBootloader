
#ifndef __FLASH_H__
#define __FLASH_H__

#include "flash_cfg.h"
#include "flash_c55_driver.h"

//#ifdef NXF47391
/*******************************************************************************
* Callback function prototype
*******************************************************************************/
/*! @brief Call back function pointer data type
 *
 *   If using callback in the application, any code reachable from this function
 *   must not be placed in a Flash block targeted for a program/erase operation.
 *   Functions can be placed in RAM section by using the START/END_FUNCTION_DEFINITION/DECLARATION_RAMSECTION macros.
 */
typedef void (* flash_callback_t)(void);

/*! @brief  Null callback */
#define NULL_CALLBACK      ((flash_callback_t)0xFFFFFFFFU)

#ifndef FLASH_SDK_USING

/* Word size 2 bytes */
#define FTFx_WORD_SIZE     0x0002U
/* Long word size 4 bytes */
#define FTFx_LONGWORD_SIZE 0x0004U
/* Phrase size 8 bytes */
#define FTFx_PHRASE_SIZE   0x0008U
/* Double-phrase size 16 bytes */
#define FTFx_DPHRASE_SIZE  0x0010U

/*C55 Flash*/
#define FLASH_C55_BASE                    C55FMC_BASE                /*!< Base of register in flash c55 module */
#define FLASH_C55                         C55FMC                     /*!< Base pointer of flash peripheral */
#define C55_MCR_RVE                       C55FMC_MCR_RVE_MASK        /*!< Read Voltage Error */
#define C55_MCR_RRE                       C55FMC_MCR_RRE_MASK        /*!< Read Reference Error */
#define C55_MCR_AEE                       C55FMC_MCR_AEE_MASK        /*!< Address Encode Error */
#define C55_MCR_EEE                       C55FMC_MCR_EEE_MASK        /*!< ECC after ECC Error */
#define C55_MCR_EER                       C55FMC_MCR_EER_MASK        /*!< ECC Event Error */
#define C55_MCR_RWE                       C55FMC_MCR_RWE_MASK        /*!< Read While Write Event Error */
#define C55_MCR_SBC                       C55FMC_MCR_SBC_MASK        /*!< Single Bit Correction Error */

#define C55_LOCK0           0x0010U       /*!< Lock 0 Register */
#define C55_LOCK1           0x0014U       /*!< Lock 1 Register */
#define C55_LOCK2           0x0018U       /*!< Lock 2 Register */
#define C55_LOCK3           0x001CU       /*!< Lock 3 Register */

/* LOCK0 Bit Fields */
#define C55_LOCK0_MIDLOCK_MASK            C55FMC_LOCK0_MIDLOCK_MASK
#define C55_LOCK0_MIDLOCK_SHIFT           C55FMC_LOCK0_MIDLOCK_SHIFT
#define C55_LOCK0_LOWLOCK_MASK            C55FMC_LOCK0_LOWLOCK_MASK
#define C55_LOCK0_LOWLOCK_SHIFT           C55FMC_LOCK0_LOWLOCK_SHIFT
#define C55_LOCK0_TSLOCK_MASK             C55FMC_LOCK0_TSLOCK_MASK
#define C55_LOCK0_TSLOCK_SHIFT            C55FMC_LOCK0_TSLOCK_SHIFT
/* LOCK1 Bit Fields */
#define C55_LOCK1_HIGHLOCK_MASK           C55FMC_LOCK1_HIGHLOCK_MASK
#define C55_LOCK1_HIGHLOCK_SHIFT          C55FMC_LOCK1_HIGHLOCK_SHIFT
/* LOCK2 Bit Fields */
#define C55_LOCK2_A256KLOCK_MASK          C55FMC_LOCK2_A256KLOCK_MASK
#define C55_LOCK2_A256KLOCK_SHIFT         C55FMC_LOCK2_A256KLOCK_SHIFT
/* LOCK3 Bit Fields */
#define C55_LOCK3_A256KLOCK_MASK          C55FMC_LOCK3_A256KLOCK_MASK
#define C55_LOCK3_A256KLOCK_SHIFT         C55FMC_LOCK3_A256KLOCK_SHIFT
/* SEL0 Bit Fields */
#define C55_SEL0_MIDSEL_MASK              C55FMC_SEL0_MIDSEL_MASK
#define C55_SEL0_MIDSEL_SHIFT             C55FMC_SEL0_MIDSEL_SHIFT
#define C55_SEL0_LOWSEL_MASK              C55FMC_SEL0_LOWSEL_MASK
#define C55_SEL0_LOWSEL_SHIFT             C55FMC_SEL0_LOWSEL_SHIFT
/* SEL1 Bit Fields */
#define C55_SEL1_HIGHSEL_MASK             C55FMC_SEL1_HIGHSEL_MASK
#define C55_SEL1_HIGHSEL_SHIFT            C55FMC_SEL1_HIGHSEL_SHIFT
/* SEL2 Bit Fields */
#define C55_SEL2_A256KSEL_MASK            C55FMC_SEL2_A256KSEL_MASK
#define C55_SEL2_A256KSEL_SHIFT           C55FMC_SEL2_A256KSEL_SHIFT
/* SEL3 Bit Fields */
#define C55_SEL3_A256KSEL_MASK            C55FMC_SEL3_A256KSEL_MASK
#define C55_SEL3_A256KSEL_SHIFT           C55FMC_SEL3_A256KSEL_SHIFT
/* OPP0 Bit Fields */
#define C55_OPP0_MIDOPP_MASK              C55FMC_OPP0_MIDOPP_MASK
#define C55_OPP0_MIDOPP_SHIFT             C55FMC_OPP0_MIDOPP_SHIFT
#define C55_OPP0_LOWOPP_MASK              C55FMC_OPP0_LOWOPP_MASK
#define C55_OPP0_LOWOPP_SHIFT             C55FMC_OPP0_LOWOPP_SHIFT
/* OPP1 Bit Fields */
#define C55_OPP1_HIGHOPP_MASK             C55FMC_OPP1_HIGHOPP_MASK
#define C55_OPP1_HIGHOPP_SHIFT            C55FMC_OPP1_HIGHOPP_SHIFT
/* OPP2 Bit Fields */
#define C55_OPP2_A256KOPP_MASK            C55FMC_OPP2_A256KOPP_MASK
#define C55_OPP2_A256KOPP_SHIFT           C55FMC_OPP2_A256KOPP_SHIFT
/* OPP3 Bit Fields */
#define C55_OPP3_A256KOPP_MASK            C55FMC_OPP3_A256KOPP_MASK
#define C55_OPP3_A256KOPP_SHIFT           C55FMC_OPP3_A256KOPP_SHIFT
/*! @brief get the value of bit mask in register */
#define FLASH_C55_GET_REG(reg, mask, shift) ((reg & mask) >> shift)


/*!
 * @brief Flash User Configuration Structure
 *
 * Implements : flash_user_config_t_Class
 */
typedef struct
{
    uint32_t PFlashBase;            /*!< The base address of P-Flash memory */
    uint32_t PFlashSize;            /*!< The size in byte of P-Flash memory */
    uint32_t DFlashBase;            /*!< For FlexNVM device, this is the base address of D-Flash memory
                                     *    (FlexNVM memory); For non-FlexNVM device, this field is unused */
    uint32_t EERAMBase;             /*!< The base address of FlexRAM (for FlexNVM device)
                                     *    or acceleration RAM memory (for non-FlexNVM device) */
    flash_callback_t CallBack;      /*!< Call back function to service the time critical events. Any code reachable from this function
                                     *   must not be placed in a Flash block targeted for a program/erase operation */
} flash_user_config_t;

/*!
 * @brief Flash SSD Configuration Structure
 *
 * The structure includes the static parameters for C90TFS/FTFx which are
 * device-dependent. The fields including
 * PFlashBlockBase, PFlashBlockSize, DFlashBlockBase, EERAMBlockBase,
 * and CallBack are passed via flash_user_config_t.
 * The rest of parameters such as DFlashBlockSize, and EEEBlockSize will be
 * initialized in FLASH_DRV_Init() automatically.
 *
 * Implements : flash_ssd_config_t_Class
 */
typedef struct
{
    uint32_t PFlashBase;          /*!< The base address of P-Flash memory */
    uint32_t PFlashSize;          /*!< The size in byte of P-Flash memory */
    uint32_t DFlashBase;          /*!< For FlexNVM device, this is the base address of D-Flash memory (FlexNVM memory);
                                   *    For non-FlexNVM device, this field is unused */
    uint32_t DFlashSize;          /*!< For FlexNVM device, this is the size in byte of area
                                   *    which is used as D-Flash from FlexNVM memory;
                                   *    For non-FlexNVM device, this field is unused */
    uint32_t EERAMBase;           /*!< The base address of FlexRAM (for FlexNVM device)
                                   *    or acceleration RAM memory (for non-FlexNVM device) */
    uint32_t EEESize;             /*!< For FlexNVM device, this is the size in byte of EEPROM area which was partitioned
                                   *    from FlexRAM; For non-FlexNVM device, this field is unused */
    flash_callback_t CallBack;    /*!< Call back function to service the time critical events. Any code reachable from this function
                                   *   must not be placed in a Flash block targeted for a program/erase operation */
} flash_ssd_config_t;
#endif	//end of FLASH_SDK_USING

typedef struct
{
	status_t (*FLASH_DRV_CheckEraseStatus)(flash_state_t * opResult);

	status_t (*FLASH_DRV_SetLock)(flash_address_space_t lockedBlockSelection,
	                           uint32_t lockedBlockState);

	status_t (*FLASH_DRV_GetLock)(flash_address_space_t lockedBlockSelection,
	                           uint32_t * lockedBlockState);

	status_t (*FLASH_DRV_Erase)(flash_erase_option_t eraseOption, flash_block_select_t * blockSelect);

	status_t (*FLASH_DRV_Program)(flash_context_data_t * pCtxData,
									uint32_t dest,
									uint32_t size,
									uint32_t source);

	status_t (*FLASH_DRV_CheckProgramStatus)(flash_context_data_t * pCtxData,
            								flash_state_t * opResult);

	status_t (*FLASH_DRV_ProgramVerify)(uint32_t dest,
									uint32_t size,
									uint32_t source,
									uint32_t numOfWordCycle,
									uint32_t * pFailedAddress,
									void (*CallBack)(void));

	status_t (*FLASH_DRV_CheckSum)(uint32_t dest,
								uint32_t size,
								uint32_t numOfWordCycle,
								uint32_t *pSum,
								void (*CallBack)(void));
} tFlashOptInfo;

//typedef struct
//{
//	status_t (*Flash_Unlock_g)(uint32_t startAddr, uint32_t endAddr);
//
//	status_t (*Flash_Erase_g)(uint32_t startAddr, uint32_t endAddr);
//
//	status_t (*Flash_Check_g)(uint32_t startAddr, uint32_t endAddr);
//
//	status_t (*Flash_Program_g)(uint32_t startAddr, uint32_t endAddr, uint32_t *buffer, uint32_t len);
//
//	status_t (*Flash_Lock_g)(uint32_t startAddr, uint32_t endAddr);
//
//	uint32_t (*Flash_Read_g)(uint32_t addr);
//
//} tFlashOptInfo;

//typedef struct
//{
//    status_t (*FLASH_EraseAllBlock)(const flash_ssd_config_t * pSSDConfig);
//    status_t (*FLASH_VerifyAllBlock)(const flash_ssd_config_t * pSSDConfig,uint8_t marginLevel);
//    status_t (*FLASH_EraseSector)(const flash_ssd_config_t * pSSDConfig,uint32_t dest,uint32_t size);
//    status_t (*FLASH_VerifySection)(const flash_ssd_config_t * pSSDConfig,uint32_t dest,uint16_t number,uint8_t marginLevel);
//    void (*FLASH_EraseSuspend)(void);
//    void (*FLASH_EraseResume)(void);
//    status_t (*FLASH_Program)(const flash_ssd_config_t * pSSDConfig,uint32_t dest, uint32_t size,const uint8_t * pData);
//    status_t (*FLASH_ProgramCheck)(const flash_ssd_config_t * pSSDConfig,uint32_t dest,uint32_t size,const uint8_t * pExpectedData,uint32_t * pFailAddr,uint8_t marginLevel);
//    status_t (*FLASH_ProgramSection)(const flash_ssd_config_t * pSSDConfig,uint32_t dest,uint16_t number);
//    status_t (*FLASH_EraseBlock)(const flash_ssd_config_t * pSSDConfig, uint32_t dest);
//    status_t (*FLASH_CommandSequence)(const flash_ssd_config_t * pSSDConfig);
//    status_t (*FLASH_VerifyBlock)(const flash_ssd_config_t * pSSDConfig,uint32_t dest,uint8_t marginLevel);
//} tFlashOptInfo;

//#define FLASH_API_DEBUG

#ifdef FLASH_API_DEBUG
extern void Flash_test(void);
#endif	//end of FLASH_API_DEBUG

//#endif	//end of NXF47391


//#ifdef USE_FLASH_DRIVER
extern status_t EraseFlash(flash_erase_option_t eraseOption,
											flash_block_select_t * blockSelect);

extern unsigned char WriteFlash(const uint32_t i_xStartAddr,
                                const void *i_pvDataBuf,
                                const unsigned short i_usDataLen);

/*flash erase verify*/
extern unsigned char FlashEraseVerify(const unsigned long i_ulStartVerifyAddr,
                                      const unsigned long i_ulVerifyLen);
//#endif	//end of USE_FLASH_DRIVER

/*init flash*/
extern status_t FLASH_DRV_Init(void);

/* Init falsh g_stFlashOptInfo pointer */
extern void InitFlashAPI(void);


/***********************************************************
** read a byte from flash. Read data address must  global address.
************************************************************/
extern unsigned char ReadFlashByte(const unsigned long i_ulGloabalAddress);

/********************************************************
**	read data from current page flash.
** 	paramer :
**		@	i_ulLogicalAddr : Local address
**		@	i_ulLength : need read data length
**		@	o_pucDataBuf : read data buf
*********************************************************/
extern void ReadFlashMemory(const unsigned long i_ulLogicalAddr,
                            const unsigned long i_ulLength,
                            unsigned char* o_pucDataBuf);
#endif /*__FLASH_H__*/

/************************End file********************************/



