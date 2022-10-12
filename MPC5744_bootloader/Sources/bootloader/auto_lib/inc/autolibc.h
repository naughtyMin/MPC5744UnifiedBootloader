/**
  @file             autolibc.h
  @version          0.0.2.0

  @brief            Header file for the AutoLibc.c

  @details

  Project           M4_ETH_PROJECT_NAME

  Platform          M4_ETH_PLATFORM

  SWVersion         M4_ETH_SW_VERSION

  Copyright (c) 2012-2016 Freescale Semiconductor Inc.
  Copyright (c) 2016 NXP
  
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

#ifndef AUTOLIBC_H
#define AUTOLIBC_H

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
/* labs() is identical to abs(), because int and long are same on 32bit PPC */
#define fsl_labs(a) fsl_abs(a)

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
void *fsl_memcpy (void *pavDest2, const void *pcoavSource2,uint32_t u32Length2);
void *fsl_memset (void *pavDest3, uint8_t u8Fill3, uint32_t u32Length3);
void *fsl_memmove (void *pavDest4,const void *pcoavSource4,uint32_t u32Length4);
int32_t fsl_memcmp ( const void *pcoavMemA5,
                     const void *pcoavMemB5,
                     uint32_t u32Size5
                   );
int32_t fsl_strcmp (const char_t *pcoszStrA6, const char_t *pcoszStrB6);
char_t *fsl_strncpy (char_t *pszDest7, const char_t *pcoszSrc7, uint32_t u32Length7);
uint32_t fsl_strlen (const char_t pcozsStr8[]);
void fsl_srand (uint32_t u32Seed9);
uint32_t fsl_rand (void);
int32_t fsl_abs (int32_t s32Number);
int64_t fsl_abs64 (int64_t s64Number);


#endif /* AUTOLIBC_H */