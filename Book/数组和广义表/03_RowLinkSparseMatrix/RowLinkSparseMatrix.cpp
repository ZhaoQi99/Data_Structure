/*
Problem:���߼����ӵ�˳���洢��ϡ�����
Author:QiZhao
Data:2017-12-12
Description:��ε�������ݽṹ�α�Դ��
Copyright  2017 QiZhao. All rights reserved.
*/

#include"RowLinkSparseMatrix.h"
#include<stdio.h>

Status CreateSMatrix(RLSMatrix &M)
{
    // ����ϡ�����M
    int i;
    int m, n;
    Triple T;
    printf("��������������,����,����Ԫ�ظ���:\n");
    scanf("%d %d %d", &M.mu, &M.nu, &M.tu);
    printf("%d %d %d\n", M.mu, M.nu, M.tu);
    M.data[0].i=0;
    for(i = 1; i <= M.tu; i++)
    {
        printf("�������%d������Ԫ�����ڵ���(1��%d),��(1��%d),Ԫ��ֵ:\n", i, M.mu, M.nu);
        scanf("%d %d %d", &T.i, &T.j, &T.e);
        printf("%d %d %d\n", T.i, T.j, T.e);
        M.data[i] = T;
    }
    for(i = 1; i <= M.tu; i++) // ����rpos[]
        if(M.data[i].i > M.data[i - 1].i) //��ʼ���µ�һ��
            for(T.i = 0; T.i < M.data[i].i - M.data[i - 1].i; T.i++)
                M.rpos[M.data[i].i - T.i] = i;
    for(i = M.data[M.tu].i + 1; i <= M.mu; i++) // �����û�з���Ԫ�صļ��и�ֵ
        M.rpos[i] = M.tu + 1;
    return OK;
}

Status DestroySMatrix(RLSMatrix &M)
{
    // ����ϡ�����M
    M.mu = 0;
    M.nu = 0;
    M.tu = 0;
    return OK;
}

void PrinRLSMatrix(RLSMatrix M)
{
    // ���ϡ�����M
    int i;
    int k = 1;
    printf("-----------------------------\n");
    printf("��   ��   Ԫ��ֵ\n");
    for(i = 1; i <= M.tu; i++)
        printf("%2d%4d%8d\n", M.data[i].i, M.data[i].j, M.data[i].e);
//    for(i=1;i<=M.mu;i++)
//     printf("��%d�еĵ�һ������Ԫ���Ǳ������%d��Ԫ��\n",i,M.rpos[i]);
    printf("-----------------------------\n");
}

Status CopySMatrix(RLSMatrix M, RLSMatrix &T)
{
    //��ϡ�����M���Ƶõ�T
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
    // ��ϡ�����ĺ�Q=M+N

}

Status SubRLSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix &Q)
{
    // ��ϡ�����Ĳ�Q=M-N
}

Status MulRLSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix &Q)
{
    // ��ϡ�����ĳ˻�Q=M*N
    int arow, brow, p, q, t, ctemp[30], l, ccol, tp;
    if (M.nu != N.mu) return ERROR;
    Q.mu = M.mu;
    Q.nu = N.nu;
    Q.tu = 0;       // Q��ʼ��
    if (M.tu * N.tu != 0)   // Q�Ƿ������
    {
        for (arow = 1; arow <= M.mu; ++arow)    // ����M��ÿһ��
        {
            for (l = 1; l <= M.nu; ++l) ctemp[l] = 0; // ��ǰ�и�Ԫ���ۼ�������
            Q.rpos[arow] = Q.tu + 1;
            if (arow < M.mu) tp = M.rpos[arow + 1];
            else tp = M.tu + 1;
            for (p = M.rpos[arow]; p < tp; ++p) // �Ե�ǰ����ÿһ������Ԫ
            {
                brow = M.data[p].j;        // �ҵ���ӦԪ��N�е��к�
                if (brow < N.mu ) t = N.rpos[brow + 1];
                else t = N.tu + 1;
                for (q = N.rpos[brow];  q < t;  ++q)
                {
                    ccol = N.data[q].j;            // �˻�Ԫ����Q���к�
                    ctemp[ccol] += M.data[p].e * N.data[q].e;
                } // for q
            } // ���Q�е�crow( =arow)�еķ���Ԫ
            for (ccol = 1; ccol <= Q.nu; ++ccol) // ѹ���洢���з���Ԫ
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
