/*
Problem:行逻辑链接的顺序表存储的稀疏矩阵
Author:QiZhao
Data:2017-12-12
Description:严蔚敏版数据结构课本源码
Copyright  2017 QiZhao. All rights reserved.
*/

#include"RowLinkSparseMatrix.h"
#include<stdio.h>

Status CreateSMatrix(RLSMatrix &M)
{
    // 创建稀疏矩阵M
    int i;
    int m, n;
    Triple T;
    printf("请输入矩阵的行数,列数,非零元素个数:\n");
    scanf("%d %d %d", &M.mu, &M.nu, &M.tu);
    printf("%d %d %d\n", M.mu, M.nu, M.tu);
    M.data[0].i=0;
    for(i = 1; i <= M.tu; i++)
    {
        printf("请输入第%d个非零元素所在的行(1～%d),列(1～%d),元素值:\n", i, M.mu, M.nu);
        scanf("%d %d %d", &T.i, &T.j, &T.e);
        printf("%d %d %d\n", T.i, T.j, T.e);
        M.data[i] = T;
    }
    for(i = 1; i <= M.tu; i++) // 计算rpos[]
        if(M.data[i].i > M.data[i - 1].i) //开始了新的一行
            for(T.i = 0; T.i < M.data[i].i - M.data[i - 1].i; T.i++)
                M.rpos[M.data[i].i - T.i] = i;
    for(i = M.data[M.tu].i + 1; i <= M.mu; i++) // 给最后没有非零元素的几行赋值
        M.rpos[i] = M.tu + 1;
    return OK;
}

Status DestroySMatrix(RLSMatrix &M)
{
    // 销毁稀疏矩阵M
    M.mu = 0;
    M.nu = 0;
    M.tu = 0;
    return OK;
}

void PrinRLSMatrix(RLSMatrix M)
{
    // 输出稀疏矩阵M
    int i;
    int k = 1;
    printf("-----------------------------\n");
    printf("行   列   元素值\n");
    for(i = 1; i <= M.tu; i++)
        printf("%2d%4d%8d\n", M.data[i].i, M.data[i].j, M.data[i].e);
//    for(i=1;i<=M.mu;i++)
//     printf("第%d行的第一个非零元素是本矩阵第%d个元素\n",i,M.rpos[i]);
    printf("-----------------------------\n");
}

Status CopySMatrix(RLSMatrix M, RLSMatrix &T)
{
    //由稀疏矩阵M复制得到T
    T.mu = M.mu;
    T.nu = M.nu;
    T.tu = M.tu;
    int k;
    for(k = 1; k <= M.tu; k++)
        T.data[k] = M.data[k];
    return OK;
}

Status AddSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix &Q)
{
    // 求稀疏矩阵的和Q=M+N

}

Status SubRLSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix &Q)
{
    // 求稀疏矩阵的差Q=M-N
}

Status MulRLSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix &Q)
{
    // 求稀疏矩阵的乘积Q=M*N
    int arow, brow, p, q, t, ctemp[30], l, ccol, tp;
    if (M.nu != N.mu) return ERROR;
    Q.mu = M.mu;
    Q.nu = N.nu;
    Q.tu = 0;       // Q初始化
    if (M.tu * N.tu != 0)   // Q是非零矩阵
    {
        for (arow = 1; arow <= M.mu; ++arow)    // 处理M的每一行
        {
            for (l = 1; l <= M.nu; ++l) ctemp[l] = 0; // 当前行各元素累加器清零
            Q.rpos[arow] = Q.tu + 1;
            if (arow < M.mu) tp = M.rpos[arow + 1];
            else tp = M.tu + 1;
            for (p = M.rpos[arow]; p < tp; ++p) // 对当前行中每一个非零元
            {
                brow = M.data[p].j;        // 找到对应元在N中的行号
                if (brow < N.mu ) t = N.rpos[brow + 1];
                else t = N.tu + 1;
                for (q = N.rpos[brow];  q < t;  ++q)
                {
                    ccol = N.data[q].j;            // 乘积元素在Q中列号
                    ctemp[ccol] += M.data[p].e * N.data[q].e;
                } // for q
            } // 求得Q中第crow( =arow)行的非零元
            for (ccol = 1; ccol <= Q.nu; ++ccol) // 压缩存储该行非零元
                if (ctemp[ccol])
                {
                    if (++Q.tu > MAXSIZE) return ERROR;
                    Q.data[Q.tu].i = arow;
                    Q.data[Q.tu].j = ccol;
                    Q.data[Q.tu].e = ctemp[ccol];
                } // if
        } // for arow
    } // if
    return OK;
}
