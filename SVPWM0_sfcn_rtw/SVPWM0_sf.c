/*
 * SVPWM0_sf.c
 *
 * Code generation for model "SVPWM0_sf".
 *
 * Model version              : 1.8
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Mon Jan  5 17:32:31 2026
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SVPWM0_sf.h"
#include "SVPWM0_sf_types.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <float.h>
#include "SVPWM0_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *SVPWM0_malloc(SimStruct *S);

#endif

#ifndef __RTW_UTFREE__
#if defined (MATLAB_MEX_FILE)

extern void * utMalloc(size_t);
extern void utFree(void *);

#endif
#endif                                 /* #ifndef __RTW_UTFREE__ */

/* Forward declaration for local functions */
static real_T SVPWM0_rt_modd_snf(real_T u0, real_T u1);

#if defined(MATLAB_MEX_FILE)
#include "rt_nonfinite.c"
#endif

static const char_T *RT_MEMORY_ALLOCATION_ERROR =
  "memory allocation error in generated S-Function";
static real_T SVPWM0_rt_modd_snf(real_T u0, real_T u1)
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

/* Start for root system: '<Root>' */
#define MDL_START

static void mdlStart(SimStruct *S)
{
  /* instance underlying S-Function data */
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#if defined(MATLAB_MEX_FILE)
#endif

  SVPWM0_malloc(S);
  if (ssGetErrorStatus(S) != (NULL) ) {
    return;
  }

#endif

  {
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  real_T rtb_Add4;
  real_T rtb_Add6;
  real_T rtb_Add7;
  real_T rtb_MathFunction;
  real_T rtb_MathFunction1;
  real_T rtb_MathFunction1_tmp;

  /* Saturate: '<S1>/Saturation1' */
  if (*((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0] > 1.0) {
    rtb_MathFunction = 1.0;
  } else if (*((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0] < -1.0) {
    rtb_MathFunction = -1.0;
  } else {
    rtb_MathFunction = *((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0];
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* Trigonometry: '<S1>/Trigonometric Function1' */
  rtb_Add4 = cos(*((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0]);

  /* Saturate: '<S1>/Saturation' */
  if (*((const real_T **)ssGetInputPortSignalPtrs(S, 1))[0] > 1.0) {
    rtb_MathFunction1 = 1.0;
  } else if (*((const real_T **)ssGetInputPortSignalPtrs(S, 1))[0] < -1.0) {
    rtb_MathFunction1 = -1.0;
  } else {
    rtb_MathFunction1 = *((const real_T **)ssGetInputPortSignalPtrs(S, 1))[0];
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Trigonometry: '<S1>/Trigonometric Function' */
  rtb_Add7 = sin(*((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0]);

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

  /* Selector: '<S1>/Selector1' incorporates:
   *  Abs: '<S1>/Abs'
   *  Abs: '<S1>/Abs1'
   *  Constant: '<S1>/Constant5'
   *  Constant: '<S1>/Constant7'
   *  Constant: '<S1>/sector'
   *  Gain: '<S1>/Gain1'
   *  Gain: '<S1>/Gain2'
   *  Gain: '<S1>/Gain3'
   *  RelationalOperator: '<S1>/Relational Operator2'
   *  RelationalOperator: '<S1>/Relational Operator3'
   *  RelationalOperator: '<S1>/Relational Operator4'
   *  Selector: '<S1>/Selector'
   *  Sum: '<S1>/Add3'
   */
  rtb_MathFunction1_tmp = SVPWM0_ConstP.sector_Value[(uint8_T)(((((uint32_T)
    ((rtb_Add6 > 0.0) << 7) << 1) + (uint32_T)((fabs(rtb_Add6) >
    1.7320508075688772 * fabs(rtb_Add7)) << 7)) + ((uint32_T)(rtb_Add7 > 0.0) <<
    6)) >> 6)];

  /* Gain: '<S1>/Gain4' incorporates:
   *  Constant: '<S1>/sector'
   *  Selector: '<S1>/Selector1'
   */
  rtb_MathFunction1 = 1.0471975511965976 * rtb_MathFunction1_tmp;

  /* Sum: '<S1>/Add4' incorporates:
   *  Product: '<S1>/Product4'
   *  Product: '<S1>/Product5'
   *  Trigonometry: '<S1>/Trigonometric Function2'
   *  Trigonometry: '<S1>/Trigonometric Function3'
   */
  rtb_Add4 = rtb_Add7 * sin(rtb_MathFunction1) - rtb_Add6 * cos
    (rtb_MathFunction1);

  /* Sum: '<S1>/Add6' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Product: '<S1>/Product6'
   *  Product: '<S1>/Product7'
   *  Sum: '<S1>/Add5'
   *  Trigonometry: '<S1>/Trigonometric Function4'
   *  Trigonometry: '<S1>/Trigonometric Function5'
   */
  rtb_Add6 = cos(rtb_MathFunction1 - 1.0471975511965976) * rtb_Add6 - sin
    (rtb_MathFunction1 - 1.0471975511965976) * rtb_Add7;

  /* Math: '<S1>/Math Function' incorporates:
   *  Constant: '<S1>/Constant10'
   *  Math: '<S1>/Math Function1'
   *  Math: '<S1>/Math Function2'
   */
  rtb_MathFunction = SVPWM0_rt_modd_snf(rtb_MathFunction1_tmp, 6.0);

  /* Gain: '<S1>/Gain5' incorporates:
   *  Constant: '<S1>/Constant6'
   *  Gain: '<S1>/Gain6'
   *  Gain: '<S1>/Gain7'
   *  Sum: '<S1>/Add7'
   */
  rtb_MathFunction1 = ((1.0 - rtb_Add4) - rtb_Add6) * 0.5;

  /* Outport: '<Root>/du' incorporates:
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S1>/Phase sequence'
   *  Gain: '<S1>/Gain5'
   *  Math: '<S1>/Math Function'
   *  Product: '<S1>/Product8'
   *  Product: '<S1>/Product9'
   *  Selector: '<S1>/Selector'
   *  Selector: '<S1>/Selector2'
   *  Sum: '<S1>/Add8'
   *  Sum: '<S1>/Add9'
   */
  ((real_T *)ssGetOutputPortSignal(S, 0))[0] =
    (SVPWM0_ConstP.Phasesequence_Value[(int32_T)(rtb_MathFunction1_tmp - 1.0)] *
     rtb_Add4 + SVPWM0_ConstP.Phasesequence_Value[(int32_T)rtb_MathFunction] *
     rtb_Add6) + rtb_MathFunction1;

  /* Outport: '<Root>/dv' incorporates:
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S1>/Phase sequence'
   *  Product: '<S1>/Product10'
   *  Product: '<S1>/Product11'
   *  Selector: '<S1>/Selector'
   *  Selector: '<S1>/Selector3'
   *  Selector: '<S1>/Selector4'
   *  Sum: '<S1>/Add11'
   *  Sum: '<S1>/Add8'
   */
  ((real_T *)ssGetOutputPortSignal(S, 1))[0] =
    (SVPWM0_ConstP.Phasesequence_Value[(int32_T)(rtb_MathFunction1_tmp - 1.0) +
     6] * rtb_Add4 + SVPWM0_ConstP.Phasesequence_Value[(int32_T)rtb_MathFunction
     + 6] * rtb_Add6) + rtb_MathFunction1;

  /* Outport: '<Root>/dw' incorporates:
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S1>/Phase sequence'
   *  Product: '<S1>/Product12'
   *  Product: '<S1>/Product13'
   *  Selector: '<S1>/Selector'
   *  Selector: '<S1>/Selector5'
   *  Selector: '<S1>/Selector6'
   *  Sum: '<S1>/Add13'
   *  Sum: '<S1>/Add8'
   */
  ((real_T *)ssGetOutputPortSignal(S, 2))[0] =
    (SVPWM0_ConstP.Phasesequence_Value[(int32_T)(rtb_MathFunction1_tmp - 1.0) +
     12] * rtb_Add4 + SVPWM0_ConstP.Phasesequence_Value[(int32_T)
     rtb_MathFunction + 12] * rtb_Add6) + rtb_MathFunction1;
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  UNUSED_PARAMETER(tid);
}

/* Termination for root system: '<Root>' */
static void mdlTerminate(SimStruct *S)
{
  UNUSED_PARAMETER(S);

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

  if (ssGetUserData(S) != (NULL) ) {
    rt_FREE(ssGetLocalBlockIO(S));
  }

  rt_FREE(ssGetUserData(S));

#endif

}

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#include "SVPWM0_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 1);           /* Number of sample times */
  ssSetNumContStates(S, 0);            /* Number of continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 3))
    return;

  /* outport number: 0 */
  if (!ssSetOutputPortMatrixDimensions(S, 0, 1, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 0, 0.001);
  ssSetOutputPortOffsetTime(S, 0, 0.0);
  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

  /* outport number: 1 */
  if (!ssSetOutputPortMatrixDimensions(S, 1, 1, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 1, 0.001);
  ssSetOutputPortOffsetTime(S, 1, 0.0);
  ssSetOutputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

  /* outport number: 2 */
  if (!ssSetOutputPortMatrixDimensions(S, 2, 1, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 2, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 2, 0.001);
  ssSetOutputPortOffsetTime(S, 2, 0.0);
  ssSetOutputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 3))
    return;

  /* inport number: 0 */
  {
    if (!ssSetInputPortVectorDimension(S, 0, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 0, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortSampleTime(S, 0, 0.001);
    ssSetInputPortOffsetTime(S, 0, 0.0);
    ssSetInputPortOverWritable(S, 0, 0);
    ssSetInputPortOptimOpts(S, 0, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 1 */
  {
    if (!ssSetInputPortVectorDimension(S, 1, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 1, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortSampleTime(S, 1, 0.001);
    ssSetInputPortOffsetTime(S, 1, 0.0);
    ssSetInputPortOverWritable(S, 1, 0);
    ssSetInputPortOptimOpts(S, 1, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 2 */
  {
    if (!ssSetInputPortVectorDimension(S, 2, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 2, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 2, 1);
    ssSetInputPortSampleTime(S, 2, 0.001);
    ssSetInputPortOffsetTime(S, 2, 0.0);
    ssSetInputPortOverWritable(S, 2, 0);
    ssSetInputPortOptimOpts(S, 2, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* DWork */
  if (!ssSetNumDWork(S, 1)) {
    return;
  }

  /* '<S1>/Add3': DWORK1 */
  ssSetDWorkName(S, 0, "DWORK0");
  ssSetDWorkWidth(S, 0, 1);
  ssSetDWorkDataType(S, 0, SS_UINT32);

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 0);

  /* Number of expected parameters */
#if defined(MATLAB_MEX_FILE)

  if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {

#if defined(MDL_CHECK_PARAMETERS)

    mdlCheckParameters(S);

#endif                                 /* MDL_CHECK_PARAMETERS */

    if (ssGetErrorStatus(S) != (NULL) ) {
      return;
    }
  } else {
    return;                /* Parameter mismatch will be reported by Simulink */
  }

#endif                                 /* MATLAB_MEX_FILE */

  /* Options */
  ssSetOptions(S, (SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE |
                   SS_OPTION_PORT_SAMPLE_TIMES_ASSIGNED ));

#if SS_SFCN_FOR_SIM

  {
    ssSupportsMultipleExecInstances(S, true);
    ssHasStateInsideForEachSS(S, false);
  }

#endif

}

/* Function to initialize sample times. */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  /* task periods */
  ssSetSampleTime(S, 0, 0.001);

  /* task offsets */
  ssSetOffsetTime(S, 0, 0.0);
}

#if defined(MATLAB_MEX_FILE)
#include "fixedpoint.c"
#include "simulink.c"
#else
#undef S_FUNCTION_NAME
#define S_FUNCTION_NAME                SVPWM0_sf
#include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
