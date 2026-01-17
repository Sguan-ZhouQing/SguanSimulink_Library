/*
 * SVPWM0_data.c
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

/* Block parameters (default storage) */
P_SVPWM0_T SVPWM0_P = {
  /* Expression: [1 0 0;1 1 0;0 1 0;0 1 1;0 0 1;1 0 1]
   * Referenced by: '<S1>/Phase sequence'
   */
  { 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 1.0, 1.0 },

  /* Expression: [4 6 5 5 3 1 2 2]
   * Referenced by: '<S1>/sector'
   */
  { 4.0, 6.0, 5.0, 5.0, 3.0, 1.0, 2.0, 2.0 },

  /* Expression: 0
   * Referenced by: '<S1>/Constant7'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Saturation1'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Saturation1'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Saturation'
   */
  -1.0,

  /* Expression: sqrt(3)
   * Referenced by: '<S1>/Gain1'
   */
  1.7320508075688772,

  /* Expression: 0
   * Referenced by: '<S1>/Constant5'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant4'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant2'
   */
  0.0,

  /* Expression: pi/3
   * Referenced by: '<S1>/Gain4'
   */
  1.0471975511965976,

  /* Expression: 6
   * Referenced by: '<S1>/Constant10'
   */
  6.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant1'
   */
  0.0,

  /* Expression: pi/3
   * Referenced by: '<S1>/Constant3'
   */
  1.0471975511965976,

  /* Expression: 1
   * Referenced by: '<S1>/Constant6'
   */
  1.0,

  /* Expression: 1/2
   * Referenced by: '<S1>/Gain5'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<S1>/Constant12'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant11'
   */
  1.0,

  /* Expression: 6
   * Referenced by: '<S1>/Constant9'
   */
  6.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant8'
   */
  1.0,

  /* Expression: 1/2
   * Referenced by: '<S1>/Gain6'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<S1>/Constant16'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S1>/Constant15'
   */
  2.0,

  /* Expression: 6
   * Referenced by: '<S1>/Constant14'
   */
  6.0,

  /* Expression: 2
   * Referenced by: '<S1>/Constant13'
   */
  2.0,

  /* Expression: 1/2
   * Referenced by: '<S1>/Gain7'
   */
  0.5,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S1>/Gain2'
   */
  128U,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S1>/Gain3'
   */
  128U
};
