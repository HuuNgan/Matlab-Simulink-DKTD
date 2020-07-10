/*
 * recti_feedback_ctrl2.c
 *
 * Code generation for model "recti_feedback_ctrl2".
 *
 * Model version              : 1.5
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Sun Jul  5 13:55:03 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "recti_feedback_ctrl2.h"
#include "recti_feedback_ctrl2_private.h"

/* Block signals (default storage) */
B_recti_feedback_ctrl2_T recti_feedback_ctrl2_B;

/* Continuous states */
X_recti_feedback_ctrl2_T recti_feedback_ctrl2_X;

/* Block states (default storage) */
DW_recti_feedback_ctrl2_T recti_feedback_ctrl2_DW;

/* Real-time model */
RT_MODEL_recti_feedback_ctrl2_T recti_feedback_ctrl2_M_;
RT_MODEL_recti_feedback_ctrl2_T *const recti_feedback_ctrl2_M =
  &recti_feedback_ctrl2_M_;

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
  recti_feedback_ctrl2_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  recti_feedback_ctrl2_step();
  recti_feedback_ctrl2_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  recti_feedback_ctrl2_step();
  recti_feedback_ctrl2_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  recti_feedback_ctrl2_step();
  recti_feedback_ctrl2_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void recti_feedback_ctrl2_step(void)
{
  real_T um1_tmp;
  if (rtmIsMajorTimeStep(recti_feedback_ctrl2_M)) {
    /* set solver stop time */
    if (!(recti_feedback_ctrl2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&recti_feedback_ctrl2_M->solverInfo,
                            ((recti_feedback_ctrl2_M->Timing.clockTickH0 + 1) *
        recti_feedback_ctrl2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&recti_feedback_ctrl2_M->solverInfo,
                            ((recti_feedback_ctrl2_M->Timing.clockTick0 + 1) *
        recti_feedback_ctrl2_M->Timing.stepSize0 +
        recti_feedback_ctrl2_M->Timing.clockTickH0 *
        recti_feedback_ctrl2_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(recti_feedback_ctrl2_M)) {
    recti_feedback_ctrl2_M->Timing.t[0] = rtsiGetT
      (&recti_feedback_ctrl2_M->solverInfo);
  }

  /* Integrator: '<S1>/Integrator3' */
  recti_feedback_ctrl2_B.Integrator3 = recti_feedback_ctrl2_X.Integrator3_CSTATE;

  /* Integrator: '<S1>/Integrator2' */
  recti_feedback_ctrl2_B.Integrator2 = recti_feedback_ctrl2_X.Integrator2_CSTATE;
  if (rtmIsMajorTimeStep(recti_feedback_ctrl2_M)) {
    /* Gain: '<Root>/Gain3 [0; 0; 1; 0]' incorporates:
     *  Constant: '<Root>/Set point posotion2 (mm)'
     */
    recti_feedback_ctrl2_B.Gain30010[0] = recti_feedback_ctrl2_P.Gain30010_Gain
      [0] * recti_feedback_ctrl2_P.Setpointposotion2mm_Value;
    recti_feedback_ctrl2_B.Gain30010[1] = recti_feedback_ctrl2_P.Gain30010_Gain
      [1] * recti_feedback_ctrl2_P.Setpointposotion2mm_Value;
    recti_feedback_ctrl2_B.Gain30010[2] = recti_feedback_ctrl2_P.Gain30010_Gain
      [2] * recti_feedback_ctrl2_P.Setpointposotion2mm_Value;
    recti_feedback_ctrl2_B.Gain30010[3] = recti_feedback_ctrl2_P.Gain30010_Gain
      [3] * recti_feedback_ctrl2_P.Setpointposotion2mm_Value;
  }

  /* Sum: '<Root>/Add ' incorporates:
   *  Gain: '<Root>/Gain1 1000'
   *  Gain: '<Root>/Kf1'
   *  Gain: '<Root>/Kf2'
   *  Gain: '<Root>/Kf3'
   *  Gain: '<Root>/Kf4'
   *  Integrator: '<S1>/Integrator'
   *  Integrator: '<S1>/Integrator1'
   *  Sum: '<Root>/Add1 '
   */
  recti_feedback_ctrl2_B.Add = (((recti_feedback_ctrl2_B.Gain30010[0] -
    recti_feedback_ctrl2_P.Gain11000_Gain *
    recti_feedback_ctrl2_X.Integrator1_CSTATE) * recti_feedback_ctrl2_P.Kf1_Gain
    + (recti_feedback_ctrl2_B.Gain30010[1] -
       recti_feedback_ctrl2_P.Gain11000_Gain *
       recti_feedback_ctrl2_B.Integrator3) * recti_feedback_ctrl2_P.Kf2_Gain) +
    (recti_feedback_ctrl2_B.Gain30010[2] - recti_feedback_ctrl2_P.Gain11000_Gain
     * recti_feedback_ctrl2_X.Integrator_CSTATE) *
    recti_feedback_ctrl2_P.Kf3_Gain) + (recti_feedback_ctrl2_B.Gain30010[3] -
    recti_feedback_ctrl2_P.Gain11000_Gain * recti_feedback_ctrl2_B.Integrator2) *
    recti_feedback_ctrl2_P.Kf4_Gain;
  if (rtmIsMajorTimeStep(recti_feedback_ctrl2_M)) {
  }

  /* Gain: '<Root>/Gain2 1000 ' incorporates:
   *  Integrator: '<S1>/Integrator'
   *  Integrator: '<S1>/Integrator1'
   */
  recti_feedback_ctrl2_B.Gain21000[0] = recti_feedback_ctrl2_P.Gain21000_Gain *
    recti_feedback_ctrl2_X.Integrator1_CSTATE;
  recti_feedback_ctrl2_B.Gain21000[1] = recti_feedback_ctrl2_P.Gain21000_Gain *
    recti_feedback_ctrl2_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(recti_feedback_ctrl2_M)) {
    /* Scope: '<Root>/Scope ' */
    if (rtmIsMajorTimeStep(recti_feedback_ctrl2_M)) {
      StructLogVar *svar = (StructLogVar *)
        recti_feedback_ctrl2_DW.Scope_PWORK.LoggedData;
      LogVar *var = svar->signals.values;

      /* time */
      {
        double locTime = (((recti_feedback_ctrl2_M->Timing.clockTick1+
                            recti_feedback_ctrl2_M->Timing.clockTickH1*
                            4294967296.0)) * 0.001);
        ;
        rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
      }

      /* signals */
      {
        real_T up0[2];
        up0[0] = recti_feedback_ctrl2_B.Gain21000[0];
        up0[1] = recti_feedback_ctrl2_B.Gain21000[1];
        rt_UpdateLogVar((LogVar *)var, up0, 0);
      }
    }
  }

  /* Fcn: '<S1>/Fcn1 ' incorporates:
   *  Fcn: '<S1>/Fcn2 '
   *  Integrator: '<S1>/Integrator'
   *  Integrator: '<S1>/Integrator1'
   */
  um1_tmp = (recti_feedback_ctrl2_X.Integrator_CSTATE -
             recti_feedback_ctrl2_X.Integrator1_CSTATE) * 1000.0;

  /* Gain: '<S1>/1//m1' incorporates:
   *  Fcn: '<S1>/Fcn1 '
   *  Integrator: '<S1>/Integrator1'
   */
  recti_feedback_ctrl2_B.um1 = ((um1_tmp - 1000.0 *
    recti_feedback_ctrl2_X.Integrator1_CSTATE) - 10.0 *
    recti_feedback_ctrl2_B.Integrator3) * recti_feedback_ctrl2_P.um1_Gain;

  /* Gain: '<S1>/1//m2' incorporates:
   *  Fcn: '<S1>/Fcn2 '
   */
  recti_feedback_ctrl2_B.um2 = ((recti_feedback_ctrl2_B.Add - um1_tmp) - 5.0 *
    recti_feedback_ctrl2_B.Integrator2) * recti_feedback_ctrl2_P.um2_Gain;
  if (rtmIsMajorTimeStep(recti_feedback_ctrl2_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(recti_feedback_ctrl2_M->rtwLogInfo,
                        (recti_feedback_ctrl2_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(recti_feedback_ctrl2_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(recti_feedback_ctrl2_M)!=-1) &&
          !((rtmGetTFinal(recti_feedback_ctrl2_M)-
             (((recti_feedback_ctrl2_M->Timing.clockTick1+
                recti_feedback_ctrl2_M->Timing.clockTickH1* 4294967296.0)) *
              0.001)) > (((recti_feedback_ctrl2_M->Timing.clockTick1+
                           recti_feedback_ctrl2_M->Timing.clockTickH1*
                           4294967296.0)) * 0.001) * (DBL_EPSILON))) {
        rtmSetErrorStatus(recti_feedback_ctrl2_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&recti_feedback_ctrl2_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++recti_feedback_ctrl2_M->Timing.clockTick0)) {
      ++recti_feedback_ctrl2_M->Timing.clockTickH0;
    }

    recti_feedback_ctrl2_M->Timing.t[0] = rtsiGetSolverStopTime
      (&recti_feedback_ctrl2_M->solverInfo);

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
      recti_feedback_ctrl2_M->Timing.clockTick1++;
      if (!recti_feedback_ctrl2_M->Timing.clockTick1) {
        recti_feedback_ctrl2_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void recti_feedback_ctrl2_derivatives(void)
{
  XDot_recti_feedback_ctrl2_T *_rtXdot;
  _rtXdot = ((XDot_recti_feedback_ctrl2_T *) recti_feedback_ctrl2_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = recti_feedback_ctrl2_B.Integrator3;

  /* Derivatives for Integrator: '<S1>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = recti_feedback_ctrl2_B.um1;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = recti_feedback_ctrl2_B.Integrator2;

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = recti_feedback_ctrl2_B.um2;
}

/* Model initialize function */
void recti_feedback_ctrl2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)recti_feedback_ctrl2_M, 0,
                sizeof(RT_MODEL_recti_feedback_ctrl2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&recti_feedback_ctrl2_M->solverInfo,
                          &recti_feedback_ctrl2_M->Timing.simTimeStep);
    rtsiSetTPtr(&recti_feedback_ctrl2_M->solverInfo, &rtmGetTPtr
                (recti_feedback_ctrl2_M));
    rtsiSetStepSizePtr(&recti_feedback_ctrl2_M->solverInfo,
                       &recti_feedback_ctrl2_M->Timing.stepSize0);
    rtsiSetdXPtr(&recti_feedback_ctrl2_M->solverInfo,
                 &recti_feedback_ctrl2_M->derivs);
    rtsiSetContStatesPtr(&recti_feedback_ctrl2_M->solverInfo, (real_T **)
                         &recti_feedback_ctrl2_M->contStates);
    rtsiSetNumContStatesPtr(&recti_feedback_ctrl2_M->solverInfo,
      &recti_feedback_ctrl2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&recti_feedback_ctrl2_M->solverInfo,
      &recti_feedback_ctrl2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&recti_feedback_ctrl2_M->solverInfo,
      &recti_feedback_ctrl2_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&recti_feedback_ctrl2_M->solverInfo,
      &recti_feedback_ctrl2_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&recti_feedback_ctrl2_M->solverInfo,
                          (&rtmGetErrorStatus(recti_feedback_ctrl2_M)));
    rtsiSetRTModelPtr(&recti_feedback_ctrl2_M->solverInfo,
                      recti_feedback_ctrl2_M);
  }

  rtsiSetSimTimeStep(&recti_feedback_ctrl2_M->solverInfo, MAJOR_TIME_STEP);
  recti_feedback_ctrl2_M->intgData.y = recti_feedback_ctrl2_M->odeY;
  recti_feedback_ctrl2_M->intgData.f[0] = recti_feedback_ctrl2_M->odeF[0];
  recti_feedback_ctrl2_M->intgData.f[1] = recti_feedback_ctrl2_M->odeF[1];
  recti_feedback_ctrl2_M->intgData.f[2] = recti_feedback_ctrl2_M->odeF[2];
  recti_feedback_ctrl2_M->intgData.f[3] = recti_feedback_ctrl2_M->odeF[3];
  recti_feedback_ctrl2_M->contStates = ((X_recti_feedback_ctrl2_T *)
    &recti_feedback_ctrl2_X);
  rtsiSetSolverData(&recti_feedback_ctrl2_M->solverInfo, (void *)
                    &recti_feedback_ctrl2_M->intgData);
  rtsiSetSolverName(&recti_feedback_ctrl2_M->solverInfo,"ode4");
  rtmSetTPtr(recti_feedback_ctrl2_M, &recti_feedback_ctrl2_M->Timing.tArray[0]);
  rtmSetTFinal(recti_feedback_ctrl2_M, 5.0);
  recti_feedback_ctrl2_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    recti_feedback_ctrl2_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(recti_feedback_ctrl2_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(recti_feedback_ctrl2_M->rtwLogInfo, (NULL));
    rtliSetLogT(recti_feedback_ctrl2_M->rtwLogInfo, "tout");
    rtliSetLogX(recti_feedback_ctrl2_M->rtwLogInfo, "");
    rtliSetLogXFinal(recti_feedback_ctrl2_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(recti_feedback_ctrl2_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(recti_feedback_ctrl2_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(recti_feedback_ctrl2_M->rtwLogInfo, 0);
    rtliSetLogDecimation(recti_feedback_ctrl2_M->rtwLogInfo, 1);
    rtliSetLogY(recti_feedback_ctrl2_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(recti_feedback_ctrl2_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(recti_feedback_ctrl2_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &recti_feedback_ctrl2_B), 0,
                sizeof(B_recti_feedback_ctrl2_T));

  /* states (continuous) */
  {
    (void) memset((void *)&recti_feedback_ctrl2_X, 0,
                  sizeof(X_recti_feedback_ctrl2_T));
  }

  /* states (dwork) */
  (void) memset((void *)&recti_feedback_ctrl2_DW, 0,
                sizeof(DW_recti_feedback_ctrl2_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(recti_feedback_ctrl2_M->rtwLogInfo, 0.0,
    rtmGetTFinal(recti_feedback_ctrl2_M),
    recti_feedback_ctrl2_M->Timing.stepSize0, (&rtmGetErrorStatus
    (recti_feedback_ctrl2_M)));

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

    static char_T rt_ScopeBlockName[] = "recti_feedback_ctrl2/Scope ";
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
    recti_feedback_ctrl2_DW.Scope_PWORK.LoggedData = rt_CreateStructLogVar(
      recti_feedback_ctrl2_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(recti_feedback_ctrl2_M),
      recti_feedback_ctrl2_M->Timing.stepSize0,
      (&rtmGetErrorStatus(recti_feedback_ctrl2_M)),
      "ScopeData1",
      1,
      0,
      1,
      0.001,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (recti_feedback_ctrl2_DW.Scope_PWORK.LoggedData == (NULL))
      return;
  }

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  recti_feedback_ctrl2_X.Integrator1_CSTATE =
    recti_feedback_ctrl2_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator3' */
  recti_feedback_ctrl2_X.Integrator3_CSTATE =
    recti_feedback_ctrl2_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  recti_feedback_ctrl2_X.Integrator_CSTATE =
    recti_feedback_ctrl2_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator2' */
  recti_feedback_ctrl2_X.Integrator2_CSTATE =
    recti_feedback_ctrl2_P.Integrator2_IC;
}

/* Model terminate function */
void recti_feedback_ctrl2_terminate(void)
{
  /* (no terminate code required) */
}
