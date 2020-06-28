/*
 * motor_cont_ctrl0.h
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

#ifndef RTW_HEADER_motor_cont_ctrl0_h_
#define RTW_HEADER_motor_cont_ctrl0_h_
#include <stddef.h>
#include <float.h>
#include <math.h>
#include <string.h>
#ifndef motor_cont_ctrl0_COMMON_INCLUDES_
# define motor_cont_ctrl0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* motor_cont_ctrl0_COMMON_INCLUDES_ */

#include "motor_cont_ctrl0_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Step;                         /* '<Root>/Step ' */
  real_T SW_R;                         /* '<Root>/SW_R' */
  real_T DCMotor;                      /* '<Root>/DC Motor' */
  real_T SW_Y;                         /* '<Root>/SW_Y' */
  real_T Add;                          /* '<Root>/Add' */
  real_T Ki;                           /* '<Root>/Ki' */
} B_motor_cont_ctrl0_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope ' */
} DW_motor_cont_ctrl0_T;

/* Continuous states (default storage) */
typedef struct {
  real_T DCMotor_CSTATE[2];            /* '<Root>/DC Motor' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator ' */
} X_motor_cont_ctrl0_T;

/* State derivatives (default storage) */
typedef struct {
  real_T DCMotor_CSTATE[2];            /* '<Root>/DC Motor' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator ' */
} XDot_motor_cont_ctrl0_T;

/* State disabled  */
typedef struct {
  boolean_T DCMotor_CSTATE[2];         /* '<Root>/DC Motor' */
  boolean_T Integrator1_CSTATE;        /* '<Root>/Integrator1' */
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator ' */
} XDis_motor_cont_ctrl0_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_motor_cont_ctrl0_T_ {
  real_T Ramp_rep_seq_y[2];            /* Mask Parameter: Ramp_rep_seq_y
                                        * Referenced by: '<S1>/Look-Up Table1'
                                        */
  real_T Step_Time;                    /* Expression: 0
                                        * Referenced by: '<Root>/Step '
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step '
                                        */
  real_T Step_YFinal;                  /* Expression: 1000
                                        * Referenced by: '<Root>/Step '
                                        */
  real_T Constant_Value;               /* Expression: period
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T LookUpTable1_bp01Data[2];     /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S1>/Look-Up Table1'
                                        */
  real_T DCMotor_A[2];                 /* Computed Parameter: DCMotor_A
                                        * Referenced by: '<Root>/DC Motor'
                                        */
  real_T DCMotor_C[2];                 /* Computed Parameter: DCMotor_C
                                        * Referenced by: '<Root>/DC Motor'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T Kp_Gain;                      /* Expression: 0.005
                                        * Referenced by: '<Root>/Kp'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator '
                                        */
  real_T Ki_Gain;                      /* Expression: 0.0001
                                        * Referenced by: '<Root>/Ki'
                                        */
  uint8_T SW_R_CurrentSetting;         /* Computed Parameter: SW_R_CurrentSetting
                                        * Referenced by: '<Root>/SW_R'
                                        */
  uint8_T SW_Y_CurrentSetting;         /* Computed Parameter: SW_Y_CurrentSetting
                                        * Referenced by: '<Root>/SW_Y'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_motor_cont_ctrl0_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_motor_cont_ctrl0_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[4];
  real_T odeF[3][4];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_motor_cont_ctrl0_T motor_cont_ctrl0_P;

/* Block signals (default storage) */
extern B_motor_cont_ctrl0_T motor_cont_ctrl0_B;

/* Continuous states (default storage) */
extern X_motor_cont_ctrl0_T motor_cont_ctrl0_X;

/* Block states (default storage) */
extern DW_motor_cont_ctrl0_T motor_cont_ctrl0_DW;

/* Model entry point functions */
extern void motor_cont_ctrl0_initialize(void);
extern void motor_cont_ctrl0_step(void);
extern void motor_cont_ctrl0_terminate(void);

/* Real-time Model object */
extern RT_MODEL_motor_cont_ctrl0_T *const motor_cont_ctrl0_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'motor_cont_ctrl0'
 * '<S1>'   : 'motor_cont_ctrl0/Ramp'
 */
#endif                                 /* RTW_HEADER_motor_cont_ctrl0_h_ */
