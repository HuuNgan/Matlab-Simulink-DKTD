/*
 * motor_cont_ctrl0.c
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

/* Block signals (default storage) */
B_motor_cont_ctrl0_T motor_cont_ctrl0_B;

/* Continuous states */
X_motor_cont_ctrl0_T motor_cont_ctrl0_X;

/* Block states (default storage) */
DW_motor_cont_ctrl0_T motor_cont_ctrl0_DW;

/* Real-time model */
RT_MODEL_motor_cont_ctrl0_T motor_cont_ctrl0_M_;
RT_MODEL_motor_cont_ctrl0_T *const motor_cont_ctrl0_M = &motor_cont_ctrl0_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

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
  motor_cont_ctrl0_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  motor_cont_ctrl0_step();
  motor_cont_ctrl0_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  motor_cont_ctrl0_step();
  motor_cont_ctrl0_derivatives();

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

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T q;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    y = (rtNaN);
  } else if ((u1 != 0.0) && (u1 != trunc(u1))) {
    q = fabs(u0 / u1);
    if (fabs(q - floor(q + 0.5)) <= DBL_EPSILON * q) {
      y = 0.0 * u0;
    } else {
      y = fmod(u0, u1);
    }
  } else {
    y = fmod(u0, u1);
  }

  return y;
}

