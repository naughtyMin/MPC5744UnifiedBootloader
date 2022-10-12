#include "flash.h"
#include "flash_hal_Cfg.h"

/* Declare a Flash config struct which initialized by FLASH_DRV_Init, and will be used all flash operation */
static tFlashOptInfo *g_pstFlashOptInfo = (void *)0;

#define IS_FLASH_DRIVER_IN_RAM	1

status_t FLASH_DRV_Init(void)
{
    /* Clear error bits MCR_EER, MCR_RWE, MCR_SBC, MCR_RVE, MCR_RRE, MCR_AEE, MCR_EEE */
    FLASH_C55->MCR = (C55_MCR_RVE | C55_MCR_RRE |
                      C55_MCR_AEE | C55_MCR_EEE |
                      C55_MCR_EER | C55_MCR_RWE | C55_MCR_SBC);

    return STATUS_SUCCESS;
}

/*init flash*/
void InitFlash(void)
{
    /* Init flash */
	FLASH_DRV_Init();
}

/* Init falsh g_stFlashOptInfo pointer */
void InitFlashAPI(void)
{
    //caculate offset
    uint32_t *tmp = NULL;
    uint32_t flashDriverStartAdd = 0;
    uint32_t flashDriverEndAdd = 0;

    FLASH_HAL_GetFlashDriverInfo(&flashDriverStartAdd, &flashDriverEndAdd);
    tmp = (uint32 *)flashDriverStartAdd;

    for(int i=0; i<sizeof(tFlashOptInfo)/4; i++)
    {
        //tmp[i] -= 0x410;
        tmp[i] += (uint32_t)flashDriverStartAdd;
    }

    g_pstFlashOptInfo = (tFlashOptInfo *)flashDriverStartAdd;

	/* Disable cache to ensure that all flash operations will take effect instantly,
	   this is device dependent */
#ifdef S32K144_SERIES
//	MSCM->OCMDR[0u] |= MSCM_OCMDR_OCM1(0xFu);
//	MSCM->OCMDR[1u] |= MSCM_OCMDR_OCM1(0xFu);
//	MSCM->OCMDR[2u] |= MSCM_OCMDR_OCM1(0xFu);
#endif /* S32K144_SERIES */ 	
}

//#ifdef USE_FLASH_DRIVER

/*erase flash*/
status_t EraseFlash(flash_erase_option_t eraseOption,
        				flash_block_select_t * blockSelect)
{
    status_t ret;        /* Store the driver APIs return code */
#if IS_FLASH_DRIVER_IN_RAM
    ret = g_pstFlashOptInfo->FLASH_DRV_Erase(eraseOption, blockSelect);
#else
    ret = FLASH_DRV_Erase(eraseOption, blockSelect);
#endif
//    DEV_ASSERT(STATUS_SUCCESS == ret);

    return ret;
}

status_t CheckEraseStatus(flash_state_t * opResult)
{
    status_t ret;        /* Store the driver APIs return code */
#if IS_FLASH_DRIVER_IN_RAM
    ret = g_pstFlashOptInfo->FLASH_DRV_CheckEraseStatus(opResult);
#else
    ret = FLASH_DRV_CheckEraseStatus(opResult);
#endif

    return ret;
}

/*write flash. If write flash successfull return TRUE, else return FALSE.*/
status_t ProgramFLASH(flash_context_data_t * pCtxData,
                           uint32_t dest,
                           uint32_t size,
                           uint32_t source)
{
	status_t ret;
#if IS_FLASH_DRIVER_IN_RAM
	ret = g_pstFlashOptInfo->FLASH_DRV_Program(pCtxData, dest, size, source);
#else
	ret = FLASH_DRV_Program(pCtxData, dest, size, source);
#endif
    return ret;
}


