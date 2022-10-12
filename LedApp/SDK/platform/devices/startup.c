/*
 * Copyright (c) 2013 - 2014, Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.9, An object should be defined at block
 * scope if its identifier only appears in a single function.
 * All variables with this problem are defined in the linker files.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.11, When an array with external linkage
 * is declared, its size should be explicitly specified.
 * The size of the arrays can not be explicitly determined.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 11.4, A conversion should not be performed
 * between a pointer to object and an integer type.
 * The cast is required to initialize a pointer with an unsigned int define,
 * representing an address.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 11.6, A cast shall not be performed
 * between pointer to void and an arithmetic type.
 * The cast is required to initialize a pointer with an unsigned int define,
 * representing an address.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 2.1, A project shall not contain unreachable
 * code.
 * The condition compares two address defined in linker files that can be different.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External could be made static.
 * Function is defined for usage by application code.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 1.3, Unusual pointer cast (incompatible
 * indirect types).
 * The cast is required to cast the address of linker section to initialization layout.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 11.3, Cast performed between a pointer
 * to object type and a pointer to a different object type.
 * The cast is required to cast the address of linker section to initialization layout.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 11.8, Attempt to cast away const/volatile from a pointer or reference.
 * The cast is required to cast the initialization layout structure.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 18.4, Pointer arithmetic other than array indexing used.
 * This is required to increment the source address.
 *
 */

#include "startup.h"
#include <stdint.h>
#include <stddef.h>

/*******************************************************************************
 * Definitions
 *******************************************************************************/
 /*!
 * @brief Defines the init table layout
 */
typedef struct
{
    uint8_t * rom_start; /*!< Start address of section in ROM */
    uint8_t * ram_start; /*!< Start address of section in RAM */
    uint8_t * rom_end;   /*!< End address of section in ROM */
} copy_layout_t;

/*!
 * @brief Defines the zero table layout
 */
typedef struct
{
    uint8_t * ram_start; /*!< Start address of section in RAM */
    uint8_t * ram_end;   /*!< End address of section in RAM */
} zero_layout_t;

extern uint32_t __COPY_TABLE[];
extern uint32_t __ZERO_TABLE[];
#if (defined(__ARMCC_VERSION))
    extern uint32_t __VECTOR_RAM;
#else
    extern uint32_t __VECTOR_RAM[];
#endif

/*******************************************************************************
 * Static Variables
 ******************************************************************************/
static volatile uint32_t * const s_vectors[NUMBER_OF_CORES] = FEATURE_INTERRUPT_INT_VECTORS;

/*******************************************************************************
 * Code
 ******************************************************************************/
/*FUNCTION**********************************************************************
 *
 * Function Name : init_data_bss
 * Description   : Make necessary initializations for RAM.
 * - Copy the vector table from ROM to RAM.
 * - Copy initialized data from ROM to RAM.
 * - Copy code that should reside in RAM from ROM
 * - Clear the zero-initialized data section.
 *
 * Tool Chains:
 *   __GNUC__           : GNU Compiler Collection
 *   __ghs__            : Green Hills ARM Compiler
 *   __ICCARM__         : IAR ARM Compiler
 *   __DCC__            : Wind River Diab Compiler
 *   __ARMCC_VERSION    : ARMC Compiler
 *
 * Implements    : init_data_bss_Activity
 *END**************************************************************************/
void init_data_bss(void)
{
    const copy_layout_t * copy_layout;
    const zero_layout_t * zero_layout;
    const uint8_t * rom;
    uint8_t * ram;
    uint8_t coreId = 0U;
    uint32_t len = 0U;
    uint32_t size = 0U;
    uint32_t i = 0U;
    uint32_t j = 0U;

#if (defined(__ICCARM__))
    /* Workaround: The table address will be minus 1 in Thumb mode */
    const uint32_t * initTable = (uint32_t *)((uint32_t)((uint32_t *)__COPY_TABLE) - 1U);
    const uint32_t * zeroTable = (uint32_t *)((uint32_t)((uint32_t *)__ZERO_TABLE) - 1U);
#else
    const uint32_t * initTable = (uint32_t *)__COPY_TABLE;
    const uint32_t * zeroTable = (uint32_t *)__ZERO_TABLE;
#endif

    /* Copy initialized table */
    len = *initTable;
    copy_layout = (copy_layout_t *)(initTable + 1U);
    for(i = 0; i < len; i++)
    {
        rom = copy_layout[i].rom_start;
        ram = copy_layout[i].ram_start;
        size = (uint32_t)copy_layout[i].rom_end - (uint32_t)copy_layout[i].rom_start;

        for(j = 0UL; j < size; j++)
        {
            ram[j] = rom[j];
        }
    }

    /* Point the VTOR to the position of vector table */
    coreId = GET_CORE_ID();
    *s_vectors[coreId] = (uint32_t)__VECTOR_RAM;

    /* Clear zero table */
    len = *zeroTable;
    zero_layout = (zero_layout_t *)(zeroTable + 1U);
    for(i = 0; i < len; i++)
    {
        ram = zero_layout[i].ram_start;
        size = (uint32_t)zero_layout[i].ram_end - (uint32_t)zero_layout[i].ram_start;

        for(j = 0UL; j < size; j++)
        {
            ram[j] = 0U;
        }
    }
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
