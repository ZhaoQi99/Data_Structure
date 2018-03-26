#ifndef ROWLINKSPARSEMATRIX_H_INCLUDED
#define ROWLINKSPARSEMATRIX_H_INCLUDED

#include"../../../template.h"

#define MAXSIZE 100 // 非零元个数的最大值
#define MAXRC 20//最大行列数

typedef int ElemType;

typedef struct
{
    int i, j; // 行下标,列下标
    ElemType e; // 非零元素值
} Triple;

struct RLSMatrix
{
    Triple data[MAXSIZE + 1]; // 非零元三元组表
    int rpos[MAXRC + 1]; // 各行第一个非零元素的位置表
    int mu, nu, tu; // 矩阵的行数、列数和非零元个数
};

Status CreateSMatrix(RLSMatrix &M);
// 创建稀疏矩阵M

Status DestroySMatrix(RLSMatrix &M);
// 销毁稀疏矩阵M

void PrinRLSMatrix(RLSMatrix M);
// 输出稀疏矩阵M

Status CopySMatrix(RLSMatrix M,RLSMatrix &T);
//由稀疏矩阵M复制得到T

Status AddSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix &Q);
// 求稀疏矩阵的和Q=M+N

Status SubRLSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix &Q);
// 求稀疏矩阵的差Q=M-N

Status MulRLSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix &Q);
// 求稀疏矩阵的乘积Q=M*N

#endif // ROWLINKSPARSEMATRIX_H_INCLUDED
