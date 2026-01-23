/*
 * @Author: 星必尘Sguan
 * @Date: 2026-01-24 00:58:27
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2026-01-24 02:04:24
 * @FilePath: \SguanSimulink库\PID_Loop.c
 * @Description: PID开环控制系统的函数搭建(输入Error)
 * 
 * Copyright (c) 2026 by $JUST, All Rights Reserved. 
 */
#include "PID_Loop.h"

PID_STRUCT pid;

/* PID核心参数初始化，主函数调用 */
void PID_Init(void){
    pid.Wc = 10;    // 单位为“rad/s”
    pid.T = 0.001;  // 单位为“s秒”
    pid.Kp = 1.5;   // 无数学单位
    pid.Ki = 0.2;   // 无数学单位
    pid.Kd = 0.001; // 无数学单位
    double temp0 = pid.T*pid.Ki;
    double temp1 = pid.T*pid.Wc;
    double temp2 = pid.Kd*pid.Wc;
    pid.num[0] = (float)(4*pid.Kp+2*temp0+4*temp2+2*pid.Kp*temp1+temp0*temp1);
    pid.num[1] = (float)(-8*pid.Kp-8*temp2+2*temp0*temp1);
    pid.num[2] = (float)(4*pid.Kp-2*temp0+4*temp2-2*pid.Kp*temp1+temp0*temp1);
    pid.den[0] = (float)(4+2*temp1);
    pid.den[1] = (float)(-8);
    pid.den[2] = (float)(4-2*temp1);
    // 初始化为零
    for (int n = 0; n < 3; n++){
        pid.i[n] = 0;
        pid.o[n] = 0;
    }
}

/* 定时器1ms中断服务函数 */
void PID_Loop(float error,float *output){
    // 更新历史输入和输出数值
    for (int n = 2; n > 0; n--){
        pid.i[n] = pid.i[n-1];
        pid.o[n] = pid.o[n-1];
    }
    // 更新当前输入
    pid.i[0] = error;
    float num = pid.num[0]*pid.i[0]+pid.num[1]*pid.i[1]+pid.num[2]*pid.i[2];
    float den = pid.den[1]*pid.o[1]+pid.den[2]*pid.o[2];
    pid.o[0] = (num - den)/pid.den[0];
    *output = pid.o[0];
}
