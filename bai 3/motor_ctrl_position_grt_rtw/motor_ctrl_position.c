/*
 * motor_ctrl_position.c
 *
 * Code generation for model "motor_ctrl_position".
 *
 * Model version              : 1.2
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Sun Jun 14 13:19:44 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motor_ctrl_position.h"
#include "motor_ctrl_position_private.h"

/* Block signals (default storage) */
B_motor_ctrl_position_T motor_ctrl_position_B;

/* Continuous states */
X_motor_ctrl_position_T motor_ctrl_position_X;

/* Block states (default storage) */
DW_motor_ctrl_position_T motor_ctrl_position_DW;

/* Real-time model */
RT_MODEL_motor_ctrl_position_T motor_ctrl_position_M_;
RT_MODEL_motor_ctrl_position_T *const motor_ctrl_position_M =
  &motor_ctrl_position_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  motor_ctrl_position_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  motor_ctrl_position_step();
  motor_ctrl_position_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  motor_ctrl_position_step();
  motor_ctrl_position_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void motor_ctrl_position_step(void)
{
  /* local block i/o variables */
  real_T rtb_FilterCoefficient;
  real_T rtb_IntegralGain;
  real_T currentTime;
  if (rtmIsMajorTimeStep(motor_ctrl_position_M)) {
    /* set solver stop time */
    if (!(motor_ctrl_position_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&motor_ctrl_position_M->solverInfo,
                            ((motor_ctrl_position_M->Timing.clockTickH0 + 1) *
        motor_ctrl_position_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&motor_ctrl_position_M->solverInfo,
                            ((motor_ctrl_position_M->Timing.clockTick0 + 1) *
        motor_ctrl_position_M->Timing.stepSize0 +
        motor_ctrl_position_M->Timing.clockTickH0 *
        motor_ctrl_position_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(motor_ctrl_position_M)) {
    motor_ctrl_position_M->Timing.t[0] = rtsiGetT
      (&motor_ctrl_position_M->solverInfo);
  }

  /* Integrator: '<Root>/Integrator ' */
  motor_ctrl_position_B.Integrator = motor_ctrl_position_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(motor_ctrl_position_M)) {
    /* Step: '<Root>/Set point (rpm)' */
    currentTime = (((motor_ctrl_position_M->Timing.clockTick1+
                     motor_ctrl_position_M->Timing.clockTickH1* 4294967296.0)) *
                   0.005);
    if (currentTime < motor_ctrl_position_P.Setpointrpm_Time) {
      motor_ctrl_position_B.Setpointrpm = motor_ctrl_position_P.Setpointrpm_Y0;
    } else {
      motor_ctrl_position_B.Setpointrpm =
        motor_ctrl_position_P.Setpointrpm_YFinal;
    }

    /* End of Step: '<Root>/Set point (rpm)' */

    /* Scope: '<Root>/Scope ' */
    if (rtmIsMajorTimeStep(motor_ctrl_position_M)) {
      StructLogVar *svar = (StructLogVar *)
        motor_ctrl_position_DW.Scope_PWORK.LoggedData;
      LogVar *var = svar->signals.values;

      /* time */
      {
        double locTime = (((motor_ctrl_position_M->Timing.clockTick1+
                            motor_ctrl_position_M->Timing.clockTickH1*
                            4294967296.0)) * 0.005);
        ;
        rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
      }

      /* signals */
      {
        real_T up0[2];
        up0[0] = motor_ctrl_position_B.Setpointrpm;
        up0[1] = motor_ctrl_position_B.Integrator;
        rt_UpdateLogVar((LogVar *)var, up0, 0);
      }
    }
  }

  /* Sum: '<Root>/Sum' */
  motor_ctrl_position_B.Sum = motor_ctrl_position_B.Setpointrpm -
    motor_ctrl_position_B.Integrator;
  if (rtmIsMajorTimeStep(motor_ctrl_position_M)) {
    /* Gain: '<S1>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S1>/Filter'
     *  Gain: '<S1>/Derivative Gain'
     *  Sum: '<S1>/SumD'
     */
    rtb_FilterCoefficient = (motor_ctrl_position_P.DiscretePIDController_D *
      motor_ctrl_position_B.Sum - motor_ctrl_position_DW.Filter_DSTATE) *
      motor_ctrl_position_P.DiscretePIDController_N;

    /* Gain: '<S1>/Integral Gain' */
    rtb_IntegralGain = motor_ctrl_position_P.DiscretePIDController_I *
      motor_ctrl_position_B.Sum;

    /* Sum: '<S1>/Sum' incorporates:
     *  DiscreteIntegrator: '<S1>/Integrator'
     *  Gain: '<S1>/Proportional Gain'
     */
    motor_ctrl_position_B.Sum_a = (motor_ctrl_position_P.DiscretePIDController_P
      * motor_ctrl_position_B.Sum + motor_ctrl_position_DW.Integrator_DSTATE) +
      rtb_FilterCoefficient;
  }

  /* TransferFcn: '<Root>/Transfer Fcn ' */
  motor_ctrl_position_B.TransferFcn = 0.0;
  motor_ctrl_position_B.TransferFcn += motor_ctrl_position_P.TransferFcn_C *
    motor_ctrl_position_X.TransferFcn_CSTATE;
  if (rtmIsMajorTimeStep(motor_ctrl_position_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(motor_ctrl_position_M->rtwLogInfo,
                        (motor_ctrl_position_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(motor_ctrl_position_M)) {
    if (rtmIsMajorTimeStep(motor_ctrl_position_M)) {
      /* Update for DiscreteIntegrator: '<S1>/Filter' */
      motor_ctrl_position_DW.Filter_DSTATE +=
        motor_ctrl_position_P.Filter_gainval * rtb_FilterCoefficient;

      /* Update for DiscreteIntegrator: '<S1>/Integrator' */
      motor_ctrl_position_DW.Integrator_DSTATE +=
        motor_ctrl_position_P.Integrator_gainval * rtb_IntegralGain;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(motor_ctrl_position_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(motor_ctrl_position_M)!=-1) &&
          !((rtmGetTFinal(motor_ctrl_position_M)-
             (((motor_ctrl_position_M->Timing.clockTick1+
                motor_ctrl_position_M->Timing.clockTickH1* 4294967296.0)) *
              0.005)) > (((motor_ctrl_position_M->Timing.clockTick1+
                           motor_ctrl_position_M->Timing.clockTickH1*
                           4294967296.0)) * 0.005) * (DBL_EPSILON))) {
        rtmSetErrorStatus(motor_ctrl_position_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&motor_ctrl_position_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++motor_ctrl_position_M->Timing.clockTick0)) {
      ++motor_ctrl_position_M->Timing.clockTickH0;
    }

    motor_ctrl_position_M->Timing.t[0] = rtsiGetSolverStopTime
      (&motor_ctrl_position_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.005s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.005, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      motor_ctrl_position_M->Timing.clockTick1++;
      if (!motor_ctrl_position_M->Timing.clockTick1) {
        motor_ctrl_position_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void motor_ctrl_position_derivatives(void)
{
  XDot_motor_ctrl_position_T *_rtXdot;
  _rtXdot = ((XDot_motor_ctrl_position_T *) motor_ctrl_position_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator ' */
  _rtXdot->Integrator_CSTATE = motor_ctrl_position_B.TransferFcn;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn ' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += motor_ctrl_position_P.TransferFcn_A *
    motor_ctrl_position_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += motor_ctrl_position_B.Sum_a;
}

/* Model initialize function */
void motor_ctrl_position_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)motor_ctrl_position_M, 0,
                sizeof(RT_MODEL_motor_ctrl_position_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&motor_ctrl_position_M->solverInfo,
                          &motor_ctrl_position_M->Timing.simTimeStep);
    rtsiSetTPtr(&motor_ctrl_position_M->solverInfo, &rtmGetTPtr
                (motor_ctrl_position_M));
    rtsiSetStepSizePtr(&motor_ctrl_position_M->solverInfo,
                       &motor_ctrl_position_M->Timing.stepSize0);
    rtsiSetdXPtr(&motor_ctrl_position_M->solverInfo,
                 &motor_ctrl_position_M->derivs);
    rtsiSetContStatesPtr(&motor_ctrl_position_M->solverInfo, (real_T **)
                         &motor_ctrl_position_M->contStates);
    rtsiSetNumContStatesPtr(&motor_ctrl_position_M->solverInfo,
      &motor_ctrl_position_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&motor_ctrl_position_M->solverInfo,
      &motor_ctrl_position_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&motor_ctrl_position_M->solverInfo,
      &motor_ctrl_position_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&motor_ctrl_position_M->solverInfo,
      &motor_ctrl_position_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&motor_ctrl_position_M->solverInfo,
                          (&rtmGetErrorStatus(motor_ctrl_position_M)));
    rtsiSetRTModelPtr(&motor_ctrl_position_M->solverInfo, motor_ctrl_position_M);
  }

  rtsiSetSimTimeStep(&motor_ctrl_position_M->solverInfo, MAJOR_TIME_STEP);
  motor_ctrl_position_M->intgData.y = motor_ctrl_position_M->odeY;
  motor_ctrl_position_M->intgData.f[0] = motor_ctrl_position_M->odeF[0];
  motor_ctrl_position_M->intgData.f[1] = motor_ctrl_position_M->odeF[1];
  motor_ctrl_position_M->intgData.f[2] = motor_ctrl_position_M->odeF[2];
  motor_ctrl_position_M->contStates = ((X_motor_ctrl_position_T *)
    &motor_ctrl_position_X);
  rtsiSetSolverData(&motor_ctrl_position_M->solverInfo, (void *)
                    &motor_ctrl_position_M->intgData);
  rtsiSetSolverName(&motor_ctrl_position_M->solverInfo,"ode3");
  rtmSetTPtr(motor_ctrl_position_M, &motor_ctrl_position_M->Timing.tArray[0]);
  rtmSetTFinal(motor_ctrl_position_M, 5.0);
  motor_ctrl_position_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    motor_ctrl_position_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(motor_ctrl_position_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(motor_ctrl_position_M->rtwLogInfo, (NULL));
    rtliSetLogT(motor_ctrl_position_M->rtwLogInfo, "tout");
    rtliSetLogX(motor_ctrl_position_M->rtwLogInfo, "");
    rtliSetLogXFinal(motor_ctrl_position_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(motor_ctrl_position_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(motor_ctrl_position_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(motor_ctrl_position_M->rtwLogInfo, 0);
    rtliSetLogDecimation(motor_ctrl_position_M->rtwLogInfo, 1);
    rtliSetLogY(motor_ctrl_position_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(motor_ctrl_position_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(motor_ctrl_position_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &motor_ctrl_position_B), 0,
                sizeof(B_motor_ctrl_position_T));

  /* states (continuous) */
  {
    (void) memset((void *)&motor_ctrl_position_X, 0,
                  sizeof(X_motor_ctrl_position_T));
  }

  /* states (dwork) */
  (void) memset((void *)&motor_ctrl_position_DW, 0,
                sizeof(DW_motor_ctrl_position_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(motor_ctrl_position_M->rtwLogInfo, 0.0,
    rtmGetTFinal(motor_ctrl_position_M), motor_ctrl_position_M->Timing.stepSize0,
    (&rtmGetErrorStatus(motor_ctrl_position_M)));

  /* Start for Scope: '<Root>/Scope ' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 2 };

    static int_T rt_ScopeSignalNumDimensions[] = { 1 };

    static int_T rt_ScopeSignalDimensions[] = { 2 };

    static void *rt_ScopeCurrSigDims[] = { (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 4 };

    static const char_T *rt_ScopeSignalLabels[] = { "" };

    static char_T rt_ScopeSignalTitles[] = "";
    static int_T rt_ScopeSignalTitleLengths[] = { 0 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 0, 0 };

    BuiltInDTypeId dTypes[1] = { SS_DOUBLE };

    static char_T rt_ScopeBlockName[] = "motor_ctrl_position/Scope ";
    static int_T rt_ScopeFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ScopeSignalLoggingPreprocessingFcnPtrs[] =
      {
      (NULL)
    };

    rt_ScopeSignalInfo.numSignals = 1;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = rt_ScopeFrameData;
    rt_ScopeSignalInfo.preprocessingPtrs =
      rt_ScopeSignalLoggingPreprocessingFcnPtrs;
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    motor_ctrl_position_DW.Scope_PWORK.LoggedData = rt_CreateStructLogVar(
      motor_ctrl_position_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(motor_ctrl_position_M),
      motor_ctrl_position_M->Timing.stepSize0,
      (&rtmGetErrorStatus(motor_ctrl_position_M)),
      "ScopeData",
      1,
      0,
      1,
      0.005,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (motor_ctrl_position_DW.Scope_PWORK.LoggedData == (NULL))
      return;
  }

  /* InitializeConditions for Integrator: '<Root>/Integrator ' */
  motor_ctrl_position_X.Integrator_CSTATE = motor_ctrl_position_P.Integrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Filter' */
  motor_ctrl_position_DW.Filter_DSTATE = motor_ctrl_position_P.Filter_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Integrator' */
  motor_ctrl_position_DW.Integrator_DSTATE =
    motor_ctrl_position_P.Integrator_IC_f;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn ' */
  motor_ctrl_position_X.TransferFcn_CSTATE = 0.0;
}

/* Model terminate function */
void motor_ctrl_position_terminate(void)
{
  /* (no terminate code required) */
}
