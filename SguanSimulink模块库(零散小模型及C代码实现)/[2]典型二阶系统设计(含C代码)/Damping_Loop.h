#ifndef __DAMPING_LOOP_H
#define __DAMPING_LOOP_H

typedef struct{
    float i[3];     // (数据)历史输入值
    float o[3];     // (数据)历史输出值

    double zeta;    // (参数设计)zeta阻尼比
    double Wn;      // (参数设计)Wn无阻尼自然频率
    double T;       // (参数设计)T周期

    float num[4];   // (中间量)传递函数分子系数
    float den[4];   // (中间量)传递函数分母系数
}DAMPING_STRUCT;

void Damping_Init(void);
void Damping_Loop(float input,float *output);

#endif // DAMPING_LOOP_H