status_t CheckFlashProgramStatus(flash_context_data_t * pCtxData,
                                      flash_state_t * opResult)
{
	status_t ret;
#if IS_FLASH_DRIVER_IN_RAM
	ret = g_pstFlashOptInfo->FLASH_DRV_CheckProgramStatus(pCtxData, opResult);
#else
	ret = FLASH_DRV_CheckProgramStatus(pCtxData, opResult);
#endif
	return ret;
}

status_t FLASHProgramVerify(uint32_t dest,
                                 uint32_t size,
                                 uint32_t source,
                                 uint32_t numOfWordCycle,
                                 uint32_t * pFailedAddress,
                                 void (*CallBack)(void))
{
	status_t ret;
#if IS_FLASH_DRIVER_IN_RAM
	ret = g_pstFlashOptInfo->FLASH_DRV_ProgramVerify(dest, size, source, numOfWordCycle, pFailedAddress, CallBack);
#else
	ret = FLASH_DRV_ProgramVerify(dest, size, source, numOfWordCycle, pFailedAddress, CallBack);
#endif
	return ret;
}


status_t FLASHCheckSum(uint32_t dest,
                            uint32_t size,
                            uint32_t numOfWordCycle,
                            uint32_t *pSum,
                            void (*CallBack)(void))
{
	status_t ret;
#if IS_FLASH_DRIVER_IN_RAM
	ret = g_pstFlashOptInfo->FLASH_DRV_CheckSum(dest, size, numOfWordCycle, pSum, CallBack);
#else
	ret = FLASH_DRV_CheckSum(dest, size, numOfWordCycle, pSum, CallBack);
#endif
	return ret;
}

/*!
 * @brief Get the number of low blocks in flash memory.
 *
 */
static inline uint32_t FLASH_GetNumOfLowBlock(void)
{
    uint32_t retValue;

    retValue = FLASH_C55_GET_REG(FLASH_C55->MCRE, C55FMC_MCRE_n16Kl_MASK, C55FMC_MCRE_n16Kl_SHIFT);
    retValue += FLASH_C55_GET_REG(FLASH_C55->MCRE, C55FMC_MCRE_n32Kl_MASK, C55FMC_MCRE_n32Kl_SHIFT);
    retValue += FLASH_C55_GET_REG(FLASH_C55->MCRE, C55FMC_MCRE_n64Kl_MASK, C55FMC_MCRE_n64Kl_SHIFT);
    retValue = retValue << 1U;

    return retValue;
}

/*!
 * @brief Get the number of mid blocks in flash memory.
 *
 */
static inline uint32_t FLASH_GetNumOfMidBlock(void)
{
    uint32_t retValue;

    retValue = FLASH_C55_GET_REG(FLASH_C55->MCRE, C55FMC_MCRE_n16Km_MASK, C55FMC_MCRE_n16Km_SHIFT);
    retValue += FLASH_C55_GET_REG(FLASH_C55->MCRE, C55FMC_MCRE_n32Km_MASK, C55FMC_MCRE_n32Km_SHIFT);
    retValue += FLASH_C55_GET_REG(FLASH_C55->MCRE, C55FMC_MCRE_n64Km_MASK, C55FMC_MCRE_n64Km_SHIFT);
    retValue = retValue << 1U;

    return retValue;
}

/*!
 * @brief Get the number of high blocks in flash memory.
 *
 */
static inline uint32_t FLASH_GetNumOfHighBlock(void)
{
    uint32_t retValue;

    retValue = FLASH_C55_GET_REG(FLASH_C55->MCRE, C55FMC_MCRE_n16Kh_MASK, C55FMC_MCRE_n16Kh_SHIFT);
    retValue += FLASH_C55_GET_REG(FLASH_C55->MCRE, C55FMC_MCRE_n32Kh_MASK, C55FMC_MCRE_n32Kh_SHIFT);
    retValue += FLASH_C55_GET_REG(FLASH_C55->MCRE, C55FMC_MCRE_n64Kh_MASK, C55FMC_MCRE_n64Kh_SHIFT);
    retValue = retValue << 1U;

    return retValue;
}

