/*
 * @Author: 星必尘Sguan
 * @Date: 2026-01-21 19:54:51
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2026-01-22 12:04:08
 * @FilePath: \SguanSimulink库\Damping_Loop.c
 * @Description: 实现二阶自控原理典型环节
 * 
 * Copyright (c) 2026 by $JUST, All Rights Reserved. 
 */
#include "Damping_Loop.h"

DAMPING_STRUCT osc;

/* 二阶典型环节参数初始化，主函数调用 */
void Damping_Init(void){
    osc.zeta = 0.4; // 无数学单位
    osc.Wn = 10;    // 单位为"rad/s"
    osc.T = 0.001;  // 单位为"s秒"
    double temp0 = osc.T*osc.Wn*osc.zeta;
    double temp1 = osc.T*osc.Wn;
    double temp2 = osc.T*osc.T*osc.Wn*osc.Wn;
    osc.num[0] = (float)temp2;
    osc.num[1] = (float)(2*temp2);
    osc.num[2] = (float)temp2;
    osc.den[0] = (float)(temp2+4*temp0+4);
    osc.den[1] = (float)(-8+2*temp2);
    osc.den[2] = (float)(temp2-4*temp0+4);
    // 初始化为零
    for (int n = 0; n < 3; n++){
        osc.i[n] = 0;
        osc.o[n] = 0;
    }
}

/* 定时器1ms中断服务函数 */
void Damping_Loop(float input,float *output){
    // 更新历史输入和输出数值
    for (int n = 2; n > 0; n--){
        osc.i[n] = osc.i[n-1];
        osc.o[n] = osc.o[n-1];
    }
    // 更新当前输入
    osc.i[0] = input;
    float num = osc.num[0]*osc.i[0]+osc.num[1]*osc.i[1]+osc.num[2]*osc.i[2];
    float den = osc.den[1]*osc.o[1]+osc.den[2]*osc.o[2];
    osc.o[0] = (num - den)/osc.den[0];
    *output = osc.o[0];
}
