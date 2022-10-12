/*
 * File: PowerCtrolProject1_S32K144_private.h
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

#ifndef RTW_HEADER_PowerCtrolProject1_S32K144_private_h_
#define RTW_HEADER_PowerCtrolProject1_S32K144_private_h_
#include "rtwtypes.h"
#include "PowerCtrolProject1_S32K144.h"

extern real32_T look1_iflf_binlc(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex);
extern real32_T look1_iflf_binlx(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex);
extern void PowerCtrolProject1__Chart1_Init(rtDW_Chart1_PowerCtrolProject1_
  *localDW);
extern void PowerCtrolProject1_S32K1_Chart1(boolean_T rtu_in, boolean_T
  rtu_last_out, boolean_T *rty_out, rtDW_Chart1_PowerCtrolProject1_ *localDW);
extern void ff_resetting_Init(boolean_T *rty_fault_flg, uint8_T *rty_ff_count,
  rtDW_ff_resetting *localDW);
extern void ff_resetting_Reset(boolean_T *rty_fault_flg, uint8_T *rty_ff_count,
  rtDW_ff_resetting *localDW);
extern void ff_resetting(boolean_T rtu_inst_fault, uint8_T rtu_sat, uint8_T
  rtu_inc, uint8_T rtu_dec, boolean_T *rty_fault_flg, uint8_T *rty_ff_count,
  rtDW_ff_resetting *localDW);
extern void Pow_valid_signal_selection_Init(real32_T *rty_valid_signal);
extern void Po_valid_signal_selection_Reset(real32_T *rty_valid_signal);
extern void PowerCtr_valid_signal_selection(real32_T rtu_def_value, real32_T
  rtu_new_signal, boolean_T rtu_ifault_flg, boolean_T rtu_fault_flg, real32_T
  rtu_old_signal, real32_T *rty_valid_signal);
extern void sig_valid_check_Init(boolean_T *rty_fault_flg, real32_T
  *rty_valid_signal, rtDW_sig_valid_check *localDW);
extern void sig_valid_check_Reset(boolean_T *rty_fault_flg, real32_T
  *rty_valid_signal, rtDW_sig_valid_check *localDW);
extern void sig_valid_check(real32_T rtu_u, boolean_T rtu_u_valid_flg, boolean_T
  rtu_u_rangeFault_flg, real32_T rtu_def_value, uint8_T rtu_sat, uint8_T rtu_inc,
  uint8_T rtu_dec, boolean_T *rty_fault_flg, real32_T *rty_valid_signal,
  rtDW_sig_valid_check *localDW);
extern void PowerCtrolPro_CANDiagnosis_Init(rtB_CANDiagnosis_PowerCtrolProj
  *localB, rtDW_CANDiagnosis_PowerCtrolPro *localDW);
extern void PowerCtrolPr_CANDiagnosis_Reset(real32_T *rtb_valid_signal_mzd,
  rtB_CANDiagnosis_PowerCtrolProj *localB, rtDW_CANDiagnosis_PowerCtrolPro
  *localDW);
extern void PowerCtrol_CANDiagnosis_Disable(rtDW_CANDiagnosis_PowerCtrolPro
  *localDW);
extern void PowerCtrolProject1_CANDiagnosis(boolean_T rtu_Enable, boolean_T
  rtu_CANAvail_flg, uint8_T rtu_NINP_lim, uint8_T rtu_NINP_inc, uint8_T
  rtu_NINP_dec, rtB_CANDiagnosis_PowerCtrolProj *localB,
  rtDW_CANDiagnosis_PowerCtrolPro *localDW);
extern void PowerCtrolP_Initialization_Init(boolean_T *rty_CANInt);
extern void PowerCtrolProjec_Initialization(boolean_T rtu_CANAct, boolean_T
  *rty_CANInt);
extern void P_valid_signal_selection_a_Init(real32_T *rty_valid_signal);
extern void PowerC_valid_signal_selection_n(real32_T rtu_def_value, real32_T
  rtu_new_signal, boolean_T rtu_ifault_flg, boolean_T rtu_fault_flg, real32_T
  rtu_old_signal, real32_T *rty_valid_signal);
extern void PowerCtrol_sig_valid_check_Init(boolean_T *rty_fault_flg, real32_T
  *rty_valid_signal, rtDW_sig_valid_check_p *localDW);
extern void PowerCtrolProje_sig_valid_check(real32_T rtu_u, boolean_T
  rtu_u_valid_flg, boolean_T rtu_u_rangeFault_flg, real32_T rtu_def_value,
  uint8_T rtu_sat, uint8_T rtu_inc, uint8_T rtu_dec, boolean_T *rty_fault_flg,
  real32_T *rty_valid_signal, rtDW_sig_valid_check_p *localDW);
extern void PowerCtr_sig_valid_check_l_Init(boolean_T *rty_fault_flg, real32_T
  *rty_valid_signal, rtDW_sig_valid_check_k *localDW);
extern void PowerCt_sig_valid_check_k_Reset(boolean_T *rty_fault_flg, real32_T
  *rty_valid_signal, rtDW_sig_valid_check_k *localDW);
extern void PowerCtrolPro_sig_valid_check_k(real32_T rtu_u, real32_T
  rtu_def_value, uint8_T rtu_sat, uint8_T rtu_inc, uint8_T rtu_dec, boolean_T
  *rty_fault_flg, real32_T *rty_valid_signal, const rtC_sig_valid_check_ge
  *localC, rtDW_sig_valid_check_k *localDW);
extern void PowerCtro_Initialization_h_Init(boolean_T *rty_CANInt);
extern void PowerCtrolProj_Initialization_f(boolean_T rtu_CANAct, boolean_T
  *rty_CANInt);
extern void PowerCtr_sig_valid_check_n_Init(boolean_T *rty_fault_flg, real32_T
  *rty_valid_signal, rtDW_sig_valid_check_a *localDW);
extern void PowerCtrolPro_sig_valid_check_j(real32_T rtu_u, real32_T
  rtu_def_value, uint8_T rtu_sat, uint8_T rtu_inc, uint8_T rtu_dec, boolean_T
  *rty_fault_flg, real32_T *rty_valid_signal, const rtC_sig_valid_check_a
  *localC, rtDW_sig_valid_check_a *localDW);
extern void PowerCtr_sig_valid_check_k_Init(boolean_T *rty_fault_flg, real32_T
  *rty_valid_signal, rtDW_sig_valid_check_ku *localDW);
extern void PowerCtrolPro_sig_valid_check_f(real32_T rtu_u, uint8_T rtu_sat,
  uint8_T rtu_inc, uint8_T rtu_dec, boolean_T *rty_fault_flg, real32_T
  *rty_valid_signal, const rtC_sig_valid_check_gc *localC,
  rtDW_sig_valid_check_ku *localDW);
extern void PowerCtr_sig_valid_check_o_Init(boolean_T *rty_fault_flg, real32_T
  *rty_valid_signal, rtDW_sig_valid_check_g *localDW);
extern void PowerCtrolPro_sig_valid_check_m(real32_T rtu_u, boolean_T
  rtu_u_valid_flg, boolean_T rtu_u_rangeFault_flg, uint8_T rtu_sat, uint8_T
  rtu_inc, uint8_T rtu_dec, boolean_T *rty_fault_flg, real32_T *rty_valid_signal,
  const rtC_sig_valid_check_d *localC, rtDW_sig_valid_check_g *localDW);
extern void PowerCtrolP_CANDiagnosis_b_Init(rtB_CANDiagnosis_PowerCtrolPr_c
  *localB, rtDW_CANDiagnosis_PowerCtrolP_g *localDW);
extern void PowerCtrol_CANDiagnosis_k_Reset(real32_T *rtb_valid_signal_mb,
  rtB_CANDiagnosis_PowerCtrolPr_c *localB, rtDW_CANDiagnosis_PowerCtrolP_g
  *localDW);
extern void PowerCtr_CANDiagnosis_j_Disable(rtDW_CANDiagnosis_PowerCtrolP_g
  *localDW);
extern void PowerCtrolProjec_CANDiagnosis_j(boolean_T rtu_Enable, uint8_T
  rtu_NINP_lim, uint8_T rtu_NINP_inc, uint8_T rtu_NINP_dec,
  rtB_CANDiagnosis_PowerCtrolPr_c *localB, const rtC_CANDiagnosis_PowerCtrolPr_h
  *localC, rtDW_CANDiagnosis_PowerCtrolP_g *localDW);

#endif                                 /* RTW_HEADER_PowerCtrolProject1_S32K144_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