/*!
 * @brief Get the number of 256K blocks in flash memory.
 *
 */
static inline uint32_t FLASH_GetNumOf256KBlock(void)
{
    return (FLASH_C55_GET_REG(FLASH_C55->MCRE, C55FMC_MCRE_n256K_MASK, C55FMC_MCRE_n256K_SHIFT) << 1U);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLASH_DRV_GetLock
 * Description   : This function will check the block locking status of
 * Low/Middle/High/256K address spaces in the C55 module.
 *
 * Implements    : FLASH_DRV_GetLock_Activity
 *END**************************************************************************/
status_t FLASH_DRV_GetLock(flash_address_space_t lockedBlockSelection,
                           uint32_t * lockedBlockState)
{
    DEV_ASSERT(lockedBlockSelection <= C55_BLOCK_UTEST);
    uint32_t value;                              /* value of block locking register */
    uint32_t mask;                               /* block locking bit mask for the address space */
    uint32_t temp;

    /* Determine which address space is selected */
    switch (lockedBlockSelection)
    {
        case C55_BLOCK_LOW:
            value = FLASH_C55->LOCK0;
            mask = (0xFFFFFFFFU >> (32U - FLASH_GetNumOfLowBlock())) << C55_LOCK0_LOWLOCK_SHIFT;
            /* Mask off the other bits and make proper shift */
            *lockedBlockState = (value & mask) >> C55_LOCK0_LOWLOCK_SHIFT;
            break;
        case C55_BLOCK_MID:
            value = FLASH_C55->LOCK0;
            mask = 0xFFFFFFFFU >> (32U - FLASH_GetNumOfMidBlock());
            *lockedBlockState = (value & mask) >> C55_LOCK0_MIDLOCK_SHIFT;
            break;
        case C55_BLOCK_HIGH:
            value = FLASH_C55->LOCK1;
            mask = 0xFFFFFFFFU >> (32U - FLASH_GetNumOfHighBlock());
            *lockedBlockState = (value & mask) >> C55_LOCK1_HIGHLOCK_SHIFT;
            break;
        case C55_BLOCK_256K_FIRST:
            value = FLASH_C55->LOCK2;
            temp = FLASH_GetNumOf256KBlock();
            if ( temp >= 32U )
            {
                mask = 0xFFFFFFFFU;
            }
            else
            {
                mask = 0xFFFFFFFFU >> (32U - temp);
            }
            *lockedBlockState = (value & mask) >> C55_LOCK2_A256KLOCK_SHIFT;
            break;
        case C55_BLOCK_256K_SECOND:
            value = FLASH_C55->LOCK3;
            temp = FLASH_GetNumOf256KBlock();
            if ( temp > 32U )
            {
                mask = 0xFFFFFFFFU >> (64U - temp);
            }
            else
            {
                mask = 0x0U;
            }
            *lockedBlockState = (value & mask) >> C55_LOCK3_A256KLOCK_SHIFT;
            break;
        case C55_BLOCK_UTEST:
            value = FLASH_C55->LOCK0;
            mask = C55_LOCK0_TSLOCK_MASK;
            *lockedBlockState = (value & mask) >> C55_LOCK0_TSLOCK_SHIFT;
            break;
        default: /* Nothing to do */
            break;
    }

    return STATUS_SUCCESS;
}

status_t GetLock(flash_address_space_t lockedBlockSelection,
                           uint32_t * lockedBlockState)
{
	status_t ret;
	FLASH_DRV_GetLock(lockedBlockSelection, lockedBlockState);
//#if IS_FLASH_DRIVER_IN_RAM
//	ret = g_pstFlashOptInfo->FLASH_DRV_GetLock(lockedBlockSelection, lockedBlockState);
//#else
//	ret = FLASH_DRV_GetLock(lockedBlockSelection, lockedBlockState);
//#endif
	return ret;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLASH_DRV_SetLock
 * Description   : This function will set the block lock state for Low/Middle/High/256K
 * address space on the C55 module to protect them from program or erase.
 *
 * Implements    : FLASH_DRV_SetLock_Activity
 *END**************************************************************************/
status_t FLASH_DRV_SetLock(flash_address_space_t lockedBlockSelection,
                           uint32_t lockedBlockState)
{
    DEV_ASSERT(lockedBlockSelection <= C55_BLOCK_UTEST);
    status_t returnCode = STATUS_SUCCESS;    /* return code */
    uint32_t address = 0x0U;                 /* address of the block locking register */
    uint32_t mask = 0x0U;                    /* block locking field mask of an address space */
    uint32_t shift = 0x0U;                   /* bit shift value for the block locking field of an address space */
    uint32_t lockValue0;                     /* first value of the lock register */
    uint32_t lockValue1;                     /* second value of the lock register  */

    /* Determine which address space is selected */
    switch (lockedBlockSelection)
    {
        case C55_BLOCK_LOW:
            address = C55_LOCK0;
            shift = C55_LOCK0_LOWLOCK_SHIFT;
            mask = (0xFFFFFFFFU >> (32U - FLASH_GetNumOfLowBlock())) << 16U;
            break;
        case C55_BLOCK_MID:
            address = C55_LOCK0;
            shift = C55_LOCK0_MIDLOCK_SHIFT;
            mask = 0xFFFFFFFFU >> (32U - FLASH_GetNumOfMidBlock());
            break;
        case C55_BLOCK_HIGH:
            address = C55_LOCK1;
            shift = C55_LOCK1_HIGHLOCK_SHIFT;
            mask = 0xFFFFFFFFU >> (32U - FLASH_GetNumOfHighBlock());
            break;
        case C55_BLOCK_256K_FIRST:
            address = C55_LOCK2;
            shift = C55_LOCK2_A256KLOCK_SHIFT;
            if ( FLASH_GetNumOf256KBlock() >= 32U )
            {
                mask = 0xFFFFFFFFU;
            }
            else
            {
                mask = 0xFFFFFFFFU >> (32U - FLASH_GetNumOf256KBlock());
            }
            break;
        case C55_BLOCK_256K_SECOND:
            address = C55_LOCK3;
            shift = C55_LOCK3_A256KLOCK_SHIFT;
            /* Re-use lockValue0 to get the number of 256K blocks */
            lockValue0 = FLASH_GetNumOf256KBlock();
            if ( lockValue0 > 32U )
            {
                mask = 0xFFFFFFFFU >> (64U - lockValue0);
            }
            else
            {
                mask = 0x0U;
            }
            break;
        case C55_BLOCK_UTEST:
            address = C55_LOCK0;
            shift = C55_LOCK0_TSLOCK_SHIFT;
            mask = C55_LOCK0_TSLOCK_MASK;
            break;
        default: /* Nothing to do */
            break;
    }

    address += FLASH_C55_BASE;
    /* Clear the block lock field */
    REG_BIT_CLEAR32(address, mask);
    /* Set the new value to the block lock field */
    lockValue0 = (lockedBlockState << shift) & mask;
    REG_BIT_SET32(address, lockValue0);
    /* Read out the locking status */
    lockValue1 = REG_READ32(address) & lockValue0;
    /* Check the setting lock value with block lock field */
    if (lockValue0 != lockValue1)
    {
        returnCode = STATUS_ERROR;
    }

    return returnCode;
}

status_t SetLock(flash_address_space_t lockedBlockSelection,
                           uint32_t lockedBlockState)
{
	status_t ret;
	ret = FLASH_DRV_SetLock(lockedBlockSelection, lockedBlockState);
//#if IS_FLASH_DRIVER_IN_RAM
//	ret = g_pstFlashOptInfo->FLASH_DRV_SetLock(lockedBlockSelection, lockedBlockState);
//#else
//	ret = FLASH_DRV_SetLock(lockedBlockSelection, lockedBlockState);
//#endif
	return ret;
}
/************************End file********************************/

