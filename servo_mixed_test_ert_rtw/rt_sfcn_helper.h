/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sfcn_helper.h
 *
 * Code generated for Simulink model 'servo_mixed_test'.
 *
 * Model version                  : 1.45
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Mon Apr 10 23:33:06 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rt_sfcn_helper_h_
#define RTW_HEADER_rt_sfcn_helper_h_
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"

extern int_T rt_CallSys(SimStruct *S, int_T element, int_T tid);
extern int_T rt_EnableSys(SimStruct *S, int_T element, int_T tid);
extern int_T rt_DisableSys(SimStruct *S, int_T element, int_T tid);

#endif                                 /* RTW_HEADER_rt_sfcn_helper_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */