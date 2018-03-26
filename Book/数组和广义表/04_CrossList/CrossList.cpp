/*
Problem:ʮ������洢��ϡ�����
Author:QiZhao
Data:2017-12-13
Description:��ε�������ݽṹ�α�Դ��
Copyright  2017 QiZhao. All rights reserved.
*/
#include"CrossList.h"
#include<stdio.h>
#include<conio.h>

Status CreateSMatrix(CrossList &M)
{
    // ����ϡ�����M
// if (M) free(M);
    OLNode *p, *q;
    int i, j, e;
    int m, n, t;
    printf("��������������,����,����Ԫ�ظ���:\n");
    scanf("%d %d %d", &m, &n, &t );   // ����M�������������ͷ���Ԫ����
//    printf("%d %d %d\n",m,n,t);
    M.mu = m;
    M.nu = n;
    M.tu = t;
    if (!(M.rhead = (OLink *)malloc((m + 1) * sizeof(OLink)))) return ERROR;
    if (!(M.chead = (OLink *)malloc((n + 1) * sizeof(OLink)))) return ERROR;
    for(int a = 1; a <= m; a++) // ��ʼ������ͷָ������������������Ϊ������
        M.rhead[a] = NULL;
    for(int b = 1; b <= n; b++) M.chead[b] = NULL;
    for ( int c = 1; c <= t; c++) // ����������������Ԫ
    {
        printf("�������%d������Ԫ�����ڵ���(1��%d),��(1��%d),Ԫ��ֵ:\n", c, M.mu, M.nu);
        scanf("%d %d %d", &i, &j, &e);
//        printf("%d %d %d\n",i,j,e);
        if (!(p = (OLNode *)malloc(sizeof(OLNode)))) return ERROR;
        p->i = i;
        p->j = j;
        p->e = e;
        p->down = NULL;
        p->right = NULL; // �½��
        if (M.rhead[i] == NULL || M.rhead[i]->j > j)
        {
            p->right = M.rhead[i];
            M.rhead[i] = p;
        }
        else      // Ѱ�����б��еĲ���λ��
        {
            for (q = M.rhead[i]; (q->right) && (q->right->j < j);  q = q->right);
            p->right = q->right;
            q ->right = p;
        }  // ����в���
        if (M.chead[j] == NULL || M.chead[j]->i > i)
        {
            p->down = M.chead[j];
            M.chead[j] = p;
        }
        else      // Ѱ�����б��еĲ���λ��
        {
            for ( q = M.chead[j]; (q->down) && q->down->i < i;  q = q->down );
            p->down = q->down;
            q->down = p;
        }  // ����в���
    } // for
    printf("-----------------------------------\n");
    return OK;

}

Status DestroySMatrix(CrossList &M)
{
    // ����ϡ�����M
    int i;
    OLNode *p, *q;
    for(i = 1; i <= M.mu; i++) // �����ͷŽ��
    {
        p = *(M.rhead + i);
        while(p)
        {
            q = p;
            p = p->right;
            free(q);
        }
    }
    free(M.rhead);
    free(M.chead);
    M.rhead = M.chead = NULL;
    M.mu = M.nu = M.tu = 0;
    return OK;
}

void PrintSMatrix(CrossList M)
{
    // ���ϡ�����M
    int  j;
    char i;
    OLink p;
    printf("%d��%d��%d������Ԫ��\n", M.mu, M.nu, M.tu);
    printf("������ѡ��(1.������� 2.�������): ");
    i=getch();
    while(i!='1'&&i!='2')
    {
        printf("�����������������룡\n");
        i=getch();
    }
    printf("\n-----------------------------\n");
    printf("��  ��   Ԫ��ֵ\n");
    for(j = 1; j <= M.mu; j++)
    {
        p = M.rhead[j];
        while(p)
        {
            printf("%2d%4d%6d\n", p->i, p->j, p->e);
            if(i=='1')
                p=p->right;
            else
                p=p->down;
        }
    }
    printf("-----------------------------\n");
}

Status CopySMatrix(CrossList M, CrossList &T)
{
    //��ϡ�����M���Ƶõ�T

}

