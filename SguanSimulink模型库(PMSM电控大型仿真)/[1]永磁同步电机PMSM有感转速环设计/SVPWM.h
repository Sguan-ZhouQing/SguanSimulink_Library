#ifndef __SVPWM_H
#define __SVPWM_H

// 内部宏定义声明
#define Value_PI 3.14159265358979323846f
#define Value_rad60 1.047197551196598f
#define Value_SQRT3 1.73205080756887729353f

void SVPWM(double VBUS, double alpha, double beta, double *d_u, double *d_v, double *d_w);

#endif // SVPWM_H
