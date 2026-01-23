#ifndef __PID_LOOP_H
#define __PID_LOOP_H

typedef struct{
    float i[3];     // (数据)历史输入值
    float o[3];     // (数据)历史输出值

    double Wc;      // (参数设计)Wc微分环节一阶低通滤波
    double T;       // (参数设计)T周期

    double Kp;      // (参数设计)Kp比例项增益
    double Ki;      // (参数设计)Ki积分项增益
    double Kd;      // (参数设计)Kd微分项增益

    float num[3];   // (中间量)传递函数分子系数
    float den[3];   // (中间量)传递函数分母系数
}PID_STRUCT;

void PID_Init(void);
void PID_Loop(float error,float *output);

#endif // PID_LOOP_H
