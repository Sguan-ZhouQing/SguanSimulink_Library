/*
 * SVPWM0_mid.h
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
 *
 * SOURCES: SVPWM0_sf.c
 */

#if defined(MATLAB_MEX_FILE) || defined(RT_MALLOC)

static int_T RegNumInputPorts(SimStruct *S, int_T nInputPorts)
{
  _ssSetNumInputPorts(S,nInputPorts);
  return true;
}

static int_T RegNumOutputPorts(SimStruct *S, int_T nOutputPorts)
{
  _ssSetNumOutputPorts(S,nOutputPorts);
  return true;
}

static int_T FcnSetErrorStatus(const SimStruct *S, DTypeId arg2)
{
  static char_T msg[256];
  if (strlen(ssGetModelName(S)) < 128) {
    snprintf(msg, sizeof(msg),
             "S-function %s does not have a tlc file. It cannot use macros that access regDataType field in simstruct.",
             ssGetModelName(S));
  } else {
    snprintf(msg, sizeof(msg),
             "A S-function does not have a tlc file. It cannot use macros that access regDataType field in simstruct.");
  }

  ssSetErrorStatus(S, msg);
  UNUSED_PARAMETER(arg2);
  return 0;
}

static void * FcnSetErrorStatusWithReturnPtr(const SimStruct *S, DTypeId arg2)
{
  FcnSetErrorStatus(S,0);
  UNUSED_PARAMETER(arg2);
  return 0;
}

static int_T FcnSetErrorStatusWithArgPtr(const SimStruct *S, const void* arg2)
{
  FcnSetErrorStatus(S,0);
  UNUSED_PARAMETER(arg2);
  return 0;
}

#endif

/* Instance data for model: SVPWM0 */
void *SVPWM0_malloc(SimStruct *rts)
{
  /* Local SimStruct for the generated S-Function */
  LocalS *lS = (LocalS *) malloc(sizeof(LocalS));
  ss_VALIDATE_MEMORY(rts,lS);
  (void) memset((char_T *) lS, 0,
                sizeof(LocalS));
  ssSetUserData(rts, lS);

  /* model checksums */
  ssSetChecksumVal(rts, 0, 3484960771U);
  ssSetChecksumVal(rts, 1, 3029146152U);
  ssSetChecksumVal(rts, 2, 1319260285U);
  ssSetChecksumVal(rts, 3, 3835224955U);
  return (NULL);
}
