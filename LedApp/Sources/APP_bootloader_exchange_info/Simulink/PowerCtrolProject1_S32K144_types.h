/*
 * File: PowerCtrolProject1_S32K144_types.h
 *
 * Code generated for Simulink model 'PowerCtrolProject1_S32K144'.
 *
 * Model version                  : 1.4096
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep  5 11:48:41 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PowerCtrolProject1_S32K144_types_h_
#define RTW_HEADER_PowerCtrolProject1_S32K144_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_
#define DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_

typedef struct {
  uint8_T Extended;
  uint8_T Length;
  uint8_T Remote;
  uint8_T Error;
  uint32_T ID;
  real_T Timestamp;
  uint8_T Data[8];
} CAN_MESSAGE_BUS;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_PowerCtrolProject1_S32K RT_MODEL_PowerCtrolProject1_S32;

#endif                                 /* RTW_HEADER_PowerCtrolProject1_S32K144_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
