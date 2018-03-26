/*
Problem:带头结点的单链表
Author:QiZhao
Data:2017-10-01
Description:严蔚敏版数据结构课本源码
Copyright  2017 QiZhao. All rights reserved.
*/

#include"LinkList.h"

Status InitList(LinkList &L)
{
    // 构造一个空的线性表L。
    L = (LinkList)malloc(sizeof(LNode));
    if(!L)
        return(OVERFLOW);
    (*L).next = NULL;
    return OK;
} // InitList

Status DestroyList(LinkList &L)
{
    //销毁线性表L
    LinkList p = L;
    while(p)
    {
        L = p->next;
        free(p);
        p = L;
    }
    return OK;
}//DestroyList

Status ClearList(LinkList &L)
{
    //将L重置为空表
    LinkList p = L->next; //保留头结点
    while(p)
    {
        L->next = p->next;
        free(p);
        p = L->next;
    }
    L->next = NULL; //置空头结点
    return OK;
}//ClearList

int ListEmpty(LinkList L)
{
    //若L为空表,则返回TRUE,否则返回FALSE
    if(L != NULL && L->next == NULL) //链表存在且头结点为空时为空表
        return TRUE;
    else
        return ERROR;
}//ListEmpty

int ListLength(LinkList L)
{
    //返回L中数据元素个数
    int i = 0;
    LinkList p = L->next;
    while(p)
    {
        i++;
        p = p->next;
    }
    return i;
}//ListLength

Status GetElem_L(LinkList &L, int i, ElemType &e)
{
    // L为带头结点的单链表的头指针。
    // 当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
    LinkList p;
    p = L->next;
    int j = 1;           // 初始化，p指向第一个结点，j为计数器
    while (p && j < i)   // 顺指针向后查找，直到p指向第i个元素或p为空
    {
        p = p->next;
        ++j;
    }
    if ( !p || j > i ) return ERROR; // 第i个元素不存在
    e = p->data;   // 取第i个元素
    return OK;
} // GetElem_L

int LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
    // 在顺序线性表L中查找第1个值与e满足compare()的元素的位序。
    // 若找到，则返回其在L中的位序，否则返回0。
    LinkList p = L->next;
    int i = 1;
    while(p != NULL && (!(compare(p->data, e))))
    {
        p = p->next;
        i++;
    }
    if(p)
        return i;
    else
        return 0;
} // LocateElem

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e)
{
    //若cur_e是L的数据元素,且不是第一个,则用pre_e返回它的前驱,否则操作失败,pre_e无定义
    LinkList p = L->next;
    if(p->data != cur_e) //第一个节点没有前驱
    {
        while(p->next)
        {
            if(p->next->data != cur_e)
                p = p->next;
            else
            {
                pre_e = p->data;
                return OK;
            }
        }
    }
    return ERROR;
}//PriorElem

Status NextELem(LinkList L, ElemType cur_e, ElemType &next_e)
{
    //若cur_e是L的数据元素,且不是最后一个,则用next_e返回它的后继,否则操作失败,next_e无定义
    LinkList p = L->next;
    while(p->next)//最后一个节点没有后继
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
}//NextELem

Status ListInsert_L(LinkList &L, int i, ElemType e)
{
    // 在带头结点的单链线性表L的第i个元素之前插入元素e
    LinkList p, s;
    p = L;
    int j = 0;
    while (p && j < i - 1)  // 寻找第i-1个结点
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) return ERROR;    // i小于1或者大于表长
    s = (LinkList)malloc(sizeof(LNode));  // 生成新结点
    s->data = e;
    s->next = p->next;      // 插入L中
    p->next = s;
    return OK;
} // LinstInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e)
{
    // 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
    LinkList p, q;
    p = L;
    int j = 0;
    while (p->next && j < i - 1)  // 寻找第i个结点，并令p指向其前趋
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1) return ERROR; // 删除位置不合理
    q = p->next;
    p->next = q->next;           // 删除并释放结点
    e = q->data;
    free(q);
    return OK;
} // ListDelete_L

Status ListTraverse(LinkList L, Status (*visit)(ElemType))
{
    //依次对L的每个数据元素调用函数visit().一旦visit()失败，则操作失败
    if(!L)
        return ERROR;
    LinkList p = L->next;
    while(p)
    {
        visit(p->data);
        p = p->next;
    }
    return OK;
}

