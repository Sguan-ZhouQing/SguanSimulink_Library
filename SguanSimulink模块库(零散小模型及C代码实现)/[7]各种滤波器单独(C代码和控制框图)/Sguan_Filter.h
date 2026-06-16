#ifndef __SGUAN_FILTER_H
#define __SGUAN_FILTER_H

// /* SguanFOC配置文件声明 */
// #include "Sguan_Config.h"

#define Value_INV_SQRT3     0.5773502691896257f     // 根号三分之壹
#define Value_2_SQRT2       2.8284271247461903f

// =========================== LPF低通滤波器 ========================
typedef struct{
    float i[2];             // (数据)历史输入值
    float o[2];             // (数据)历史输出值

    float Input;            // (数据)Input输入
    float Output;           // (数据)Output输出

    float num[2];           // (中间量)传递函数分子系数
    float den[2];           // (中间量)传递函数分母系数
}LPF_GO_STRUCT;

typedef struct{
    LPF_GO_STRUCT filter;   // (结构体)滤波器运算数据

    float T;                // (系统时钟)T离散周期
    float Wc;               // (参数设计)Wc截止频率
}LPF_STRUCT;

void LPF_Init(LPF_STRUCT *lpf);
void LPF_Loop(LPF_STRUCT *lpf);


// =========================== BSF陷波滤波器 ========================
typedef struct{
    float i[2];             // (数据)历史输入值
    float o[2];             // (数据)历史输出值

    float Input;            // (数据)Input输入
    float Output;           // (数据)Output输出

    float Gain0;
    float Gain1;
}BSF_GO_STRUCT;

typedef struct{
    BSF_GO_STRUCT filter;   // (结构体)滤波器运算数据

    float T;                // (系统时钟)T离散周期

    float Wo;               // (参数设计)Wo陷波频率
    float zeta;             // (参数设计)zeta阻尼比
}BSF_STRUCT;

void BSF_Init(BSF_STRUCT *bsf);
void BSF_Loop(BSF_STRUCT *bsf);


// =========================== BPF带通滤波器 ========================
typedef struct{
    float i[2];             // (数据)历史输入值
    float o[2];             // (数据)历史输出值

    float Input;            // (数据)Input输入
    float Output;           // (数据)Output输出

    float num;           // (中间量)传递函数分子系数
    float den[2];           // (中间量)传递函数分母系数
}BPF_GO_STRUCT;

typedef struct{
    BPF_GO_STRUCT filter;   // (结构体)滤波器运算数据

    float T;                // (系统时钟)T离散周期

    float Wo;               // (参数设计)Wo带通频率
    float zeta;             // (参数设计)zeta阻尼比
}BPF_STRUCT;

void BPF_Init(BPF_STRUCT *bpf);
void BPF_Loop(BPF_STRUCT *bpf);

// ======================== TPNF三参数陷波滤波器 =======================
typedef struct{
    float i[2];             // (数据)历史输入值
    float o[2];             // (数据)历史输出值

    float Input;            // (输入数据)Input输入
    float Output;           // (输出数据)Output输出

    float Gain0;            // (中间量)增益系数
    float Gain1;            // (中间量)增益系数
    float Gain2;            // (中间量)增益系数
}TPNF_GO_STRUCT;

typedef struct{
    TPNF_GO_STRUCT filter;  // (结构体)滤波器运算数据

    float T;                // (系统时钟)T离散周期

    float Wo;               // (参数设计)Wo陷波频率
    float K1;               // (参数设计)K1分母阻尼比
    float K2;               // (参数设计)K2分子阻尼比
}TPNF_STRUCT;

void TPNF_Init(TPNF_STRUCT *tpnf);
void TPNF_Loop(TPNF_STRUCT *tpnf);

void Filter_Init(void);
void Filter_Loop(float LPF_in,float BSF_in,float BPF_in,float TPNF_in,float *LPF_out,float *BSF_out,float *BPF_out,float *TPNF_out,float *out_K1,float *out_K2);


#endif // SGUAN_FILTER_H
