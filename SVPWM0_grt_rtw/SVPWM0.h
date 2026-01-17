/*
 * SVPWM0.h
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

#ifndef SVPWM0_h_
#define SVPWM0_h_
#ifndef SVPWM0_COMMON_INCLUDES_
#define SVPWM0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* SVPWM0_COMMON_INCLUDES_ */

#include "SVPWM0_types.h"
#include "rtGetNaN.h"
#include <float.h>
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T phi;                          /* '<Root>/phi' */
  real_T Ud;                           /* '<Root>/Ud' */
  real_T Uq;                           /* '<Root>/Uq' */
} ExtU_SVPWM0_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T du;                           /* '<Root>/du' */
  real_T dv;                           /* '<Root>/dv' */
  real_T dw;                           /* '<Root>/dw' */
} ExtY_SVPWM0_T;

/* Parameters (default storage) */
struct P_SVPWM0_T_ {
  real_T Phasesequence_Value[18];
                            /* Expression: [1 0 0;1 1 0;0 1 0;0 1 1;0 0 1;1 0 1]
                             * Referenced by: '<S1>/Phase sequence'
                             */
  real_T sector_Value[8];              /* Expression: [4 6 5 5 3 1 2 2]
                                        * Referenced by: '<S1>/sector'
                                        */
  real_T Constant7_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant7'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Gain1_Gain;                   /* Expression: sqrt(3)
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant4'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Gain4_Gain;                   /* Expression: pi/3
                                        * Referenced by: '<S1>/Gain4'
                                        */
  real_T Constant10_Value;             /* Expression: 6
                                        * Referenced by: '<S1>/Constant10'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: pi/3
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant6'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1/2
                                        * Referenced by: '<S1>/Gain5'
                                        */
  real_T Constant12_Value;             /* Expression: 1
                                        * Referenced by: '<S1>/Constant12'
                                        */
  real_T Constant11_Value;             /* Expression: 1
                                        * Referenced by: '<S1>/Constant11'
                                        */
  real_T Constant9_Value;              /* Expression: 6
                                        * Referenced by: '<S1>/Constant9'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant8'
                                        */
  real_T Gain6_Gain;                   /* Expression: 1/2
                                        * Referenced by: '<S1>/Gain6'
                                        */
  real_T Constant16_Value;             /* Expression: 1
                                        * Referenced by: '<S1>/Constant16'
                                        */
  real_T Constant15_Value;             /* Expression: 2
                                        * Referenced by: '<S1>/Constant15'
                                        */
  real_T Constant14_Value;             /* Expression: 6
                                        * Referenced by: '<S1>/Constant14'
                                        */
  real_T Constant13_Value;             /* Expression: 2
                                        * Referenced by: '<S1>/Constant13'
                                        */
  real_T Gain7_Gain;                   /* Expression: 1/2
                                        * Referenced by: '<S1>/Gain7'
                                        */
  uint8_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S1>/Gain2'
                                        */
  uint8_T Gain3_Gain;                  /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S1>/Gain3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_SVPWM0_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_SVPWM0_T SVPWM0_P;

/* External inputs (root inport signals with default storage) */
extern ExtU_SVPWM0_T SVPWM0_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_SVPWM0_T SVPWM0_Y;

/* Model entry point functions */
extern void SVPWM0_initialize(void);
extern void SVPWM0_step(void);
extern void SVPWM0_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SVPWM0_T *const SVPWM0_M;

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
#endif                                 /* SVPWM0_h_ */
