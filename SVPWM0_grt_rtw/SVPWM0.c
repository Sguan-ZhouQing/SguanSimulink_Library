/*
 * SVPWM0.c
 *
 * Code generation for model "SVPWM0".
 *
 * Model version              : 1.8
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Mon Jan  5 17:33:12 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SVPWM0.h"
#include <math.h>
#include <emmintrin.h>
#include "SVPWM0_private.h"
#include "rtwtypes.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <float.h>

/* External inputs (root inport signals with default storage) */
ExtU_SVPWM0_T SVPWM0_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_SVPWM0_T SVPWM0_Y;

/* Real-time model */
static RT_MODEL_SVPWM0_T SVPWM0_M_;
RT_MODEL_SVPWM0_T *const SVPWM0_M = &SVPWM0_M_;
real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      real_T q;
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void SVPWM0_step(void)
{
  real_T tmp_1[2];
  real_T rtb_Add4;
  real_T rtb_Add6;
  real_T rtb_Add7;
  real_T rtb_MathFunction;
  real_T rtb_MathFunction1;
  int32_T tmp;
  int32_T tmp_0;

  /* Saturate: '<S1>/Saturation1' incorporates:
   *  Inport: '<Root>/Uq'
   */
  if (SVPWM0_U.Uq > SVPWM0_P.Saturation1_UpperSat) {
    rtb_MathFunction = SVPWM0_P.Saturation1_UpperSat;
  } else if (SVPWM0_U.Uq < SVPWM0_P.Saturation1_LowerSat) {
    rtb_MathFunction = SVPWM0_P.Saturation1_LowerSat;
  } else {
    rtb_MathFunction = SVPWM0_U.Uq;
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* Trigonometry: '<S1>/Trigonometric Function1' incorporates:
   *  Inport: '<Root>/phi'
   */
  rtb_Add4 = cos(SVPWM0_U.phi);

  /* Saturate: '<S1>/Saturation' incorporates:
   *  Inport: '<Root>/Ud'
   */
  if (SVPWM0_U.Ud > SVPWM0_P.Saturation_UpperSat) {
    rtb_MathFunction1 = SVPWM0_P.Saturation_UpperSat;
  } else if (SVPWM0_U.Ud < SVPWM0_P.Saturation_LowerSat) {
    rtb_MathFunction1 = SVPWM0_P.Saturation_LowerSat;
  } else {
    rtb_MathFunction1 = SVPWM0_U.Ud;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Trigonometry: '<S1>/Trigonometric Function' incorporates:
   *  Inport: '<Root>/phi'
   */
  rtb_Add7 = sin(SVPWM0_U.phi);

  /* Sum: '<S1>/Add1' incorporates:
   *  Product: '<S1>/Product'
   *  Product: '<S1>/Product1'
   */
  rtb_Add6 = rtb_MathFunction * rtb_Add4 + rtb_MathFunction1 * rtb_Add7;

  /* Sum: '<S1>/Add2' incorporates:
   *  Product: '<S1>/Product2'
   *  Product: '<S1>/Product3'
   */
  rtb_Add7 = rtb_MathFunction1 * rtb_Add4 - rtb_MathFunction * rtb_Add7;

  /* Gain: '<S1>/Gain2' incorporates:
   *  Constant: '<S1>/Constant7'
   *  RelationalOperator: '<S1>/Relational Operator2'
   */
  if (SVPWM0_P.Constant7_Value < rtb_Add6) {
    tmp = SVPWM0_P.Gain2_Gain;
  } else {
    tmp = 0;
  }

  /* Gain: '<S1>/Gain3' incorporates:
   *  Abs: '<S1>/Abs'
   *  Abs: '<S1>/Abs1'
   *  Gain: '<S1>/Gain1'
   *  RelationalOperator: '<S1>/Relational Operator4'
   */
  if (fabs(rtb_Add6) > SVPWM0_P.Gain1_Gain * fabs(rtb_Add7)) {
    tmp_0 = SVPWM0_P.Gain3_Gain;
  } else {
    tmp_0 = 0;
  }

  /* Selector: '<S1>/Selector1' incorporates:
   *  Constant: '<S1>/Constant5'
   *  Constant: '<S1>/sector'
   *  Gain: '<S1>/Gain2'
   *  Gain: '<S1>/Gain3'
   *  RelationalOperator: '<S1>/Relational Operator3'
   *  Selector: '<S1>/Selector'
   *  Selector: '<S1>/Selector2'
   *  Selector: '<S1>/Selector3'
   *  Selector: '<S1>/Selector4'
   *  Selector: '<S1>/Selector5'
   *  Selector: '<S1>/Selector6'
   *  Sum: '<S1>/Add3'
   */
  rtb_MathFunction = SVPWM0_P.sector_Value[(uint8_T)(((((uint32_T)tmp << 1) +
    (uint32_T)tmp_0) + ((uint32_T)(rtb_Add7 > SVPWM0_P.Constant5_Value) << 6)) >>
    6)];

  /* Gain: '<S1>/Gain4' incorporates:
   *  Constant: '<S1>/sector'
   *  Selector: '<S1>/Selector1'
   */
  rtb_MathFunction1 = SVPWM0_P.Gain4_Gain * rtb_MathFunction;

  /* Sum: '<S1>/Add4' incorporates:
   *  Product: '<S1>/Product4'
   *  Product: '<S1>/Product5'
   *  Trigonometry: '<S1>/Trigonometric Function2'
   *  Trigonometry: '<S1>/Trigonometric Function3'
   */
  rtb_Add4 = rtb_Add7 * sin(rtb_MathFunction1) - rtb_Add6 * cos
    (rtb_MathFunction1);

  /* Sum: '<S1>/Add5' incorporates:
   *  Constant: '<S1>/Constant3'
   */
  rtb_MathFunction1 -= SVPWM0_P.Constant3_Value;

  /* Sum: '<S1>/Add6' incorporates:
   *  Product: '<S1>/Product6'
   *  Product: '<S1>/Product7'
   *  Trigonometry: '<S1>/Trigonometric Function4'
   *  Trigonometry: '<S1>/Trigonometric Function5'
   */
  rtb_Add6 = rtb_Add6 * cos(rtb_MathFunction1) - rtb_Add7 * sin
    (rtb_MathFunction1);

  /* Sum: '<S1>/Add7' incorporates:
   *  Constant: '<S1>/Constant6'
   */
  rtb_Add7 = (SVPWM0_P.Constant6_Value - rtb_Add4) - rtb_Add6;

  /* Selector: '<S1>/Selector3' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant10'
   *  Constant: '<S1>/Constant11'
   *  Constant: '<S1>/Constant12'
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S1>/Constant8'
   *  Constant: '<S1>/Constant9'
   *  Constant: '<S1>/Phase sequence'
   *  Gain: '<S1>/Gain5'
   *  Gain: '<S1>/Gain6'
   *  Math: '<S1>/Math Function'
   *  Math: '<S1>/Math Function1'
   *  Product: '<S1>/Product8'
   *  Product: '<S1>/Product9'
   *  Selector: '<S1>/Selector'
   *  Selector: '<S1>/Selector2'
   *  Selector: '<S1>/Selector4'
   *  Sum: '<S1>/Add10'
   *  Sum: '<S1>/Add8'
   */
  _mm_storeu_pd(&tmp_1[0], _mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_set_pd
    (SVPWM0_P.Phasesequence_Value[(int32_T)(rtb_MathFunction -
    SVPWM0_P.Constant12_Value) + 6 * (int32_T)SVPWM0_P.Constant11_Value],
     SVPWM0_P.Phasesequence_Value[(int32_T)(rtb_MathFunction -
    SVPWM0_P.Constant4_Value) + 6 * (int32_T)SVPWM0_P.Constant2_Value]),
    _mm_set1_pd(rtb_Add4)), _mm_mul_pd(_mm_set_pd(SVPWM0_P.Phasesequence_Value[6
    * (int32_T)SVPWM0_P.Constant8_Value + (int32_T)rt_modd_snf(rtb_MathFunction,
    SVPWM0_P.Constant9_Value)], SVPWM0_P.Phasesequence_Value[6 * (int32_T)
    SVPWM0_P.Constant1_Value + (int32_T)rt_modd_snf(rtb_MathFunction,
    SVPWM0_P.Constant10_Value)]), _mm_set1_pd(rtb_Add6))), _mm_mul_pd(_mm_set_pd
    (SVPWM0_P.Gain6_Gain, SVPWM0_P.Gain5_Gain), _mm_set1_pd(rtb_Add7))));

  /* Outport: '<Root>/du' */
  SVPWM0_Y.du = tmp_1[0];

  /* Outport: '<Root>/dv' */
  SVPWM0_Y.dv = tmp_1[1];

  /* Outport: '<Root>/dw' incorporates:
   *  Constant: '<S1>/Constant13'
   *  Constant: '<S1>/Constant14'
   *  Constant: '<S1>/Constant15'
   *  Constant: '<S1>/Constant16'
   *  Constant: '<S1>/Phase sequence'
   *  Gain: '<S1>/Gain7'
   *  Math: '<S1>/Math Function2'
   *  Product: '<S1>/Product12'
   *  Product: '<S1>/Product13'
   *  Selector: '<S1>/Selector5'
   *  Selector: '<S1>/Selector6'
   *  Sum: '<S1>/Add12'
   *  Sum: '<S1>/Add13'
   */
  SVPWM0_Y.dw = (SVPWM0_P.Phasesequence_Value[(int32_T)(rtb_MathFunction -
    SVPWM0_P.Constant16_Value) + 6 * (int32_T)SVPWM0_P.Constant15_Value] *
                 rtb_Add4 + SVPWM0_P.Phasesequence_Value[6 * (int32_T)
                 SVPWM0_P.Constant13_Value + (int32_T)rt_modd_snf
                 (rtb_MathFunction, SVPWM0_P.Constant14_Value)] * rtb_Add6) +
    SVPWM0_P.Gain7_Gain * rtb_Add7;

  /* Matfile logging */
  rt_UpdateTXYLogVars(SVPWM0_M->rtwLogInfo, (&SVPWM0_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(SVPWM0_M)!=-1) &&
        !((rtmGetTFinal(SVPWM0_M)-SVPWM0_M->Timing.taskTime0) >
          SVPWM0_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(SVPWM0_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++SVPWM0_M->Timing.clockTick0)) {
    ++SVPWM0_M->Timing.clockTickH0;
  }

  SVPWM0_M->Timing.taskTime0 = SVPWM0_M->Timing.clockTick0 *
    SVPWM0_M->Timing.stepSize0 + SVPWM0_M->Timing.clockTickH0 *
    SVPWM0_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void SVPWM0_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)SVPWM0_M, 0,
                sizeof(RT_MODEL_SVPWM0_T));
  rtmSetTFinal(SVPWM0_M, 10.0);
  SVPWM0_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    SVPWM0_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(SVPWM0_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(SVPWM0_M->rtwLogInfo, (NULL));
    rtliSetLogT(SVPWM0_M->rtwLogInfo, "tout");
    rtliSetLogX(SVPWM0_M->rtwLogInfo, "");
    rtliSetLogXFinal(SVPWM0_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(SVPWM0_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(SVPWM0_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(SVPWM0_M->rtwLogInfo, 0);
    rtliSetLogDecimation(SVPWM0_M->rtwLogInfo, 1);
    rtliSetLogY(SVPWM0_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(SVPWM0_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(SVPWM0_M->rtwLogInfo, (NULL));
  }

  /* external inputs */
  (void)memset(&SVPWM0_U, 0, sizeof(ExtU_SVPWM0_T));

  /* external outputs */
  (void)memset(&SVPWM0_Y, 0, sizeof(ExtY_SVPWM0_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(SVPWM0_M->rtwLogInfo, 0.0, rtmGetTFinal
    (SVPWM0_M), SVPWM0_M->Timing.stepSize0, (&rtmGetErrorStatus(SVPWM0_M)));
}

/* Model terminate function */
void SVPWM0_terminate(void)
{
  /* (no terminate code required) */
}
