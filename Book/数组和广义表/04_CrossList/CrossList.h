#ifndef CROSSLIST_H_INCLUDED
#define CROSSLIST_H_INCLUDED

#include"../../../template.h"
#include<stdlib.h>
typedef int ElemType;

struct OLNode
{
    int i, j; // 该非零元的行和列下标
    ElemType e; // 非零元素值
    OLNode *right, *down; // 该非零元所在行表和列表的后继链域
};

typedef OLNode *OLink;

struct CrossList
{
    OLink *rhead, *chead; // 行和列链表头指针向量基址,由CreatSMatrix_OL()分配
    int mu, nu, tu; // 稀疏矩阵的行数、列数和非零元个数
};

Status CreateSMatrix(CrossList &M);
// 创建稀疏矩阵M

Status DestroySMatrix(CrossList &M);
// 销毁稀疏矩阵M

void PrinCrossList(CrossList M);
// 输出稀疏矩阵M

Status CopySMatrix(CrossList M,CrossList &T);
//由稀疏矩阵M复制得到T

Status AddSMatrix(CrossList M,CrossList N,CrossList &Q);
// 求稀疏矩阵的和Q=M+N

Status SubCrossList(CrossList M,CrossList N,CrossList &Q);
// 求稀疏矩阵的差Q=M-N

Status MulCrossList(CrossList M,CrossList N,CrossList &Q);
// 求稀疏矩阵的乘积Q=M*N

#endif // CROSSLIST_H_INCLUDED
