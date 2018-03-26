/*
Problem:十字链表存储的稀疏矩阵
Author:QiZhao
Data:2017-12-13
Description:严蔚敏版数据结构课本源码
Copyright  2017 QiZhao. All rights reserved.
*/
#include"CrossList.h"
#include<stdio.h>
#include<conio.h>

Status CreateSMatrix(CrossList &M)
{
    // 创建稀疏矩阵M
// if (M) free(M);
    OLNode *p, *q;
    int i, j, e;
    int m, n, t;
    printf("请输入矩阵的行数,列数,非零元素个数:\n");
    scanf("%d %d %d", &m, &n, &t );   // 输入M的行数、列数和非零元个数
//    printf("%d %d %d\n",m,n,t);
    M.mu = m;
    M.nu = n;
    M.tu = t;
    if (!(M.rhead = (OLink *)malloc((m + 1) * sizeof(OLink)))) return ERROR;
    if (!(M.chead = (OLink *)malloc((n + 1) * sizeof(OLink)))) return ERROR;
    for(int a = 1; a <= m; a++) // 初始化行列头指针向量；各行列链表为空链表
        M.rhead[a] = NULL;
    for(int b = 1; b <= n; b++) M.chead[b] = NULL;
    for ( int c = 1; c <= t; c++) // 按任意次序输入非零元
    {
        printf("请输入第%d个非零元素所在的行(1～%d),列(1～%d),元素值:\n", c, M.mu, M.nu);
        scanf("%d %d %d", &i, &j, &e);
//        printf("%d %d %d\n",i,j,e);
        if (!(p = (OLNode *)malloc(sizeof(OLNode)))) return ERROR;
        p->i = i;
        p->j = j;
        p->e = e;
        p->down = NULL;
        p->right = NULL; // 新结点
        if (M.rhead[i] == NULL || M.rhead[i]->j > j)
        {
            p->right = M.rhead[i];
            M.rhead[i] = p;
        }
        else      // 寻查在行表中的插入位置
        {
            for (q = M.rhead[i]; (q->right) && (q->right->j < j);  q = q->right);
            p->right = q->right;
            q ->right = p;
        }  // 完成行插入
        if (M.chead[j] == NULL || M.chead[j]->i > i)
        {
            p->down = M.chead[j];
            M.chead[j] = p;
        }
        else      // 寻查在列表中的插入位置
        {
            for ( q = M.chead[j]; (q->down) && q->down->i < i;  q = q->down );
            p->down = q->down;
            q->down = p;
        }  // 完成列插入
    } // for
    printf("-----------------------------------\n");
    return OK;

}

Status DestroySMatrix(CrossList &M)
{
    // 销毁稀疏矩阵M
    int i;
    OLNode *p, *q;
    for(i = 1; i <= M.mu; i++) // 按行释放结点
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
    // 输出稀疏矩阵M
    int  j;
    char i;
    OLink p;
    printf("%d行%d列%d个非零元素\n", M.mu, M.nu, M.tu);
    printf("请输入选择(1.按行输出 2.按列输出): ");
    i=getch();
    while(i!='1'&&i!='2')
    {
        printf("输入有误，请重新输入！\n");
        i=getch();
    }
    printf("\n-----------------------------\n");
    printf("行  列   元素值\n");
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
    //由稀疏矩阵M复制得到T

}