/* Model step function */
void motor_cont_ctrl0_step(void)
{
  real_T rtb_Sum;
  if (rtmIsMajorTimeStep(motor_cont_ctrl0_M)) {
    /* set solver stop time */
    if (!(motor_cont_ctrl0_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&motor_cont_ctrl0_M->solverInfo,
                            ((motor_cont_ctrl0_M->Timing.clockTickH0 + 1) *
        motor_cont_ctrl0_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&motor_cont_ctrl0_M->solverInfo,
                            ((motor_cont_ctrl0_M->Timing.clockTick0 + 1) *
        motor_cont_ctrl0_M->Timing.stepSize0 +
        motor_cont_ctrl0_M->Timing.clockTickH0 *
        motor_cont_ctrl0_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(motor_cont_ctrl0_M)) {
    motor_cont_ctrl0_M->Timing.t[0] = rtsiGetT(&motor_cont_ctrl0_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(motor_cont_ctrl0_M)) {
    /* Step: '<Root>/Step ' */
    if ((((motor_cont_ctrl0_M->Timing.clockTick1+
           motor_cont_ctrl0_M->Timing.clockTickH1* 4294967296.0)) * 0.0001) <
        motor_cont_ctrl0_P.Step_Time) {
      motor_cont_ctrl0_B.Step = motor_cont_ctrl0_P.Step_Y0;
    } else {
      motor_cont_ctrl0_B.Step = motor_cont_ctrl0_P.Step_YFinal;
    }

    /* End of Step: '<Root>/Step ' */
  }

  /* ManualSwitch: '<Root>/SW_R' incorporates:
   *  Clock: '<S1>/Clock'
   *  Constant: '<S1>/Constant'
   *  Lookup_n-D: '<S1>/Look-Up Table1'
   *  Math: '<S1>/Math Function'
   *  S-Function (sfun_tstart): '<S1>/startTime'
   *  Sum: '<S1>/Sum'
   */
  if (motor_cont_ctrl0_P.SW_R_CurrentSetting == 1) {
    motor_cont_ctrl0_B.SW_R = motor_cont_ctrl0_B.Step;
  } else {
    motor_cont_ctrl0_B.SW_R = look1_binlxpw(rt_remd_snf
      (motor_cont_ctrl0_M->Timing.t[0] - (0.0),
       motor_cont_ctrl0_P.Constant_Value),
      motor_cont_ctrl0_P.LookUpTable1_bp01Data,
      motor_cont_ctrl0_P.Ramp_rep_seq_y, 1U);
  }

  /* End of ManualSwitch: '<Root>/SW_R' */

  /* TransferFcn: '<Root>/DC Motor' */
  motor_cont_ctrl0_B.DCMotor = 0.0;
  motor_cont_ctrl0_B.DCMotor += motor_cont_ctrl0_P.DCMotor_C[0] *
    motor_cont_ctrl0_X.DCMotor_CSTATE[0];
  motor_cont_ctrl0_B.DCMotor += motor_cont_ctrl0_P.DCMotor_C[1] *
    motor_cont_ctrl0_X.DCMotor_CSTATE[1];

  /* ManualSwitch: '<Root>/SW_Y' incorporates:
   *  Integrator: '<Root>/Integrator1'
   */
  if (motor_cont_ctrl0_P.SW_Y_CurrentSetting == 1) {
    motor_cont_ctrl0_B.SW_Y = motor_cont_ctrl0_B.DCMotor;
  } else {
    motor_cont_ctrl0_B.SW_Y = motor_cont_ctrl0_X.Integrator1_CSTATE;
  }

  /* End of ManualSwitch: '<Root>/SW_Y' */
  if (rtmIsMajorTimeStep(motor_cont_ctrl0_M)) {
    /* Scope: '<Root>/Scope ' */
    if (rtmIsMajorTimeStep(motor_cont_ctrl0_M)) {
      StructLogVar *svar = (StructLogVar *)
        motor_cont_ctrl0_DW.Scope_PWORK.LoggedData;
      LogVar *var = svar->signals.values;

      /* time */
      {
        double locTime = (((motor_cont_ctrl0_M->Timing.clockTick1+
                            motor_cont_ctrl0_M->Timing.clockTickH1* 4294967296.0))
                          * 0.0001);
        ;
        rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
      }

      /* signals */
      {
        real_T up0[2];
        up0[0] = motor_cont_ctrl0_B.SW_R;
        up0[1] = motor_cont_ctrl0_B.SW_Y;
        rt_UpdateLogVar((LogVar *)var, up0, 0);
      }
    }
  }

  /* Sum: '<Root>/Sum' */
  rtb_Sum = motor_cont_ctrl0_B.SW_R - motor_cont_ctrl0_B.SW_Y;

  /* Sum: '<Root>/Add' incorporates:
   *  Gain: '<Root>/Kp'
   *  Integrator: '<Root>/Integrator '
   */
  motor_cont_ctrl0_B.Add = motor_cont_ctrl0_P.Kp_Gain * rtb_Sum +
    motor_cont_ctrl0_X.Integrator_CSTATE;

  /* Gain: '<Root>/Ki' */
  motor_cont_ctrl0_B.Ki = motor_cont_ctrl0_P.Ki_Gain * rtb_Sum;
  if (rtmIsMajorTimeStep(motor_cont_ctrl0_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(motor_cont_ctrl0_M->rtwLogInfo,
                        (motor_cont_ctrl0_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(motor_cont_ctrl0_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(motor_cont_ctrl0_M)!=-1) &&
          !((rtmGetTFinal(motor_cont_ctrl0_M)-
             (((motor_cont_ctrl0_M->Timing.clockTick1+
                motor_cont_ctrl0_M->Timing.clockTickH1* 4294967296.0)) * 0.0001))
            > (((motor_cont_ctrl0_M->Timing.clockTick1+
                 motor_cont_ctrl0_M->Timing.clockTickH1* 4294967296.0)) * 0.0001)
            * (DBL_EPSILON))) {
        rtmSetErrorStatus(motor_cont_ctrl0_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&motor_cont_ctrl0_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++motor_cont_ctrl0_M->Timing.clockTick0)) {
      ++motor_cont_ctrl0_M->Timing.clockTickH0;
    }

    motor_cont_ctrl0_M->Timing.t[0] = rtsiGetSolverStopTime
      (&motor_cont_ctrl0_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.0001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.0001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      motor_cont_ctrl0_M->Timing.clockTick1++;
      if (!motor_cont_ctrl0_M->Timing.clockTick1) {
        motor_cont_ctrl0_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void motor_cont_ctrl0_derivatives(void)
{
  XDot_motor_cont_ctrl0_T *_rtXdot;
  _rtXdot = ((XDot_motor_cont_ctrl0_T *) motor_cont_ctrl0_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/DC Motor' */
  _rtXdot->DCMotor_CSTATE[0] = 0.0;
  _rtXdot->DCMotor_CSTATE[0] += motor_cont_ctrl0_P.DCMotor_A[0] *
    motor_cont_ctrl0_X.DCMotor_CSTATE[0];
  _rtXdot->DCMotor_CSTATE[1] = 0.0;
  _rtXdot->DCMotor_CSTATE[0] += motor_cont_ctrl0_P.DCMotor_A[1] *
    motor_cont_ctrl0_X.DCMotor_CSTATE[1];
  _rtXdot->DCMotor_CSTATE[1] += motor_cont_ctrl0_X.DCMotor_CSTATE[0];
  _rtXdot->DCMotor_CSTATE[0] += motor_cont_ctrl0_B.Add;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = motor_cont_ctrl0_B.DCMotor;

  /* Derivatives for Integrator: '<Root>/Integrator ' */
  _rtXdot->Integrator_CSTATE = motor_cont_ctrl0_B.Ki;
}

/* Model initialize function */
void motor_cont_ctrl0_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)motor_cont_ctrl0_M, 0,
                sizeof(RT_MODEL_motor_cont_ctrl0_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&motor_cont_ctrl0_M->solverInfo,
                          &motor_cont_ctrl0_M->Timing.simTimeStep);
    rtsiSetTPtr(&motor_cont_ctrl0_M->solverInfo, &rtmGetTPtr(motor_cont_ctrl0_M));
    rtsiSetStepSizePtr(&motor_cont_ctrl0_M->solverInfo,
                       &motor_cont_ctrl0_M->Timing.stepSize0);
    rtsiSetdXPtr(&motor_cont_ctrl0_M->solverInfo, &motor_cont_ctrl0_M->derivs);
    rtsiSetContStatesPtr(&motor_cont_ctrl0_M->solverInfo, (real_T **)
                         &motor_cont_ctrl0_M->contStates);
    rtsiSetNumContStatesPtr(&motor_cont_ctrl0_M->solverInfo,
      &motor_cont_ctrl0_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&motor_cont_ctrl0_M->solverInfo,
      &motor_cont_ctrl0_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&motor_cont_ctrl0_M->solverInfo,
      &motor_cont_ctrl0_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&motor_cont_ctrl0_M->solverInfo,
      &motor_cont_ctrl0_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&motor_cont_ctrl0_M->solverInfo, (&rtmGetErrorStatus
      (motor_cont_ctrl0_M)));
    rtsiSetRTModelPtr(&motor_cont_ctrl0_M->solverInfo, motor_cont_ctrl0_M);
  }

  rtsiSetSimTimeStep(&motor_cont_ctrl0_M->solverInfo, MAJOR_TIME_STEP);
  motor_cont_ctrl0_M->intgData.y = motor_cont_ctrl0_M->odeY;
  motor_cont_ctrl0_M->intgData.f[0] = motor_cont_ctrl0_M->odeF[0];
  motor_cont_ctrl0_M->intgData.f[1] = motor_cont_ctrl0_M->odeF[1];
  motor_cont_ctrl0_M->intgData.f[2] = motor_cont_ctrl0_M->odeF[2];
  motor_cont_ctrl0_M->contStates = ((X_motor_cont_ctrl0_T *) &motor_cont_ctrl0_X);
  rtsiSetSolverData(&motor_cont_ctrl0_M->solverInfo, (void *)
                    &motor_cont_ctrl0_M->intgData);
  rtsiSetSolverName(&motor_cont_ctrl0_M->solverInfo,"ode3");
  rtmSetTPtr(motor_cont_ctrl0_M, &motor_cont_ctrl0_M->Timing.tArray[0]);
  rtmSetTFinal(motor_cont_ctrl0_M, 30.0);
  motor_cont_ctrl0_M->Timing.stepSize0 = 0.0001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    motor_cont_ctrl0_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(motor_cont_ctrl0_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(motor_cont_ctrl0_M->rtwLogInfo, (NULL));
    rtliSetLogT(motor_cont_ctrl0_M->rtwLogInfo, "tout");
    rtliSetLogX(motor_cont_ctrl0_M->rtwLogInfo, "");
    rtliSetLogXFinal(motor_cont_ctrl0_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(motor_cont_ctrl0_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(motor_cont_ctrl0_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(motor_cont_ctrl0_M->rtwLogInfo, 0);
    rtliSetLogDecimation(motor_cont_ctrl0_M->rtwLogInfo, 1);
    rtliSetLogY(motor_cont_ctrl0_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(motor_cont_ctrl0_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(motor_cont_ctrl0_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &motor_cont_ctrl0_B), 0,
                sizeof(B_motor_cont_ctrl0_T));

  /* states (continuous) */
  {
    (void) memset((void *)&motor_cont_ctrl0_X, 0,
                  sizeof(X_motor_cont_ctrl0_T));
  }

  /* states (dwork) */
  (void) memset((void *)&motor_cont_ctrl0_DW, 0,
                sizeof(DW_motor_cont_ctrl0_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(motor_cont_ctrl0_M->rtwLogInfo, 0.0,
    rtmGetTFinal(motor_cont_ctrl0_M), motor_cont_ctrl0_M->Timing.stepSize0,
    (&rtmGetErrorStatus(motor_cont_ctrl0_M)));

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

    static char_T rt_ScopeBlockName[] = "motor_cont_ctrl0/Scope ";
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
    motor_cont_ctrl0_DW.Scope_PWORK.LoggedData = rt_CreateStructLogVar(
      motor_cont_ctrl0_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(motor_cont_ctrl0_M),
      motor_cont_ctrl0_M->Timing.stepSize0,
      (&rtmGetErrorStatus(motor_cont_ctrl0_M)),
      "ScopeData",
      1,
      0,
      1,
      0.0001,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (motor_cont_ctrl0_DW.Scope_PWORK.LoggedData == (NULL))
      return;
  }

  /* InitializeConditions for TransferFcn: '<Root>/DC Motor' */
  motor_cont_ctrl0_X.DCMotor_CSTATE[0] = 0.0;
  motor_cont_ctrl0_X.DCMotor_CSTATE[1] = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  motor_cont_ctrl0_X.Integrator1_CSTATE = motor_cont_ctrl0_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator ' */
  motor_cont_ctrl0_X.Integrator_CSTATE = motor_cont_ctrl0_P.Integrator_IC;
}

/* Model terminate function */
void motor_cont_ctrl0_terminate(void)
{
  /* (no terminate code required) */
}
