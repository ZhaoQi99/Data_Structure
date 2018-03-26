#ifndef TRIPLESPARSEMATRIX_H_INCLUDED
#define TRIPLESPARSEMATRIX_H_INCLUDED

#include"../../../template.h"

#define MAXSIZE 100 // 非零元个数的最大值
typedef int ElemType;

typedef struct
{
    int i, j; // 行下标,列下标
    ElemType e; // 非零元素值
} Triple;

typedef struct
{
    Triple data[MAXSIZE + 1]; // 非零元三元组表,data[0]未用
    int mu, nu, tu; // 矩阵的行数、列数和非零元个数
} TSMatrix;

Status CreateSMatrix(TSMatrix &M);
// 创建稀疏矩阵M

Status DestroySMatrix(TSMatrix &M);
// 销毁稀疏矩阵M

void PrintSMatrix(TSMatrix M);
// 输出稀疏矩阵M

Status CopySMatrix(TSMatrix M,TSMatrix &T);
//由稀疏矩阵M复制得到T

Status AddSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q);
// 求稀疏矩阵的和Q=M+N

Status SubtSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q);
// 求稀疏矩阵的差Q=M-N

Status MultSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q);
// 求稀疏矩阵的乘积Q=M*N

Status TransposeSMatrix(TSMatrix M, TSMatrix &T);
// 采用三元组顺序表存储表示，求稀疏矩阵M的转置矩阵T

Status  FastTransposeSMatrix(TSMatrix M, TSMatrix &T);
// 采用三元组顺序表存储表示，求稀疏矩阵M的转置矩阵T

#endif // TRIPLESPARSEMATRIX_H_INCLUDED
