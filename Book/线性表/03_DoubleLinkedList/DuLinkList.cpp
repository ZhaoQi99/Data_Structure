/*
Problem:带头结点的双头循环链表
Author:QiZhao
Data:2017-10-12
Description:严蔚敏版数据结构课本源码
Copyright  2017 QiZhao. All rights reserved.
*/
#include"DuLinkList.h"
#include<stdio.h>
#include<stdlib.h>

Status InitList_DuL(DuLinkList &L)
{
    // 构造一个空的线性表L。
    L = (DuLinkList)malloc(sizeof(DuLNode));
    if(!L)
        return(OVERFLOW);
    (*L).next = (*L).prior = L;
    return OK;
} // InitList_DuL

Status DestroyList_DuL(DuLinkList &L)
{
    //销毁线性表L
    DuLinkList p = L->next;
    DuLinkList q;
    while(p!=L)
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(L);
    L=NULL;
    return OK;
}//DestroyList_DuL

Status ClearList_DuL(DuLinkList &L)
{
    //将L重置为空表
    DuLinkList p = L->next;
    DuLinkList q;
    while(p != L)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = L->prior = L;
    return OK;
}//ClearList_DuL

int DuLinkListEmpty(DuLinkList L)
{
    //若L为空表,则返回TRUE,否则返回FALSE
    if(L != NULL && L->next == L && L->prior == L) //链表存在且头结点的前驱和后继均为自己
        return TRUE;
    else
        return FALSE;
}//DuLinkListEmpty

int DuLinkListLength(DuLinkList L)
{
    //返回L中数据元素个数
    int i = 0;
    DuLinkList p = L->next;
    while(p != L)
    {
        i++;
        p = p->next;
    }
    return i;
}//DuLinkListLength

DuLinkList GetElem_DuL(DuLinkList va, int i)
{
    // L为带头结点的单链表的头指针。
    // 当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
    DuLinkList p;
    p = va->next;
    int j = 1;  // 初始化，p指向第一个结点，j为计数器
    while (p && j < i) //顺指针向后查找，直到p指向第i个元素或p为空
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return ERROR; // 第i个元素不存在
    else return p;
} // GetElem_DuL

int LocateElem_DuL(DuLinkList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
    // 在双链循环线性表L中查找第1个值与e满足compare()的元素的位序。
    // 若找到，则返回其在L中的位序，否则返回0。
    DuLinkList p = L->next;
    int i = 1;
    while(p != L && (!(compare(p->data, e))))
    {
        p = p->next;
        i++;
    }
    if(p)
        return i;
    else
        return 0;
} // LocateElem_DuL

Status PriorElem_DuL(DuLinkList L, ElemType cur_e, ElemType &pre_e)
{
    //若cur_e是L的数据元素,且不是第一个,则用pre_e返回它的前驱,否则操作失败,pre_e无定义
    DuLinkList p = L->next;
    if(p->data != cur_e) //第一个节点没有前驱
    {
        while(p != L)
        {
            if(p->data != cur_e)
                p = p->next;
            else
            {
                pre_e = p->prior->data;
                return OK;
            }
        }
    }
    return ERROR;
    }//PriorElem_DuL

Status NextELem_DuL(DuLinkList L, ElemType cur_e, ElemType &next_e)
{
    //若cur_e是L的数据元素,且不是最后一个,则用next_e返回它的后继,否则操作失败,next_e无定义
    DuLinkList p = L->next;
    while(p->next!=L)//最后一个节点没有后继
    {
        if(p->data != cur_e)
            p = p->next;
        else
        {
            next_e = p->next->data;
            return OK;
        }
    }
    return ERROR;
}//NextELem_DuL

Status ListInsert_DuL(DuLinkList &L, int i, ElemType e)
{
    // 在带头结点的双链循环线性表L的第i个元素之前插入元素e，
    // i的合法值为1≤i≤表长+1。
    DuLinkList p, s;
    if (!(p = GetElem_DuL(L, i)))  // 在L中确定第i个元素的位置指针p
        return ERROR;                 // p=NULL, 即第i个元素不存在
    if (!(s = (DuLinkList)malloc(sizeof(DuLNode))))
        return ERROR;
    s->data = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return OK;
}//ListInsert_DuL

