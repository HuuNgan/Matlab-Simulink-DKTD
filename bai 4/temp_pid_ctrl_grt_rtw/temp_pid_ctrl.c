/*
 * temp_pid_ctrl.c
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

/* Block signals (default storage) */
B_temp_pid_ctrl_T temp_pid_ctrl_B;

/* Continuous states */
X_temp_pid_ctrl_T temp_pid_ctrl_X;

/* Block states (default storage) */
DW_temp_pid_ctrl_T temp_pid_ctrl_DW;

/* Real-time model */
RT_MODEL_temp_pid_ctrl_T temp_pid_ctrl_M_;
RT_MODEL_temp_pid_ctrl_T *const temp_pid_ctrl_M = &temp_pid_ctrl_M_;

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
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  temp_pid_ctrl_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  temp_pid_ctrl_step();
  temp_pid_ctrl_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  temp_pid_ctrl_step();
  temp_pid_ctrl_derivatives();

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
void temp_pid_ctrl_step(void)
{
  real_T rtb_Sum_e;
  if (rtmIsMajorTimeStep(temp_pid_ctrl_M)) {
    /* set solver stop time */
    if (!(temp_pid_ctrl_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&temp_pid_ctrl_M->solverInfo,
                            ((temp_pid_ctrl_M->Timing.clockTickH0 + 1) *
        temp_pid_ctrl_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&temp_pid_ctrl_M->solverInfo,
                            ((temp_pid_ctrl_M->Timing.clockTick0 + 1) *
        temp_pid_ctrl_M->Timing.stepSize0 + temp_pid_ctrl_M->Timing.clockTickH0 *
        temp_pid_ctrl_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(temp_pid_ctrl_M)) {
    temp_pid_ctrl_M->Timing.t[0] = rtsiGetT(&temp_pid_ctrl_M->solverInfo);
  }

  /* TransferFcn: '<Root>/Transfer Fcn ' */
  temp_pid_ctrl_B.TransferFcn = 0.0;
  temp_pid_ctrl_B.TransferFcn += temp_pid_ctrl_P.TransferFcn_C[0] *
    temp_pid_ctrl_X.TransferFcn_CSTATE[0];
  temp_pid_ctrl_B.TransferFcn += temp_pid_ctrl_P.TransferFcn_C[1] *
    temp_pid_ctrl_X.TransferFcn_CSTATE[1];
  if (rtmIsMajorTimeStep(temp_pid_ctrl_M)) {
    /* Scope: '<Root>/Scope ' */
    if (rtmIsMajorTimeStep(temp_pid_ctrl_M)) {
      StructLogVar *svar = (StructLogVar *)
        temp_pid_ctrl_DW.Scope_PWORK.LoggedData;
      LogVar *var = svar->signals.values;

      /* time */
      {
        double locTime = (((temp_pid_ctrl_M->Timing.clockTick1+
                            temp_pid_ctrl_M->Timing.clockTickH1* 4294967296.0)) *
                          0.1);
        ;
        rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
      }

      /* signals */
      {
        real_T up0[1];
        up0[0] = temp_pid_ctrl_B.TransferFcn;
        rt_UpdateLogVar((LogVar *)var, up0, 0);
      }
    }
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Nhiet do dat'
   */
  rtb_Sum_e = temp_pid_ctrl_P.Nhietdodat_Value - temp_pid_ctrl_B.TransferFcn;

  /* Gain: '<S1>/Filter Coefficient' incorporates:
   *  Gain: '<S1>/Derivative Gain'
   *  Integrator: '<S1>/Filter'
   *  Sum: '<S1>/SumD'
   */
  temp_pid_ctrl_B.FilterCoefficient = (temp_pid_ctrl_P.PIDController_D *
    rtb_Sum_e - temp_pid_ctrl_X.Filter_CSTATE) * temp_pid_ctrl_P.PIDController_N;

  /* Gain: '<S1>/Integral Gain' */
  temp_pid_ctrl_B.IntegralGain = temp_pid_ctrl_P.PIDController_I * rtb_Sum_e;

  /* Gain: '<S1>/Proportional Gain' incorporates:
   *  Integrator: '<S1>/Integrator'
   *  Sum: '<S1>/Sum'
   */
  temp_pid_ctrl_B.ProportionalGain = ((rtb_Sum_e +
    temp_pid_ctrl_X.Integrator_CSTATE) + temp_pid_ctrl_B.FilterCoefficient) *
    temp_pid_ctrl_P.PIDController_P;
  if (rtmIsMajorTimeStep(temp_pid_ctrl_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(temp_pid_ctrl_M->rtwLogInfo, (temp_pid_ctrl_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(temp_pid_ctrl_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(temp_pid_ctrl_M)!=-1) &&
          !((rtmGetTFinal(temp_pid_ctrl_M)-(((temp_pid_ctrl_M->Timing.clockTick1
               +temp_pid_ctrl_M->Timing.clockTickH1* 4294967296.0)) * 0.1)) >
            (((temp_pid_ctrl_M->Timing.clockTick1+
               temp_pid_ctrl_M->Timing.clockTickH1* 4294967296.0)) * 0.1) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(temp_pid_ctrl_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&temp_pid_ctrl_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++temp_pid_ctrl_M->Timing.clockTick0)) {
      ++temp_pid_ctrl_M->Timing.clockTickH0;
    }

    temp_pid_ctrl_M->Timing.t[0] = rtsiGetSolverStopTime
      (&temp_pid_ctrl_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.1s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.1, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      temp_pid_ctrl_M->Timing.clockTick1++;
      if (!temp_pid_ctrl_M->Timing.clockTick1) {
        temp_pid_ctrl_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void temp_pid_ctrl_derivatives(void)
{
  XDot_temp_pid_ctrl_T *_rtXdot;
  _rtXdot = ((XDot_temp_pid_ctrl_T *) temp_pid_ctrl_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn ' */
  _rtXdot->TransferFcn_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += temp_pid_ctrl_P.TransferFcn_A[0] *
    temp_pid_ctrl_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += temp_pid_ctrl_P.TransferFcn_A[1] *
    temp_pid_ctrl_X.TransferFcn_CSTATE[1];
  _rtXdot->TransferFcn_CSTATE[1] += temp_pid_ctrl_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[0] += temp_pid_ctrl_B.ProportionalGain;

  /* Derivatives for Integrator: '<S1>/Filter' */
  _rtXdot->Filter_CSTATE = temp_pid_ctrl_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = temp_pid_ctrl_B.IntegralGain;
}

/* Model initialize function */
void temp_pid_ctrl_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)temp_pid_ctrl_M, 0,
                sizeof(RT_MODEL_temp_pid_ctrl_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&temp_pid_ctrl_M->solverInfo,
                          &temp_pid_ctrl_M->Timing.simTimeStep);
    rtsiSetTPtr(&temp_pid_ctrl_M->solverInfo, &rtmGetTPtr(temp_pid_ctrl_M));
    rtsiSetStepSizePtr(&temp_pid_ctrl_M->solverInfo,
                       &temp_pid_ctrl_M->Timing.stepSize0);
    rtsiSetdXPtr(&temp_pid_ctrl_M->solverInfo, &temp_pid_ctrl_M->derivs);
    rtsiSetContStatesPtr(&temp_pid_ctrl_M->solverInfo, (real_T **)
                         &temp_pid_ctrl_M->contStates);
    rtsiSetNumContStatesPtr(&temp_pid_ctrl_M->solverInfo,
      &temp_pid_ctrl_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&temp_pid_ctrl_M->solverInfo,
      &temp_pid_ctrl_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&temp_pid_ctrl_M->solverInfo,
      &temp_pid_ctrl_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&temp_pid_ctrl_M->solverInfo,
      &temp_pid_ctrl_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&temp_pid_ctrl_M->solverInfo, (&rtmGetErrorStatus
      (temp_pid_ctrl_M)));
    rtsiSetRTModelPtr(&temp_pid_ctrl_M->solverInfo, temp_pid_ctrl_M);
  }

  rtsiSetSimTimeStep(&temp_pid_ctrl_M->solverInfo, MAJOR_TIME_STEP);
  temp_pid_ctrl_M->intgData.y = temp_pid_ctrl_M->odeY;
  temp_pid_ctrl_M->intgData.f[0] = temp_pid_ctrl_M->odeF[0];
  temp_pid_ctrl_M->intgData.f[1] = temp_pid_ctrl_M->odeF[1];
  temp_pid_ctrl_M->intgData.f[2] = temp_pid_ctrl_M->odeF[2];
  temp_pid_ctrl_M->contStates = ((X_temp_pid_ctrl_T *) &temp_pid_ctrl_X);
  rtsiSetSolverData(&temp_pid_ctrl_M->solverInfo, (void *)
                    &temp_pid_ctrl_M->intgData);
  rtsiSetSolverName(&temp_pid_ctrl_M->solverInfo,"ode3");
  rtmSetTPtr(temp_pid_ctrl_M, &temp_pid_ctrl_M->Timing.tArray[0]);
  rtmSetTFinal(temp_pid_ctrl_M, 700.0);
  temp_pid_ctrl_M->Timing.stepSize0 = 0.1;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    temp_pid_ctrl_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(temp_pid_ctrl_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(temp_pid_ctrl_M->rtwLogInfo, (NULL));
    rtliSetLogT(temp_pid_ctrl_M->rtwLogInfo, "tout");
    rtliSetLogX(temp_pid_ctrl_M->rtwLogInfo, "");
    rtliSetLogXFinal(temp_pid_ctrl_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(temp_pid_ctrl_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(temp_pid_ctrl_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(temp_pid_ctrl_M->rtwLogInfo, 0);
    rtliSetLogDecimation(temp_pid_ctrl_M->rtwLogInfo, 1);
    rtliSetLogY(temp_pid_ctrl_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(temp_pid_ctrl_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(temp_pid_ctrl_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &temp_pid_ctrl_B), 0,
                sizeof(B_temp_pid_ctrl_T));

  /* states (continuous) */
  {
    (void) memset((void *)&temp_pid_ctrl_X, 0,
                  sizeof(X_temp_pid_ctrl_T));
  }

  /* states (dwork) */
  (void) memset((void *)&temp_pid_ctrl_DW, 0,
                sizeof(DW_temp_pid_ctrl_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(temp_pid_ctrl_M->rtwLogInfo, 0.0,
    rtmGetTFinal(temp_pid_ctrl_M), temp_pid_ctrl_M->Timing.stepSize0,
    (&rtmGetErrorStatus(temp_pid_ctrl_M)));

  /* Start for Scope: '<Root>/Scope ' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 1 };

    static int_T rt_ScopeSignalNumDimensions[] = { 1 };

    static int_T rt_ScopeSignalDimensions[] = { 1 };

    static void *rt_ScopeCurrSigDims[] = { (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 4 };

    static const char_T *rt_ScopeSignalLabels[] = { "" };

    static char_T rt_ScopeSignalTitles[] = "";
    static int_T rt_ScopeSignalTitleLengths[] = { 0 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 0 };

    BuiltInDTypeId dTypes[1] = { SS_DOUBLE };

    static char_T rt_ScopeBlockName[] = "temp_pid_ctrl/Scope ";
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
    temp_pid_ctrl_DW.Scope_PWORK.LoggedData = rt_CreateStructLogVar(
      temp_pid_ctrl_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(temp_pid_ctrl_M),
      temp_pid_ctrl_M->Timing.stepSize0,
      (&rtmGetErrorStatus(temp_pid_ctrl_M)),
      "ScopeData",
      1,
      0,
      1,
      0.1,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (temp_pid_ctrl_DW.Scope_PWORK.LoggedData == (NULL))
      return;
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn ' */
  temp_pid_ctrl_X.TransferFcn_CSTATE[0] = 0.0;
  temp_pid_ctrl_X.TransferFcn_CSTATE[1] = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Filter' */
  temp_pid_ctrl_X.Filter_CSTATE = temp_pid_ctrl_P.Filter_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  temp_pid_ctrl_X.Integrator_CSTATE = temp_pid_ctrl_P.Integrator_IC;
}

/* Model terminate function */
void temp_pid_ctrl_terminate(void)
{
  /* (no terminate code required) */
}
