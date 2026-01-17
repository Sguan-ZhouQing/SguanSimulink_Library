

        /*
    * rt_nonfinite.c
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




    
#include "rtwtypes.h"

#include "rt_nonfinite.h"

#include "math.h"


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

                real_T rtNaN = -(real_T)NAN;



                real_T rtInf = (real_T)INFINITY;



                real_T rtMinusInf = -(real_T)INFINITY;



                real32_T rtNaNF = -(real32_T)NAN;



                real32_T rtInfF = (real32_T)INFINITY;



                real32_T rtMinusInfF = -(real32_T)INFINITY;






        /* Test if value is infinite */
         boolean_T rtIsInf(real_T value) {
        return (boolean_T)isinf(value);
    }
    
    /* Test if single-precision value is infinite */
         boolean_T rtIsInfF(real32_T value) {
        return (boolean_T)isinf(value);
    }
    
    /* Test if value is not a number */
         boolean_T rtIsNaN(real_T value) {
        return (boolean_T)(isnan(value) != 0);
    }
    
    /* Test if single-precision value is not a number */
         boolean_T rtIsNaNF(real32_T value) {
        return (boolean_T)(isnan(value) != 0);
    }
    


    

    

    

    
