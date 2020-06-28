/*
 * untitled_data.c
 *
 * Code generation for model "untitled".
 *
 * Model version              : 1.0
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Thu Jun 18 16:14:14 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"

/* Block parameters (default storage) */
P_untitled_T untitled_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S1>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S1>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S1>/Filter Coefficient'
   */
  1.0E+11,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S1>/Proportional Gain'
   */
  0.108,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<Root>/Transfer Fcn '
   */
  { -0.028333333333333332, -0.00016666666666666666 },

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<Root>/Transfer Fcn '
   */
  { 0.0, 0.016666666666666666 },

  /* Expression: 100
   * Referenced by: '<Root>/Nhiet do dat'
   */
  100.0,

  /* Expression: InitialConditionForFilter
   * Referenced by: '<S1>/Filter'
   */
  0.0,

  /* Expression: InitialConditionForIntegrator
   * Referenced by: '<S1>/Integrator'
   */
  0.0
};
