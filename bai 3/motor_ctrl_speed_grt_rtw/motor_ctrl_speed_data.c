/*
 * motor_ctrl_speed_data.c
 *
 * Code generation for model "motor_ctrl_speed".
 *
 * Model version              : 1.1
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Sun Jun 14 13:05:45 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motor_ctrl_speed.h"
#include "motor_ctrl_speed_private.h"

/* Block parameters (default storage) */
P_motor_ctrl_speed_T motor_ctrl_speed_P = {
  /* Mask Parameter: DiscretePIDController_D
   * Referenced by: '<S1>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_I
   * Referenced by: '<S1>/Integral Gain'
   */
  10.0,

  /* Mask Parameter: DiscretePIDController_N
   * Referenced by: '<S1>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S1>/Proportional Gain'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Set point (rpm)'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Set point (rpm)'
   */
  0.0,

  /* Expression: 800
   * Referenced by: '<Root>/Set point (rpm)'
   */
  800.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<Root>/Transfer Fcn '
   */
  -3.3333333333333335,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<Root>/Transfer Fcn '
   */
  13.333333333333334,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S1>/Filter'
   */
  0.005,

  /* Expression: InitialConditionForFilter
   * Referenced by: '<S1>/Filter'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S1>/Integrator'
   */
  0.005,

  /* Expression: InitialConditionForIntegrator
   * Referenced by: '<S1>/Integrator'
   */
  0.0
};