Status AddSMatrix(CrossList M, CrossList N, CrossList &Q)
{
    // ��ϡ�����ĺ�Q=M+N
    int i, k;
    OLink p, pq, pm, pn;
    OLink *col;
    if(M.mu != N.mu || M.nu != N.nu)
    {
        printf("����������ͬ���͵�,�������\n");
        exit(OVERFLOW);
    }
    Q.mu = M.mu; // ��ʼ��Q����
    Q.nu = M.nu;
    Q.tu = 0; // Ԫ�ظ����ĳ�ֵ
    Q.rhead = (OLink*)malloc((Q.mu + 1) * sizeof(OLink));
    if(!Q.rhead)
        exit(OVERFLOW);
    Q.chead = (OLink*)malloc((Q.nu + 1) * sizeof(OLink));
    if(!Q.chead)
        exit(OVERFLOW);
    for(k = 1; k <= Q.mu; k++) // ��ʼ��Q����ͷָ������;��������Ϊ������
        Q.rhead[k] = NULL;
    for(k = 1; k <= Q.nu; k++) // ��ʼ��Q����ͷָ������;��������Ϊ������
        Q.chead[k] = NULL;
    col = (OLink*)malloc((Q.nu + 1) * sizeof(OLink)); // ����ָ���е�����������
    if(!col)
        exit(OVERFLOW);
    for(k = 1; k <= Q.nu; k++) // ����ֵ
        col[k] = NULL;
    for(i = 1; i <= M.mu; i++) // ���е�˳�����
    {
        pm = M.rhead[i]; // pmָ�����M�ĵ�i�еĵ�1�����
        pn = N.rhead[i]; // pnָ�����N�ĵ�i�еĵ�1�����
        while(pm && pn) // pm��pn������
        {
            if(pm->j < pn->j) // ����M��ǰ������С�ھ���N��ǰ������
            {
                p = (OLink)malloc(sizeof(OLNode)); // ���ɾ���Q�Ľ��
                if(!p)
                    exit(OVERFLOW);
                Q.tu++; // ����Ԫ������1
                p->i = i; // ����㸳ֵ
                p->j = pm->j;
                p->e = pm->e;
                p->right = NULL;
                pm = pm->right; // pmָ��������
            }
            else if(pm->j > pn->j) // ����M��ǰ�����д��ھ���N��ǰ������
            {
                p = (OLink)malloc(sizeof(OLNode)); // ���ɾ���Q�Ľ��
                if(!p)
                    exit(OVERFLOW);
                Q.tu++; // ����Ԫ������1
                p->i = i; // ����㸳ֵ
                p->j = pn->j;
                p->e = pn->e;
                p->right = NULL;
                pn = pn->right; // pnָ��������
            }
            else if(pm->e + pn->e) // ����M��N��ǰ�������������Ԫ��֮�Ͳ�Ϊ0
            {
                p = (OLink)malloc(sizeof(OLNode)); // ���ɾ���Q�Ľ��
                if(!p)
                    exit(OVERFLOW);
                Q.tu++; // ����Ԫ������1
                p->i = i; // ����㸳ֵ
                p->j = pn->j;
                p->e = pm->e + pn->e;
                p->right = NULL;
                pm = pm->right; // pmָ��������
                pn = pn->right; // pnָ��������
            }
            else // ����M��N��ǰ�������������Ԫ��֮��Ϊ0
            {
                pm = pm->right; // pmָ��������
                pn = pn->right; // pnָ��������
                continue;
            }
            if(Q.rhead[i] == NULL) // pΪ���еĵ�1�����
                Q.rhead[i] = pq = p; // p���ڸ��еı�ͷ��pqָ��p(���е����һ�����)
            else // ����pq��ָ���֮��
            {
                pq->right = p; // ����в���
                pq = pq->right; // pqָ����е����һ�����
            }
            if(Q.chead[p->j] == NULL) // pΪ���еĵ�1�����
                Q.chead[p->j] = col[p->j] = p; // p���ڸ��еı�ͷ��col[p->j]ָ��p
            else // ����col[p->]��ָ���֮��
            {
                col[p->j]->down = p; // ����в���
                col[p->j] = col[p->j]->down; // col[p->j]ָ����е����һ�����
            }
        }
        while(pm) // ������M���е�ʣ��Ԫ�ز������Q
        {
            p = (OLink)malloc(sizeof(OLNode)); // ���ɾ���Q�Ľ��
            if(!p)
                exit(OVERFLOW);
            Q.tu++; // ����Ԫ������1
            p->i = i; // ����㸳ֵ
            p->j = pm->j;
            p->e = pm->e;
            p->right = NULL;
            pm = pm->right; // pmָ��������
            if(Q.rhead[i] == NULL) // pΪ���еĵ�1�����
                Q.rhead[i] = pq = p; // p���ڸ��еı�ͷ��pqָ��p(���е����һ�����)
            else // ����pq��ָ���֮��
            {
                pq->right = p; // ����в���
                pq = pq->right; // pqָ����е����һ�����
            }
            if(Q.chead[p->j] == NULL) // pΪ���еĵ�1�����
                Q.chead[p->j] = col[p->j] = p; // p���ڸ��еı�ͷ��col[p->j]ָ��p
            else // ����col[p->j]��ָ���֮��
            {
                col[p->j]->down = p; // ����в���
                col[p->j] = col[p->j]->down; // col[p->j]ָ����е����һ�����
            }
        }
        while(pn) // ������N���е�ʣ��Ԫ�ز������Q
        {
            p = (OLink)malloc(sizeof(OLNode)); // ���ɾ���Q�Ľ��
            if(!p)
                exit(OVERFLOW);
            Q.tu++; // ����Ԫ������1
            p->i = i; // ����㸳ֵ
            p->j = pn->j;
            p->e = pn->e;
            p->right = NULL;
            pn = pn->right; // pmָ��������
            if(Q.rhead[i] == NULL) // pΪ���еĵ�1�����
                Q.rhead[i] = pq = p; // p���ڸ��еı�ͷ��pqָ��p(���е����һ�����)
            else // ����pq��ָ���֮��
            {
                pq->right = p; // ����в���
                pq = pq->right; // pqָ����е����һ�����
            }
            if(Q.chead[p->j] == NULL) // pΪ���еĵ�1�����
                Q.chead[p->j] = col[p->j] = p; // p���ڸ��еı�ͷ��col[p->j]ָ��p
            else // ����col[p->j]��ָ���֮��
            {
                col[p->j]->down = p; // ����в���
                col[p->j] = col[p->j]->down; // col[p->j]ָ����е����һ�����
            }
        }
    }
    for(k = 1; k <= Q.nu; k++)
        if(col[k]) // k���н��
            col[k]->down = NULL; //  ��������һ������downָ��Ϊ��  �оͲ����𣿣�
    free(col);
    return OK;
}

Status SubCrossList(CrossList M, CrossList N, CrossList &Q)
{
    // ��ϡ�����Ĳ�Q=M-N
}

Status MulCrossList(CrossList M, CrossList N, CrossList &Q)
{
    // ��ϡ�����ĳ˻�Q=M*N
}

