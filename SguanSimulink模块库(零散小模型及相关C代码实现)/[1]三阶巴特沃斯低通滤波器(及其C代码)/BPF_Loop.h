#ifndef __BPF_LOOP_H
#define __BPF_LOOP_H

typedef struct{
    float i[4];     // (数据)历史输入值
    float o[4];     // (数据)历史输出值

    double Wc;       // (参数设计)Wc截止频率
    double T;        // (参数设计)T周期

    float num[4];   // (中间量)传递函数分子系数
    float den[4];   // (中间量)传递函数分母系数
}BPF_STRUCT;

void BPF_Init(void);
void BPF_Loop(float input,float *output);

#endif // BPF_LOOP_H
