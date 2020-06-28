/*
 * motor_cont_ctrl0_data.c
 *
 * Code generation for model "motor_cont_ctrl0".
 *
 * Model version              : 1.1
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Sat Jun 13 20:56:20 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motor_cont_ctrl0.h"
#include "motor_cont_ctrl0_private.h"

/* Block parameters (default storage) */
P_motor_cont_ctrl0_T motor_cont_ctrl0_P = {
  /* Mask Parameter: Ramp_rep_seq_y
   * Referenced by: '<S1>/Look-Up Table1'
   */
  { 0.0, 800.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Step '
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step '
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<Root>/Step '
   */
  1000.0,

  /* Expression: period
   * Referenced by: '<S1>/Constant'
   */
  10.0,

  /* Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S1>/Look-Up Table1'
   */
  { 0.0, 10.0 },

  /* Computed Parameter: DCMotor_A
   * Referenced by: '<Root>/DC Motor'
   */
  { -30.0, -20.0 },

  /* Computed Parameter: DCMotor_C
   * Referenced by: '<Root>/DC Motor'
   */
  { 0.0, 2000.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Integrator1'
   */
  0.0,

  /* Expression: 0.005
   * Referenced by: '<Root>/Kp'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator '
   */
  0.0,

  /* Expression: 0.0001
   * Referenced by: '<Root>/Ki'
   */
  0.0001,

  /* Computed Parameter: SW_R_CurrentSetting
   * Referenced by: '<Root>/SW_R'
   */
  1U,

  /* Computed Parameter: SW_Y_CurrentSetting
   * Referenced by: '<Root>/SW_Y'
   */
  0U
};
