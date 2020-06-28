/*
 * temp_pid_ctrl_data.c
 *
 * Code generation for model "temp_pid_ctrl".
 *
 * Model version              : 1.1
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Thu Jun 18 16:59:32 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "temp_pid_ctrl.h"
#include "temp_pid_ctrl_private.h"

/* Block parameters (default storage) */
P_temp_pid_ctrl_T temp_pid_ctrl_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S1>/Derivative Gain'
   */
  10.385,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S1>/Integral Gain'
   */
  0.02407,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S1>/Filter Coefficient'
   */
  10.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S1>/Proportional Gain'
   */
  0.1296,

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
