/*
Problem:三元组顺序表存储的稀疏矩阵
Author:QiZhao
Data:2017-12-12
Description:严蔚敏版数据结构课本源码
Copyright  2017 QiZhao. All rights reserved.
*/
#include"TripleSparseMatrix.h"
#include<stdio.h>

Status CreateSMatrix(TSMatrix &M)
{
    // 创建稀疏矩阵M
    int k;
    int m,n;
    ElemType e;
    printf("请输入矩阵的行数,列数,非零元素个数:\n");
    scanf("%d %d %d", &M.mu, &M.nu, &M.tu);
    printf("%d %d %d\n",M.mu,M.nu,M.tu);
    for(k=1;k<=M.tu;k++)
    {
        printf("请输入第%d个非零元素所在的行(1～%d),列(1～%d),元素值:\n", k, M.mu,M.nu);
        scanf("%d %d %d", &m, &n, &e);
        printf("%d %d %d\n",m,n,e);
        M.data[k].i=m;
        M.data[k].j=n;
        M.data[k].e=e;
    }
    return OK;
}

Status DestroySMatrix(TSMatrix &M)
{
    // 销毁稀疏矩阵M
    M.mu=0;
    M.nu=0;
    M.tu=0;
    return OK;
}

void PrintSMatrix(TSMatrix M)
{
    // 输出稀疏矩阵M
    int r,c;
    int k=1;
    printf("-----------------------------\n");
    for(r=1;r<=M.mu;r++)
    {
        for(c=1;c<=M.nu;c++)
        {
            if(M.data[k].i==r&&M.data[k].j==c)
            {
                printf("%2d",M.data[k].e);
                k++;
            }
            else
                printf(" 0 ");
        }
        printf("\n");
    }
    printf("-----------------------------\n");
}

Status CopySMatrix(TSMatrix M, TSMatrix &T)
{
    //由稀疏矩阵M复制得到T
    T.mu=M.mu;
    T.nu=M.nu;
    T.tu=M.tu;
    int k;
    for(k=1;k<=M.tu;k++)
        T.data[k]=M.data[k];
    return OK;
}

Status AddSMatrix(TSMatrix M, TSMatrix N, TSMatrix &Q)
{
    // 求稀疏矩阵的和Q=M+N

}

Status SubtSMatrix(TSMatrix M, TSMatrix N, TSMatrix &Q)
{
    // 求稀疏矩阵的差Q=M-N
}

Status MultSMatrix(TSMatrix M, TSMatrix N, TSMatrix &Q)
{
    // 求稀疏矩阵的乘积Q=M*N
}

Status TransposeSMatrix(TSMatrix M, TSMatrix &T)
{
    // 采用三元组顺序表存储表示，求稀疏矩阵M的转置矩阵T
    int p, q, col;
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    if (T.tu)
    {
        q = 1;
        for (col = 1; col <= M.nu; ++col)
            for (p = 1; p <= M.tu; ++p)
                if (M.data[p].j == col)
                {
                    T.data[q].i = M.data[p].j;
                    T.data[q].j = M.data[p].i;
                    T.data[q].e = M.data[p].e;
                    ++q;
                }
    }
    return OK;
}

Status  FastTransposeSMatrix(TSMatrix M, TSMatrix &T)
{
    // 采用三元组顺序表存储表示，求稀疏矩阵M的转置矩阵T
    int col, t, p, q;
    int num[20], cpot[20];
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    if (T.tu)
    {
        for (col = 1; col <= M.nu; ++col) num[col] = 0;
        for (t = 1; t <= M.tu; ++t) // 求 M 中每一列所含非零元的个数
            ++num[M.data[t].j];
        cpot[1] = 1;
        // 求 M 中每一列的第一个非零元在 b.data 中的序号
        for (col = 2; col <= M.nu; ++col) cpot[col] = cpot[col - 1] + num[col - 1];
        for (p = 1; p <= M.tu; ++p)
        {
            col = M.data[p].j;
            q = cpot[col];
            T.data[q].i = M.data[p].j;
            T.data[q].j = M.data[p].i;
            T.data[q].e = M.data[p].e;
            ++cpot[col];
        } // for
    } // if
    return OK;
}
