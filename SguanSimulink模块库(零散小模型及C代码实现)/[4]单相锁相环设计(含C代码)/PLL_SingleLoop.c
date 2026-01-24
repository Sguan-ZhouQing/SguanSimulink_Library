/*
 * @Author: 星必尘Sguan
 * @Date: 2026-01-24 17:13:04
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2026-01-25 00:10:37
 * @FilePath: \SguanSimulink库\PLL_SingleLoop.c
 * @Description: 实现PLL单相锁相环(输出We和Rad)
 * 
 * Copyright (c) 2026 by $JUST, All Rights Reserved. 
 */
#include "PLL_SingleLoop.h"

PLL_SINGLE_STRUCT alone;

/* 单相锁相环参数初始化，主函数调用 */
void PLL_SingleInit(void){
    alone.Wc = 1;      // 单位为“rad/s”
    alone.T = 0.001;   // 单位为“s秒”
    alone.Kp = 0.8;    // 无数学单位
    alone.Ki = 1.2;    // 无数学单位
    double temp0 = alone.T*alone.Ki;
    double temp1 = alone.T*alone.Wc;
    alone.PI.num[0] = (float)(2*alone.Kp+temp0);
    alone.PI.num[1] = (float)(-2*alone.Kp+temp0);
    alone.PI.den[0] = (float)2;
    alone.PI.den[1] = (float)(-2);
    alone.BPF.num[0] = (float)temp1;
    alone.BPF.num[1] = (float)temp1;
    alone.BPF.den[0] = (float)(2+temp1);
    alone.BPF.den[1] = (float)(-2+temp1);
    alone.Integral.num[0] = (float)alone.T;
    alone.Integral.num[1] = (float)alone.T;
    alone.Integral.den[0] = (float)2;
    alone.Integral.den[1] = (float)(-2);
    // 初始化为零
    for (int n = 0; n < 2; n++){
        alone.PI.i[n] = 0;
        alone.PI.o[n] = 0;
        alone.BPF.i[n] = 0;
        alone.BPF.o[n] = 0;
        alone.Integral.i[n] = 0;
        alone.Integral.o[n] = 0;
        alone.Last_Rad = 0;
    }
}

/* 定时器1ms中断服务函数 */
void PLL_SingleLoop(float input,float *OutWe,float *OutRad){
    // 更新历史输入和输出数值
    alone.PI.i[1] = alone.PI.i[0];
    alone.PI.o[1] = alone.PI.o[0];
    alone.BPF.i[1] = alone.BPF.i[0];
    alone.BPF.o[1] = alone.BPF.o[0];
    alone.Integral.i[1] = alone.Integral.i[0];
    alone.Integral.o[1] = alone.Integral.o[0];
    alone.Last_Rad = alone.Integral.o[0];
    // 更新PI项当前输入值
    alone.PI.i[0] = input - alone.Last_Rad;
    float num_PI = alone.PI.num[0]*alone.PI.i[0]+alone.PI.num[1]*alone.PI.i[1];
    float den_PI = alone.PI.den[1]*alone.PI.o[1];
    alone.PI.o[0] = (num_PI - den_PI)/alone.PI.den[0];
    // 刷新数据输入
    alone.BPF.i[0] = alone.PI.o[0];
    alone.Integral.i[0] = alone.PI.o[0];
    // 输出预测角速度
    float num_BPF = alone.BPF.num[0]*alone.BPF.i[0]+alone.BPF.num[1]*alone.BPF.i[1];
    float den_BPF = alone.BPF.den[1]*alone.BPF.o[1];
    alone.BPF.o[0] = (num_BPF - den_BPF)/alone.BPF.den[0];
    *OutWe = alone.BPF.o[0];
    // 输出预测角度值
    float num_Integral = alone.Integral.num[0]*alone.Integral.i[0]+alone.Integral.num[1]*alone.Integral.i[1];
    float den_Integral = alone.Integral.den[1]*alone.Integral.o[1];
    alone.Integral.o[0] = (num_Integral - den_Integral)/alone.Integral.den[0];
    *OutRad = alone.Integral.o[0];
}
