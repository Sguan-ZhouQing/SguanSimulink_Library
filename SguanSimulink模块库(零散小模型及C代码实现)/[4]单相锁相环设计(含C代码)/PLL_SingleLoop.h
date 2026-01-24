#ifndef __PLL_SINGLELOOP_H
#define __PLL_SINGLELOOP_H

typedef struct{
    float i[2];     // (数据)历史输入值
    float o[2];     // (数据)历史输出值

    float num[2];   // (中间量)传递函数分子系数
    float den[2];   // (中间量)传递函数分母系数
}MD_STRUCT;

typedef struct{
    MD_STRUCT PI;   // (传递函数)PI项
    MD_STRUCT BPF;  // (传递函数)一阶巴特沃斯低通滤波
    MD_STRUCT Integral; // (传递)积分项

    float Last_Rad; // (数据)上一时刻的输出角度

    double Wc;      // (参数设计)Wc微分环节一阶低通滤波
    double T;       // (参数设计)T周期
    double Kp;      // (参数设计)Kp比例项增益
    double Ki;      // (参数设计)Ki积分项增益
}PLL_SINGLE_STRUCT;

void PLL_SingleInit(void);
void PLL_SingleLoop(float input,float *OutWe,float *OutRad);

#endif // PLL_SINGLELOOP_H
