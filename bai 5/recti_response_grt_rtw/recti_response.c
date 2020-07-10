/*
 * recti_response.c
 *
 * Code generation for model "recti_response".
 *
 * Model version              : 1.5
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Sun Jul  5 11:24:50 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "recti_response.h"
#include "recti_response_private.h"

/* Block signals (default storage) */
B_recti_response_T recti_response_B;

/* Continuous states */
X_recti_response_T recti_response_X;

/* Block states (default storage) */
DW_recti_response_T recti_response_DW;

/* Real-time model */
RT_MODEL_recti_response_T recti_response_M_;
RT_MODEL_recti_response_T *const recti_response_M = &recti_response_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  recti_response_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  recti_response_step();
  recti_response_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  recti_response_step();
  recti_response_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  recti_response_step();
  recti_response_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void recti_response_step(void)
{
  real_T um1_tmp;
  if (rtmIsMajorTimeStep(recti_response_M)) {
    /* set solver stop time */
    if (!(recti_response_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&recti_response_M->solverInfo,
                            ((recti_response_M->Timing.clockTickH0 + 1) *
        recti_response_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&recti_response_M->solverInfo,
                            ((recti_response_M->Timing.clockTick0 + 1) *
        recti_response_M->Timing.stepSize0 +
        recti_response_M->Timing.clockTickH0 *
        recti_response_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(recti_response_M)) {
    recti_response_M->Timing.t[0] = rtsiGetT(&recti_response_M->solverInfo);
  }

  /* Integrator: '<S1>/Integrator1' */
  recti_response_B.Integrator1 = recti_response_X.Integrator1_CSTATE;

  /* Integrator: '<S1>/Integrator' */
  recti_response_B.Integrator = recti_response_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(recti_response_M)) {
    /* Scope: '<Root>/Scope ' */
    if (rtmIsMajorTimeStep(recti_response_M)) {
      StructLogVar *svar = (StructLogVar *)
        recti_response_DW.Scope_PWORK.LoggedData;
      LogVar *var = svar->signals.values;

      /* time */
      {
        double locTime = (((recti_response_M->Timing.clockTick1+
                            recti_response_M->Timing.clockTickH1* 4294967296.0))
                          * 0.001);
        ;
        rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
      }

      /* signals */
      {
        real_T up0[2];
        up0[0] = recti_response_B.Integrator1;
        up0[1] = recti_response_B.Integrator;
        rt_UpdateLogVar((LogVar *)var, up0, 0);
      }
    }
  }

  /* Integrator: '<S1>/Integrator3' */
  recti_response_B.Integrator3 = recti_response_X.Integrator3_CSTATE;

  /* Integrator: '<S1>/Integrator2' */
  recti_response_B.Integrator2 = recti_response_X.Integrator2_CSTATE;

  /* Fcn: '<S1>/Fcn1 ' incorporates:
   *  Fcn: '<S1>/Fcn2 '
   */
  um1_tmp = (recti_response_B.Integrator - recti_response_B.Integrator1) *
    1000.0;

  /* Gain: '<S1>/1//m1' incorporates:
   *  Fcn: '<S1>/Fcn1 '
   */
  recti_response_B.um1 = ((um1_tmp - 1000.0 * recti_response_B.Integrator1) -
    10.0 * recti_response_B.Integrator3) * recti_response_P.um1_Gain;

  /* Gain: '<S1>/1//m2' incorporates:
   *  Constant: '<Root>/Force (N)'
   *  Fcn: '<S1>/Fcn2 '
   */
  recti_response_B.um2 = ((recti_response_P.ForceN_Value - um1_tmp) - 5.0 *
    recti_response_B.Integrator2) * recti_response_P.um2_Gain;
  if (rtmIsMajorTimeStep(recti_response_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(recti_response_M->rtwLogInfo,
                        (recti_response_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(recti_response_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(recti_response_M)!=-1) &&
          !((rtmGetTFinal(recti_response_M)-
             (((recti_response_M->Timing.clockTick1+
                recti_response_M->Timing.clockTickH1* 4294967296.0)) * 0.001)) >
            (((recti_response_M->Timing.clockTick1+
               recti_response_M->Timing.clockTickH1* 4294967296.0)) * 0.001) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(recti_response_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&recti_response_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++recti_response_M->Timing.clockTick0)) {
      ++recti_response_M->Timing.clockTickH0;
    }

    recti_response_M->Timing.t[0] = rtsiGetSolverStopTime
      (&recti_response_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      recti_response_M->Timing.clockTick1++;
      if (!recti_response_M->Timing.clockTick1) {
        recti_response_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void recti_response_derivatives(void)
{
  XDot_recti_response_T *_rtXdot;
  _rtXdot = ((XDot_recti_response_T *) recti_response_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = recti_response_B.Integrator3;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = recti_response_B.Integrator2;

  /* Derivatives for Integrator: '<S1>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = recti_response_B.um1;

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = recti_response_B.um2;
}

/* Model initialize function */
void recti_response_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)recti_response_M, 0,
                sizeof(RT_MODEL_recti_response_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&recti_response_M->solverInfo,
                          &recti_response_M->Timing.simTimeStep);
    rtsiSetTPtr(&recti_response_M->solverInfo, &rtmGetTPtr(recti_response_M));
    rtsiSetStepSizePtr(&recti_response_M->solverInfo,
                       &recti_response_M->Timing.stepSize0);
    rtsiSetdXPtr(&recti_response_M->solverInfo, &recti_response_M->derivs);
    rtsiSetContStatesPtr(&recti_response_M->solverInfo, (real_T **)
                         &recti_response_M->contStates);
    rtsiSetNumContStatesPtr(&recti_response_M->solverInfo,
      &recti_response_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&recti_response_M->solverInfo,
      &recti_response_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&recti_response_M->solverInfo,
      &recti_response_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&recti_response_M->solverInfo,
      &recti_response_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&recti_response_M->solverInfo, (&rtmGetErrorStatus
      (recti_response_M)));
    rtsiSetRTModelPtr(&recti_response_M->solverInfo, recti_response_M);
  }

  rtsiSetSimTimeStep(&recti_response_M->solverInfo, MAJOR_TIME_STEP);
  recti_response_M->intgData.y = recti_response_M->odeY;
  recti_response_M->intgData.f[0] = recti_response_M->odeF[0];
  recti_response_M->intgData.f[1] = recti_response_M->odeF[1];
  recti_response_M->intgData.f[2] = recti_response_M->odeF[2];
  recti_response_M->intgData.f[3] = recti_response_M->odeF[3];
  recti_response_M->contStates = ((X_recti_response_T *) &recti_response_X);
  rtsiSetSolverData(&recti_response_M->solverInfo, (void *)
                    &recti_response_M->intgData);
  rtsiSetSolverName(&recti_response_M->solverInfo,"ode4");
  rtmSetTPtr(recti_response_M, &recti_response_M->Timing.tArray[0]);
  rtmSetTFinal(recti_response_M, 10.0);
  recti_response_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    recti_response_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(recti_response_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(recti_response_M->rtwLogInfo, (NULL));
    rtliSetLogT(recti_response_M->rtwLogInfo, "tout");
    rtliSetLogX(recti_response_M->rtwLogInfo, "");
    rtliSetLogXFinal(recti_response_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(recti_response_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(recti_response_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(recti_response_M->rtwLogInfo, 0);
    rtliSetLogDecimation(recti_response_M->rtwLogInfo, 1);
    rtliSetLogY(recti_response_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(recti_response_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(recti_response_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &recti_response_B), 0,
                sizeof(B_recti_response_T));

  /* states (continuous) */
  {
    (void) memset((void *)&recti_response_X, 0,
                  sizeof(X_recti_response_T));
  }

  /* states (dwork) */
  (void) memset((void *)&recti_response_DW, 0,
                sizeof(DW_recti_response_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(recti_response_M->rtwLogInfo, 0.0,
    rtmGetTFinal(recti_response_M), recti_response_M->Timing.stepSize0,
    (&rtmGetErrorStatus(recti_response_M)));

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

    static char_T rt_ScopeBlockName[] = "recti_response/Scope ";
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
    recti_response_DW.Scope_PWORK.LoggedData = rt_CreateStructLogVar(
      recti_response_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(recti_response_M),
      recti_response_M->Timing.stepSize0,
      (&rtmGetErrorStatus(recti_response_M)),
      "ScopeData",
      1,
      0,
      1,
      0.001,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (recti_response_DW.Scope_PWORK.LoggedData == (NULL))
      return;
  }

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  recti_response_X.Integrator1_CSTATE = recti_response_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  recti_response_X.Integrator_CSTATE = recti_response_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator3' */
  recti_response_X.Integrator3_CSTATE = recti_response_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator2' */
  recti_response_X.Integrator2_CSTATE = recti_response_P.Integrator2_IC;
}

/* Model terminate function */
void recti_response_terminate(void)
{
  /* (no terminate code required) */
}
