/*
 * SVPWM0_sf.h
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

#ifndef SVPWM0_sf_h_
#define SVPWM0_sf_h_
#ifndef SVPWM0_sf_COMMON_INCLUDES_
#define SVPWM0_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                SVPWM0_sf
#define S_FUNCTION_LEVEL               2
#ifndef RTW_GENERATED_S_FUNCTION
#define RTW_GENERATED_S_FUNCTION
#endif

#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_nonfinite.h"
#include "math.h"
#if !defined(MATLAB_MEX_FILE)
#include "rt_matrx.h"
#endif

#if !defined(RTW_SFUNCTION_DEFINES)
#define RTW_SFUNCTION_DEFINES

typedef struct {
  void *blockIO;
  void *defaultParam;
  void *nonContDerivSig;
} LocalS;

#define ssSetLocalBlockIO(S, io)       ((LocalS *)ssGetUserData(S))->blockIO = ((void *)(io))
#define ssGetLocalBlockIO(S)           ((LocalS *)ssGetUserData(S))->blockIO
#define ssSetLocalDefaultParam(S, paramVector) ((LocalS *)ssGetUserData(S))->defaultParam = (paramVector)
#define ssGetLocalDefaultParam(S)      ((LocalS *)ssGetUserData(S))->defaultParam
#define ssSetLocalNonContDerivSig(S, pSig) ((LocalS *)ssGetUserData(S))->nonContDerivSig = (pSig)
#define ssGetLocalNonContDerivSig(S)   ((LocalS *)ssGetUserData(S))->nonContDerivSig
#endif
#endif                                 /* SVPWM0_sf_COMMON_INCLUDES_ */

#include "SVPWM0_sf_types.h"
#include "rtGetNaN.h"
#include <string.h>
#include <stddef.h>
#include "rt_defines.h"

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [1 0 0;1 1 0;0 1 0;0 1 1;0 0 1;1 0 1]
   * Referenced by: '<S1>/Phase sequence'
   */
  real_T Phasesequence_Value[18];

  /* Expression: [4 6 5 5 3 1 2 2]
   * Referenced by: '<S1>/sector'
   */
  real_T sector_Value[8];
} ConstP_SVPWM0_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T *phi;                         /* '<Root>/phi' */
  real_T *Ud;                          /* '<Root>/Ud' */
  real_T *Uq;                          /* '<Root>/Uq' */
} ExternalUPtrs_SVPWM0_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T *du;                          /* '<Root>/du' */
  real_T *dv;                          /* '<Root>/dv' */
  real_T *dw;                          /* '<Root>/dw' */
} ExtY_SVPWM0_T;

/* Constant parameters (default storage) */
extern const ConstP_SVPWM0_T SVPWM0_ConstP;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('SguanTest/SVPWM')    - opens subsystem SguanTest/SVPWM
 * hilite_system('SguanTest/SVPWM/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SguanTest'
 * '<S1>'   : 'SguanTest/SVPWM'
 */
#endif                                 /* SVPWM0_sf_h_ */
