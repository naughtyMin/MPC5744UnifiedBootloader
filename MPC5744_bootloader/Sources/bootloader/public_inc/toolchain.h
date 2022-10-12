/** 
  @file             toolchain.h
  @version          0.0.0.0

  @brief            Toolchain specific definitions
  @details          

  Project           M4_ETH_PROJECT_NAME
  Platform          M4_ETH_PLATFORM

  SWVersion         M4_ETH_RELEASE_VERSION


  (c) Copyright 2014 Freescale Semiconductor Inc.
  Copyright 2018 NXP
  
 This software is owned or controlled by NXP and may only be used strictly 
 in accordance with the applicable license terms.  By expressly accepting 
 such terms or by downloading, installing, activating and/or otherwise using 
 the software, you are agreeing that you have read, and that you agree to 
 comply with and are bound by, such license terms.  If you do not agree to 
 be bound by the applicable license terms, then you may not retain, 
 install, activate or otherwise use the software.
*/
/*==============================================================================
==============================================================================*/

/*==============================================================================
                                         MISRA VIOLATIONS
==============================================================================*/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section toolchain_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, A function should be used in preference to a function-like macro.
* It is not possible to use function to abstract data attribute definition.
*/

#ifndef TOOLCHAIN_H
    #define TOOLCHAIN_H
/*==============================================================================
                                INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==============================================================================*/

/*==============================================================================
                      SOURCE FILE VERSION INFORMATION
==============================================================================*/

/*==============================================================================
                            FILE VERSION CHECKS
==============================================================================*/

/*==============================================================================
                                 CONSTANTS
==============================================================================*/

/*==============================================================================
                             DEFINES AND MACROS
==============================================================================*/
#if defined __ghs__ || defined (__GNUC__)
    #define ASM_KEYWORD         __asm
    #define INTERRUPT_FUNC      __interrupt
    #define INLINE              inline
    #define PACKED_STRUCT_BEGIN
    #define PACKED_STRUCT_FIELD(x) x __attribute__((packed))
    #define PACKED_STRUCT_END   __attribute__((packed))
    /** @violates @ref toolchain_h_REF_1 MISRA rule 19.7 */
    #define ALIGNEDXB(x)        __attribute__((aligned(x)))
#elif defined __DCC__
    #define ASM_KEYWORD         __asm volatile
    #define INTERRUPT_FUNC      __interrupt__
    #define INLINE              __inline__
    #define PACKED_STRUCT_BEGIN __packed__ 
    #define PACKED_STRUCT_FIELD(x) x
    #define PACKED_STRUCT_END
    /** @violates @ref toolchain_h_REF_1 MISRA rule 19.7 */
    #define ALIGNEDXB(x)        __attribute__((aligned(x)))
#elif defined __MWERKS__
	#define INLINE				inline
   // #error "For this compiler it must be updated here"
#elif defined __CC_ARM
    #define ASM_KEYWORD         __asm
    #define INTERRUPT_FUNC      __irq
    /* NOTE: __inline must be used (with __) because we use inlining in C90 */
    #if 1 /* NOTE: inlining is not working correctly between modules in DS-5,
             so it must be disabled. Otherwise the code would not compile or
             the INLINEs would have to be removed at problematic locations */
        #define INLINE          __inline
    #else
        #define INLINE
    #endif
    #define PACKED_STRUCT_BEGIN
    #define PACKED_STRUCT_FIELD(x) x __attribute__((packed))
    #define PACKED_STRUCT_END   __attribute__((packed))
    /** @violates @ref toolchain_h_REF_1 MISRA rule 19.7 */
    #define ALIGNEDXB(x)        __attribute__((aligned(x)))
#elif defined __IAR_SYSTEMS_ICC__
    #define ASM_KEYWORD         __asm volatile
    #define INTERRUPT_FUNC      __interrupt
    #define INLINE              inline
    #if 1 /* Applicable to version 7.50.3 */
        #define STRINGIZE(X) #X
        #define PACKED_STRUCT_BEGIN     __packed
        #define PACKED_STRUCT_FIELD(x)  x
        #define PACKED_STRUCT_END       
        /** @violates @ref toolchain_h_REF_1 MISRA rule 19.7 */
        #define ALIGNEDXB(n)            _Pragma(STRINGIZE(data_alignment=n))
    #else /* Applicable to version 8.30.2 */
        #define PACKED_STRUCT_BEGIN     
        #define PACKED_STRUCT_FIELD(x)  x
        #define PACKED_STRUCT_END       __attribute__((packed))
        /** @violates @ref toolchain_h_REF_1 MISRA rule 19.7 */
        #define ALIGNEDXB(n)            __attribute__((aligned(n)))
    #endif
#else
    #error "Unknown toolchain"
#endif

/*==============================================================================
                                    ENUMS
==============================================================================*/

/*==============================================================================
                        STRUCTURES AND OTHER TYPEDEFS
==============================================================================*/

/*==============================================================================
                         GLOBAL VARIABLE DECLARATIONS
==============================================================================*/

/*==============================================================================
                             FUNCTION PROTOTYPES
==============================================================================*/
 
#endif /* TOOLCHAIN_H */