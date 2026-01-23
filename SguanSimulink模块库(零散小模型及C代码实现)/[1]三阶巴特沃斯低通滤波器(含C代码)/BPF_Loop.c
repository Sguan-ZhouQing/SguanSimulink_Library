/*
 * @Author: 星必尘Sguan
 * @Date: 2026-01-21 19:54:51
 * @LastEditors: 星必尘Sguan|3464647102@qq.com
 * @LastEditTime: 2026-01-22 12:20:32
 * @FilePath: \SguanSimulink库\BPF_Loop.c
 * @Description: 实现三阶巴特沃斯低通滤波器
 * 
 * Copyright (c) 2026 by $JUST, All Rights Reserved. 
 */
#include "BPF_Loop.h"

BPF_STRUCT bpf;

/* 巴特沃斯参数初始化，主函数调用 */
void BPF_Init(void){
    bpf.Wc = 10;    // 单位为"rad/s"
    bpf.T = 0.001;  // 单位为"s秒"
    double temp1 = bpf.T*bpf.Wc;
    double temp2 = bpf.T*bpf.T*bpf.Wc*bpf.Wc;
    double temp3 = bpf.T*bpf.T*bpf.T*bpf.Wc*bpf.Wc*bpf.Wc;
    bpf.num[0] = (float)temp3;
    bpf.num[1] = (float)(3*temp3);
    bpf.num[2] = (float)(3*temp3);
    bpf.num[3] = (float)temp3;
    bpf.den[0] = (float)(8+8*temp1+4*temp2+temp3);
    bpf.den[1] = (float)(-24-8*temp1+4*temp2+3*temp3);
    bpf.den[2] = (float)(24-8*temp1-4*temp2+3*temp3);
    bpf.den[3] = (float)(-8+8*temp1-4*temp2+temp3);
    // 初始化为零
    for (int n = 0; n < 4; n++){
        bpf.i[n] = 0;
        bpf.o[n] = 0;
    }
}

/* 定时器1ms中断服务函数 */
void BPF_Loop(float input,float *output){
    // 更新历史输入和输出数值
    for (int n = 3; n > 0; n--){
        bpf.i[n] = bpf.i[n-1];
        bpf.o[n] = bpf.o[n-1];
    }
    // 更新当前输入
    bpf.i[0] = input;
    float num = bpf.num[0]*bpf.i[0]+bpf.num[1]*bpf.i[1]+bpf.num[2]*bpf.i[2]+bpf.num[3]*bpf.i[3];
    float den = bpf.den[1]*bpf.o[1]+bpf.den[2]*bpf.o[2]+bpf.den[3]*bpf.o[3];
    bpf.o[0] = (num - den)/bpf.den[0];
    *output = bpf.o[0];
}