Status ListDelete_DuL(DuLinkList &L, int i, ElemType &e)
{
    // 删除带头结点的双链循环线性表L的第i个元素，i的合法值为1≤i≤表长
    DuLinkList p;
    if (!(p = GetElem_DuL(L, i)))  // 在L中确定第i个元素的位置指针p
        return ERROR;                 // p=NULL, 即第i个元素不存在
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
} // ListDelete_DuL

Status ListTraverse(DuLinkList L, Status (*visit)(ElemType))
{
    //依次对L的每个数据元素调用函数visit().一旦visit()失败，则操作失败
    if(!L)
        return ERROR;
    DuLinkList p = L->next;
    while(p!=L)
    {
        visit(p->data);
        p = p->next;
    }
    return OK;
}

Status visit(ElemType e)
{
    printf("%d ", e);
    return OK;
}//visit

Status compare(ElemType a, ElemType b)
{
    return a > b ? TRUE : FALSE;
}//compare

int main()
{
/******************************************************Test**********************************************************/
    DuLinkList L;
    ElemType e;
    int i;

    printf("*********************************函数InitList测试*********************************\n");
    InitList_DuL(L) ? printf("初始化双循环链表成功\n") : printf("初始化双循环链表失败\n");

    printf("*********************************函数ListEmpty测试*********************************\n");
    DuLinkListEmpty(L) ? printf("双循环链表L为空\n") : printf("双循环链表L不为空\n");

    printf("*********************************函数ListInsert测试*********************************\n");
    for(i = 1; i <= 15; i++) //插入15个数据元素
    {
        e = rand() % 300; //实际为41、167、34、100、269、124、78、258、262、164、5、245、181、27、61、
        printf("在第%d个位置插入\"%d\"\n", i, e);
        ListInsert_DuL(L, i, e);
    }

    printf("*********************************函数ListTraverse测试*********************************\n");
    printf("双循环链表L中元素 = ");
    ListTraverse(L, visit);
    printf("\n");

    printf("*********************************函数ListDelete测试*********************************\n");
    ListDelete_DuL(L, 6, e);
    printf("删除双循环链表L中第6个元素:\"%d\"\n", e);
    ListTraverse(L, visit);
    printf("\n");

    printf("*********************************函数ListLength测试*********************************\n");
    printf("双循环链表L的长度为:length = %d\n", DuLinkListLength(L));

    printf("*********************************函数GetElem测试*********************************\n");
    GetElem_DuL(L, 5);
    printf("双循环链表L中第五个位置的元素为%d\n", e);

    printf("*********************************函数LocateElem测试*********************************\n");
    i = LocateElem_DuL(L, 15, compare);
    i == 0 ? printf("大于15的元素不存在\n") : printf("第一个大于15的元素的位置为%d\n", i);
    i = LocateElem_DuL(L, 999, compare);
    i == 0 ? printf("大于999的元素不存在\n") : printf("第一个大于999的元素的位置为%d\n", i);

    printf("*********************************函数PriorElem测试*********************************\n");
    PriorElem_DuL(L, 100, e);
    printf("元素\"100\"的前驱为%d\n", e);

    printf("*********************************函数NextElem测试*********************************\n");
    NextELem_DuL(L, 100, e);
    printf("元素\"100\"的后继为%d\n", e);

    printf("*********************************函数ClearList测试*********************************\n");
    printf("重置双循环链表L前：");
    DuLinkListEmpty(L) ? printf("双循环链表L为空\n") : printf("双循环链表L不为空\n");
    ClearList_DuL(L);
    printf("重置双循环链表L后：");
    DuLinkListEmpty(L) ? printf("双循环链表L为空\n") : printf("双循环链表L不为空\n");

    printf("*********************************函数DestroyList测试*********************************\n");
    printf("销毁双循环链表L前：");
    L ? printf("双循环链表L存在\n") : printf("双循环链表L不存在\n");
    DestroyList_DuL(L);
    printf("销毁双循环链表L后：");
    L ? printf("双循环链表L存在\n") : printf("双循环链表不存在\n");

    system("pause");

    return 0;
}
