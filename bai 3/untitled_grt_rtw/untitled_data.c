/*
 * untitled_data.c
 *
 * Code generation for model "untitled".
 *
 * Model version              : 1.0
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Sun Jun 14 09:47:00 2020
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
  6.666666666666667,

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
