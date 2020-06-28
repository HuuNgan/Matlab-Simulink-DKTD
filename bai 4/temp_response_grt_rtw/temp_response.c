/*
 * temp_response.c
 *
 * Code generation for model "temp_response".
 *
 * Model version              : 1.1
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Thu Jun 18 15:20:17 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "temp_response.h"
#include "temp_response_private.h"

/* Block signals (default storage) */
B_temp_response_T temp_response_B;

/* Continuous states */
X_temp_response_T temp_response_X;

/* Block states (default storage) */
DW_temp_response_T temp_response_DW;

/* Real-time model */
RT_MODEL_temp_response_T temp_response_M_;
RT_MODEL_temp_response_T *const temp_response_M = &temp_response_M_;

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
  temp_response_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  temp_response_step();
  temp_response_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  temp_response_step();
  temp_response_derivatives();

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
void temp_response_step(void)
{
  if (rtmIsMajorTimeStep(temp_response_M)) {
    /* set solver stop time */
    if (!(temp_response_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&temp_response_M->solverInfo,
                            ((temp_response_M->Timing.clockTickH0 + 1) *
        temp_response_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&temp_response_M->solverInfo,
                            ((temp_response_M->Timing.clockTick0 + 1) *
        temp_response_M->Timing.stepSize0 + temp_response_M->Timing.clockTickH0 *
        temp_response_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(temp_response_M)) {
    temp_response_M->Timing.t[0] = rtsiGetT(&temp_response_M->solverInfo);
  }

  /* TransferFcn: '<Root>/Transfer Fcn ' */
  temp_response_B.TransferFcn = 0.0;
  temp_response_B.TransferFcn += temp_response_P.TransferFcn_C[0] *
    temp_response_X.TransferFcn_CSTATE[0];
  temp_response_B.TransferFcn += temp_response_P.TransferFcn_C[1] *
    temp_response_X.TransferFcn_CSTATE[1];
  if (rtmIsMajorTimeStep(temp_response_M)) {
  }

  if (rtmIsMajorTimeStep(temp_response_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(temp_response_M->rtwLogInfo, (temp_response_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(temp_response_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(temp_response_M)!=-1) &&
          !((rtmGetTFinal(temp_response_M)-(((temp_response_M->Timing.clockTick1
               +temp_response_M->Timing.clockTickH1* 4294967296.0)) * 0.1)) >
            (((temp_response_M->Timing.clockTick1+
               temp_response_M->Timing.clockTickH1* 4294967296.0)) * 0.1) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(temp_response_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&temp_response_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++temp_response_M->Timing.clockTick0)) {
      ++temp_response_M->Timing.clockTickH0;
    }

    temp_response_M->Timing.t[0] = rtsiGetSolverStopTime
      (&temp_response_M->solverInfo);

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
      temp_response_M->Timing.clockTick1++;
      if (!temp_response_M->Timing.clockTick1) {
        temp_response_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void temp_response_derivatives(void)
{
  XDot_temp_response_T *_rtXdot;
  _rtXdot = ((XDot_temp_response_T *) temp_response_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn ' incorporates:
   *  Constant: '<Root>/U'
   */
  _rtXdot->TransferFcn_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += temp_response_P.TransferFcn_A[0] *
    temp_response_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += temp_response_P.TransferFcn_A[1] *
    temp_response_X.TransferFcn_CSTATE[1];
  _rtXdot->TransferFcn_CSTATE[1] += temp_response_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[0] += temp_response_P.U_Value;
}

/* Model initialize function */
void temp_response_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)temp_response_M, 0,
                sizeof(RT_MODEL_temp_response_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&temp_response_M->solverInfo,
                          &temp_response_M->Timing.simTimeStep);
    rtsiSetTPtr(&temp_response_M->solverInfo, &rtmGetTPtr(temp_response_M));
    rtsiSetStepSizePtr(&temp_response_M->solverInfo,
                       &temp_response_M->Timing.stepSize0);
    rtsiSetdXPtr(&temp_response_M->solverInfo, &temp_response_M->derivs);
    rtsiSetContStatesPtr(&temp_response_M->solverInfo, (real_T **)
                         &temp_response_M->contStates);
    rtsiSetNumContStatesPtr(&temp_response_M->solverInfo,
      &temp_response_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&temp_response_M->solverInfo,
      &temp_response_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&temp_response_M->solverInfo,
      &temp_response_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&temp_response_M->solverInfo,
      &temp_response_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&temp_response_M->solverInfo, (&rtmGetErrorStatus
      (temp_response_M)));
    rtsiSetRTModelPtr(&temp_response_M->solverInfo, temp_response_M);
  }

  rtsiSetSimTimeStep(&temp_response_M->solverInfo, MAJOR_TIME_STEP);
  temp_response_M->intgData.y = temp_response_M->odeY;
  temp_response_M->intgData.f[0] = temp_response_M->odeF[0];
  temp_response_M->intgData.f[1] = temp_response_M->odeF[1];
  temp_response_M->intgData.f[2] = temp_response_M->odeF[2];
  temp_response_M->contStates = ((X_temp_response_T *) &temp_response_X);
  rtsiSetSolverData(&temp_response_M->solverInfo, (void *)
                    &temp_response_M->intgData);
  rtsiSetSolverName(&temp_response_M->solverInfo,"ode3");
  rtmSetTPtr(temp_response_M, &temp_response_M->Timing.tArray[0]);
  rtmSetTFinal(temp_response_M, 700.0);
  temp_response_M->Timing.stepSize0 = 0.1;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    temp_response_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(temp_response_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(temp_response_M->rtwLogInfo, (NULL));
    rtliSetLogT(temp_response_M->rtwLogInfo, "tout");
    rtliSetLogX(temp_response_M->rtwLogInfo, "");
    rtliSetLogXFinal(temp_response_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(temp_response_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(temp_response_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(temp_response_M->rtwLogInfo, 0);
    rtliSetLogDecimation(temp_response_M->rtwLogInfo, 1);
    rtliSetLogY(temp_response_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(temp_response_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(temp_response_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &temp_response_B), 0,
                sizeof(B_temp_response_T));

  /* states (continuous) */
  {
    (void) memset((void *)&temp_response_X, 0,
                  sizeof(X_temp_response_T));
  }

  /* states (dwork) */
  (void) memset((void *)&temp_response_DW, 0,
                sizeof(DW_temp_response_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(temp_response_M->rtwLogInfo, 0.0,
    rtmGetTFinal(temp_response_M), temp_response_M->Timing.stepSize0,
    (&rtmGetErrorStatus(temp_response_M)));

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn ' */
  temp_response_X.TransferFcn_CSTATE[0] = 0.0;
  temp_response_X.TransferFcn_CSTATE[1] = 0.0;
}

/* Model terminate function */
void temp_response_terminate(void)
{
  /* (no terminate code required) */
}
