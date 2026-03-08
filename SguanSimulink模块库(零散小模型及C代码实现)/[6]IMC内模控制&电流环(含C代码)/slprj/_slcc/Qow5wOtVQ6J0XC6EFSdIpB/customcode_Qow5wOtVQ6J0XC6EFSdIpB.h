#ifndef __customcode_Qow5wOtVQ6J0XC6EFSdIpB_h__
#define __customcode_Qow5wOtVQ6J0XC6EFSdIpB_h__

/* Include files */
#include "mex.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "tmwtypes.h"


/* Helper definitions for DLL support */
#if defined _WIN32 
  #define DLL_EXPORT_CC __declspec(dllexport)
#else
  #if __GNUC__ >= 4
    #define DLL_EXPORT_CC __attribute__ ((visibility ("default")))
  #else
    #define DLL_EXPORT_CC
  #endif
#endif
/* Custom Code from Simulation Target dialog */
#include "Sguan_InternalModel.h"

/* Function Declarations */
#ifdef __cplusplus
extern "C" {
#endif
DLL_EXPORT_CC void customcode_Qow5wOtVQ6J0XC6EFSdIpB_initializer(void);

#define customcode_Qow5wOtVQ6J0XC6EFSdIpB_terminator()
#ifdef __cplusplus
}
#endif

#endif

