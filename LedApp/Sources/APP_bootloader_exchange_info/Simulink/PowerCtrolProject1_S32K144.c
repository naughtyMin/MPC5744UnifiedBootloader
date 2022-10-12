/*
 * File: PowerCtrolProject1_S32K144.c
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

#include "PowerCtrolProject1_S32K144.h"
#include "PowerCtrolProject1_S32K144_private.h"

/* Named constants for Chart: '<S55>/Chart' */
#define PowerCtrolP_IN_DCDCFaultCounter ((uint8_T)2U)
#define PowerCtrolPro_IN_DCDCFatalFault ((uint8_T)1U)
#define PowerCtrolPro_IN_DCDCNormalWork ((uint8_T)3U)
#define PowerCtrolProjec_IN_DCDCInitial ((uint8_T)1U)
#define PowerCtrolProject1_IN_DCDCReady ((uint8_T)2U)
#define PowerCtrolProject1_IN_DCDCStart ((uint8_T)4U)
#define PowerCtrolProject1_S3_IN_DCDCOn ((uint8_T)2U)
#define PowerCtrolProject1_S_IN_DCDCOff ((uint8_T)1U)
#define PowerCtrolProject1_S_IN_DCDCRun ((uint8_T)3U)
#define PowerCtrolProject_IN_DCDCPreOff ((uint8_T)3U)
#define PowerCtrol_IN_NO_ACTIVE_CHILD_h ((uint8_T)0U)

/* Named constants for Chart: '<S80>/DebounceState' */
#define PowerCtrolProject1_S32K1_IN_Low ((uint8_T)3U)
#define PowerCtrolProject1_S32K_IN_High ((uint8_T)1U)
#define PowerCtrolProject1__IN_High2Low ((uint8_T)2U)
#define PowerCtrolProject1__IN_Low2High ((uint8_T)4U)

/* Named constants for Chart: '<S65>/OBCInvertChrgChart' */
#define PowerCtrolPr_IN_CloseInpAndOutp ((uint8_T)2U)
#define PowerCtrolPr_IN_NoConnCloseInvt ((uint8_T)6U)
#define PowerCtrolPr_IN_NoConnCloseOutp ((uint8_T)7U)
#define PowerCtrolPro_IN_NoConnStrtInvt ((uint8_T)11U)
#define PowerCtrolProj_IN_ConnCloseInvt ((uint8_T)2U)
#define PowerCtrolProj_IN_ConnCloseOutp ((uint8_T)3U)
#define PowerCtrolProj_IN_NoConnOpenInp ((uint8_T)10U)
#define PowerCtrolProje_IN_ConnCloseInp ((uint8_T)1U)
#define PowerCtrolProje_IN_ConnStrtInvt ((uint8_T)5U)
#define PowerCtrolProject1_S32K_IN_Init ((uint8_T)2U)
#define PowerCtrolProject1_S_IN_ACSuply ((uint8_T)1U)
#define PowerCtrolProject1_S_IN_OpenInp ((uint8_T)5U)
#define PowerCtrolProject1__IN_ConnChrg ((uint8_T)1U)
#define PowerCtrolProject1__IN_ConnInit ((uint8_T)4U)
#define PowerCtrolProject1__IN_ConnInvt ((uint8_T)4U)
#define PowerCtrolProject1__IN_Inverter ((uint8_T)1U)
#define PowerCtrolProject1__IN_OpenOutp ((uint8_T)6U)
#define PowerCtrolProject_IN_ConnChrg_g ((uint8_T)3U)
#define PowerCtrolProject_IN_NoConnChrg ((uint8_T)3U)
#define PowerCtrolProject_IN_NoConnInit ((uint8_T)8U)
#define PowerCtrolProject_IN_NoConnInvt ((uint8_T)9U)
#define PowerCtrolProject_IN_NoInverter ((uint8_T)2U)

/* Exported data definition */

/* Definition for custom storage class: Struct */
can_rx_msg_type can_rx_msg;

/* Block signals (default storage) */
BlockIO_PowerCtrolProject1_S32K PowerCtrolProject1_S32K144_B;

/* Block states (default storage) */
D_Work_PowerCtrolProject1_S32K1 PowerCtrolProject1_S32K14_DWork;

/* External outputs (root outports fed by signals with default storage) */
ExternalOutputs_PowerCtrolProje PowerCtrolProject1_S32K144_Y;

/* Real-time model */
RT_MODEL_PowerCtrolProject1_S32 PowerCtrolProject1_S32K144_M_;
RT_MODEL_PowerCtrolProject1_S32 *const PowerCtrolProject1_S32K144_M =
  &PowerCtrolProject1_S32K144_M_;

/* Forward declaration for local functions */
static void PowerCtrolProject1_S_NoConnChrg(const boolean_T *NISP_sigOut, const
  boolean_T *RelationalOperator, const uint8_T *NISP_SigOut_i, uint8_T
  *NISP_SigOut_k, uint8_T *NISP_SigOut_j, boolean_T *NISP_sigOut_k);
static void PowerCtrolProject1_S32_ConnChrg(const boolean_T *NISP_sigOut, const
  uint8_T *NISP_SigOut_i, const uint8_T *NISP_SigOut_l, uint8_T *NISP_SigOut_k,
  uint8_T *NISP_SigOut_j, boolean_T *NISP_sigOut_k);
real32_T look1_iflf_binlc(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T maxIndex)
{
  real32_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0F;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

real32_T look1_iflf_binlx(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T maxIndex)
{
  real32_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

/*
 * System initialize for atomic system:
 *    '<S73>/Chart1'
 *    '<S74>/Chart1'
 *    '<S99>/Chart1'
 */
void PowerCtrolProject1__Chart1_Init(rtDW_Chart1_PowerCtrolProject1_ *localDW)
{
  localDW->timer = 0.0;
  localDW->step = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S73>/Chart1'
 *    '<S74>/Chart1'
 *    '<S99>/Chart1'
 */
void PowerCtrolProject1_S32K1_Chart1(boolean_T rtu_in, boolean_T rtu_last_out,
  boolean_T *rty_out, rtDW_Chart1_PowerCtrolProject1_ *localDW)
{
  /* Chart: '<S73>/Chart1' */
  if (localDW->step == 0.0) {
    *rty_out = false;
    localDW->step++;
  } else if (rtu_in == rtu_last_out) {
    localDW->timer++;
    if (localDW->timer > 50.0) {
      *rty_out = rtu_in;
    }
  } else {
    localDW->timer = 0.0;
  }

  /* End of Chart: '<S73>/Chart1' */
}

/*
 * System initialize for atomic system:
 *    '<S164>/resetting fault filter'
 *    '<S170>/resetting fault filter'
 *    '<S177>/resetting fault filter'
 *    '<S184>/resetting fault filter'
 *    '<S191>/resetting fault filter'
 *    '<S206>/resetting fault filter'
 *    '<S212>/resetting fault filter'
 *    '<S218>/resetting fault filter'
 *    '<S225>/resetting fault filter'
 *    '<S231>/resetting fault filter'
 *    ...
 */
void ff_resetting_Init(boolean_T *rty_fault_flg, uint8_T *rty_ff_count,
  rtDW_ff_resetting *localDW)
{
  /* SystemInitialize for Chart: '<S165>/rff_ctl' */
  localDW->count = 0;
  *rty_fault_flg = false;
  *rty_ff_count = 0U;
}

/*
 * System reset for atomic system:
 *    '<S164>/resetting fault filter'
 *    '<S170>/resetting fault filter'
 *    '<S177>/resetting fault filter'
 *    '<S184>/resetting fault filter'
 *    '<S191>/resetting fault filter'
 *    '<S206>/resetting fault filter'
 *    '<S212>/resetting fault filter'
 *    '<S218>/resetting fault filter'
 *    '<S225>/resetting fault filter'
 *    '<S231>/resetting fault filter'
 *    ...
 */
void ff_resetting_Reset(boolean_T *rty_fault_flg, uint8_T *rty_ff_count,
  rtDW_ff_resetting *localDW)
{
  /* SystemReset for Chart: '<S165>/rff_ctl' */
  localDW->count = 0;
  *rty_fault_flg = false;
  *rty_ff_count = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S164>/resetting fault filter'
 *    '<S170>/resetting fault filter'
 *    '<S177>/resetting fault filter'
 *    '<S184>/resetting fault filter'
 *    '<S191>/resetting fault filter'
 *    '<S206>/resetting fault filter'
 *    '<S212>/resetting fault filter'
 *    '<S218>/resetting fault filter'
 *    '<S225>/resetting fault filter'
 *    '<S231>/resetting fault filter'
 *    ...
 */
void ff_resetting(boolean_T rtu_inst_fault, uint8_T rtu_sat, uint8_T rtu_inc,
                  uint8_T rtu_dec, boolean_T *rty_fault_flg, uint8_T
                  *rty_ff_count, rtDW_ff_resetting *localDW)
{
  /* Chart: '<S165>/rff_ctl' */
  if (rtu_inst_fault) {
    localDW->count += rtu_inc;
  } else {
    localDW->count -= rtu_dec;
  }

  if (localDW->count >= rtu_sat) {
    localDW->count = rtu_sat;
    *rty_fault_flg = true;
  } else {
    if (localDW->count <= 0) {
      localDW->count = 0;
      *rty_fault_flg = false;
    }
  }

  *rty_ff_count = (uint8_T)localDW->count;

  /* End of Chart: '<S165>/rff_ctl' */
}

/*
 * System initialize for atomic system:
 *    '<S164>/valid_signal_selection'
 *    '<S170>/valid_signal_selection'
 *    '<S177>/valid_signal_selection'
 *    '<S184>/valid_signal_selection'
 *    '<S191>/valid_signal_selection'
 *    '<S206>/valid_signal_selection'
 *    '<S218>/valid_signal_selection'
 *    '<S231>/valid_signal_selection'
 *    '<S238>/valid_signal_selection'
 *    '<S254>/valid_signal_selection'
 *    ...
 */
void Pow_valid_signal_selection_Init(real32_T *rty_valid_signal)
{
  *rty_valid_signal = 0.0F;
}

/*
 * System reset for atomic system:
 *    '<S164>/valid_signal_selection'
 *    '<S170>/valid_signal_selection'
 *    '<S177>/valid_signal_selection'
 *    '<S184>/valid_signal_selection'
 *    '<S191>/valid_signal_selection'
 *    '<S206>/valid_signal_selection'
 *    '<S218>/valid_signal_selection'
 *    '<S231>/valid_signal_selection'
 *    '<S238>/valid_signal_selection'
 *    '<S254>/valid_signal_selection'
 *    ...
 */
void Po_valid_signal_selection_Reset(real32_T *rty_valid_signal)
{
  *rty_valid_signal = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S164>/valid_signal_selection'
 *    '<S170>/valid_signal_selection'
 *    '<S177>/valid_signal_selection'
 *    '<S184>/valid_signal_selection'
 *    '<S191>/valid_signal_selection'
 *    '<S206>/valid_signal_selection'
 *    '<S218>/valid_signal_selection'
 *    '<S231>/valid_signal_selection'
 *    '<S238>/valid_signal_selection'
 *    '<S254>/valid_signal_selection'
 *    ...
 */
void PowerCtr_valid_signal_selection(real32_T rtu_def_value, real32_T
  rtu_new_signal, boolean_T rtu_ifault_flg, boolean_T rtu_fault_flg, real32_T
  rtu_old_signal, real32_T *rty_valid_signal)
{
  /* Chart: '<S164>/valid_signal_selection' */
  if (rtu_fault_flg) {
    *rty_valid_signal = rtu_def_value;
  } else if (rtu_ifault_flg) {
    *rty_valid_signal = rtu_old_signal;
  } else {
    *rty_valid_signal = rtu_new_signal;
  }

  /* End of Chart: '<S164>/valid_signal_selection' */
}

/*
 * System initialize for atomic system:
 *    '<S161>/signal validity checking'
 *    '<S168>/signal validity checking'
 *    '<S175>/signal validity checking'
 *    '<S182>/signal validity checking'
 *    '<S189>/signal validity checking'
 *    '<S203>/signal validity checking'
 *    '<S216>/signal validity checking'
 *    '<S229>/signal validity checking'
 *    '<S236>/signal validity checking'
 *    '<S251>/signal validity checking'
 *    ...
 */
void sig_valid_check_Init(boolean_T *rty_fault_flg, real32_T *rty_valid_signal,
  rtDW_sig_valid_check *localDW)
{
  uint8_T rtb_ff_count_g;

  /* InitializeConditions for UnitDelay: '<S164>/UnitDelay' */
  localDW->UnitDelay_DSTATE = 0.0F;

  /* SystemInitialize for Atomic SubSystem: '<S164>/resetting fault filter' */
  ff_resetting_Init(rty_fault_flg, &rtb_ff_count_g,
                    &localDW->resettingfaultfilter);

  /* End of SystemInitialize for SubSystem: '<S164>/resetting fault filter' */

  /* SystemInitialize for Chart: '<S164>/valid_signal_selection' */
  Pow_valid_signal_selection_Init(rty_valid_signal);
}

/*
 * System reset for atomic system:
 *    '<S161>/signal validity checking'
 *    '<S168>/signal validity checking'
 *    '<S175>/signal validity checking'
 *    '<S182>/signal validity checking'
 *    '<S189>/signal validity checking'
 *    '<S203>/signal validity checking'
 *    '<S216>/signal validity checking'
 *    '<S229>/signal validity checking'
 *    '<S236>/signal validity checking'
 *    '<S251>/signal validity checking'
 *    ...
 */
void sig_valid_check_Reset(boolean_T *rty_fault_flg, real32_T *rty_valid_signal,
  rtDW_sig_valid_check *localDW)
{
  uint8_T rtb_ff_count_gs;

  /* InitializeConditions for UnitDelay: '<S164>/UnitDelay' */
  localDW->UnitDelay_DSTATE = 0.0F;

  /* SystemReset for Atomic SubSystem: '<S164>/resetting fault filter' */
  ff_resetting_Reset(rty_fault_flg, &rtb_ff_count_gs,
                     &localDW->resettingfaultfilter);

  /* End of SystemReset for SubSystem: '<S164>/resetting fault filter' */

  /* SystemReset for Chart: '<S164>/valid_signal_selection' */
  Po_valid_signal_selection_Reset(rty_valid_signal);
}

/*
 * Output and update for atomic system:
 *    '<S161>/signal validity checking'
 *    '<S168>/signal validity checking'
 *    '<S175>/signal validity checking'
 *    '<S182>/signal validity checking'
 *    '<S189>/signal validity checking'
 *    '<S203>/signal validity checking'
 *    '<S216>/signal validity checking'
 *    '<S229>/signal validity checking'
 *    '<S236>/signal validity checking'
 *    '<S251>/signal validity checking'
 *    ...
 */
void sig_valid_check(real32_T rtu_u, boolean_T rtu_u_valid_flg, boolean_T
                     rtu_u_rangeFault_flg, real32_T rtu_def_value, uint8_T
                     rtu_sat, uint8_T rtu_inc, uint8_T rtu_dec, boolean_T
                     *rty_fault_flg, real32_T *rty_valid_signal,
                     rtDW_sig_valid_check *localDW)
{
  boolean_T rtb_ifault_flg_d;
  uint8_T rtb_ff_count_g;

  /* Logic: '<S164>/Logical Operator' incorporates:
   *  Logic: '<S164>/Logical Operator1'
   */
  rtb_ifault_flg_d = ((!rtu_u_valid_flg) || rtu_u_rangeFault_flg);

  /* Outputs for Atomic SubSystem: '<S164>/resetting fault filter' */
  ff_resetting(rtb_ifault_flg_d, rtu_sat, rtu_inc, rtu_dec, rty_fault_flg,
               &rtb_ff_count_g, &localDW->resettingfaultfilter);

  /* End of Outputs for SubSystem: '<S164>/resetting fault filter' */

  /* Chart: '<S164>/valid_signal_selection' incorporates:
   *  UnitDelay: '<S164>/UnitDelay'
   */
  PowerCtr_valid_signal_selection(rtu_def_value, rtu_u, rtb_ifault_flg_d,
    *rty_fault_flg, localDW->UnitDelay_DSTATE, rty_valid_signal);

  /* Update for UnitDelay: '<S164>/UnitDelay' */
  localDW->UnitDelay_DSTATE = *rty_valid_signal;
}

/*
 * System initialize for enable system:
 *    '<S160>/CANDiagnosis'
 *    '<S202>/CANDiagnosis'
 *    '<S250>/CANDiagnosis'
 *    '<S403>/CANDiagnosis'
 *    '<S445>/CANDiagnosis'
 *    '<S495>/CANDiagnosis'
 *    '<S558>/CANDiagnosis'
 *    '<S567>/CANDiagnosis'
 *    '<S601>/CANDiagnosis'
 *    '<S769>/CANDiagnosis'
 *    ...
 */
void PowerCtrolPro_CANDiagnosis_Init(rtB_CANDiagnosis_PowerCtrolProj *localB,
  rtDW_CANDiagnosis_PowerCtrolPro *localDW)
{
  real32_T rtb_valid_signal_ml2;

  /* SystemInitialize for Atomic SubSystem: '<S161>/signal validity checking' */
  sig_valid_check_Init(&localB->fault_flg, &rtb_valid_signal_ml2,
                       &localDW->signalvaliditychecking);

  /* End of SystemInitialize for SubSystem: '<S161>/signal validity checking' */
}

/*
 * System reset for enable system:
 *    '<S160>/CANDiagnosis'
 *    '<S202>/CANDiagnosis'
 *    '<S250>/CANDiagnosis'
 *    '<S403>/CANDiagnosis'
 *    '<S445>/CANDiagnosis'
 *    '<S495>/CANDiagnosis'
 *    '<S558>/CANDiagnosis'
 *    '<S567>/CANDiagnosis'
 *    '<S601>/CANDiagnosis'
 *    '<S769>/CANDiagnosis'
 *    ...
 */
void PowerCtrolPr_CANDiagnosis_Reset(real32_T *rtb_valid_signal_mzd,
  rtB_CANDiagnosis_PowerCtrolProj *localB, rtDW_CANDiagnosis_PowerCtrolPro
  *localDW)
{
  /* SystemReset for Atomic SubSystem: '<S161>/signal validity checking' */
  sig_valid_check_Reset(&localB->fault_flg, rtb_valid_signal_mzd,
                        &localDW->signalvaliditychecking);

  /* End of SystemReset for SubSystem: '<S161>/signal validity checking' */
}

/*
 * Disable for enable system:
 *    '<S160>/CANDiagnosis'
 *    '<S202>/CANDiagnosis'
 *    '<S250>/CANDiagnosis'
 *    '<S403>/CANDiagnosis'
 *    '<S445>/CANDiagnosis'
 *    '<S495>/CANDiagnosis'
 *    '<S558>/CANDiagnosis'
 *    '<S567>/CANDiagnosis'
 *    '<S601>/CANDiagnosis'
 *    '<S769>/CANDiagnosis'
 *    ...
 */
void PowerCtrol_CANDiagnosis_Disable(rtDW_CANDiagnosis_PowerCtrolPro *localDW)
{
  localDW->CANDiagnosis_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S160>/CANDiagnosis'
 *    '<S202>/CANDiagnosis'
 *    '<S250>/CANDiagnosis'
 *    '<S403>/CANDiagnosis'
 *    '<S445>/CANDiagnosis'
 *    '<S495>/CANDiagnosis'
 *    '<S558>/CANDiagnosis'
 *    '<S567>/CANDiagnosis'
 *    '<S601>/CANDiagnosis'
 *    '<S769>/CANDiagnosis'
 *    ...
 */
void PowerCtrolProject1_CANDiagnosis(boolean_T rtu_Enable, boolean_T
  rtu_CANAvail_flg, uint8_T rtu_NINP_lim, uint8_T rtu_NINP_inc, uint8_T
  rtu_NINP_dec, rtB_CANDiagnosis_PowerCtrolProj *localB,
  rtDW_CANDiagnosis_PowerCtrolPro *localDW)
{
  real32_T rtb_valid_signal_ms;

  /* Outputs for Enabled SubSystem: '<S160>/CANDiagnosis' incorporates:
   *  EnablePort: '<S161>/Enable'
   */
  if (rtu_Enable) {
    if (!localDW->CANDiagnosis_MODE) {
      PowerCtrolPr_CANDiagnosis_Reset(&rtb_valid_signal_ms, localB, localDW);
      localDW->CANDiagnosis_MODE = true;
    }

    /* Outputs for Atomic SubSystem: '<S161>/signal validity checking' */
    /* DataTypeConversion: '<S161>/Data Type Conversion' incorporates:
     *  Constant: '<S161>/False'
     *  Constant: '<S161>/sat2'
     *  DataTypeConversion: '<S161>/Data Type Conversion1'
     */
    sig_valid_check((real32_T)rtu_CANAvail_flg, rtu_CANAvail_flg, false, 0.0F,
                    rtu_NINP_lim, rtu_NINP_inc, rtu_NINP_dec, &localB->fault_flg,
                    &rtb_valid_signal_ms, &localDW->signalvaliditychecking);

    /* End of Outputs for SubSystem: '<S161>/signal validity checking' */
  } else {
    if (localDW->CANDiagnosis_MODE) {
      PowerCtrol_CANDiagnosis_Disable(localDW);
    }
  }

  /* End of Outputs for SubSystem: '<S160>/CANDiagnosis' */
}

/*
 * System initialize for atomic system:
 *    '<S160>/Initialization'
 *    '<S202>/Initialization'
 *    '<S250>/Initialization'
 *    '<S403>/Initialization'
 *    '<S445>/Initialization'
 *    '<S495>/Initialization'
 *    '<S558>/Initialization'
 *    '<S567>/Initialization'
 *    '<S601>/Initialization'
 *    '<S769>/Initialization'
 *    ...
 */
void PowerCtrolP_Initialization_Init(boolean_T *rty_CANInt)
{
  *rty_CANInt = false;
}

/*
 * Output and update for atomic system:
 *    '<S160>/Initialization'
 *    '<S202>/Initialization'
 *    '<S250>/Initialization'
 *    '<S403>/Initialization'
 *    '<S445>/Initialization'
 *    '<S495>/Initialization'
 *    '<S558>/Initialization'
 *    '<S567>/Initialization'
 *    '<S601>/Initialization'
 *    '<S769>/Initialization'
 *    ...
 */
void PowerCtrolProjec_Initialization(boolean_T rtu_CANAct, boolean_T *rty_CANInt)
{
  /* Chart: '<S160>/Initialization' */
  if ((!*rty_CANInt) && rtu_CANAct) {
    *rty_CANInt = true;
  }

  /* End of Chart: '<S160>/Initialization' */
}

/*
 * System initialize for atomic system:
 *    '<S212>/valid_signal_selection'
 *    '<S225>/valid_signal_selection'
 *    '<S260>/valid_signal_selection'
 *    '<S273>/valid_signal_selection'
 *    '<S322>/valid_signal_selection'
 *    '<S328>/valid_signal_selection'
 *    '<S334>/valid_signal_selection'
 *    '<S340>/valid_signal_selection'
 *    '<S346>/valid_signal_selection'
 *    '<S352>/valid_signal_selection'
 *    ...
 */
void P_valid_signal_selection_a_Init(real32_T *rty_valid_signal)
{
  *rty_valid_signal = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S212>/valid_signal_selection'
 *    '<S225>/valid_signal_selection'
 *    '<S260>/valid_signal_selection'
 *    '<S273>/valid_signal_selection'
 *    '<S322>/valid_signal_selection'
 *    '<S328>/valid_signal_selection'
 *    '<S334>/valid_signal_selection'
 *    '<S340>/valid_signal_selection'
 *    '<S346>/valid_signal_selection'
 *    '<S352>/valid_signal_selection'
 *    ...
 */
void PowerC_valid_signal_selection_n(real32_T rtu_def_value, real32_T
  rtu_new_signal, boolean_T rtu_ifault_flg, boolean_T rtu_fault_flg, real32_T
  rtu_old_signal, real32_T *rty_valid_signal)
{
  /* Chart: '<S212>/valid_signal_selection' */
  if (rtu_fault_flg) {
    *rty_valid_signal = rtu_def_value;
  } else if (rtu_ifault_flg) {
    *rty_valid_signal = rtu_old_signal;
  } else {
    *rty_valid_signal = rtu_new_signal;
  }

  /* End of Chart: '<S212>/valid_signal_selection' */
}

/*
 * System initialize for atomic system:
 *    '<S210>/signal validity checking'
 *    '<S223>/signal validity checking'
 *    '<S258>/signal validity checking'
 *    '<S271>/signal validity checking'
 *    '<S453>/signal validity checking'
 *    '<S459>/signal validity checking'
 *    '<S503>/signal validity checking'
 *    '<S509>/signal validity checking'
 *    '<S609>/signal validity checking'
 *    '<S615>/signal validity checking'
 *    ...
 */
void PowerCtrol_sig_valid_check_Init(boolean_T *rty_fault_flg, real32_T
  *rty_valid_signal, rtDW_sig_valid_check_p *localDW)
{
  uint8_T rtb_ff_count;

  /* SystemInitialize for Atomic SubSystem: '<S212>/resetting fault filter' */
  ff_resetting_Init(rty_fault_flg, &rtb_ff_count, &localDW->resettingfaultfilter);

  /* End of SystemInitialize for SubSystem: '<S212>/resetting fault filter' */

  /* SystemInitialize for Chart: '<S212>/valid_signal_selection' */
  P_valid_signal_selection_a_Init(rty_valid_signal);
}

/*
 * Output and update for atomic system:
 *    '<S210>/signal validity checking'
 *    '<S223>/signal validity checking'
 *    '<S258>/signal validity checking'
 *    '<S271>/signal validity checking'
 *    '<S453>/signal validity checking'
 *    '<S459>/signal validity checking'
 *    '<S503>/signal validity checking'
 *    '<S509>/signal validity checking'
 *    '<S609>/signal validity checking'
 *    '<S615>/signal validity checking'
 *    ...
 */
void PowerCtrolProje_sig_valid_check(real32_T rtu_u, boolean_T rtu_u_valid_flg,
  boolean_T rtu_u_rangeFault_flg, real32_T rtu_def_value, uint8_T rtu_sat,
  uint8_T rtu_inc, uint8_T rtu_dec, boolean_T *rty_fault_flg, real32_T
  *rty_valid_signal, rtDW_sig_valid_check_p *localDW)
{
  boolean_T rtb_ifault_flg;
  uint8_T rtb_ff_count;

  /* Logic: '<S212>/Logical Operator' incorporates:
   *  Logic: '<S212>/Logical Operator1'
   */
  rtb_ifault_flg = ((!rtu_u_valid_flg) || rtu_u_rangeFault_flg);

  /* Outputs for Atomic SubSystem: '<S212>/resetting fault filter' */
  ff_resetting(rtb_ifault_flg, rtu_sat, rtu_inc, rtu_dec, rty_fault_flg,
               &rtb_ff_count, &localDW->resettingfaultfilter);

  /* End of Outputs for SubSystem: '<S212>/resetting fault filter' */

  /* Chart: '<S212>/valid_signal_selection' incorporates:
   *  UnitDelay: '<S212>/UnitDelay'
   */
  PowerC_valid_signal_selection_n(rtu_def_value, rtu_u, rtb_ifault_flg,
    *rty_fault_flg, localDW->UnitDelay_DSTATE, rty_valid_signal);

  /* Update for UnitDelay: '<S212>/UnitDelay' */
  localDW->UnitDelay_DSTATE = *rty_valid_signal;
}

/*
 * System initialize for atomic system:
 *    '<S313>/signal validity checking'
 *    '<S891>/signal validity checking'
 *    '<S916>/signal validity checking'
 *    '<S923>/signal validity checking'
 *    '<S1279>/signal validity checking'
 *    '<S1286>/signal validity checking'
 *    '<S1293>/signal validity checking'
 *    '<S1300>/signal validity checking'
 *    '<S1351>/signal validity checking'
 *    '<S1358>/signal validity checking'
 *    ...
 */
void PowerCtr_sig_valid_check_l_Init(boolean_T *rty_fault_flg, real32_T
  *rty_valid_signal, rtDW_sig_valid_check_k *localDW)
{
  uint8_T rtb_ff_count;

  /* InitializeConditions for UnitDelay: '<S316>/UnitDelay' */
  localDW->UnitDelay_DSTATE = 0.0F;

  /* SystemInitialize for Atomic SubSystem: '<S316>/resetting fault filter' */
  ff_resetting_Init(rty_fault_flg, &rtb_ff_count, &localDW->resettingfaultfilter);

  /* End of SystemInitialize for SubSystem: '<S316>/resetting fault filter' */

  /* SystemInitialize for Chart: '<S316>/valid_signal_selection' */
  Pow_valid_signal_selection_Init(rty_valid_signal);
}

/*
 * System reset for atomic system:
 *    '<S313>/signal validity checking'
 *    '<S891>/signal validity checking'
 *    '<S916>/signal validity checking'
 *    '<S923>/signal validity checking'
 *    '<S1279>/signal validity checking'
 *    '<S1286>/signal validity checking'
 *    '<S1293>/signal validity checking'
 *    '<S1300>/signal validity checking'
 *    '<S1351>/signal validity checking'
 *    '<S1358>/signal validity checking'
 *    ...
 */
void PowerCt_sig_valid_check_k_Reset(boolean_T *rty_fault_flg, real32_T
  *rty_valid_signal, rtDW_sig_valid_check_k *localDW)
{
  uint8_T rtb_ff_count;

  /* InitializeConditions for UnitDelay: '<S316>/UnitDelay' */
  localDW->UnitDelay_DSTATE = 0.0F;

  /* SystemReset for Atomic SubSystem: '<S316>/resetting fault filter' */
  ff_resetting_Reset(rty_fault_flg, &rtb_ff_count,
                     &localDW->resettingfaultfilter);

  /* End of SystemReset for SubSystem: '<S316>/resetting fault filter' */

  /* SystemReset for Chart: '<S316>/valid_signal_selection' */
  Po_valid_signal_selection_Reset(rty_valid_signal);
}

/*
 * Output and update for atomic system:
 *    '<S313>/signal validity checking'
 *    '<S891>/signal validity checking'
 *    '<S916>/signal validity checking'
 *    '<S923>/signal validity checking'
 *    '<S1279>/signal validity checking'
 *    '<S1286>/signal validity checking'
 *    '<S1293>/signal validity checking'
 *    '<S1300>/signal validity checking'
 *    '<S1351>/signal validity checking'
 *    '<S1358>/signal validity checking'
 *    ...
 */
void PowerCtrolPro_sig_valid_check_k(real32_T rtu_u, real32_T rtu_def_value,
  uint8_T rtu_sat, uint8_T rtu_inc, uint8_T rtu_dec, boolean_T *rty_fault_flg,
  real32_T *rty_valid_signal, const rtC_sig_valid_check_ge *localC,
  rtDW_sig_valid_check_k *localDW)
{
  uint8_T rtb_ff_count;

  /* Outputs for Atomic SubSystem: '<S316>/resetting fault filter' */
  ff_resetting(localC->ifault_flg, rtu_sat, rtu_inc, rtu_dec, rty_fault_flg,
               &rtb_ff_count, &localDW->resettingfaultfilter);

  /* End of Outputs for SubSystem: '<S316>/resetting fault filter' */

  /* Chart: '<S316>/valid_signal_selection' incorporates:
   *  UnitDelay: '<S316>/UnitDelay'
   */
  PowerCtr_valid_signal_selection(rtu_def_value, rtu_u, localC->ifault_flg,
    *rty_fault_flg, localDW->UnitDelay_DSTATE, rty_valid_signal);

  /* Update for UnitDelay: '<S316>/UnitDelay' */
  localDW->UnitDelay_DSTATE = *rty_valid_signal;
}

/*
 * System initialize for atomic system:
 *    '<S312>/Initialization'
 *    '<S890>/Initialization'
 *    '<S1414>/Initialization'
 */
void PowerCtro_Initialization_h_Init(boolean_T *rty_CANInt)
{
  *rty_CANInt = false;
}

/*
 * Output and update for atomic system:
 *    '<S312>/Initialization'
 *    '<S890>/Initialization'
 *    '<S1414>/Initialization'
 */
void PowerCtrolProj_Initialization_f(boolean_T rtu_CANAct, boolean_T *rty_CANInt)
{
  /* Chart: '<S312>/Initialization' */
  if ((!*rty_CANInt) && rtu_CANAct) {
    *rty_CANInt = true;
  }

  /* End of Chart: '<S312>/Initialization' */
}

/*
 * System initialize for atomic system:
 *    '<S320>/signal validity checking'
 *    '<S332>/signal validity checking'
 *    '<S338>/signal validity checking'
 *    '<S344>/signal validity checking'
 *    '<S350>/signal validity checking'
 *    '<S356>/signal validity checking'
 *    '<S362>/signal validity checking'
 *    '<S368>/signal validity checking'
 *    '<S374>/signal validity checking'
 *    '<S380>/signal validity checking'
 *    ...
 */
void PowerCtr_sig_valid_check_n_Init(boolean_T *rty_fault_flg, real32_T
  *rty_valid_signal, rtDW_sig_valid_check_a *localDW)
{
  uint8_T rtb_ff_count;

  /* SystemInitialize for Atomic SubSystem: '<S322>/resetting fault filter' */
  ff_resetting_Init(rty_fault_flg, &rtb_ff_count, &localDW->resettingfaultfilter);

  /* End of SystemInitialize for SubSystem: '<S322>/resetting fault filter' */

  /* SystemInitialize for Chart: '<S322>/valid_signal_selection' */
  P_valid_signal_selection_a_Init(rty_valid_signal);
}

/*
 * Output and update for atomic system:
 *    '<S320>/signal validity checking'
 *    '<S332>/signal validity checking'
 *    '<S338>/signal validity checking'
 *    '<S344>/signal validity checking'
 *    '<S350>/signal validity checking'
 *    '<S356>/signal validity checking'
 *    '<S362>/signal validity checking'
 *    '<S368>/signal validity checking'
 *    '<S374>/signal validity checking'
 *    '<S380>/signal validity checking'
 *    ...
 */
void PowerCtrolPro_sig_valid_check_j(real32_T rtu_u, real32_T rtu_def_value,
  uint8_T rtu_sat, uint8_T rtu_inc, uint8_T rtu_dec, boolean_T *rty_fault_flg,
  real32_T *rty_valid_signal, const rtC_sig_valid_check_a *localC,
  rtDW_sig_valid_check_a *localDW)
{
  uint8_T rtb_ff_count;

  /* Outputs for Atomic SubSystem: '<S322>/resetting fault filter' */
  ff_resetting(localC->ifault_flg, rtu_sat, rtu_inc, rtu_dec, rty_fault_flg,
               &rtb_ff_count, &localDW->resettingfaultfilter);

  /* End of Outputs for SubSystem: '<S322>/resetting fault filter' */

  /* Chart: '<S322>/valid_signal_selection' incorporates:
   *  UnitDelay: '<S322>/UnitDelay'
   */
  PowerC_valid_signal_selection_n(rtu_def_value, rtu_u, localC->ifault_flg,
    *rty_fault_flg, localDW->UnitDelay_DSTATE, rty_valid_signal);

  /* Update for UnitDelay: '<S322>/UnitDelay' */
  localDW->UnitDelay_DSTATE = *rty_valid_signal;
}

/*
 * System initialize for atomic system:
 *    '<S326>/signal validity checking'
 *    '<S386>/signal validity checking'
 *    '<S392>/signal validity checking'
 *    '<S904>/signal validity checking'
 *    '<S1273>/signal validity checking'
 *    '<S1321>/signal validity checking'
 *    '<S1327>/signal validity checking'
 *    '<S1333>/signal validity checking'
 *    '<S1345>/signal validity checking'
 *    '<S1365>/signal validity checking'
 *    ...
 */
void PowerCtr_sig_valid_check_k_Init(boolean_T *rty_fault_flg, real32_T
  *rty_valid_signal, rtDW_sig_valid_check_ku *localDW)
{
  uint8_T rtb_ff_count;

  /* SystemInitialize for Atomic SubSystem: '<S328>/resetting fault filter' */
  ff_resetting_Init(rty_fault_flg, &rtb_ff_count, &localDW->resettingfaultfilter);

  /* End of SystemInitialize for SubSystem: '<S328>/resetting fault filter' */

  /* SystemInitialize for Chart: '<S328>/valid_signal_selection' */
  P_valid_signal_selection_a_Init(rty_valid_signal);
}

/*
 * Output and update for atomic system:
 *    '<S326>/signal validity checking'
 *    '<S386>/signal validity checking'
 *    '<S392>/signal validity checking'
 *    '<S904>/signal validity checking'
 *    '<S1273>/signal validity checking'
 *    '<S1321>/signal validity checking'
 *    '<S1327>/signal validity checking'
 *    '<S1333>/signal validity checking'
 *    '<S1345>/signal validity checking'
 *    '<S1365>/signal validity checking'
 *    ...
 */
void PowerCtrolPro_sig_valid_check_f(real32_T rtu_u, uint8_T rtu_sat, uint8_T
  rtu_inc, uint8_T rtu_dec, boolean_T *rty_fault_flg, real32_T *rty_valid_signal,
  const rtC_sig_valid_check_gc *localC, rtDW_sig_valid_check_ku *localDW)
{
  uint8_T rtb_ff_count;

  /* Outputs for Atomic SubSystem: '<S328>/resetting fault filter' */
  ff_resetting(localC->ifault_flg, rtu_sat, rtu_inc, rtu_dec, rty_fault_flg,
               &rtb_ff_count, &localDW->resettingfaultfilter);

  /* End of Outputs for SubSystem: '<S328>/resetting fault filter' */

  /* Chart: '<S328>/valid_signal_selection' incorporates:
   *  UnitDelay: '<S328>/UnitDelay'
   */
  PowerC_valid_signal_selection_n(localC->DataTypeConversion, rtu_u,
    localC->ifault_flg, *rty_fault_flg, localDW->UnitDelay_DSTATE,
    rty_valid_signal);

  /* Update for UnitDelay: '<S328>/UnitDelay' */
  localDW->UnitDelay_DSTATE = *rty_valid_signal;
}

/*
 * System initialize for atomic system:
 *    '<S797>/signal validity checking'
 *    '<S815>/signal validity checking'
 *    '<S1040>/signal validity checking'
 *    '<S1046>/signal validity checking'
 *    '<S1052>/signal validity checking'
 *    '<S1058>/signal validity checking'
 *    '<S1064>/signal validity checking'
 *    '<S1070>/signal validity checking'
 *    '<S1076>/signal validity checking'
 *    '<S1082>/signal validity checking'
 *    ...
 */
void PowerCtr_sig_valid_check_o_Init(boolean_T *rty_fault_flg, real32_T
  *rty_valid_signal, rtDW_sig_valid_check_g *localDW)
{
  uint8_T rtb_ff_count;

  /* SystemInitialize for Atomic SubSystem: '<S799>/resetting fault filter' */
  ff_resetting_Init(rty_fault_flg, &rtb_ff_count, &localDW->resettingfaultfilter);

  /* End of SystemInitialize for SubSystem: '<S799>/resetting fault filter' */

  /* SystemInitialize for Chart: '<S799>/valid_signal_selection' */
  P_valid_signal_selection_a_Init(rty_valid_signal);
}

/*
 * Output and update for atomic system:
 *    '<S797>/signal validity checking'
 *    '<S815>/signal validity checking'
 *    '<S1040>/signal validity checking'
 *    '<S1046>/signal validity checking'
 *    '<S1052>/signal validity checking'
 *    '<S1058>/signal validity checking'
 *    '<S1064>/signal validity checking'
 *    '<S1070>/signal validity checking'
 *    '<S1076>/signal validity checking'
 *    '<S1082>/signal validity checking'
 *    ...
 */
void PowerCtrolPro_sig_valid_check_m(real32_T rtu_u, boolean_T rtu_u_valid_flg,
  boolean_T rtu_u_rangeFault_flg, uint8_T rtu_sat, uint8_T rtu_inc, uint8_T
  rtu_dec, boolean_T *rty_fault_flg, real32_T *rty_valid_signal, const
  rtC_sig_valid_check_d *localC, rtDW_sig_valid_check_g *localDW)
{
  boolean_T rtb_ifault_flg;
  uint8_T rtb_ff_count;

  /* Logic: '<S799>/Logical Operator' incorporates:
   *  Logic: '<S799>/Logical Operator1'
   */
  rtb_ifault_flg = ((!rtu_u_valid_flg) || rtu_u_rangeFault_flg);

  /* Outputs for Atomic SubSystem: '<S799>/resetting fault filter' */
  ff_resetting(rtb_ifault_flg, rtu_sat, rtu_inc, rtu_dec, rty_fault_flg,
               &rtb_ff_count, &localDW->resettingfaultfilter);

  /* End of Outputs for SubSystem: '<S799>/resetting fault filter' */

  /* Chart: '<S799>/valid_signal_selection' incorporates:
   *  UnitDelay: '<S799>/UnitDelay'
   */
  PowerC_valid_signal_selection_n(localC->DataTypeConversion, rtu_u,
    rtb_ifault_flg, *rty_fault_flg, localDW->UnitDelay_DSTATE, rty_valid_signal);

  /* Update for UnitDelay: '<S799>/UnitDelay' */
  localDW->UnitDelay_DSTATE = *rty_valid_signal;
}

/*
 * System initialize for enable system:
 *    '<S890>/CANDiagnosis'
 *    '<S1414>/CANDiagnosis'
 */
void PowerCtrolP_CANDiagnosis_b_Init(rtB_CANDiagnosis_PowerCtrolPr_c *localB,
  rtDW_CANDiagnosis_PowerCtrolP_g *localDW)
{
  real32_T rtb_valid_signal_gw;

  /* SystemInitialize for Atomic SubSystem: '<S891>/signal validity checking' */
  PowerCtr_sig_valid_check_l_Init(&localB->fault_flg, &rtb_valid_signal_gw,
    &localDW->signalvaliditychecking);

  /* End of SystemInitialize for SubSystem: '<S891>/signal validity checking' */
}

/*
 * System reset for enable system:
 *    '<S890>/CANDiagnosis'
 *    '<S1414>/CANDiagnosis'
 */
void PowerCtrol_CANDiagnosis_k_Reset(real32_T *rtb_valid_signal_mb,
  rtB_CANDiagnosis_PowerCtrolPr_c *localB, rtDW_CANDiagnosis_PowerCtrolP_g
  *localDW)
{
  /* SystemReset for Atomic SubSystem: '<S891>/signal validity checking' */
  PowerCt_sig_valid_check_k_Reset(&localB->fault_flg, rtb_valid_signal_mb,
    &localDW->signalvaliditychecking);

  /* End of SystemReset for SubSystem: '<S891>/signal validity checking' */
}

/*
 * Disable for enable system:
 *    '<S890>/CANDiagnosis'
 *    '<S1414>/CANDiagnosis'
 */
void PowerCtr_CANDiagnosis_j_Disable(rtDW_CANDiagnosis_PowerCtrolP_g *localDW)
{
  localDW->CANDiagnosis_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S890>/CANDiagnosis'
 *    '<S1414>/CANDiagnosis'
 */
void PowerCtrolProjec_CANDiagnosis_j(boolean_T rtu_Enable, uint8_T rtu_NINP_lim,
  uint8_T rtu_NINP_inc, uint8_T rtu_NINP_dec, rtB_CANDiagnosis_PowerCtrolPr_c
  *localB, const rtC_CANDiagnosis_PowerCtrolPr_h *localC,
  rtDW_CANDiagnosis_PowerCtrolP_g *localDW)
{
  real32_T rtb_valid_signal_pw;

  /* Outputs for Enabled SubSystem: '<S890>/CANDiagnosis' incorporates:
   *  EnablePort: '<S891>/Enable'
   */
  if (rtu_Enable) {
    if (!localDW->CANDiagnosis_MODE) {
      PowerCtrol_CANDiagnosis_k_Reset(&rtb_valid_signal_pw, localB, localDW);
      localDW->CANDiagnosis_MODE = true;
    }

    /* Outputs for Atomic SubSystem: '<S891>/signal validity checking' */
    /* Constant: '<S891>/sat2' */
    PowerCtrolPro_sig_valid_check_k(localC->DataTypeConversion, 0.0F,
      rtu_NINP_lim, rtu_NINP_inc, rtu_NINP_dec, &localB->fault_flg,
      &rtb_valid_signal_pw, &localC->signalvaliditychecking,
      &localDW->signalvaliditychecking);

    /* End of Outputs for SubSystem: '<S891>/signal validity checking' */
  } else {
    if (localDW->CANDiagnosis_MODE) {
      PowerCtr_CANDiagnosis_j_Disable(localDW);
    }
  }

  /* End of Outputs for SubSystem: '<S890>/CANDiagnosis' */
}

/* Function for Chart: '<S65>/OBCInvertChrgChart' */
static void PowerCtrolProject1_S_NoConnChrg(const boolean_T *NISP_sigOut, const
  boolean_T *RelationalOperator, const uint8_T *NISP_SigOut_i, uint8_T
  *NISP_SigOut_k, uint8_T *NISP_SigOut_j, boolean_T *NISP_sigOut_k)
{
  boolean_T tmp;
  tmp = !*NISP_sigOut_k;
  if (((*NISP_SigOut_i != 0) && (*NISP_SigOut_j == 1) && (*NISP_SigOut_i != 8)) ||
      (tmp && (*NISP_SigOut_k == 0)) || ((*RelationalOperator) &&
       (PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum == 1))) {
    PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
      PowerCtrol_IN_NO_ACTIVE_CHILD_h;
    PowerCtrolProject1_S32K14_DWork.is_c3_PowerCtrolProject1_S32K14 =
      PowerCtrolProject1_S32K_IN_Init;
    PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 0U;
    PowerCtrolProject1_S32K144_B.VRCC_SetInverter_flg = false;
    PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = false;
    PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = false;
    PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = false;
    PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw = 100.0F;
    PowerCtrolProject1_S32K14_DWork.TimeCounter = 0.0F;
  } else {
    switch (PowerCtrolProject1_S32K14_DWork.is_NoConnChrg) {
     case PowerCtrolProje_IN_ConnCloseInp:
      /* Constant: '<S65>/Debug value1' */
      if (PowerCtrolProject1_S32K14_DWork.TimeCounter > 0.2F) {
        PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
          PowerCtrolProj_IN_ConnCloseOutp;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 19U;
        PowerCtrolProject1_S32K14_DWork.TimeCounter = 0.0F;
      } else {
        PowerCtrolProject1_S32K14_DWork.TimeCounter = (real32_T)
          (PowerCtrolProject1_S32K14_DWork.TimeCounter + 0.01);
        PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_SetInverter_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw = 100.0F;
      }
      break;

     case PowerCtrolProj_IN_ConnCloseInvt:
      if ((*NISP_sigOut) && (*NISP_SigOut_k != 0) &&
          (PowerCtrolProject1_S32K144_B.NISP_SigOut == 2) &&
          (!*RelationalOperator) && (*NISP_sigOut_k) && ((*NISP_sigOut) &&
           (*NISP_SigOut_k != 0) && (*NISP_SigOut_k != 1) && (*NISP_SigOut_i ==
            8))) {
        PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
          PowerCtrolProject1__IN_ConnInvt;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 23U;
      } else if (((!*NISP_sigOut) || (*NISP_SigOut_k == 0) ||
                  (*RelationalOperator) || tmp || (*NISP_SigOut_k == 1)) &&
                 (PowerCtrolProject1_S32K14_DWork.TimeCounter > 0.2F)) {
        PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
          PowerCtrolProj_IN_NoConnOpenInp;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 15U;
        PowerCtrolProject1_S32K14_DWork.TimeCounter = 0.0F;
      } else {
        PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_SetInverter_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw = 100.0F;
      }
      break;

     case PowerCtrolProj_IN_ConnCloseOutp:
      /* Constant: '<S65>/Debug value2' */
      if ((PowerCtrolProject1_S32K14_DWork.TimeCounter > 0.2F) &&
          (PowerCtrolProject1_S32K144_B.NISP_SigOut == 1)) {
        PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
          PowerCtrolProje_IN_ConnStrtInvt;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 21U;
      } else if ((!*NISP_sigOut) || (*NISP_SigOut_k == 0) ||
                 (*RelationalOperator) || tmp || (*NISP_SigOut_k == 1)) {
        PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
          PowerCtrolProj_IN_NoConnOpenInp;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 15U;
        PowerCtrolProject1_S32K14_DWork.TimeCounter = 0.0F;
      } else {
        PowerCtrolProject1_S32K14_DWork.TimeCounter = (real32_T)
          (PowerCtrolProject1_S32K14_DWork.TimeCounter + 0.1);
        PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw = 100.0F;
      }

      /* End of Constant: '<S65>/Debug value2' */
      break;

     case PowerCtrolProject1__IN_ConnInvt:
      if ((!*NISP_sigOut) || (*NISP_SigOut_k == 0) ||
          (PowerCtrolProject1_S32K144_B.NISP_SigOut == 3) || (*NISP_SigOut_k ==
           1) || (*RelationalOperator) || tmp || (*NISP_SigOut_i == 0)) {
        PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
          PowerCtrolProj_IN_ConnCloseInvt;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 25U;
      } else {
        PowerCtrolProject1_S32K144_B.VRCC_SetInverter_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw = 100.0F;
      }
      break;

     case PowerCtrolProje_IN_ConnStrtInvt:
      if ((PowerCtrolProject1_S32K144_B.NISP_SigOut == 2) && ((*NISP_sigOut) &&
           (*NISP_SigOut_k != 0) && (*NISP_SigOut_i != 0))) {
        PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
          PowerCtrolProject1__IN_ConnInvt;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 23U;
      } else if ((!*NISP_sigOut) || (*NISP_SigOut_k == 0) ||
                 (*RelationalOperator) || tmp || (*NISP_SigOut_k == 1)) {
        PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
          PowerCtrolProj_IN_NoConnOpenInp;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 15U;
        PowerCtrolProject1_S32K14_DWork.TimeCounter = 0.0F;
      } else {
        PowerCtrolProject1_S32K144_B.VRCC_SetInverter_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw = 100.0F;
      }
      break;

     case PowerCtrolPr_IN_NoConnCloseInvt:
      /* Constant: '<S65>/Debug value1' */
      if (((*NISP_sigOut) && (*NISP_SigOut_k != 0)) || (*RelationalOperator) ||
          tmp || (*NISP_SigOut_k == 1) ||
          (PowerCtrolProject1_S32K14_DWork.TimeCounter > 0.2F)) {
        PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
          PowerCtrolProj_IN_NoConnOpenInp;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 15U;
        PowerCtrolProject1_S32K14_DWork.TimeCounter = 0.0F;
      } else if ((PowerCtrolProject1_S32K144_B.NISP_SigOut == 2) &&
                 (!*RelationalOperator) && (*NISP_sigOut_k) && ((!*NISP_sigOut) ||
                  (*NISP_SigOut_k == 0) || (*NISP_SigOut_k == 1))) {
        PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
          PowerCtrolProject_IN_NoConnInvt;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 9U;
      } else {
        PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_SetInverter_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw = 100.0F;
      }
      break;

     case PowerCtrolPr_IN_NoConnCloseOutp:
      if (((*NISP_sigOut) && (*NISP_SigOut_k != 0)) || (*NISP_SigOut_k == 1) ||
          (*RelationalOperator) || tmp) {
        PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
          PowerCtrolProj_IN_NoConnOpenInp;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 15U;
        PowerCtrolProject1_S32K14_DWork.TimeCounter = 0.0F;
      } else if ((PowerCtrolProject1_S32K14_DWork.TimeCounter > 0.2F) &&
                 (PowerCtrolProject1_S32K144_B.NISP_SigOut == 1)) {
        PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
          PowerCtrolPro_IN_NoConnStrtInvt;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 7U;
      } else {
        PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw = 100.0F;
        PowerCtrolProject1_S32K14_DWork.TimeCounter = (real32_T)
          (PowerCtrolProject1_S32K14_DWork.TimeCounter + 0.1);
      }
      break;

     case PowerCtrolProject_IN_NoConnInit:
      if ((PowerCtrolProject1_S32K144_B.NISP_SigOut == 0) && (*NISP_SigOut_k ==
           0) && (*NISP_SigOut_i == 0)) {
        PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
          PowerCtrolPr_IN_NoConnCloseOutp;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 5U;
        PowerCtrolProject1_S32K14_DWork.TimeCounter = 0.0F;
      } else if ((*NISP_sigOut) && (*NISP_SigOut_k != 0) &&
                 (PowerCtrolProject1_S32K144_B.NISP_SigOut == 0) &&
                 (*NISP_SigOut_k == 2) && (*NISP_SigOut_j == 0) &&
                 (*NISP_SigOut_i == 8) && (*NISP_sigOut_k)) {
        PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
          PowerCtrolProje_IN_ConnCloseInp;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 17U;
        PowerCtrolProject1_S32K14_DWork.TimeCounter = 0.0F;
      } else {
        PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_SetInverter_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw = 100.0F;
      }
      break;

     case PowerCtrolProject_IN_NoConnInvt:
      if (((*NISP_sigOut) && (*NISP_SigOut_k != 0)) || (*NISP_SigOut_k == 1) ||
          (*RelationalOperator) || tmp ||
          (PowerCtrolProject1_S32K144_B.NISP_SigOut == 3)) {
        PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
          PowerCtrolPr_IN_NoConnCloseInvt;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 11U;
      } else {
        PowerCtrolProject1_S32K144_B.VRCC_SetInverter_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw = 100.0F;
      }
      break;

     case PowerCtrolProj_IN_NoConnOpenInp:
      /* Constant: '<S65>/Debug value3' */
      if (PowerCtrolProject1_S32K14_DWork.TimeCounter > 0.2F) {
        PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
          PowerCtrolProject_IN_NoConnInit;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 1U;
      } else {
        PowerCtrolProject1_S32K14_DWork.TimeCounter = (real32_T)
          (PowerCtrolProject1_S32K14_DWork.TimeCounter + 0.01);
        PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_SetInverter_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw = 100.0F;
      }

      /* End of Constant: '<S65>/Debug value3' */
      break;

     default:
      if (((*NISP_sigOut) && (*NISP_SigOut_k != 0)) || (*NISP_SigOut_k == 1) ||
          (PowerCtrolProject1_S32K144_B.NISP_SigOut == 3) ||
          (*RelationalOperator) || tmp) {
        PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
          PowerCtrolProj_IN_NoConnOpenInp;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 15U;
        PowerCtrolProject1_S32K14_DWork.TimeCounter = 0.0F;
      } else if ((PowerCtrolProject1_S32K144_B.NISP_SigOut == 2) &&
                 ((*NISP_SigOut_i != 2) && (*NISP_SigOut_i != 3) &&
                  (*NISP_SigOut_i != 5))) {
        PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
          PowerCtrolProject_IN_NoConnInvt;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 9U;
      } else {
        PowerCtrolProject1_S32K144_B.VRCC_SetInverter_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw = 100.0F;
      }
      break;
    }
  }
}

/* Function for Chart: '<S65>/OBCInvertChrgChart' */
static void PowerCtrolProject1_S32_ConnChrg(const boolean_T *NISP_sigOut, const
  uint8_T *NISP_SigOut_i, const uint8_T *NISP_SigOut_l, uint8_T *NISP_SigOut_k,
  uint8_T *NISP_SigOut_j, boolean_T *NISP_sigOut_k)
{
  boolean_T tmp;
  tmp = !*NISP_sigOut;
  if ((tmp || (*NISP_SigOut_k == 0) || (*NISP_SigOut_j != 1)) &&
      (PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum == 2)) {
    PowerCtrolProject1_S32K14_DWork.is_ACSuply = PowerCtrol_IN_NO_ACTIVE_CHILD_h;
    PowerCtrolProject1_S32K14_DWork.is_ConnChrg =
      PowerCtrol_IN_NO_ACTIVE_CHILD_h;
    PowerCtrolProject1_S32K14_DWork.is_c3_PowerCtrolProject1_S32K14 =
      PowerCtrolProject1_S32K_IN_Init;
    PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 0U;
    PowerCtrolProject1_S32K144_B.VRCC_SetInverter_flg = false;
    PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = false;
    PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = false;
    PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = false;
    PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw = 100.0F;
    PowerCtrolProject1_S32K14_DWork.TimeCounter = 0.0F;
  } else {
    switch (PowerCtrolProject1_S32K14_DWork.is_ConnChrg) {
     case PowerCtrolProject1_S_IN_ACSuply:
      if (tmp || (*NISP_SigOut_k == 0) ||
          (PowerCtrolProject1_S32K144_B.NISP_SigOut_e == 3) || (*NISP_SigOut_l ==
           0) || (*NISP_SigOut_k == 1)) {
        PowerCtrolProject1_S32K14_DWork.is_ACSuply =
          PowerCtrol_IN_NO_ACTIVE_CHILD_h;
        PowerCtrolProject1_S32K14_DWork.is_ConnChrg =
          PowerCtrolProject1__IN_OpenOutp;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 18U;
        PowerCtrolProject1_S32K14_DWork.TimeCounter = 0.0F;
      } else if (!*NISP_sigOut_k) {
        PowerCtrolProject1_S32K14_DWork.is_ACSuply =
          PowerCtrol_IN_NO_ACTIVE_CHILD_h;
        PowerCtrolProject1_S32K14_DWork.is_ConnChrg =
          PowerCtrolProject_IN_ConnChrg_g;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 8U;
      } else if (PowerCtrolProject1_S32K14_DWork.is_ACSuply ==
                 PowerCtrolProject1__IN_Inverter) {
        if (PowerCtrolProject1_S32K144_B.NISP_SigOut_e == 2) {
          PowerCtrolProject1_S32K14_DWork.is_ACSuply =
            PowerCtrolProject_IN_NoInverter;
          PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 24U;
        } else {
          PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = true;
          PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = true;
          PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = true;
          PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw =
            PowerCtrolProject1_S32K144_B.VRCC_RoundPower_kw;
        }
      } else if (PowerCtrolProject1_S32K144_B.NISP_SigOut_e != 2) {
        PowerCtrolProject1_S32K14_DWork.is_ACSuply =
          PowerCtrolProject1__IN_Inverter;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 22U;
      } else {
        PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw =
          PowerCtrolProject1_S32K144_B.VRCC_RoundPower_kw;
      }
      break;

     case PowerCtrolPr_IN_CloseInpAndOutp:
      /* Constant: '<S65>/Debug value1' */
      if (((PowerCtrolProject1_S32K144_B.NISP_SigOut_h == 1) ||
           (PowerCtrolProject1_S32K144_B.NISP_SigOut_h == 2) ||
           (PowerCtrolProject1_S32K144_B.NISP_SigOut_h == 3)) && (*NISP_SigOut_k
           == 2) && (PowerCtrolProject1_S32K14_DWork.TimeCounter > 0.2F)) {
        PowerCtrolProject1_S32K14_DWork.is_ConnChrg =
          PowerCtrolProject_IN_ConnChrg_g;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 8U;
      } else if (tmp || (*NISP_SigOut_k == 0) ||
                 (PowerCtrolProject1_S32K144_B.NISP_SigOut_e == 3) ||
                 (*NISP_SigOut_l == 0) || (*NISP_SigOut_k == 1)) {
        PowerCtrolProject1_S32K14_DWork.is_ConnChrg =
          PowerCtrolProject1_S_IN_OpenInp;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 20U;
        PowerCtrolProject1_S32K14_DWork.TimeCounter = 0.0F;
      } else {
        PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = true;
        PowerCtrolProject1_S32K14_DWork.TimeCounter = (real32_T)
          (PowerCtrolProject1_S32K14_DWork.TimeCounter + 0.1);
        PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw = 100.0F;
      }

      /* End of Constant: '<S65>/Debug value1' */
      break;

     case PowerCtrolProject_IN_ConnChrg_g:
      if (tmp || (*NISP_SigOut_k == 0) || (*NISP_SigOut_k == 1) ||
          (*NISP_SigOut_k == 0) || (PowerCtrolProject1_S32K144_B.NISP_SigOut_e ==
           3) || (PowerCtrolProject1_S32K144_B.NISP_SigOut_e == 2) ||
          (*NISP_SigOut_l == 0)) {
        PowerCtrolProject1_S32K14_DWork.is_ConnChrg =
          PowerCtrolProject1__IN_ConnInit;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 2U;
      } else if (*NISP_sigOut_k) {
        PowerCtrolProject1_S32K14_DWork.is_ConnChrg =
          PowerCtrolProject1_S_IN_ACSuply;
        PowerCtrolProject1_S32K14_DWork.is_ACSuply =
          PowerCtrolProject1__IN_Inverter;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 22U;
      } else {
        PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw =
          PowerCtrolProject1_S32K144_B.VISP_PowerReq_kw;
      }
      break;

     case PowerCtrolProject1__IN_ConnInit:
      if ((PowerCtrolProject1_S32K144_B.NISP_SigOut_e != 3) &&
          (PowerCtrolProject1_S32K144_B.NISP_SigOut_e != 2) && (*NISP_SigOut_l ==
           1) && (*NISP_SigOut_i != 0) && (*NISP_SigOut_i != 8)) {
        PowerCtrolProject1_S32K14_DWork.is_ConnChrg =
          PowerCtrolPr_IN_CloseInpAndOutp;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 4U;
        PowerCtrolProject1_S32K14_DWork.TimeCounter = 0.0F;
      } else {
        PowerCtrolProject1_S32K144_B.VRCC_SetInverter_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw = 100.0F;
      }
      break;

     case PowerCtrolProject1_S_IN_OpenInp:
      /* Constant: '<S65>/Debug value3' */
      if (PowerCtrolProject1_S32K14_DWork.TimeCounter > 0.2F) {
        PowerCtrolProject1_S32K14_DWork.is_ConnChrg =
          PowerCtrolProject1__IN_ConnInit;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 2U;
      } else {
        PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = false;
        PowerCtrolProject1_S32K14_DWork.TimeCounter = (real32_T)
          (PowerCtrolProject1_S32K14_DWork.TimeCounter + 0.1);
        PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw = 100.0F;
      }

      /* End of Constant: '<S65>/Debug value3' */
      break;

     default:
      /* Constant: '<S65>/Debug value4' */
      if (PowerCtrolProject1_S32K14_DWork.TimeCounter > 0.2F) {
        PowerCtrolProject1_S32K14_DWork.is_ConnChrg =
          PowerCtrolProject1_S_IN_OpenInp;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 20U;
        PowerCtrolProject1_S32K14_DWork.TimeCounter = 0.0F;
      } else {
        PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = true;
        PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = false;
        PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw =
          PowerCtrolProject1_S32K144_B.VISP_PowerReq_kw;
        PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = false;
        PowerCtrolProject1_S32K14_DWork.TimeCounter = (real32_T)
          (PowerCtrolProject1_S32K14_DWork.TimeCounter + 0.1);
      }

      /* End of Constant: '<S65>/Debug value4' */
      break;
    }
  }
}

/* Model step function */
void PowerCtrolProject1_S32K144_step(void)
{
  uint8_T rtb_MinMax1;
  int32_T rtb_Switch;
  boolean_T rtb_Compare_k;
  boolean_T rtb_AND_a;
  boolean_T rtb_AND_bg;
  boolean_T rtb_AND_g;
  boolean_T rtb_AND_jj;
  boolean_T NISP_sigOut;
  boolean_T RelationalOperator;
  uint8_T NISP_SigOut_i;
  uint8_T NISP_SigOut_l;
  real32_T rtb_valid_signal_e5;
  real32_T rtb_valid_signal_ft;
  real32_T rtb_valid_signal_gem;
  real32_T rtb_valid_signal_em;
  real32_T rtb_valid_signal_co;
  real32_T rtb_valid_signal_nv;
  real32_T rtb_valid_signal_iw;
  real32_T rtb_valid_signal;
  real32_T rtb_valid_signal_pd;
  int32_T i;
  uint8_T NISP_SigOut_k;
  uint8_T NISP_SigOut_j;
  boolean_T NISP_sigOut_k;

  /* BusCreator: '<Root>/Bus Creator15' incorporates:
   *  Constant: '<Root>/Constant69'
   *  Constant: '<Root>/Constant72'
   *  Inport: '<Root>/In40'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX270h.Extended =
    PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic13;
  PowerCtrolProject1_S32K144_B.CAN1RX270h.Length = can_rx_msg.CAN1_DLC270h;
  PowerCtrolProject1_S32K144_B.CAN1RX270h.Remote = 0U;
  PowerCtrolProject1_S32K144_B.CAN1RX270h.Error = 0U;

  /* Switch: '<Root>/Switch13' */
  if (PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic13 != 0) {
    /* BusCreator: '<Root>/Bus Creator15' incorporates:
     *  Constant: '<Root>/Constant73'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX270h.ID = 0U;
  } else {
    /* BusCreator: '<Root>/Bus Creator15' incorporates:
     *  Inport: '<Root>/In41'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX270h.ID = can_rx_msg.CAN1_StdId270h;
  }

  /* End of Switch: '<Root>/Switch13' */

  /* BusCreator: '<Root>/Bus Creator15' incorporates:
   *  Constant: '<Root>/Constant70'
   *  Inport: '<Root>/In42'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX270h.Timestamp = 0.0;
  for (i = 0; i < 8; i++) {
    PowerCtrolProject1_S32K144_B.CAN1RX270h.Data[i] = can_rx_msg.CAN1_Data270h[i];
  }

  /* S-Function (scanunpack): '<S20>/CANRXUnPack_CDU_270h' */
  {
    /* S-Function (scanunpack): '<S20>/CANRXUnPack_CDU_270h' */
    if ((8 == PowerCtrolProject1_S32K144_B.CAN1RX270h.Length) &&
        (PowerCtrolProject1_S32K144_B.CAN1RX270h.ID != INVALID_CAN_ID) ) {
      if ((624 == PowerCtrolProject1_S32K144_B.CAN1RX270h.ID) && (0U ==
           PowerCtrolProject1_S32K144_B.CAN1RX270h.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 32
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX270h.Data[4]) & (uint8_T)
                    (0x3U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.DCDC_Status = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 40
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX270h.Data[5]) & (uint8_T)
                    (0x1U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.OBC_AC_request = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 37
           *  length                  = 3
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX270h.Data[4]) & (uint8_T)
                    (0xE0U)) >> 5);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.OBC_Charge_Status = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 24
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX270h.Data[3]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX270h.Data[2]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.1;
              PowerCtrolProject1_S32K144_B.OBC_HV_Output_Current = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 8
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX270h.Data[1]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX270h.Data[0]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.1;
              PowerCtrolProject1_S32K144_B.OBC_HV_Output_Voltage = result;
            }
          }

          /* --------------- START Unpacking signal 5 ------------------
           *  startBit                = 34
           *  length                  = 3
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX270h.Data[4]) & (uint8_T)
                    (0x1CU)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.OBC_Inverter_status = result;
            }
          }
        }
      }
    }
  }

  /* DataTypeConversion: '<S20>/Convert ofVHSPI_OBCInverterSts_enum' */
  if (PowerCtrolProject1_S32K144_B.OBC_Inverter_status < 256.0) {
    if (PowerCtrolProject1_S32K144_B.OBC_Inverter_status >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.OBC_Inverter_status;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S20>/Convert ofVHSPI_OBCInverterSts_enum' */

  /* Outputs for Atomic SubSystem: '<S930>/signal validity checking' */
  /* DataTypeConversion: '<S930>/Data Type Conversion' incorporates:
   *  Constant: '<S889>/KISP_VldChkOBCInverterStsDec_cnt'
   *  Constant: '<S889>/KISP_VldChkOBCInverterStsInc_cnt'
   *  Constant: '<S889>/KISP_VldChkOBCInverterStsLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_j((real32_T)NISP_SigOut_i,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_pkg, &rtb_valid_signal_e5,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_lq,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_lq);

  /* End of Outputs for SubSystem: '<S930>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S930>/override signal' */
  /* DataTypeConversion: '<S930>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S931>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut = (uint8_T)rtb_valid_signal_e5;

  /* End of Outputs for SubSystem: '<S930>/override signal' */

  /* BusCreator: '<Root>/Bus Creator5' incorporates:
   *  Constant: '<Root>/Constant15'
   *  Constant: '<Root>/Constant18'
   *  Inport: '<Root>/In10'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX204h.Extended =
    PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic3;
  PowerCtrolProject1_S32K144_B.CAN1RX204h.Length = can_rx_msg.CAN1_DLC204h;
  PowerCtrolProject1_S32K144_B.CAN1RX204h.Remote = 0U;
  PowerCtrolProject1_S32K144_B.CAN1RX204h.Error = 0U;

  /* Switch: '<Root>/Switch3' */
  if (PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic3 != 0) {
    /* BusCreator: '<Root>/Bus Creator5' incorporates:
     *  Constant: '<Root>/Constant19'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX204h.ID = 0U;
  } else {
    /* BusCreator: '<Root>/Bus Creator5' incorporates:
     *  Inport: '<Root>/In11'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX204h.ID = can_rx_msg.CAN1_StdId204h;
  }

  /* End of Switch: '<Root>/Switch3' */

  /* BusCreator: '<Root>/Bus Creator5' incorporates:
   *  Constant: '<Root>/Constant16'
   *  Inport: '<Root>/In12'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX204h.Timestamp = 0.0;
  for (i = 0; i < 8; i++) {
    PowerCtrolProject1_S32K144_B.CAN1RX204h.Data[i] = can_rx_msg.CAN1_Data204h[i];
  }

  /* S-Function (scanunpack): '<S9>/CANRXUnPack_BMS_204h' */
  {
    /* S-Function (scanunpack): '<S9>/CANRXUnPack_BMS_204h' */
    if ((8 == PowerCtrolProject1_S32K144_B.CAN1RX204h.Length) &&
        (PowerCtrolProject1_S32K144_B.CAN1RX204h.ID != INVALID_CAN_ID) ) {
      if ((516 == PowerCtrolProject1_S32K144_B.CAN1RX204h.ID) && (0U ==
           PowerCtrolProject1_S32K144_B.CAN1RX204h.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 12
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX204h.Data[1]) & (uint8_T)
                    (0x30U)) >> 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_AC_charge_S2_status = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 18
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX204h.Data[2]) & (uint8_T)
                    (0x4U)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Charge_connector_status = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 2
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX204h.Data[0]) & (uint8_T)
                    (0xCU)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Charge_relay_status = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 10
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX204h.Data[1]) & (uint8_T)
                    (0xCU)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Charge_status = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 14
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX204h.Data[1]) & (uint8_T)
                    (0xC0U)) >> 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_DC_charge_relay_status = result;
            }
          }

          /* --------------- START Unpacking signal 5 ------------------
           *  startBit                = 0
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX204h.Data[0]) & (uint8_T)
                    (0x3U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Discharge_relay_status = result;
            }
          }

          /* --------------- START Unpacking signal 6 ------------------
           *  startBit                = 19
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX204h.Data[2]) & (uint8_T)
                    (0x18U)) >> 3);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Eleclock_status = result;
            }
          }

          /* --------------- START Unpacking signal 7 ------------------
           *  startBit                = 23
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 8 ------------------
           *  startBit                = 16
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX204h.Data[2]) & (uint8_T)
                    (0x3U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Heating_charge_relay_status =
                result;
            }
          }

          /* --------------- START Unpacking signal 9 ------------------
           *  startBit                = 21
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 10 ------------------
           *  startBit                = 24
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX204h.Data[3]) & (uint8_T)
                    (0x1U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Total_positive_relay_status =
                result;
            }
          }

          /* --------------- START Unpacking signal 11 ------------------
           *  startBit                = 4
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX204h.Data[0]) & (uint8_T)
                    (0x30U)) >> 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Precharge_relay_status = result;
            }
          }

          /* --------------- START Unpacking signal 12 ------------------
           *  startBit                = 22
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX204h.Data[2]) & (uint8_T)
                    (0x40U)) >> 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_BMS_204h_o13 = result;
            }
          }

          /* --------------- START Unpacking signal 13 ------------------
           *  startBit                = 8
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX204h.Data[1]) & (uint8_T)
                    (0x3U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_System_status_n = result;
            }
          }

          /* --------------- START Unpacking signal 14 ------------------
           *  startBit                = 6
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX204h.Data[0]) & (uint8_T)
                    (0xC0U)) >> 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Total_positive_relay_stat_f =
                result;
            }
          }
        }
      }
    }
  }

  /* Outputs for Atomic SubSystem: '<S326>/signal validity checking' */
  /* DataTypeConversion: '<S326>/Data Type Conversion' incorporates:
   *  Constant: '<S300>/KISP_VldChkBMSChrgConnStsDec_cnt'
   *  Constant: '<S300>/KISP_VldChkBMSChrgConnStsInc_cnt'
   *  Constant: '<S300>/KISP_VldChkBMSChrgConnStsLim_cnt'
   *  DataTypeConversion: '<S9>/Convert ofVHSPI_BMSChrgConnSts_flg'
   */
  PowerCtrolPro_sig_valid_check_f((real32_T)
    (PowerCtrolProject1_S32K144_B.BMS_Charge_connector_status != 0.0), 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_dg2, &rtb_valid_signal_e5,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_fl,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_fl);

  /* End of Outputs for SubSystem: '<S326>/signal validity checking' */

  /* DataTypeConversion: '<S20>/Convert ofVHSPI_OBCChrgSts_enum' */
  if (PowerCtrolProject1_S32K144_B.OBC_Charge_Status < 256.0) {
    if (PowerCtrolProject1_S32K144_B.OBC_Charge_Status >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.OBC_Charge_Status;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S20>/Convert ofVHSPI_OBCChrgSts_enum' */

  /* Outputs for Atomic SubSystem: '<S910>/signal validity checking' */
  /* DataTypeConversion: '<S910>/Data Type Conversion' incorporates:
   *  Constant: '<S886>/KISP_VldChkOBCChrgStsDec_cnt'
   *  Constant: '<S886>/KISP_VldChkOBCChrgStsInc_cnt'
   *  Constant: '<S886>/KISP_VldChkOBCChrgStsLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_j((real32_T)NISP_SigOut_i,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_n, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_pe, &rtb_valid_signal_ft,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_kw,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_kw);

  /* End of Outputs for SubSystem: '<S910>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S910>/override signal' */
  /* DataTypeConversion: '<S910>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S911>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_h = (uint8_T)rtb_valid_signal_ft;

  /* End of Outputs for SubSystem: '<S910>/override signal' */

  /* BusCreator: '<Root>/Bus Creator12' incorporates:
   *  Constant: '<Root>/Constant42'
   *  Constant: '<Root>/Constant45'
   *  Inport: '<Root>/In31'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX230h.Extended =
    PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic10;
  PowerCtrolProject1_S32K144_B.CAN1RX230h.Length = can_rx_msg.CAN1_DLC230h;
  PowerCtrolProject1_S32K144_B.CAN1RX230h.Remote = 0U;
  PowerCtrolProject1_S32K144_B.CAN1RX230h.Error = 0U;

  /* Switch: '<Root>/Switch10' */
  if (PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic10 != 0) {
    /* BusCreator: '<Root>/Bus Creator12' incorporates:
     *  Constant: '<Root>/Constant46'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX230h.ID = 0U;
  } else {
    /* BusCreator: '<Root>/Bus Creator12' incorporates:
     *  Inport: '<Root>/In32'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX230h.ID = can_rx_msg.CAN1_StdId230h;
  }

  /* End of Switch: '<Root>/Switch10' */

  /* BusCreator: '<Root>/Bus Creator12' incorporates:
   *  Constant: '<Root>/Constant43'
   *  Inport: '<Root>/In33'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX230h.Timestamp = 0.0;
  for (i = 0; i < 8; i++) {
    PowerCtrolProject1_S32K144_B.CAN1RX230h.Data[i] = can_rx_msg.CAN1_Data230h[i];
  }

  /* S-Function (scanunpack): '<S16>/CANRXUnPack_BMS_230h' */
  {
    /* S-Function (scanunpack): '<S16>/CANRXUnPack_BMS_230h' */
    if ((8 == PowerCtrolProject1_S32K144_B.CAN1RX230h.Length) &&
        (PowerCtrolProject1_S32K144_B.CAN1RX230h.ID != INVALID_CAN_ID) ) {
      if ((560 == PowerCtrolProject1_S32K144_B.CAN1RX230h.ID) && (0U ==
           PowerCtrolProject1_S32K144_B.CAN1RX230h.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 32
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX230h.Data[4]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.1;
              PowerCtrolProject1_S32K144_B.BMS_CVEndCurrent = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 56
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX230h.Data[7]) & (uint8_T)
                    (0x1U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Charge_request = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 44
           *  length                  = 4
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX230h.Data[5]) & (uint8_T)
                    (0xF0U)) >> 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Chargeing_CC_cable_capacity =
                result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 48
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX230h.Data[6]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Charging_CP_PWM_Current = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 42
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX230h.Data[5]) & (uint8_T)
                    (0xCU)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Charging_signal_CC = result;
            }
          }

          /* --------------- START Unpacking signal 5 ------------------
           *  startBit                = 40
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX230h.Data[5]) & (uint8_T)
                    (0x3U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Charging_signal_CP = result;
            }
          }

          /* --------------- START Unpacking signal 6 ------------------
           *  startBit                = 57
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX230h.Data[7]) & (uint8_T)
                    (0x2U)) >> 1);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_DCDC_Work_En = result;
            }
          }

          /* --------------- START Unpacking signal 7 ------------------
           *  startBit                = 24
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX230h.Data[3]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX230h.Data[2]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.1;
              PowerCtrolProject1_S32K144_B.BMS_Max_charge_current = result;
            }
          }

          /* --------------- START Unpacking signal 8 ------------------
           *  startBit                = 8
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX230h.Data[1]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX230h.Data[0]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.1;
              PowerCtrolProject1_S32K144_B.BMS_Max_charge_voltage = result;
            }
          }
        }
      }
    }
  }

  /* DataTypeConversion: '<S16>/Convert ofVHSPI_BMSChrgCCCableCp_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Chargeing_CC_cable_capacity < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Chargeing_CC_cable_capacity >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Chargeing_CC_cable_capacity;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S16>/Convert ofVHSPI_BMSChrgCCCableCp_enum' */

  /* Outputs for Atomic SubSystem: '<S784>/signal validity checking' */
  /* DataTypeConversion: '<S784>/Data Type Conversion' incorporates:
   *  Constant: '<S142>/Bus Selector_SigVld4'
   *  Constant: '<S761>/KISP_VldChkBMSChrgCCCableCpDec_cnt'
   *  Constant: '<S761>/KISP_VldChkBMSChrgCCCableCpInc_cnt'
   *  Constant: '<S761>/KISP_VldChkBMSChrgCCCableCpLim_cnt'
   *  Constant: '<S784>/False'
   *  Logic: '<S784>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_nu, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_c3e, &rtb_valid_signal_em,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_gz);

  /* End of Outputs for SubSystem: '<S784>/signal validity checking' */

  /* DataTypeConversion: '<S16>/Convert ofVHSPI_BMSChrgSigCC_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Charging_signal_CC < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Charging_signal_CC >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Charging_signal_CC;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S16>/Convert ofVHSPI_BMSChrgSigCC_enum' */

  /* Outputs for Atomic SubSystem: '<S803>/signal validity checking' */
  /* DataTypeConversion: '<S803>/Data Type Conversion' incorporates:
   *  Constant: '<S142>/Bus Selector_SigVld6'
   *  Constant: '<S764>/KISP_VldChkBMSChrgSigCCDec_cnt'
   *  Constant: '<S764>/KISP_VldChkBMSChrgSigCCInc_cnt'
   *  Constant: '<S764>/KISP_VldChkBMSChrgSigCCLim_cnt'
   *  Constant: '<S803>/False'
   *  Logic: '<S803>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_l, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_nd, &rtb_valid_signal_co,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_cl);

  /* End of Outputs for SubSystem: '<S803>/signal validity checking' */

  /* DataTypeConversion: '<S16>/Convert ofVHSPI_BMSChrgSigCP_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Charging_signal_CP < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Charging_signal_CP >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Charging_signal_CP;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S16>/Convert ofVHSPI_BMSChrgSigCP_enum' */

  /* Outputs for Atomic SubSystem: '<S809>/signal validity checking' */
  /* DataTypeConversion: '<S809>/Data Type Conversion' incorporates:
   *  Constant: '<S142>/Bus Selector_SigVld7'
   *  Constant: '<S765>/KISP_VldChkBMSChrgSigCPDec_cnt'
   *  Constant: '<S765>/KISP_VldChkBMSChrgSigCPInc_cnt'
   *  Constant: '<S765>/KISP_VldChkBMSChrgSigCPLim_cnt'
   *  Constant: '<S809>/False'
   *  Logic: '<S809>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_g, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_hf, &rtb_valid_signal_nv,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_o0x);

  /* End of Outputs for SubSystem: '<S809>/signal validity checking' */

  /* DataTypeConversion: '<S9>/Convert ofVHSPI_BMSACChrgS2Sts_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_AC_charge_S2_status < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_AC_charge_S2_status >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_AC_charge_S2_status;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S9>/Convert ofVHSPI_BMSACChrgS2Sts_enum' */

  /* Outputs for Atomic SubSystem: '<S320>/signal validity checking' */
  /* DataTypeConversion: '<S320>/Data Type Conversion' incorporates:
   *  Constant: '<S299>/KISP_VldChkBMSACChrgS2StsDec_cnt'
   *  Constant: '<S299>/KISP_VldChkBMSACChrgS2StsInc_cnt'
   *  Constant: '<S299>/KISP_VldChkBMSACChrgS2StsLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_j((real32_T)NISP_SigOut_i,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_i, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_fu, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_jr,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_jr);

  /* End of Outputs for SubSystem: '<S320>/signal validity checking' */

  /* BusCreator: '<Root>/Bus Creator21' incorporates:
   *  Constant: '<Root>/Constant95'
   *  Constant: '<Root>/Constant98'
   *  Inport: '<Root>/In58'
   */
  PowerCtrolProject1_S32K144_B.CAN2RX0h.Extended =
    PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic19;
  PowerCtrolProject1_S32K144_B.CAN2RX0h.Length = can_rx_msg.CAN2_DLC0h;
  PowerCtrolProject1_S32K144_B.CAN2RX0h.Remote = 0U;
  PowerCtrolProject1_S32K144_B.CAN2RX0h.Error = 0U;

  /* Switch: '<Root>/Switch19' */
  if (PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic19 != 0) {
    /* BusCreator: '<Root>/Bus Creator21' incorporates:
     *  Constant: '<Root>/Constant99'
     */
    PowerCtrolProject1_S32K144_B.CAN2RX0h.ID = 0U;
  } else {
    /* BusCreator: '<Root>/Bus Creator21' incorporates:
     *  Inport: '<Root>/In59'
     */
    PowerCtrolProject1_S32K144_B.CAN2RX0h.ID = can_rx_msg.CAN2_StdId0h;
  }

  /* End of Switch: '<Root>/Switch19' */

  /* BusCreator: '<Root>/Bus Creator21' incorporates:
   *  Constant: '<Root>/Constant96'
   *  Inport: '<Root>/In60'
   */
  PowerCtrolProject1_S32K144_B.CAN2RX0h.Timestamp = 0.0;
  for (i = 0; i < 8; i++) {
    PowerCtrolProject1_S32K144_B.CAN2RX0h.Data[i] = can_rx_msg.CAN2_Data0h[i];
  }

  /* S-Function (scanunpack): '<S2>/CANRXUnPack_RS485_Rx_03and1' */
  {
    /* S-Function (scanunpack): '<S2>/CANRXUnPack_RS485_Rx_03and1' */
    if ((1 == PowerCtrolProject1_S32K144_B.CAN2RX0h.Length) &&
        (PowerCtrolProject1_S32K144_B.CAN2RX0h.ID != INVALID_CAN_ID) ) {
      if ((0 == PowerCtrolProject1_S32K144_B.CAN2RX0h.ID) && (0U ==
           PowerCtrolProject1_S32K144_B.CAN2RX0h.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 1
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN2RX0h.Data[0]) & (uint8_T)
                    (0x6U)) >> 1);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_RS485_Rx_03and1_o1 =
                result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 0
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN2RX0h.Data[0]) & (uint8_T)
                    (0x1U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_RS485_Rx_03and1_o2 =
                result;
            }
          }
        }
      }
    }
  }

  /* Outputs for Atomic SubSystem: '<S1579>/signal validity checking' */
  /* DataTypeConversion: '<S1579>/Data Type Conversion' incorporates:
   *  Constant: '<S1572>/KISP_VldChkInverterEnaDec_cnt'
   *  Constant: '<S1572>/KISP_VldChkInverterEnaInc_cnt'
   *  Constant: '<S1572>/KISP_VldChkInverterEnaLim_cnt'
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   */
  PowerCtrolPro_sig_valid_check_f((real32_T)
    (PowerCtrolProject1_S32K144_B.CANRXUnPack_RS485_Rx_03and1_o2 != 0.0), 20, 1,
    2, &PowerCtrolProject1_S32K144_B.fault_flg, &rtb_valid_signal,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_a0h,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_a0h);

  /* End of Outputs for SubSystem: '<S1579>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S16>/Convert ofVHSPI_BMSChrgCPPWMI_A'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Charging_CP_PWM_Current;

  /* Outputs for Atomic SubSystem: '<S790>/signal validity checking' */
  /* Logic: '<S790>/Logical Operator1' incorporates:
   *  Constant: '<S142>/Bus Selector_SigVld5'
   *  Constant: '<S762>/KISP_BMSChrgCPPWMIDft_A'
   *  Constant: '<S762>/KISP_VldChkBMSChrgCPPWMIDec_cnt'
   *  Constant: '<S762>/KISP_VldChkBMSChrgCPPWMIInc_cnt'
   *  Constant: '<S762>/KISP_VldChkBMSChrgCPPWMILim_cnt'
   *  Constant: '<S790>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_fq,
                  &rtb_valid_signal_ft,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_o4);

  /* End of Outputs for SubSystem: '<S790>/signal validity checking' */

  /* BusCreator: '<Root>/Bus Creator16' incorporates:
   *  Constant: '<Root>/Constant55'
   *  Constant: '<Root>/Constant58'
   *  Inport: '<Root>/In43'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX280h.Extended =
    PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic14;
  PowerCtrolProject1_S32K144_B.CAN1RX280h.Length = can_rx_msg.CAN1_DLC280h;
  PowerCtrolProject1_S32K144_B.CAN1RX280h.Remote = 0U;
  PowerCtrolProject1_S32K144_B.CAN1RX280h.Error = 0U;

  /* Switch: '<Root>/Switch14' */
  if (PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic14 != 0) {
    /* BusCreator: '<Root>/Bus Creator16' incorporates:
     *  Constant: '<Root>/Constant59'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX280h.ID = 0U;
  } else {
    /* BusCreator: '<Root>/Bus Creator16' incorporates:
     *  Inport: '<Root>/In44'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX280h.ID = can_rx_msg.CAN1_StdId280h;
  }

  /* End of Switch: '<Root>/Switch14' */

  /* BusCreator: '<Root>/Bus Creator16' incorporates:
   *  Constant: '<Root>/Constant56'
   *  Inport: '<Root>/In45'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX280h.Timestamp = 0.0;
  for (i = 0; i < 8; i++) {
    PowerCtrolProject1_S32K144_B.CAN1RX280h.Data[i] = can_rx_msg.CAN1_Data280h[i];
  }

  /* S-Function (scanunpack): '<S21>/CANRXUnPack_CDU_280h' */
  {
    /* S-Function (scanunpack): '<S21>/CANRXUnPack_CDU_280h' */
    if ((8 == PowerCtrolProject1_S32K144_B.CAN1RX280h.Length) &&
        (PowerCtrolProject1_S32K144_B.CAN1RX280h.ID != INVALID_CAN_ID) ) {
      if ((640 == PowerCtrolProject1_S32K144_B.CAN1RX280h.ID) && (0U ==
           PowerCtrolProject1_S32K144_B.CAN1RX280h.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 40
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = -40.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX280h.Data[5]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result + -40.0;
              PowerCtrolProject1_S32K144_B.OBC_ChgCoolantPlate_temp = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 48
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX280h.Data[6]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.1;
              PowerCtrolProject1_S32K144_B.OBC_HL_Batt_Voltage = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 8
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX280h.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.OBC_HL_Output_Current = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 0
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX280h.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.1;
              PowerCtrolProject1_S32K144_B.OBC_HL_Output_Voltage = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 32
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX280h.Data[4]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.OBC_OutputCurrent_AC = result;
            }
          }

          /* --------------- START Unpacking signal 5 ------------------
           *  startBit                = 24
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX280h.Data[3]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX280h.Data[2]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.OBC_OutputVoltage_AC = result;
            }
          }
        }
      }
    }
  }

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S21>/Convert ofVHSPI_OBCOutpACU_V'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.OBC_OutputVoltage_AC;

  /* Outputs for Atomic SubSystem: '<S986>/signal validity checking' */
  /* Logic: '<S986>/Logical Operator1' incorporates:
   *  Constant: '<S146>/Bus Selector_SigVld6'
   *  Constant: '<S942>/KISP_OBCOutpACUDft_V'
   *  Constant: '<S942>/KISP_VldChkOBCOutpACUDec_cnt'
   *  Constant: '<S942>/KISP_VldChkOBCOutpACUInc_cnt'
   *  Constant: '<S942>/KISP_VldChkOBCOutpACULim_cnt'
   *  Constant: '<S986>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_noq,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ax);

  /* End of Outputs for SubSystem: '<S986>/signal validity checking' */

  /* DataTypeConversion: '<S9>/Convert ofVHSPI_BMSChrgSts_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Charge_status < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Charge_status >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.BMS_Charge_status;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S9>/Convert ofVHSPI_BMSChrgSts_enum' */

  /* Outputs for Atomic SubSystem: '<S338>/signal validity checking' */
  /* DataTypeConversion: '<S338>/Data Type Conversion' incorporates:
   *  Constant: '<S302>/KISP_VldChkBMSChrgStsDec_cnt'
   *  Constant: '<S302>/KISP_VldChkBMSChrgStsInc_cnt'
   *  Constant: '<S302>/KISP_VldChkBMSChrgStsLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_j((real32_T)NISP_SigOut_i,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_c, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_bj, &rtb_valid_signal_gem,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_i,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_i);

  /* End of Outputs for SubSystem: '<S338>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S338>/override signal' */
  /* DataTypeConversion: '<S338>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S339>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_e = (uint8_T)rtb_valid_signal_gem;

  /* End of Outputs for SubSystem: '<S338>/override signal' */

  /* Outputs for Atomic SubSystem: '<S326>/override signal' */
  /* DataTypeConversion: '<S326>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S327>/TmpSignal ConversionAtSwitch1Inport3'
   */
  NISP_sigOut = (rtb_valid_signal_e5 != 0.0F);

  /* End of Outputs for SubSystem: '<S326>/override signal' */

  /* MinMax: '<S119>/MinMax2' incorporates:
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_p >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_b) {
    rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_p;
  } else {
    rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_b;
  }

  if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_ej) {
    rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_ej;
  }

  if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_l2) {
    rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_l2;
  }

  if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_f) {
    rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_f;
  }

  if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_ll) {
    rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_ll;
  }

  if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_nw) {
    rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_nw;
  }

  if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_c) {
    rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_c;
  }

  if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_j0) {
    rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_j0;
  }

  if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_fl) {
    rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_fl;
  }

  if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_o) {
    rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_o;
  }

  if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_oo) {
    rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_oo;
  }

  if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_ih) {
    rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_ih;
  }

  /* RelationalOperator: '<S119>/Relational Operator' incorporates:
   *  Constant: '<S119>/Debug value5'
   */
  RelationalOperator = (rtb_MinMax1 >= 2);

  /* Outputs for Atomic SubSystem: '<S784>/override signal' */
  /* DataTypeConversion: '<S784>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S785>/TmpSignal ConversionAtSwitch1Inport3'
   */
  NISP_SigOut_i = (uint8_T)rtb_valid_signal_em;

  /* End of Outputs for SubSystem: '<S784>/override signal' */

  /* Outputs for Atomic SubSystem: '<S803>/override signal' */
  /* DataTypeConversion: '<S803>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S804>/TmpSignal ConversionAtSwitch1Inport3'
   */
  NISP_SigOut_k = (uint8_T)rtb_valid_signal_co;

  /* End of Outputs for SubSystem: '<S803>/override signal' */

  /* Outputs for Atomic SubSystem: '<S809>/override signal' */
  /* DataTypeConversion: '<S809>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S810>/TmpSignal ConversionAtSwitch1Inport3'
   */
  NISP_SigOut_j = (uint8_T)rtb_valid_signal_nv;

  /* End of Outputs for SubSystem: '<S809>/override signal' */

  /* Outputs for Atomic SubSystem: '<S320>/override signal' */
  /* DataTypeConversion: '<S320>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S321>/TmpSignal ConversionAtSwitch1Inport3'
   */
  NISP_SigOut_l = (uint8_T)rtb_valid_signal_iw;

  /* End of Outputs for SubSystem: '<S320>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1579>/override signal' */
  /* DataTypeConversion: '<S1579>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1580>/TmpSignal ConversionAtSwitch1Inport3'
   */
  NISP_sigOut_k = (rtb_valid_signal != 0.0F);

  /* End of Outputs for SubSystem: '<S1579>/override signal' */

  /* Switch: '<S106>/Switch1' incorporates:
   *  Constant: '<S106>/Debug value11'
   */
  PowerCtrolProject1_S32K144_B.VISP_PowerReq_kw = 100.0F;

  /* Switch: '<S105>/Switch2' incorporates:
   *  Constant: '<S105>/Debug value11'
   *  Constant: '<S105>/Debug value15'
   *  RelationalOperator: '<S105>/Comparison1'
   */
  if (NISP_SigOut_i == 1) {
    rtb_MinMax1 = 10U;

    /* Switch: '<S105>/Switch1' */
    rtb_valid_signal_em = PowerCtrolProject1_S32K1_ConstB.DataTypeConversion1;
  } else if (NISP_SigOut_i == 2) {
    /* Switch: '<S105>/Switch3' incorporates:
     *  Constant: '<S105>/Debug value7'
     */
    rtb_MinMax1 = 16U;

    /* Switch: '<S105>/Switch1' */
    rtb_valid_signal_em = PowerCtrolProject1_S32K1_ConstB.DataTypeConversion1;
  } else if (NISP_SigOut_i == 3) {
    /* Switch: '<S105>/Switch4' incorporates:
     *  Constant: '<S105>/Debug value16'
     *  Switch: '<S105>/Switch3'
     */
    rtb_MinMax1 = 32U;

    /* Switch: '<S105>/Switch1' */
    rtb_valid_signal_em = PowerCtrolProject1_S32K1_ConstB.DataTypeConversion1;
  } else if (NISP_SigOut_i == 5) {
    /* Switch: '<S105>/Switch5' incorporates:
     *  Constant: '<S105>/Debug value17'
     *  Switch: '<S105>/Switch3'
     *  Switch: '<S105>/Switch4'
     */
    rtb_MinMax1 = 64U;

    /* Switch: '<S105>/Switch1' */
    rtb_valid_signal_em = PowerCtrolProject1_S32K1_ConstB.DataTypeConversion1;
  } else {
    /* Switch: '<S105>/Switch4' incorporates:
     *  Constant: '<S105>/Debug value8'
     *  Switch: '<S105>/Switch3'
     *  Switch: '<S105>/Switch5'
     */
    rtb_MinMax1 = 0U;

    /* Switch: '<S105>/Switch1' incorporates:
     *  Constant: '<S105>/Debug value9'
     */
    rtb_valid_signal_em = 0.0F;
  }

  /* End of Switch: '<S105>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S790>/override signal' */
  /* MinMax: '<S105>/MinMax' incorporates:
   *  DataTypeConversion: '<S105>/Data Type Conversion'
   *  SignalConversion: '<S791>/TmpSignal ConversionAtSwitch1Inport3'
   */
  if ((rtb_MinMax1 < rtb_valid_signal_ft) || rtIsNaNF(rtb_valid_signal_ft)) {
    rtb_valid_signal_ft = rtb_MinMax1;
  }

  /* End of MinMax: '<S105>/MinMax' */
  /* End of Outputs for SubSystem: '<S790>/override signal' */

  /* Outputs for Atomic SubSystem: '<S986>/override signal' */
  /* Switch: '<S107>/Switch' incorporates:
   *  Constant: '<S105>/Debug value3'
   *  Product: '<S105>/Divide'
   *  SignalConversion: '<S987>/TmpSignal ConversionAtSwitch1Inport3'
   *  Sum: '<S105>/Subtract'
   */
  PowerCtrolProject1_S32K144_B.y = rtb_valid_signal_ft * rtb_valid_signal_pd /
    1000.0F - rtb_valid_signal_em;

  /* End of Outputs for SubSystem: '<S986>/override signal' */

  /* Outputs for Atomic SubSystem: '<S105>/Limiter' */
  /* Switch: '<S107>/Switch1' incorporates:
   *  Constant: '<S105>/Debug value10'
   *  RelationalOperator: '<S107>/Relational Operator'
   */
  if (100.0F < PowerCtrolProject1_S32K144_B.y) {
    /* Switch: '<S107>/Switch' */
    PowerCtrolProject1_S32K144_B.y = 100.0F;
  }

  /* End of Switch: '<S107>/Switch1' */

  /* Switch: '<S107>/Switch' incorporates:
   *  Constant: '<S105>/Debug value2'
   *  RelationalOperator: '<S107>/Relational Operator1'
   */
  if (!(PowerCtrolProject1_S32K144_B.y > 0.0F)) {
    PowerCtrolProject1_S32K144_B.y = 0.0F;
  }

  /* End of Outputs for SubSystem: '<S105>/Limiter' */

  /* Product: '<S105>/Divide1' incorporates:
   *  Constant: '<S105>/Debug value1'
   */
  PowerCtrolProject1_S32K144_B.VRCC_RoundPower_kw =
    PowerCtrolProject1_S32K144_B.y * 10.0F;

  /* BusCreator: '<Root>/Bus Creator22' incorporates:
   *  Constant: '<Root>/Constant100'
   *  Constant: '<Root>/Constant103'
   *  Inport: '<Root>/In61'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX501h.Extended =
    PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic20;
  PowerCtrolProject1_S32K144_B.CAN1RX501h.Length = can_rx_msg.CAN1_DLC501h;
  PowerCtrolProject1_S32K144_B.CAN1RX501h.Remote = 0U;
  PowerCtrolProject1_S32K144_B.CAN1RX501h.Error = 0U;

  /* Switch: '<Root>/Switch20' */
  if (PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic20 != 0) {
    /* BusCreator: '<Root>/Bus Creator22' incorporates:
     *  Constant: '<Root>/Constant104'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX501h.ID = 0U;
  } else {
    /* BusCreator: '<Root>/Bus Creator22' incorporates:
     *  Inport: '<Root>/In62'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX501h.ID = can_rx_msg.CAN1_StdId501h;
  }

  /* End of Switch: '<Root>/Switch20' */

  /* BusCreator: '<Root>/Bus Creator22' incorporates:
   *  Constant: '<Root>/Constant101'
   *  Inport: '<Root>/In63'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX501h.Timestamp = 0.0;
  for (i = 0; i < 8; i++) {
    PowerCtrolProject1_S32K144_B.CAN1RX501h.Data[i] = can_rx_msg.CAN1_Data501h[i];
  }

  /* S-Function (scanunpack): '<S25>/CANRXUnPack_0x419' */
  {
    /* S-Function (scanunpack): '<S25>/CANRXUnPack_0x419' */
    if ((8 == PowerCtrolProject1_S32K144_B.CAN1RX501h.Length) &&
        (PowerCtrolProject1_S32K144_B.CAN1RX501h.ID != INVALID_CAN_ID) ) {
      if ((1281 == PowerCtrolProject1_S32K144_B.CAN1RX501h.ID) && (0U ==
           PowerCtrolProject1_S32K144_B.CAN1RX501h.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 7
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX501h.Data[0]) & (uint8_T)
                    (0x80U)) >> 7);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 6
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX501h.Data[0]) & (uint8_T)
                    (0x40U)) >> 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 4
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX501h.Data[0]) & (uint8_T)
                    (0x10U)) >> 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o3 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 16
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX501h.Data[2]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.1;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o4 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 8
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX501h.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o5 = result;
            }
          }

          /* --------------- START Unpacking signal 5 ------------------
           *  startBit                = 5
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX501h.Data[0]) & (uint8_T)
                    (0x20U)) >> 5);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o6 = result;
            }
          }

          /* --------------- START Unpacking signal 6 ------------------
           *  startBit                = 24
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX501h.Data[3]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o7 = result;
            }
          }

          /* --------------- START Unpacking signal 7 ------------------
           *  startBit                = 32
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX501h.Data[4]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o8 = result;
            }
          }
        }
      }
    }
  }

  /* Outputs for Atomic SubSystem: '<S1543>/signal validity checking' */
  /* DataTypeConversion: '<S1543>/Data Type Conversion' incorporates:
   *  Constant: '<S1480>/KISP_VldChkACPwrFocModDec_cnt'
   *  Constant: '<S1480>/KISP_VldChkACPwrFocModInc_cnt'
   *  Constant: '<S1480>/KISP_VldChkACPwrFocModLim_cnt'
   *  DataTypeConversion: '<S25>/Convert ofVHSPI_InverterEna_flg5'
   */
  PowerCtrolPro_sig_valid_check_f((real32_T)
    (PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o5 != 0.0), 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_k, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_n0,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_n0);

  /* End of Outputs for SubSystem: '<S1543>/signal validity checking' */

  /* Chart: '<S65>/OBCInvertChrgChart' incorporates:
   *  Constant: '<S119>/Debug value5'
   *  DataTypeConversion: '<S326>/Data Type Conversion1'
   *  RelationalOperator: '<S119>/Relational Operator'
   *  SignalConversion: '<S327>/TmpSignal ConversionAtSwitch1Inport3'
   */
  if (PowerCtrolProject1_S32K14_DWork.is_active_c3_PowerCtrolProject1 == 0U) {
    PowerCtrolProject1_S32K14_DWork.is_active_c3_PowerCtrolProject1 = 1U;
    PowerCtrolProject1_S32K14_DWork.is_c3_PowerCtrolProject1_S32K14 =
      PowerCtrolProject1_S32K_IN_Init;
    PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 0U;
    PowerCtrolProject1_S32K144_B.VRCC_SetInverter_flg = false;
    PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = false;
    PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = false;
    PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = false;
    PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw = 100.0F;
    PowerCtrolProject1_S32K14_DWork.TimeCounter = 0.0F;
  } else {
    switch (PowerCtrolProject1_S32K14_DWork.is_c3_PowerCtrolProject1_S32K14) {
     case PowerCtrolProject1__IN_ConnChrg:
      PowerCtrolProject1_S32_ConnChrg(&NISP_sigOut, &NISP_SigOut_i,
        &NISP_SigOut_l, &NISP_SigOut_k, &NISP_SigOut_j, &NISP_sigOut_k);
      break;

     case PowerCtrolProject1_S32K_IN_Init:
      /* MinMax: '<S119>/MinMax2' incorporates:
       *  UnitDelay: '<S5>/Unit Delay2'
       */
      if (PowerCtrolProject1_S32K144_B.NISP_SigOut_p >
          PowerCtrolProject1_S32K144_B.NISP_SigOut_b) {
        rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_p;
      } else {
        rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_b;
      }

      if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_ej) {
        rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_ej;
      }

      if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_l2) {
        rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_l2;
      }

      if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_f) {
        rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_f;
      }

      if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_ll) {
        rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_ll;
      }

      if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_nw) {
        rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_nw;
      }

      if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_c) {
        rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_c;
      }

      if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_j0) {
        rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_j0;
      }

      if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_fl) {
        rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_fl;
      }

      if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_o) {
        rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_o;
      }

      if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_oo) {
        rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_oo;
      }

      if (rtb_MinMax1 <= PowerCtrolProject1_S32K144_B.NISP_SigOut_ih) {
        rtb_MinMax1 = PowerCtrolProject1_S32K144_B.NISP_SigOut_ih;
      }

      if (NISP_sigOut_k && ((NISP_SigOut_i == 0) || (NISP_SigOut_i == 8)) &&
          (rtb_MinMax1 < 2)) {
        PowerCtrolProject1_S32K14_DWork.is_c3_PowerCtrolProject1_S32K14 =
          PowerCtrolProject_IN_NoConnChrg;
        PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
          PowerCtrolProject_IN_NoConnInit;
        PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 1U;
      } else {
        /* Outputs for Atomic SubSystem: '<S326>/override signal' */
        if ((NISP_SigOut_i != 0) && (NISP_SigOut_i != 8) && (NISP_SigOut_j == 1)
            && ((rtb_valid_signal_e5 != 0.0F) && (NISP_SigOut_k != 0))) {
          PowerCtrolProject1_S32K14_DWork.is_c3_PowerCtrolProject1_S32K14 =
            PowerCtrolProject1__IN_ConnChrg;
          PowerCtrolProject1_S32K14_DWork.is_ConnChrg =
            PowerCtrolProject1__IN_ConnInit;
          PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 2U;
        }

        /* End of Outputs for SubSystem: '<S326>/override signal' */
      }
      break;

     default:
      PowerCtrolProject1_S_NoConnChrg(&NISP_sigOut, &RelationalOperator,
        &NISP_SigOut_i, &NISP_SigOut_k, &NISP_SigOut_j, &NISP_sigOut_k);
      break;
    }
  }

  /* End of Chart: '<S65>/OBCInvertChrgChart' */

  /* Outputs for Atomic SubSystem: '<S1523>/signal validity checking' */
  /* DataTypeConversion: '<S1523>/Data Type Conversion' incorporates:
   *  Constant: '<S1477>/KISP_VldChkACPwrFocModDec_cnt'
   *  Constant: '<S1477>/KISP_VldChkACPwrFocModInc_cnt'
   *  Constant: '<S1477>/KISP_VldChkACPwrFocModLim_cnt'
   *  Constant: '<S25>/Constant20'
   *  DataTypeConversion: '<S25>/Convert ofVHSPI_InverterEna_flg14'
   */
  PowerCtrolPro_sig_valid_check_f(0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_cf, &rtb_valid_signal_co,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_ll,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ll);

  /* End of Outputs for SubSystem: '<S1523>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S386>/signal validity checking' */
  /* DataTypeConversion: '<S386>/Data Type Conversion' incorporates:
   *  Constant: '<S310>/KISP_VldChkBMSChrgConnStsDec_cnt'
   *  Constant: '<S310>/KISP_VldChkBMSChrgConnStsInc_cnt'
   *  Constant: '<S310>/KISP_VldChkBMSChrgConnStsLim_cnt'
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   */
  PowerCtrolPro_sig_valid_check_f((real32_T)
    (PowerCtrolProject1_S32K144_B.BMS_Total_positive_relay_status != 0.0), 20, 1,
    2, &PowerCtrolProject1_S32K144_B.fault_flg_mu, &rtb_valid_signal_e5,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_fo,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_fo);

  /* End of Outputs for SubSystem: '<S386>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1573>/signal validity checking' */
  /* DataTypeConversion: '<S1573>/Data Type Conversion' incorporates:
   *  Constant: '<S1571>/KISP_VldChkOBCInverterStsDec_cnt'
   *  Constant: '<S1571>/KISP_VldChkOBCInverterStsInc_cnt'
   *  Constant: '<S1571>/KISP_VldChkOBCInverterStsLim_cnt'
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  PowerCtrolPro_sig_valid_check_j((real32_T)(uint8_T)
    PowerCtrolProject1_S32K144_B.CANRXUnPack_RS485_Rx_03and1_o1,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_a, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_c, &rtb_valid_signal_em,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_oez,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_oez);

  /* End of Outputs for SubSystem: '<S1573>/signal validity checking' */

  /* Chart: '<S312>/Initialization' */
  PowerCtrolProj_Initialization_f
    (PowerCtrolProject1_S32K1_ConstB.VHSPI_BMS204hCANActv_flg,
     &PowerCtrolProject1_S32K144_B.CANInt_c3);

  /* Outputs for Enabled SubSystem: '<S312>/CANDiagnosis' incorporates:
   *  EnablePort: '<S313>/Enable'
   */
  if (PowerCtrolProject1_S32K144_B.CANInt_c3) {
    if (!PowerCtrolProject1_S32K14_DWork.CANDiagnosis_MODE_l) {
      /* SystemReset for Atomic SubSystem: '<S313>/signal validity checking' */
      PowerCt_sig_valid_check_k_Reset(&PowerCtrolProject1_S32K144_B.fault_flg_ga,
        &PowerCtrolProject1_S32K144_B.valid_signal_c,
        &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ku);

      /* End of SystemReset for SubSystem: '<S313>/signal validity checking' */
      PowerCtrolProject1_S32K14_DWork.CANDiagnosis_MODE_l = true;
    }

    /* Outputs for Atomic SubSystem: '<S313>/signal validity checking' */
    /* Constant: '<S313>/sat2' incorporates:
     *  Constant: '<S298>/KISP_VldChkBMS204hCANActvDec_cnt'
     *  Constant: '<S298>/KISP_VldChkBMS204hCANActvInc_cnt'
     *  Constant: '<S298>/KISP_VldChkBMS204hCANActvLim_cnt'
     */
    PowerCtrolPro_sig_valid_check_k
      (PowerCtrolProject1_S32K1_ConstB.DataTypeConversion_n, 0.0F, 20, 1, 2,
       &PowerCtrolProject1_S32K144_B.fault_flg_ga,
       &PowerCtrolProject1_S32K144_B.valid_signal_c,
       &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_ku,
       &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ku);

    /* End of Outputs for SubSystem: '<S313>/signal validity checking' */
  } else {
    if (PowerCtrolProject1_S32K14_DWork.CANDiagnosis_MODE_l) {
      PowerCtrolProject1_S32K14_DWork.CANDiagnosis_MODE_l = false;
    }
  }

  /* End of Outputs for SubSystem: '<S312>/CANDiagnosis' */

  /* Outputs for Atomic SubSystem: '<S1504>/signal validity checking' */
  /* DataTypeConversion: '<S1504>/Data Type Conversion' incorporates:
   *  Constant: '<S1474>/KISP_VldChkACPwrFocModDec_cnt'
   *  Constant: '<S1474>/KISP_VldChkACPwrFocModInc_cnt'
   *  Constant: '<S1474>/KISP_VldChkACPwrFocModLim_cnt'
   *  DataTypeConversion: '<S25>/Convert ofVHSPI_InverterEna_flg2'
   */
  PowerCtrolPro_sig_valid_check_f((real32_T)
    (PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o1 != 0.0), 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_j, &rtb_valid_signal_ft,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_ad,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ad);

  /* End of Outputs for SubSystem: '<S1504>/signal validity checking' */

  /* DataTypeConversion: '<S9>/Convert ofVHSPI_BMSSysSts_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_System_status_n < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_System_status_n >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.BMS_System_status_n;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S9>/Convert ofVHSPI_BMSSysSts_enum' */

  /* Outputs for Atomic SubSystem: '<S368>/signal validity checking' */
  /* DataTypeConversion: '<S368>/Data Type Conversion' incorporates:
   *  Constant: '<S307>/KISP_VldChkBMSSysStsDec_cnt'
   *  Constant: '<S307>/KISP_VldChkBMSSysStsInc_cnt'
   *  Constant: '<S307>/KISP_VldChkBMSSysStsLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_j((real32_T)NISP_SigOut_i,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_d, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_eg, &rtb_valid_signal_nv,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_er,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_er);

  /* End of Outputs for SubSystem: '<S368>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S368>/override signal' */
  /* DataTypeConversion: '<S368>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S369>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_a = (uint8_T)rtb_valid_signal_nv;

  /* End of Outputs for SubSystem: '<S368>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1611>/OSPProcessACChrgPwrF_kw' */
  /* Switch: '<S1621>/Switch2' incorporates:
   *  Constant: '<S1611>/KOSP_ACChrgPwrFHigh_kw'
   *  Constant: '<S1611>/KOSP_ACChrgPwrFLow_kw'
   *  RelationalOperator: '<S1621>/LowerRelop1'
   *  RelationalOperator: '<S1621>/UpperRelop'
   *  SignalConversion: '<S1620>/TmpSignal ConversionAtSwitch1Inport3'
   *  Switch: '<S1621>/Switch'
   */
  if (PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw > 65535.0F) {
    /* Product: '<S1611>/Product' */
    PowerCtrolProject1_S32K144_B.VOSP_ACChrgPwrF_kw = 65535.0F;
  } else if (PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw < 0.0F) {
    /* Switch: '<S1621>/Switch' incorporates:
     *  Constant: '<S1611>/KOSP_ACChrgPwrFLow_kw'
     *  Product: '<S1611>/Product'
     */
    PowerCtrolProject1_S32K144_B.VOSP_ACChrgPwrF_kw = 0.0F;
  } else {
    /* Product: '<S1611>/Product' */
    PowerCtrolProject1_S32K144_B.VOSP_ACChrgPwrF_kw =
      PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw;
  }

  /* End of Switch: '<S1621>/Switch2' */
  /* End of Outputs for SubSystem: '<S1611>/OSPProcessACChrgPwrF_kw' */

  /* Switch: '<S62>/Switch' incorporates:
   *  Constant: '<S56>/Constant73'
   *  Constant: '<S62>/dummy_MorEna_C'
   *  DataTypeConversion: '<S1523>/Data Type Conversion1'
   *  DataTypeConversion: '<S386>/Data Type Conversion1'
   *  Logic: '<S56>/Logical2'
   *  Logic: '<S56>/OR'
   *  RelationalOperator: '<S56>/Comparison28'
   *  RelationalOperator: '<S56>/Comparison6'
   *  SignalConversion: '<S1524>/TmpSignal ConversionAtSwitch1Inport3'
   *  SignalConversion: '<S387>/TmpSignal ConversionAtSwitch1Inport3'
   */
  if (PowerCtrolProject1_S32K1_ConstB.Logical1) {
    PowerCtrolProject1_S32K144_B.VOSP_ChrgForbd_flg = false;
  } else {
    /* Outputs for Atomic SubSystem: '<S1523>/override signal' */
    /* Outputs for Atomic SubSystem: '<S386>/override signal' */
    PowerCtrolProject1_S32K144_B.VOSP_ChrgForbd_flg = ((NISP_sigOut &&
      (rtb_valid_signal_co != 0.0F)) || (NISP_SigOut_k == 1) ||
      (rtb_valid_signal_e5 != 0.0F));

    /* End of Outputs for SubSystem: '<S386>/override signal' */
    /* End of Outputs for SubSystem: '<S1523>/override signal' */
  }

  /* End of Switch: '<S62>/Switch' */

  /* Logic: '<S120>/Logical2' incorporates:
   *  Logic: '<S120>/OR'
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  NISP_sigOut = !PowerCtrolProject1_S32K14_DWork.UnitDelay2_57_DSTATE;

  /* Outputs for Atomic SubSystem: '<S120>/Turn On Delay Time1' */
  /* Outputs for Atomic SubSystem: '<S126>/EdgeRising' */
  /* Logic: '<S127>/AND' incorporates:
   *  Logic: '<S120>/Logical2'
   *  Logic: '<S127>/OR1'
   *  UnitDelay: '<S127>/Unit Delay'
   */
  RelationalOperator = (NISP_sigOut &&
                        (!PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_ow));

  /* Update for UnitDelay: '<S127>/Unit Delay' incorporates:
   *  Logic: '<S120>/Logical2'
   */
  PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_ow = NISP_sigOut;

  /* End of Outputs for SubSystem: '<S126>/EdgeRising' */

  /* Switch: '<S126>/Switch1' incorporates:
   *  Constant: '<S120>/Constant5'
   *  Constant: '<S126>/Constant Value1'
   *  Logic: '<S120>/Logical2'
   *  Logic: '<S126>/OR'
   *  Logic: '<S126>/OR1'
   *  MinMax: '<S126>/Minimum'
   *  Sum: '<S126>/Summation'
   *  UnitDelay: '<S126>/Unit Delay'
   */
  if ((!NISP_sigOut) || RelationalOperator) {
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_e = 0.0F;
  } else if ((6.0F < 0.099999994F +
              PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_e) || rtIsNaNF
             (0.099999994F + PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_e))
  {
    /* MinMax: '<S126>/Minimum' */
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_e = 6.0F;
  } else {
    /* MinMax: '<S126>/Minimum' incorporates:
     *  Constant: '<S120>/Constant5'
     *  Sum: '<S126>/Summation'
     *  UnitDelay: '<S126>/Unit Delay'
     */
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_e += 0.099999994F;
  }

  /* End of Switch: '<S126>/Switch1' */
  /* End of Outputs for SubSystem: '<S120>/Turn On Delay Time1' */

  /* MinMax: '<S119>/MinMax3' incorporates:
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_l2 >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_o) {
    NISP_SigOut_i = PowerCtrolProject1_S32K144_B.NISP_SigOut_l2;
  } else {
    NISP_SigOut_i = PowerCtrolProject1_S32K144_B.NISP_SigOut_o;
  }

  /* End of MinMax: '<S119>/MinMax3' */

  /* Switch: '<S120>/Switch6' incorporates:
   *  Constant: '<S119>/Debug value6'
   *  Constant: '<S120>/Constant1'
   *  Constant: '<S120>/Constant17'
   *  Constant: '<S120>/Constant2'
   *  Constant: '<S120>/Constant6'
   *  Constant: '<S123>/Constant'
   *  Constant: '<S124>/Constant'
   *  Constant: '<S125>/Constant'
   *  Logic: '<S120>/Logical Operator'
   *  Logic: '<S120>/Logical Operator1'
   *  Logic: '<S120>/Logical1'
   *  Logic: '<S120>/Logical10'
   *  Logic: '<S120>/Logical11'
   *  Logic: '<S120>/Logical2'
   *  Logic: '<S120>/Logical3'
   *  Logic: '<S126>/AND'
   *  RelationalOperator: '<S119>/Relational Operator1'
   *  RelationalOperator: '<S120>/Comparison1'
   *  RelationalOperator: '<S120>/Comparison3'
   *  RelationalOperator: '<S123>/Compare'
   *  RelationalOperator: '<S124>/Compare'
   *  RelationalOperator: '<S125>/Compare'
   *  RelationalOperator: '<S126>/Greater  Than'
   *  Switch: '<S120>/Switch10'
   *  Switch: '<S120>/Switch3'
   *  UnitDelay: '<S126>/Unit Delay'
   *  UnitDelay: '<S5>/Unit Delay'
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  if (PowerCtrolProject1_S32K14_DWork.UnitDelay2_57_DSTATE || (NISP_SigOut_i >=
       2) || (!PowerCtrolProject1_S32K14_DWork.UnitDelay2_34_DSTATE)) {
    PowerCtrolProject1_S32K144_B.VOSP_DCDCOutpUReq_V = 0.0F;
  } else if (((PowerCtrolProject1_S32K144_B.DCDCState >= 12) &&
              (PowerCtrolProject1_S32K144_B.DCDCState <= 15)) ||
             (PowerCtrolProject1_S32K144_B.DCDCState == 20)) {
    /* Switch: '<S120>/Switch10' incorporates:
     *  UnitDelay: '<S5>/Unit Delay'
     */
    PowerCtrolProject1_S32K144_B.VOSP_DCDCOutpUReq_V =
      PowerCtrolProject1_S32K144_B.VCU_DCDC_OutputVoltageRequest;
  } else {
    /* Outputs for Atomic SubSystem: '<S120>/Turn On Delay Time1' */
    if (((PowerCtrolProject1_S32K14_DWork.UnitDelay2_53_DSTATE == 1) ||
         (PowerCtrolProject1_S32K14_DWork.UnitDelay2_53_DSTATE == 2)) &&
        (NISP_sigOut && (PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_e >=
                         6.0F))) {
      /* Switch: '<S120>/Switch3' incorporates:
       *  Constant: '<S120>/Constant3'
       *  Switch: '<S120>/Switch10'
       */
      PowerCtrolProject1_S32K144_B.VOSP_DCDCOutpUReq_V = 13.0F;
    } else {
      /* Switch: '<S120>/Switch10' incorporates:
       *  Constant: '<S120>/Constant4'
       *  Switch: '<S120>/Switch3'
       */
      PowerCtrolProject1_S32K144_B.VOSP_DCDCOutpUReq_V = 0.0F;
    }

    /* End of Outputs for SubSystem: '<S120>/Turn On Delay Time1' */
  }

  /* End of Switch: '<S120>/Switch6' */

  /* Outputs for Atomic SubSystem: '<S1613>/OSPProcessDCDCOutpUReq_V' */
  /* Switch: '<S1624>/Switch2' incorporates:
   *  Constant: '<S1613>/KOSP_DCDCOutpUReqHigh_V'
   *  Constant: '<S1613>/KOSP_DCDCOutpUReqLow_V'
   *  RelationalOperator: '<S1624>/LowerRelop1'
   *  RelationalOperator: '<S1624>/UpperRelop'
   *  SignalConversion: '<S1623>/TmpSignal ConversionAtSwitch1Inport3'
   *  Switch: '<S1624>/Switch'
   */
  if (PowerCtrolProject1_S32K144_B.VOSP_DCDCOutpUReq_V > 65535.0F) {
    /* Product: '<S1613>/Product' */
    PowerCtrolProject1_S32K144_B.VOSP_DCDCOutpUReq_V = 65535.0F;
  } else {
    if (PowerCtrolProject1_S32K144_B.VOSP_DCDCOutpUReq_V < 0.0F) {
      /* Switch: '<S1624>/Switch' incorporates:
       *  Constant: '<S1613>/KOSP_DCDCOutpUReqLow_V'
       *  Product: '<S1613>/Product'
       */
      PowerCtrolProject1_S32K144_B.VOSP_DCDCOutpUReq_V = 0.0F;
    }
  }

  /* End of Switch: '<S1624>/Switch2' */
  /* End of Outputs for SubSystem: '<S1613>/OSPProcessDCDCOutpUReq_V' */

  /* Outputs for Atomic SubSystem: '<S1573>/override signal' */
  /* DataTypeConversion: '<S1573>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1574>/TmpSignal ConversionAtSwitch1Inport3'
   */
  NISP_SigOut_i = (uint8_T)rtb_valid_signal_em;

  /* End of Outputs for SubSystem: '<S1573>/override signal' */

  /* RelationalOperator: '<S56>/Comparison3' incorporates:
   *  Constant: '<S56>/Constant7'
   */
  RelationalOperator = (NISP_SigOut_k == 1);

  /* Outputs for Atomic SubSystem: '<S56>/Turn On Delay Time1' */
  /* Outputs for Atomic SubSystem: '<S85>/EdgeRising' */
  /* Logic: '<S93>/AND' incorporates:
   *  Logic: '<S93>/OR1'
   *  UnitDelay: '<S93>/Unit Delay'
   */
  rtb_AND_a = (RelationalOperator &&
               (!PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_gx));

  /* Update for UnitDelay: '<S93>/Unit Delay' */
  PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_gx = RelationalOperator;

  /* End of Outputs for SubSystem: '<S85>/EdgeRising' */

  /* Switch: '<S85>/Switch1' incorporates:
   *  Constant: '<S56>/Constant12'
   *  Constant: '<S85>/Constant Value1'
   *  Logic: '<S85>/OR'
   *  Logic: '<S85>/OR1'
   *  MinMax: '<S85>/Minimum'
   *  Sum: '<S85>/Summation'
   *  UnitDelay: '<S85>/Unit Delay'
   */
  if ((!RelationalOperator) || rtb_AND_a) {
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_au = 0.0F;
  } else if ((2.0F < 0.099999994F +
              PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_au) || rtIsNaNF
             (0.099999994F + PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_au))
  {
    /* MinMax: '<S85>/Minimum' */
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_au = 2.0F;
  } else {
    /* MinMax: '<S85>/Minimum' incorporates:
     *  Constant: '<S56>/Constant12'
     *  Sum: '<S85>/Summation'
     *  UnitDelay: '<S85>/Unit Delay'
     */
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_au += 0.099999994F;
  }

  /* End of Switch: '<S85>/Switch1' */

  /* Logic: '<S85>/AND' incorporates:
   *  Constant: '<S56>/Constant13'
   *  RelationalOperator: '<S85>/Greater  Than'
   *  UnitDelay: '<S85>/Unit Delay'
   */
  rtb_AND_bg = (RelationalOperator &&
                (PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_au >= 2.0F));

  /* End of Outputs for SubSystem: '<S56>/Turn On Delay Time1' */

  /* Outputs for Atomic SubSystem: '<S56>/Turn On Delay Time' */
  /* Outputs for Atomic SubSystem: '<S84>/EdgeRising' */
  /* Logic: '<S92>/AND' incorporates:
   *  Logic: '<S92>/OR1'
   *  UnitDelay: '<S92>/Unit Delay'
   */
  RelationalOperator = (rtb_AND_bg &&
                        (!PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_h));

  /* Update for UnitDelay: '<S92>/Unit Delay' */
  PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_h = rtb_AND_bg;

  /* End of Outputs for SubSystem: '<S84>/EdgeRising' */

  /* Switch: '<S84>/Switch1' incorporates:
   *  Constant: '<S56>/Constant8'
   *  Constant: '<S84>/Constant Value1'
   *  Logic: '<S84>/OR'
   *  Logic: '<S84>/OR1'
   *  MinMax: '<S84>/Minimum'
   *  Sum: '<S84>/Summation'
   *  UnitDelay: '<S84>/Unit Delay'
   */
  if ((!rtb_AND_bg) || RelationalOperator) {
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_a0 = 0.0F;
  } else if ((1.0F < 0.099999994F +
              PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_a0) || rtIsNaNF
             (0.099999994F + PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_a0))
  {
    /* MinMax: '<S84>/Minimum' */
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_a0 = 1.0F;
  } else {
    /* MinMax: '<S84>/Minimum' incorporates:
     *  Constant: '<S56>/Constant8'
     *  Sum: '<S84>/Summation'
     *  UnitDelay: '<S84>/Unit Delay'
     */
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_a0 += 0.099999994F;
  }

  /* End of Switch: '<S84>/Switch1' */
  /* End of Outputs for SubSystem: '<S56>/Turn On Delay Time' */

  /* Switch: '<S56>/Switch7' incorporates:
   *  Constant: '<S56>/Constant1'
   *  Constant: '<S56>/Constant18'
   *  Constant: '<S56>/Constant2'
   *  Constant: '<S56>/Constant35'
   *  Constant: '<S56>/Constant62'
   *  Constant: '<S56>/Constant63'
   *  Constant: '<S56>/Constant9'
   *  Logic: '<S56>/Logical16'
   *  Logic: '<S56>/Logical22'
   *  Logic: '<S84>/AND'
   *  RelationalOperator: '<S56>/Comparison11'
   *  RelationalOperator: '<S56>/Comparison14'
   *  RelationalOperator: '<S56>/Comparison24'
   *  RelationalOperator: '<S56>/Comparison25'
   *  RelationalOperator: '<S56>/Comparison9'
   *  RelationalOperator: '<S84>/Greater  Than'
   *  Switch: '<S56>/Switch13'
   *  Switch: '<S56>/Switch14'
   *  Switch: '<S56>/Switch19'
   *  Switch: '<S56>/Switch21'
   *  UnitDelay: '<S84>/Unit Delay'
   */
  if (NISP_SigOut_i == 1) {
    NISP_SigOut_l = 0U;
  } else if (NISP_SigOut_i == 0) {
    /* Switch: '<S56>/Switch14' incorporates:
     *  Constant: '<S56>/Constant57'
     */
    NISP_SigOut_l = 1U;
  } else {
    /* Outputs for Atomic SubSystem: '<S56>/Turn On Delay Time' */
    if (rtb_AND_bg && (PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_a0 >=
                       1.0F)) {
      /* Switch: '<S56>/Switch21' incorporates:
       *  Constant: '<S56>/Constant69'
       *  Switch: '<S56>/Switch14'
       */
      NISP_SigOut_l = 0U;
    } else if ((NISP_SigOut_l == 1) && NISP_sigOut_k) {
      /* Switch: '<S56>/Switch13' incorporates:
       *  Constant: '<S56>/Constant64'
       *  Switch: '<S56>/Switch14'
       *  Switch: '<S56>/Switch21'
       */
      NISP_SigOut_l = 1U;
    } else if ((NISP_SigOut_l == 1) &&
               (PowerCtrolProject1_S32K144_B.NISP_SigOut_e == 1)) {
      /* Switch: '<S56>/Switch19' incorporates:
       *  Constant: '<S56>/Constant34'
       *  Switch: '<S56>/Switch13'
       *  Switch: '<S56>/Switch14'
       *  Switch: '<S56>/Switch21'
       */
      NISP_SigOut_l = 1U;
    } else {
      /* Switch: '<S56>/Switch19' incorporates:
       *  Constant: '<S56>/Constant68'
       *  Switch: '<S56>/Switch13'
       *  Switch: '<S56>/Switch14'
       *  Switch: '<S56>/Switch20'
       *  Switch: '<S56>/Switch21'
       */
      NISP_SigOut_l = 0U;
    }

    /* End of Outputs for SubSystem: '<S56>/Turn On Delay Time' */
  }

  /* End of Switch: '<S56>/Switch7' */

  /* Outputs for Atomic SubSystem: '<S1615>/OSPProcessElecLockEna_enum' */
  /* Switch: '<S1627>/Switch2' incorporates:
   *  DataTypeConversion: '<S1626>/Data Type Conversion2'
   */
  PowerCtrolProject1_S32K144_B.Switch2 = NISP_SigOut_l;

  /* End of Outputs for SubSystem: '<S1615>/OSPProcessElecLockEna_enum' */

  /* Outputs for Enabled SubSystem: '<S49>/HeartBeat' incorporates:
   *  EnablePort: '<S53>/Enable'
   */
  /* Outputs for Atomic SubSystem: '<S1543>/override signal' */
  /* DataTypeConversion: '<S1543>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1544>/TmpSignal ConversionAtSwitch1Inport3'
   */
  if (rtb_valid_signal_pd != 0.0F) {
    if (!PowerCtrolProject1_S32K14_DWork.HeartBeat_MODE) {
      /* InitializeConditions for Delay: '<S53>/Delay' */
      PowerCtrolProject1_S32K14_DWork.Delay_DSTATE = 0U;
      PowerCtrolProject1_S32K14_DWork.HeartBeat_MODE = true;
    }

    /* Sum: '<S53>/Add' incorporates:
     *  Constant: '<S49>/Constant Value1'
     *  Delay: '<S53>/Delay'
     */
    PowerCtrolProject1_S32K14_DWork.Delay_DSTATE++;

    /* Switch: '<S53>/Switch' incorporates:
     *  Constant: '<S53>/Constant'
     *  Delay: '<S53>/Delay'
     */
    if (PowerCtrolProject1_S32K14_DWork.Delay_DSTATE >= 255) {
      PowerCtrolProject1_S32K14_DWork.Delay_DSTATE = 0U;
    }

    /* End of Switch: '<S53>/Switch' */
  } else {
    if (PowerCtrolProject1_S32K14_DWork.HeartBeat_MODE) {
      PowerCtrolProject1_S32K14_DWork.HeartBeat_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S1543>/override signal' */
  /* End of Outputs for SubSystem: '<S49>/HeartBeat' */

  /* Outputs for Atomic SubSystem: '<S1617>/OSPProcessHeartBeat_enum' */
  /* Switch: '<S1630>/Switch2' incorporates:
   *  DataTypeConversion: '<S1629>/Data Type Conversion2'
   *  Delay: '<S53>/Delay'
   */
  PowerCtrolProject1_S32K144_B.Switch2_o =
    PowerCtrolProject1_S32K14_DWork.Delay_DSTATE;

  /* End of Outputs for SubSystem: '<S1617>/OSPProcessHeartBeat_enum' */

  /* Outputs for Atomic SubSystem: '<S1618>/OSPProcessInverterRly_flg' */
  /* DataTypeConversion: '<S1618>/DataTypeConversion' incorporates:
   *  DataTypeConversion: '<S1631>/Data Type Conversion2'
   */
  PowerCtrolProject1_S32K144_B.VOSP_InverterRly_flg =
    PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg;

  /* End of Outputs for SubSystem: '<S1618>/OSPProcessInverterRly_flg' */

  /* MinMax: '<S119>/MinMax1' incorporates:
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_g >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_db) {
    PowerCtrolProject1_S32K144_B.NISP_SigOut_db =
      PowerCtrolProject1_S32K144_B.NISP_SigOut_g;
  }

  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_db >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_p) {
    PowerCtrolProject1_S32K144_B.NISP_SigOut_p =
      PowerCtrolProject1_S32K144_B.NISP_SigOut_db;
  }

  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_p >
      PowerCtrolProject1_S32K14_DWork.UnitDelay2_105_DSTATE) {
    PowerCtrolProject1_S32K14_DWork.UnitDelay2_105_DSTATE =
      PowerCtrolProject1_S32K144_B.NISP_SigOut_p;
  }

  if (PowerCtrolProject1_S32K14_DWork.UnitDelay2_105_DSTATE >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_b) {
    PowerCtrolProject1_S32K144_B.NISP_SigOut_b =
      PowerCtrolProject1_S32K14_DWork.UnitDelay2_105_DSTATE;
  }

  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_b >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_n) {
    PowerCtrolProject1_S32K144_B.NISP_SigOut_n =
      PowerCtrolProject1_S32K144_B.NISP_SigOut_b;
  }

  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_n >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_hg) {
    PowerCtrolProject1_S32K144_B.NISP_SigOut_hg =
      PowerCtrolProject1_S32K144_B.NISP_SigOut_n;
  }

  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_hg >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_ej) {
    PowerCtrolProject1_S32K144_B.NISP_SigOut_ej =
      PowerCtrolProject1_S32K144_B.NISP_SigOut_hg;
  }

  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_ej >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_ji) {
    PowerCtrolProject1_S32K144_B.NISP_SigOut_ji =
      PowerCtrolProject1_S32K144_B.NISP_SigOut_ej;
  }

  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_ji >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_l2) {
    PowerCtrolProject1_S32K144_B.NISP_SigOut_l2 =
      PowerCtrolProject1_S32K144_B.NISP_SigOut_ji;
  }

  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_l2 >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_f) {
    PowerCtrolProject1_S32K144_B.NISP_SigOut_f =
      PowerCtrolProject1_S32K144_B.NISP_SigOut_l2;
  }

  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_f >
      PowerCtrolProject1_S32K14_DWork.UnitDelay2_121_DSTATE) {
    PowerCtrolProject1_S32K14_DWork.UnitDelay2_121_DSTATE =
      PowerCtrolProject1_S32K144_B.NISP_SigOut_f;
  }

  if (PowerCtrolProject1_S32K14_DWork.UnitDelay2_121_DSTATE >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_ll) {
    PowerCtrolProject1_S32K144_B.NISP_SigOut_ll =
      PowerCtrolProject1_S32K14_DWork.UnitDelay2_121_DSTATE;
  }

  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_ll >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_nw) {
    PowerCtrolProject1_S32K144_B.NISP_SigOut_nw =
      PowerCtrolProject1_S32K144_B.NISP_SigOut_ll;
  }

  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_nw >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_c) {
    PowerCtrolProject1_S32K144_B.NISP_SigOut_c =
      PowerCtrolProject1_S32K144_B.NISP_SigOut_nw;
  }

  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_c >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_j0) {
    PowerCtrolProject1_S32K144_B.NISP_SigOut_j0 =
      PowerCtrolProject1_S32K144_B.NISP_SigOut_c;
  }

  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_j0 >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_fl) {
    PowerCtrolProject1_S32K144_B.NISP_SigOut_fl =
      PowerCtrolProject1_S32K144_B.NISP_SigOut_j0;
  }

  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_fl >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_d0) {
    PowerCtrolProject1_S32K144_B.NISP_SigOut_d0 =
      PowerCtrolProject1_S32K144_B.NISP_SigOut_fl;
  }

  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_d0 >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_o) {
    PowerCtrolProject1_S32K144_B.NISP_SigOut_o =
      PowerCtrolProject1_S32K144_B.NISP_SigOut_d0;
  }

  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_o >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_gn) {
    PowerCtrolProject1_S32K144_B.NISP_SigOut_gn =
      PowerCtrolProject1_S32K144_B.NISP_SigOut_o;
  }

  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_gn >
      PowerCtrolProject1_S32K14_DWork.UnitDelay2_141_DSTATE) {
    PowerCtrolProject1_S32K14_DWork.UnitDelay2_141_DSTATE =
      PowerCtrolProject1_S32K144_B.NISP_SigOut_gn;
  }

  if (PowerCtrolProject1_S32K14_DWork.UnitDelay2_141_DSTATE >
      PowerCtrolProject1_S32K14_DWork.UnitDelay2_143_DSTATE) {
    PowerCtrolProject1_S32K14_DWork.UnitDelay2_143_DSTATE =
      PowerCtrolProject1_S32K14_DWork.UnitDelay2_141_DSTATE;
  }

  if (PowerCtrolProject1_S32K14_DWork.UnitDelay2_143_DSTATE >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_oo) {
    PowerCtrolProject1_S32K144_B.NISP_SigOut_oo =
      PowerCtrolProject1_S32K14_DWork.UnitDelay2_143_DSTATE;
  }

  if (PowerCtrolProject1_S32K144_B.NISP_SigOut_oo >
      PowerCtrolProject1_S32K144_B.NISP_SigOut_ih) {
    PowerCtrolProject1_S32K144_B.NISP_SigOut_ih =
      PowerCtrolProject1_S32K144_B.NISP_SigOut_oo;
  }

  /* DataTypeConversion: '<S1619>/DataTypeConversion' incorporates:
   *  Constant: '<S120>/Constant12'
   *  Logic: '<S120>/OR'
   *  RelationalOperator: '<S120>/Comparison4'
   *  UnitDelay: '<S5>/Unit Delay'
   */
  PowerCtrolProject1_S32K144_B.VOSP_SetInverter_flg = (NISP_sigOut &&
    (PowerCtrolProject1_S32K144_B.NISP_SigOut_ih != 1) &&
    PowerCtrolProject1_S32K14_DWork.UnitDelay_11_DSTATE);

  /* DataTypeConversion: '<S1634>/DataTypeConversion' incorporates:
   *  Delay: '<S118>/Delay'
   */
  PowerCtrolProject1_S32K144_B.VOSP_BMSKL15_flg =
    PowerCtrolProject1_S32K14_DWork.Delay_DSTATE_d;

  /* Outputs for Atomic SubSystem: '<S312>/override signal' */
  /* DataTypeConversion: '<S312>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S315>/TmpSignal ConversionAtSwitch1Inport3'
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  PowerCtrolProject1_S32K14_DWork.UnitDelay2_34_DSTATE =
    (PowerCtrolProject1_S32K144_B.valid_signal_c != 0.0F);

  /* End of Outputs for SubSystem: '<S312>/override signal' */

  /* Switch: '<S61>/Switch' incorporates:
   *  Constant: '<S61>/dummy_MorEna_C'
   *  DataTypeConversion: '<S386>/Data Type Conversion1'
   *  Logic: '<S56>/Logical10'
   *  Logic: '<S56>/Logical11'
   *  SignalConversion: '<S387>/TmpSignal ConversionAtSwitch1Inport3'
   *  Switch: '<S56>/Switch6'
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  if (PowerCtrolProject1_S32K1_ConstB.Logical1_h) {
    PowerCtrolProject1_S32K144_B.VOSP_ACInpRlyCtrlr_flg = false;
  } else {
    /* Outputs for Atomic SubSystem: '<S386>/override signal' */
    PowerCtrolProject1_S32K144_B.VOSP_ACInpRlyCtrlr_flg =
      ((!(rtb_valid_signal_e5 != 0.0F)) && (!rtb_AND_bg) &&
       PowerCtrolProject1_S32K14_DWork.UnitDelay2_34_DSTATE &&
       PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg);

    /* End of Outputs for SubSystem: '<S386>/override signal' */
  }

  /* End of Switch: '<S61>/Switch' */

  /* Outputs for Atomic SubSystem: '<S48>/Turn On Delay Time1' */
  /* Outputs for Atomic SubSystem: '<S51>/EdgeRising' */
  /* Logic: '<S52>/AND' incorporates:
   *  Logic: '<S52>/OR1'
   *  Switch: '<S48>/Switch'
   *  UnitDelay: '<S52>/Unit Delay'
   */
  NISP_sigOut_k = (PowerCtrolProject1_S32K144_B.VOSP_ACInpRlyCtrlr_flg &&
                   (!PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_c));

  /* Update for UnitDelay: '<S52>/Unit Delay' incorporates:
   *  Switch: '<S48>/Switch'
   */
  PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_c =
    PowerCtrolProject1_S32K144_B.VOSP_ACInpRlyCtrlr_flg;

  /* End of Outputs for SubSystem: '<S51>/EdgeRising' */

  /* Switch: '<S51>/Switch1' incorporates:
   *  Constant: '<S48>/Constant6'
   *  Constant: '<S51>/Constant Value1'
   *  Logic: '<S51>/OR'
   *  Logic: '<S51>/OR1'
   *  MinMax: '<S51>/Minimum'
   *  Sum: '<S51>/Summation'
   *  Switch: '<S48>/Switch'
   *  UnitDelay: '<S51>/Unit Delay'
   */
  if ((!PowerCtrolProject1_S32K144_B.VOSP_ACInpRlyCtrlr_flg) || NISP_sigOut_k) {
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_ij = 0.0F;
  } else if ((2.0F < 0.099999994F +
              PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_ij) || rtIsNaNF
             (0.099999994F + PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_ij))
  {
    /* MinMax: '<S51>/Minimum' */
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_ij = 2.0F;
  } else {
    /* MinMax: '<S51>/Minimum' incorporates:
     *  Constant: '<S48>/Constant6'
     *  Sum: '<S51>/Summation'
     *  UnitDelay: '<S51>/Unit Delay'
     */
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_ij += 0.099999994F;
  }

  /* End of Switch: '<S51>/Switch1' */

  /* DataTypeConversion: '<S1635>/DataTypeConversion' incorporates:
   *  Constant: '<S48>/Constant9'
   *  Logic: '<S51>/AND'
   *  RelationalOperator: '<S51>/Greater  Than'
   *  Switch: '<S48>/Switch'
   *  UnitDelay: '<S51>/Unit Delay'
   */
  PowerCtrolProject1_S32K144_B.VOSP_CDJQDSts_flg =
    (PowerCtrolProject1_S32K144_B.VOSP_ACInpRlyCtrlr_flg &&
     (PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_ij >= 2.0F));

  /* End of Outputs for SubSystem: '<S48>/Turn On Delay Time1' */

  /* Switch: '<S122>/Switch2' incorporates:
   *  Constant: '<S122>/Debug value3'
   *  Constant: '<S122>/Debug value5'
   *  Constant: '<S122>/Debug value6'
   *  Logic: '<S122>/AND'
   *  RelationalOperator: '<S122>/Relational Operator'
   *  RelationalOperator: '<S122>/Relational Operator1'
   *  RelationalOperator: '<S122>/Relational Operator2'
   *  Switch: '<S122>/Switch3'
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  if (PowerCtrolProject1_S32K14_DWork.UnitDelay2_293_DSTATE <= 0.2F) {
    /* Switch: '<S1644>/Switch2' incorporates:
     *  Constant: '<S122>/Debug value4'
     */
    PowerCtrolProject1_S32K144_B.Switch2_h = 0U;
  } else if ((PowerCtrolProject1_S32K14_DWork.UnitDelay2_293_DSTATE <= 4.2F) &&
             (3.8F <= PowerCtrolProject1_S32K14_DWork.UnitDelay2_293_DSTATE)) {
    /* Switch: '<S122>/Switch3' incorporates:
     *  Constant: '<S122>/Debug value7'
     *  Switch: '<S1644>/Switch2'
     */
    PowerCtrolProject1_S32K144_B.Switch2_h = 2U;
  } else {
    /* Switch: '<S1644>/Switch2' incorporates:
     *  Constant: '<S122>/Debug value8'
     *  Switch: '<S122>/Switch3'
     */
    PowerCtrolProject1_S32K144_B.Switch2_h = 1U;
  }

  /* End of Switch: '<S122>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S1504>/override signal' */
  /* Switch: '<S1646>/Switch2' incorporates:
   *  DataTypeConversion: '<S1504>/Data Type Conversion1'
   *  DataTypeConversion: '<S1637>/DataTypeConversion'
   *  SignalConversion: '<S1505>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.Switch2_m = (uint8_T)(rtb_valid_signal_ft != 0.0F);

  /* End of Outputs for SubSystem: '<S1504>/override signal' */

  /* DataTypeConversion: '<S1638>/DataTypeConversion' incorporates:
   *  Delay: '<S118>/Delay'
   */
  PowerCtrolProject1_S32K144_B.VOSP_OBCKL15_flg =
    PowerCtrolProject1_S32K14_DWork.Delay_DSTATE_d;

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S21>/Convert ofVHSPI_OBCChgCooltPlateT_deg1'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.OBC_HL_Batt_Voltage;

  /* Outputs for Atomic SubSystem: '<S951>/signal validity checking' */
  /* Logic: '<S951>/Logical Operator1' incorporates:
   *  Constant: '<S146>/Bus Selector_SigVld1'
   *  Constant: '<S937>/KISP_OBCOutpACUDft_V'
   *  Constant: '<S937>/KISP_VldChkOBCOutpACUDec_cnt'
   *  Constant: '<S937>/KISP_VldChkOBCOutpACUInc_cnt'
   *  Constant: '<S937>/KISP_VldChkOBCOutpACULim_cnt'
   *  Constant: '<S951>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_be,
                  &rtb_valid_signal_em,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_a0);

  /* End of Outputs for SubSystem: '<S951>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S57>/Hysteresis' */
  /* Outputs for Atomic SubSystem: '<S951>/override signal' */
  /* Switch: '<S98>/Switch1' incorporates:
   *  Constant: '<S57>/Constant3'
   *  Constant: '<S57>/Constant4'
   *  Constant: '<S98>/Constant Value'
   *  RelationalOperator: '<S98>/Greater  Than'
   *  RelationalOperator: '<S98>/Greater  Than1'
   *  SignalConversion: '<S952>/TmpSignal ConversionAtSwitch1Inport3'
   *  UnitDelay: '<S98>/Unit Delay'
   */
  if (rtb_valid_signal_em > 13.5F) {
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_ih = true;
  } else {
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_ih =
      ((!(rtb_valid_signal_em <= 12.4F)) &&
       PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_ih);
  }

  /* End of Switch: '<S98>/Switch1' */
  /* End of Outputs for SubSystem: '<S951>/override signal' */
  /* End of Outputs for SubSystem: '<S57>/Hysteresis' */

  /* Chart: '<S99>/Chart1' incorporates:
   *  UnitDelay: '<S98>/Unit Delay'
   *  UnitDelay: '<S99>/Unit Delay2'
   */
  PowerCtrolProject1_S32K1_Chart1
    (PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_ih,
     PowerCtrolProject1_S32K14_DWork.UnitDelay2_DSTATE,
     &PowerCtrolProject1_S32K144_B.out,
     &PowerCtrolProject1_S32K14_DWork.sf_Chart1_h);

  /* Switch: '<S57>/Switch' incorporates:
   *  Constant: '<S57>/Constant1'
   *  Constant: '<S57>/Constant2'
   */
  if (PowerCtrolProject1_S32K144_B.out) {
    rtb_Switch = 800;
  } else {
    rtb_Switch = 0;
  }

  /* End of Switch: '<S57>/Switch' */

  /* RelationalOperator: '<S69>/Compare' incorporates:
   *  Constant: '<S69>/Constant'
   */
  NISP_sigOut_k = (rtb_Switch <= 400);

  /* Logic: '<S75>/Logical Operator1' incorporates:
   *  Logic: '<S75>/Logical Operator'
   *  UnitDelay: '<S75>/Unit Delay'
   */
  NISP_sigOut = (NISP_sigOut_k &&
                 (!PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_df));

  /* Chart: '<S74>/Chart1' incorporates:
   *  UnitDelay: '<S74>/Unit Delay2'
   */
  PowerCtrolProject1_S32K1_Chart1(NISP_sigOut,
    PowerCtrolProject1_S32K14_DWork.UnitDelay2_DSTATE_k,
    &PowerCtrolProject1_S32K144_B.out_i,
    &PowerCtrolProject1_S32K14_DWork.sf_Chart1_j);

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S21>/Convert ofVHSPI_OBCHLOutpU_V'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.OBC_HL_Output_Voltage;

  /* Outputs for Atomic SubSystem: '<S972>/signal validity checking' */
  /* Logic: '<S972>/Logical Operator1' incorporates:
   *  Constant: '<S146>/Bus Selector_SigVld4'
   *  Constant: '<S940>/KISP_OBCHLOutpUDft_V'
   *  Constant: '<S940>/KISP_VldChkOBCHLOutpUDec_cnt'
   *  Constant: '<S940>/KISP_VldChkOBCHLOutpUInc_cnt'
   *  Constant: '<S940>/KISP_VldChkOBCHLOutpULim_cnt'
   *  Constant: '<S972>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_bd,
                  &rtb_valid_signal_co,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_gu);

  /* End of Outputs for SubSystem: '<S972>/signal validity checking' */

  /* BusCreator: '<Root>/Bus Creator6' incorporates:
   *  Constant: '<Root>/Constant20'
   *  Constant: '<Root>/Constant33'
   *  Inport: '<Root>/In13'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX206h.Extended =
    PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic4;
  PowerCtrolProject1_S32K144_B.CAN1RX206h.Length = can_rx_msg.CAN1_DLC206h;
  PowerCtrolProject1_S32K144_B.CAN1RX206h.Remote = 0U;
  PowerCtrolProject1_S32K144_B.CAN1RX206h.Error = 0U;

  /* Switch: '<Root>/Switch4' */
  if (PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic4 != 0) {
    /* BusCreator: '<Root>/Bus Creator6' incorporates:
     *  Constant: '<Root>/Constant34'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX206h.ID = 0U;
  } else {
    /* BusCreator: '<Root>/Bus Creator6' incorporates:
     *  Inport: '<Root>/In14'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX206h.ID = can_rx_msg.CAN1_StdId206h;
  }

  /* End of Switch: '<Root>/Switch4' */

  /* BusCreator: '<Root>/Bus Creator6' incorporates:
   *  Constant: '<Root>/Constant21'
   *  Inport: '<Root>/In15'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX206h.Timestamp = 0.0;
  for (i = 0; i < 8; i++) {
    PowerCtrolProject1_S32K144_B.CAN1RX206h.Data[i] = can_rx_msg.CAN1_Data206h[i];
  }

  /* S-Function (scanunpack): '<S10>/CANRXUnPack_BMS_206h' */
  {
    /* S-Function (scanunpack): '<S10>/CANRXUnPack_BMS_206h' */
    if ((8 == PowerCtrolProject1_S32K144_B.CAN1RX206h.Length) &&
        (PowerCtrolProject1_S32K144_B.CAN1RX206h.ID != INVALID_CAN_ID) ) {
      if ((518 == PowerCtrolProject1_S32K144_B.CAN1RX206h.ID) && (0U ==
           PowerCtrolProject1_S32K144_B.CAN1RX206h.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 8
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX206h.Data[1]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX206h.Data[0]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.1;
              PowerCtrolProject1_S32K144_B.BMS_Continuous_Discharge_pw = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 24
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX206h.Data[3]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX206h.Data[2]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.1;
              PowerCtrolProject1_S32K144_B.BMS_Continuous_charge_pw = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 40
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX206h.Data[5]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX206h.Data[4]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.1;
              PowerCtrolProject1_S32K144_B.BMS_Instantaneous_Discharge_pw =
                result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 56
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX206h.Data[7]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX206h.Data[6]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.1;
              PowerCtrolProject1_S32K144_B.BMS_Instantaneous_charge_pw = result;
            }
          }
        }
      }
    }
  }

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S10>/Convert ofVHSPI_BMSContnsChrg_kw'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Continuous_charge_pw;

  /* Outputs for Atomic SubSystem: '<S411>/signal validity checking' */
  /* Logic: '<S411>/Logical Operator1' incorporates:
   *  Constant: '<S136>/Bus Selector_SigVld3'
   *  Constant: '<S399>/KISP_BMSContnsChrgDft_kw'
   *  Constant: '<S399>/KISP_VldChkBMSContnsChrgDec_cnt'
   *  Constant: '<S399>/KISP_VldChkBMSContnsChrgInc_cnt'
   *  Constant: '<S399>/KISP_VldChkBMSContnsChrgLim_cnt'
   *  Constant: '<S411>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_pv,
                  &rtb_valid_signal_co,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_fj);

  /* End of Outputs for SubSystem: '<S411>/signal validity checking' */

  /* BusCreator: '<Root>/Bus Creator' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant3'
   *  Inport: '<Root>/In1'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX201h.Extended =
    PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic;
  PowerCtrolProject1_S32K144_B.CAN1RX201h.Length = can_rx_msg.CAN1_DLC201h;
  PowerCtrolProject1_S32K144_B.CAN1RX201h.Remote = 0U;
  PowerCtrolProject1_S32K144_B.CAN1RX201h.Error = 0U;

  /* Switch: '<Root>/Switch' */
  if (PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic != 0) {
    /* BusCreator: '<Root>/Bus Creator' incorporates:
     *  Constant: '<Root>/Constant4'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX201h.ID = 0U;
  } else {
    /* BusCreator: '<Root>/Bus Creator' incorporates:
     *  Inport: '<Root>/In6'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX201h.ID = can_rx_msg.CAN1_StdId201h;
  }

  /* End of Switch: '<Root>/Switch' */

  /* BusCreator: '<Root>/Bus Creator' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Inport: '<Root>/In8'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX201h.Timestamp = 0.0;
  for (i = 0; i < 8; i++) {
    PowerCtrolProject1_S32K144_B.CAN1RX201h.Data[i] = can_rx_msg.CAN1_Data201h[i];
  }

  /* S-Function (scanunpack): '<S6>/CANRXUnPack_BMS_201h' */
  {
    /* S-Function (scanunpack): '<S6>/CANRXUnPack_BMS_201h' */
    if ((8 == PowerCtrolProject1_S32K144_B.CAN1RX201h.Length) &&
        (PowerCtrolProject1_S32K144_B.CAN1RX201h.ID != INVALID_CAN_ID) ) {
      if ((513 == PowerCtrolProject1_S32K144_B.CAN1RX201h.ID) && (0U ==
           PowerCtrolProject1_S32K144_B.CAN1RX201h.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 40
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = -3000.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX201h.Data[5]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX201h.Data[4]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = (result * 0.1) + -3000.0;
              PowerCtrolProject1_S32K144_B.BMS_Charge_Discharge_current = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 56
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = SIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              int16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);
                int16_T* tempValuePtr = (int16_T*)&tempValue;

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX201h.Data[7]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX201h.Data[6]) << 8);
                }

                unpackedValue = *tempValuePtr;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.1;
              PowerCtrolProject1_S32K144_B.BMS_SOC = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 8
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX201h.Data[1]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX201h.Data[0]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.1;
              PowerCtrolProject1_S32K144_B.BMS_Total_bat_voltage_inside = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 24
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX201h.Data[3]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX201h.Data[2]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.1;
              PowerCtrolProject1_S32K144_B.BMS_Total_bat_voltage_outside =
                result;
            }
          }
        }
      }
    }
  }

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S6>/Convert ofVHSPI_BMSTotBattUInsd_V'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Total_bat_voltage_inside;

  /* Outputs for Atomic SubSystem: '<S182>/signal validity checking' */
  /* Logic: '<S182>/Logical Operator1' incorporates:
   *  Constant: '<S132>/Bus Selector_SigVld4'
   *  Constant: '<S158>/KISP_BMSTotBattUInsdDft_V'
   *  Constant: '<S158>/KISP_VldChkBMSTotBattUInsdDec_cnt'
   *  Constant: '<S158>/KISP_VldChkBMSTotBattUInsdInc_cnt'
   *  Constant: '<S158>/KISP_VldChkBMSTotBattUInsdLim_cnt'
   *  Constant: '<S182>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_nw1,
                  &rtb_valid_signal_nv,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_m);

  /* End of Outputs for SubSystem: '<S182>/signal validity checking' */

  /* BusCreator: '<Root>/Bus Creator20' incorporates:
   *  Constant: '<Root>/Constant90'
   *  Constant: '<Root>/Constant93'
   *  Inport: '<Root>/In55'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX419h.Extended =
    PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic18;
  PowerCtrolProject1_S32K144_B.CAN1RX419h.Length = can_rx_msg.CAN1_DLC419h;
  PowerCtrolProject1_S32K144_B.CAN1RX419h.Remote = 0U;
  PowerCtrolProject1_S32K144_B.CAN1RX419h.Error = 0U;

  /* Switch: '<Root>/Switch18' */
  if (PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic18 != 0) {
    /* BusCreator: '<Root>/Bus Creator20' incorporates:
     *  Constant: '<Root>/Constant94'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX419h.ID = 0U;
  } else {
    /* BusCreator: '<Root>/Bus Creator20' incorporates:
     *  Inport: '<Root>/In56'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX419h.ID = can_rx_msg.CAN1_StdId419h;
  }

  /* End of Switch: '<Root>/Switch18' */

  /* BusCreator: '<Root>/Bus Creator20' incorporates:
   *  Constant: '<Root>/Constant91'
   *  Inport: '<Root>/In57'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX419h.Timestamp = 0.0;
  for (i = 0; i < 8; i++) {
    PowerCtrolProject1_S32K144_B.CAN1RX419h.Data[i] = can_rx_msg.CAN1_Data419h[i];
  }

  /* S-Function (scanunpack): '<S24>/CANRXUnPack_0x419' */
  {
    /* S-Function (scanunpack): '<S24>/CANRXUnPack_0x419' */
    if ((8 == PowerCtrolProject1_S32K144_B.CAN1RX419h.Length) &&
        (PowerCtrolProject1_S32K144_B.CAN1RX419h.ID != INVALID_CAN_ID) ) {
      if ((1049 == PowerCtrolProject1_S32K144_B.CAN1RX419h.ID) && (0U ==
           PowerCtrolProject1_S32K144_B.CAN1RX419h.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 51
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX419h.Data[6]) & (uint8_T)
                    (0x8U)) >> 3);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o1_n = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 56
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX419h.Data[7]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o2_c = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 55
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX419h.Data[6]) & (uint8_T)
                    (0x80U)) >> 7);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o3_j = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 53
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX419h.Data[6]) & (uint8_T)
                    (0x20U)) >> 5);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o4_j = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 8
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.01
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX419h.Data[1]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX419h.Data[0]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.01;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o5_c = result;
            }
          }

          /* --------------- START Unpacking signal 5 ------------------
           *  startBit                = 32
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = -40.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX419h.Data[4]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result + -40.0;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o6_c = result;
            }
          }

          /* --------------- START Unpacking signal 6 ------------------
           *  startBit                = 52
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX419h.Data[6]) & (uint8_T)
                    (0x10U)) >> 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o7_c = result;
            }
          }

          /* --------------- START Unpacking signal 7 ------------------
           *  startBit                = 24
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.01
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX419h.Data[3]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX419h.Data[2]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.01;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o8_p = result;
            }
          }

          /* --------------- START Unpacking signal 8 ------------------
           *  startBit                = 40
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX419h.Data[5]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o9 = result;
            }
          }

          /* --------------- START Unpacking signal 9 ------------------
           *  startBit                = 50
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX419h.Data[6]) & (uint8_T)
                    (0x4U)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o10 = result;
            }
          }

          /* --------------- START Unpacking signal 10 ------------------
           *  startBit                = 49
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX419h.Data[6]) & (uint8_T)
                    (0x2U)) >> 1);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o11 = result;
            }
          }

          /* --------------- START Unpacking signal 11 ------------------
           *  startBit                = 48
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX419h.Data[6]) & (uint8_T)
                    (0x1U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o12 = result;
            }
          }

          /* --------------- START Unpacking signal 12 ------------------
           *  startBit                = 54
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX419h.Data[6]) & (uint8_T)
                    (0x40U)) >> 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o13 = result;
            }
          }
        }
      }
    }
  }

  /* DataTypeConversion: '<S24>/Convert ofVHSPI_OBCHLOutpI_A21' */
  if (PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o9 < 256.0) {
    if (PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o9 >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o9;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S24>/Convert ofVHSPI_OBCHLOutpI_A21' */

  /* Outputs for Atomic SubSystem: '<S1378>/signal validity checking' */
  /* DataTypeConversion: '<S1378>/Data Type Conversion' incorporates:
   *  Constant: '<S1316>/KISP_VldChkOBCInverterStsDec_cnt'
   *  Constant: '<S1316>/KISP_VldChkOBCInverterStsInc_cnt'
   *  Constant: '<S1316>/KISP_VldChkOBCInverterStsLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_j((real32_T)NISP_SigOut_i,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_il, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_kg, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_p3,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_p3);

  /* End of Outputs for SubSystem: '<S1378>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1378>/override signal' */
  /* DataTypeConversion: '<S1378>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1379>/TmpSignal ConversionAtSwitch1Inport3'
   */
  NISP_SigOut_j = (uint8_T)rtb_valid_signal_iw;

  /* End of Outputs for SubSystem: '<S1378>/override signal' */

  /* RelationalOperator: '<S70>/Compare' incorporates:
   *  Constant: '<S70>/Constant'
   */
  RelationalOperator = (NISP_SigOut_j == 255);

  /* Outputs for Atomic SubSystem: '<S1333>/signal validity checking' */
  /* DataTypeConversion: '<S1333>/Data Type Conversion' incorporates:
   *  Constant: '<S1309>/KISP_VldChkCDUChgCooltPlateOTPFltDec_cnt'
   *  Constant: '<S1309>/KISP_VldChkCDUChgCooltPlateOTPFltInc_cnt'
   *  Constant: '<S1309>/KISP_VldChkCDUChgCooltPlateOTPFltLim_cnt'
   *  DataTypeConversion: '<S24>/Convert ofVHSPI_OBCHLOutpI_A15'
   */
  PowerCtrolPro_sig_valid_check_f((real32_T)
    (PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o3_j != 0.0), 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_b4, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_jo,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_jo);

  /* End of Outputs for SubSystem: '<S1333>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1333>/override signal' */
  /* RelationalOperator: '<S72>/Compare' incorporates:
   *  DataTypeConversion: '<S1333>/Data Type Conversion1'
   *  SignalConversion: '<S1334>/TmpSignal ConversionAtSwitch1Inport3'
   */
  rtb_AND_a = (rtb_valid_signal_iw != 0.0F);

  /* End of Outputs for SubSystem: '<S1333>/override signal' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S21>/Convert ofVHSPI_OBCHLOutpI_A'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.OBC_HL_Output_Current;

  /* Outputs for Atomic SubSystem: '<S965>/signal validity checking' */
  /* Logic: '<S965>/Logical Operator1' incorporates:
   *  Constant: '<S146>/Bus Selector_SigVld3'
   *  Constant: '<S939>/KISP_OBCHLOutpIDft_A'
   *  Constant: '<S939>/KISP_VldChkOBCHLOutpIDec_cnt'
   *  Constant: '<S939>/KISP_VldChkOBCHLOutpIInc_cnt'
   *  Constant: '<S939>/KISP_VldChkOBCHLOutpILim_cnt'
   *  Constant: '<S965>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_hz, &rtb_valid_signal,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_kqj);

  /* End of Outputs for SubSystem: '<S965>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S951>/override signal' */
  /* RelationalOperator: '<S71>/Compare' incorporates:
   *  Constant: '<S71>/Constant'
   *  SignalConversion: '<S952>/TmpSignal ConversionAtSwitch1Inport3'
   */
  rtb_Compare_k = (rtb_valid_signal_em <= 12.4F);

  /* End of Outputs for SubSystem: '<S951>/override signal' */

  /* Chart: '<S73>/Chart1' incorporates:
   *  UnitDelay: '<S73>/Unit Delay2'
   */
  PowerCtrolProject1_S32K1_Chart1(rtb_Compare_k,
    PowerCtrolProject1_S32K14_DWork.UnitDelay2_DSTATE_c,
    &PowerCtrolProject1_S32K144_B.out_i2,
    &PowerCtrolProject1_S32K14_DWork.sf_Chart1);

  /* DataTypeConversion: '<S24>/Convert ofVHSPI_OBCHLOutpI_A14' */
  if (PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o2_c < 256.0) {
    if (PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o2_c >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o2_c;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S24>/Convert ofVHSPI_OBCHLOutpI_A14' */

  /* Outputs for Atomic SubSystem: '<S1339>/signal validity checking' */
  /* DataTypeConversion: '<S1339>/Data Type Conversion' incorporates:
   *  Constant: '<S1310>/KISP_VldChkOBCInverterStsDec_cnt'
   *  Constant: '<S1310>/KISP_VldChkOBCInverterStsInc_cnt'
   *  Constant: '<S1310>/KISP_VldChkOBCInverterStsLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_j((real32_T)NISP_SigOut_i,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_co, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_ju, &rtb_valid_signal_gem,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_a0x,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_a0x);

  /* End of Outputs for SubSystem: '<S1339>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1339>/override signal' */
  /* DataTypeConversion: '<S1339>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1340>/TmpSignal ConversionAtSwitch1Inport3'
   */
  NISP_SigOut_i = (uint8_T)rtb_valid_signal_gem;

  /* End of Outputs for SubSystem: '<S1339>/override signal' */

  /* Chart: '<S55>/Chart' incorporates:
   *  DataTypeConversion: '<S1333>/Data Type Conversion1'
   *  DataTypeConversion: '<S386>/Data Type Conversion1'
   *  Logic: '<S76>/Logical Operator'
   *  Logic: '<S76>/Logical Operator1'
   *  Logic: '<S77>/Logical Operator'
   *  Logic: '<S77>/Logical Operator1'
   *  SignalConversion: '<S1334>/TmpSignal ConversionAtSwitch1Inport3'
   *  SignalConversion: '<S387>/TmpSignal ConversionAtSwitch1Inport3'
   *  SignalConversion: '<S952>/TmpSignal ConversionAtSwitch1Inport3'
   *  SignalConversion: '<S966>/TmpSignal ConversionAtSwitch1Inport3'
   *  UnitDelay: '<S76>/Unit Delay'
   *  UnitDelay: '<S77>/Unit Delay'
   */
  if (PowerCtrolProject1_S32K14_DWork.temporalCounter_i1 < MAX_uint32_T) {
    PowerCtrolProject1_S32K14_DWork.temporalCounter_i1++;
  }

  if (PowerCtrolProject1_S32K14_DWork.is_active_c1_PowerCtrolProject1 == 0U) {
    PowerCtrolProject1_S32K14_DWork.is_active_c1_PowerCtrolProject1 = 1U;

    /* Timer = 0; */
    PowerCtrolProject1_S32K14_DWork.is_c1_PowerCtrolProject1_S32K14 =
      PowerCtrolProject1_S_IN_DCDCOff;
    PowerCtrolProject1_S32K14_DWork.temporalCounter_i1 = 0U;
    PowerCtrolProject1_S32K144_B.DCDCState = 0U;
    PowerCtrolProject1_S32K144_B.DCDC_KL15 = false;
    PowerCtrolProject1_S32K144_B.VCU_Command_state = 0U;
    PowerCtrolProject1_S32K144_B.FaultCounter = 0U;
  } else {
    switch (PowerCtrolProject1_S32K14_DWork.is_c1_PowerCtrolProject1_S32K14) {
     case PowerCtrolProject1_S_IN_DCDCOff:
      PowerCtrolProject1_S32K144_B.DCDC_KL15 = false;
      PowerCtrolProject1_S32K144_B.VCU_Command_state = 0U;

      /* Outputs for Atomic SubSystem: '<S951>/override signal' */
      /* %BMS必须正常工作中，高压上电完成 */
      if ((PowerCtrolProject1_S32K144_B.NISP_SigOut_a == 2) && ((rtb_Switch >
            (int32_T)400.0F) || (rtb_valid_signal_em > 13.5F)) &&
          (!PowerCtrolProject1_S32K144_B.VOSP_ChrgForbd_flg) &&
          (PowerCtrolProject1_S32K14_DWork.temporalCounter_i1 >= 100.0F)) {
        PowerCtrolProject1_S32K14_DWork.is_c1_PowerCtrolProject1_S32K14 =
          PowerCtrolProject1_S3_IN_DCDCOn;
        PowerCtrolProject1_S32K14_DWork.is_DCDCOn =
          PowerCtrolPro_IN_DCDCNormalWork;
        PowerCtrolProject1_S32K14_DWork.is_DCDCNormalWork =
          PowerCtrolProjec_IN_DCDCInitial;
        PowerCtrolProject1_S32K14_DWork.temporalCounter_i1 = 0U;
        PowerCtrolProject1_S32K144_B.DCDCState = 11U;
        PowerCtrolProject1_S32K144_B.DCDC_KL15 = true;
        PowerCtrolProject1_S32K144_B.DCDCOutU = 0.0F;

        /* Gain: '<S67>/Gain' */
        PowerCtrolProject1_S32K144_B.DCDCOutCurr = 0.0F;
        PowerCtrolProject1_S32K144_B.VCU_Command_state = MAX_uint8_T;
      }

      /* End of Outputs for SubSystem: '<S951>/override signal' */
      break;

     case PowerCtrolProject1_S3_IN_DCDCOn:
      /* Outputs for Atomic SubSystem: '<S386>/override signal' */
      if ((rtb_valid_signal_e5 != 0.0F) ||
          (PowerCtrolProject1_S32K144_B.NISP_SigOut_a != 2) ||
          PowerCtrolProject1_S32K144_B.VOSP_ChrgForbd_flg ||
          PowerCtrolProject1_S32K144_B.out_i ||
          PowerCtrolProject1_S32K144_B.out_i2) {
        PowerCtrolProject1_S32K14_DWork.is_DCDCNormalWork =
          PowerCtrol_IN_NO_ACTIVE_CHILD_h;
        PowerCtrolProject1_S32K14_DWork.is_DCDCOn =
          PowerCtrol_IN_NO_ACTIVE_CHILD_h;
        PowerCtrolProject1_S32K14_DWork.is_c1_PowerCtrolProject1_S32K14 =
          PowerCtrolProject_IN_DCDCPreOff;
        PowerCtrolProject1_S32K14_DWork.temporalCounter_i1 = 0U;
        PowerCtrolProject1_S32K144_B.DCDCState = 3U;
        PowerCtrolProject1_S32K144_B.VCU_Command_state = 0U;
        PowerCtrolProject1_S32K144_B.DCDCOutU = 0.0F;

        /* Gain: '<S67>/Gain' */
        PowerCtrolProject1_S32K144_B.DCDCOutCurr = 0.0F;
      } else {
        switch (PowerCtrolProject1_S32K14_DWork.is_DCDCOn) {
         case PowerCtrolPro_IN_DCDCFatalFault:
          PowerCtrolProject1_S32K144_B.VCU_Command_state = 0U;
          break;

         case PowerCtrolP_IN_DCDCFaultCounter:
          PowerCtrolProject1_S32K144_B.VCU_Command_state = 0U;
          PowerCtrolProject1_S32K144_B.VCU_DCDC_OutputVoltageRequest = 12.4F;
          if (PowerCtrolProject1_S32K144_B.FaultCounter >= 5) {
            PowerCtrolProject1_S32K14_DWork.is_DCDCOn =
              PowerCtrolPro_IN_DCDCFatalFault;
            PowerCtrolProject1_S32K144_B.DCDCState = 21U;
            PowerCtrolProject1_S32K144_B.VCU_Command_state = 0U;
            PowerCtrolProject1_S32K144_B.DCDCOutU = 0.0F;

            /* Gain: '<S67>/Gain' */
            PowerCtrolProject1_S32K144_B.DCDCOutCurr = 0.0F;
          } else {
            PowerCtrolProject1_S32K14_DWork.is_DCDCOn =
              PowerCtrolPro_IN_DCDCNormalWork;
            PowerCtrolProject1_S32K14_DWork.is_DCDCNormalWork =
              PowerCtrolProjec_IN_DCDCInitial;
            PowerCtrolProject1_S32K14_DWork.temporalCounter_i1 = 0U;
            PowerCtrolProject1_S32K144_B.DCDCState = 11U;
            PowerCtrolProject1_S32K144_B.DCDC_KL15 = true;
            PowerCtrolProject1_S32K144_B.DCDCOutU = 0.0F;

            /* Gain: '<S67>/Gain' */
            PowerCtrolProject1_S32K144_B.DCDCOutCurr = 0.0F;
            PowerCtrolProject1_S32K144_B.VCU_Command_state = MAX_uint8_T;
          }
          break;

         default:
          /* 0xFF的上升沿 */
          if ((RelationalOperator &&
               (!PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_dg)) ||
              (rtb_AND_a && (!PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_b)))
          {
            PowerCtrolProject1_S32K14_DWork.is_DCDCNormalWork =
              PowerCtrol_IN_NO_ACTIVE_CHILD_h;
            PowerCtrolProject1_S32K14_DWork.is_DCDCOn =
              PowerCtrolP_IN_DCDCFaultCounter;
            PowerCtrolProject1_S32K144_B.DCDCState = 20U;
            PowerCtrolProject1_S32K144_B.VCU_Command_state = 0U;
            PowerCtrolProject1_S32K144_B.DCDCOutU = 0.0F;

            /* Gain: '<S67>/Gain' */
            PowerCtrolProject1_S32K144_B.DCDCOutCurr = 0.0F;
            PowerCtrolProject1_S32K144_B.VCU_DCDC_OutputVoltageRequest = 12.4F;
            if ((NISP_SigOut_i != 3) && (NISP_SigOut_i != 18)) {
              i = PowerCtrolProject1_S32K144_B.FaultCounter + 1;
              if (i > 255) {
                i = 255;
              }

              PowerCtrolProject1_S32K144_B.FaultCounter = (uint8_T)i;
            }
          } else {
            switch (PowerCtrolProject1_S32K14_DWork.is_DCDCNormalWork) {
             case PowerCtrolProjec_IN_DCDCInitial:
              PowerCtrolProject1_S32K144_B.DCDC_KL15 = true;
              PowerCtrolProject1_S32K144_B.VCU_Command_state = MAX_uint8_T;

              /* Outputs for Atomic SubSystem: '<S1333>/override signal' */
              /* Outputs for Atomic SubSystem: '<S951>/override signal' */
              /* 等待DC-DC反馈状态为待机且无故障 */
              if ((NISP_SigOut_j == 2) && (!(rtb_valid_signal_iw != 0.0F)) &&
                  ((rtb_Switch > (int32_T)400.0F) || (rtb_valid_signal_em >
                    13.5F)) &&
                  (PowerCtrolProject1_S32K14_DWork.temporalCounter_i1 >= 300.0F))
              {
                PowerCtrolProject1_S32K14_DWork.is_DCDCNormalWork =
                  PowerCtrolProject1_IN_DCDCReady;
                PowerCtrolProject1_S32K14_DWork.temporalCounter_i1 = 0U;
                PowerCtrolProject1_S32K144_B.DCDCState = 12U;
                PowerCtrolProject1_S32K144_B.VCU_Command_state = 1U;
                PowerCtrolProject1_S32K144_B.VCU_DCDC_OutputVoltageRequest =
                  12.4F;

                /* VCU请求升压DC-DC进入准备状态
                   降低降压DC- DC输出电压 */
              }

              /* End of Outputs for SubSystem: '<S951>/override signal' */
              /* End of Outputs for SubSystem: '<S1333>/override signal' */
              break;

             case PowerCtrolProject1_IN_DCDCReady:
              PowerCtrolProject1_S32K144_B.VCU_Command_state = 1U;
              PowerCtrolProject1_S32K144_B.VCU_DCDC_OutputVoltageRequest = 12.4F;

              /* Outputs for Atomic SubSystem: '<S1333>/override signal' */
              /* Outputs for Atomic SubSystem: '<S965>/override signal' */
              /* 等待DC-DC反馈状态为准备且无故障 */
              if ((NISP_SigOut_j == 6) && (!(rtb_valid_signal_iw != 0.0F)) &&
                  (rtb_valid_signal <= 5.0F) &&
                  (PowerCtrolProject1_S32K14_DWork.temporalCounter_i1 >= 300.0F))
              {
                PowerCtrolProject1_S32K14_DWork.is_DCDCNormalWork =
                  PowerCtrolProject1_IN_DCDCStart;
                PowerCtrolProject1_S32K14_DWork.temporalCounter_i1 = 0U;
                PowerCtrolProject1_S32K144_B.DCDCState = 13U;
                PowerCtrolProject1_S32K144_B.VCU_DCDC_OutputVoltageRequest =
                  0.0F;
                PowerCtrolProject1_S32K144_B.VCU_Command_state = 2U;
                PowerCtrolProject1_S32K144_B.DCDCOutU = 382.0F;

                /* Gain: '<S67>/Gain' */
                PowerCtrolProject1_S32K144_B.DCDCOutCurr = 0.5F;
              }

              /* End of Outputs for SubSystem: '<S965>/override signal' */
              /* End of Outputs for SubSystem: '<S1333>/override signal' */
              break;

             case PowerCtrolProject1_S_IN_DCDCRun:
              PowerCtrolProject1_S32K144_B.DCDCOutU = 382.0F;
              if (rtb_Switch > (int32_T)400.0F) {
                /* Lookup_n-D: '<S67>/1-D Lookup Table' */
                /* DCDC_InputVoltage>KBDC_OBCHLOutUStrtThd_V ] */
                /* 行车充电模式 */
                rtb_valid_signal_em = look1_iflf_binlc((real32_T)rtb_Switch,
                  PowerCtrolProject1_S32K1_ConstP.uDLookupTable_bp01Data,
                  PowerCtrolProject1_S32K1_ConstP.uDLookupTable_tableData, 5U);

                /* Outputs for Atomic SubSystem: '<S411>/override signal' */
                /* MinMax: '<S67>/MinMax' incorporates:
                 *  SignalConversion: '<S412>/TmpSignal ConversionAtSwitch1Inport3'
                 */
                if ((rtb_valid_signal_co < rtb_valid_signal_em) || rtIsNaNF
                    (rtb_valid_signal_em)) {
                  rtb_valid_signal_em = rtb_valid_signal_co;
                }

                /* End of MinMax: '<S67>/MinMax' */
                /* End of Outputs for SubSystem: '<S411>/override signal' */

                /* Outputs for Atomic SubSystem: '<S182>/override signal' */
                /* Gain: '<S67>/Gain' incorporates:
                 *  Product: '<S67>/Divide'
                 *  SignalConversion: '<S183>/TmpSignal ConversionAtSwitch1Inport3'
                 */
                PowerCtrolProject1_S32K144_B.DCDCOutCurr = rtb_valid_signal_em /
                  rtb_valid_signal_nv * 1000.0F;

                /* End of Outputs for SubSystem: '<S182>/override signal' */

                /* Saturate: '<S67>/Saturation1' */
                if (PowerCtrolProject1_S32K144_B.DCDCOutCurr > 100.0F) {
                  /* Gain: '<S67>/Gain' */
                  PowerCtrolProject1_S32K144_B.DCDCOutCurr = 100.0F;
                } else {
                  if (PowerCtrolProject1_S32K144_B.DCDCOutCurr < 0.0F) {
                    /* Gain: '<S67>/Gain' */
                    PowerCtrolProject1_S32K144_B.DCDCOutCurr = 0.0F;
                  }
                }

                /* End of Saturate: '<S67>/Saturation1' */
                PowerCtrolProject1_S32K144_B.DCDCState = 15U;
              } else {
                /* Gain: '<S67>/Gain' */
                /* 太阳能充电模式 */
                PowerCtrolProject1_S32K144_B.DCDCOutCurr = 0.5F;
                PowerCtrolProject1_S32K144_B.DCDCState = 14U;
              }

              if (PowerCtrolProject1_S32K14_DWork.temporalCounter_i1 >= 600.0F)
              {
                /* 稳定运行清故障 */
                PowerCtrolProject1_S32K144_B.FaultCounter = 0U;
              }
              break;

             default:
              PowerCtrolProject1_S32K144_B.VCU_DCDC_OutputVoltageRequest = 0.0F;
              PowerCtrolProject1_S32K144_B.VCU_Command_state = 2U;
              if (PowerCtrolProject1_S32K14_DWork.temporalCounter_i1 >= 20.0F) {
                PowerCtrolProject1_S32K14_DWork.is_DCDCNormalWork =
                  PowerCtrolProject1_S_IN_DCDCRun;
                PowerCtrolProject1_S32K14_DWork.temporalCounter_i1 = 0U;
                PowerCtrolProject1_S32K144_B.DCDCOutU = 382.0F;
              }
              break;
            }
          }
          break;
        }
      }

      /* End of Outputs for SubSystem: '<S386>/override signal' */
      break;

     default:
      PowerCtrolProject1_S32K144_B.VCU_Command_state = 0U;
      if (PowerCtrolProject1_S32K14_DWork.temporalCounter_i1 >= 10.0F) {
        PowerCtrolProject1_S32K14_DWork.is_c1_PowerCtrolProject1_S32K14 =
          PowerCtrolProject1_S_IN_DCDCOff;
        PowerCtrolProject1_S32K14_DWork.temporalCounter_i1 = 0U;
        PowerCtrolProject1_S32K144_B.DCDCState = 0U;
        PowerCtrolProject1_S32K144_B.DCDC_KL15 = false;
        PowerCtrolProject1_S32K144_B.VCU_Command_state = 0U;
        PowerCtrolProject1_S32K144_B.FaultCounter = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S55>/Chart' */

  /* Outputs for Atomic SubSystem: '<S1655>/OSPProcessLmtChgILvl_enum' */
  /* Saturate: '<S1655>/Saturation' incorporates:
   *  SignalConversion: '<S1660>/TmpSignal ConversionAtSwitch1Inport3'
   */
  if (PowerCtrolProject1_S32K144_B.DCDCOutU > 420.0F) {
    PowerCtrolProject1_S32K144_B.VOSP_BDCDCOutU_V = 420.0F;
  } else if (PowerCtrolProject1_S32K144_B.DCDCOutU < 0.0F) {
    PowerCtrolProject1_S32K144_B.VOSP_BDCDCOutU_V = 0.0F;
  } else {
    PowerCtrolProject1_S32K144_B.VOSP_BDCDCOutU_V =
      PowerCtrolProject1_S32K144_B.DCDCOutU;
  }

  /* End of Saturate: '<S1655>/Saturation' */
  /* End of Outputs for SubSystem: '<S1655>/OSPProcessLmtChgILvl_enum' */

  /* Outputs for Atomic SubSystem: '<S1653>/OSPProcessSysRunAllw_flg' */
  /* Saturate: '<S1653>/Saturation' incorporates:
   *  SignalConversion: '<S1658>/TmpSignal ConversionAtSwitch1Inport3'
   */
  if (PowerCtrolProject1_S32K144_B.DCDCOutCurr > 7.0F) {
    PowerCtrolProject1_S32K144_B.VOSP_BDCDCOutCurr_A = 7.0F;
  } else if (PowerCtrolProject1_S32K144_B.DCDCOutCurr < 0.0F) {
    PowerCtrolProject1_S32K144_B.VOSP_BDCDCOutCurr_A = 0.0F;
  } else {
    PowerCtrolProject1_S32K144_B.VOSP_BDCDCOutCurr_A =
      PowerCtrolProject1_S32K144_B.DCDCOutCurr;
  }

  /* End of Saturate: '<S1653>/Saturation' */
  /* End of Outputs for SubSystem: '<S1653>/OSPProcessSysRunAllw_flg' */

  /* Product: '<S1591>/Product' */
  PowerCtrolProject1_S32K144_B.VOSP_BDCDCOutPwr_w =
    PowerCtrolProject1_S32K144_B.DCDCOutU *
    PowerCtrolProject1_S32K144_B.DCDCOutCurr;

  /* Saturate: '<S1654>/Saturation' */
  if (PowerCtrolProject1_S32K144_B.VOSP_BDCDCOutPwr_w > 2000.0F) {
    /* Product: '<S1591>/Product' */
    PowerCtrolProject1_S32K144_B.VOSP_BDCDCOutPwr_w = 2000.0F;
  } else {
    if (PowerCtrolProject1_S32K144_B.VOSP_BDCDCOutPwr_w < 0.0F) {
      /* Product: '<S1591>/Product' */
      PowerCtrolProject1_S32K144_B.VOSP_BDCDCOutPwr_w = 0.0F;
    }
  }

  /* End of Saturate: '<S1654>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S1657>/OSPProcessSysRunAllw_flg' */
  /* DataTypeConversion: '<S1657>/DataTypeConversion' incorporates:
   *  DataTypeConversion: '<S1662>/Data Type Conversion2'
   */
  PowerCtrolProject1_S32K144_B.VOSP_VCU2BDCDCCmdSt_enum =
    PowerCtrolProject1_S32K144_B.VCU_Command_state;

  /* End of Outputs for SubSystem: '<S1657>/OSPProcessSysRunAllw_flg' */

  /* Outputs for Atomic SubSystem: '<S3>/Turn Off Delay Time' */
  /* Outputs for Atomic SubSystem: '<S34>/EdgeFalling1' */
  /* Logic: '<S35>/AND' incorporates:
   *  Logic: '<S35>/OR1'
   *  UnitDelay: '<S35>/Unit Delay'
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  rtb_AND_jj = ((!PowerCtrolProject1_S32K14_DWork.UnitDelay2_34_DSTATE) &&
                PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_p);

  /* Update for UnitDelay: '<S35>/Unit Delay' incorporates:
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_p =
    PowerCtrolProject1_S32K14_DWork.UnitDelay2_34_DSTATE;

  /* End of Outputs for SubSystem: '<S34>/EdgeFalling1' */

  /* Switch: '<S34>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  MinMax: '<S34>/Minimum'
   *  Sum: '<S34>/Summation'
   *  UnitDelay: '<S34>/Unit Delay'
   */
  if (rtb_AND_jj) {
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_o = 30.0F;
  } else if (PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_o - 0.099999994F >
             0.0F) {
    /* MinMax: '<S34>/Minimum' incorporates:
     *  Constant: '<S3>/Constant'
     *  Sum: '<S34>/Summation'
     *  UnitDelay: '<S34>/Unit Delay'
     */
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_o -= 0.099999994F;
  } else {
    /* MinMax: '<S34>/Minimum' */
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_o = 0.0F;
  }

  /* End of Switch: '<S34>/Switch' */

  /* Outputs for Enabled SubSystem: '<S3>/HSPO_100ms' incorporates:
   *  EnablePort: '<S32>/Enable'
   */
  /* Logic: '<S34>/AND' incorporates:
   *  Constant: '<S34>/Constant Value2'
   *  RelationalOperator: '<S34>/Greater  Than'
   *  UnitDelay: '<S34>/Unit Delay'
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  if (PowerCtrolProject1_S32K14_DWork.UnitDelay2_34_DSTATE ||
      (PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_o > 0.0F)) {
    /* S-Function (scanpack): '<S32>/CANTXPack_VCU_180h' incorporates:
     *  Outport: '<Root>/CAN1TX180h'
     */
    /* S-Function (scanpack): '<S32>/CANTXPack_VCU_180h' */
    PowerCtrolProject1_S32K144_Y.CAN1TX180h.ID = 384U;
    PowerCtrolProject1_S32K144_Y.CAN1TX180h.Length = 8U;
    PowerCtrolProject1_S32K144_Y.CAN1TX180h.Extended = 0U;
    PowerCtrolProject1_S32K144_Y.CAN1TX180h.Remote = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[0] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[1] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[2] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[3] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[4] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[5] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[6] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 8
       *  length                  = 8
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        real32_T outValue = 0;

        {
          real32_T result = PowerCtrolProject1_S32K144_B.VOSP_ACChrgPwrF_kw;

          /* no scaling required */
          outValue = result;
        }

        {
          uint8_T packedValue;
          if (outValue > (real32_T)(255)) {
            packedValue = (uint8_T) 255;
          } else if (outValue < (real32_T)(0)) {
            packedValue = (uint8_T) 0;
          } else {
            packedValue = (uint8_T) (outValue);
          }

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[1] =
                PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[1] | (uint8_T)
                (packedValue);
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 4
       *  length                  = 4
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T)
            (PowerCtrolProject1_S32K144_B.VOSP_ChrgForbd_flg);

          /* no scaling required */
          packingValue = result;
        }

        {
          uint8_T packedValue;
          if (packingValue > (boolean_T)(15)) {
            packedValue = (uint8_T) 15;
          } else if (packingValue < (boolean_T)(0)) {
            packedValue = (uint8_T) 0;
          } else {
            packedValue = (uint8_T) (packingValue);
          }

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[0] =
                PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[0] | (uint8_T)
                ((uint8_T)((uint8_T)(packedValue & (uint8_T)0xFU) << 4));
            }
          }
        }
      }

      /* --------------- START Packing signal 2 ------------------
       *  startBit                = 16
       *  length                  = 8
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 0.1
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        real32_T outValue = 0;

        {
          real32_T result = PowerCtrolProject1_S32K144_B.VOSP_DCDCOutpUReq_V;

          /* no offset to apply */
          result = result * (1 / 0.1F);
          outValue = result;
        }

        {
          uint8_T packedValue;
          if (outValue > (real32_T)(255)) {
            packedValue = (uint8_T) 255;
          } else if (outValue < (real32_T)(0)) {
            packedValue = (uint8_T) 0;
          } else {
            packedValue = (uint8_T) (outValue);
          }

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[2] =
                PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[2] | (uint8_T)
                (packedValue);
            }
          }
        }
      }

      /* --------------- START Packing signal 3 ------------------
       *  startBit                = 0
       *  length                  = 4
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T)
            (PowerCtrolProject1_S32K1_ConstB.VOSP_DchaForbd_flg);

          /* no scaling required */
          packingValue = result;
        }

        {
          uint8_T packedValue;
          if (packingValue > (boolean_T)(15)) {
            packedValue = (uint8_T) 15;
          } else if (packingValue < (boolean_T)(0)) {
            packedValue = (uint8_T) 0;
          } else {
            packedValue = (uint8_T) (packingValue);
          }

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[0] =
                PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[0] | (uint8_T)
                ((uint8_T)(packedValue & (uint8_T)0xFU));
            }
          }
        }
      }

      /* --------------- START Packing signal 4 ------------------
       *  startBit                = 26
       *  length                  = 2
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.Switch2);

          /* no scaling required */
          packingValue = result;
        }

        {
          uint8_T packedValue;
          if (packingValue > (uint8_T)(3)) {
            packedValue = (uint8_T) 3;
          } else {
            packedValue = (uint8_T) (packingValue);
          }

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[3] =
                PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[3] | (uint8_T)
                ((uint8_T)((uint8_T)(packedValue & (uint8_T)0x3U) << 2));
            }
          }
        }
      }

      /* --------------- START Packing signal 5 ------------------
       *  startBit                = 28
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T)
            (PowerCtrolProject1_S32K1_ConstB.VOSP_EnChkInsulation_flg);

          /* no scaling required */
          packingValue = result;
        }

        {
          uint8_T packedValue;
          if (packingValue > (boolean_T)(1)) {
            packedValue = (uint8_T) 1;
          } else if (packingValue < (boolean_T)(0)) {
            packedValue = (uint8_T) 0;
          } else {
            packedValue = (uint8_T) (packingValue);
          }

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[3] =
                PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[3] | (uint8_T)
                ((uint8_T)((uint8_T)(packedValue & (uint8_T)0x1U) << 4));
            }
          }
        }
      }

      /* --------------- START Packing signal 6 ------------------
       *  startBit                = 32
       *  length                  = 8
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.Switch2_o);

          /* no scaling required */
          packingValue = result;
        }

        {
          uint8_T packedValue;
          packedValue = (uint8_T) (packingValue);

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[4] =
                PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[4] | (uint8_T)
                (packedValue);
            }
          }
        }
      }

      /* --------------- START Packing signal 7 ------------------
       *  startBit                = 24
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T)
            (PowerCtrolProject1_S32K144_B.VOSP_InverterRly_flg);

          /* no scaling required */
          packingValue = result;
        }

        {
          uint8_T packedValue;
          if (packingValue > (boolean_T)(1)) {
            packedValue = (uint8_T) 1;
          } else if (packingValue < (boolean_T)(0)) {
            packedValue = (uint8_T) 0;
          } else {
            packedValue = (uint8_T) (packingValue);
          }

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[3] =
                PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[3] | (uint8_T)
                ((uint8_T)(packedValue & (uint8_T)0x1U));
            }
          }
        }
      }

      /* --------------- START Packing signal 8 ------------------
       *  startBit                = 25
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T)
            (PowerCtrolProject1_S32K144_B.VOSP_SetInverter_flg);

          /* no scaling required */
          packingValue = result;
        }

        {
          uint8_T packedValue;
          if (packingValue > (boolean_T)(1)) {
            packedValue = (uint8_T) 1;
          } else if (packingValue < (boolean_T)(0)) {
            packedValue = (uint8_T) 0;
          } else {
            packedValue = (uint8_T) (packingValue);
          }

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[3] =
                PowerCtrolProject1_S32K144_Y.CAN1TX180h.Data[3] | (uint8_T)
                ((uint8_T)((uint8_T)(packedValue & (uint8_T)0x1U) << 1));
            }
          }
        }
      }
    }

    /* S-Function (scanpack): '<S32>/CANTXPack_VCU_190h' incorporates:
     *  Outport: '<Root>/CAN1TX190h'
     */
    /* S-Function (scanpack): '<S32>/CANTXPack_VCU_190h' */
    PowerCtrolProject1_S32K144_Y.CAN1TX190h.ID = 400U;
    PowerCtrolProject1_S32K144_Y.CAN1TX190h.Length = 8U;
    PowerCtrolProject1_S32K144_Y.CAN1TX190h.Extended = 0U;
    PowerCtrolProject1_S32K144_Y.CAN1TX190h.Remote = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX190h.Data[0] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX190h.Data[1] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX190h.Data[2] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX190h.Data[3] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX190h.Data[4] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX190h.Data[5] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX190h.Data[6] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX190h.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 0
       *  length                  = 2
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (PowerCtrolProject1_S32K1_ConstB.Switch2);

          /* no scaling required */
          packingValue = result;
        }

        {
          uint8_T packedValue;
          if (packingValue > (uint8_T)(3)) {
            packedValue = (uint8_T) 3;
          } else {
            packedValue = (uint8_T) (packingValue);
          }

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX190h.Data[0] =
                PowerCtrolProject1_S32K144_Y.CAN1TX190h.Data[0] | (uint8_T)
                ((uint8_T)(packedValue & (uint8_T)0x3U));
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 10
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T)
            (PowerCtrolProject1_S32K144_B.VOSP_BMSKL15_flg);

          /* no scaling required */
          packingValue = result;
        }

        {
          uint8_T packedValue;
          if (packingValue > (boolean_T)(1)) {
            packedValue = (uint8_T) 1;
          } else if (packingValue < (boolean_T)(0)) {
            packedValue = (uint8_T) 0;
          } else {
            packedValue = (uint8_T) (packingValue);
          }

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX190h.Data[1] =
                PowerCtrolProject1_S32K144_Y.CAN1TX190h.Data[1] | (uint8_T)
                ((uint8_T)((uint8_T)(packedValue & (uint8_T)0x1U) << 2));
            }
          }
        }
      }

      /* --------------- START Packing signal 2 ------------------
       *  startBit                = 8
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T)
            (PowerCtrolProject1_S32K144_B.VOSP_CDJQDSts_flg);

          /* no scaling required */
          packingValue = result;
        }

        {
          uint8_T packedValue;
          if (packingValue > (boolean_T)(1)) {
            packedValue = (uint8_T) 1;
          } else if (packingValue < (boolean_T)(0)) {
            packedValue = (uint8_T) 0;
          } else {
            packedValue = (uint8_T) (packingValue);
          }

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX190h.Data[1] =
                PowerCtrolProject1_S32K144_Y.CAN1TX190h.Data[1] | (uint8_T)
                ((uint8_T)(packedValue & (uint8_T)0x1U));
            }
          }
        }
      }

      /* --------------- START Packing signal 3 ------------------
       *  startBit                = 4
       *  length                  = 2
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.Switch2_h);

          /* no scaling required */
          packingValue = result;
        }

        {
          uint8_T packedValue;
          if (packingValue > (uint8_T)(3)) {
            packedValue = (uint8_T) 3;
          } else {
            packedValue = (uint8_T) (packingValue);
          }

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX190h.Data[0] =
                PowerCtrolProject1_S32K144_Y.CAN1TX190h.Data[0] | (uint8_T)
                ((uint8_T)((uint8_T)(packedValue & (uint8_T)0x3U) << 4));
            }
          }
        }
      }

      /* --------------- START Packing signal 4 ------------------
       *  startBit                = 2
       *  length                  = 2
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.Switch2_m);

          /* no scaling required */
          packingValue = result;
        }

        {
          uint8_T packedValue;
          if (packingValue > (uint8_T)(3)) {
            packedValue = (uint8_T) 3;
          } else {
            packedValue = (uint8_T) (packingValue);
          }

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX190h.Data[0] =
                PowerCtrolProject1_S32K144_Y.CAN1TX190h.Data[0] | (uint8_T)
                ((uint8_T)((uint8_T)(packedValue & (uint8_T)0x3U) << 2));
            }
          }
        }
      }

      /* --------------- START Packing signal 5 ------------------
       *  startBit                = 9
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T)
            (PowerCtrolProject1_S32K144_B.VOSP_OBCKL15_flg);

          /* no scaling required */
          packingValue = result;
        }

        {
          uint8_T packedValue;
          if (packingValue > (boolean_T)(1)) {
            packedValue = (uint8_T) 1;
          } else if (packingValue < (boolean_T)(0)) {
            packedValue = (uint8_T) 0;
          } else {
            packedValue = (uint8_T) (packingValue);
          }

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX190h.Data[1] =
                PowerCtrolProject1_S32K144_Y.CAN1TX190h.Data[1] | (uint8_T)
                ((uint8_T)((uint8_T)(packedValue & (uint8_T)0x1U) << 1));
            }
          }
        }
      }
    }

    /* S-Function (scanpack): '<S32>/CANTXPack_VCU_331h' incorporates:
     *  Outport: '<Root>/CAN1TX331h'
     */
    /* S-Function (scanpack): '<S32>/CANTXPack_VCU_331h' */
    PowerCtrolProject1_S32K144_Y.CAN1TX331h.ID = 817U;
    PowerCtrolProject1_S32K144_Y.CAN1TX331h.Length = 8U;
    PowerCtrolProject1_S32K144_Y.CAN1TX331h.Extended = 0U;
    PowerCtrolProject1_S32K144_Y.CAN1TX331h.Remote = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX331h.Data[0] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX331h.Data[1] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX331h.Data[2] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX331h.Data[3] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX331h.Data[4] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX331h.Data[5] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX331h.Data[6] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX331h.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 5
       *  length                  = 2
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T)
            (PowerCtrolProject1_S32K1_ConstB.Switch2_a);

          /* no scaling required */
          packingValue = result;
        }

        {
          uint8_T packedValue;
          if (packingValue > (uint8_T)(3)) {
            packedValue = (uint8_T) 3;
          } else {
            packedValue = (uint8_T) (packingValue);
          }

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX331h.Data[0] =
                PowerCtrolProject1_S32K144_Y.CAN1TX331h.Data[0] | (uint8_T)
                ((uint8_T)((uint8_T)(packedValue & (uint8_T)0x3U) << 5));
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 7
       *  length                  = 1
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T)
            (PowerCtrolProject1_S32K1_ConstB.VOSP_SysRunAllw_flg);

          /* no scaling required */
          packingValue = result;
        }

        {
          uint8_T packedValue;
          if (packingValue > (boolean_T)(1)) {
            packedValue = (uint8_T) 1;
          } else if (packingValue < (boolean_T)(0)) {
            packedValue = (uint8_T) 0;
          } else {
            packedValue = (uint8_T) (packingValue);
          }

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX331h.Data[0] =
                PowerCtrolProject1_S32K144_Y.CAN1TX331h.Data[0] | (uint8_T)
                ((uint8_T)((uint8_T)(packedValue & (uint8_T)0x1U) << 7));
            }
          }
        }
      }
    }

    /* S-Function (scanpack): '<S32>/CANTXPack_VCU_410h' incorporates:
     *  Outport: '<Root>/CAN1TX410h'
     */
    /* S-Function (scanpack): '<S32>/CANTXPack_VCU_410h' */
    PowerCtrolProject1_S32K144_Y.CAN1TX410h.ID = 1040U;
    PowerCtrolProject1_S32K144_Y.CAN1TX410h.Length = 8U;
    PowerCtrolProject1_S32K144_Y.CAN1TX410h.Extended = 0U;
    PowerCtrolProject1_S32K144_Y.CAN1TX410h.Remote = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[0] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[1] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[2] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[3] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[4] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[5] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[6] = 0;
    PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 48
       *  length                  = 8
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 0.1
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        real32_T outValue = 0;

        {
          real32_T result = PowerCtrolProject1_S32K1_ConstB.VOSP_InpUOffs_V;

          /* no offset to apply */
          result = result * (1 / 0.1F);
          outValue = result;
        }

        {
          uint8_T packedValue;
          if (outValue > (real32_T)(255)) {
            packedValue = (uint8_T) 255;
          } else if (outValue < (real32_T)(0)) {
            packedValue = (uint8_T) 0;
          } else {
            packedValue = (uint8_T) (outValue);
          }

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[6] =
                PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[6] | (uint8_T)
                (packedValue);
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 24
       *  length                  = 16
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 0.01
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        real32_T outValue = 0;

        {
          real32_T result = PowerCtrolProject1_S32K144_B.VOSP_BDCDCOutCurr_A;

          /* no offset to apply */
          result = result * (1 / 0.01F);
          outValue = result;
        }

        {
          uint16_T packedValue;
          if (outValue > (real32_T)(65535)) {
            packedValue = (uint16_T) 65535;
          } else if (outValue < (real32_T)(0)) {
            packedValue = (uint16_T) 0;
          } else {
            packedValue = (uint16_T) (outValue);
          }

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[3] =
                PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[3] | (uint8_T)
                ((uint16_T)(packedValue & (uint16_T)0xFFU));
              PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[2] =
                PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[2] | (uint8_T)
                ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
            }
          }
        }
      }

      /* --------------- START Packing signal 2 ------------------
       *  startBit                = 40
       *  length                  = 16
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 10.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        real32_T outValue = 0;

        {
          real32_T result = PowerCtrolProject1_S32K144_B.VOSP_BDCDCOutPwr_w;

          /* no offset to apply */
          result = result * (1 / 10.0F);
          outValue = result;
        }

        {
          uint16_T packedValue;
          if (outValue > (real32_T)(65535)) {
            packedValue = (uint16_T) 65535;
          } else if (outValue < (real32_T)(0)) {
            packedValue = (uint16_T) 0;
          } else {
            packedValue = (uint16_T) (outValue);
          }

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[5] =
                PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[5] | (uint8_T)
                ((uint16_T)(packedValue & (uint16_T)0xFFU));
              PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[4] =
                PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[4] | (uint8_T)
                ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
            }
          }
        }
      }

      /* --------------- START Packing signal 3 ------------------
       *  startBit                = 8
       *  length                  = 16
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 0.01
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        real32_T outValue = 0;

        {
          real32_T result = PowerCtrolProject1_S32K144_B.VOSP_BDCDCOutU_V;

          /* no offset to apply */
          result = result * (1 / 0.01F);
          outValue = result;
        }

        {
          uint16_T packedValue;
          if (outValue > (real32_T)(65535)) {
            packedValue = (uint16_T) 65535;
          } else if (outValue < (real32_T)(0)) {
            packedValue = (uint16_T) 0;
          } else {
            packedValue = (uint16_T) (outValue);
          }

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[1] =
                PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[1] | (uint8_T)
                ((uint16_T)(packedValue & (uint16_T)0xFFU));
              PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[0] =
                PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[0] | (uint8_T)
                ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
            }
          }
        }
      }

      /* --------------- START Packing signal 4 ------------------
       *  startBit                = 56
       *  length                  = 8
       *  desiredSignalByteLayout = BIGENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        uint32_T packingValue = 0;

        {
          uint32_T result = (uint32_T)
            (PowerCtrolProject1_S32K144_B.VOSP_VCU2BDCDCCmdSt_enum);

          /* no scaling required */
          packingValue = result;
        }

        {
          uint8_T packedValue;
          packedValue = (uint8_T) (packingValue);

          {
            {
              PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[7] =
                PowerCtrolProject1_S32K144_Y.CAN1TX410h.Data[7] | (uint8_T)
                (packedValue);
            }
          }
        }
      }
    }
  }

  /* End of Logic: '<S34>/AND' */
  /* End of Outputs for SubSystem: '<S3>/HSPO_100ms' */
  /* End of Outputs for SubSystem: '<S3>/Turn Off Delay Time' */

  /* BusCreator: '<Root>/Bus Creator13' incorporates:
   *  Constant: '<Root>/Constant47'
   *  Constant: '<Root>/Constant50'
   *  Inport: '<Root>/In34'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX231h.Extended =
    PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic11;
  PowerCtrolProject1_S32K144_B.CAN1RX231h.Length = can_rx_msg.CAN1_DLC231h;
  PowerCtrolProject1_S32K144_B.CAN1RX231h.Remote = 0U;
  PowerCtrolProject1_S32K144_B.CAN1RX231h.Error = 0U;

  /* Switch: '<Root>/Switch11' */
  if (PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic11 != 0) {
    /* BusCreator: '<Root>/Bus Creator13' incorporates:
     *  Constant: '<Root>/Constant51'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX231h.ID = 0U;
  } else {
    /* BusCreator: '<Root>/Bus Creator13' incorporates:
     *  Inport: '<Root>/In35'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX231h.ID = can_rx_msg.CAN1_StdId231h;
  }

  /* End of Switch: '<Root>/Switch11' */

  /* BusCreator: '<Root>/Bus Creator13' incorporates:
   *  Constant: '<Root>/Constant48'
   *  Inport: '<Root>/In36'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX231h.Timestamp = 0.0;
  for (i = 0; i < 8; i++) {
    PowerCtrolProject1_S32K144_B.CAN1RX231h.Data[i] = can_rx_msg.CAN1_Data231h[i];
  }

  /* S-Function (scanunpack): '<S17>/CANRXUnPack_BMS_231h' */
  {
    /* S-Function (scanunpack): '<S17>/CANRXUnPack_BMS_231h' */
    if ((8 == PowerCtrolProject1_S32K144_B.CAN1RX231h.Length) &&
        (PowerCtrolProject1_S32K144_B.CAN1RX231h.ID != INVALID_CAN_ID) ) {
      if ((561 == PowerCtrolProject1_S32K144_B.CAN1RX231h.ID) && (0U ==
           PowerCtrolProject1_S32K144_B.CAN1RX231h.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 24
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX231h.Data[3]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX231h.Data[2]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Charging_duration = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX231h.Data[4]) & (uint8_T)
                    (0x3U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Charging_signal_CC2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 40
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX231h.Data[5]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_DC_charging_signal = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 8
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX231h.Data[1]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX231h.Data[0]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Full_chargingtime = result;
            }
          }
        }
      }
    }
  }

  /* DataTypeConversion: '<S17>/Convert ofVHSPI_BMSChrgSigCC2_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Charging_signal_CC2 < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Charging_signal_CC2 >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Charging_signal_CC2;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S17>/Convert ofVHSPI_BMSChrgSigCC2_enum' */

  /* Outputs for Atomic SubSystem: '<S855>/signal validity checking' */
  /* DataTypeConversion: '<S855>/Data Type Conversion' incorporates:
   *  Constant: '<S143>/Bus Selector_SigVld3'
   *  Constant: '<S837>/KISP_VldChkBMSChrgSigCC2Dec_cnt'
   *  Constant: '<S837>/KISP_VldChkBMSChrgSigCC2Inc_cnt'
   *  Constant: '<S837>/KISP_VldChkBMSChrgSigCC2Lim_cnt'
   *  Constant: '<S855>/False'
   *  Logic: '<S855>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_nd, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_dw, &rtb_valid_signal_em,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_li);

  /* End of Outputs for SubSystem: '<S855>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S392>/signal validity checking' */
  /* DataTypeConversion: '<S392>/Data Type Conversion' incorporates:
   *  Constant: '<S311>/KISP_VldChkBMSChrgConnStsDec_cnt'
   *  Constant: '<S311>/KISP_VldChkBMSChrgConnStsInc_cnt'
   *  Constant: '<S311>/KISP_VldChkBMSChrgConnStsLim_cnt'
   *  DataTypeConversion: '<S9>/Data Type Conversion1'
   */
  PowerCtrolPro_sig_valid_check_f((real32_T)
    (PowerCtrolProject1_S32K144_B.CANRXUnPack_BMS_204h_o13 != 0.0), 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_ft, &rtb_valid_signal_co,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_m3,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_m3);

  /* End of Outputs for SubSystem: '<S392>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  Constant: '<S25>/Constant19'
   *  DataTypeConversion: '<S25>/Convert ofVHSPI_InverterEna_flg13'
   *  Lookup_n-D: '<S26>/1-D'
   */
  PowerCtrolProject1_S32K144_B.y = look1_iflf_binlx(0.0F,
    PowerCtrolProject1_S32K1_ConstP.uD_bp01Data,
    PowerCtrolProject1_S32K1_ConstP.pooled18, 32U);

  /* Outputs for Atomic SubSystem: '<S25>/Limiter2' */
  /* Switch: '<S31>/Switch1' incorporates:
   *  Constant: '<S25>/Constant5'
   *  RelationalOperator: '<S31>/Relational Operator'
   */
  if (100.0F < PowerCtrolProject1_S32K144_B.y) {
    /* Switch: '<S107>/Switch' */
    PowerCtrolProject1_S32K144_B.y = 100.0F;
  }

  /* End of Switch: '<S31>/Switch1' */

  /* Switch: '<S31>/Switch' incorporates:
   *  Constant: '<S25>/Constant6'
   *  RelationalOperator: '<S31>/Relational Operator1'
   */
  if (!(PowerCtrolProject1_S32K144_B.y > -100.0F)) {
    /* Switch: '<S107>/Switch' */
    PowerCtrolProject1_S32K144_B.y = -100.0F;
  }

  /* End of Switch: '<S31>/Switch' */
  /* End of Outputs for SubSystem: '<S25>/Limiter2' */

  /* Outputs for Atomic SubSystem: '<S1510>/signal validity checking' */
  /* Constant: '<S1475>/KISP_WhlSpdReLeDft_kph' incorporates:
   *  Constant: '<S1475>/KISP_VldChkWhlSpdReLeDec_cnt'
   *  Constant: '<S1475>/KISP_VldChkWhlSpdReLeInc_cnt'
   *  Constant: '<S1475>/KISP_VldChkWhlSpdReLeLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_k(PowerCtrolProject1_S32K144_B.y, 0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_g, &rtb_valid_signal_nv,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_fq,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_fq);

  /* End of Outputs for SubSystem: '<S1510>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1517>/signal validity checking' */
  /* DataTypeConversion: '<S1517>/Data Type Conversion' incorporates:
   *  Constant: '<S1476>/KISP_VldChkACPwrFocModDec_cnt'
   *  Constant: '<S1476>/KISP_VldChkACPwrFocModInc_cnt'
   *  Constant: '<S1476>/KISP_VldChkACPwrFocModLim_cnt'
   *  DataTypeConversion: '<S25>/Convert ofVHSPI_InverterEna_flg8'
   */
  PowerCtrolPro_sig_valid_check_f((real32_T)
    (PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o3 != 0.0), 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_p, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_ga,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ga);

  /* End of Outputs for SubSystem: '<S1517>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S56>/Debounce' */
  /* Chart: '<S80>/DebounceState' incorporates:
   *  Constant: '<S56>/Constant32'
   *  Constant: '<S56>/Constant33'
   *  Constant: '<S80>/Constant2'
   *  DataTypeConversion: '<S1517>/Data Type Conversion1'
   *  DataTypeConversion: '<S80>/DataTypeConversion2'
   *  SignalConversion: '<S1518>/TmpSignal ConversionAtSwitch1Inport3'
   */
  if (PowerCtrolProject1_S32K14_DWork.is_active_c2_ecartronic_lib == 0U) {
    PowerCtrolProject1_S32K14_DWork.is_active_c2_ecartronic_lib = 1U;
    PowerCtrolProject1_S32K14_DWork.is_c2_ecartronic_lib =
      PowerCtrolProject1_S32K1_IN_Low;
    PowerCtrolProject1_S32K144_B.Out = false;
  } else {
    switch (PowerCtrolProject1_S32K14_DWork.is_c2_ecartronic_lib) {
     case PowerCtrolProject1_S32K_IN_High:
      PowerCtrolProject1_S32K144_B.Out = true;

      /* Outputs for Atomic SubSystem: '<S1517>/override signal' */
      if (!(rtb_valid_signal_iw != 0.0F)) {
        PowerCtrolProject1_S32K14_DWork.is_c2_ecartronic_lib =
          PowerCtrolProject1__IN_High2Low;
        PowerCtrolProject1_S32K14_DWork.Local_Time_S = 0.1F;
      }

      /* End of Outputs for SubSystem: '<S1517>/override signal' */
      break;

     case PowerCtrolProject1__IN_High2Low:
      /* Outputs for Atomic SubSystem: '<S1517>/override signal' */
      if (rtb_valid_signal_iw != 0.0F) {
        PowerCtrolProject1_S32K14_DWork.is_c2_ecartronic_lib =
          PowerCtrolProject1_S32K_IN_High;
        PowerCtrolProject1_S32K144_B.Out = true;
      } else if (PowerCtrolProject1_S32K14_DWork.Local_Time_S >= 2.0F) {
        PowerCtrolProject1_S32K14_DWork.is_c2_ecartronic_lib =
          PowerCtrolProject1_S32K1_IN_Low;
        PowerCtrolProject1_S32K144_B.Out = false;
      } else {
        PowerCtrolProject1_S32K14_DWork.Local_Time_S += 0.1F;
      }

      /* End of Outputs for SubSystem: '<S1517>/override signal' */
      break;

     case PowerCtrolProject1_S32K1_IN_Low:
      PowerCtrolProject1_S32K144_B.Out = false;

      /* Outputs for Atomic SubSystem: '<S1517>/override signal' */
      if (rtb_valid_signal_iw != 0.0F) {
        PowerCtrolProject1_S32K14_DWork.is_c2_ecartronic_lib =
          PowerCtrolProject1__IN_Low2High;
        PowerCtrolProject1_S32K14_DWork.Local_Time_S = 0.1F;
      }

      /* End of Outputs for SubSystem: '<S1517>/override signal' */
      break;

     default:
      /* Outputs for Atomic SubSystem: '<S1517>/override signal' */
      if (!(rtb_valid_signal_iw != 0.0F)) {
        PowerCtrolProject1_S32K14_DWork.is_c2_ecartronic_lib =
          PowerCtrolProject1_S32K1_IN_Low;
        PowerCtrolProject1_S32K144_B.Out = false;
      } else if (PowerCtrolProject1_S32K14_DWork.Local_Time_S >= 2.0F) {
        PowerCtrolProject1_S32K14_DWork.is_c2_ecartronic_lib =
          PowerCtrolProject1_S32K_IN_High;
        PowerCtrolProject1_S32K144_B.Out = true;
      } else {
        PowerCtrolProject1_S32K14_DWork.Local_Time_S += 0.1F;
      }

      /* End of Outputs for SubSystem: '<S1517>/override signal' */
      break;
    }
  }

  /* End of Chart: '<S80>/DebounceState' */
  /* End of Outputs for SubSystem: '<S56>/Debounce' */

  /* DataTypeConversion: '<S20>/Convert ofVHSPI_DCDCSts_enum' */
  if (PowerCtrolProject1_S32K144_B.DCDC_Status < 256.0) {
    if (PowerCtrolProject1_S32K144_B.DCDC_Status >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.DCDC_Status;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S20>/Convert ofVHSPI_DCDCSts_enum' */

  /* Outputs for Atomic SubSystem: '<S898>/signal validity checking' */
  /* DataTypeConversion: '<S898>/Data Type Conversion' incorporates:
   *  Constant: '<S884>/KISP_VldChkDCDCStsDec_cnt'
   *  Constant: '<S884>/KISP_VldChkDCDCStsInc_cnt'
   *  Constant: '<S884>/KISP_VldChkDCDCStsLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_j((real32_T)NISP_SigOut_i,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_ad, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_mh, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_kp,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_kp);

  /* End of Outputs for SubSystem: '<S898>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S898>/override signal' */
  /* DataTypeConversion: '<S898>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S899>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_d = (uint8_T)rtb_valid_signal_iw;

  /* End of Outputs for SubSystem: '<S898>/override signal' */

  /* Switch: '<S64>/Switch' */
  if (PowerCtrolProject1_S32K1_ConstB.Logical1_g) {
    /* DataTypeConversion: '<S1594>/DataTypeConversion' incorporates:
     *  Constant: '<S64>/dummy_MorEna_C'
     */
    PowerCtrolProject1_S32K144_B.VOSP_ACOutRlyCtrlr_flg = false;
  } else {
    /* Outputs for Atomic SubSystem: '<S386>/override signal' */
    /* DataTypeConversion: '<S1594>/DataTypeConversion' incorporates:
     *  DataTypeConversion: '<S386>/Data Type Conversion1'
     *  Logic: '<S56>/Logical12'
     *  Logic: '<S56>/Logical9'
     *  SignalConversion: '<S387>/TmpSignal ConversionAtSwitch1Inport3'
     *  Switch: '<S56>/Switch5'
     *  UnitDelay: '<S5>/Unit Delay2'
     */
    PowerCtrolProject1_S32K144_B.VOSP_ACOutRlyCtrlr_flg =
      ((!(rtb_valid_signal_e5 != 0.0F)) && (!rtb_AND_bg) &&
       PowerCtrolProject1_S32K14_DWork.UnitDelay2_34_DSTATE &&
       PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg);

    /* End of Outputs for SubSystem: '<S386>/override signal' */
  }

  /* End of Switch: '<S64>/Switch' */

  /* Outputs for Atomic SubSystem: '<S1543>/override signal' */
  /* Switch: '<S33>/Switch1' incorporates:
   *  Constant: '<S33>/Constant4'
   *  Constant: '<S33>/Constant5'
   *  DataTypeConversion: '<S1543>/Data Type Conversion1'
   *  DataTypeConversion: '<S855>/Data Type Conversion1'
   *  Logic: '<S33>/AND'
   *  RelationalOperator: '<S33>/Equal'
   *  RelationalOperator: '<S33>/Relational Operator'
   *  SignalConversion: '<S1544>/TmpSignal ConversionAtSwitch1Inport3'
   *  SignalConversion: '<S856>/TmpSignal ConversionAtSwitch1Inport3'
   */
  if (rtb_valid_signal_pd != 0.0F) {
    PowerCtrolProject1_S32K144_B.Switch1 = (rtb_valid_signal_pd != 0.0F);
  } else {
    /* Outputs for Atomic SubSystem: '<S855>/override signal' */
    PowerCtrolProject1_S32K144_B.Switch1 = ((NISP_SigOut_k != 0) || ((uint8_T)
      rtb_valid_signal_em != 0));

    /* End of Outputs for SubSystem: '<S855>/override signal' */
  }

  /* End of Switch: '<S33>/Switch1' */
  /* End of Outputs for SubSystem: '<S1543>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1595>/OSPProcessCDJQDSts_flg' */
  /* DataTypeConversion: '<S1595>/DataTypeConversion' incorporates:
   *  DataTypeConversion: '<S1603>/Data Type Conversion2'
   */
  PowerCtrolProject1_S32K144_B.VOSP_BDCDCKL15_flg =
    PowerCtrolProject1_S32K144_B.DCDC_KL15;

  /* End of Outputs for SubSystem: '<S1595>/OSPProcessCDJQDSts_flg' */

  /* Outputs for Atomic SubSystem: '<S58>/Hysteresis' */
  /* Outputs for Atomic SubSystem: '<S1510>/override signal' */
  /* Switch: '<S103>/Switch1' incorporates:
   *  Constant: '<S103>/Constant Value'
   *  Constant: '<S58>/Constant'
   *  Constant: '<S58>/Constant1'
   *  RelationalOperator: '<S103>/Greater  Than'
   *  RelationalOperator: '<S103>/Greater  Than1'
   *  SignalConversion: '<S1511>/TmpSignal ConversionAtSwitch1Inport3'
   *  UnitDelay: '<S103>/Unit Delay'
   */
  if (rtb_valid_signal_nv > 50.0F) {
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_nw = true;
  } else {
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_nw =
      ((!(rtb_valid_signal_nv < 45.0F)) &&
       PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_nw);
  }

  /* End of Switch: '<S103>/Switch1' */
  /* End of Outputs for SubSystem: '<S1510>/override signal' */
  /* End of Outputs for SubSystem: '<S58>/Hysteresis' */

  /* Outputs for Atomic SubSystem: '<S392>/override signal' */
  /* Outputs for Atomic SubSystem: '<S386>/override signal' */
  /* DataTypeConversion: '<S1597>/DataTypeConversion' incorporates:
   *  Constant: '<S101>/Constant'
   *  DataTypeConversion: '<S386>/Data Type Conversion1'
   *  DataTypeConversion: '<S392>/Data Type Conversion1'
   *  Logic: '<S58>/Logical Operator'
   *  Logic: '<S58>/Logical Operator1'
   *  Logic: '<S58>/Logical Operator2'
   *  RelationalOperator: '<S101>/Compare'
   *  SignalConversion: '<S387>/TmpSignal ConversionAtSwitch1Inport3'
   *  SignalConversion: '<S393>/TmpSignal ConversionAtSwitch1Inport3'
   *  UnitDelay: '<S103>/Unit Delay'
   */
  PowerCtrolProject1_S32K144_B.VOSP_ElecFanOn_flg = ((((rtb_valid_signal_co !=
    0.0F) && (PowerCtrolProject1_S32K144_B.NISP_SigOut_a == 1)) ||
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_nw) &&
    (!(rtb_valid_signal_e5 != 0.0F)));

  /* End of Outputs for SubSystem: '<S386>/override signal' */
  /* End of Outputs for SubSystem: '<S392>/override signal' */

  /* Outputs for Atomic SubSystem: '<S56>/Turn On Delay Time5' */
  /* Outputs for Atomic SubSystem: '<S89>/EdgeRising' */
  /* Logic: '<S97>/AND' incorporates:
   *  DataTypeConversion: '<S56>/Data Type Conversion3'
   *  Logic: '<S97>/OR1'
   *  UnitDelay: '<S97>/Unit Delay'
   */
  rtb_AND_bg = ((NISP_SigOut_l != 0) &&
                (!PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_gn));

  /* Update for UnitDelay: '<S97>/Unit Delay' incorporates:
   *  DataTypeConversion: '<S56>/Data Type Conversion3'
   */
  PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_gn = (NISP_SigOut_l != 0);

  /* End of Outputs for SubSystem: '<S89>/EdgeRising' */

  /* Switch: '<S89>/Switch1' incorporates:
   *  Constant: '<S56>/Constant74'
   *  Constant: '<S89>/Constant Value1'
   *  DataTypeConversion: '<S56>/Data Type Conversion3'
   *  Logic: '<S89>/OR'
   *  Logic: '<S89>/OR1'
   *  MinMax: '<S89>/Minimum'
   *  Sum: '<S89>/Summation'
   *  UnitDelay: '<S89>/Unit Delay'
   */
  if ((NISP_SigOut_l == 0) || rtb_AND_bg) {
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_k = 0.0F;
  } else if ((3.0F < 0.099999994F +
              PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_k) || rtIsNaNF
             (0.099999994F + PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_k))
  {
    /* MinMax: '<S89>/Minimum' */
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_k = 3.0F;
  } else {
    /* MinMax: '<S89>/Minimum' incorporates:
     *  Constant: '<S56>/Constant74'
     *  Sum: '<S89>/Summation'
     *  UnitDelay: '<S89>/Unit Delay'
     */
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_k += 0.099999994F;
  }

  /* End of Switch: '<S89>/Switch1' */

  /* Logic: '<S89>/AND' incorporates:
   *  Constant: '<S56>/Constant75'
   *  DataTypeConversion: '<S56>/Data Type Conversion3'
   *  RelationalOperator: '<S89>/Greater  Than'
   *  UnitDelay: '<S89>/Unit Delay'
   */
  PowerCtrolProject1_S32K144_B.VOSP_ElecLockPWM_flg = ((NISP_SigOut_l != 0) &&
    (PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_k >= 3.0F));

  /* End of Outputs for SubSystem: '<S56>/Turn On Delay Time5' */

  /* Switch: '<S56>/Switch9' incorporates:
   *  Constant: '<S56>/Constant31'
   *  RelationalOperator: '<S56>/Comparison10'
   *  RelationalOperator: '<S56>/Comparison7'
   *  Switch: '<S56>/Switch12'
   */
  if (!PowerCtrolProject1_S32K144_B.VOSP_ElecLockPWM_flg) {
    /* Switch: '<S56>/Switch10' incorporates:
     *  Constant: '<S56>/Constant26'
     *  Constant: '<S56>/Constant27'
     *  RelationalOperator: '<S56>/Comparison8'
     */
    if (PowerCtrolProject1_S32K144_B.Out) {
      NISP_SigOut_k = 2U;
    } else {
      NISP_SigOut_k = 0U;
    }

    /* End of Switch: '<S56>/Switch10' */
  } else if (!PowerCtrolProject1_S32K144_B.Out) {
    /* Switch: '<S56>/Switch12' incorporates:
     *  Constant: '<S56>/Constant30'
     */
    NISP_SigOut_k = 1U;
  } else {
    NISP_SigOut_k = 3U;
  }

  /* End of Switch: '<S56>/Switch9' */

  /* RelationalOperator: '<S56>/Comparison19' incorporates:
   *  Constant: '<S56>/Constant47'
   */
  rtb_AND_bg = (NISP_SigOut_k == 3);

  /* Outputs for Atomic SubSystem: '<S56>/Turn On Delay Time2' */
  /* Outputs for Atomic SubSystem: '<S86>/EdgeRising' */
  /* Logic: '<S94>/AND' incorporates:
   *  Logic: '<S94>/OR1'
   *  UnitDelay: '<S94>/Unit Delay'
   */
  rtb_AND_jj = (rtb_AND_bg &&
                (!PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_kq));

  /* Update for UnitDelay: '<S94>/Unit Delay' */
  PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_kq = rtb_AND_bg;

  /* End of Outputs for SubSystem: '<S86>/EdgeRising' */

  /* Switch: '<S86>/Switch1' incorporates:
   *  Constant: '<S56>/Constant49'
   *  Constant: '<S86>/Constant Value1'
   *  Logic: '<S86>/OR'
   *  Logic: '<S86>/OR1'
   *  MinMax: '<S86>/Minimum'
   *  Sum: '<S86>/Summation'
   *  UnitDelay: '<S86>/Unit Delay'
   */
  if ((!rtb_AND_bg) || rtb_AND_jj) {
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_a = 0.0F;
  } else if ((2.5F < 0.099999994F +
              PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_a) || rtIsNaNF
             (0.099999994F + PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_a))
  {
    /* MinMax: '<S86>/Minimum' */
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_a = 2.5F;
  } else {
    /* MinMax: '<S86>/Minimum' incorporates:
     *  Constant: '<S56>/Constant49'
     *  Sum: '<S86>/Summation'
     *  UnitDelay: '<S86>/Unit Delay'
     */
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_a += 0.099999994F;
  }

  /* End of Switch: '<S86>/Switch1' */
  /* End of Outputs for SubSystem: '<S56>/Turn On Delay Time2' */

  /* RelationalOperator: '<S56>/Comparison20' incorporates:
   *  Constant: '<S56>/Constant48'
   */
  rtb_AND_jj = (NISP_SigOut_k == 0);

  /* Outputs for Atomic SubSystem: '<S56>/Turn On Delay Time3' */
  /* Outputs for Atomic SubSystem: '<S87>/EdgeRising' */
  /* Logic: '<S95>/AND' incorporates:
   *  Logic: '<S95>/OR1'
   *  UnitDelay: '<S95>/Unit Delay'
   */
  rtb_AND_g = (rtb_AND_jj &&
               (!PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_j));

  /* Update for UnitDelay: '<S95>/Unit Delay' */
  PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_j = rtb_AND_jj;

  /* End of Outputs for SubSystem: '<S87>/EdgeRising' */

  /* Switch: '<S87>/Switch1' incorporates:
   *  Constant: '<S56>/Constant50'
   *  Constant: '<S87>/Constant Value1'
   *  Logic: '<S87>/OR'
   *  Logic: '<S87>/OR1'
   *  MinMax: '<S87>/Minimum'
   *  Sum: '<S87>/Summation'
   *  UnitDelay: '<S87>/Unit Delay'
   */
  if ((!rtb_AND_jj) || rtb_AND_g) {
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_i = 0.0F;
  } else if ((2.5F < 0.099999994F +
              PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_i) || rtIsNaNF
             (0.099999994F + PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_i))
  {
    /* MinMax: '<S87>/Minimum' */
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_i = 2.5F;
  } else {
    /* MinMax: '<S87>/Minimum' incorporates:
     *  Constant: '<S56>/Constant50'
     *  Sum: '<S87>/Summation'
     *  UnitDelay: '<S87>/Unit Delay'
     */
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_i += 0.099999994F;
  }

  /* End of Switch: '<S87>/Switch1' */
  /* End of Outputs for SubSystem: '<S56>/Turn On Delay Time3' */

  /* Switch: '<S56>/Switch15' incorporates:
   *  Constant: '<S56>/Constant43'
   *  Constant: '<S56>/Constant45'
   *  Constant: '<S56>/Constant51'
   *  Constant: '<S56>/Constant52'
   *  Logic: '<S86>/AND'
   *  Logic: '<S87>/AND'
   *  RelationalOperator: '<S56>/Comparison17'
   *  RelationalOperator: '<S56>/Comparison18'
   *  RelationalOperator: '<S86>/Greater  Than'
   *  RelationalOperator: '<S87>/Greater  Than'
   *  Switch: '<S56>/Switch16'
   *  Switch: '<S56>/Switch17'
   *  Switch: '<S56>/Switch18'
   *  UnitDelay: '<S86>/Unit Delay'
   *  UnitDelay: '<S87>/Unit Delay'
   */
  if (NISP_SigOut_k == 1) {
    /* Product: '<S1599>/Product' incorporates:
     *  Constant: '<S56>/Constant44'
     *  Switch: '<S1608>/Switch2'
     */
    PowerCtrolProject1_S32K144_B.VOSP_ElecLockPWM_pct = 0.0F;
  } else if (NISP_SigOut_k == 2) {
    /* Switch: '<S56>/Switch16' incorporates:
     *  Constant: '<S56>/Constant46'
     *  Product: '<S1599>/Product'
     *  Switch: '<S1608>/Switch2'
     */
    PowerCtrolProject1_S32K144_B.VOSP_ElecLockPWM_pct = 0.0F;
  } else {
    /* Outputs for Atomic SubSystem: '<S56>/Turn On Delay Time2' */
    if (rtb_AND_bg && (PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_a >=
                       2.5F)) {
      /* Switch: '<S56>/Switch17' incorporates:
       *  Constant: '<S56>/Constant53'
       *  Product: '<S1599>/Product'
       *  Switch: '<S1608>/Switch2'
       *  Switch: '<S56>/Switch16'
       */
      PowerCtrolProject1_S32K144_B.VOSP_ElecLockPWM_pct = 0.0F;
    } else {
      /* Outputs for Atomic SubSystem: '<S56>/Turn On Delay Time3' */
      if (rtb_AND_jj && (PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_i >=
                         2.5F)) {
        /* Switch: '<S56>/Switch18' incorporates:
         *  Constant: '<S56>/Constant54'
         *  Product: '<S1599>/Product'
         *  Switch: '<S1608>/Switch2'
         *  Switch: '<S56>/Switch16'
         *  Switch: '<S56>/Switch17'
         */
        PowerCtrolProject1_S32K144_B.VOSP_ElecLockPWM_pct = 0.0F;
      } else {
        /* Product: '<S1599>/Product' incorporates:
         *  Constant: '<S56>/Constant55'
         *  Switch: '<S1608>/Switch2'
         *  Switch: '<S56>/Switch16'
         *  Switch: '<S56>/Switch17'
         *  Switch: '<S56>/Switch18'
         */
        PowerCtrolProject1_S32K144_B.VOSP_ElecLockPWM_pct = 100.0F;
      }

      /* End of Outputs for SubSystem: '<S56>/Turn On Delay Time3' */
    }

    /* End of Outputs for SubSystem: '<S56>/Turn On Delay Time2' */
  }

  /* End of Switch: '<S56>/Switch15' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S21>/Convert ofVHSPI_OBCChgCooltPlateT_deg'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.OBC_ChgCoolantPlate_temp;

  /* Outputs for Atomic SubSystem: '<S958>/signal validity checking' */
  /* Logic: '<S958>/Logical Operator1' incorporates:
   *  Constant: '<S146>/Bus Selector_SigVld2'
   *  Constant: '<S938>/KISP_OBCChgCooltPlateTDft_deg'
   *  Constant: '<S938>/KISP_VldChkOBCChgCooltPlateTDec_cnt'
   *  Constant: '<S938>/KISP_VldChkOBCChgCooltPlateTInc_cnt'
   *  Constant: '<S938>/KISP_VldChkOBCChgCooltPlateTLim_cnt'
   *  Constant: '<S958>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_p0,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_nb);

  /* End of Outputs for SubSystem: '<S958>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S24>/Convert ofVHSPI_OBCHLOutpI_A18'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o6_c;

  /* Outputs for Atomic SubSystem: '<S1358>/signal validity checking' */
  /* Constant: '<S1313>/KISP_WhlSpdReLeDft_kph' incorporates:
   *  Constant: '<S1313>/KISP_VldChkWhlSpdReLeDec_cnt'
   *  Constant: '<S1313>/KISP_VldChkWhlSpdReLeInc_cnt'
   *  Constant: '<S1313>/KISP_VldChkWhlSpdReLeLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_k(PowerCtrolProject1_S32K144_B.y, 0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_jp, &rtb_valid_signal_em,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_nh,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_nh);

  /* End of Outputs for SubSystem: '<S1358>/signal validity checking' */

  /* Chart: '<S943>/Initialization' incorporates:
   *  Constant: '<S21>/CANActv_CDU_280h'
   */
  PowerCtrolProjec_Initialization(true, &PowerCtrolProject1_S32K144_B.CANInt_i);

  /* Outputs for Enabled SubSystem: '<S943>/CANDiagnosis' incorporates:
   *  EnablePort: '<S944>/Enable'
   */
  if (PowerCtrolProject1_S32K144_B.CANInt_i) {
    if (!PowerCtrolProject1_S32K14_DWork.CANDiagnosis_MODE) {
      /* SystemReset for Atomic SubSystem: '<S944>/signal validity checking' */
      sig_valid_check_Reset(&PowerCtrolProject1_S32K144_B.fault_flg_do,
                            &PowerCtrolProject1_S32K144_B.valid_signal,
                            &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_jxh);

      /* End of SystemReset for SubSystem: '<S944>/signal validity checking' */
      PowerCtrolProject1_S32K14_DWork.CANDiagnosis_MODE = true;
    }

    /* Outputs for Atomic SubSystem: '<S944>/signal validity checking' */
    /* DataTypeConversion: '<S944>/Data Type Conversion' incorporates:
     *  Constant: '<S21>/CANActv_CDU_280h'
     *  Constant: '<S936>/KISP_VldChkCDU280hCANActvDec_cnt'
     *  Constant: '<S936>/KISP_VldChkCDU280hCANActvInc_cnt'
     *  Constant: '<S936>/KISP_VldChkCDU280hCANActvLim_cnt'
     *  Constant: '<S944>/False'
     *  Constant: '<S944>/sat2'
     *  DataTypeConversion: '<S944>/Data Type Conversion1'
     */
    sig_valid_check(1.0F, true, false, 0.0F, 20, 1, 2,
                    &PowerCtrolProject1_S32K144_B.fault_flg_do,
                    &PowerCtrolProject1_S32K144_B.valid_signal,
                    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_jxh);

    /* End of Outputs for SubSystem: '<S944>/signal validity checking' */
  } else {
    if (PowerCtrolProject1_S32K14_DWork.CANDiagnosis_MODE) {
      PowerCtrolProject1_S32K14_DWork.CANDiagnosis_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S943>/CANDiagnosis' */

  /* Logic: '<S66>/Logical4' incorporates:
   *  Constant: '<S66>/Constant'
   *  Constant: '<S66>/Constant1'
   *  Constant: '<S66>/Constant6'
   *  Constant: '<S66>/Constant7'
   *  Constant: '<S66>/Constant8'
   *  Constant: '<S66>/Constant9'
   *  Delay: '<S66>/Delay'
   *  Logic: '<S66>/Logical2'
   *  Logic: '<S66>/Logical3'
   *  Logic: '<S66>/Logical5'
   *  RelationalOperator: '<S66>/Comparison1'
   *  RelationalOperator: '<S66>/Comparison4'
   *  RelationalOperator: '<S66>/Comparison5'
   *  RelationalOperator: '<S66>/Comparison6'
   *  RelationalOperator: '<S66>/Comparison7'
   *  RelationalOperator: '<S66>/Comparison8'
   */
  rtb_AND_bg = (((PowerCtrolProject1_S32K144_B.NISP_SigOut_e == 0) ||
                 (PowerCtrolProject1_S32K144_B.NISP_SigOut_e == 1)) &&
                ((PowerCtrolProject1_S32K144_B.NISP_SigOut_d == 0) ||
                 (PowerCtrolProject1_S32K144_B.NISP_SigOut_d == 1)) &&
                ((PowerCtrolProject1_S32K144_B.NISP_SigOut == 0) ||
                 (PowerCtrolProject1_S32K144_B.NISP_SigOut == 1)) &&
                (!PowerCtrolProject1_S32K14_DWork.Delay_DSTATE_g));

  /* Outputs for Atomic SubSystem: '<S66>/Turn On Delay Time' */
  /* Outputs for Atomic SubSystem: '<S112>/EdgeRising' */
  /* Logic: '<S114>/AND' incorporates:
   *  Logic: '<S114>/OR1'
   *  UnitDelay: '<S114>/Unit Delay'
   */
  rtb_AND_jj = (rtb_AND_bg &&
                (!PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_gr));

  /* Update for UnitDelay: '<S114>/Unit Delay' */
  PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_gr = rtb_AND_bg;

  /* End of Outputs for SubSystem: '<S112>/EdgeRising' */

  /* Switch: '<S112>/Switch1' incorporates:
   *  Constant: '<S112>/Constant Value1'
   *  Constant: '<S66>/Constant13'
   *  Logic: '<S112>/OR'
   *  Logic: '<S112>/OR1'
   *  MinMax: '<S112>/Minimum'
   *  Sum: '<S112>/Summation'
   *  UnitDelay: '<S112>/Unit Delay'
   */
  if ((!rtb_AND_bg) || rtb_AND_jj) {
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_d = 0.0F;
  } else if ((10.0F < 0.099999994F +
              PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_d) || rtIsNaNF
             (0.099999994F + PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_d))
  {
    /* MinMax: '<S112>/Minimum' */
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_d = 10.0F;
  } else {
    /* MinMax: '<S112>/Minimum' incorporates:
     *  Constant: '<S66>/Constant13'
     *  Sum: '<S112>/Summation'
     *  UnitDelay: '<S112>/Unit Delay'
     */
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_d += 0.099999994F;
  }

  /* End of Switch: '<S112>/Switch1' */

  /* Logic: '<S112>/AND' incorporates:
   *  Constant: '<S66>/Constant14'
   *  RelationalOperator: '<S112>/Greater  Than'
   *  UnitDelay: '<S112>/Unit Delay'
   */
  rtb_AND_bg = (rtb_AND_bg &&
                (PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_d >= 10.0F));

  /* End of Outputs for SubSystem: '<S66>/Turn On Delay Time' */

  /* Outputs for Atomic SubSystem: '<S66>/Hysteresis' */
  /* Outputs for Atomic SubSystem: '<S958>/override signal' */
  /* Switch: '<S109>/Switch1' incorporates:
   *  Constant: '<S109>/Constant Value'
   *  Constant: '<S66>/Constant Value3'
   *  Constant: '<S66>/Constant Value7'
   *  RelationalOperator: '<S109>/Greater  Than'
   *  RelationalOperator: '<S109>/Greater  Than1'
   *  SignalConversion: '<S959>/TmpSignal ConversionAtSwitch1Inport3'
   *  UnitDelay: '<S109>/Unit Delay'
   */
  if (rtb_valid_signal_pd > 50.0F) {
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_n = true;
  } else {
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_n = ((!(rtb_valid_signal_pd
      < 45.0F)) && PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_n);
  }

  /* End of Switch: '<S109>/Switch1' */
  /* End of Outputs for SubSystem: '<S958>/override signal' */
  /* End of Outputs for SubSystem: '<S66>/Hysteresis' */

  /* Outputs for Atomic SubSystem: '<S66>/Hysteresis1' */
  /* Outputs for Atomic SubSystem: '<S1358>/override signal' */
  /* Switch: '<S110>/Switch1' incorporates:
   *  Constant: '<S110>/Constant Value'
   *  Constant: '<S66>/Constant Value11'
   *  Constant: '<S66>/Constant Value12'
   *  RelationalOperator: '<S110>/Greater  Than'
   *  RelationalOperator: '<S110>/Greater  Than1'
   *  SignalConversion: '<S1359>/TmpSignal ConversionAtSwitch1Inport3'
   *  UnitDelay: '<S110>/Unit Delay'
   */
  if (rtb_valid_signal_em > 50.0F) {
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_om = true;
  } else {
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_om =
      ((!(rtb_valid_signal_em < 45.0F)) &&
       PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_om);
  }

  /* End of Switch: '<S110>/Switch1' */
  /* End of Outputs for SubSystem: '<S1358>/override signal' */
  /* End of Outputs for SubSystem: '<S66>/Hysteresis1' */

  /* Outputs for Atomic SubSystem: '<S943>/override signal' */
  /* Switch: '<S111>/Switch2' incorporates:
   *  Constant: '<S66>/Constant Value1'
   *  DataTypeConversion: '<S943>/Data Type Conversion1'
   *  SignalConversion: '<S946>/TmpSignal ConversionAtSwitch1Inport3'
   *  Switch: '<S111>/Switch1'
   *  UnitDelay: '<S111>/Unit Delay'
   */
  if (PowerCtrolProject1_S32K144_B.valid_signal != 0.0F) {
    /* Switch: '<S66>/Switch1' incorporates:
     *  Constant: '<S66>/Constant12'
     *  Constant: '<S66>/Constant2'
     *  Constant: '<S66>/Constant3'
     *  DataTypeConversion: '<S1504>/Data Type Conversion1'
     *  Logic: '<S66>/Logical1'
     *  RelationalOperator: '<S66>/Comparison11'
     *  RelationalOperator: '<S66>/Comparison2'
     *  RelationalOperator: '<S66>/Comparison3'
     *  SignalConversion: '<S1505>/TmpSignal ConversionAtSwitch1Inport3'
     *  Switch: '<S66>/Switch'
     *  Switch: '<S66>/Switch3'
     */
    if ((PowerCtrolProject1_S32K144_B.NISP_SigOut_d == 3) ||
        (PowerCtrolProject1_S32K144_B.NISP_SigOut_e == 3) ||
        (PowerCtrolProject1_S32K144_B.NISP_SigOut == 3)) {
      /* UnitDelay: '<S111>/Unit Delay' incorporates:
       *  Constant: '<S66>/Constant Value4'
       */
      PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE = 1.0F;
    } else if (rtb_AND_bg) {
      /* Switch: '<S66>/Switch' incorporates:
       *  Constant: '<S66>/Constant Value2'
       *  UnitDelay: '<S111>/Unit Delay'
       */
      PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE = 0.0F;
    } else {
      /* Outputs for Atomic SubSystem: '<S1504>/override signal' */
      if (rtb_valid_signal_ft != 0.0F) {
        /* Switch: '<S66>/Switch3' incorporates:
         *  Constant: '<S66>/Constant Value6'
         *  Switch: '<S66>/Switch'
         *  UnitDelay: '<S111>/Unit Delay'
         */
        PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE = 1.0F;
      } else {
        /* UnitDelay: '<S111>/Unit Delay' incorporates:
         *  Logic: '<S66>/Logical7'
         *  Switch: '<S66>/Switch'
         *  Switch: '<S66>/Switch3'
         *  UnitDelay: '<S109>/Unit Delay'
         *  UnitDelay: '<S110>/Unit Delay'
         */
        PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE = (real32_T)
          (PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_n ||
           PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_om);
      }

      /* End of Outputs for SubSystem: '<S1504>/override signal' */
    }

    /* End of Switch: '<S66>/Switch1' */
  } else {
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE = 1.0F;
  }

  /* End of Switch: '<S111>/Switch2' */
  /* End of Outputs for SubSystem: '<S943>/override signal' */

  /* Gain: '<S66>/Gain' incorporates:
   *  Constant: '<S66>/Constant Value5'
   *  Sum: '<S66>/Sum1'
   *  UnitDelay: '<S111>/Unit Delay'
   */
  rtb_valid_signal_ft = (1.0F - PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE)
    * 100.0F;

  /* Switch: '<S60>/Switch' incorporates:
   *  Constant: '<S60>/dummy_MorEna_C'
   */
  if (PowerCtrolProject1_S32K1_ConstB.Logical1_l) {
    PowerCtrolProject1_S32K144_B.VOSP_WtrPmpStrtCtrlrPWM_pct = 0.0F;
  } else {
    PowerCtrolProject1_S32K144_B.VOSP_WtrPmpStrtCtrlrPWM_pct =
      rtb_valid_signal_ft;
  }

  /* End of Switch: '<S60>/Switch' */

  /* Outputs for Atomic SubSystem: '<S1600>/OSPProcessDCDCOutpUReq_V' */
  /* Switch: '<S1610>/Switch2' incorporates:
   *  Constant: '<S1600>/KOSP_DCDCOutpUReqHigh_V'
   *  Constant: '<S1600>/KOSP_DCDCOutpUReqLow_V'
   *  RelationalOperator: '<S1610>/LowerRelop1'
   *  RelationalOperator: '<S1610>/UpperRelop'
   *  SignalConversion: '<S1609>/TmpSignal ConversionAtSwitch1Inport3'
   *  Switch: '<S1610>/Switch'
   */
  if (PowerCtrolProject1_S32K144_B.VOSP_WtrPmpStrtCtrlrPWM_pct > 65535.0F) {
    /* Product: '<S1600>/Product' */
    PowerCtrolProject1_S32K144_B.VOSP_WtrPmpStrtCtrlrPWM_pct = 65535.0F;
  } else {
    if (PowerCtrolProject1_S32K144_B.VOSP_WtrPmpStrtCtrlrPWM_pct < 0.0F) {
      /* Switch: '<S1610>/Switch' incorporates:
       *  Constant: '<S1600>/KOSP_DCDCOutpUReqLow_V'
       *  Product: '<S1600>/Product'
       */
      PowerCtrolProject1_S32K144_B.VOSP_WtrPmpStrtCtrlrPWM_pct = 0.0F;
    }
  }

  /* End of Switch: '<S1610>/Switch2' */
  /* End of Outputs for SubSystem: '<S1600>/OSPProcessDCDCOutpUReq_V' */

  /* Switch: '<S63>/Switch' incorporates:
   *  Constant: '<S63>/dummy_MorEna_C'
   *  Constant: '<S66>/Constant Value10'
   *  Delay: '<S66>/Delay1'
   *  RelationalOperator: '<S66>/Comparison13'
   *  Switch: '<S66>/Switch5'
   */
  if (PowerCtrolProject1_S32K1_ConstB.Logical1_f) {
    PowerCtrolProject1_S32K144_B.Switch_n = false;
  } else if (PowerCtrolProject1_S32K14_DWork.Delay1_DSTATE == 100.0F) {
    /* Switch: '<S66>/Switch5' incorporates:
     *  Constant: '<S66>/Constant16'
     */
    PowerCtrolProject1_S32K144_B.Switch_n = false;
  } else {
    /* Switch: '<S66>/Switch5' incorporates:
     *  Switch: '<S66>/Switch2'
     */
    PowerCtrolProject1_S32K144_B.Switch_n = !rtb_AND_bg;
  }

  /* End of Switch: '<S63>/Switch' */

  /* S-Function (scanpack): '<S33>/CANTXPack_VCU_180h' incorporates:
   *  Outport: '<Root>/CAN1TX500h'
   */
  /* S-Function (scanpack): '<S33>/CANTXPack_VCU_180h' */
  PowerCtrolProject1_S32K144_Y.CAN1TX500h.ID = 1280U;
  PowerCtrolProject1_S32K144_Y.CAN1TX500h.Length = 8U;
  PowerCtrolProject1_S32K144_Y.CAN1TX500h.Extended = 0U;
  PowerCtrolProject1_S32K144_Y.CAN1TX500h.Remote = 0;
  PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[0] = 0;
  PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[1] = 0;
  PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[2] = 0;
  PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[3] = 0;
  PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[4] = 0;
  PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[5] = 0;
  PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[6] = 0;
  PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 7
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.VOSP_ACInpRlyCtrlr_flg);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[0] =
              PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[0] | (uint8_T)
              ((uint8_T)((uint8_T)(packedValue & (uint8_T)0x1U) << 7));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 6
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.VOSP_ACOutRlyCtrlr_flg);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[0] =
              PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[0] | (uint8_T)
              ((uint8_T)((uint8_T)(packedValue & (uint8_T)0x1U) << 6));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 5
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.Switch1);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[0] =
              PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[0] | (uint8_T)
              ((uint8_T)((uint8_T)(packedValue & (uint8_T)0x1U) << 5));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 4
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.VOSP_BDCDCKL15_flg);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[0] =
              PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[0] | (uint8_T)
              ((uint8_T)((uint8_T)(packedValue & (uint8_T)0x1U) << 4));
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 3
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.VOSP_ElecFanOn_flg);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[0] =
              PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[0] | (uint8_T)
              ((uint8_T)((uint8_T)(packedValue & (uint8_T)0x1U) << 3));
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 2
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.VOSP_ElecLockPWM_flg);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[0] =
              PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[0] | (uint8_T)
              ((uint8_T)((uint8_T)(packedValue & (uint8_T)0x1U) << 2));
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 8
     *  length                  = 8
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = PowerCtrolProject1_S32K144_B.VOSP_ElecLockPWM_pct;

        /* no scaling required */
        outValue = result;
      }

      {
        uint8_T packedValue;
        if (outValue > (real32_T)(255)) {
          packedValue = (uint8_T) 255;
        } else if (outValue < (real32_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (outValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[1] =
              PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[1] | (uint8_T)
              (packedValue);
          }
        }
      }
    }

    /* --------------- START Packing signal 7 ------------------
     *  startBit                = 16
     *  length                  = 8
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result =
          PowerCtrolProject1_S32K144_B.VOSP_WtrPmpStrtCtrlrPWM_pct;

        /* no scaling required */
        outValue = result;
      }

      {
        uint8_T packedValue;
        if (outValue > (real32_T)(255)) {
          packedValue = (uint8_T) 255;
        } else if (outValue < (real32_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (outValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[2] =
              PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[2] | (uint8_T)
              (packedValue);
          }
        }
      }
    }

    /* --------------- START Packing signal 8 ------------------
     *  startBit                = 1
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.Switch_n);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[0] =
              PowerCtrolProject1_S32K144_Y.CAN1TX500h.Data[0] | (uint8_T)
              ((uint8_T)((uint8_T)(packedValue & (uint8_T)0x1U) << 1));
          }
        }
      }
    }
  }

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S6>/Convert ofVHSPI_BMSChrgDchaI_A'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Charge_Discharge_current;

  /* Outputs for Atomic SubSystem: '<S168>/signal validity checking' */
  /* Outputs for Atomic SubSystem: '<S168>/override signal' */
  /* SignalConversion: '<S169>/TmpSignal ConversionAtSwitch1Inport3' incorporates:
   *  Constant: '<S132>/Bus Selector_SigVld2'
   *  Constant: '<S156>/KISP_BMSChrgDchaIDft_A'
   *  Constant: '<S156>/KISP_VldChkBMSChrgDchaIDec_cnt'
   *  Constant: '<S156>/KISP_VldChkBMSChrgDchaIInc_cnt'
   *  Constant: '<S156>/KISP_VldChkBMSChrgDchaILim_cnt'
   *  Constant: '<S168>/False'
   *  Logic: '<S168>/Logical Operator1'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_jn,
                  &PowerCtrolProject1_S32K144_B.u_h,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking);

  /* End of Outputs for SubSystem: '<S168>/override signal' */
  /* End of Outputs for SubSystem: '<S168>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S6>/Convert ofVHSPI_BMSSOC_pct'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_SOC;

  /* Outputs for Atomic SubSystem: '<S175>/signal validity checking' */
  /* Outputs for Atomic SubSystem: '<S175>/override signal' */
  /* SignalConversion: '<S176>/TmpSignal ConversionAtSwitch1Inport3' incorporates:
   *  Constant: '<S132>/Bus Selector_SigVld3'
   *  Constant: '<S157>/KISP_BMSSOCDft_pct'
   *  Constant: '<S157>/KISP_VldChkBMSSOCDec_cnt'
   *  Constant: '<S157>/KISP_VldChkBMSSOCInc_cnt'
   *  Constant: '<S157>/KISP_VldChkBMSSOCLim_cnt'
   *  Constant: '<S175>/False'
   *  Logic: '<S175>/Logical Operator1'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_az,
                  &PowerCtrolProject1_S32K144_B.u_b,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_g);

  /* End of Outputs for SubSystem: '<S175>/override signal' */
  /* End of Outputs for SubSystem: '<S175>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S6>/Convert ofVHSPI_BMSTotBattUOutd_V'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Total_bat_voltage_outside;

  /* Outputs for Atomic SubSystem: '<S189>/signal validity checking' */
  /* Outputs for Atomic SubSystem: '<S189>/override signal' */
  /* SignalConversion: '<S190>/TmpSignal ConversionAtSwitch1Inport3' incorporates:
   *  Constant: '<S132>/Bus Selector_SigVld5'
   *  Constant: '<S159>/KISP_BMSTotBattUOutdDft_V'
   *  Constant: '<S159>/KISP_VldChkBMSTotBattUOutdDec_cnt'
   *  Constant: '<S159>/KISP_VldChkBMSTotBattUOutdInc_cnt'
   *  Constant: '<S159>/KISP_VldChkBMSTotBattUOutdLim_cnt'
   *  Constant: '<S189>/False'
   *  Logic: '<S189>/Logical Operator1'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_kb,
                  &PowerCtrolProject1_S32K144_B.u,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_j);

  /* End of Outputs for SubSystem: '<S189>/override signal' */
  /* End of Outputs for SubSystem: '<S189>/signal validity checking' */

  /* BusCreator: '<Root>/Bus Creator11' incorporates:
   *  Constant: '<Root>/Constant75'
   *  Constant: '<Root>/Constant78'
   *  Inport: '<Root>/In28'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX220h.Extended =
    PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic9;
  PowerCtrolProject1_S32K144_B.CAN1RX220h.Length = can_rx_msg.CAN1_DLC220h;
  PowerCtrolProject1_S32K144_B.CAN1RX220h.Remote = 0U;
  PowerCtrolProject1_S32K144_B.CAN1RX220h.Error = 0U;

  /* Switch: '<Root>/Switch9' */
  if (PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic9 != 0) {
    /* BusCreator: '<Root>/Bus Creator11' incorporates:
     *  Constant: '<Root>/Constant79'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX220h.ID = 0U;
  } else {
    /* BusCreator: '<Root>/Bus Creator11' incorporates:
     *  Inport: '<Root>/In29'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX220h.ID = can_rx_msg.CAN1_StdId220h;
  }

  /* End of Switch: '<Root>/Switch9' */

  /* BusCreator: '<Root>/Bus Creator11' incorporates:
   *  Constant: '<Root>/Constant76'
   *  Inport: '<Root>/In30'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX220h.Timestamp = 0.0;
  for (i = 0; i < 8; i++) {
    PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[i] = can_rx_msg.CAN1_Data220h[i];
  }

  /* S-Function (scanunpack): '<S15>/CANRXUnPack_BMS_220h' */
  {
    /* S-Function (scanunpack): '<S15>/CANRXUnPack_BMS_220h' */
    if ((8 == PowerCtrolProject1_S32K144_B.CAN1RX220h.Length) &&
        (PowerCtrolProject1_S32K144_B.CAN1RX220h.ID != INVALID_CAN_ID) ) {
      if ((544 == PowerCtrolProject1_S32K144_B.CAN1RX220h.ID) && (0U ==
           PowerCtrolProject1_S32K144_B.CAN1RX220h.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 12
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[1]) & (uint8_T)
                    (0x30U)) >> 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Charge_current_high_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 54
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[6]) & (uint8_T)
                    (0xC0U)) >> 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Charging_waiting_timeout_Wa =
                result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 14
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[1]) & (uint8_T)
                    (0xC0U)) >> 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Discharge_current_high_Wa =
                result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 30
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[3]) & (uint8_T)
                    (0xC0U)) >> 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_EleLock_fault_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 28
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[3]) & (uint8_T)
                    (0x30U)) >> 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_HVIL_fault_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 5 ------------------
           *  startBit                = 44
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[5]) & (uint8_T)
                    (0x30U)) >> 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Heaters_fault_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 6 ------------------
           *  startBit                = 46
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[5]) & (uint8_T)
                    (0xC0U)) >> 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Heaters_timeout_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 7 ------------------
           *  startBit                = 22
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[2]) & (uint8_T)
                    (0xC0U)) >> 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Insulation_fault_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 8 ------------------
           *  startBit                = 4
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[0]) & (uint8_T)
                    (0x30U)) >> 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Monomer_voltage_high_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 9 ------------------
           *  startBit                = 6
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[0]) & (uint8_T)
                    (0xC0U)) >> 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Monomer_voltage_low_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 10 ------------------
           *  startBit                = 42
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[5]) & (uint8_T)
                    (0xCU)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Precharge_fault_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 11 ------------------
           *  startBit                = 38
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[4]) & (uint8_T)
                    (0xC0U)) >> 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Soc_high_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 12 ------------------
           *  startBit                = 20
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[2]) & (uint8_T)
                    (0x30U)) >> 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Soc_low_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 13 ------------------
           *  startBit                = 16
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[2]) & (uint8_T)
                    (0x3U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Temp_difference_high_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 14 ------------------
           *  startBit                = 8
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[1]) & (uint8_T)
                    (0x3U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Temp_high_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 15 ------------------
           *  startBit                = 10
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[1]) & (uint8_T)
                    (0xCU)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Temp_low_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 16 ------------------
           *  startBit                = 40
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[5]) & (uint8_T)
                    (0x3U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Total_relay_adhesion_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 17 ------------------
           *  startBit                = 26
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[3]) & (uint8_T)
                    (0xCU)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Total_relay_fault_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 18 ------------------
           *  startBit                = 0
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[0]) & (uint8_T)
                    (0x3U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Total_voltage_high_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 19 ------------------
           *  startBit                = 2
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[0]) & (uint8_T)
                    (0xCU)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Total_voltage_low_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 20 ------------------
           *  startBit                = 36
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[4]) & (uint8_T)
                    (0x30U)) >> 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Tx_charging_lost_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 21 ------------------
           *  startBit                = 34
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[4]) & (uint8_T)
                    (0xCU)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Tx_obc_lost_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 22 ------------------
           *  startBit                = 32
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[4]) & (uint8_T)
                    (0x3U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Tx_vcu_lost_Wa = result;
            }
          }

          /* --------------- START Unpacking signal 23 ------------------
           *  startBit                = 18
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[2]) & (uint8_T)
                    (0xCU)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Voltage_difference_high_Wa =
                result;
            }
          }

          /* --------------- START Unpacking signal 24 ------------------
           *  startBit                = 24
           *  length                  = 2
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX220h.Data[3]) & (uint8_T)
                    (0x3U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_hardware_fault_Wa = result;
            }
          }
        }
      }
    }
  }

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSChrgIHiFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Charge_current_high_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Charge_current_high_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Charge_current_high_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSChrgIHiFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S609>/signal validity checking' */
  /* DataTypeConversion: '<S609>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld2'
   *  Constant: '<S576>/KISP_VldChkBMSChrgIHiFltDec_cnt'
   *  Constant: '<S576>/KISP_VldChkBMSChrgIHiFltInc_cnt'
   *  Constant: '<S576>/KISP_VldChkBMSChrgIHiFltLim_cnt'
   *  Constant: '<S609>/False'
   *  Logic: '<S609>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_l5, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_hm, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_n4);

  /* End of Outputs for SubSystem: '<S609>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S609>/override signal' */
  /* DataTypeConversion: '<S609>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S610>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_g = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S609>/override signal' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSChrgnWaitTimeoutFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Charging_waiting_timeout_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Charging_waiting_timeout_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Charging_waiting_timeout_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSChrgnWaitTimeoutFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S615>/signal validity checking' */
  /* DataTypeConversion: '<S615>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld3'
   *  Constant: '<S577>/KISP_VldChkBMSChrgnWaitTimeoutFltDec_cnt'
   *  Constant: '<S577>/KISP_VldChkBMSChrgnWaitTimeoutFltInc_cnt'
   *  Constant: '<S577>/KISP_VldChkBMSChrgnWaitTimeoutFltLim_cnt'
   *  Constant: '<S615>/False'
   *  Logic: '<S615>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_lf, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_oy, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_pb);

  /* End of Outputs for SubSystem: '<S615>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S615>/override signal' */
  /* MinMax: '<S119>/MinMax1' incorporates:
   *  DataTypeConversion: '<S615>/Data Type Conversion1'
   *  SignalConversion: '<S616>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_db = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S615>/override signal' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSDchaIHiFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Discharge_current_high_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Discharge_current_high_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Discharge_current_high_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSDchaIHiFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S621>/signal validity checking' */
  /* DataTypeConversion: '<S621>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld4'
   *  Constant: '<S578>/KISP_VldChkBMSDchaIHiFltDec_cnt'
   *  Constant: '<S578>/KISP_VldChkBMSDchaIHiFltInc_cnt'
   *  Constant: '<S578>/KISP_VldChkBMSDchaIHiFltLim_cnt'
   *  Constant: '<S621>/False'
   *  Logic: '<S621>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_ip, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_ac, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_pe);

  /* End of Outputs for SubSystem: '<S621>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S621>/override signal' */
  /* MinMax: '<S119>/MinMax1' incorporates:
   *  DataTypeConversion: '<S621>/Data Type Conversion1'
   *  SignalConversion: '<S622>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_p = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S621>/override signal' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSHVILFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_HVIL_fault_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_HVIL_fault_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.BMS_HVIL_fault_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSHVILFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S633>/signal validity checking' */
  /* DataTypeConversion: '<S633>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld6'
   *  Constant: '<S580>/KISP_VldChkBMSHVILFltDec_cnt'
   *  Constant: '<S580>/KISP_VldChkBMSHVILFltInc_cnt'
   *  Constant: '<S580>/KISP_VldChkBMSHVILFltLim_cnt'
   *  Constant: '<S633>/False'
   *  Logic: '<S633>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_j, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_pc, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_o);

  /* End of Outputs for SubSystem: '<S633>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S633>/override signal' */
  /* MinMax: '<S119>/MinMax1' incorporates:
   *  DataTypeConversion: '<S633>/Data Type Conversion1'
   *  SignalConversion: '<S634>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_b = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S633>/override signal' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSHeatrFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Heaters_fault_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Heaters_fault_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.BMS_Heaters_fault_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSHeatrFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S639>/signal validity checking' */
  /* DataTypeConversion: '<S639>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld7'
   *  Constant: '<S581>/KISP_VldChkBMSHeatrFltDec_cnt'
   *  Constant: '<S581>/KISP_VldChkBMSHeatrFltInc_cnt'
   *  Constant: '<S581>/KISP_VldChkBMSHeatrFltLim_cnt'
   *  Constant: '<S639>/False'
   *  Logic: '<S639>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_h, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_k12, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_a);

  /* End of Outputs for SubSystem: '<S639>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S639>/override signal' */
  /* MinMax: '<S119>/MinMax1' incorporates:
   *  DataTypeConversion: '<S639>/Data Type Conversion1'
   *  SignalConversion: '<S640>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_n = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S639>/override signal' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSHeatrTimeOutFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Heaters_timeout_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Heaters_timeout_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Heaters_timeout_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSHeatrTimeOutFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S645>/signal validity checking' */
  /* DataTypeConversion: '<S645>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld8'
   *  Constant: '<S582>/KISP_VldChkBMSHeatrTimeOutFltDec_cnt'
   *  Constant: '<S582>/KISP_VldChkBMSHeatrTimeOutFltInc_cnt'
   *  Constant: '<S582>/KISP_VldChkBMSHeatrTimeOutFltLim_cnt'
   *  Constant: '<S645>/False'
   *  Logic: '<S645>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_ay, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_ot, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_oi);

  /* End of Outputs for SubSystem: '<S645>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S645>/override signal' */
  /* MinMax: '<S119>/MinMax1' incorporates:
   *  DataTypeConversion: '<S645>/Data Type Conversion1'
   *  SignalConversion: '<S646>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_hg = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S645>/override signal' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSInsulatFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Insulation_fault_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Insulation_fault_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Insulation_fault_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSInsulatFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S657>/signal validity checking' */
  /* DataTypeConversion: '<S657>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld9'
   *  Constant: '<S584>/KISP_VldChkBMSInsulatFltDec_cnt'
   *  Constant: '<S584>/KISP_VldChkBMSInsulatFltInc_cnt'
   *  Constant: '<S584>/KISP_VldChkBMSInsulatFltLim_cnt'
   *  Constant: '<S657>/False'
   *  Logic: '<S657>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_o, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_op, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_pj);

  /* End of Outputs for SubSystem: '<S657>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S657>/override signal' */
  /* MinMax: '<S119>/MinMax1' incorporates:
   *  DataTypeConversion: '<S657>/Data Type Conversion1'
   *  SignalConversion: '<S658>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_ej = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S657>/override signal' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSMonomerUHi_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Monomer_voltage_high_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Monomer_voltage_high_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Monomer_voltage_high_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSMonomerUHi_enum' */

  /* Outputs for Atomic SubSystem: '<S663>/signal validity checking' */
  /* DataTypeConversion: '<S663>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld10'
   *  Constant: '<S585>/KISP_VldChkBMSMonomerUHiDec_cnt'
   *  Constant: '<S585>/KISP_VldChkBMSMonomerUHiInc_cnt'
   *  Constant: '<S585>/KISP_VldChkBMSMonomerUHiLim_cnt'
   *  Constant: '<S663>/False'
   *  Logic: '<S663>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_f, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_ge, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_fs);

  /* End of Outputs for SubSystem: '<S663>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S663>/override signal' */
  /* MinMax: '<S119>/MinMax1' incorporates:
   *  DataTypeConversion: '<S663>/Data Type Conversion1'
   *  SignalConversion: '<S664>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_ji = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S663>/override signal' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSMonomerULo_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Monomer_voltage_low_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Monomer_voltage_low_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Monomer_voltage_low_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSMonomerULo_enum' */

  /* Outputs for Atomic SubSystem: '<S669>/signal validity checking' */
  /* DataTypeConversion: '<S669>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld11'
   *  Constant: '<S586>/KISP_VldChkBMSMonomerULoDec_cnt'
   *  Constant: '<S586>/KISP_VldChkBMSMonomerULoInc_cnt'
   *  Constant: '<S586>/KISP_VldChkBMSMonomerULoLim_cnt'
   *  Constant: '<S669>/False'
   *  Logic: '<S669>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_hk, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_hc, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_dz);

  /* End of Outputs for SubSystem: '<S669>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S669>/override signal' */
  /* MinMax: '<S119>/MinMax1' incorporates:
   *  DataTypeConversion: '<S669>/Data Type Conversion1'
   *  SignalConversion: '<S670>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_l2 = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S669>/override signal' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_PrecFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Precharge_fault_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Precharge_fault_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Precharge_fault_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_PrecFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S741>/signal validity checking' */
  /* DataTypeConversion: '<S741>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld12'
   *  Constant: '<S598>/KISP_VldChkPrecFltDec_cnt'
   *  Constant: '<S598>/KISP_VldChkPrecFltInc_cnt'
   *  Constant: '<S598>/KISP_VldChkPrecFltLim_cnt'
   *  Constant: '<S741>/False'
   *  Logic: '<S741>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_dn, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_bw, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_gg);

  /* End of Outputs for SubSystem: '<S741>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S741>/override signal' */
  /* MinMax: '<S119>/MinMax1' incorporates:
   *  DataTypeConversion: '<S741>/Data Type Conversion1'
   *  SignalConversion: '<S742>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_f = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S741>/override signal' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_SocLoFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Soc_low_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Soc_low_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.BMS_Soc_low_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_SocLoFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S753>/signal validity checking' */
  /* DataTypeConversion: '<S753>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld14'
   *  Constant: '<S600>/KISP_VldChkSocLoFltDec_cnt'
   *  Constant: '<S600>/KISP_VldChkSocLoFltInc_cnt'
   *  Constant: '<S600>/KISP_VldChkSocLoFltLim_cnt'
   *  Constant: '<S753>/False'
   *  Logic: '<S753>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_fh, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_ny, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_cf);

  /* End of Outputs for SubSystem: '<S753>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S753>/override signal' */
  /* DataTypeConversion: '<S753>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S754>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_ft = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S753>/override signal' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSTDifHiFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Temp_difference_high_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Temp_difference_high_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Temp_difference_high_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSTDifHiFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S675>/signal validity checking' */
  /* DataTypeConversion: '<S675>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld15'
   *  Constant: '<S587>/KISP_VldChkBMSTDifHiFltDec_cnt'
   *  Constant: '<S587>/KISP_VldChkBMSTDifHiFltInc_cnt'
   *  Constant: '<S587>/KISP_VldChkBMSTDifHiFltLim_cnt'
   *  Constant: '<S675>/False'
   *  Logic: '<S675>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_nm, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_bi0, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ke);

  /* End of Outputs for SubSystem: '<S675>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S675>/override signal' */
  /* MinMax: '<S119>/MinMax1' incorporates:
   *  DataTypeConversion: '<S675>/Data Type Conversion1'
   *  SignalConversion: '<S676>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_ll = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S675>/override signal' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSTHiFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Temp_high_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Temp_high_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.BMS_Temp_high_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSTHiFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S681>/signal validity checking' */
  /* DataTypeConversion: '<S681>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld16'
   *  Constant: '<S588>/KISP_VldChkBMSTHiFltDec_cnt'
   *  Constant: '<S588>/KISP_VldChkBMSTHiFltInc_cnt'
   *  Constant: '<S588>/KISP_VldChkBMSTHiFltLim_cnt'
   *  Constant: '<S681>/False'
   *  Logic: '<S681>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_p, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_bi, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_of);

  /* End of Outputs for SubSystem: '<S681>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S681>/override signal' */
  /* MinMax: '<S119>/MinMax1' incorporates:
   *  DataTypeConversion: '<S681>/Data Type Conversion1'
   *  SignalConversion: '<S682>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_nw = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S681>/override signal' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSTLoFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Temp_low_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Temp_low_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.BMS_Temp_low_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSTLoFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S687>/signal validity checking' */
  /* DataTypeConversion: '<S687>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld17'
   *  Constant: '<S589>/KISP_VldChkBMSTLoFltDec_cnt'
   *  Constant: '<S589>/KISP_VldChkBMSTLoFltInc_cnt'
   *  Constant: '<S589>/KISP_VldChkBMSTLoFltLim_cnt'
   *  Constant: '<S687>/False'
   *  Logic: '<S687>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_gs, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_oj, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ix);

  /* End of Outputs for SubSystem: '<S687>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S687>/override signal' */
  /* MinMax: '<S119>/MinMax1' incorporates:
   *  DataTypeConversion: '<S687>/Data Type Conversion1'
   *  SignalConversion: '<S688>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_c = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S687>/override signal' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSTotRlyAdhFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Total_relay_adhesion_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Total_relay_adhesion_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Total_relay_adhesion_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSTotRlyAdhFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S693>/signal validity checking' */
  /* DataTypeConversion: '<S693>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld18'
   *  Constant: '<S590>/KISP_VldChkBMSTotRlyAdhFltDec_cnt'
   *  Constant: '<S590>/KISP_VldChkBMSTotRlyAdhFltInc_cnt'
   *  Constant: '<S590>/KISP_VldChkBMSTotRlyAdhFltLim_cnt'
   *  Constant: '<S693>/False'
   *  Logic: '<S693>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_h5, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_dq, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_dt);

  /* End of Outputs for SubSystem: '<S693>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S693>/override signal' */
  /* MinMax: '<S119>/MinMax1' incorporates:
   *  DataTypeConversion: '<S693>/Data Type Conversion1'
   *  SignalConversion: '<S694>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_j0 = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S693>/override signal' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSTotRlyFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Total_relay_fault_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Total_relay_fault_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Total_relay_fault_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSTotRlyFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S699>/signal validity checking' */
  /* DataTypeConversion: '<S699>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld19'
   *  Constant: '<S591>/KISP_VldChkBMSTotRlyFltDec_cnt'
   *  Constant: '<S591>/KISP_VldChkBMSTotRlyFltInc_cnt'
   *  Constant: '<S591>/KISP_VldChkBMSTotRlyFltLim_cnt'
   *  Constant: '<S699>/False'
   *  Logic: '<S699>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_b, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_dij, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_i2);

  /* End of Outputs for SubSystem: '<S699>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S699>/override signal' */
  /* MinMax: '<S119>/MinMax1' incorporates:
   *  DataTypeConversion: '<S699>/Data Type Conversion1'
   *  SignalConversion: '<S700>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_fl = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S699>/override signal' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSTotUHiFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Total_voltage_high_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Total_voltage_high_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Total_voltage_high_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSTotUHiFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S705>/signal validity checking' */
  /* DataTypeConversion: '<S705>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld20'
   *  Constant: '<S592>/KISP_VldChkBMSTotUHiFltDec_cnt'
   *  Constant: '<S592>/KISP_VldChkBMSTotUHiFltInc_cnt'
   *  Constant: '<S592>/KISP_VldChkBMSTotUHiFltLim_cnt'
   *  Constant: '<S705>/False'
   *  Logic: '<S705>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_hz, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_mhz, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_lt);

  /* End of Outputs for SubSystem: '<S705>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S705>/override signal' */
  /* MinMax: '<S119>/MinMax1' incorporates:
   *  DataTypeConversion: '<S705>/Data Type Conversion1'
   *  SignalConversion: '<S706>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_d0 = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S705>/override signal' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSTotULoFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Total_voltage_low_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Total_voltage_low_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Total_voltage_low_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSTotULoFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S711>/signal validity checking' */
  /* DataTypeConversion: '<S711>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld21'
   *  Constant: '<S593>/KISP_VldChkBMSTotULoFltDec_cnt'
   *  Constant: '<S593>/KISP_VldChkBMSTotULoFltInc_cnt'
   *  Constant: '<S593>/KISP_VldChkBMSTotULoFltLim_cnt'
   *  Constant: '<S711>/False'
   *  Logic: '<S711>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_h2, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_i, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_dmd);

  /* End of Outputs for SubSystem: '<S711>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S711>/override signal' */
  /* MinMax: '<S119>/MinMax1' incorporates:
   *  DataTypeConversion: '<S711>/Data Type Conversion1'
   *  SignalConversion: '<S712>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_o = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S711>/override signal' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSTxChrgLostFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Tx_charging_lost_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Tx_charging_lost_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Tx_charging_lost_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSTxChrgLostFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S717>/signal validity checking' */
  /* DataTypeConversion: '<S717>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld22'
   *  Constant: '<S594>/KISP_VldChkBMSTxChrgLostFltDec_cnt'
   *  Constant: '<S594>/KISP_VldChkBMSTxChrgLostFltInc_cnt'
   *  Constant: '<S594>/KISP_VldChkBMSTxChrgLostFltLim_cnt'
   *  Constant: '<S717>/False'
   *  Logic: '<S717>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_dq, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_jx, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_df);

  /* End of Outputs for SubSystem: '<S717>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S717>/override signal' */
  /* MinMax: '<S119>/MinMax1' incorporates:
   *  DataTypeConversion: '<S717>/Data Type Conversion1'
   *  SignalConversion: '<S718>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_gn = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S717>/override signal' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSUDifHiFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Voltage_difference_high_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Voltage_difference_high_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Voltage_difference_high_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSUDifHiFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S735>/signal validity checking' */
  /* DataTypeConversion: '<S735>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld25'
   *  Constant: '<S597>/KISP_VldChkBMSUDifHiFltDec_cnt'
   *  Constant: '<S597>/KISP_VldChkBMSUDifHiFltInc_cnt'
   *  Constant: '<S597>/KISP_VldChkBMSUDifHiFltLim_cnt'
   *  Constant: '<S735>/False'
   *  Logic: '<S735>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_e, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_k2, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_fr);

  /* End of Outputs for SubSystem: '<S735>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S735>/override signal' */
  /* MinMax: '<S119>/MinMax1' incorporates:
   *  DataTypeConversion: '<S735>/Data Type Conversion1'
   *  SignalConversion: '<S736>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_oo = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S735>/override signal' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSHwFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_hardware_fault_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_hardware_fault_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_hardware_fault_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSHwFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S651>/signal validity checking' */
  /* DataTypeConversion: '<S651>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld26'
   *  Constant: '<S583>/KISP_VldChkBMSHwFltDec_cnt'
   *  Constant: '<S583>/KISP_VldChkBMSHwFltInc_cnt'
   *  Constant: '<S583>/KISP_VldChkBMSHwFltLim_cnt'
   *  Constant: '<S651>/False'
   *  Logic: '<S651>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_ij, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_ib, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_on);

  /* End of Outputs for SubSystem: '<S651>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S651>/override signal' */
  /* MinMax: '<S119>/MinMax1' incorporates:
   *  DataTypeConversion: '<S651>/Data Type Conversion1'
   *  SignalConversion: '<S652>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_SigOut_ih = (uint8_T)rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S651>/override signal' */

  /* BusCreator: '<Root>/Bus Creator17' incorporates:
   *  Constant: '<Root>/Constant60'
   *  Constant: '<Root>/Constant64'
   *  Inport: '<Root>/In46'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX290h.Extended =
    PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic15;
  PowerCtrolProject1_S32K144_B.CAN1RX290h.Length = can_rx_msg.CAN1_DLC290h;
  PowerCtrolProject1_S32K144_B.CAN1RX290h.Remote = 0U;
  PowerCtrolProject1_S32K144_B.CAN1RX290h.Error = 0U;

  /* Switch: '<Root>/Switch15' */
  if (PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic15 != 0) {
    /* BusCreator: '<Root>/Bus Creator17' incorporates:
     *  Constant: '<Root>/Constant65'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX290h.ID = 0U;
  } else {
    /* BusCreator: '<Root>/Bus Creator17' incorporates:
     *  Inport: '<Root>/In47'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX290h.ID = can_rx_msg.CAN1_StdId290h;
  }

  /* End of Switch: '<Root>/Switch15' */

  /* BusCreator: '<Root>/Bus Creator17' incorporates:
   *  Constant: '<Root>/Constant61'
   *  Inport: '<Root>/In48'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX290h.Timestamp = 0.0;
  for (i = 0; i < 8; i++) {
    PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[i] = can_rx_msg.CAN1_Data290h[i];
  }

  /* S-Function (scanunpack): '<S22>/CANRXUnPack_CDU_290h' */
  {
    /* S-Function (scanunpack): '<S22>/CANRXUnPack_CDU_290h' */
    if ((8 == PowerCtrolProject1_S32K144_B.CAN1RX290h.Length) &&
        (PowerCtrolProject1_S32K144_B.CAN1RX290h.ID != INVALID_CAN_ID) ) {
      if ((656 == PowerCtrolProject1_S32K144_B.CAN1RX290h.ID) && (0U ==
           PowerCtrolProject1_S32K144_B.CAN1RX290h.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 7
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[0]) & (uint8_T)
                    (0x80U)) >> 7);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgACLoss_AL = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 35
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[4]) & (uint8_T)
                    (0x8U)) >> 3);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgBMSCANMissing_AL = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 33
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[4]) & (uint8_T)
                    (0x2U)) >> 1);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgCANBusOff_AL = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 22
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[2]) & (uint8_T)
                    (0x40U)) >> 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgCoolantPlateOTP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 2
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[0]) & (uint8_T)
                    (0x4U)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgDCOVP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 5 ------------------
           *  startBit                = 37
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[4]) & (uint8_T)
                    (0x20U)) >> 5);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgEepromError_AL = result;
            }
          }

          /* --------------- START Unpacking signal 6 ------------------
           *  startBit                = 24
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[3]) & (uint8_T)
                    (0x1U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgFlashCheckError_AL = result;
            }
          }

          /* --------------- START Unpacking signal 7 ------------------
           *  startBit                = 19
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[2]) & (uint8_T)
                    (0x8U)) >> 3);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgHVOVP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 8 ------------------
           *  startBit                = 8
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[1]) & (uint8_T)
                    (0x1U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgHVUVP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 9 ------------------
           *  startBit                = 25
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[3]) & (uint8_T)
                    (0x2U)) >> 1);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgInputLVOVP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 10 ------------------
           *  startBit                = 26
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[3]) & (uint8_T)
                    (0x4U)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgInputLVUVP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 11 ------------------
           *  startBit                = 32
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[4]) & (uint8_T)
                    (0x1U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgInternalCommError_AL = result;
            }
          }

          /* --------------- START Unpacking signal 12 ------------------
           *  startBit                = 20
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[2]) & (uint8_T)
                    (0x10U)) >> 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgInternalILFault_AL = result;
            }
          }

          /* --------------- START Unpacking signal 13 ------------------
           *  startBit                = 21
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[2]) & (uint8_T)
                    (0x20U)) >> 5);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgLLCMosOTP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 14 ------------------
           *  startBit                = 18
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[2]) & (uint8_T)
                    (0x4U)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgLlcHWOCP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 15 ------------------
           *  startBit                = 23
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[2]) & (uint8_T)
                    (0x80U)) >> 7);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgLlcRsnt_AL = result;
            }
          }

          /* --------------- START Unpacking signal 16 ------------------
           *  startBit                = 17
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[2]) & (uint8_T)
                    (0x2U)) >> 1);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgMasterHIoutOCP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 17 ------------------
           *  startBit                = 27
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[3]) & (uint8_T)
                    (0x8U)) >> 3);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgOut12VSwOCP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 18 ------------------
           *  startBit                = 29
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[3]) & (uint8_T)
                    (0x20U)) >> 5);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgOut12VSwOVP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 19 ------------------
           *  startBit                = 28
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[3]) & (uint8_T)
                    (0x10U)) >> 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgOut12VSwUVP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 20 ------------------
           *  startBit                = 10
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[1]) & (uint8_T)
                    (0x4U)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgP12VOVP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 21 ------------------
           *  startBit                = 9
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[1]) & (uint8_T)
                    (0x2U)) >> 1);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgP12VUVP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 22 ------------------
           *  startBit                = 31
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[3]) & (uint8_T)
                    (0x80U)) >> 7);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgP6VOVP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 23 ------------------
           *  startBit                = 30
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[3]) & (uint8_T)
                    (0x40U)) >> 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgP6VUVP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 24 ------------------
           *  startBit                = 15
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[1]) & (uint8_T)
                    (0x80U)) >> 7);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgPFCChokeOTP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 25 ------------------
           *  startBit                = 0
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[0]) & (uint8_T)
                    (0x1U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgPFCMosOTP_AL_ = result;
            }
          }

          /* --------------- START Unpacking signal 26 ------------------
           *  startBit                = 14
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[1]) & (uint8_T)
                    (0x40U)) >> 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgPFCPhaseLoss_AL = result;
            }
          }

          /* --------------- START Unpacking signal 27 ------------------
           *  startBit                = 1
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[0]) & (uint8_T)
                    (0x2U)) >> 1);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgPFCStartFail_AL = result;
            }
          }

          /* --------------- START Unpacking signal 28 ------------------
           *  startBit                = 13
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[1]) & (uint8_T)
                    (0x20U)) >> 5);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgPriFreqErr_AL = result;
            }
          }

          /* --------------- START Unpacking signal 29 ------------------
           *  startBit                = 4
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[0]) & (uint8_T)
                    (0x10U)) >> 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgPriIoutOCP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 30 ------------------
           *  startBit                = 11
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[1]) & (uint8_T)
                    (0x8U)) >> 3);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgPwmErr_AL = result;
            }
          }

          /* --------------- START Unpacking signal 31 ------------------
           *  startBit                = 36
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[4]) & (uint8_T)
                    (0x10U)) >> 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgRamCheckError_AL = result;
            }
          }

          /* --------------- START Unpacking signal 32 ------------------
           *  startBit                = 12
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[1]) & (uint8_T)
                    (0x10U)) >> 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgSCIErr_AL = result;
            }
          }

          /* --------------- START Unpacking signal 33 ------------------
           *  startBit                = 16
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[2]) & (uint8_T)
                    (0x1U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgSlaveHIoutOCP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 34 ------------------
           *  startBit                = 34
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[4]) & (uint8_T)
                    (0x4U)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgVCUCANMissing_AL = result;
            }
          }

          /* --------------- START Unpacking signal 35 ------------------
           *  startBit                = 3
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[0]) & (uint8_T)
                    (0x8U)) >> 3);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgVinOCP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 36 ------------------
           *  startBit                = 5
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[0]) & (uint8_T)
                    (0x20U)) >> 5);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgVinOVP_AL = result;
            }
          }

          /* --------------- START Unpacking signal 37 ------------------
           *  startBit                = 6
           *  length                  = 1
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX290h.Data[0]) & (uint8_T)
                    (0x40U)) >> 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.CDU_ChgVinUVP_AL = result;
            }
          }
        }
      }
    }
  }

  /* Outputs for Atomic SubSystem: '<S1046>/signal validity checking' */
  /* DataTypeConversion: '<S1046>/Data Type Conversion' incorporates:
   *  Constant: '<S1046>/False'
   *  Constant: '<S147>/Bus Selector_SigVld2'
   *  Constant: '<S995>/KISP_VldChkCDUChgACLossFltDec_cnt'
   *  Constant: '<S995>/KISP_VldChkCDUChgACLossFltInc_cnt'
   *  Constant: '<S995>/KISP_VldChkCDUChgACLossFltLim_cnt'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgACLossFlt_flg'
   *  Logic: '<S1046>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgACLoss_AL != 0.0), true, false, 20, 1,
    2, &PowerCtrolProject1_S32K144_B.fault_flg_ja, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_j5,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_j5);

  /* End of Outputs for SubSystem: '<S1046>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1046>/override signal' */
  /* DataTypeConversion: '<S1046>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1047>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_bq = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1046>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1052>/signal validity checking' */
  /* DataTypeConversion: '<S1052>/Data Type Conversion' incorporates:
   *  Constant: '<S1052>/False'
   *  Constant: '<S147>/Bus Selector_SigVld5'
   *  Constant: '<S996>/KISP_VldChkCDUChgCooltPlateOTPFltDec_cnt'
   *  Constant: '<S996>/KISP_VldChkCDUChgCooltPlateOTPFltInc_cnt'
   *  Constant: '<S996>/KISP_VldChkCDUChgCooltPlateOTPFltLim_cnt'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgCooltPlateOTPFlt_flg'
   *  Logic: '<S1052>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgCoolantPlateOTP_AL != 0.0), true, false,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_c3, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_ph,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ph);

  /* End of Outputs for SubSystem: '<S1052>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1052>/override signal' */
  /* DataTypeConversion: '<S1052>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1053>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_h = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1052>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1058>/signal validity checking' */
  /* DataTypeConversion: '<S1058>/Data Type Conversion' incorporates:
   *  Constant: '<S1058>/False'
   *  Constant: '<S147>/Bus Selector_SigVld6'
   *  Constant: '<S997>/KISP_VldChkCDUChgDCOVPFltDec_cnt'
   *  Constant: '<S997>/KISP_VldChkCDUChgDCOVPFltInc_cnt'
   *  Constant: '<S997>/KISP_VldChkCDUChgDCOVPFltLim_cnt'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgDCOVPFlt_flg'
   *  Logic: '<S1058>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgDCOVP_AL != 0.0), true, false, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_no, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_ko,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ko);

  /* End of Outputs for SubSystem: '<S1058>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1058>/override signal' */
  /* DataTypeConversion: '<S1058>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1059>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_e = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1058>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1070>/signal validity checking' */
  /* DataTypeConversion: '<S1070>/Data Type Conversion' incorporates:
   *  Constant: '<S1070>/False'
   *  Constant: '<S147>/Bus Selector_SigVld8'
   *  Constant: '<S999>/KISP_VldChkCDUChgFlashChkErrDec_cnt'
   *  Constant: '<S999>/KISP_VldChkCDUChgFlashChkErrInc_cnt'
   *  Constant: '<S999>/KISP_VldChkCDUChgFlashChkErrLim_cnt'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgFlashChkErr_flg'
   *  Logic: '<S1070>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgFlashCheckError_AL != 0.0), true, false,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_ea, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_oe,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_oe);

  /* End of Outputs for SubSystem: '<S1070>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1070>/override signal' */
  /* DataTypeConversion: '<S1070>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1071>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_o = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1070>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1076>/signal validity checking' */
  /* DataTypeConversion: '<S1076>/Data Type Conversion' incorporates:
   *  Constant: '<S1000>/KISP_VldChkCDUChgHVOVPFltDec_cnt'
   *  Constant: '<S1000>/KISP_VldChkCDUChgHVOVPFltInc_cnt'
   *  Constant: '<S1000>/KISP_VldChkCDUChgHVOVPFltLim_cnt'
   *  Constant: '<S1076>/False'
   *  Constant: '<S147>/Bus Selector_SigVld9'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgHVOVPFlt_flg'
   *  Logic: '<S1076>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgHVOVP_AL != 0.0), true, false, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_lk, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_gh,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_gh);

  /* End of Outputs for SubSystem: '<S1076>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1076>/override signal' */
  /* DataTypeConversion: '<S1076>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1077>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_n = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1076>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1082>/signal validity checking' */
  /* DataTypeConversion: '<S1082>/Data Type Conversion' incorporates:
   *  Constant: '<S1001>/KISP_VldChkCDUChgHVUVPFltDec_cnt'
   *  Constant: '<S1001>/KISP_VldChkCDUChgHVUVPFltInc_cnt'
   *  Constant: '<S1001>/KISP_VldChkCDUChgHVUVPFltLim_cnt'
   *  Constant: '<S1082>/False'
   *  Constant: '<S147>/Bus Selector_SigVld10'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgHVUVPFlt_flg'
   *  Logic: '<S1082>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgHVUVP_AL != 0.0), true, false, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_c01, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_ck3,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ck3);

  /* End of Outputs for SubSystem: '<S1082>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1082>/override signal' */
  /* DataTypeConversion: '<S1082>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1083>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_p = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1082>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1088>/signal validity checking' */
  /* DataTypeConversion: '<S1088>/Data Type Conversion' incorporates:
   *  Constant: '<S1002>/KISP_VldChkCDUChgInpLVOVPFltDec_cnt'
   *  Constant: '<S1002>/KISP_VldChkCDUChgInpLVOVPFltInc_cnt'
   *  Constant: '<S1002>/KISP_VldChkCDUChgInpLVOVPFltLim_cnt'
   *  Constant: '<S1088>/False'
   *  Constant: '<S147>/Bus Selector_SigVld11'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgInpLVOVPFlt_flg'
   *  Logic: '<S1088>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgInputLVOVP_AL != 0.0), true, false, 20,
    1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_p2, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_nd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_nd);

  /* End of Outputs for SubSystem: '<S1088>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1088>/override signal' */
  /* DataTypeConversion: '<S1088>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1089>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_c = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1088>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1094>/signal validity checking' */
  /* DataTypeConversion: '<S1094>/Data Type Conversion' incorporates:
   *  Constant: '<S1003>/KISP_VldChkCDUChgInpLVUVPFltDec_cnt'
   *  Constant: '<S1003>/KISP_VldChkCDUChgInpLVUVPFltInc_cnt'
   *  Constant: '<S1003>/KISP_VldChkCDUChgInpLVUVPFltLim_cnt'
   *  Constant: '<S1094>/False'
   *  Constant: '<S147>/Bus Selector_SigVld12'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgInpLVUVPFlt_flg'
   *  Logic: '<S1094>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgInputLVUVP_AL != 0.0), true, false, 20,
    1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_a, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_cq,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_cq);

  /* End of Outputs for SubSystem: '<S1094>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1094>/override signal' */
  /* DataTypeConversion: '<S1094>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1095>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_d = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1094>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1262>/signal validity checking' */
  /* DataTypeConversion: '<S1262>/Data Type Conversion' incorporates:
   *  Constant: '<S1031>/KISP_VldChkChgChgIntILFltDec_cnt'
   *  Constant: '<S1031>/KISP_VldChkChgChgIntILFltInc_cnt'
   *  Constant: '<S1031>/KISP_VldChkChgChgIntILFltLim_cnt'
   *  Constant: '<S1262>/False'
   *  Constant: '<S147>/Bus Selector_SigVld14'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_ChgChgIntILFlt_flg'
   *  Logic: '<S1262>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgInternalILFault_AL != 0.0), true, false,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_di, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_py,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_py);

  /* End of Outputs for SubSystem: '<S1262>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1262>/override signal' */
  /* DataTypeConversion: '<S1262>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1263>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_ej = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1262>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1112>/signal validity checking' */
  /* DataTypeConversion: '<S1112>/Data Type Conversion' incorporates:
   *  Constant: '<S1006>/KISP_VldChkCDUChgLLCMosOTPFltDec_cnt'
   *  Constant: '<S1006>/KISP_VldChkCDUChgLLCMosOTPFltInc_cnt'
   *  Constant: '<S1006>/KISP_VldChkCDUChgLLCMosOTPFltLim_cnt'
   *  Constant: '<S1112>/False'
   *  Constant: '<S147>/Bus Selector_SigVld15'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgLLCMosOTPFlt_flg'
   *  Logic: '<S1112>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgLLCMosOTP_AL != 0.0), true, false, 20,
    1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_nn, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_he,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_he);

  /* End of Outputs for SubSystem: '<S1112>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1112>/override signal' */
  /* DataTypeConversion: '<S1112>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1113>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_bv = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1112>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1106>/signal validity checking' */
  /* DataTypeConversion: '<S1106>/Data Type Conversion' incorporates:
   *  Constant: '<S1005>/KISP_VldChkCDUChgLLCHWOCPFltDec_cnt'
   *  Constant: '<S1005>/KISP_VldChkCDUChgLLCHWOCPFltInc_cnt'
   *  Constant: '<S1005>/KISP_VldChkCDUChgLLCHWOCPFltLim_cnt'
   *  Constant: '<S1106>/False'
   *  Constant: '<S147>/Bus Selector_SigVld16'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgLLCHWOCPFlt_flg'
   *  Logic: '<S1106>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgLlcHWOCP_AL != 0.0), true, false, 20, 1,
    2, &PowerCtrolProject1_S32K144_B.fault_flg_jvn, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_ex,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ex);

  /* End of Outputs for SubSystem: '<S1106>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1106>/override signal' */
  /* DataTypeConversion: '<S1106>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1107>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_a = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1106>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1118>/signal validity checking' */
  /* DataTypeConversion: '<S1118>/Data Type Conversion' incorporates:
   *  Constant: '<S1007>/KISP_VldChkCDUChgLlcRsntFltDec_cnt'
   *  Constant: '<S1007>/KISP_VldChkCDUChgLlcRsntFltInc_cnt'
   *  Constant: '<S1007>/KISP_VldChkCDUChgLlcRsntFltLim_cnt'
   *  Constant: '<S1118>/False'
   *  Constant: '<S147>/Bus Selector_SigVld17'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgLlcRsntFlt_flg'
   *  Logic: '<S1118>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgLlcRsnt_AL != 0.0), true, false, 20, 1,
    2, &PowerCtrolProject1_S32K144_B.fault_flg_gc, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_mx,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_mx);

  /* End of Outputs for SubSystem: '<S1118>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1118>/override signal' */
  /* DataTypeConversion: '<S1118>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1119>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_i = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1118>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1124>/signal validity checking' */
  /* DataTypeConversion: '<S1124>/Data Type Conversion' incorporates:
   *  Constant: '<S1008>/KISP_VldChkCDUChgMstHIoutOCPFltDec_cnt'
   *  Constant: '<S1008>/KISP_VldChkCDUChgMstHIoutOCPFltInc_cnt'
   *  Constant: '<S1008>/KISP_VldChkCDUChgMstHIoutOCPFltLim_cnt'
   *  Constant: '<S1124>/False'
   *  Constant: '<S147>/Bus Selector_SigVld18'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgMstHIoutOCPFlt_flg'
   *  Logic: '<S1124>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgMasterHIoutOCP_AL != 0.0), true, false,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_kx, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_j4,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_j4);

  /* End of Outputs for SubSystem: '<S1124>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1124>/override signal' */
  /* DataTypeConversion: '<S1124>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1125>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_a5 = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1124>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1130>/signal validity checking' */
  /* DataTypeConversion: '<S1130>/Data Type Conversion' incorporates:
   *  Constant: '<S1009>/KISP_VldChkCDUChgOut12VSwOCPFltDec_cnt'
   *  Constant: '<S1009>/KISP_VldChkCDUChgOut12VSwOCPFltInc_cnt'
   *  Constant: '<S1009>/KISP_VldChkCDUChgOut12VSwOCPFltLim_cnt'
   *  Constant: '<S1130>/False'
   *  Constant: '<S147>/Bus Selector_SigVld19'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgOut12VSwOCPFlt_flg'
   *  Logic: '<S1130>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgOut12VSwOCP_AL != 0.0), true, false, 20,
    1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_jcr, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_jy,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_jy);

  /* End of Outputs for SubSystem: '<S1130>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1130>/override signal' */
  /* DataTypeConversion: '<S1130>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1131>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_ib = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1130>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1136>/signal validity checking' */
  /* DataTypeConversion: '<S1136>/Data Type Conversion' incorporates:
   *  Constant: '<S1010>/KISP_VldChkCDUChgOut12VSwOVPFltDec_cnt'
   *  Constant: '<S1010>/KISP_VldChkCDUChgOut12VSwOVPFltInc_cnt'
   *  Constant: '<S1010>/KISP_VldChkCDUChgOut12VSwOVPFltLim_cnt'
   *  Constant: '<S1136>/False'
   *  Constant: '<S147>/Bus Selector_SigVld20'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgOut12VSwOVPFlt_flg'
   *  Logic: '<S1136>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgOut12VSwOVP_AL != 0.0), true, false, 20,
    1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_pf, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_kez,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_kez);

  /* End of Outputs for SubSystem: '<S1136>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1136>/override signal' */
  /* DataTypeConversion: '<S1136>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1137>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_p3 = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1136>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1142>/signal validity checking' */
  /* DataTypeConversion: '<S1142>/Data Type Conversion' incorporates:
   *  Constant: '<S1011>/KISP_VldChkCDUChgOut12VSwUVPFltDec_cnt'
   *  Constant: '<S1011>/KISP_VldChkCDUChgOut12VSwUVPFltInc_cnt'
   *  Constant: '<S1011>/KISP_VldChkCDUChgOut12VSwUVPFltLim_cnt'
   *  Constant: '<S1142>/False'
   *  Constant: '<S147>/Bus Selector_SigVld21'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgOut12VSwUVPFlt_flg'
   *  Logic: '<S1142>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgOut12VSwUVP_AL != 0.0), true, false, 20,
    1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_jc, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_knc,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_knc);

  /* End of Outputs for SubSystem: '<S1142>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1142>/override signal' */
  /* DataTypeConversion: '<S1142>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1143>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_dc = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1142>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1148>/signal validity checking' */
  /* DataTypeConversion: '<S1148>/Data Type Conversion' incorporates:
   *  Constant: '<S1012>/KISP_VldChkCDUChgP12VOVPFltDec_cnt'
   *  Constant: '<S1012>/KISP_VldChkCDUChgP12VOVPFltInc_cnt'
   *  Constant: '<S1012>/KISP_VldChkCDUChgP12VOVPFltLim_cnt'
   *  Constant: '<S1148>/False'
   *  Constant: '<S147>/Bus Selector_SigVld22'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgP12VOVPFlt_flg'
   *  Logic: '<S1148>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgP12VOVP_AL != 0.0), true, false, 20, 1,
    2, &PowerCtrolProject1_S32K144_B.fault_flg_m1, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_f5,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_f5);

  /* End of Outputs for SubSystem: '<S1148>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1148>/override signal' */
  /* DataTypeConversion: '<S1148>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1149>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_cp = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1148>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1154>/signal validity checking' */
  /* DataTypeConversion: '<S1154>/Data Type Conversion' incorporates:
   *  Constant: '<S1013>/KISP_VldChkCDUChgP12VUVPFltDec_cnt'
   *  Constant: '<S1013>/KISP_VldChkCDUChgP12VUVPFltInc_cnt'
   *  Constant: '<S1013>/KISP_VldChkCDUChgP12VUVPFltLim_cnt'
   *  Constant: '<S1154>/False'
   *  Constant: '<S147>/Bus Selector_SigVld23'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgP12VUVPFlt_flg'
   *  Logic: '<S1154>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgP12VUVP_AL != 0.0), true, false, 20, 1,
    2, &PowerCtrolProject1_S32K144_B.fault_flg_pw, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_l2,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_l2);

  /* End of Outputs for SubSystem: '<S1154>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1154>/override signal' */
  /* DataTypeConversion: '<S1154>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1155>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_b5 = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1154>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1160>/signal validity checking' */
  /* DataTypeConversion: '<S1160>/Data Type Conversion' incorporates:
   *  Constant: '<S1014>/KISP_VldChkCDUChgP6VOVPFltDec_cnt'
   *  Constant: '<S1014>/KISP_VldChkCDUChgP6VOVPFltInc_cnt'
   *  Constant: '<S1014>/KISP_VldChkCDUChgP6VOVPFltLim_cnt'
   *  Constant: '<S1160>/False'
   *  Constant: '<S147>/Bus Selector_SigVld24'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgP6VOVPFlt_flg'
   *  Logic: '<S1160>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgP6VOVP_AL != 0.0), true, false, 20, 1,
    2, &PowerCtrolProject1_S32K144_B.fault_flg_nr, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_my,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_my);

  /* End of Outputs for SubSystem: '<S1160>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1160>/override signal' */
  /* DataTypeConversion: '<S1160>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1161>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_j = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1160>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1166>/signal validity checking' */
  /* DataTypeConversion: '<S1166>/Data Type Conversion' incorporates:
   *  Constant: '<S1015>/KISP_VldChkCDUChgP6VUVPFltDec_cnt'
   *  Constant: '<S1015>/KISP_VldChkCDUChgP6VUVPFltInc_cnt'
   *  Constant: '<S1015>/KISP_VldChkCDUChgP6VUVPFltLim_cnt'
   *  Constant: '<S1166>/False'
   *  Constant: '<S147>/Bus Selector_SigVld25'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgP6VUVPFlt_flg'
   *  Logic: '<S1166>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgP6VUVP_AL != 0.0), true, false, 20, 1,
    2, &PowerCtrolProject1_S32K144_B.fault_flg_pb, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_c4,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_c4);

  /* End of Outputs for SubSystem: '<S1166>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1166>/override signal' */
  /* DataTypeConversion: '<S1166>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1167>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_ei = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1166>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1172>/signal validity checking' */
  /* DataTypeConversion: '<S1172>/Data Type Conversion' incorporates:
   *  Constant: '<S1016>/KISP_VldChkCDUChgPFCChokeOTPFltDec_cnt'
   *  Constant: '<S1016>/KISP_VldChkCDUChgPFCChokeOTPFltInc_cnt'
   *  Constant: '<S1016>/KISP_VldChkCDUChgPFCChokeOTPFltLim_cnt'
   *  Constant: '<S1172>/False'
   *  Constant: '<S147>/Bus Selector_SigVld26'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgPFCChokeOTPFlt_flg'
   *  Logic: '<S1172>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgPFCChokeOTP_AL != 0.0), true, false, 20,
    1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_kcr, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_eh,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_eh);

  /* End of Outputs for SubSystem: '<S1172>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1172>/override signal' */
  /* DataTypeConversion: '<S1172>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1173>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_k1 = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1172>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1178>/signal validity checking' */
  /* DataTypeConversion: '<S1178>/Data Type Conversion' incorporates:
   *  Constant: '<S1017>/KISP_VldChkCDUChgPFCMosOTPFltDec_cnt'
   *  Constant: '<S1017>/KISP_VldChkCDUChgPFCMosOTPFltInc_cnt'
   *  Constant: '<S1017>/KISP_VldChkCDUChgPFCMosOTPFltLim_cnt'
   *  Constant: '<S1178>/False'
   *  Constant: '<S147>/Bus Selector_SigVld27'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgPFCMosOTPFlt_flg'
   *  Logic: '<S1178>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgPFCMosOTP_AL_ != 0.0), true, false, 20,
    1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_k1, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_myz,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_myz);

  /* End of Outputs for SubSystem: '<S1178>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1178>/override signal' */
  /* DataTypeConversion: '<S1178>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1179>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_oe = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1178>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1190>/signal validity checking' */
  /* DataTypeConversion: '<S1190>/Data Type Conversion' incorporates:
   *  Constant: '<S1019>/KISP_VldChkCDUChgPFPhaLossFltDec_cnt'
   *  Constant: '<S1019>/KISP_VldChkCDUChgPFPhaLossFltInc_cnt'
   *  Constant: '<S1019>/KISP_VldChkCDUChgPFPhaLossFltLim_cnt'
   *  Constant: '<S1190>/False'
   *  Constant: '<S147>/Bus Selector_SigVld28'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgPFPhaLossFlt_flg'
   *  Logic: '<S1190>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgPFCPhaseLoss_AL != 0.0), true, false,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_fp, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_db,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_db);

  /* End of Outputs for SubSystem: '<S1190>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1190>/override signal' */
  /* DataTypeConversion: '<S1190>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1191>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_as = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1190>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1184>/signal validity checking' */
  /* DataTypeConversion: '<S1184>/Data Type Conversion' incorporates:
   *  Constant: '<S1018>/KISP_VldChkCDUChgPFCStrtFailFltDec_cnt'
   *  Constant: '<S1018>/KISP_VldChkCDUChgPFCStrtFailFltInc_cnt'
   *  Constant: '<S1018>/KISP_VldChkCDUChgPFCStrtFailFltLim_cnt'
   *  Constant: '<S1184>/False'
   *  Constant: '<S147>/Bus Selector_SigVld29'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgPFCStrtFailFlt_flg'
   *  Logic: '<S1184>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgPFCStartFail_AL != 0.0), true, false,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_fl, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_ja,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ja);

  /* End of Outputs for SubSystem: '<S1184>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1184>/override signal' */
  /* DataTypeConversion: '<S1184>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1185>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_j1 = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1184>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1196>/signal validity checking' */
  /* DataTypeConversion: '<S1196>/Data Type Conversion' incorporates:
   *  Constant: '<S1020>/KISP_VldChkCDUChgPriFrqErrDec_cnt'
   *  Constant: '<S1020>/KISP_VldChkCDUChgPriFrqErrInc_cnt'
   *  Constant: '<S1020>/KISP_VldChkCDUChgPriFrqErrLim_cnt'
   *  Constant: '<S1196>/False'
   *  Constant: '<S147>/Bus Selector_SigVld30'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgPriFrqErr_flg'
   *  Logic: '<S1196>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgPriFreqErr_AL != 0.0), true, false, 20,
    1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_kc, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_af,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_af);

  /* End of Outputs for SubSystem: '<S1196>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1196>/override signal' */
  /* DataTypeConversion: '<S1196>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1197>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_l = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1196>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1202>/signal validity checking' */
  /* DataTypeConversion: '<S1202>/Data Type Conversion' incorporates:
   *  Constant: '<S1021>/KISP_VldChkCDUChgPrilOutOCPFltDec_cnt'
   *  Constant: '<S1021>/KISP_VldChkCDUChgPrilOutOCPFltInc_cnt'
   *  Constant: '<S1021>/KISP_VldChkCDUChgPrilOutOCPFltLim_cnt'
   *  Constant: '<S1202>/False'
   *  Constant: '<S147>/Bus Selector_SigVld31'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgPrilOutOCPFlt_flg'
   *  Logic: '<S1202>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgPriIoutOCP_AL != 0.0), true, false, 20,
    1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_ob, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_lu,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_lu);

  /* End of Outputs for SubSystem: '<S1202>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1202>/override signal' */
  /* DataTypeConversion: '<S1202>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1203>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_bz = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1202>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1208>/signal validity checking' */
  /* DataTypeConversion: '<S1208>/Data Type Conversion' incorporates:
   *  Constant: '<S1022>/KISP_VldChkCDUChgPwmErrFltDec_cnt'
   *  Constant: '<S1022>/KISP_VldChkCDUChgPwmErrFltInc_cnt'
   *  Constant: '<S1022>/KISP_VldChkCDUChgPwmErrFltLim_cnt'
   *  Constant: '<S1208>/False'
   *  Constant: '<S147>/Bus Selector_SigVld32'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgPwmErrFlt_flg'
   *  Logic: '<S1208>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgPwmErr_AL != 0.0), true, false, 20, 1,
    2, &PowerCtrolProject1_S32K144_B.fault_flg_f0, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_lij,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_lij);

  /* End of Outputs for SubSystem: '<S1208>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1208>/override signal' */
  /* DataTypeConversion: '<S1208>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1209>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_m = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1208>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1220>/signal validity checking' */
  /* DataTypeConversion: '<S1220>/Data Type Conversion' incorporates:
   *  Constant: '<S1024>/KISP_VldChkCDUChgSCIErrDec_cnt'
   *  Constant: '<S1024>/KISP_VldChkCDUChgSCIErrInc_cnt'
   *  Constant: '<S1024>/KISP_VldChkCDUChgSCIErrLim_cnt'
   *  Constant: '<S1220>/False'
   *  Constant: '<S147>/Bus Selector_SigVld34'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgSCIErr_flg'
   *  Logic: '<S1220>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgSCIErr_AL != 0.0), true, false, 20, 1,
    2, &PowerCtrolProject1_S32K144_B.fault_flg_dt, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_g3,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_g3);

  /* End of Outputs for SubSystem: '<S1220>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1220>/override signal' */
  /* DataTypeConversion: '<S1220>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1221>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_jb = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1220>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1226>/signal validity checking' */
  /* DataTypeConversion: '<S1226>/Data Type Conversion' incorporates:
   *  Constant: '<S1025>/KISP_VldChkCDUChgSlaveHIOutOCPFltDec_cnt'
   *  Constant: '<S1025>/KISP_VldChkCDUChgSlaveHIOutOCPFltInc_cnt'
   *  Constant: '<S1025>/KISP_VldChkCDUChgSlaveHIOutOCPFltLim_cnt'
   *  Constant: '<S1226>/False'
   *  Constant: '<S147>/Bus Selector_SigVld35'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgSlaveHIOutOCPFlt_flg'
   *  Logic: '<S1226>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgSlaveHIoutOCP_AL != 0.0), true, false,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_jv, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_lg,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_lg);

  /* End of Outputs for SubSystem: '<S1226>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1226>/override signal' */
  /* DataTypeConversion: '<S1226>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1227>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_oe5 = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1226>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1238>/signal validity checking' */
  /* DataTypeConversion: '<S1238>/Data Type Conversion' incorporates:
   *  Constant: '<S1027>/KISP_VldChkCDUChgVinOCPFltDec_cnt'
   *  Constant: '<S1027>/KISP_VldChkCDUChgVinOCPFltInc_cnt'
   *  Constant: '<S1027>/KISP_VldChkCDUChgVinOCPFltLim_cnt'
   *  Constant: '<S1238>/False'
   *  Constant: '<S147>/Bus Selector_SigVld37'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgVinOCPFlt_flg'
   *  Logic: '<S1238>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgVinOCP_AL != 0.0), true, false, 20, 1,
    2, &PowerCtrolProject1_S32K144_B.fault_flg_pk, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_pu,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_pu);

  /* End of Outputs for SubSystem: '<S1238>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1238>/override signal' */
  /* DataTypeConversion: '<S1238>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1239>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_hs = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1238>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1244>/signal validity checking' */
  /* DataTypeConversion: '<S1244>/Data Type Conversion' incorporates:
   *  Constant: '<S1028>/KISP_VldChkCDUChgVinOVPFltDec_cnt'
   *  Constant: '<S1028>/KISP_VldChkCDUChgVinOVPFltInc_cnt'
   *  Constant: '<S1028>/KISP_VldChkCDUChgVinOVPFltLim_cnt'
   *  Constant: '<S1244>/False'
   *  Constant: '<S147>/Bus Selector_SigVld38'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgVinOVPFlt_flg'
   *  Logic: '<S1244>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgVinOVP_AL != 0.0), true, false, 20, 1,
    2, &PowerCtrolProject1_S32K144_B.fault_flg_n, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_iku,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_iku);

  /* End of Outputs for SubSystem: '<S1244>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1244>/override signal' */
  /* DataTypeConversion: '<S1244>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1245>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_nc = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1244>/override signal' */

  /* Outputs for Atomic SubSystem: '<S1250>/signal validity checking' */
  /* DataTypeConversion: '<S1250>/Data Type Conversion' incorporates:
   *  Constant: '<S1029>/KISP_VldChkCDUChgVinUVPFltDec_cnt'
   *  Constant: '<S1029>/KISP_VldChkCDUChgVinUVPFltInc_cnt'
   *  Constant: '<S1029>/KISP_VldChkCDUChgVinUVPFltLim_cnt'
   *  Constant: '<S1250>/False'
   *  Constant: '<S147>/Bus Selector_SigVld39'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgVinUVPFlt_flg'
   *  Logic: '<S1250>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgVinUVP_AL != 0.0), true, false, 20, 1,
    2, &PowerCtrolProject1_S32K144_B.fault_flg_b2, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_mk,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_mk);

  /* End of Outputs for SubSystem: '<S1250>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1250>/override signal' */
  /* DataTypeConversion: '<S1250>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S1251>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K144_B.NISP_sigOut_km = (rtb_valid_signal_pd != 0.0F);

  /* End of Outputs for SubSystem: '<S1250>/override signal' */

  /* Outputs for Atomic SubSystem: '<S4>/Turn Off Delay Time' */
  /* Outputs for Atomic SubSystem: '<S37>/EdgeFalling1' */
  /* Logic: '<S41>/AND' incorporates:
   *  UnitDelay: '<S41>/Unit Delay'
   */
  rtb_AND_bg = (PowerCtrolProject1_S32K1_ConstB.OR1 &&
                PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_er);

  /* Update for UnitDelay: '<S41>/Unit Delay' incorporates:
   *  Constant: '<S4>/Constant2'
   */
  PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_er = true;

  /* End of Outputs for SubSystem: '<S37>/EdgeFalling1' */

  /* Switch: '<S37>/Switch' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   *  MinMax: '<S37>/Minimum'
   *  Sum: '<S37>/Summation'
   *  UnitDelay: '<S37>/Unit Delay'
   */
  if (rtb_AND_bg) {
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_g = 30.0F;
  } else if (PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_g - 0.099999994F >
             0.0F) {
    /* MinMax: '<S37>/Minimum' incorporates:
     *  Constant: '<S4>/Constant'
     *  Sum: '<S37>/Summation'
     *  UnitDelay: '<S37>/Unit Delay'
     */
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_g -= 0.099999994F;
  } else {
    /* MinMax: '<S37>/Minimum' */
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_g = 0.0F;
  }

  /* End of Switch: '<S37>/Switch' */
  /* End of Outputs for SubSystem: '<S4>/Turn Off Delay Time' */

  /* Outputs for Enabled SubSystem: '<S4>/HSPO_500ms' incorporates:
   *  EnablePort: '<S36>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S36>/Subsystem5' incorporates:
   *  EnablePort: '<S40>/Enable'
   */
  /* S-Function (scanpack): '<S40>/CANTXPack_RS485_Address_1_1' incorporates:
   *  Outport: '<Root>/CAN2TX1h'
   */
  /* S-Function (scanpack): '<S40>/CANTXPack_RS485_Address_1_1' */
  PowerCtrolProject1_S32K144_Y.CAN2TX1h.ID = 1U;
  PowerCtrolProject1_S32K144_Y.CAN2TX1h.Length = 8U;
  PowerCtrolProject1_S32K144_Y.CAN2TX1h.Extended = 0U;
  PowerCtrolProject1_S32K144_Y.CAN2TX1h.Remote = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[0] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[1] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[2] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[3] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[4] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[5] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[6] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 8
     *  length                  = 16
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = PowerCtrolProject1_S32K144_B.u;

        /* no offset to apply */
        result = result * (1 / 0.1F);
        outValue = result;
      }

      {
        uint16_T packedValue;
        if (outValue > (real32_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real32_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[1] =
              PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[1] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[0] =
              PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[0] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 50
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_SigOut_e);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[6] =
              PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[6] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x3U) << 2));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 24
     *  length                  = 16
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = -3000.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = PowerCtrolProject1_S32K144_B.u_h;

        /* full scaling operation */
        result = (result - -3000.0F) * (1 / 0.1F);
        outValue = result;
      }

      {
        uint16_T packedValue;
        if (outValue > (real32_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real32_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[3] =
              PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[3] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[2] =
              PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[2] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 40
     *  length                  = 16
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = PowerCtrolProject1_S32K144_B.u_b;

        /* no offset to apply */
        result = result * (1 / 0.1F);
        outValue = result;
      }

      {
        uint16_T packedValue;
        if (outValue > (real32_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real32_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[5] =
              PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[5] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[4] =
              PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[4] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 48
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_SigOut_a);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[6] =
              PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[6] | (uint8_T)((uint8_T)
              (packedValue & (uint8_T)0x3U));
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 56
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_SigOut_d);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[7] =
              PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[7] | (uint8_T)((uint8_T)
              (packedValue & (uint8_T)0x3U));
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 61
     *  length                  = 3
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_SigOut_h);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(7)) {
          packedValue = (uint8_T) 7;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[7] =
              PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[7] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x7U) << 5));
          }
        }
      }
    }

    /* --------------- START Packing signal 7 ------------------
     *  startBit                = 58
     *  length                  = 3
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_SigOut);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(7)) {
          packedValue = (uint8_T) 7;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[7] =
              PowerCtrolProject1_S32K144_Y.CAN2TX1h.Data[7] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x7U) << 2));
          }
        }
      }
    }
  }

  /* End of Outputs for SubSystem: '<S36>/Subsystem5' */

  /* Outputs for Enabled SubSystem: '<S36>/ID67' incorporates:
   *  EnablePort: '<S38>/Enable'
   */
  /* S-Function (scanpack): '<S38>/CANTXPack_RS485_Response_03' incorporates:
   *  Outport: '<Root>/CAN2TX3h'
   */
  /* S-Function (scanpack): '<S38>/CANTXPack_RS485_Response_03' */
  PowerCtrolProject1_S32K144_Y.CAN2TX3h.ID = 3U;
  PowerCtrolProject1_S32K144_Y.CAN2TX3h.Length = 8U;
  PowerCtrolProject1_S32K144_Y.CAN2TX3h.Extended = 0U;
  PowerCtrolProject1_S32K144_Y.CAN2TX3h.Remote = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[0] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[1] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[2] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[3] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[4] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[5] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[6] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 38
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_SigOut_db);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[4] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[4] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x3U) << 6));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 12
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_SigOut_g);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[1] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x3U) << 4));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 14
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_SigOut_p);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[1] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x3U) << 6));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 28
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_SigOut_b);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[3] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[3] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x3U) << 4));
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 32
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_SigOut_n);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[4] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[4] | (uint8_T)((uint8_T)
              (packedValue & (uint8_T)0x3U));
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 34
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_SigOut_hg);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[4] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[4] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x3U) << 2));
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 22
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_SigOut_ej);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[2] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[2] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x3U) << 6));
          }
        }
      }
    }

    /* --------------- START Packing signal 7 ------------------
     *  startBit                = 4
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_SigOut_ji);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[0] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x3U) << 4));
          }
        }
      }
    }

    /* --------------- START Packing signal 8 ------------------
     *  startBit                = 6
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_SigOut_l2);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[0] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x3U) << 6));
          }
        }
      }
    }

    /* --------------- START Packing signal 9 ------------------
     *  startBit                = 30
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_SigOut_f);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[3] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[3] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x3U) << 6));
          }
        }
      }
    }

    /* --------------- START Packing signal 10 ------------------
     *  startBit                = 20
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_SigOut_ft);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[2] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[2] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x3U) << 4));
          }
        }
      }
    }

    /* --------------- START Packing signal 11 ------------------
     *  startBit                = 16
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_SigOut_ll);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[2] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[2] | (uint8_T)((uint8_T)
              (packedValue & (uint8_T)0x3U));
          }
        }
      }
    }

    /* --------------- START Packing signal 12 ------------------
     *  startBit                = 8
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_SigOut_nw);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[1] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[1] | (uint8_T)((uint8_T)
              (packedValue & (uint8_T)0x3U));
          }
        }
      }
    }

    /* --------------- START Packing signal 13 ------------------
     *  startBit                = 10
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_SigOut_c);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[1] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x3U) << 2));
          }
        }
      }
    }

    /* --------------- START Packing signal 14 ------------------
     *  startBit                = 40
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_SigOut_j0);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[5] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[5] | (uint8_T)((uint8_T)
              (packedValue & (uint8_T)0x3U));
          }
        }
      }
    }

    /* --------------- START Packing signal 15 ------------------
     *  startBit                = 26
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_SigOut_fl);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[3] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[3] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x3U) << 2));
          }
        }
      }
    }

    /* --------------- START Packing signal 16 ------------------
     *  startBit                = 0
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_SigOut_d0);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[0] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[0] | (uint8_T)((uint8_T)
              (packedValue & (uint8_T)0x3U));
          }
        }
      }
    }

    /* --------------- START Packing signal 17 ------------------
     *  startBit                = 2
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_SigOut_o);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[0] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x3U) << 2));
          }
        }
      }
    }

    /* --------------- START Packing signal 18 ------------------
     *  startBit                = 36
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_SigOut_gn);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[4] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[4] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x3U) << 4));
          }
        }
      }
    }

    /* --------------- START Packing signal 19 ------------------
     *  startBit                = 18
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_SigOut_oo);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[2] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[2] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x3U) << 2));
          }
        }
      }
    }

    /* --------------- START Packing signal 20 ------------------
     *  startBit                = 24
     *  length                  = 2
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_SigOut_ih);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(3)) {
          packedValue = (uint8_T) 3;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[3] =
              PowerCtrolProject1_S32K144_Y.CAN2TX3h.Data[3] | (uint8_T)((uint8_T)
              (packedValue & (uint8_T)0x3U));
          }
        }
      }
    }
  }

  /* End of Outputs for SubSystem: '<S36>/ID67' */

  /* Outputs for Enabled SubSystem: '<S36>/Subsystem23' incorporates:
   *  EnablePort: '<S39>/Enable'
   */
  /* S-Function (scanpack): '<S39>/CANTXPack_RS485_Address_1_7' incorporates:
   *  Outport: '<Root>/CAN2TX2h'
   */
  /* S-Function (scanpack): '<S39>/CANTXPack_RS485_Address_1_7' */
  PowerCtrolProject1_S32K144_Y.CAN2TX2h.ID = 2U;
  PowerCtrolProject1_S32K144_Y.CAN2TX2h.Length = 4U;
  PowerCtrolProject1_S32K144_Y.CAN2TX2h.Extended = 0U;
  PowerCtrolProject1_S32K144_Y.CAN2TX2h.Remote = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[0] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[1] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[2] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[3] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[4] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[5] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[6] = 0;
  PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 7
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_sigOut_bq);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[0] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 7));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 22
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_sigOut_h);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[2] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[2] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 6));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 2
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_sigOut_e);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[0] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 2));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 24
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_sigOut_o);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[3] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[3] | (uint8_T)((uint8_T)
              (packedValue & (uint8_T)0x1U));
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 19
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_sigOut_n);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[2] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[2] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 3));
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 8
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_sigOut_p);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[1] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[1] | (uint8_T)((uint8_T)
              (packedValue & (uint8_T)0x1U));
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 25
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_sigOut_c);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[3] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[3] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 1));
          }
        }
      }
    }

    /* --------------- START Packing signal 7 ------------------
     *  startBit                = 26
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_sigOut_d);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[3] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[3] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 2));
          }
        }
      }
    }

    /* --------------- START Packing signal 8 ------------------
     *  startBit                = 20
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_sigOut_ej);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[2] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[2] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 4));
          }
        }
      }
    }

    /* --------------- START Packing signal 9 ------------------
     *  startBit                = 21
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_sigOut_bv);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[2] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[2] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 5));
          }
        }
      }
    }

    /* --------------- START Packing signal 10 ------------------
     *  startBit                = 18
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_sigOut_a);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[2] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[2] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 2));
          }
        }
      }
    }

    /* --------------- START Packing signal 11 ------------------
     *  startBit                = 23
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_sigOut_i);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[2] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[2] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 7));
          }
        }
      }
    }

    /* --------------- START Packing signal 12 ------------------
     *  startBit                = 17
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_sigOut_a5);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[2] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[2] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 1));
          }
        }
      }
    }

    /* --------------- START Packing signal 13 ------------------
     *  startBit                = 27
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_sigOut_ib);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[3] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[3] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 3));
          }
        }
      }
    }

    /* --------------- START Packing signal 14 ------------------
     *  startBit                = 29
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_sigOut_p3);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[3] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[3] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 5));
          }
        }
      }
    }

    /* --------------- START Packing signal 15 ------------------
     *  startBit                = 28
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_sigOut_dc);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[3] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[3] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 4));
          }
        }
      }
    }

    /* --------------- START Packing signal 16 ------------------
     *  startBit                = 10
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_sigOut_cp);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[1] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 2));
          }
        }
      }
    }

    /* --------------- START Packing signal 17 ------------------
     *  startBit                = 9
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_sigOut_b5);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[1] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 1));
          }
        }
      }
    }

    /* --------------- START Packing signal 18 ------------------
     *  startBit                = 31
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_sigOut_j);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[3] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[3] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 7));
          }
        }
      }
    }

    /* --------------- START Packing signal 19 ------------------
     *  startBit                = 30
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_sigOut_ei);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[3] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[3] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 6));
          }
        }
      }
    }

    /* --------------- START Packing signal 20 ------------------
     *  startBit                = 15
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_sigOut_k1);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[1] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 7));
          }
        }
      }
    }

    /* --------------- START Packing signal 21 ------------------
     *  startBit                = 0
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_sigOut_oe);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[0] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[0] | (uint8_T)((uint8_T)
              (packedValue & (uint8_T)0x1U));
          }
        }
      }
    }

    /* --------------- START Packing signal 22 ------------------
     *  startBit                = 14
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_sigOut_as);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[1] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 6));
          }
        }
      }
    }

    /* --------------- START Packing signal 23 ------------------
     *  startBit                = 1
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_sigOut_j1);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[0] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 1));
          }
        }
      }
    }

    /* --------------- START Packing signal 24 ------------------
     *  startBit                = 13
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_sigOut_l);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[1] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 5));
          }
        }
      }
    }

    /* --------------- START Packing signal 25 ------------------
     *  startBit                = 4
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_sigOut_bz);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[0] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 4));
          }
        }
      }
    }

    /* --------------- START Packing signal 26 ------------------
     *  startBit                = 11
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (PowerCtrolProject1_S32K144_B.NISP_sigOut_m);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[1] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 3));
          }
        }
      }
    }

    /* --------------- START Packing signal 27 ------------------
     *  startBit                = 12
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_sigOut_jb);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[1] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[1] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 4));
          }
        }
      }
    }

    /* --------------- START Packing signal 28 ------------------
     *  startBit                = 16
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_sigOut_oe5);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[2] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[2] | (uint8_T)((uint8_T)
              (packedValue & (uint8_T)0x1U));
          }
        }
      }
    }

    /* --------------- START Packing signal 29 ------------------
     *  startBit                = 3
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_sigOut_hs);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[0] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 3));
          }
        }
      }
    }

    /* --------------- START Packing signal 30 ------------------
     *  startBit                = 5
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_sigOut_nc);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[0] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 5));
          }
        }
      }
    }

    /* --------------- START Packing signal 31 ------------------
     *  startBit                = 6
     *  length                  = 1
     *  desiredSignalByteLayout = BIGENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (PowerCtrolProject1_S32K144_B.NISP_sigOut_km);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (boolean_T)(1)) {
          packedValue = (uint8_T) 1;
        } else if (packingValue < (boolean_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[0] =
              PowerCtrolProject1_S32K144_Y.CAN2TX2h.Data[0] | (uint8_T)((uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U) << 6));
          }
        }
      }
    }
  }

  /* End of Outputs for SubSystem: '<S36>/Subsystem23' */
  /* End of Outputs for SubSystem: '<S4>/HSPO_500ms' */

  /* BusCreator: '<Root>/Bus Creator3' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant8'
   *  Inport: '<Root>/In2'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX202h.Extended =
    PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic1;
  PowerCtrolProject1_S32K144_B.CAN1RX202h.Length = can_rx_msg.CAN1_DLC202h;
  PowerCtrolProject1_S32K144_B.CAN1RX202h.Remote = 0U;
  PowerCtrolProject1_S32K144_B.CAN1RX202h.Error = 0U;

  /* Switch: '<Root>/Switch1' */
  if (PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic1 != 0) {
    /* BusCreator: '<Root>/Bus Creator3' incorporates:
     *  Constant: '<Root>/Constant9'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX202h.ID = 0U;
  } else {
    /* BusCreator: '<Root>/Bus Creator3' incorporates:
     *  Inport: '<Root>/In3'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX202h.ID = can_rx_msg.CAN1_StdId202h;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* BusCreator: '<Root>/Bus Creator3' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Inport: '<Root>/In4'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX202h.Timestamp = 0.0;
  for (i = 0; i < 8; i++) {
    PowerCtrolProject1_S32K144_B.CAN1RX202h.Data[i] = can_rx_msg.CAN1_Data202h[i];
  }

  /* S-Function (scanunpack): '<S7>/CANRXUnPack_BMS_202h' */
  {
    /* S-Function (scanunpack): '<S7>/CANRXUnPack_BMS_202h' */
    if ((8 == PowerCtrolProject1_S32K144_B.CAN1RX202h.Length) &&
        (PowerCtrolProject1_S32K144_B.CAN1RX202h.ID != INVALID_CAN_ID) ) {
      if ((514 == PowerCtrolProject1_S32K144_B.CAN1RX202h.ID) && (0U ==
           PowerCtrolProject1_S32K144_B.CAN1RX202h.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 8
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.001
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX202h.Data[1]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX202h.Data[0]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.001;
              PowerCtrolProject1_S32K144_B.BMS_Max_cell_voltage = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 16
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX202h.Data[2]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Max_cell_voltage_No = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 32
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.001
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX202h.Data[4]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX202h.Data[3]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.001;
              PowerCtrolProject1_S32K144_B.BMS_Min_cell_voltage = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 40
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX202h.Data[5]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Min_cell_voltage_No = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 56
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX202h.Data[7]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX202h.Data[6]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.1;
              PowerCtrolProject1_S32K144_B.BMS_SOH = result;
            }
          }
        }
      }
    }
  }

  /* BusCreator: '<Root>/Bus Creator19' incorporates:
   *  Constant: '<Root>/Constant85'
   *  Constant: '<Root>/Constant88'
   *  Inport: '<Root>/In52'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX418h.Extended =
    PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic17;
  PowerCtrolProject1_S32K144_B.CAN1RX418h.Length = can_rx_msg.CAN1_DLC418h;
  PowerCtrolProject1_S32K144_B.CAN1RX418h.Remote = 0U;
  PowerCtrolProject1_S32K144_B.CAN1RX418h.Error = 0U;

  /* Switch: '<Root>/Switch17' */
  if (PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic17 != 0) {
    /* BusCreator: '<Root>/Bus Creator19' incorporates:
     *  Constant: '<Root>/Constant89'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX418h.ID = 0U;
  } else {
    /* BusCreator: '<Root>/Bus Creator19' incorporates:
     *  Inport: '<Root>/In53'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX418h.ID = can_rx_msg.CAN1_StdId418h;
  }

  /* End of Switch: '<Root>/Switch17' */

  /* BusCreator: '<Root>/Bus Creator19' incorporates:
   *  Constant: '<Root>/Constant86'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX418h.Timestamp = 0.0;

  /* BusCreator: '<Root>/Bus Creator18' incorporates:
   *  Constant: '<Root>/Constant80'
   *  Constant: '<Root>/Constant83'
   *  Inport: '<Root>/In49'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX266h.Extended =
    PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic16;
  PowerCtrolProject1_S32K144_B.CAN1RX266h.Length = can_rx_msg.CAN1_DLC266h;
  PowerCtrolProject1_S32K144_B.CAN1RX266h.Remote = 0U;
  PowerCtrolProject1_S32K144_B.CAN1RX266h.Error = 0U;

  /* Switch: '<Root>/Switch16' */
  if (PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic16 != 0) {
    /* BusCreator: '<Root>/Bus Creator18' incorporates:
     *  Constant: '<Root>/Constant84'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX266h.ID = 0U;
  } else {
    /* BusCreator: '<Root>/Bus Creator18' incorporates:
     *  Inport: '<Root>/In50'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX266h.ID = can_rx_msg.CAN1_StdId266h;
  }

  /* End of Switch: '<Root>/Switch16' */

  /* BusCreator: '<Root>/Bus Creator18' incorporates:
   *  Constant: '<Root>/Constant81'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX266h.Timestamp = 0.0;

  /* BusCreator: '<Root>/Bus Creator8' incorporates:
   *  Constant: '<Root>/Constant22'
   *  Constant: '<Root>/Constant25'
   *  Inport: '<Root>/In19'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX208h.Extended =
    PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic6;
  PowerCtrolProject1_S32K144_B.CAN1RX208h.Length = can_rx_msg.CAN1_DLC208h;
  PowerCtrolProject1_S32K144_B.CAN1RX208h.Remote = 0U;
  PowerCtrolProject1_S32K144_B.CAN1RX208h.Error = 0U;

  /* Switch: '<Root>/Switch6' */
  if (PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic6 != 0) {
    /* BusCreator: '<Root>/Bus Creator8' incorporates:
     *  Constant: '<Root>/Constant26'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX208h.ID = 0U;
  } else {
    /* BusCreator: '<Root>/Bus Creator8' incorporates:
     *  Inport: '<Root>/In20'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX208h.ID = can_rx_msg.CAN1_StdId208h;
  }

  /* End of Switch: '<Root>/Switch6' */

  /* BusCreator: '<Root>/Bus Creator8' incorporates:
   *  Constant: '<Root>/Constant23'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX208h.Timestamp = 0.0;

  /* BusCreator: '<Root>/Bus Creator7' incorporates:
   *  Constant: '<Root>/Constant35'
   *  Constant: '<Root>/Constant38'
   *  Inport: '<Root>/In16'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX207h.Extended =
    PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic5;
  PowerCtrolProject1_S32K144_B.CAN1RX207h.Length = can_rx_msg.CAN1_DLC207h;
  PowerCtrolProject1_S32K144_B.CAN1RX207h.Remote = 0U;
  PowerCtrolProject1_S32K144_B.CAN1RX207h.Error = 0U;

  /* Switch: '<Root>/Switch5' */
  if (PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic5 != 0) {
    /* BusCreator: '<Root>/Bus Creator7' incorporates:
     *  Constant: '<Root>/Constant39'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX207h.ID = 0U;
  } else {
    /* BusCreator: '<Root>/Bus Creator7' incorporates:
     *  Inport: '<Root>/In17'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX207h.ID = can_rx_msg.CAN1_StdId207h;
  }

  /* End of Switch: '<Root>/Switch5' */

  /* BusCreator: '<Root>/Bus Creator7' incorporates:
   *  Constant: '<Root>/Constant36'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX207h.Timestamp = 0.0;

  /* BusCreator: '<Root>/Bus Creator4' incorporates:
   *  Constant: '<Root>/Constant10'
   *  Constant: '<Root>/Constant13'
   *  Inport: '<Root>/In5'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX203h.Extended =
    PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic2;
  PowerCtrolProject1_S32K144_B.CAN1RX203h.Length = can_rx_msg.CAN1_DLC203h;
  PowerCtrolProject1_S32K144_B.CAN1RX203h.Remote = 0U;
  PowerCtrolProject1_S32K144_B.CAN1RX203h.Error = 0U;

  /* Switch: '<Root>/Switch2' */
  if (PowerCtrolProject1_S32K1_ConstB.ShiftArithmetic2 != 0) {
    /* BusCreator: '<Root>/Bus Creator4' incorporates:
     *  Constant: '<Root>/Constant14'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX203h.ID = 0U;
  } else {
    /* BusCreator: '<Root>/Bus Creator4' incorporates:
     *  Inport: '<Root>/In7'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX203h.ID = can_rx_msg.CAN1_StdId203h;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* BusCreator: '<Root>/Bus Creator4' incorporates:
   *  Constant: '<Root>/Constant11'
   */
  PowerCtrolProject1_S32K144_B.CAN1RX203h.Timestamp = 0.0;
  for (i = 0; i < 8; i++) {
    /* BusCreator: '<Root>/Bus Creator19' incorporates:
     *  Inport: '<Root>/In54'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX418h.Data[i] = can_rx_msg.CAN1_Data418h[i];

    /* BusCreator: '<Root>/Bus Creator18' incorporates:
     *  Inport: '<Root>/In51'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX266h.Data[i] = can_rx_msg.CAN1_Data266h[i];

    /* BusCreator: '<Root>/Bus Creator8' incorporates:
     *  Inport: '<Root>/In21'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX208h.Data[i] = can_rx_msg.CAN1_Data208h[i];

    /* BusCreator: '<Root>/Bus Creator7' incorporates:
     *  Inport: '<Root>/In18'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX207h.Data[i] = can_rx_msg.CAN1_Data207h[i];

    /* BusCreator: '<Root>/Bus Creator4' incorporates:
     *  Inport: '<Root>/In9'
     */
    PowerCtrolProject1_S32K144_B.CAN1RX203h.Data[i] = can_rx_msg.CAN1_Data203h[i];
  }

  /* S-Function (scanunpack): '<S8>/CANRXUnPack_BMS_203h' */
  {
    /* S-Function (scanunpack): '<S8>/CANRXUnPack_BMS_203h' */
    if ((8 == PowerCtrolProject1_S32K144_B.CAN1RX203h.Length) &&
        (PowerCtrolProject1_S32K144_B.CAN1RX203h.ID != INVALID_CAN_ID) ) {
      if ((515 == PowerCtrolProject1_S32K144_B.CAN1RX203h.ID) && (0U ==
           PowerCtrolProject1_S32K144_B.CAN1RX203h.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = -40.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX203h.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result + -40.0;
              PowerCtrolProject1_S32K144_B.BMS_Max_cell_temp = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 8
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX203h.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Max_cell_temp_No = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 16
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = -40.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX203h.Data[2]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result + -40.0;
              PowerCtrolProject1_S32K144_B.BMS_Min_cell_temp = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 24
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX203h.Data[3]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Min_cell_temp_No = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 56
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX203h.Data[7]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX203h.Data[6]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.1;
              PowerCtrolProject1_S32K144_B.BMS_Negative_insulated = result;
            }
          }

          /* --------------- START Unpacking signal 5 ------------------
           *  startBit                = 40
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX203h.Data[5]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX203h.Data[4]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.1;
              PowerCtrolProject1_S32K144_B.BMS_Positive_insulated = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S11>/CANRXUnPack_BMS_207h' */
  {
    /* S-Function (scanunpack): '<S11>/CANRXUnPack_BMS_207h' */
    if ((8 == PowerCtrolProject1_S32K144_B.CAN1RX207h.Length) &&
        (PowerCtrolProject1_S32K144_B.CAN1RX207h.ID != INVALID_CAN_ID) ) {
      if ((519 == PowerCtrolProject1_S32K144_B.CAN1RX207h.ID) && (0U ==
           PowerCtrolProject1_S32K144_B.CAN1RX207h.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX207h.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Cellinfo_Total = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 24
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.001
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX207h.Data[3]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX207h.Data[2]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.001;
              PowerCtrolProject1_S32K144_B.BMS_Cellinfo_VnPlus1 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 40
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.001
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX207h.Data[5]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX207h.Data[4]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.001;
              PowerCtrolProject1_S32K144_B.BMS_Cellinfo_VnPlus2 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 56
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.001
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX207h.Data[7]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX207h.Data[6]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.001;
              PowerCtrolProject1_S32K144_B.BMS_Cellinfo_VnPlus3 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 8
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX207h.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Cellnfo_GroupNo = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S12>/CANRXUnPack_BMS_208h' */
  {
    /* S-Function (scanunpack): '<S12>/CANRXUnPack_BMS_208h' */
    if ((8 == PowerCtrolProject1_S32K144_B.CAN1RX208h.Length) &&
        (PowerCtrolProject1_S32K144_B.CAN1RX208h.ID != INVALID_CAN_ID) ) {
      if ((520 == PowerCtrolProject1_S32K144_B.CAN1RX208h.ID) && (0U ==
           PowerCtrolProject1_S32K144_B.CAN1RX208h.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 8
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX208h.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Celltemp_GroupNo = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 0
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX208h.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.BMS_Celltemp_Total = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 16
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = -40.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX208h.Data[2]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result + -40.0;
              PowerCtrolProject1_S32K144_B.BMS_Celltemp_VnPlus1 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 24
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = -40.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX208h.Data[3]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result + -40.0;
              PowerCtrolProject1_S32K144_B.BMS_Celltemp_VnPlus2 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 32
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = -40.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX208h.Data[4]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result + -40.0;
              PowerCtrolProject1_S32K144_B.BMS_Celltemp_VnPlus3 = result;
            }
          }

          /* --------------- START Unpacking signal 5 ------------------
           *  startBit                = 40
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = -40.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX208h.Data[5]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result + -40.0;
              PowerCtrolProject1_S32K144_B.BMS_Celltemp_VnPlus4 = result;
            }
          }

          /* --------------- START Unpacking signal 6 ------------------
           *  startBit                = 48
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = -40.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX208h.Data[6]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result + -40.0;
              PowerCtrolProject1_S32K144_B.BMS_Celltemp_VnPlus5 = result;
            }
          }

          /* --------------- START Unpacking signal 7 ------------------
           *  startBit                = 56
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = -40.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX208h.Data[7]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result + -40.0;
              PowerCtrolProject1_S32K144_B.BMS_Celltemp_VnPlus6 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S19>/CANRXUnPack_EAC_266h' */
  {
    /* S-Function (scanunpack): '<S19>/CANRXUnPack_EAC_266h' */
    if ((8 == PowerCtrolProject1_S32K144_B.CAN1RX266h.Length) &&
        (PowerCtrolProject1_S32K144_B.CAN1RX266h.ID != INVALID_CAN_ID) ) {
      if ((614 == PowerCtrolProject1_S32K144_B.CAN1RX266h.ID) && (0U ==
           PowerCtrolProject1_S32K144_B.CAN1RX266h.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 40
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX266h.Data[5]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX266h.Data[4]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.1;
              PowerCtrolProject1_S32K144_B.EAC_ActualPower = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 8
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 4.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX266h.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 4.0;
              PowerCtrolProject1_S32K144_B.EAC_CompInputDCVoltage = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 0
           *  length                  = 8
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX266h.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.1;
              PowerCtrolProject1_S32K144_B.EAC_CompRunCurrent = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 48
           *  length                  = 6
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX266h.Data[6]) & (uint8_T)
                    (0x3FU));
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.EAC_ErrorInfomation = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 28
           *  length                  = 12
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX266h.Data[3]) &
                    (uint16_T)(0xF0U)) >> 4);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX266h.Data[2]) << 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              PowerCtrolProject1_S32K144_B.EAC_RPM = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S23>/CANRXUnPack_0x418' */
  {
    /* S-Function (scanunpack): '<S23>/CANRXUnPack_0x418' */
    if ((8 == PowerCtrolProject1_S32K144_B.CAN1RX418h.Length) &&
        (PowerCtrolProject1_S32K144_B.CAN1RX418h.ID != INVALID_CAN_ID) ) {
      if ((1048 == PowerCtrolProject1_S32K144_B.CAN1RX418h.ID) && (0U ==
           PowerCtrolProject1_S32K144_B.CAN1RX418h.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 24
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.01
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX418h.Data[3]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX418h.Data[2]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.01;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x418_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 8
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.01
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX418h.Data[1]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX418h.Data[0]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.01;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x418_o2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 56
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.01
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX418h.Data[7]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX418h.Data[6]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.01;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x418_o3 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 40
           *  length                  = 16
           *  desiredSignalByteLayout = BIGENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.01
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX418h.Data[5]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (PowerCtrolProject1_S32K144_B.CAN1RX418h.Data[4]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              result = result * 0.01;
              PowerCtrolProject1_S32K144_B.CANRXUnPack_0x418_o4 = result;
            }
          }
        }
      }
    }
  }

  /* Chart: '<S160>/Initialization' incorporates:
   *  Constant: '<S6>/CANActv_BMS_201h'
   */
  PowerCtrolProjec_Initialization(true, &PowerCtrolProject1_S32K144_B.CANInt_cq);

  /* Outputs for Enabled SubSystem: '<S160>/CANDiagnosis' */
  /* Constant: '<S6>/CANActv_BMS_201h' incorporates:
   *  Constant: '<S155>/KISP_VldChkBMS201hCANActvDec_cnt'
   *  Constant: '<S155>/KISP_VldChkBMS201hCANActvInc_cnt'
   *  Constant: '<S155>/KISP_VldChkBMS201hCANActvLim_cnt'
   */
  PowerCtrolProject1_CANDiagnosis(PowerCtrolProject1_S32K144_B.CANInt_cq, true,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.CANDiagnosis,
    &PowerCtrolProject1_S32K14_DWork.CANDiagnosis);

  /* End of Outputs for SubSystem: '<S160>/CANDiagnosis' */

  /* Chart: '<S202>/Initialization' incorporates:
   *  Constant: '<S7>/CANActv_BMS_202h'
   */
  PowerCtrolProjec_Initialization(true, &PowerCtrolProject1_S32K144_B.CANInt_g5);

  /* Outputs for Enabled SubSystem: '<S202>/CANDiagnosis' */
  /* Constant: '<S7>/CANActv_BMS_202h' incorporates:
   *  Constant: '<S196>/KISP_VldChkBMS202hCANActvDec_cnt'
   *  Constant: '<S196>/KISP_VldChkBMS202hCANActvInc_cnt'
   *  Constant: '<S196>/KISP_VldChkBMS202hCANActvLim_cnt'
   */
  PowerCtrolProject1_CANDiagnosis(PowerCtrolProject1_S32K144_B.CANInt_g5, true,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.CANDiagnosis_l,
    &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_l);

  /* End of Outputs for SubSystem: '<S202>/CANDiagnosis' */

  /* DataTypeConversion: '<S7>/Convert ofVHSPI_BMSMaxCellUNo_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Max_cell_voltage_No < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Max_cell_voltage_No >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Max_cell_voltage_No;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S7>/Convert ofVHSPI_BMSMaxCellUNo_enum' */

  /* Outputs for Atomic SubSystem: '<S210>/signal validity checking' */
  /* DataTypeConversion: '<S210>/Data Type Conversion' incorporates:
   *  Constant: '<S133>/Bus Selector_SigVld3'
   *  Constant: '<S197>/KISP_VldChkBMSMaxCellUNoDec_cnt'
   *  Constant: '<S197>/KISP_VldChkBMSMaxCellUNoInc_cnt'
   *  Constant: '<S197>/KISP_VldChkBMSMaxCellUNoLim_cnt'
   *  Constant: '<S210>/False'
   *  Logic: '<S210>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_as, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_la, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_b);

  /* End of Outputs for SubSystem: '<S210>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S7>/Convert ofVHSPI_BMSMaxCellU_V'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Max_cell_voltage;

  /* Outputs for Atomic SubSystem: '<S216>/signal validity checking' */
  /* Logic: '<S216>/Logical Operator1' incorporates:
   *  Constant: '<S133>/Bus Selector_SigVld2'
   *  Constant: '<S198>/KISP_BMSMaxCellUDft_V'
   *  Constant: '<S198>/KISP_VldChkBMSMaxCellUDec_cnt'
   *  Constant: '<S198>/KISP_VldChkBMSMaxCellUInc_cnt'
   *  Constant: '<S198>/KISP_VldChkBMSMaxCellULim_cnt'
   *  Constant: '<S216>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_du,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_bf);

  /* End of Outputs for SubSystem: '<S216>/signal validity checking' */

  /* DataTypeConversion: '<S7>/Convert ofVHSPI_BMSMinCellUNo_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Min_cell_voltage_No < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Min_cell_voltage_No >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Min_cell_voltage_No;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S7>/Convert ofVHSPI_BMSMinCellUNo_enum' */

  /* Outputs for Atomic SubSystem: '<S223>/signal validity checking' */
  /* DataTypeConversion: '<S223>/Data Type Conversion' incorporates:
   *  Constant: '<S133>/Bus Selector_SigVld5'
   *  Constant: '<S199>/KISP_VldChkBMSMinCellUNoDec_cnt'
   *  Constant: '<S199>/KISP_VldChkBMSMinCellUNoInc_cnt'
   *  Constant: '<S199>/KISP_VldChkBMSMinCellUNoLim_cnt'
   *  Constant: '<S223>/False'
   *  Logic: '<S223>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_er, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_gq, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_e);

  /* End of Outputs for SubSystem: '<S223>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S7>/Convert ofVHSPI_BMSMinCellU_V'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Min_cell_voltage;

  /* Outputs for Atomic SubSystem: '<S229>/signal validity checking' */
  /* Logic: '<S229>/Logical Operator1' incorporates:
   *  Constant: '<S133>/Bus Selector_SigVld4'
   *  Constant: '<S200>/KISP_BMSMinCellUDft_V'
   *  Constant: '<S200>/KISP_VldChkBMSMinCellUDec_cnt'
   *  Constant: '<S200>/KISP_VldChkBMSMinCellUInc_cnt'
   *  Constant: '<S200>/KISP_VldChkBMSMinCellULim_cnt'
   *  Constant: '<S229>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_lxl,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_c);

  /* End of Outputs for SubSystem: '<S229>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S7>/Convert ofVHSPI_BMSSOH_pct'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_SOH;

  /* Outputs for Atomic SubSystem: '<S236>/signal validity checking' */
  /* Logic: '<S236>/Logical Operator1' incorporates:
   *  Constant: '<S133>/Bus Selector_SigVld6'
   *  Constant: '<S201>/KISP_BMSSOHDft_pct'
   *  Constant: '<S201>/KISP_VldChkBMSSOHDec_cnt'
   *  Constant: '<S201>/KISP_VldChkBMSSOHInc_cnt'
   *  Constant: '<S201>/KISP_VldChkBMSSOHLim_cnt'
   *  Constant: '<S236>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_ojo,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_k);

  /* End of Outputs for SubSystem: '<S236>/signal validity checking' */

  /* Chart: '<S250>/Initialization' incorporates:
   *  Constant: '<S8>/CANActv_BMS_203h'
   */
  PowerCtrolProjec_Initialization(true, &PowerCtrolProject1_S32K144_B.CANInt_g);

  /* Outputs for Enabled SubSystem: '<S250>/CANDiagnosis' */
  /* Constant: '<S8>/CANActv_BMS_203h' incorporates:
   *  Constant: '<S243>/KISP_VldChkBMS203hCANActvDec_cnt'
   *  Constant: '<S243>/KISP_VldChkBMS203hCANActvInc_cnt'
   *  Constant: '<S243>/KISP_VldChkBMS203hCANActvLim_cnt'
   */
  PowerCtrolProject1_CANDiagnosis(PowerCtrolProject1_S32K144_B.CANInt_g, true,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.CANDiagnosis_lh,
    &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_lh);

  /* End of Outputs for SubSystem: '<S250>/CANDiagnosis' */

  /* DataTypeConversion: '<S8>/Convert ofVHSPI_BMSMaxCellTNo_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Max_cell_temp_No < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Max_cell_temp_No >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.BMS_Max_cell_temp_No;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S8>/Convert ofVHSPI_BMSMaxCellTNo_enum' */

  /* Outputs for Atomic SubSystem: '<S258>/signal validity checking' */
  /* DataTypeConversion: '<S258>/Data Type Conversion' incorporates:
   *  Constant: '<S134>/Bus Selector_SigVld3'
   *  Constant: '<S244>/KISP_VldChkBMSMaxCellTNoDec_cnt'
   *  Constant: '<S244>/KISP_VldChkBMSMaxCellTNoInc_cnt'
   *  Constant: '<S244>/KISP_VldChkBMSMaxCellTNoLim_cnt'
   *  Constant: '<S258>/False'
   *  Logic: '<S258>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_gp, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_kk, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_bt);

  /* End of Outputs for SubSystem: '<S258>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S8>/Convert ofVHSPI_BMSMaxCellT_deg'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Max_cell_temp;

  /* Outputs for Atomic SubSystem: '<S264>/signal validity checking' */
  /* Logic: '<S264>/Logical Operator1' incorporates:
   *  Constant: '<S134>/Bus Selector_SigVld2'
   *  Constant: '<S245>/KISP_BMSMaxCellTDft_deg'
   *  Constant: '<S245>/KISP_VldChkBMSMaxCellTDec_cnt'
   *  Constant: '<S245>/KISP_VldChkBMSMaxCellTInc_cnt'
   *  Constant: '<S245>/KISP_VldChkBMSMaxCellTLim_cnt'
   *  Constant: '<S264>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_jg,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_d);

  /* End of Outputs for SubSystem: '<S264>/signal validity checking' */

  /* DataTypeConversion: '<S8>/Convert ofVHSPI_BMSMinCellTNo_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Min_cell_temp_No < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Min_cell_temp_No >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.BMS_Min_cell_temp_No;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S8>/Convert ofVHSPI_BMSMinCellTNo_enum' */

  /* Outputs for Atomic SubSystem: '<S271>/signal validity checking' */
  /* DataTypeConversion: '<S271>/Data Type Conversion' incorporates:
   *  Constant: '<S134>/Bus Selector_SigVld5'
   *  Constant: '<S246>/KISP_VldChkBMSMinCellTNoDec_cnt'
   *  Constant: '<S246>/KISP_VldChkBMSMinCellTNoInc_cnt'
   *  Constant: '<S246>/KISP_VldChkBMSMinCellTNoLim_cnt'
   *  Constant: '<S271>/False'
   *  Logic: '<S271>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_d5, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_gi, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ba);

  /* End of Outputs for SubSystem: '<S271>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S8>/Convert ofVHSPI_BMSMinCellT_deg'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Min_cell_temp;

  /* Outputs for Atomic SubSystem: '<S277>/signal validity checking' */
  /* Logic: '<S277>/Logical Operator1' incorporates:
   *  Constant: '<S134>/Bus Selector_SigVld4'
   *  Constant: '<S247>/KISP_BMSMinCellTDft_deg'
   *  Constant: '<S247>/KISP_VldChkBMSMinCellTDec_cnt'
   *  Constant: '<S247>/KISP_VldChkBMSMinCellTInc_cnt'
   *  Constant: '<S247>/KISP_VldChkBMSMinCellTLim_cnt'
   *  Constant: '<S277>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_nz,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ky);

  /* End of Outputs for SubSystem: '<S277>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S8>/Convert ofVHSPI_BMSNegInsultd_kohm'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Negative_insulated;

  /* Outputs for Atomic SubSystem: '<S284>/signal validity checking' */
  /* Logic: '<S284>/Logical Operator1' incorporates:
   *  Constant: '<S134>/Bus Selector_SigVld6'
   *  Constant: '<S248>/KISP_BMSNegInsultdDft_kohm'
   *  Constant: '<S248>/KISP_VldChkBMSNegInsultdDec_cnt'
   *  Constant: '<S248>/KISP_VldChkBMSNegInsultdInc_cnt'
   *  Constant: '<S248>/KISP_VldChkBMSNegInsultdLim_cnt'
   *  Constant: '<S284>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_ex,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_f);

  /* End of Outputs for SubSystem: '<S284>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S8>/Convert ofVHSPI_BMSPosInsultd_kohm'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Positive_insulated;

  /* Outputs for Atomic SubSystem: '<S291>/signal validity checking' */
  /* Logic: '<S291>/Logical Operator1' incorporates:
   *  Constant: '<S134>/Bus Selector_SigVld7'
   *  Constant: '<S249>/KISP_BMSPosInsultdDft_kohm'
   *  Constant: '<S249>/KISP_VldChkBMSPosInsultdDec_cnt'
   *  Constant: '<S249>/KISP_VldChkBMSPosInsultdInc_cnt'
   *  Constant: '<S249>/KISP_VldChkBMSPosInsultdLim_cnt'
   *  Constant: '<S291>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_p3,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_n);

  /* End of Outputs for SubSystem: '<S291>/signal validity checking' */

  /* DataTypeConversion: '<S9>/Convert ofVHSPI_BMSChrgRlySts_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Charge_relay_status < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Charge_relay_status >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Charge_relay_status;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S9>/Convert ofVHSPI_BMSChrgRlySts_enum' */

  /* Outputs for Atomic SubSystem: '<S332>/signal validity checking' */
  /* DataTypeConversion: '<S332>/Data Type Conversion' incorporates:
   *  Constant: '<S301>/KISP_VldChkBMSChrgRlyStsDec_cnt'
   *  Constant: '<S301>/KISP_VldChkBMSChrgRlyStsInc_cnt'
   *  Constant: '<S301>/KISP_VldChkBMSChrgRlyStsLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_j((real32_T)NISP_SigOut_i,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_i0, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_he, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_h,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_h);

  /* End of Outputs for SubSystem: '<S332>/signal validity checking' */

  /* DataTypeConversion: '<S9>/Convert ofVHSPI_BMSDCChrgRlySts_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_DC_charge_relay_status < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_DC_charge_relay_status >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_DC_charge_relay_status;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S9>/Convert ofVHSPI_BMSDCChrgRlySts_enum' */

  /* Outputs for Atomic SubSystem: '<S344>/signal validity checking' */
  /* DataTypeConversion: '<S344>/Data Type Conversion' incorporates:
   *  Constant: '<S303>/KISP_VldChkBMSDCChrgRlyStsDec_cnt'
   *  Constant: '<S303>/KISP_VldChkBMSDCChrgRlyStsInc_cnt'
   *  Constant: '<S303>/KISP_VldChkBMSDCChrgRlyStsLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_j((real32_T)NISP_SigOut_i,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_es, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_cj, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_i4,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_i4);

  /* End of Outputs for SubSystem: '<S344>/signal validity checking' */

  /* DataTypeConversion: '<S9>/Convert ofVHSPI_BMSDischargeChrgRlySts_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Discharge_relay_status < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Discharge_relay_status >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Discharge_relay_status;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S9>/Convert ofVHSPI_BMSDischargeChrgRlySts_enum' */

  /* Outputs for Atomic SubSystem: '<S350>/signal validity checking' */
  /* DataTypeConversion: '<S350>/Data Type Conversion' incorporates:
   *  Constant: '<S304>/KISP_VldChkBMSDischargeChrgRlyStsDec_cnt'
   *  Constant: '<S304>/KISP_VldChkBMSDischargeChrgRlyStsInc_cnt'
   *  Constant: '<S304>/KISP_VldChkBMSDischargeChrgRlyStsLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_j((real32_T)NISP_SigOut_i,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_bs, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_dwl, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_ka,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ka);

  /* End of Outputs for SubSystem: '<S350>/signal validity checking' */

  /* DataTypeConversion: '<S9>/Convert ofVHSPI_BMSHeatChrgRlySts_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Heating_charge_relay_status < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Heating_charge_relay_status >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Heating_charge_relay_status;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S9>/Convert ofVHSPI_BMSHeatChrgRlySts_enum' */

  /* Outputs for Atomic SubSystem: '<S356>/signal validity checking' */
  /* DataTypeConversion: '<S356>/Data Type Conversion' incorporates:
   *  Constant: '<S305>/KISP_VldChkBMSHeatChrgRlyStsDec_cnt'
   *  Constant: '<S305>/KISP_VldChkBMSHeatChrgRlyStsInc_cnt'
   *  Constant: '<S305>/KISP_VldChkBMSHeatChrgRlyStsLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_j((real32_T)NISP_SigOut_i,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_fk, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_ep, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_l,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_l);

  /* End of Outputs for SubSystem: '<S356>/signal validity checking' */

  /* DataTypeConversion: '<S9>/Convert ofVHSPI_BMSPrecRly_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Precharge_relay_status < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Precharge_relay_status >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Precharge_relay_status;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S9>/Convert ofVHSPI_BMSPrecRly_enum' */

  /* Outputs for Atomic SubSystem: '<S362>/signal validity checking' */
  /* DataTypeConversion: '<S362>/Data Type Conversion' incorporates:
   *  Constant: '<S306>/KISP_VldChkBMSPrecRlyDec_cnt'
   *  Constant: '<S306>/KISP_VldChkBMSPrecRlyInc_cnt'
   *  Constant: '<S306>/KISP_VldChkBMSPrecRlyLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_j((real32_T)NISP_SigOut_i,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_ft, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_de, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_p,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_p);

  /* End of Outputs for SubSystem: '<S362>/signal validity checking' */

  /* DataTypeConversion: '<S9>/Convert ofVHSPI_BMSTotPosRlySts_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Total_positive_relay_stat_f < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Total_positive_relay_stat_f >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_Total_positive_relay_stat_f;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S9>/Convert ofVHSPI_BMSTotPosRlySts_enum' */

  /* Outputs for Atomic SubSystem: '<S374>/signal validity checking' */
  /* DataTypeConversion: '<S374>/Data Type Conversion' incorporates:
   *  Constant: '<S308>/KISP_VldChkBMSTotPosRlyStsDec_cnt'
   *  Constant: '<S308>/KISP_VldChkBMSTotPosRlyStsInc_cnt'
   *  Constant: '<S308>/KISP_VldChkBMSTotPosRlyStsLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_j((real32_T)NISP_SigOut_i,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_k, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_g1, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_h3,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_h3);

  /* End of Outputs for SubSystem: '<S374>/signal validity checking' */

  /* DataTypeConversion: '<S9>/Convert ofVHSPI_ElecLockSts_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Eleclock_status < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Eleclock_status >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.BMS_Eleclock_status;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S9>/Convert ofVHSPI_ElecLockSts_enum' */

  /* Outputs for Atomic SubSystem: '<S380>/signal validity checking' */
  /* DataTypeConversion: '<S380>/Data Type Conversion' incorporates:
   *  Constant: '<S309>/KISP_VldChkElecLockStsDec_cnt'
   *  Constant: '<S309>/KISP_VldChkElecLockStsInc_cnt'
   *  Constant: '<S309>/KISP_VldChkElecLockStsLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_j((real32_T)NISP_SigOut_i,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_n2, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_nh, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_h31,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_h31);

  /* End of Outputs for SubSystem: '<S380>/signal validity checking' */

  /* Chart: '<S403>/Initialization' incorporates:
   *  Constant: '<S10>/CANActv_BMS_206h'
   */
  PowerCtrolProjec_Initialization(true, &PowerCtrolProject1_S32K144_B.CANInt_i2);

  /* Outputs for Enabled SubSystem: '<S403>/CANDiagnosis' */
  /* Constant: '<S10>/CANActv_BMS_206h' incorporates:
   *  Constant: '<S398>/KISP_VldChkBMS206hCANActvDec_cnt'
   *  Constant: '<S398>/KISP_VldChkBMS206hCANActvInc_cnt'
   *  Constant: '<S398>/KISP_VldChkBMS206hCANActvLim_cnt'
   */
  PowerCtrolProject1_CANDiagnosis(PowerCtrolProject1_S32K144_B.CANInt_i2, true,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.CANDiagnosis_c,
    &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_c);

  /* End of Outputs for SubSystem: '<S403>/CANDiagnosis' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S10>/Convert ofVHSPI_BMSContnsDcha_kw'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Continuous_Discharge_pw;

  /* Outputs for Atomic SubSystem: '<S418>/signal validity checking' */
  /* Logic: '<S418>/Logical Operator1' incorporates:
   *  Constant: '<S136>/Bus Selector_SigVld2'
   *  Constant: '<S400>/KISP_BMSContnsDchaDft_kw'
   *  Constant: '<S400>/KISP_VldChkBMSContnsDchaDec_cnt'
   *  Constant: '<S400>/KISP_VldChkBMSContnsDchaInc_cnt'
   *  Constant: '<S400>/KISP_VldChkBMSContnsDchaLim_cnt'
   *  Constant: '<S418>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_ml,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ck);

  /* End of Outputs for SubSystem: '<S418>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S10>/Convert ofVHSPI_BMSInstChrg_pw'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Instantaneous_charge_pw;

  /* Outputs for Atomic SubSystem: '<S425>/signal validity checking' */
  /* Logic: '<S425>/Logical Operator1' incorporates:
   *  Constant: '<S136>/Bus Selector_SigVld5'
   *  Constant: '<S401>/KISP_BMSInstChrgDft_pw'
   *  Constant: '<S401>/KISP_VldChkBMSInstChrgDec_cnt'
   *  Constant: '<S401>/KISP_VldChkBMSInstChrgInc_cnt'
   *  Constant: '<S401>/KISP_VldChkBMSInstChrgLim_cnt'
   *  Constant: '<S425>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_ky,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_dj);

  /* End of Outputs for SubSystem: '<S425>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S10>/Convert ofVHSPI_BMSInstDcha_pw'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Instantaneous_Discharge_pw;

  /* Outputs for Atomic SubSystem: '<S432>/signal validity checking' */
  /* Logic: '<S432>/Logical Operator1' incorporates:
   *  Constant: '<S136>/Bus Selector_SigVld4'
   *  Constant: '<S402>/KISP_BMSInstDchaDft_pw'
   *  Constant: '<S402>/KISP_VldChkBMSInstDchaDec_cnt'
   *  Constant: '<S402>/KISP_VldChkBMSInstDchaInc_cnt'
   *  Constant: '<S402>/KISP_VldChkBMSInstDchaLim_cnt'
   *  Constant: '<S432>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_cq,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ls);

  /* End of Outputs for SubSystem: '<S432>/signal validity checking' */

  /* Chart: '<S445>/Initialization' incorporates:
   *  Constant: '<S11>/CANActv_BMS_207h'
   */
  PowerCtrolProjec_Initialization(true, &PowerCtrolProject1_S32K144_B.CANInt_h);

  /* Outputs for Enabled SubSystem: '<S445>/CANDiagnosis' */
  /* Constant: '<S11>/CANActv_BMS_207h' incorporates:
   *  Constant: '<S439>/KISP_VldChkBMS207hCANActvDec_cnt'
   *  Constant: '<S439>/KISP_VldChkBMS207hCANActvInc_cnt'
   *  Constant: '<S439>/KISP_VldChkBMS207hCANActvLim_cnt'
   */
  PowerCtrolProject1_CANDiagnosis(PowerCtrolProject1_S32K144_B.CANInt_h, true,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.CANDiagnosis_f,
    &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_f);

  /* End of Outputs for SubSystem: '<S445>/CANDiagnosis' */

  /* DataTypeConversion: '<S11>/Convert ofVHSPI_BMSCellInfoGroupNo_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Cellnfo_GroupNo < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Cellnfo_GroupNo >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.BMS_Cellnfo_GroupNo;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S11>/Convert ofVHSPI_BMSCellInfoGroupNo_enum' */

  /* Outputs for Atomic SubSystem: '<S453>/signal validity checking' */
  /* DataTypeConversion: '<S453>/Data Type Conversion' incorporates:
   *  Constant: '<S137>/Bus Selector_SigVld6'
   *  Constant: '<S440>/KISP_VldChkBMSCellInfoGroupNoDec_cnt'
   *  Constant: '<S440>/KISP_VldChkBMSCellInfoGroupNoInc_cnt'
   *  Constant: '<S440>/KISP_VldChkBMSCellInfoGroupNoLim_cnt'
   *  Constant: '<S453>/False'
   *  Logic: '<S453>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_h3, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_cy, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_eg);

  /* End of Outputs for SubSystem: '<S453>/signal validity checking' */

  /* DataTypeConversion: '<S11>/Convert ofVHSPI_BMSCellInfoTot_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Cellinfo_Total < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Cellinfo_Total >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.BMS_Cellinfo_Total;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S11>/Convert ofVHSPI_BMSCellInfoTot_enum' */

  /* Outputs for Atomic SubSystem: '<S459>/signal validity checking' */
  /* DataTypeConversion: '<S459>/Data Type Conversion' incorporates:
   *  Constant: '<S137>/Bus Selector_SigVld2'
   *  Constant: '<S441>/KISP_VldChkBMSCellInfoTotDec_cnt'
   *  Constant: '<S441>/KISP_VldChkBMSCellInfoTotInc_cnt'
   *  Constant: '<S441>/KISP_VldChkBMSCellInfoTotLim_cnt'
   *  Constant: '<S459>/False'
   *  Logic: '<S459>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_in, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_hzg, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_pf);

  /* End of Outputs for SubSystem: '<S459>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S11>/Convert ofVHSPI_BMSCellInfoVnPlus1_V'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Cellinfo_VnPlus1;

  /* Outputs for Atomic SubSystem: '<S465>/signal validity checking' */
  /* Logic: '<S465>/Logical Operator1' incorporates:
   *  Constant: '<S137>/Bus Selector_SigVld3'
   *  Constant: '<S442>/KISP_BMSCellInfoVnPlus1Dft_V'
   *  Constant: '<S442>/KISP_VldChkBMSCellInfoVnPlus1Dec_cnt'
   *  Constant: '<S442>/KISP_VldChkBMSCellInfoVnPlus1Inc_cnt'
   *  Constant: '<S442>/KISP_VldChkBMSCellInfoVnPlus1Lim_cnt'
   *  Constant: '<S465>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_m0,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_nz);

  /* End of Outputs for SubSystem: '<S465>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S11>/Convert ofVHSPI_BMSCellInfoVnPlus2_V'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Cellinfo_VnPlus2;

  /* Outputs for Atomic SubSystem: '<S472>/signal validity checking' */
  /* Logic: '<S472>/Logical Operator1' incorporates:
   *  Constant: '<S137>/Bus Selector_SigVld4'
   *  Constant: '<S443>/KISP_BMSCellInfoVnPlus2Dft_V'
   *  Constant: '<S443>/KISP_VldChkBMSCellInfoVnPlus2Dec_cnt'
   *  Constant: '<S443>/KISP_VldChkBMSCellInfoVnPlus2Inc_cnt'
   *  Constant: '<S443>/KISP_VldChkBMSCellInfoVnPlus2Lim_cnt'
   *  Constant: '<S472>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_l3,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_iv);

  /* End of Outputs for SubSystem: '<S472>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S11>/Convert ofVHSPI_BMSCellInfoVnPlus3_V'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Cellinfo_VnPlus3;

  /* Outputs for Atomic SubSystem: '<S479>/signal validity checking' */
  /* Logic: '<S479>/Logical Operator1' incorporates:
   *  Constant: '<S137>/Bus Selector_SigVld5'
   *  Constant: '<S444>/KISP_BMSCellInfoVnPlus3Dft_V'
   *  Constant: '<S444>/KISP_VldChkBMSCellInfoVnPlus3Dec_cnt'
   *  Constant: '<S444>/KISP_VldChkBMSCellInfoVnPlus3Inc_cnt'
   *  Constant: '<S444>/KISP_VldChkBMSCellInfoVnPlus3Lim_cnt'
   *  Constant: '<S479>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_n2,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_kq);

  /* End of Outputs for SubSystem: '<S479>/signal validity checking' */

  /* Chart: '<S495>/Initialization' incorporates:
   *  Constant: '<S12>/CANActv_BMS_208h'
   */
  PowerCtrolProjec_Initialization(true, &PowerCtrolProject1_S32K144_B.CANInt_d);

  /* Outputs for Enabled SubSystem: '<S495>/CANDiagnosis' */
  /* Constant: '<S12>/CANActv_BMS_208h' incorporates:
   *  Constant: '<S486>/KISP_VldChkBMS208hCANActvDec_cnt'
   *  Constant: '<S486>/KISP_VldChkBMS208hCANActvInc_cnt'
   *  Constant: '<S486>/KISP_VldChkBMS208hCANActvLim_cnt'
   */
  PowerCtrolProject1_CANDiagnosis(PowerCtrolProject1_S32K144_B.CANInt_d, true,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.CANDiagnosis_p,
    &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_p);

  /* End of Outputs for SubSystem: '<S495>/CANDiagnosis' */

  /* DataTypeConversion: '<S12>/Convert ofVHSPI_BMSCellTGroupNo_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Celltemp_GroupNo < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Celltemp_GroupNo >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.BMS_Celltemp_GroupNo;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S12>/Convert ofVHSPI_BMSCellTGroupNo_enum' */

  /* Outputs for Atomic SubSystem: '<S503>/signal validity checking' */
  /* DataTypeConversion: '<S503>/Data Type Conversion' incorporates:
   *  Constant: '<S138>/Bus Selector_SigVld2'
   *  Constant: '<S487>/KISP_VldChkBMSCellTGroupNoDec_cnt'
   *  Constant: '<S487>/KISP_VldChkBMSCellTGroupNoInc_cnt'
   *  Constant: '<S487>/KISP_VldChkBMSCellTGroupNoLim_cnt'
   *  Constant: '<S503>/False'
   *  Logic: '<S503>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_if, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_cu, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_mp);

  /* End of Outputs for SubSystem: '<S503>/signal validity checking' */

  /* DataTypeConversion: '<S12>/Convert ofVHSPI_BMSCellTTot_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Celltemp_Total < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Celltemp_Total >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.BMS_Celltemp_Total;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S12>/Convert ofVHSPI_BMSCellTTot_enum' */

  /* Outputs for Atomic SubSystem: '<S509>/signal validity checking' */
  /* DataTypeConversion: '<S509>/Data Type Conversion' incorporates:
   *  Constant: '<S138>/Bus Selector_SigVld3'
   *  Constant: '<S488>/KISP_VldChkBMSCellTTotDec_cnt'
   *  Constant: '<S488>/KISP_VldChkBMSCellTTotInc_cnt'
   *  Constant: '<S488>/KISP_VldChkBMSCellTTotLim_cnt'
   *  Constant: '<S509>/False'
   *  Logic: '<S509>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_dnz, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_o3, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_gf);

  /* End of Outputs for SubSystem: '<S509>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S12>/Convert ofVHSPI_BMSCellTVnPlus1_deg'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Celltemp_VnPlus1;

  /* Outputs for Atomic SubSystem: '<S515>/signal validity checking' */
  /* Logic: '<S515>/Logical Operator1' incorporates:
   *  Constant: '<S138>/Bus Selector_SigVld4'
   *  Constant: '<S489>/KISP_BMSCellTVnPlus1Dft_deg'
   *  Constant: '<S489>/KISP_VldChkBMSCellTVnPlus1Dec_cnt'
   *  Constant: '<S489>/KISP_VldChkBMSCellTVnPlus1Inc_cnt'
   *  Constant: '<S489>/KISP_VldChkBMSCellTVnPlus1Lim_cnt'
   *  Constant: '<S515>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_e3,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_gb);

  /* End of Outputs for SubSystem: '<S515>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S12>/Convert ofVHSPI_BMSCellTVnPlus2_deg'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Celltemp_VnPlus2;

  /* Outputs for Atomic SubSystem: '<S522>/signal validity checking' */
  /* Logic: '<S522>/Logical Operator1' incorporates:
   *  Constant: '<S138>/Bus Selector_SigVld5'
   *  Constant: '<S490>/KISP_BMSCellTVnPlus2Dft_deg'
   *  Constant: '<S490>/KISP_VldChkBMSCellTVnPlus2Dec_cnt'
   *  Constant: '<S490>/KISP_VldChkBMSCellTVnPlus2Inc_cnt'
   *  Constant: '<S490>/KISP_VldChkBMSCellTVnPlus2Lim_cnt'
   *  Constant: '<S522>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_dp,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_pr);

  /* End of Outputs for SubSystem: '<S522>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S12>/Convert ofVHSPI_BMSCellTVnPlus3_deg'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Celltemp_VnPlus3;

  /* Outputs for Atomic SubSystem: '<S529>/signal validity checking' */
  /* Logic: '<S529>/Logical Operator1' incorporates:
   *  Constant: '<S138>/Bus Selector_SigVld6'
   *  Constant: '<S491>/KISP_BMSCellTVnPlus3Dft_deg'
   *  Constant: '<S491>/KISP_VldChkBMSCellTVnPlus3Dec_cnt'
   *  Constant: '<S491>/KISP_VldChkBMSCellTVnPlus3Inc_cnt'
   *  Constant: '<S491>/KISP_VldChkBMSCellTVnPlus3Lim_cnt'
   *  Constant: '<S529>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_am,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_dm);

  /* End of Outputs for SubSystem: '<S529>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S12>/Convert ofVHSPI_BMSCellTVnPlus4_deg'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Celltemp_VnPlus4;

  /* Outputs for Atomic SubSystem: '<S536>/signal validity checking' */
  /* Logic: '<S536>/Logical Operator1' incorporates:
   *  Constant: '<S138>/Bus Selector_SigVld7'
   *  Constant: '<S492>/KISP_BMSCellTVnPlus4Dft_deg'
   *  Constant: '<S492>/KISP_VldChkBMSCellTVnPlus4Dec_cnt'
   *  Constant: '<S492>/KISP_VldChkBMSCellTVnPlus4Inc_cnt'
   *  Constant: '<S492>/KISP_VldChkBMSCellTVnPlus4Lim_cnt'
   *  Constant: '<S536>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_bt,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_g4);

  /* End of Outputs for SubSystem: '<S536>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S12>/Convert ofVHSPI_BMSCellTVnPlus5_deg'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Celltemp_VnPlus5;

  /* Outputs for Atomic SubSystem: '<S543>/signal validity checking' */
  /* Logic: '<S543>/Logical Operator1' incorporates:
   *  Constant: '<S138>/Bus Selector_SigVld8'
   *  Constant: '<S493>/KISP_BMSCellTVnPlus5Dft_deg'
   *  Constant: '<S493>/KISP_VldChkBMSCellTVnPlus5Dec_cnt'
   *  Constant: '<S493>/KISP_VldChkBMSCellTVnPlus5Inc_cnt'
   *  Constant: '<S493>/KISP_VldChkBMSCellTVnPlus5Lim_cnt'
   *  Constant: '<S543>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_f0c,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ft);

  /* End of Outputs for SubSystem: '<S543>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S12>/Convert ofVHSPI_BMSCellTVnPlus6_deg'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Celltemp_VnPlus6;

  /* Outputs for Atomic SubSystem: '<S550>/signal validity checking' */
  /* Logic: '<S550>/Logical Operator1' incorporates:
   *  Constant: '<S138>/Bus Selector_SigVld9'
   *  Constant: '<S494>/KISP_BMSCellTVnPlus6Dft_deg'
   *  Constant: '<S494>/KISP_VldChkBMSCellTVnPlus6Dec_cnt'
   *  Constant: '<S494>/KISP_VldChkBMSCellTVnPlus6Inc_cnt'
   *  Constant: '<S494>/KISP_VldChkBMSCellTVnPlus6Lim_cnt'
   *  Constant: '<S550>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_pz,
                  &rtb_valid_signal_pd,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_cu);

  /* End of Outputs for SubSystem: '<S550>/signal validity checking' */

  /* Chart: '<S558>/Initialization' incorporates:
   *  Constant: '<S13>/CANActv_BMS_210h'
   */
  PowerCtrolProjec_Initialization(true, &PowerCtrolProject1_S32K144_B.CANInt_k);

  /* Outputs for Enabled SubSystem: '<S558>/CANDiagnosis' */
  /* Constant: '<S13>/CANActv_BMS_210h' incorporates:
   *  Constant: '<S557>/KISP_VldChkBMS210hCANActvDec_cnt'
   *  Constant: '<S557>/KISP_VldChkBMS210hCANActvInc_cnt'
   *  Constant: '<S557>/KISP_VldChkBMS210hCANActvLim_cnt'
   */
  PowerCtrolProject1_CANDiagnosis(PowerCtrolProject1_S32K144_B.CANInt_k, true,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.CANDiagnosis_h,
    &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_h);

  /* End of Outputs for SubSystem: '<S558>/CANDiagnosis' */

  /* Chart: '<S567>/Initialization' incorporates:
   *  Constant: '<S14>/CANActv_BMS_211h'
   */
  PowerCtrolProjec_Initialization(true, &PowerCtrolProject1_S32K144_B.CANInt_j);

  /* Outputs for Enabled SubSystem: '<S567>/CANDiagnosis' */
  /* Constant: '<S14>/CANActv_BMS_211h' incorporates:
   *  Constant: '<S566>/KISP_VldChkBMS211hCANActvDec_cnt'
   *  Constant: '<S566>/KISP_VldChkBMS211hCANActvInc_cnt'
   *  Constant: '<S566>/KISP_VldChkBMS211hCANActvLim_cnt'
   */
  PowerCtrolProject1_CANDiagnosis(PowerCtrolProject1_S32K144_B.CANInt_j, true,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.CANDiagnosis_lu,
    &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_lu);

  /* End of Outputs for SubSystem: '<S567>/CANDiagnosis' */

  /* Chart: '<S601>/Initialization' incorporates:
   *  Constant: '<S15>/CANActv_BMS_220h'
   */
  PowerCtrolProjec_Initialization(true, &PowerCtrolProject1_S32K144_B.CANInt_ca);

  /* Outputs for Enabled SubSystem: '<S601>/CANDiagnosis' */
  /* Constant: '<S15>/CANActv_BMS_220h' incorporates:
   *  Constant: '<S575>/KISP_VldChkBMS220hCANActvDec_cnt'
   *  Constant: '<S575>/KISP_VldChkBMS220hCANActvInc_cnt'
   *  Constant: '<S575>/KISP_VldChkBMS220hCANActvLim_cnt'
   */
  PowerCtrolProject1_CANDiagnosis(PowerCtrolProject1_S32K144_B.CANInt_ca, true,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.CANDiagnosis_a,
    &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_a);

  /* End of Outputs for SubSystem: '<S601>/CANDiagnosis' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSElecLockFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_EleLock_fault_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_EleLock_fault_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.BMS_EleLock_fault_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSElecLockFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S627>/signal validity checking' */
  /* DataTypeConversion: '<S627>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld5'
   *  Constant: '<S579>/KISP_VldChkBMSElecLockFltDec_cnt'
   *  Constant: '<S579>/KISP_VldChkBMSElecLockFltInc_cnt'
   *  Constant: '<S579>/KISP_VldChkBMSElecLockFltLim_cnt'
   *  Constant: '<S627>/False'
   *  Logic: '<S627>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_gn, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_jwc, &rtb_valid_signal_pd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_kn);

  /* End of Outputs for SubSystem: '<S627>/signal validity checking' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSTxOBCLostFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Tx_obc_lost_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Tx_obc_lost_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.BMS_Tx_obc_lost_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSTxOBCLostFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S723>/signal validity checking' */
  /* DataTypeConversion: '<S723>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld23'
   *  Constant: '<S595>/KISP_VldChkBMSTxOBCLostFltDec_cnt'
   *  Constant: '<S595>/KISP_VldChkBMSTxOBCLostFltInc_cnt'
   *  Constant: '<S595>/KISP_VldChkBMSTxOBCLostFltLim_cnt'
   *  Constant: '<S723>/False'
   *  Logic: '<S723>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_de, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_kc4, &rtb_valid_signal_em,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_o0);

  /* End of Outputs for SubSystem: '<S723>/signal validity checking' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_BMSTxVCULostFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Tx_vcu_lost_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Tx_vcu_lost_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.BMS_Tx_vcu_lost_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_BMSTxVCULostFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S729>/signal validity checking' */
  /* DataTypeConversion: '<S729>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld24'
   *  Constant: '<S596>/KISP_VldChkBMSTxVCULostFltDec_cnt'
   *  Constant: '<S596>/KISP_VldChkBMSTxVCULostFltInc_cnt'
   *  Constant: '<S596>/KISP_VldChkBMSTxVCULostFltLim_cnt'
   *  Constant: '<S729>/False'
   *  Logic: '<S729>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_ii, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_bp5, &rtb_valid_signal_co,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_jz);

  /* End of Outputs for SubSystem: '<S729>/signal validity checking' */

  /* DataTypeConversion: '<S15>/Convert ofVHSPI_SocHiFlt_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_Soc_high_Wa < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_Soc_high_Wa >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.BMS_Soc_high_Wa;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Convert ofVHSPI_SocHiFlt_enum' */

  /* Outputs for Atomic SubSystem: '<S747>/signal validity checking' */
  /* DataTypeConversion: '<S747>/Data Type Conversion' incorporates:
   *  Constant: '<S141>/Bus Selector_SigVld13'
   *  Constant: '<S599>/KISP_VldChkSocHiFltDec_cnt'
   *  Constant: '<S599>/KISP_VldChkSocHiFltInc_cnt'
   *  Constant: '<S599>/KISP_VldChkSocHiFltLim_cnt'
   *  Constant: '<S747>/False'
   *  Logic: '<S747>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_iv, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_ly, &rtb_valid_signal_nv,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_fj0);

  /* End of Outputs for SubSystem: '<S747>/signal validity checking' */

  /* Chart: '<S769>/Initialization' incorporates:
   *  Constant: '<S16>/CANActv_BMS_230h'
   */
  PowerCtrolProjec_Initialization(true, &PowerCtrolProject1_S32K144_B.CANInt_mj);

  /* Outputs for Enabled SubSystem: '<S769>/CANDiagnosis' */
  /* Constant: '<S16>/CANActv_BMS_230h' incorporates:
   *  Constant: '<S759>/KISP_VldChkBMS230hCANActvDec_cnt'
   *  Constant: '<S759>/KISP_VldChkBMS230hCANActvInc_cnt'
   *  Constant: '<S759>/KISP_VldChkBMS230hCANActvLim_cnt'
   */
  PowerCtrolProject1_CANDiagnosis(PowerCtrolProject1_S32K144_B.CANInt_mj, true,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.CANDiagnosis_d,
    &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_d);

  /* End of Outputs for SubSystem: '<S769>/CANDiagnosis' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S16>/Convert ofVHSPI_BMSCVEndI_A'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_CVEndCurrent;

  /* Outputs for Atomic SubSystem: '<S777>/signal validity checking' */
  /* Logic: '<S777>/Logical Operator1' incorporates:
   *  Constant: '<S142>/Bus Selector_SigVld2'
   *  Constant: '<S760>/KISP_BMSCVEndIDft_A'
   *  Constant: '<S760>/KISP_VldChkBMSCVEndIDec_cnt'
   *  Constant: '<S760>/KISP_VldChkBMSCVEndIInc_cnt'
   *  Constant: '<S760>/KISP_VldChkBMSCVEndILim_cnt'
   *  Constant: '<S777>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_me,
                  &rtb_valid_signal_iw,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_bfb);

  /* End of Outputs for SubSystem: '<S777>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S797>/signal validity checking' */
  /* DataTypeConversion: '<S797>/Data Type Conversion' incorporates:
   *  Constant: '<S142>/Bus Selector_SigVld3'
   *  Constant: '<S763>/KISP_VldChkBMSChrgReqDec_cnt'
   *  Constant: '<S763>/KISP_VldChkBMSChrgReqInc_cnt'
   *  Constant: '<S763>/KISP_VldChkBMSChrgReqLim_cnt'
   *  Constant: '<S797>/False'
   *  DataTypeConversion: '<S16>/Convert ofVHSPI_BMSChrgReq_flg'
   *  Logic: '<S797>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.BMS_Charge_request != 0.0), true, false, 20, 1,
    2, &PowerCtrolProject1_S32K144_B.fault_flg_bk, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_mb,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_mb);

  /* End of Outputs for SubSystem: '<S797>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S815>/signal validity checking' */
  /* DataTypeConversion: '<S815>/Data Type Conversion' incorporates:
   *  Constant: '<S142>/Bus Selector_SigVld8'
   *  Constant: '<S766>/KISP_VldChkDCDCWorkEnaDec_cnt'
   *  Constant: '<S766>/KISP_VldChkDCDCWorkEnaInc_cnt'
   *  Constant: '<S766>/KISP_VldChkDCDCWorkEnaLim_cnt'
   *  Constant: '<S815>/False'
   *  DataTypeConversion: '<S16>/Convert ofVHSPI_DCDCWorkEna_flg'
   *  Logic: '<S815>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.BMS_DCDC_Work_En != 0.0), true, false, 20, 1,
    2, &PowerCtrolProject1_S32K144_B.fault_flg_dg, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_nm,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_nm);

  /* End of Outputs for SubSystem: '<S815>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S16>/Convert ofVHSPI_MaxChrgI_A'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Max_charge_current;

  /* Outputs for Atomic SubSystem: '<S821>/signal validity checking' */
  /* Logic: '<S821>/Logical Operator1' incorporates:
   *  Constant: '<S142>/Bus Selector_SigVld9'
   *  Constant: '<S767>/KISP_MaxChrgIDft_A'
   *  Constant: '<S767>/KISP_VldChkMaxChrgIDec_cnt'
   *  Constant: '<S767>/KISP_VldChkMaxChrgIInc_cnt'
   *  Constant: '<S767>/KISP_VldChkMaxChrgILim_cnt'
   *  Constant: '<S821>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_ek,
                  &rtb_valid_signal_iw,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ik);

  /* End of Outputs for SubSystem: '<S821>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S16>/Convert ofVHSPI_MaxChrgU_V'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Max_charge_voltage;

  /* Outputs for Atomic SubSystem: '<S828>/signal validity checking' */
  /* Logic: '<S828>/Logical Operator1' incorporates:
   *  Constant: '<S142>/Bus Selector_SigVld10'
   *  Constant: '<S768>/KISP_MaxChrgUDft_V'
   *  Constant: '<S768>/KISP_VldChkMaxChrgUDec_cnt'
   *  Constant: '<S768>/KISP_VldChkMaxChrgUInc_cnt'
   *  Constant: '<S768>/KISP_VldChkMaxChrgULim_cnt'
   *  Constant: '<S828>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_bc,
                  &rtb_valid_signal_iw,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_fa);

  /* End of Outputs for SubSystem: '<S828>/signal validity checking' */

  /* Chart: '<S840>/Initialization' incorporates:
   *  Constant: '<S17>/CANActv_BMS_231h'
   */
  PowerCtrolProjec_Initialization(true, &PowerCtrolProject1_S32K144_B.CANInt_c);

  /* Outputs for Enabled SubSystem: '<S840>/CANDiagnosis' */
  /* Constant: '<S17>/CANActv_BMS_231h' incorporates:
   *  Constant: '<S835>/KISP_VldChkBMS231hCANActvDec_cnt'
   *  Constant: '<S835>/KISP_VldChkBMS231hCANActvInc_cnt'
   *  Constant: '<S835>/KISP_VldChkBMS231hCANActvLim_cnt'
   */
  PowerCtrolProject1_CANDiagnosis(PowerCtrolProject1_S32K144_B.CANInt_c, true,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.CANDiagnosis_b,
    &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_b);

  /* End of Outputs for SubSystem: '<S840>/CANDiagnosis' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S17>/Convert ofVHSPI_BMSChrgDurn_m'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Charging_duration;

  /* Outputs for Atomic SubSystem: '<S848>/signal validity checking' */
  /* Logic: '<S848>/Logical Operator1' incorporates:
   *  Constant: '<S143>/Bus Selector_SigVld2'
   *  Constant: '<S836>/KISP_BMSChrgDurnDft_m'
   *  Constant: '<S836>/KISP_VldChkBMSChrgDurnDec_cnt'
   *  Constant: '<S836>/KISP_VldChkBMSChrgDurnInc_cnt'
   *  Constant: '<S836>/KISP_VldChkBMSChrgDurnLim_cnt'
   *  Constant: '<S848>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_c2,
                  &rtb_valid_signal_iw,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_an);

  /* End of Outputs for SubSystem: '<S848>/signal validity checking' */

  /* DataTypeConversion: '<S17>/Convert ofVHSPI_BMSDCChrgSig_enum' */
  if (PowerCtrolProject1_S32K144_B.BMS_DC_charging_signal < 256.0) {
    if (PowerCtrolProject1_S32K144_B.BMS_DC_charging_signal >= 0.0) {
      NISP_SigOut_i = (uint8_T)
        PowerCtrolProject1_S32K144_B.BMS_DC_charging_signal;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S17>/Convert ofVHSPI_BMSDCChrgSig_enum' */

  /* Outputs for Atomic SubSystem: '<S861>/signal validity checking' */
  /* DataTypeConversion: '<S861>/Data Type Conversion' incorporates:
   *  Constant: '<S143>/Bus Selector_SigVld4'
   *  Constant: '<S838>/KISP_VldChkBMSDCChrgSigDec_cnt'
   *  Constant: '<S838>/KISP_VldChkBMSDCChrgSigInc_cnt'
   *  Constant: '<S838>/KISP_VldChkBMSDCChrgSigLim_cnt'
   *  Constant: '<S861>/False'
   *  Logic: '<S861>/Logical Operator1'
   */
  PowerCtrolProje_sig_valid_check((real32_T)NISP_SigOut_i, true, false,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_aym, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_dv, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_i3);

  /* End of Outputs for SubSystem: '<S861>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S17>/Convert ofVHSPI_BMSFullChrgnTi_m'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.BMS_Full_chargingtime;

  /* Outputs for Atomic SubSystem: '<S867>/signal validity checking' */
  /* Logic: '<S867>/Logical Operator1' incorporates:
   *  Constant: '<S143>/Bus Selector_SigVld5'
   *  Constant: '<S839>/KISP_BMSFullChrgnTiDft_m'
   *  Constant: '<S839>/KISP_VldChkBMSFullChrgnTiDec_cnt'
   *  Constant: '<S839>/KISP_VldChkBMSFullChrgnTiInc_cnt'
   *  Constant: '<S839>/KISP_VldChkBMSFullChrgnTiLim_cnt'
   *  Constant: '<S867>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_k0j,
                  &rtb_valid_signal_iw,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_cur);

  /* End of Outputs for SubSystem: '<S867>/signal validity checking' */

  /* Chart: '<S875>/Initialization' incorporates:
   *  Constant: '<S18>/CANActv_BMS_232h'
   */
  PowerCtrolProjec_Initialization(true, &PowerCtrolProject1_S32K144_B.CANInt_e);

  /* Outputs for Enabled SubSystem: '<S875>/CANDiagnosis' */
  /* Constant: '<S18>/CANActv_BMS_232h' incorporates:
   *  Constant: '<S874>/KISP_VldChkBMS232hCANActvDec_cnt'
   *  Constant: '<S874>/KISP_VldChkBMS232hCANActvInc_cnt'
   *  Constant: '<S874>/KISP_VldChkBMS232hCANActvLim_cnt'
   */
  PowerCtrolProject1_CANDiagnosis(PowerCtrolProject1_S32K144_B.CANInt_e, true,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.CANDiagnosis_m,
    &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_m);

  /* End of Outputs for SubSystem: '<S875>/CANDiagnosis' */

  /* Chart: '<S890>/Initialization' */
  PowerCtrolProj_Initialization_f
    (PowerCtrolProject1_S32K1_ConstB.VHSPI_CDU270hCANActv_flg,
     &PowerCtrolProject1_S32K144_B.CANInt_md);

  /* Outputs for Enabled SubSystem: '<S890>/CANDiagnosis' */
  /* Constant: '<S883>/KISP_VldChkCDU270hCANActvLim_cnt' incorporates:
   *  Constant: '<S883>/KISP_VldChkCDU270hCANActvDec_cnt'
   *  Constant: '<S883>/KISP_VldChkCDU270hCANActvInc_cnt'
   */
  PowerCtrolProjec_CANDiagnosis_j(PowerCtrolProject1_S32K144_B.CANInt_md, 20, 1,
    2, &PowerCtrolProject1_S32K144_B.CANDiagnosis_j,
    &PowerCtrolProject1_S32K1_ConstB.CANDiagnosis_j,
    &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_j);

  /* End of Outputs for SubSystem: '<S890>/CANDiagnosis' */

  /* Outputs for Atomic SubSystem: '<S904>/signal validity checking' */
  /* DataTypeConversion: '<S904>/Data Type Conversion' incorporates:
   *  Constant: '<S885>/KISP_VldChkOBCACReqDec_cnt'
   *  Constant: '<S885>/KISP_VldChkOBCACReqInc_cnt'
   *  Constant: '<S885>/KISP_VldChkOBCACReqLim_cnt'
   *  DataTypeConversion: '<S20>/Convert ofVHSPI_OBCACReq_flg'
   */
  PowerCtrolPro_sig_valid_check_f((real32_T)
    (PowerCtrolProject1_S32K144_B.OBC_AC_request != 0.0), 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_jd, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_gp,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_gp);

  /* End of Outputs for SubSystem: '<S904>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S20>/Convert ofVHSPI_OBCHVOutpI_A'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.OBC_HV_Output_Current;

  /* Outputs for Atomic SubSystem: '<S916>/signal validity checking' */
  /* Constant: '<S887>/KISP_OBCHVOutpIDft_A' incorporates:
   *  Constant: '<S887>/KISP_VldChkOBCHVOutpIDec_cnt'
   *  Constant: '<S887>/KISP_VldChkOBCHVOutpIInc_cnt'
   *  Constant: '<S887>/KISP_VldChkOBCHVOutpILim_cnt'
   */
  PowerCtrolPro_sig_valid_check_k(PowerCtrolProject1_S32K144_B.y, 0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_ln, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_jx,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_jx);

  /* End of Outputs for SubSystem: '<S916>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S20>/Convert ofVHSPI_OBCHVOutpU_V'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.OBC_HV_Output_Voltage;

  /* Outputs for Atomic SubSystem: '<S923>/signal validity checking' */
  /* Constant: '<S888>/KISP_OBCHVOutpUDft_V' incorporates:
   *  Constant: '<S888>/KISP_VldChkOBCHVOutpUDec_cnt'
   *  Constant: '<S888>/KISP_VldChkOBCHVOutpUInc_cnt'
   *  Constant: '<S888>/KISP_VldChkOBCHVOutpULim_cnt'
   */
  PowerCtrolPro_sig_valid_check_k(PowerCtrolProject1_S32K144_B.y, 0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_m5, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_ma,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ma);

  /* End of Outputs for SubSystem: '<S923>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S21>/Convert ofVHSPI_OBCOutpACI_A'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.OBC_OutputCurrent_AC;

  /* Outputs for Atomic SubSystem: '<S979>/signal validity checking' */
  /* Logic: '<S979>/Logical Operator1' incorporates:
   *  Constant: '<S146>/Bus Selector_SigVld5'
   *  Constant: '<S941>/KISP_OBCOutpACIDft_A'
   *  Constant: '<S941>/KISP_VldChkOBCOutpACIDec_cnt'
   *  Constant: '<S941>/KISP_VldChkOBCOutpACIInc_cnt'
   *  Constant: '<S941>/KISP_VldChkOBCOutpACILim_cnt'
   *  Constant: '<S979>/False'
   */
  sig_valid_check(PowerCtrolProject1_S32K144_B.y, true, false, 0.0F, 20, 1, 2,
                  &PowerCtrolProject1_S32K144_B.fault_flg_noc,
                  &rtb_valid_signal_iw,
                  &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_p5);

  /* End of Outputs for SubSystem: '<S979>/signal validity checking' */

  /* Chart: '<S1032>/Initialization' incorporates:
   *  Constant: '<S22>/CANActv_CDU_290h'
   */
  PowerCtrolProjec_Initialization(true, &PowerCtrolProject1_S32K144_B.CANInt_m);

  /* Outputs for Enabled SubSystem: '<S1032>/CANDiagnosis' */
  /* Constant: '<S22>/CANActv_CDU_290h' incorporates:
   *  Constant: '<S993>/KISP_VldChkCDU290hCANActvDec_cnt'
   *  Constant: '<S993>/KISP_VldChkCDU290hCANActvInc_cnt'
   *  Constant: '<S993>/KISP_VldChkCDU290hCANActvLim_cnt'
   */
  PowerCtrolProject1_CANDiagnosis(PowerCtrolProject1_S32K144_B.CANInt_m, true,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.CANDiagnosis_gv,
    &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_gv);

  /* End of Outputs for SubSystem: '<S1032>/CANDiagnosis' */

  /* Outputs for Atomic SubSystem: '<S1040>/signal validity checking' */
  /* DataTypeConversion: '<S1040>/Data Type Conversion' incorporates:
   *  Constant: '<S1040>/False'
   *  Constant: '<S147>/Bus Selector_SigVld3'
   *  Constant: '<S994>/KISP_VldChkCDUBMSCANMissFltDec_cnt'
   *  Constant: '<S994>/KISP_VldChkCDUBMSCANMissFltInc_cnt'
   *  Constant: '<S994>/KISP_VldChkCDUBMSCANMissFltLim_cnt'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUBMSCANMissFlt_flg'
   *  Logic: '<S1040>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgBMSCANMissing_AL != 0.0), true, false,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_j3, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_clj,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_clj);

  /* End of Outputs for SubSystem: '<S1040>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1064>/signal validity checking' */
  /* DataTypeConversion: '<S1064>/Data Type Conversion' incorporates:
   *  Constant: '<S1064>/False'
   *  Constant: '<S147>/Bus Selector_SigVld7'
   *  Constant: '<S998>/KISP_VldChkCDUChgEEpromErrDec_cnt'
   *  Constant: '<S998>/KISP_VldChkCDUChgEEpromErrInc_cnt'
   *  Constant: '<S998>/KISP_VldChkCDUChgEEpromErrLim_cnt'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgEEpromErr_flg'
   *  Logic: '<S1064>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgEepromError_AL != 0.0), true, false, 20,
    1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_nw, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_bc,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_bc);

  /* End of Outputs for SubSystem: '<S1064>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1100>/signal validity checking' */
  /* DataTypeConversion: '<S1100>/Data Type Conversion' incorporates:
   *  Constant: '<S1004>/KISP_VldChkCDUChgIntComErrDec_cnt'
   *  Constant: '<S1004>/KISP_VldChkCDUChgIntComErrInc_cnt'
   *  Constant: '<S1004>/KISP_VldChkCDUChgIntComErrLim_cnt'
   *  Constant: '<S1100>/False'
   *  Constant: '<S147>/Bus Selector_SigVld13'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgIntComErr_flg'
   *  Logic: '<S1100>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgInternalCommError_AL != 0.0), true,
    false, 20, 1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_k0,
    &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_iw,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_iw);

  /* End of Outputs for SubSystem: '<S1100>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1214>/signal validity checking' */
  /* DataTypeConversion: '<S1214>/Data Type Conversion' incorporates:
   *  Constant: '<S1023>/KISP_VldChkCDUChgRamChkErrDec_cnt'
   *  Constant: '<S1023>/KISP_VldChkCDUChgRamChkErrInc_cnt'
   *  Constant: '<S1023>/KISP_VldChkCDUChgRamChkErrLim_cnt'
   *  Constant: '<S1214>/False'
   *  Constant: '<S147>/Bus Selector_SigVld33'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgRamChkErr_flg'
   *  Logic: '<S1214>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgRamCheckError_AL != 0.0), true, false,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_ms, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_f0,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_f0);

  /* End of Outputs for SubSystem: '<S1214>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1232>/signal validity checking' */
  /* DataTypeConversion: '<S1232>/Data Type Conversion' incorporates:
   *  Constant: '<S1026>/KISP_VldChkCDUChgVCUCANMissFltDec_cnt'
   *  Constant: '<S1026>/KISP_VldChkCDUChgVCUCANMissFltInc_cnt'
   *  Constant: '<S1026>/KISP_VldChkCDUChgVCUCANMissFltLim_cnt'
   *  Constant: '<S1232>/False'
   *  Constant: '<S147>/Bus Selector_SigVld36'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_CDUChgVCUCANMissFlt_flg'
   *  Logic: '<S1232>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgVCUCANMissing_AL != 0.0), true, false,
    20, 1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_l2, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_ehd,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ehd);

  /* End of Outputs for SubSystem: '<S1232>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1256>/signal validity checking' */
  /* DataTypeConversion: '<S1256>/Data Type Conversion' incorporates:
   *  Constant: '<S1030>/KISP_VldChkChgCANBusOffFltDec_cnt'
   *  Constant: '<S1030>/KISP_VldChkChgCANBusOffFltInc_cnt'
   *  Constant: '<S1030>/KISP_VldChkChgCANBusOffFltLim_cnt'
   *  Constant: '<S1256>/False'
   *  Constant: '<S147>/Bus Selector_SigVld4'
   *  DataTypeConversion: '<S22>/Convert ofVHSPI_ChgCANBusOffFlt_flg'
   *  Logic: '<S1256>/Logical Operator1'
   */
  PowerCtrolPro_sig_valid_check_m((real32_T)
    (PowerCtrolProject1_S32K144_B.CDU_ChgCANBusOff_AL != 0.0), true, false, 20,
    1, 2, &PowerCtrolProject1_S32K144_B.fault_flg_js, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_np,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_np);

  /* End of Outputs for SubSystem: '<S1256>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1273>/signal validity checking' */
  /* Constant: '<S1268>/KISP_VldChkACPwrFocModLim_cnt' incorporates:
   *  Constant: '<S1268>/KISP_VldChkACPwrFocModDec_cnt'
   *  Constant: '<S1268>/KISP_VldChkACPwrFocModInc_cnt'
   */
  PowerCtrolPro_sig_valid_check_f
    (PowerCtrolProject1_S32K1_ConstB.DataTypeConversion, 20, 1, 2,
     &PowerCtrolProject1_S32K144_B.fault_flg_o, &rtb_valid_signal_iw,
     &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_nv,
     &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_nv);

  /* End of Outputs for SubSystem: '<S1273>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S23>/Convert ofVHSPI_OBCHLOutpI_A9'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.CANRXUnPack_0x418_o1;

  /* Outputs for Atomic SubSystem: '<S1279>/signal validity checking' */
  /* Constant: '<S1269>/KISP_WhlSpdReLeDft_kph' incorporates:
   *  Constant: '<S1269>/KISP_VldChkWhlSpdReLeDec_cnt'
   *  Constant: '<S1269>/KISP_VldChkWhlSpdReLeInc_cnt'
   *  Constant: '<S1269>/KISP_VldChkWhlSpdReLeLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_k(PowerCtrolProject1_S32K144_B.y, 0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_pj, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_ay,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ay);

  /* End of Outputs for SubSystem: '<S1279>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S23>/Convert ofVHSPI_OBCHLOutpI_A10'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.CANRXUnPack_0x418_o2;

  /* Outputs for Atomic SubSystem: '<S1286>/signal validity checking' */
  /* Constant: '<S1270>/KISP_WhlSpdReLeDft_kph' incorporates:
   *  Constant: '<S1270>/KISP_VldChkWhlSpdReLeDec_cnt'
   *  Constant: '<S1270>/KISP_VldChkWhlSpdReLeInc_cnt'
   *  Constant: '<S1270>/KISP_VldChkWhlSpdReLeLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_k(PowerCtrolProject1_S32K144_B.y, 0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_l5, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_fv,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_fv);

  /* End of Outputs for SubSystem: '<S1286>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S23>/Convert ofVHSPI_OBCHLOutpI_A11'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.CANRXUnPack_0x418_o3;

  /* Outputs for Atomic SubSystem: '<S1293>/signal validity checking' */
  /* Constant: '<S1271>/KISP_WhlSpdReLeDft_kph' incorporates:
   *  Constant: '<S1271>/KISP_VldChkWhlSpdReLeDec_cnt'
   *  Constant: '<S1271>/KISP_VldChkWhlSpdReLeInc_cnt'
   *  Constant: '<S1271>/KISP_VldChkWhlSpdReLeLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_k(PowerCtrolProject1_S32K144_B.y, 0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_fh, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_nf,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_nf);

  /* End of Outputs for SubSystem: '<S1293>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S23>/Convert ofVHSPI_OBCHLOutpI_A12'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.CANRXUnPack_0x418_o4;

  /* Outputs for Atomic SubSystem: '<S1300>/signal validity checking' */
  /* Constant: '<S1272>/KISP_WhlSpdReLeDft_kph' incorporates:
   *  Constant: '<S1272>/KISP_VldChkWhlSpdReLeDec_cnt'
   *  Constant: '<S1272>/KISP_VldChkWhlSpdReLeInc_cnt'
   *  Constant: '<S1272>/KISP_VldChkWhlSpdReLeLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_k(PowerCtrolProject1_S32K144_B.y, 0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_m, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_ij,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ij);

  /* End of Outputs for SubSystem: '<S1300>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1321>/signal validity checking' */
  /* Constant: '<S1307>/KISP_VldChkACPwrFocModLim_cnt' incorporates:
   *  Constant: '<S1307>/KISP_VldChkACPwrFocModDec_cnt'
   *  Constant: '<S1307>/KISP_VldChkACPwrFocModInc_cnt'
   */
  PowerCtrolPro_sig_valid_check_f
    (PowerCtrolProject1_S32K1_ConstB.DataTypeConversion_i, 20, 1, 2,
     &PowerCtrolProject1_S32K144_B.fault_flg_cz, &rtb_valid_signal_iw,
     &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_p5k,
     &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_p5k);

  /* End of Outputs for SubSystem: '<S1321>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1327>/signal validity checking' */
  /* DataTypeConversion: '<S1327>/Data Type Conversion' incorporates:
   *  Constant: '<S1308>/KISP_VldChkCDUChgCooltPlateOTPFltDec_cnt'
   *  Constant: '<S1308>/KISP_VldChkCDUChgCooltPlateOTPFltInc_cnt'
   *  Constant: '<S1308>/KISP_VldChkCDUChgCooltPlateOTPFltLim_cnt'
   *  DataTypeConversion: '<S24>/Convert ofVHSPI_OBCHLOutpI_A13'
   */
  PowerCtrolPro_sig_valid_check_f((real32_T)
    (PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o1_n != 0.0), 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_bp, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_b4,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_b4);

  /* End of Outputs for SubSystem: '<S1327>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1345>/signal validity checking' */
  /* DataTypeConversion: '<S1345>/Data Type Conversion' incorporates:
   *  Constant: '<S1311>/KISP_VldChkCDUChgCooltPlateOTPFltDec_cnt'
   *  Constant: '<S1311>/KISP_VldChkCDUChgCooltPlateOTPFltInc_cnt'
   *  Constant: '<S1311>/KISP_VldChkCDUChgCooltPlateOTPFltLim_cnt'
   *  DataTypeConversion: '<S24>/Convert ofVHSPI_OBCHLOutpI_A16'
   */
  PowerCtrolPro_sig_valid_check_f((real32_T)
    (PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o4_j != 0.0), 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_pq, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_n3,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_n3);

  /* End of Outputs for SubSystem: '<S1345>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S24>/Convert ofVHSPI_OBCHLOutpI_A17'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o5_c;

  /* Outputs for Atomic SubSystem: '<S1351>/signal validity checking' */
  /* Constant: '<S1312>/KISP_WhlSpdReLeDft_kph' incorporates:
   *  Constant: '<S1312>/KISP_VldChkWhlSpdReLeDec_cnt'
   *  Constant: '<S1312>/KISP_VldChkWhlSpdReLeInc_cnt'
   *  Constant: '<S1312>/KISP_VldChkWhlSpdReLeLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_k(PowerCtrolProject1_S32K144_B.y, 0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_lx, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_bo,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_bo);

  /* End of Outputs for SubSystem: '<S1351>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1365>/signal validity checking' */
  /* DataTypeConversion: '<S1365>/Data Type Conversion' incorporates:
   *  Constant: '<S1314>/KISP_VldChkCDUChgCooltPlateOTPFltDec_cnt'
   *  Constant: '<S1314>/KISP_VldChkCDUChgCooltPlateOTPFltInc_cnt'
   *  Constant: '<S1314>/KISP_VldChkCDUChgCooltPlateOTPFltLim_cnt'
   *  DataTypeConversion: '<S24>/Convert ofVHSPI_OBCHLOutpI_A19'
   */
  PowerCtrolPro_sig_valid_check_f((real32_T)
    (PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o7_c != 0.0), 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_kf, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_oq,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_oq);

  /* End of Outputs for SubSystem: '<S1365>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S24>/Convert ofVHSPI_OBCHLOutpI_A20'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o8_p;

  /* Outputs for Atomic SubSystem: '<S1371>/signal validity checking' */
  /* Constant: '<S1315>/KISP_WhlSpdReLeDft_kph' incorporates:
   *  Constant: '<S1315>/KISP_VldChkWhlSpdReLeDec_cnt'
   *  Constant: '<S1315>/KISP_VldChkWhlSpdReLeInc_cnt'
   *  Constant: '<S1315>/KISP_VldChkWhlSpdReLeLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_k(PowerCtrolProject1_S32K144_B.y, 0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_c0, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_kv,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_kv);

  /* End of Outputs for SubSystem: '<S1371>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1384>/signal validity checking' */
  /* DataTypeConversion: '<S1384>/Data Type Conversion' incorporates:
   *  Constant: '<S1317>/KISP_VldChkCDUChgCooltPlateOTPFltDec_cnt'
   *  Constant: '<S1317>/KISP_VldChkCDUChgCooltPlateOTPFltInc_cnt'
   *  Constant: '<S1317>/KISP_VldChkCDUChgCooltPlateOTPFltLim_cnt'
   *  DataTypeConversion: '<S24>/Convert ofVHSPI_OBCHLOutpI_A22'
   */
  PowerCtrolPro_sig_valid_check_f((real32_T)
    (PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o10 != 0.0), 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_fe, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_oc,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_oc);

  /* End of Outputs for SubSystem: '<S1384>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1390>/signal validity checking' */
  /* DataTypeConversion: '<S1390>/Data Type Conversion' incorporates:
   *  Constant: '<S1318>/KISP_VldChkCDUChgCooltPlateOTPFltDec_cnt'
   *  Constant: '<S1318>/KISP_VldChkCDUChgCooltPlateOTPFltInc_cnt'
   *  Constant: '<S1318>/KISP_VldChkCDUChgCooltPlateOTPFltLim_cnt'
   *  DataTypeConversion: '<S24>/Convert ofVHSPI_OBCHLOutpI_A23'
   */
  PowerCtrolPro_sig_valid_check_f((real32_T)
    (PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o11 != 0.0), 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_gx, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_lc,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_lc);

  /* End of Outputs for SubSystem: '<S1390>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1396>/signal validity checking' */
  /* DataTypeConversion: '<S1396>/Data Type Conversion' incorporates:
   *  Constant: '<S1319>/KISP_VldChkCDUChgCooltPlateOTPFltDec_cnt'
   *  Constant: '<S1319>/KISP_VldChkCDUChgCooltPlateOTPFltInc_cnt'
   *  Constant: '<S1319>/KISP_VldChkCDUChgCooltPlateOTPFltLim_cnt'
   *  DataTypeConversion: '<S24>/Convert ofVHSPI_OBCHLOutpI_A24'
   */
  PowerCtrolPro_sig_valid_check_f((real32_T)
    (PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o12 != 0.0), 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_h3, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_iy,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_iy);

  /* End of Outputs for SubSystem: '<S1396>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1402>/signal validity checking' */
  /* DataTypeConversion: '<S1402>/Data Type Conversion' incorporates:
   *  Constant: '<S1320>/KISP_VldChkCDUChgCooltPlateOTPFltDec_cnt'
   *  Constant: '<S1320>/KISP_VldChkCDUChgCooltPlateOTPFltInc_cnt'
   *  Constant: '<S1320>/KISP_VldChkCDUChgCooltPlateOTPFltLim_cnt'
   *  DataTypeConversion: '<S24>/Convert ofVHSPI_OBCHLOutpI_A25'
   */
  PowerCtrolPro_sig_valid_check_f((real32_T)
    (PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o13 != 0.0), 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_cl, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_oh,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_oh);

  /* End of Outputs for SubSystem: '<S1402>/signal validity checking' */

  /* Chart: '<S1414>/Initialization' */
  PowerCtrolProj_Initialization_f
    (PowerCtrolProject1_S32K1_ConstB.VHSPI_EAC266hCANActv_flg,
     &PowerCtrolProject1_S32K144_B.CANInt);

  /* Outputs for Enabled SubSystem: '<S1414>/CANDiagnosis' */
  /* Constant: '<S1408>/KISP_VldChkEAC266hCANActvLim_cnt' incorporates:
   *  Constant: '<S1408>/KISP_VldChkEAC266hCANActvDec_cnt'
   *  Constant: '<S1408>/KISP_VldChkEAC266hCANActvInc_cnt'
   */
  PowerCtrolProjec_CANDiagnosis_j(PowerCtrolProject1_S32K144_B.CANInt, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.CANDiagnosis_k,
    &PowerCtrolProject1_S32K1_ConstB.CANDiagnosis_k,
    &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_k);

  /* End of Outputs for SubSystem: '<S1414>/CANDiagnosis' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S19>/Convert ofVHSPI_EACActPwr_W'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.EAC_ActualPower;

  /* Outputs for Atomic SubSystem: '<S1422>/signal validity checking' */
  /* Constant: '<S1409>/KISP_EACActPwrDft_W' incorporates:
   *  Constant: '<S1409>/KISP_VldChkEACActPwrDec_cnt'
   *  Constant: '<S1409>/KISP_VldChkEACActPwrInc_cnt'
   *  Constant: '<S1409>/KISP_VldChkEACActPwrLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_k(PowerCtrolProject1_S32K144_B.y, 0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_gk, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_cly,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_cly);

  /* End of Outputs for SubSystem: '<S1422>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S19>/Convert ofVHSPI_EACCmprInpDCU_V'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.EAC_CompInputDCVoltage;

  /* Outputs for Atomic SubSystem: '<S1429>/signal validity checking' */
  /* Constant: '<S1410>/KISP_EACCmprInpDCUDft_V' incorporates:
   *  Constant: '<S1410>/KISP_VldChkEACCmprInpDCUDec_cnt'
   *  Constant: '<S1410>/KISP_VldChkEACCmprInpDCUInc_cnt'
   *  Constant: '<S1410>/KISP_VldChkEACCmprInpDCULim_cnt'
   */
  PowerCtrolPro_sig_valid_check_k(PowerCtrolProject1_S32K144_B.y, 0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_h2, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_bh,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_bh);

  /* End of Outputs for SubSystem: '<S1429>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S19>/Convert ofVHSPI_EACCmprRunI_A'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.EAC_CompRunCurrent;

  /* Outputs for Atomic SubSystem: '<S1436>/signal validity checking' */
  /* Constant: '<S1411>/KISP_EACCmprRunIDft_A' incorporates:
   *  Constant: '<S1411>/KISP_VldChkEACCmprRunIDec_cnt'
   *  Constant: '<S1411>/KISP_VldChkEACCmprRunIInc_cnt'
   *  Constant: '<S1411>/KISP_VldChkEACCmprRunILim_cnt'
   */
  PowerCtrolPro_sig_valid_check_k(PowerCtrolProject1_S32K144_B.y, 0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_eo, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_jao,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_jao);

  /* End of Outputs for SubSystem: '<S1436>/signal validity checking' */

  /* DataTypeConversion: '<S19>/Convert ofVHSPI_EACErrInfoFlt_flg' */
  if (PowerCtrolProject1_S32K144_B.EAC_ErrorInfomation < 256.0) {
    if (PowerCtrolProject1_S32K144_B.EAC_ErrorInfomation >= 0.0) {
      NISP_SigOut_i = (uint8_T)PowerCtrolProject1_S32K144_B.EAC_ErrorInfomation;
    } else {
      NISP_SigOut_i = 0U;
    }
  } else {
    NISP_SigOut_i = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S19>/Convert ofVHSPI_EACErrInfoFlt_flg' */

  /* Outputs for Atomic SubSystem: '<S1443>/signal validity checking' */
  /* DataTypeConversion: '<S1443>/Data Type Conversion' incorporates:
   *  Constant: '<S1412>/KISP_VldChkOBCInverterStsDec_cnt'
   *  Constant: '<S1412>/KISP_VldChkOBCInverterStsInc_cnt'
   *  Constant: '<S1412>/KISP_VldChkOBCInverterStsLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_j((real32_T)NISP_SigOut_i,
    PowerCtrolProject1_S32K1_ConstB.DataTypeConversion2_a0, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_gr, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_n5,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_n5);

  /* End of Outputs for SubSystem: '<S1443>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S19>/Convert ofVHSPI_EACSpd_rpm'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.EAC_RPM;

  /* Outputs for Atomic SubSystem: '<S1449>/signal validity checking' */
  /* Constant: '<S1413>/KISP_EACSpdDft_rpm' incorporates:
   *  Constant: '<S1413>/KISP_VldChkEACSpdDec_cnt'
   *  Constant: '<S1413>/KISP_VldChkEACSpdInc_cnt'
   *  Constant: '<S1413>/KISP_VldChkEACSpdLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_k(PowerCtrolProject1_S32K144_B.y, 0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_gt, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_ea,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ea);

  /* End of Outputs for SubSystem: '<S1449>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1485>/signal validity checking' */
  /* DataTypeConversion: '<S1485>/Data Type Conversion' incorporates:
   *  Constant: '<S1471>/KISP_VldChkACPwrFocModDec_cnt'
   *  Constant: '<S1471>/KISP_VldChkACPwrFocModInc_cnt'
   *  Constant: '<S1471>/KISP_VldChkACPwrFocModLim_cnt'
   *  Constant: '<S25>/Constant17'
   *  DataTypeConversion: '<S25>/Convert ofVHSPI_InverterEna_flg9'
   */
  PowerCtrolPro_sig_valid_check_f(0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_l, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_kk,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_kk);

  /* End of Outputs for SubSystem: '<S1485>/signal validity checking' */

  /* Lookup_n-D: '<S28>/1-D Lookup Table' incorporates:
   *  Constant: '<S25>/Constant18'
   *  DataTypeConversion: '<S25>/Convert ofVHSPI_InverterEna_flg10'
   *  Lookup_n-D: '<S27>/1-D Lookup Table'
   */
  rtb_valid_signal_iw = look1_iflf_binlx(0.0F,
    PowerCtrolProject1_S32K1_ConstP.pooled22,
    PowerCtrolProject1_S32K1_ConstP.pooled18, 32U);

  /* Outputs for Atomic SubSystem: '<S25>/Limiter1' */
  /* Switch: '<S30>/Switch1' incorporates:
   *  Constant: '<S25>/Constant1'
   *  Lookup_n-D: '<S28>/1-D Lookup Table'
   *  RelationalOperator: '<S30>/Relational Operator'
   */
  if (100.0F < rtb_valid_signal_iw) {
    /* Switch: '<S107>/Switch' */
    PowerCtrolProject1_S32K144_B.y = 100.0F;
  } else {
    /* Switch: '<S107>/Switch' */
    PowerCtrolProject1_S32K144_B.y = rtb_valid_signal_iw;
  }

  /* End of Switch: '<S30>/Switch1' */

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S25>/Constant2'
   *  RelationalOperator: '<S30>/Relational Operator1'
   */
  if (!(PowerCtrolProject1_S32K144_B.y > -100.0F)) {
    /* Switch: '<S107>/Switch' */
    PowerCtrolProject1_S32K144_B.y = -100.0F;
  }

  /* End of Switch: '<S30>/Switch' */
  /* End of Outputs for SubSystem: '<S25>/Limiter1' */

  /* Outputs for Atomic SubSystem: '<S1491>/signal validity checking' */
  /* Constant: '<S1472>/KISP_WhlSpdReLeDft_kph' incorporates:
   *  Constant: '<S1472>/KISP_VldChkWhlSpdReLeDec_cnt'
   *  Constant: '<S1472>/KISP_VldChkWhlSpdReLeInc_cnt'
   *  Constant: '<S1472>/KISP_VldChkWhlSpdReLeLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_k(PowerCtrolProject1_S32K144_B.y, 0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_jw, &rtb_valid_signal,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_km,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_km);

  /* End of Outputs for SubSystem: '<S1491>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1498>/signal validity checking' */
  /* DataTypeConversion: '<S1498>/Data Type Conversion' incorporates:
   *  Constant: '<S1473>/KISP_VldChkACPwrFocModDec_cnt'
   *  Constant: '<S1473>/KISP_VldChkACPwrFocModInc_cnt'
   *  Constant: '<S1473>/KISP_VldChkACPwrFocModLim_cnt'
   *  Constant: '<S25>/Constant'
   *  DataTypeConversion: '<S25>/Convert ofVHSPI_InverterEna_flg3'
   */
  PowerCtrolPro_sig_valid_check_f(1.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_e, &rtb_valid_signal,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_ii,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ii);

  /* End of Outputs for SubSystem: '<S1498>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S25>/Limiter' */
  /* Switch: '<S29>/Switch' incorporates:
   *  RelationalOperator: '<S29>/Relational Operator1'
   */
  if (PowerCtrolProject1_S32K1_ConstB.Switch1 > rtb_valid_signal_iw) {
    /* Switch: '<S107>/Switch' */
    PowerCtrolProject1_S32K144_B.y = PowerCtrolProject1_S32K1_ConstB.Switch1;
  } else {
    /* Switch: '<S107>/Switch' */
    PowerCtrolProject1_S32K144_B.y = rtb_valid_signal_iw;
  }

  /* End of Switch: '<S29>/Switch' */
  /* End of Outputs for SubSystem: '<S25>/Limiter' */

  /* Outputs for Atomic SubSystem: '<S1529>/signal validity checking' */
  /* Constant: '<S1478>/KISP_WhlSpdReLeDft_kph' incorporates:
   *  Constant: '<S1478>/KISP_VldChkWhlSpdReLeDec_cnt'
   *  Constant: '<S1478>/KISP_VldChkWhlSpdReLeInc_cnt'
   *  Constant: '<S1478>/KISP_VldChkWhlSpdReLeLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_k(PowerCtrolProject1_S32K144_B.y, 0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_hi, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_pt,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_pt);

  /* End of Outputs for SubSystem: '<S1529>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S25>/Convert ofVHSPI_InverterEna_flg7'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o4;

  /* Outputs for Atomic SubSystem: '<S1536>/signal validity checking' */
  /* Constant: '<S1479>/KISP_WhlSpdReLeDft_kph' incorporates:
   *  Constant: '<S1479>/KISP_VldChkWhlSpdReLeDec_cnt'
   *  Constant: '<S1479>/KISP_VldChkWhlSpdReLeInc_cnt'
   *  Constant: '<S1479>/KISP_VldChkWhlSpdReLeLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_k(PowerCtrolProject1_S32K144_B.y, 0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_h, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_cfs,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_cfs);

  /* End of Outputs for SubSystem: '<S1536>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S1549>/signal validity checking' */
  /* DataTypeConversion: '<S1549>/Data Type Conversion' incorporates:
   *  Constant: '<S1481>/KISP_VldChkACPwrFocModDec_cnt'
   *  Constant: '<S1481>/KISP_VldChkACPwrFocModInc_cnt'
   *  Constant: '<S1481>/KISP_VldChkACPwrFocModLim_cnt'
   *  DataTypeConversion: '<S25>/Convert ofVHSPI_InverterEna_flg6'
   */
  PowerCtrolPro_sig_valid_check_f((real32_T)
    (PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o6 != 0.0), 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_b, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_mpl,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_mpl);

  /* End of Outputs for SubSystem: '<S1549>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S25>/Convert ofVHSPI_InverterEna_flg12'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o8;

  /* Outputs for Atomic SubSystem: '<S1555>/signal validity checking' */
  /* Constant: '<S1482>/KISP_WhlSpdReLeDft_kph' incorporates:
   *  Constant: '<S1482>/KISP_VldChkWhlSpdReLeDec_cnt'
   *  Constant: '<S1482>/KISP_VldChkWhlSpdReLeInc_cnt'
   *  Constant: '<S1482>/KISP_VldChkWhlSpdReLeLim_cnt'
   */
  PowerCtrolPro_sig_valid_check_k(PowerCtrolProject1_S32K144_B.y, 0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_f, &rtb_valid_signal_iw,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_lv,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_lv);

  /* End of Outputs for SubSystem: '<S1555>/signal validity checking' */

  /* Switch: '<S107>/Switch' incorporates:
   *  DataTypeConversion: '<S25>/Convert ofVHSPI_InverterEna_flg11'
   */
  PowerCtrolProject1_S32K144_B.y = (real32_T)
    PowerCtrolProject1_S32K144_B.CANRXUnPack_0x419_o7;

  /* Outputs for Atomic SubSystem: '<S1563>/signal validity checking' */
  /* Outputs for Atomic SubSystem: '<S1563>/override signal' */
  /* SignalConversion: '<S1564>/TmpSignal ConversionAtSwitch1Inport3' incorporates:
   *  Constant: '<S1484>/KISP_VldChkWhlSpdReLeDec_cnt'
   *  Constant: '<S1484>/KISP_VldChkWhlSpdReLeInc_cnt'
   *  Constant: '<S1484>/KISP_VldChkWhlSpdReLeLim_cnt'
   *  Constant: '<S1484>/KISP_WhlSpdReLeDft_kph'
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  PowerCtrolPro_sig_valid_check_k(PowerCtrolProject1_S32K144_B.y, 0.0F, 20, 1, 2,
    &PowerCtrolProject1_S32K144_B.fault_flg_d,
    &PowerCtrolProject1_S32K14_DWork.UnitDelay2_293_DSTATE,
    &PowerCtrolProject1_S32K1_ConstB.signalvaliditychecking_k5,
    &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_k5);

  /* End of Outputs for SubSystem: '<S1563>/override signal' */
  /* End of Outputs for SubSystem: '<S1563>/signal validity checking' */

  /* Outputs for Atomic SubSystem: '<S747>/override signal' */
  /* MinMax: '<S119>/MinMax1' incorporates:
   *  DataTypeConversion: '<S627>/Data Type Conversion1'
   *  DataTypeConversion: '<S723>/Data Type Conversion1'
   *  DataTypeConversion: '<S729>/Data Type Conversion1'
   *  DataTypeConversion: '<S747>/Data Type Conversion1'
   *  SignalConversion: '<S628>/TmpSignal ConversionAtSwitch1Inport3'
   *  SignalConversion: '<S724>/TmpSignal ConversionAtSwitch1Inport3'
   *  SignalConversion: '<S730>/TmpSignal ConversionAtSwitch1Inport3'
   *  SignalConversion: '<S748>/TmpSignal ConversionAtSwitch1Inport3'
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  PowerCtrolProject1_S32K14_DWork.UnitDelay2_121_DSTATE = (uint8_T)
    rtb_valid_signal_nv;

  /* End of Outputs for SubSystem: '<S747>/override signal' */

  /* Outputs for Atomic SubSystem: '<S729>/override signal' */
  PowerCtrolProject1_S32K14_DWork.UnitDelay2_143_DSTATE = (uint8_T)
    rtb_valid_signal_co;

  /* End of Outputs for SubSystem: '<S729>/override signal' */

  /* Outputs for Atomic SubSystem: '<S723>/override signal' */
  PowerCtrolProject1_S32K14_DWork.UnitDelay2_141_DSTATE = (uint8_T)
    rtb_valid_signal_em;

  /* End of Outputs for SubSystem: '<S723>/override signal' */

  /* Outputs for Atomic SubSystem: '<S627>/override signal' */
  PowerCtrolProject1_S32K14_DWork.UnitDelay2_105_DSTATE = (uint8_T)
    rtb_valid_signal_pd;

  /* End of Outputs for SubSystem: '<S627>/override signal' */

  /* UnitDelay: '<S54>/Unit Delay1' incorporates:
   *  Delay: '<S66>/Delay'
   */
  PowerCtrolProject1_S32K14_DWork.Delay_DSTATE_g =
    PowerCtrolProject1_S32K14_DWork.UnitDelay1_DSTATE;

  /* Outputs for Atomic SubSystem: '<S386>/override signal' */
  /* Update for UnitDelay: '<S5>/Unit Delay2' incorporates:
   *  DataTypeConversion: '<S386>/Data Type Conversion1'
   *  SignalConversion: '<S387>/TmpSignal ConversionAtSwitch1Inport3'
   */
  PowerCtrolProject1_S32K14_DWork.UnitDelay2_57_DSTATE = (rtb_valid_signal_e5 !=
    0.0F);

  /* End of Outputs for SubSystem: '<S386>/override signal' */
  PowerCtrolProject1_S32K14_DWork.UnitDelay2_53_DSTATE =
    PowerCtrolProject1_S32K144_B.NISP_SigOut_a;

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  PowerCtrolProject1_S32K14_DWork.UnitDelay_11_DSTATE =
    PowerCtrolProject1_S32K144_B.VRCC_SetInverter_flg;

  /* Update for Delay: '<S118>/Delay' incorporates:
   *  Constant: '<S118>/Constant15'
   */
  PowerCtrolProject1_S32K14_DWork.Delay_DSTATE_d = true;

  /* Update for UnitDelay: '<S99>/Unit Delay2' incorporates:
   *  UnitDelay: '<S98>/Unit Delay'
   */
  PowerCtrolProject1_S32K14_DWork.UnitDelay2_DSTATE =
    PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_ih;

  /* Update for UnitDelay: '<S75>/Unit Delay' */
  PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_df = NISP_sigOut_k;

  /* Update for UnitDelay: '<S74>/Unit Delay2' */
  PowerCtrolProject1_S32K14_DWork.UnitDelay2_DSTATE_k = NISP_sigOut;

  /* Update for UnitDelay: '<S76>/Unit Delay' */
  PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_dg = RelationalOperator;

  /* Update for UnitDelay: '<S77>/Unit Delay' */
  PowerCtrolProject1_S32K14_DWork.UnitDelay_DSTATE_b = rtb_AND_a;

  /* Update for UnitDelay: '<S73>/Unit Delay2' */
  PowerCtrolProject1_S32K14_DWork.UnitDelay2_DSTATE_c = rtb_Compare_k;

  /* Update for Delay: '<S66>/Delay1' */
  PowerCtrolProject1_S32K14_DWork.Delay1_DSTATE = rtb_valid_signal_ft;

  /* Update for UnitDelay: '<S54>/Unit Delay1' */
  PowerCtrolProject1_S32K14_DWork.UnitDelay1_DSTATE =
    PowerCtrolProject1_S32K144_B.DCDC_KL15;
}

/* Model initialize function */
void PowerCtrolProject1_S32K144_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(PowerCtrolProject1_S32K144_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &PowerCtrolProject1_S32K144_B), 0,
                sizeof(BlockIO_PowerCtrolProject1_S32K));

  /* states (dwork) */
  (void) memset((void *)&PowerCtrolProject1_S32K14_DWork, 0,
                sizeof(D_Work_PowerCtrolProject1_S32K1));

  {
    real32_T rtb_valid_signal;

    /* Start for S-Function (scanunpack): '<S20>/CANRXUnPack_CDU_270h' */

    /*-----------S-Function Block: <S20>/CANRXUnPack_CDU_270h -----------------*/

    /* Start for S-Function (scanunpack): '<S9>/CANRXUnPack_BMS_204h' */

    /*-----------S-Function Block: <S9>/CANRXUnPack_BMS_204h -----------------*/

    /* Start for S-Function (scanunpack): '<S16>/CANRXUnPack_BMS_230h' */

    /*-----------S-Function Block: <S16>/CANRXUnPack_BMS_230h -----------------*/

    /* Start for S-Function (scanunpack): '<S2>/CANRXUnPack_RS485_Rx_03and1' */

    /*-----------S-Function Block: <S2>/CANRXUnPack_RS485_Rx_03and1 -----------------*/

    /* Start for S-Function (scanunpack): '<S21>/CANRXUnPack_CDU_280h' */

    /*-----------S-Function Block: <S21>/CANRXUnPack_CDU_280h -----------------*/

    /* Start for S-Function (scanunpack): '<S25>/CANRXUnPack_0x419' */

    /*-----------S-Function Block: <S25>/CANRXUnPack_0x419 -----------------*/

    /* Start for S-Function (scanunpack): '<S10>/CANRXUnPack_BMS_206h' */

    /*-----------S-Function Block: <S10>/CANRXUnPack_BMS_206h -----------------*/

    /* Start for S-Function (scanunpack): '<S6>/CANRXUnPack_BMS_201h' */

    /*-----------S-Function Block: <S6>/CANRXUnPack_BMS_201h -----------------*/

    /* Start for S-Function (scanunpack): '<S24>/CANRXUnPack_0x419' */

    /*-----------S-Function Block: <S24>/CANRXUnPack_0x419 -----------------*/

    /* Start for S-Function (scanunpack): '<S17>/CANRXUnPack_BMS_231h' */

    /*-----------S-Function Block: <S17>/CANRXUnPack_BMS_231h -----------------*/

    /* Start for S-Function (scanunpack): '<S15>/CANRXUnPack_BMS_220h' */

    /*-----------S-Function Block: <S15>/CANRXUnPack_BMS_220h -----------------*/

    /* Start for S-Function (scanunpack): '<S22>/CANRXUnPack_CDU_290h' */

    /*-----------S-Function Block: <S22>/CANRXUnPack_CDU_290h -----------------*/

    /* Start for S-Function (scanunpack): '<S7>/CANRXUnPack_BMS_202h' */

    /*-----------S-Function Block: <S7>/CANRXUnPack_BMS_202h -----------------*/

    /* Start for S-Function (scanunpack): '<S8>/CANRXUnPack_BMS_203h' */

    /*-----------S-Function Block: <S8>/CANRXUnPack_BMS_203h -----------------*/

    /* Start for S-Function (scanunpack): '<S11>/CANRXUnPack_BMS_207h' */

    /*-----------S-Function Block: <S11>/CANRXUnPack_BMS_207h -----------------*/

    /* Start for S-Function (scanunpack): '<S12>/CANRXUnPack_BMS_208h' */

    /*-----------S-Function Block: <S12>/CANRXUnPack_BMS_208h -----------------*/

    /* Start for S-Function (scanunpack): '<S19>/CANRXUnPack_EAC_266h' */

    /*-----------S-Function Block: <S19>/CANRXUnPack_EAC_266h -----------------*/

    /* Start for S-Function (scanunpack): '<S23>/CANRXUnPack_0x418' */

    /*-----------S-Function Block: <S23>/CANRXUnPack_0x418 -----------------*/

    /* SystemInitialize for Atomic SubSystem: '<S930>/signal validity checking' */
    PowerCtr_sig_valid_check_n_Init(&PowerCtrolProject1_S32K144_B.fault_flg_pkg,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_lq);

    /* End of SystemInitialize for SubSystem: '<S930>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S326>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_dg2,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_fl);

    /* End of SystemInitialize for SubSystem: '<S326>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S910>/signal validity checking' */
    PowerCtr_sig_valid_check_n_Init(&PowerCtrolProject1_S32K144_B.fault_flg_pe,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_kw);

    /* End of SystemInitialize for SubSystem: '<S910>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S784>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_c3e,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_gz);

    /* End of SystemInitialize for SubSystem: '<S784>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S803>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_nd,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_cl);

    /* End of SystemInitialize for SubSystem: '<S803>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S809>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_hf,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_o0x);

    /* End of SystemInitialize for SubSystem: '<S809>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S320>/signal validity checking' */
    PowerCtr_sig_valid_check_n_Init(&PowerCtrolProject1_S32K144_B.fault_flg_fu,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_jr);

    /* End of SystemInitialize for SubSystem: '<S320>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1579>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_a0h);

    /* End of SystemInitialize for SubSystem: '<S1579>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S790>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_fq,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_o4);

    /* End of SystemInitialize for SubSystem: '<S790>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S986>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_noq,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ax);

    /* End of SystemInitialize for SubSystem: '<S986>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S338>/signal validity checking' */
    PowerCtr_sig_valid_check_n_Init(&PowerCtrolProject1_S32K144_B.fault_flg_bj,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_i);

    /* End of SystemInitialize for SubSystem: '<S338>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1543>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_k,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_n0);

    /* End of SystemInitialize for SubSystem: '<S1543>/signal validity checking' */

    /* SystemInitialize for Chart: '<S65>/OBCInvertChrgChart' */
    PowerCtrolProject1_S32K14_DWork.is_ConnChrg =
      PowerCtrol_IN_NO_ACTIVE_CHILD_h;
    PowerCtrolProject1_S32K14_DWork.is_ACSuply = PowerCtrol_IN_NO_ACTIVE_CHILD_h;
    PowerCtrolProject1_S32K14_DWork.is_NoConnChrg =
      PowerCtrol_IN_NO_ACTIVE_CHILD_h;
    PowerCtrolProject1_S32K14_DWork.is_active_c3_PowerCtrolProject1 = 0U;
    PowerCtrolProject1_S32K14_DWork.is_c3_PowerCtrolProject1_S32K14 =
      PowerCtrol_IN_NO_ACTIVE_CHILD_h;
    PowerCtrolProject1_S32K14_DWork.TimeCounter = 0.0F;
    PowerCtrolProject1_S32K144_B.VRCC_OBCChrgCtrlr_enum = 0U;
    PowerCtrolProject1_S32K144_B.VRCC_ACOutRlyCtrlr_flg = false;
    PowerCtrolProject1_S32K144_B.VRCC_ACInpRlyCtrlr_flg = false;
    PowerCtrolProject1_S32K144_B.VRCC_InverterRly_flg = false;
    PowerCtrolProject1_S32K144_B.VRCC_SetInverter_flg = false;
    PowerCtrolProject1_S32K144_B.VRCC_ACChrgPwrF_kw = 0.0F;

    /* SystemInitialize for Atomic SubSystem: '<S1523>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_cf,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ll);

    /* End of SystemInitialize for SubSystem: '<S1523>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S386>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_mu,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_fo);

    /* End of SystemInitialize for SubSystem: '<S386>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1573>/signal validity checking' */
    PowerCtr_sig_valid_check_n_Init(&PowerCtrolProject1_S32K144_B.fault_flg_c,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_oez);

    /* End of SystemInitialize for SubSystem: '<S1573>/signal validity checking' */

    /* SystemInitialize for Chart: '<S312>/Initialization' */
    PowerCtro_Initialization_h_Init(&PowerCtrolProject1_S32K144_B.CANInt_c3);

    /* SystemInitialize for Enabled SubSystem: '<S312>/CANDiagnosis' */
    /* SystemInitialize for Atomic SubSystem: '<S313>/signal validity checking' */
    PowerCtr_sig_valid_check_l_Init(&PowerCtrolProject1_S32K144_B.fault_flg_ga,
      &PowerCtrolProject1_S32K144_B.valid_signal_c,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ku);

    /* End of SystemInitialize for SubSystem: '<S313>/signal validity checking' */
    /* End of SystemInitialize for SubSystem: '<S312>/CANDiagnosis' */

    /* SystemInitialize for Atomic SubSystem: '<S1504>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_j,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ad);

    /* End of SystemInitialize for SubSystem: '<S1504>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S368>/signal validity checking' */
    PowerCtr_sig_valid_check_n_Init(&PowerCtrolProject1_S32K144_B.fault_flg_eg,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_er);

    /* End of SystemInitialize for SubSystem: '<S368>/signal validity checking' */

    /* SystemInitialize for Enabled SubSystem: '<S49>/HeartBeat' */
    /* InitializeConditions for Delay: '<S53>/Delay' */
    PowerCtrolProject1_S32K14_DWork.Delay_DSTATE = 0U;

    /* End of SystemInitialize for SubSystem: '<S49>/HeartBeat' */

    /* SystemInitialize for Atomic SubSystem: '<S951>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_be,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_a0);

    /* End of SystemInitialize for SubSystem: '<S951>/signal validity checking' */

    /* SystemInitialize for Chart: '<S99>/Chart1' */
    PowerCtrolProject1__Chart1_Init(&PowerCtrolProject1_S32K14_DWork.sf_Chart1_h);

    /* SystemInitialize for Chart: '<S74>/Chart1' */
    PowerCtrolProject1__Chart1_Init(&PowerCtrolProject1_S32K14_DWork.sf_Chart1_j);

    /* SystemInitialize for Atomic SubSystem: '<S972>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_bd,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_gu);

    /* End of SystemInitialize for SubSystem: '<S972>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S411>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_pv,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_fj);

    /* End of SystemInitialize for SubSystem: '<S411>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S182>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_nw1,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_m);

    /* End of SystemInitialize for SubSystem: '<S182>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1378>/signal validity checking' */
    PowerCtr_sig_valid_check_n_Init(&PowerCtrolProject1_S32K144_B.fault_flg_kg,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_p3);

    /* End of SystemInitialize for SubSystem: '<S1378>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1333>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_b4,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_jo);

    /* End of SystemInitialize for SubSystem: '<S1333>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S965>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_hz,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_kqj);

    /* End of SystemInitialize for SubSystem: '<S965>/signal validity checking' */

    /* SystemInitialize for Chart: '<S73>/Chart1' */
    PowerCtrolProject1__Chart1_Init(&PowerCtrolProject1_S32K14_DWork.sf_Chart1);

    /* SystemInitialize for Atomic SubSystem: '<S1339>/signal validity checking' */
    PowerCtr_sig_valid_check_n_Init(&PowerCtrolProject1_S32K144_B.fault_flg_ju,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_a0x);

    /* End of SystemInitialize for SubSystem: '<S1339>/signal validity checking' */

    /* SystemInitialize for Chart: '<S55>/Chart' */
    PowerCtrolProject1_S32K14_DWork.is_DCDCOn = PowerCtrol_IN_NO_ACTIVE_CHILD_h;
    PowerCtrolProject1_S32K14_DWork.is_DCDCNormalWork =
      PowerCtrol_IN_NO_ACTIVE_CHILD_h;
    PowerCtrolProject1_S32K14_DWork.temporalCounter_i1 = 0U;
    PowerCtrolProject1_S32K14_DWork.is_active_c1_PowerCtrolProject1 = 0U;
    PowerCtrolProject1_S32K14_DWork.is_c1_PowerCtrolProject1_S32K14 =
      PowerCtrol_IN_NO_ACTIVE_CHILD_h;
    PowerCtrolProject1_S32K144_B.DCDCOutU = 0.0F;
    PowerCtrolProject1_S32K144_B.DCDCState = 0U;

    /* SystemInitialize for Gain: '<S67>/Gain' incorporates:
     *  Chart: '<S55>/Chart'
     */
    PowerCtrolProject1_S32K144_B.DCDCOutCurr = 0.0F;

    /* SystemInitialize for Chart: '<S55>/Chart' */
    PowerCtrolProject1_S32K144_B.VCU_Command_state = 0U;
    PowerCtrolProject1_S32K144_B.DCDC_KL15 = false;
    PowerCtrolProject1_S32K144_B.VCU_DCDC_OutputVoltageRequest = 0.0F;
    PowerCtrolProject1_S32K144_B.FaultCounter = 0U;

    /* SystemInitialize for Atomic SubSystem: '<S855>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_dw,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_li);

    /* End of SystemInitialize for SubSystem: '<S855>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S392>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_ft,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_m3);

    /* End of SystemInitialize for SubSystem: '<S392>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1510>/signal validity checking' */
    PowerCtr_sig_valid_check_l_Init(&PowerCtrolProject1_S32K144_B.fault_flg_g,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_fq);

    /* End of SystemInitialize for SubSystem: '<S1510>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1517>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_p,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ga);

    /* End of SystemInitialize for SubSystem: '<S1517>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S56>/Debounce' */
    /* SystemInitialize for Chart: '<S80>/DebounceState' */
    PowerCtrolProject1_S32K14_DWork.is_active_c2_ecartronic_lib = 0U;
    PowerCtrolProject1_S32K14_DWork.is_c2_ecartronic_lib =
      PowerCtrol_IN_NO_ACTIVE_CHILD_h;
    PowerCtrolProject1_S32K14_DWork.Local_Time_S = 0.0F;
    PowerCtrolProject1_S32K144_B.Out = false;

    /* End of SystemInitialize for SubSystem: '<S56>/Debounce' */

    /* SystemInitialize for Atomic SubSystem: '<S898>/signal validity checking' */
    PowerCtr_sig_valid_check_n_Init(&PowerCtrolProject1_S32K144_B.fault_flg_mh,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_kp);

    /* End of SystemInitialize for SubSystem: '<S898>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S958>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_p0,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_nb);

    /* End of SystemInitialize for SubSystem: '<S958>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1358>/signal validity checking' */
    PowerCtr_sig_valid_check_l_Init(&PowerCtrolProject1_S32K144_B.fault_flg_jp,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_nh);

    /* End of SystemInitialize for SubSystem: '<S1358>/signal validity checking' */

    /* SystemInitialize for Chart: '<S943>/Initialization' */
    PowerCtrolP_Initialization_Init(&PowerCtrolProject1_S32K144_B.CANInt_i);

    /* SystemInitialize for Enabled SubSystem: '<S943>/CANDiagnosis' */
    /* SystemInitialize for Atomic SubSystem: '<S944>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_do,
                         &PowerCtrolProject1_S32K144_B.valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_jxh);

    /* End of SystemInitialize for SubSystem: '<S944>/signal validity checking' */
    /* End of SystemInitialize for SubSystem: '<S943>/CANDiagnosis' */

    /* SystemInitialize for Atomic SubSystem: '<S168>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_jn,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking);

    /* End of SystemInitialize for SubSystem: '<S168>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S175>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_az,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_g);

    /* End of SystemInitialize for SubSystem: '<S175>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S189>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_kb,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_j);

    /* End of SystemInitialize for SubSystem: '<S189>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S609>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_hm,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_n4);

    /* End of SystemInitialize for SubSystem: '<S609>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S615>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_oy,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_pb);

    /* End of SystemInitialize for SubSystem: '<S615>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S621>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_ac,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_pe);

    /* End of SystemInitialize for SubSystem: '<S621>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S633>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_pc,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_o);

    /* End of SystemInitialize for SubSystem: '<S633>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S639>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_k12,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_a);

    /* End of SystemInitialize for SubSystem: '<S639>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S645>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_ot,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_oi);

    /* End of SystemInitialize for SubSystem: '<S645>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S657>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_op,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_pj);

    /* End of SystemInitialize for SubSystem: '<S657>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S663>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_ge,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_fs);

    /* End of SystemInitialize for SubSystem: '<S663>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S669>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_hc,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_dz);

    /* End of SystemInitialize for SubSystem: '<S669>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S741>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_bw,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_gg);

    /* End of SystemInitialize for SubSystem: '<S741>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S753>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_ny,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_cf);

    /* End of SystemInitialize for SubSystem: '<S753>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S675>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_bi0,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ke);

    /* End of SystemInitialize for SubSystem: '<S675>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S681>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_bi,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_of);

    /* End of SystemInitialize for SubSystem: '<S681>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S687>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_oj,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ix);

    /* End of SystemInitialize for SubSystem: '<S687>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S693>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_dq,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_dt);

    /* End of SystemInitialize for SubSystem: '<S693>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S699>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_dij,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_i2);

    /* End of SystemInitialize for SubSystem: '<S699>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S705>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_mhz,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_lt);

    /* End of SystemInitialize for SubSystem: '<S705>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S711>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_i,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_dmd);

    /* End of SystemInitialize for SubSystem: '<S711>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S717>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_jx,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_df);

    /* End of SystemInitialize for SubSystem: '<S717>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S735>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_k2,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_fr);

    /* End of SystemInitialize for SubSystem: '<S735>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S651>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_ib,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_on);

    /* End of SystemInitialize for SubSystem: '<S651>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1046>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_ja,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_j5);

    /* End of SystemInitialize for SubSystem: '<S1046>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1052>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_c3,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ph);

    /* End of SystemInitialize for SubSystem: '<S1052>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1058>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_no,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ko);

    /* End of SystemInitialize for SubSystem: '<S1058>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1070>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_ea,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_oe);

    /* End of SystemInitialize for SubSystem: '<S1070>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1076>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_lk,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_gh);

    /* End of SystemInitialize for SubSystem: '<S1076>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1082>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_c01,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ck3);

    /* End of SystemInitialize for SubSystem: '<S1082>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1088>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_p2,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_nd);

    /* End of SystemInitialize for SubSystem: '<S1088>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1094>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_a,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_cq);

    /* End of SystemInitialize for SubSystem: '<S1094>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1262>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_di,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_py);

    /* End of SystemInitialize for SubSystem: '<S1262>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1112>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_nn,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_he);

    /* End of SystemInitialize for SubSystem: '<S1112>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1106>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_jvn,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ex);

    /* End of SystemInitialize for SubSystem: '<S1106>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1118>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_gc,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_mx);

    /* End of SystemInitialize for SubSystem: '<S1118>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1124>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_kx,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_j4);

    /* End of SystemInitialize for SubSystem: '<S1124>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1130>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_jcr,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_jy);

    /* End of SystemInitialize for SubSystem: '<S1130>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1136>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_pf,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_kez);

    /* End of SystemInitialize for SubSystem: '<S1136>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1142>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_jc,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_knc);

    /* End of SystemInitialize for SubSystem: '<S1142>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1148>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_m1,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_f5);

    /* End of SystemInitialize for SubSystem: '<S1148>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1154>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_pw,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_l2);

    /* End of SystemInitialize for SubSystem: '<S1154>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1160>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_nr,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_my);

    /* End of SystemInitialize for SubSystem: '<S1160>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1166>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_pb,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_c4);

    /* End of SystemInitialize for SubSystem: '<S1166>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1172>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_kcr,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_eh);

    /* End of SystemInitialize for SubSystem: '<S1172>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1178>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_k1,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_myz);

    /* End of SystemInitialize for SubSystem: '<S1178>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1190>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_fp,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_db);

    /* End of SystemInitialize for SubSystem: '<S1190>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1184>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_fl,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ja);

    /* End of SystemInitialize for SubSystem: '<S1184>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1196>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_kc,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_af);

    /* End of SystemInitialize for SubSystem: '<S1196>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1202>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_ob,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_lu);

    /* End of SystemInitialize for SubSystem: '<S1202>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1208>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_f0,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_lij);

    /* End of SystemInitialize for SubSystem: '<S1208>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1220>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_dt,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_g3);

    /* End of SystemInitialize for SubSystem: '<S1220>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1226>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_jv,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_lg);

    /* End of SystemInitialize for SubSystem: '<S1226>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1238>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_pk,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_pu);

    /* End of SystemInitialize for SubSystem: '<S1238>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1244>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_n,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_iku);

    /* End of SystemInitialize for SubSystem: '<S1244>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1250>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_b2,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_mk);

    /* End of SystemInitialize for SubSystem: '<S1250>/signal validity checking' */

    /* SystemInitialize for Chart: '<S160>/Initialization' */
    PowerCtrolP_Initialization_Init(&PowerCtrolProject1_S32K144_B.CANInt_cq);

    /* SystemInitialize for Enabled SubSystem: '<S160>/CANDiagnosis' */
    PowerCtrolPro_CANDiagnosis_Init(&PowerCtrolProject1_S32K144_B.CANDiagnosis,
      &PowerCtrolProject1_S32K14_DWork.CANDiagnosis);

    /* End of SystemInitialize for SubSystem: '<S160>/CANDiagnosis' */

    /* SystemInitialize for Chart: '<S202>/Initialization' */
    PowerCtrolP_Initialization_Init(&PowerCtrolProject1_S32K144_B.CANInt_g5);

    /* SystemInitialize for Enabled SubSystem: '<S202>/CANDiagnosis' */
    PowerCtrolPro_CANDiagnosis_Init(&PowerCtrolProject1_S32K144_B.CANDiagnosis_l,
      &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_l);

    /* End of SystemInitialize for SubSystem: '<S202>/CANDiagnosis' */

    /* SystemInitialize for Atomic SubSystem: '<S210>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_la,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_b);

    /* End of SystemInitialize for SubSystem: '<S210>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S216>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_du,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_bf);

    /* End of SystemInitialize for SubSystem: '<S216>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S223>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_gq,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_e);

    /* End of SystemInitialize for SubSystem: '<S223>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S229>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_lxl,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_c);

    /* End of SystemInitialize for SubSystem: '<S229>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S236>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_ojo,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_k);

    /* End of SystemInitialize for SubSystem: '<S236>/signal validity checking' */

    /* SystemInitialize for Chart: '<S250>/Initialization' */
    PowerCtrolP_Initialization_Init(&PowerCtrolProject1_S32K144_B.CANInt_g);

    /* SystemInitialize for Enabled SubSystem: '<S250>/CANDiagnosis' */
    PowerCtrolPro_CANDiagnosis_Init
      (&PowerCtrolProject1_S32K144_B.CANDiagnosis_lh,
       &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_lh);

    /* End of SystemInitialize for SubSystem: '<S250>/CANDiagnosis' */

    /* SystemInitialize for Atomic SubSystem: '<S258>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_kk,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_bt);

    /* End of SystemInitialize for SubSystem: '<S258>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S264>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_jg,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_d);

    /* End of SystemInitialize for SubSystem: '<S264>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S271>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_gi,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ba);

    /* End of SystemInitialize for SubSystem: '<S271>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S277>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_nz,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ky);

    /* End of SystemInitialize for SubSystem: '<S277>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S284>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_ex,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_f);

    /* End of SystemInitialize for SubSystem: '<S284>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S291>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_p3,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_n);

    /* End of SystemInitialize for SubSystem: '<S291>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S332>/signal validity checking' */
    PowerCtr_sig_valid_check_n_Init(&PowerCtrolProject1_S32K144_B.fault_flg_he,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_h);

    /* End of SystemInitialize for SubSystem: '<S332>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S344>/signal validity checking' */
    PowerCtr_sig_valid_check_n_Init(&PowerCtrolProject1_S32K144_B.fault_flg_cj,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_i4);

    /* End of SystemInitialize for SubSystem: '<S344>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S350>/signal validity checking' */
    PowerCtr_sig_valid_check_n_Init(&PowerCtrolProject1_S32K144_B.fault_flg_dwl,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ka);

    /* End of SystemInitialize for SubSystem: '<S350>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S356>/signal validity checking' */
    PowerCtr_sig_valid_check_n_Init(&PowerCtrolProject1_S32K144_B.fault_flg_ep,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_l);

    /* End of SystemInitialize for SubSystem: '<S356>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S362>/signal validity checking' */
    PowerCtr_sig_valid_check_n_Init(&PowerCtrolProject1_S32K144_B.fault_flg_de,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_p);

    /* End of SystemInitialize for SubSystem: '<S362>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S374>/signal validity checking' */
    PowerCtr_sig_valid_check_n_Init(&PowerCtrolProject1_S32K144_B.fault_flg_g1,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_h3);

    /* End of SystemInitialize for SubSystem: '<S374>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S380>/signal validity checking' */
    PowerCtr_sig_valid_check_n_Init(&PowerCtrolProject1_S32K144_B.fault_flg_nh,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_h31);

    /* End of SystemInitialize for SubSystem: '<S380>/signal validity checking' */

    /* SystemInitialize for Chart: '<S403>/Initialization' */
    PowerCtrolP_Initialization_Init(&PowerCtrolProject1_S32K144_B.CANInt_i2);

    /* SystemInitialize for Enabled SubSystem: '<S403>/CANDiagnosis' */
    PowerCtrolPro_CANDiagnosis_Init(&PowerCtrolProject1_S32K144_B.CANDiagnosis_c,
      &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_c);

    /* End of SystemInitialize for SubSystem: '<S403>/CANDiagnosis' */

    /* SystemInitialize for Atomic SubSystem: '<S418>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_ml,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ck);

    /* End of SystemInitialize for SubSystem: '<S418>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S425>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_ky,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_dj);

    /* End of SystemInitialize for SubSystem: '<S425>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S432>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_cq,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ls);

    /* End of SystemInitialize for SubSystem: '<S432>/signal validity checking' */

    /* SystemInitialize for Chart: '<S445>/Initialization' */
    PowerCtrolP_Initialization_Init(&PowerCtrolProject1_S32K144_B.CANInt_h);

    /* SystemInitialize for Enabled SubSystem: '<S445>/CANDiagnosis' */
    PowerCtrolPro_CANDiagnosis_Init(&PowerCtrolProject1_S32K144_B.CANDiagnosis_f,
      &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_f);

    /* End of SystemInitialize for SubSystem: '<S445>/CANDiagnosis' */

    /* SystemInitialize for Atomic SubSystem: '<S453>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_cy,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_eg);

    /* End of SystemInitialize for SubSystem: '<S453>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S459>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_hzg,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_pf);

    /* End of SystemInitialize for SubSystem: '<S459>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S465>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_m0,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_nz);

    /* End of SystemInitialize for SubSystem: '<S465>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S472>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_l3,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_iv);

    /* End of SystemInitialize for SubSystem: '<S472>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S479>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_n2,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_kq);

    /* End of SystemInitialize for SubSystem: '<S479>/signal validity checking' */

    /* SystemInitialize for Chart: '<S495>/Initialization' */
    PowerCtrolP_Initialization_Init(&PowerCtrolProject1_S32K144_B.CANInt_d);

    /* SystemInitialize for Enabled SubSystem: '<S495>/CANDiagnosis' */
    PowerCtrolPro_CANDiagnosis_Init(&PowerCtrolProject1_S32K144_B.CANDiagnosis_p,
      &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_p);

    /* End of SystemInitialize for SubSystem: '<S495>/CANDiagnosis' */

    /* SystemInitialize for Atomic SubSystem: '<S503>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_cu,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_mp);

    /* End of SystemInitialize for SubSystem: '<S503>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S509>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_o3,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_gf);

    /* End of SystemInitialize for SubSystem: '<S509>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S515>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_e3,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_gb);

    /* End of SystemInitialize for SubSystem: '<S515>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S522>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_dp,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_pr);

    /* End of SystemInitialize for SubSystem: '<S522>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S529>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_am,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_dm);

    /* End of SystemInitialize for SubSystem: '<S529>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S536>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_bt,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_g4);

    /* End of SystemInitialize for SubSystem: '<S536>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S543>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_f0c,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ft);

    /* End of SystemInitialize for SubSystem: '<S543>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S550>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_pz,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_cu);

    /* End of SystemInitialize for SubSystem: '<S550>/signal validity checking' */

    /* SystemInitialize for Chart: '<S558>/Initialization' */
    PowerCtrolP_Initialization_Init(&PowerCtrolProject1_S32K144_B.CANInt_k);

    /* SystemInitialize for Enabled SubSystem: '<S558>/CANDiagnosis' */
    PowerCtrolPro_CANDiagnosis_Init(&PowerCtrolProject1_S32K144_B.CANDiagnosis_h,
      &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_h);

    /* End of SystemInitialize for SubSystem: '<S558>/CANDiagnosis' */

    /* SystemInitialize for Chart: '<S567>/Initialization' */
    PowerCtrolP_Initialization_Init(&PowerCtrolProject1_S32K144_B.CANInt_j);

    /* SystemInitialize for Enabled SubSystem: '<S567>/CANDiagnosis' */
    PowerCtrolPro_CANDiagnosis_Init
      (&PowerCtrolProject1_S32K144_B.CANDiagnosis_lu,
       &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_lu);

    /* End of SystemInitialize for SubSystem: '<S567>/CANDiagnosis' */

    /* SystemInitialize for Chart: '<S601>/Initialization' */
    PowerCtrolP_Initialization_Init(&PowerCtrolProject1_S32K144_B.CANInt_ca);

    /* SystemInitialize for Enabled SubSystem: '<S601>/CANDiagnosis' */
    PowerCtrolPro_CANDiagnosis_Init(&PowerCtrolProject1_S32K144_B.CANDiagnosis_a,
      &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_a);

    /* End of SystemInitialize for SubSystem: '<S601>/CANDiagnosis' */

    /* SystemInitialize for Atomic SubSystem: '<S627>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_jwc,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_kn);

    /* End of SystemInitialize for SubSystem: '<S627>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S723>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_kc4,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_o0);

    /* End of SystemInitialize for SubSystem: '<S723>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S729>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_bp5,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_jz);

    /* End of SystemInitialize for SubSystem: '<S729>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S747>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_ly,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_fj0);

    /* End of SystemInitialize for SubSystem: '<S747>/signal validity checking' */

    /* SystemInitialize for Chart: '<S769>/Initialization' */
    PowerCtrolP_Initialization_Init(&PowerCtrolProject1_S32K144_B.CANInt_mj);

    /* SystemInitialize for Enabled SubSystem: '<S769>/CANDiagnosis' */
    PowerCtrolPro_CANDiagnosis_Init(&PowerCtrolProject1_S32K144_B.CANDiagnosis_d,
      &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_d);

    /* End of SystemInitialize for SubSystem: '<S769>/CANDiagnosis' */

    /* SystemInitialize for Atomic SubSystem: '<S777>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_me,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_bfb);

    /* End of SystemInitialize for SubSystem: '<S777>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S797>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_bk,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_mb);

    /* End of SystemInitialize for SubSystem: '<S797>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S815>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_dg,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_nm);

    /* End of SystemInitialize for SubSystem: '<S815>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S821>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_ek,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ik);

    /* End of SystemInitialize for SubSystem: '<S821>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S828>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_bc,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_fa);

    /* End of SystemInitialize for SubSystem: '<S828>/signal validity checking' */

    /* SystemInitialize for Chart: '<S840>/Initialization' */
    PowerCtrolP_Initialization_Init(&PowerCtrolProject1_S32K144_B.CANInt_c);

    /* SystemInitialize for Enabled SubSystem: '<S840>/CANDiagnosis' */
    PowerCtrolPro_CANDiagnosis_Init(&PowerCtrolProject1_S32K144_B.CANDiagnosis_b,
      &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_b);

    /* End of SystemInitialize for SubSystem: '<S840>/CANDiagnosis' */

    /* SystemInitialize for Atomic SubSystem: '<S848>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_c2,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_an);

    /* End of SystemInitialize for SubSystem: '<S848>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S861>/signal validity checking' */
    PowerCtrol_sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_dv,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_i3);

    /* End of SystemInitialize for SubSystem: '<S861>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S867>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_k0j,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_cur);

    /* End of SystemInitialize for SubSystem: '<S867>/signal validity checking' */

    /* SystemInitialize for Chart: '<S875>/Initialization' */
    PowerCtrolP_Initialization_Init(&PowerCtrolProject1_S32K144_B.CANInt_e);

    /* SystemInitialize for Enabled SubSystem: '<S875>/CANDiagnosis' */
    PowerCtrolPro_CANDiagnosis_Init(&PowerCtrolProject1_S32K144_B.CANDiagnosis_m,
      &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_m);

    /* End of SystemInitialize for SubSystem: '<S875>/CANDiagnosis' */

    /* SystemInitialize for Chart: '<S890>/Initialization' */
    PowerCtro_Initialization_h_Init(&PowerCtrolProject1_S32K144_B.CANInt_md);

    /* SystemInitialize for Enabled SubSystem: '<S890>/CANDiagnosis' */
    PowerCtrolP_CANDiagnosis_b_Init(&PowerCtrolProject1_S32K144_B.CANDiagnosis_j,
      &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_j);

    /* End of SystemInitialize for SubSystem: '<S890>/CANDiagnosis' */

    /* SystemInitialize for Atomic SubSystem: '<S904>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_jd,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_gp);

    /* End of SystemInitialize for SubSystem: '<S904>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S916>/signal validity checking' */
    PowerCtr_sig_valid_check_l_Init(&PowerCtrolProject1_S32K144_B.fault_flg_ln,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_jx);

    /* End of SystemInitialize for SubSystem: '<S916>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S923>/signal validity checking' */
    PowerCtr_sig_valid_check_l_Init(&PowerCtrolProject1_S32K144_B.fault_flg_m5,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ma);

    /* End of SystemInitialize for SubSystem: '<S923>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S979>/signal validity checking' */
    sig_valid_check_Init(&PowerCtrolProject1_S32K144_B.fault_flg_noc,
                         &rtb_valid_signal,
                         &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_p5);

    /* End of SystemInitialize for SubSystem: '<S979>/signal validity checking' */

    /* SystemInitialize for Chart: '<S1032>/Initialization' */
    PowerCtrolP_Initialization_Init(&PowerCtrolProject1_S32K144_B.CANInt_m);

    /* SystemInitialize for Enabled SubSystem: '<S1032>/CANDiagnosis' */
    PowerCtrolPro_CANDiagnosis_Init
      (&PowerCtrolProject1_S32K144_B.CANDiagnosis_gv,
       &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_gv);

    /* End of SystemInitialize for SubSystem: '<S1032>/CANDiagnosis' */

    /* SystemInitialize for Atomic SubSystem: '<S1040>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_j3,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_clj);

    /* End of SystemInitialize for SubSystem: '<S1040>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1064>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_nw,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_bc);

    /* End of SystemInitialize for SubSystem: '<S1064>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1100>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_k0,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_iw);

    /* End of SystemInitialize for SubSystem: '<S1100>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1214>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_ms,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_f0);

    /* End of SystemInitialize for SubSystem: '<S1214>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1232>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_l2,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ehd);

    /* End of SystemInitialize for SubSystem: '<S1232>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1256>/signal validity checking' */
    PowerCtr_sig_valid_check_o_Init(&PowerCtrolProject1_S32K144_B.fault_flg_js,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_np);

    /* End of SystemInitialize for SubSystem: '<S1256>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1273>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_o,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_nv);

    /* End of SystemInitialize for SubSystem: '<S1273>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1279>/signal validity checking' */
    PowerCtr_sig_valid_check_l_Init(&PowerCtrolProject1_S32K144_B.fault_flg_pj,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ay);

    /* End of SystemInitialize for SubSystem: '<S1279>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1286>/signal validity checking' */
    PowerCtr_sig_valid_check_l_Init(&PowerCtrolProject1_S32K144_B.fault_flg_l5,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_fv);

    /* End of SystemInitialize for SubSystem: '<S1286>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1293>/signal validity checking' */
    PowerCtr_sig_valid_check_l_Init(&PowerCtrolProject1_S32K144_B.fault_flg_fh,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_nf);

    /* End of SystemInitialize for SubSystem: '<S1293>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1300>/signal validity checking' */
    PowerCtr_sig_valid_check_l_Init(&PowerCtrolProject1_S32K144_B.fault_flg_m,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ij);

    /* End of SystemInitialize for SubSystem: '<S1300>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1321>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_cz,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_p5k);

    /* End of SystemInitialize for SubSystem: '<S1321>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1327>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_bp,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_b4);

    /* End of SystemInitialize for SubSystem: '<S1327>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1345>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_pq,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_n3);

    /* End of SystemInitialize for SubSystem: '<S1345>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1351>/signal validity checking' */
    PowerCtr_sig_valid_check_l_Init(&PowerCtrolProject1_S32K144_B.fault_flg_lx,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_bo);

    /* End of SystemInitialize for SubSystem: '<S1351>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1365>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_kf,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_oq);

    /* End of SystemInitialize for SubSystem: '<S1365>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1371>/signal validity checking' */
    PowerCtr_sig_valid_check_l_Init(&PowerCtrolProject1_S32K144_B.fault_flg_c0,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_kv);

    /* End of SystemInitialize for SubSystem: '<S1371>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1384>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_fe,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_oc);

    /* End of SystemInitialize for SubSystem: '<S1384>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1390>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_gx,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_lc);

    /* End of SystemInitialize for SubSystem: '<S1390>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1396>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_h3,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_iy);

    /* End of SystemInitialize for SubSystem: '<S1396>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1402>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_cl,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_oh);

    /* End of SystemInitialize for SubSystem: '<S1402>/signal validity checking' */

    /* SystemInitialize for Chart: '<S1414>/Initialization' */
    PowerCtro_Initialization_h_Init(&PowerCtrolProject1_S32K144_B.CANInt);

    /* SystemInitialize for Enabled SubSystem: '<S1414>/CANDiagnosis' */
    PowerCtrolP_CANDiagnosis_b_Init(&PowerCtrolProject1_S32K144_B.CANDiagnosis_k,
      &PowerCtrolProject1_S32K14_DWork.CANDiagnosis_k);

    /* End of SystemInitialize for SubSystem: '<S1414>/CANDiagnosis' */

    /* SystemInitialize for Atomic SubSystem: '<S1422>/signal validity checking' */
    PowerCtr_sig_valid_check_l_Init(&PowerCtrolProject1_S32K144_B.fault_flg_gk,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_cly);

    /* End of SystemInitialize for SubSystem: '<S1422>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1429>/signal validity checking' */
    PowerCtr_sig_valid_check_l_Init(&PowerCtrolProject1_S32K144_B.fault_flg_h2,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_bh);

    /* End of SystemInitialize for SubSystem: '<S1429>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1436>/signal validity checking' */
    PowerCtr_sig_valid_check_l_Init(&PowerCtrolProject1_S32K144_B.fault_flg_eo,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_jao);

    /* End of SystemInitialize for SubSystem: '<S1436>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1443>/signal validity checking' */
    PowerCtr_sig_valid_check_n_Init(&PowerCtrolProject1_S32K144_B.fault_flg_gr,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_n5);

    /* End of SystemInitialize for SubSystem: '<S1443>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1449>/signal validity checking' */
    PowerCtr_sig_valid_check_l_Init(&PowerCtrolProject1_S32K144_B.fault_flg_gt,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ea);

    /* End of SystemInitialize for SubSystem: '<S1449>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1485>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_l,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_kk);

    /* End of SystemInitialize for SubSystem: '<S1485>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1491>/signal validity checking' */
    PowerCtr_sig_valid_check_l_Init(&PowerCtrolProject1_S32K144_B.fault_flg_jw,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_km);

    /* End of SystemInitialize for SubSystem: '<S1491>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1498>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_e,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_ii);

    /* End of SystemInitialize for SubSystem: '<S1498>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1529>/signal validity checking' */
    PowerCtr_sig_valid_check_l_Init(&PowerCtrolProject1_S32K144_B.fault_flg_hi,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_pt);

    /* End of SystemInitialize for SubSystem: '<S1529>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1536>/signal validity checking' */
    PowerCtr_sig_valid_check_l_Init(&PowerCtrolProject1_S32K144_B.fault_flg_h,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_cfs);

    /* End of SystemInitialize for SubSystem: '<S1536>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1549>/signal validity checking' */
    PowerCtr_sig_valid_check_k_Init(&PowerCtrolProject1_S32K144_B.fault_flg_b,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_mpl);

    /* End of SystemInitialize for SubSystem: '<S1549>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1555>/signal validity checking' */
    PowerCtr_sig_valid_check_l_Init(&PowerCtrolProject1_S32K144_B.fault_flg_f,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_lv);

    /* End of SystemInitialize for SubSystem: '<S1555>/signal validity checking' */

    /* SystemInitialize for Atomic SubSystem: '<S1563>/signal validity checking' */
    PowerCtr_sig_valid_check_l_Init(&PowerCtrolProject1_S32K144_B.fault_flg_d,
      &rtb_valid_signal,
      &PowerCtrolProject1_S32K14_DWork.signalvaliditychecking_k5);

    /* End of SystemInitialize for SubSystem: '<S1563>/signal validity checking' */
  }
}

/* Model terminate function */
void PowerCtrolProject1_S32K144_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