void CreateList_L(LinkList &L, int n)
{
    // 逆位序输入（随机产生）n个元素的值，建立带表头结点的单链线性表L
    LinkList p;
    int i;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;              // 先建立一个带头结点的单链表
    int temp[] = {41, 167, 34, 100, 269, 124, 78, 258, 262, 164, 5, 245, 181, 27, 61};
    int flag = 0;
    for (i = n; i > 0; --i)
    {
        p = (LinkList)malloc(sizeof(LNode));  // 生成新结点
        //scanf("%d",&p->data);
        p->data = temp[flag++];
        p->next = L->next;
        L->next = p;    // 插入到表头
    }
} // CreateList_L

void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc)
{
    // 已知单链线性表La和Lb的元素按值非递减排列。
    // 归并La和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列。
    LinkList pa, pb, pc;
    pa = La->next;
    pb = Lb->next;
    Lc = pc = La;             // 用La的头结点作为Lc的头结点
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;  // 插入剩余段
    free(Lb);                 // 释放Lb的头结点
} // MergeList_L

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
    LinkList L;
    ElemType e;
    int i;

    printf("*********************************函数InitList测试*********************************\n");
    InitList(L) ? printf("初始化链表成功\n") : printf("初始化链表失败\n");

    printf("*********************************函数ListEmpty测试*********************************\n");
    ListEmpty(L) ? printf("链表L为空\n") : printf("链表L不为空\n");

    printf("*********************************函数ListInsert测试*********************************\n");
    for(i = 1; i <= 15; i++) //插入15个数据元素
    {
        e = rand() % 300; //实际为41、167、34、100、269、124、78、258、262、164、5、245、181、27、61、
        printf("在第%d个位置插入\"%d\"\n", i, e);
        ListInsert_L(L, i, e);
    }

    printf("*********************************函数ListTraverse测试*********************************\n");
    printf("链表L中元素 = ");
    ListTraverse(L, visit);
    printf("\n");

    printf("*********************************函数ListDelete测试*********************************\n");
    ListDelete_L(L, 6, e);
    printf("删除链表L中第6个元素:\"%d\"\n", e);
    ListTraverse(L, visit);
    printf("\n");

    printf("*********************************函数ListLength测试*********************************\n");
    printf("链表L的长度为:length = %d\n", ListLength(L));

    printf("*********************************函数GetElem测试*********************************\n");
    GetElem_L(L, 5, e);
    printf("链表L中第五个位置的元素为%d\n", e);

    printf("*********************************函数LocateElem测试*********************************\n");
    i = LocateElem(L, 15, compare);
    i == 0 ? printf("大于15的元素不存在\n") : printf("第一个大于15的元素的位置为%d\n", i);
    i = LocateElem(L, 999, compare);
    i == 0 ? printf("大于999的元素不存在\n") : printf("第一个大于999的元素的位置为%d\n", i);

    printf("*********************************函数PriorElem测试*********************************\n");
    PriorElem(L, 100, e);
    printf("元素\"100\"的前驱为%d\n", e);

    printf("*********************************函数NextElem测试*********************************\n");
    NextELem(L, 100, e);
    printf("元素\"100\"的后继为%d\n", e);

    printf("*********************************函数ClearList测试*********************************\n");
    printf("重置链表L前：");
    ListEmpty(L) ? printf("链表L为空\n") : printf("链表L不为空\n");
    ClearList(L);
    printf("重置链表L后：");
    ListEmpty(L) ? printf("链表L为空\n") : printf("链表L不为空\n");

    printf("*********************************函数DestroyList测试*********************************\n");
    printf("销毁链表L前：");
    L ? printf("链表L存在\n") : printf("链表L不存在\n");
    DestroyList(L);
    printf("销毁链表L后：");
    L ? printf("链表L存在\n") : printf("链表L不存在\n");

    printf("*********************************函数CreateList_L测试*********************************\n");
    LinkList p;
    CreateList_L(p, 15);
    ListTraverse(p, visit);
    printf("\n");

    system("pause");

    return 0;
}