Status AddSMatrix(CrossList M, CrossList N, CrossList &Q)
{
    // 求稀疏矩阵的和Q=M+N
    int i, k;
    OLink p, pq, pm, pn;
    OLink *col;
    if(M.mu != N.mu || M.nu != N.nu)
    {
        printf("两个矩阵不是同类型的,不能相加\n");
        exit(OVERFLOW);
    }
    Q.mu = M.mu; // 初始化Q矩阵
    Q.nu = M.nu;
    Q.tu = 0; // 元素个数的初值
    Q.rhead = (OLink*)malloc((Q.mu + 1) * sizeof(OLink));
    if(!Q.rhead)
        exit(OVERFLOW);
    Q.chead = (OLink*)malloc((Q.nu + 1) * sizeof(OLink));
    if(!Q.chead)
        exit(OVERFLOW);
    for(k = 1; k <= Q.mu; k++) // 初始化Q的行头指针向量;各行链表为空链表
        Q.rhead[k] = NULL;
    for(k = 1; k <= Q.nu; k++) // 初始化Q的列头指针向量;各列链表为空链表
        Q.chead[k] = NULL;
    col = (OLink*)malloc((Q.nu + 1) * sizeof(OLink)); // 生成指向列的最后结点的数组
    if(!col)
        exit(OVERFLOW);
    for(k = 1; k <= Q.nu; k++) // 赋初值
        col[k] = NULL;
    for(i = 1; i <= M.mu; i++) // 按行的顺序相加
    {
        pm = M.rhead[i]; // pm指向矩阵M的第i行的第1个结点
        pn = N.rhead[i]; // pn指向矩阵N的第i行的第1个结点
        while(pm && pn) // pm和pn均不空
        {
            if(pm->j < pn->j) // 矩阵M当前结点的列小于矩阵N当前结点的列
            {
                p = (OLink)malloc(sizeof(OLNode)); // 生成矩阵Q的结点
                if(!p)
                    exit(OVERFLOW);
                Q.tu++; // 非零元素数加1
                p->i = i; // 给结点赋值
                p->j = pm->j;
                p->e = pm->e;
                p->right = NULL;
                pm = pm->right; // pm指针向右移
            }
            else if(pm->j > pn->j) // 矩阵M当前结点的列大于矩阵N当前结点的列
            {
                p = (OLink)malloc(sizeof(OLNode)); // 生成矩阵Q的结点
                if(!p)
                    exit(OVERFLOW);
                Q.tu++; // 非零元素数加1
                p->i = i; // 给结点赋值
                p->j = pn->j;
                p->e = pn->e;
                p->right = NULL;
                pn = pn->right; // pn指针向右移
            }
            else if(pm->e + pn->e) // 矩阵M、N当前结点的列相等且两元素之和不为0
            {
                p = (OLink)malloc(sizeof(OLNode)); // 生成矩阵Q的结点
                if(!p)
                    exit(OVERFLOW);
                Q.tu++; // 非零元素数加1
                p->i = i; // 给结点赋值
                p->j = pn->j;
                p->e = pm->e + pn->e;
                p->right = NULL;
                pm = pm->right; // pm指针向右移
                pn = pn->right; // pn指针向右移
            }
            else // 矩阵M、N当前结点的列相等且两元素之和为0
            {
                pm = pm->right; // pm指针向右移
                pn = pn->right; // pn指针向右移
                continue;
            }
            if(Q.rhead[i] == NULL) // p为该行的第1个结点
                Q.rhead[i] = pq = p; // p插在该行的表头且pq指向p(该行的最后一个结点)
            else // 插在pq所指结点之后
            {
                pq->right = p; // 完成行插入
                pq = pq->right; // pq指向该行的最后一个结点
            }
            if(Q.chead[p->j] == NULL) // p为该列的第1个结点
                Q.chead[p->j] = col[p->j] = p; // p插在该列的表头且col[p->j]指向p
            else // 插在col[p->]所指结点之后
            {
                col[p->j]->down = p; // 完成列插入
                col[p->j] = col[p->j]->down; // col[p->j]指向该列的最后一个结点
            }
        }
        while(pm) // 将矩阵M该行的剩余元素插入矩阵Q
        {
            p = (OLink)malloc(sizeof(OLNode)); // 生成矩阵Q的结点
            if(!p)
                exit(OVERFLOW);
            Q.tu++; // 非零元素数加1
            p->i = i; // 给结点赋值
            p->j = pm->j;
            p->e = pm->e;
            p->right = NULL;
            pm = pm->right; // pm指针向右移
            if(Q.rhead[i] == NULL) // p为该行的第1个结点
                Q.rhead[i] = pq = p; // p插在该行的表头且pq指向p(该行的最后一个结点)
            else // 插在pq所指结点之后
            {
                pq->right = p; // 完成行插入
                pq = pq->right; // pq指向该行的最后一个结点
            }
            if(Q.chead[p->j] == NULL) // p为该列的第1个结点
                Q.chead[p->j] = col[p->j] = p; // p插在该列的表头且col[p->j]指向p
            else // 插在col[p->j]所指结点之后
            {
                col[p->j]->down = p; // 完成列插入
                col[p->j] = col[p->j]->down; // col[p->j]指向该列的最后一个结点
            }
        }
        while(pn) // 将矩阵N该行的剩余元素插入矩阵Q
        {
            p = (OLink)malloc(sizeof(OLNode)); // 生成矩阵Q的结点
            if(!p)
                exit(OVERFLOW);
            Q.tu++; // 非零元素数加1
            p->i = i; // 给结点赋值
            p->j = pn->j;
            p->e = pn->e;
            p->right = NULL;
            pn = pn->right; // pm指针向右移
            if(Q.rhead[i] == NULL) // p为该行的第1个结点
                Q.rhead[i] = pq = p; // p插在该行的表头且pq指向p(该行的最后一个结点)
            else // 插在pq所指结点之后
            {
                pq->right = p; // 完成行插入
                pq = pq->right; // pq指向该行的最后一个结点
            }
            if(Q.chead[p->j] == NULL) // p为该列的第1个结点
                Q.chead[p->j] = col[p->j] = p; // p插在该列的表头且col[p->j]指向p
            else // 插在col[p->j]所指结点之后
            {
                col[p->j]->down = p; // 完成列插入
                col[p->j] = col[p->j]->down; // col[p->j]指向该列的最后一个结点
            }
        }
    }
    for(k = 1; k <= Q.nu; k++)
        if(col[k]) // k列有结点
            col[k]->down = NULL; //  令该列最后一个结点的down指针为空  行就不用吗？？
    free(col);
    return OK;
}

Status SubCrossList(CrossList M, CrossList N, CrossList &Q)
{
    // 求稀疏矩阵的差Q=M-N
}

Status MulCrossList(CrossList M, CrossList N, CrossList &Q)
{
    // 求稀疏矩阵的乘积Q=M*N
}

