/*
 * SVPWM0_sf_data.c
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
#include "SVPWM0_sf_private.h"

/* Constant parameters (default storage) */
const ConstP_SVPWM0_T SVPWM0_ConstP = {
  /* Expression: [1 0 0;1 1 0;0 1 0;0 1 1;0 0 1;1 0 1]
   * Referenced by: '<S1>/Phase sequence'
   */
  { 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 1.0, 1.0 },

  /* Expression: [4 6 5 5 3 1 2 2]
   * Referenced by: '<S1>/sector'
   */
  { 4.0, 6.0, 5.0, 5.0, 3.0, 1.0, 2.0, 2.0 }
};
