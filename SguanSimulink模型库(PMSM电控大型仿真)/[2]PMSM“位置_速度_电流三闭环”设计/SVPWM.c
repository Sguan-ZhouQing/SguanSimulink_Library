/*
 * @Author: 星必尘Sguan
 * @GitHub: https://github.com/Sguan-ZhouQing
 * @Date: 2026-02-04 23:48:38
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2026-02-05 00:19:39
 * @FilePath: \model_HFI\SVPWM.c
 * @Description: SVPWM模块的实现
 * 
 * Copyright (c) 2026 by $星必尘Sguan, All Rights Reserved. 
 */
#include "SVPWM.h"
#include <stdbool.h>

// 快速sine和cosine求解的局部函数
static double f1(double x) {
  double u = 1.3528548e-10f;
  u = u * x + -2.4703144e-08f;
  u = u * x + 2.7532926e-06f;
  u = u * x + -0.00019840381f;
  u = u * x + 0.0083333179f;
  return u * x + -0.16666666f;
}

// 快速sine和cosine求解的局部函数
static double f2(double x) {
  double u = 1.7290616e-09f;
  u = u * x + -2.7093486e-07f;
  u = u * x + 2.4771643e-05f;
  u = u * x + -0.0013887906f;
  u = u * x + 0.041666519f;
  return u * x + -0.49999991f;
}

// 快速求解sine和cosine
static void fast_sin_cos(double x, double *sin_x, double *cos_x) {
  int si = (int)(x * 0.31830988f);
  x = x - (double)si * Value_PI;
  if (si & 1) {
    x = x > 0.0f ? x - Value_PI : x + Value_PI;
  }
  *sin_x = x + x * x * x * f1(x * x);
  *cos_x = 1.0f + x * x * f2(x * x);
}

// 重写fabsf函数
static double Sguan_fabsf(double x) {
  return x < 0.0 ? -x : x;
}

// 电机SVPWM空间矢量调制函数
void SVPWM(double VBUS, double alpha, double beta, double *d_u, double *d_v, double *d_w) {
  const int v[6][3] = {{1, 0, 0}, {1, 1, 0}, {0, 1, 0}, {0, 1, 1}, {0, 0, 1}, {1, 0, 1}};
  const int K_to_sector[] = {4, 6, 5, 5, 3, 1, 2, 2};

  alpha = alpha/VBUS;
  beta = beta/VBUS;

  bool A = beta > 0;
  bool B = Sguan_fabsf(beta) > Value_SQRT3 * Sguan_fabsf(alpha);
  bool C = alpha > 0;
  int K = 4 * A + 2 * B + C;
  int sector = K_to_sector[K];

  double angle_data0 = sector * Value_rad60;
  double angle_data1 = angle_data0 - Value_rad60;
  double sin_m,cos_m,sin_n,cos_n;
  fast_sin_cos(angle_data0,&sin_m,&cos_m);
  fast_sin_cos(angle_data1,&sin_n,&cos_n);

  double t_m = sin_m * alpha - cos_m * beta;
  double t_n = beta * cos_n - alpha * sin_n;
  double t_0 = 1 - t_m - t_n;
  *d_u = t_m * v[sector - 1][0] + t_n * v[sector % 6][0] + t_0 / 2;
  *d_v = t_m * v[sector - 1][1] + t_n * v[sector % 6][1] + t_0 / 2;
  *d_w = t_m * v[sector - 1][2] + t_n * v[sector % 6][2] + t_0 / 2;
}


