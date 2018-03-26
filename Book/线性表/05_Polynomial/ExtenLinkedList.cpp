/*
Problem:扩展的带头节点的线性链表
Author:QiZhao
Data:2017-10-19
Description:严蔚敏版数据结构课本源码
Copyright  2017 QiZhao. All rights reserved.
*/
#include"ExtenLinkedList.h"
#include<stdio.h>
#include<stdlib.h>

Status MakeNode(Link &p, ElemType e)
{
    //分配由p指向值为e的结点，并返回OK；若返回失败,则返回ERROR
    p = (Link)malloc(sizeof(LNode));
    if(!p)
        return OVERFLOW;
    p->data = e;
    p->next = NULL;
    return OK;
}

void FreeNode(Link &p)
{
    //释放p所指结点
    free(p);
    p = NULL;
}

Status InitList(LinkList &L)
{
    // 构造一个空的线性表L。
    Link p;
    p = (Link)malloc(sizeof(LNode));
    if(!p)
        return OVERFLOW;
    p->next = NULL;
    L.head = L.tail = p;
    L.len = 0;
    return OK;
}

Status DestroyList(LinkList & L)
{
    //销毁线性表L,L不再存在
    Link p = GetHead(L);
    Link q;
    while(p!=GetLast(L))
    {
        q = p->next;
        FreeNode(p);
        p = q;
    }
    FreeNode(L.tail);
    L.len=0;
    L.head=NULL;
    return OK;
}

Status ClearList(LinkList & L)
{
    //将L重置为空表,并释放原链表的结点空间
    Link p = GetHead(L)->next; //p指向第一个结点
    Link q;
    while(p)
    {
        q = p->next;
        FreeNode(p);
        p = q;
    }
    L.len=0;
    L.tail=GetHead(L);
    return OK;
}

Status InsFirst(LinkList &L,Link h, Link s)
{
    //已知h指向线性链表的头结点,将s所指结点插入在第一个结点之前
    Link p=h->next;//p指向第一个结点
    s->next=p;
    h->next=s;
    L.len++;
    return OK;
}

Status DelFirst(LinkList &L,Link h, Link &q)
{
    //已知h指向线性链表的头结点,删除链表中第一个结点并以q返回
    q=h->next;
    h->next=q->next;
    L.len--;
    return OK;
}

Status Append(LinkList &L, Link s)
{
    //将指针s所指(彼此以指针相链)的一串结点链接在线性链表L的最后一个结点
    //之后,并改变链表L的尾指针指向新的尾结点
    Link q=L.tail;
    while(s!=NULL)
    {
        q->next=s;
        q=s;
        s=s->next;
        L.len++;
    }
    L.tail=q;//尾指针指向新的尾结点
    return  OK;
}

Status Remove(LinkList &L, Link &q)
{
    //删除线性链表L中的尾结点并以q返回,改变链表L的尾指针指向新的尾结点
    Link p=GetHead(L);
    if(L.head==L.tail)
        return ERROR;
    while(p->next!=L.tail)
        p=p->next;
    L.tail=p;
    p=p->next;
    q->data=p->data;
    //FreeNode(p);
    L.len--;
    return OK;
}

Status InsBefore(LinkList &L, Link &p, Link s)
{
    //已知p指向线性链表L中的一个结点,将s所指结点插入在p所指结点之前,
    //并修改指针p指向新插入的结点
    Link q=GetHead(L);
    while(q->next != p)
        q = q->next;
    s->next=q->next;
    q->next=s;
    if(p==L.head->next)//p所指结点为第一个时
        L.head=p;
    p=s;
    L.len++;
    return OK;
}

Status InsAfter(LinkList &L, Link &p, Link s)
{
    //已知p指向线性链表L中的一个结点,将s所指结点插入在p所指结点之后,
    //并修改指针p指向新插入的结点
    Link q=GetHead(L);
    while(q!=p)
        q=q->next;
    s->next=p->next;
    p->next=s;
    if(p==GetLast(L))
        L.tail=s;
    p=s;
    L.len++;
    return OK;
}

Status ListInsert(LinkList &L, int i, ElemType e)
{
    // 在带头结点的扩展的单链线性表L的第i个元素之前插入元素e
    Link p, s;
    p = GetHead(L);
    int j = 0;
    if (!p || j > i - 1)
        return ERROR;    // i小于1或者大于表长
    while (p && j < i - 1)  // 寻找第i-1个结点
    {
        p = p->next;
        ++j;
    }
    if(!MakeNode(s,e))  // 生成新结点
        return OVERFLOW;
    s->next = p->next;      // 插入L中
    p->next = s;
    if(i==ListLength(L)+1)
        L.tail=s;
    L.len++;
    return OK;
}

Status SetCurElem(Link &p, ElemType e)
{
    //已知p指向线性链表中的一个结点,用e更新p所指结点中数据元素的值
    p->data=e;
    return OK;
}

ElemType GetCurElem(Link p)
{
    //已知p指向线性链表中的一个结点,返回p所指结点中数据元素的值
    return p->data;
}

Status ListEmpty(LinkList L)
{
    //若L为空表,则返回TRUE,否则返回FALSE
    if(L.len==0)
        return TRUE;
    else
        return FALSE;
}

int ListLength(LinkList L)
{
    //返回L中数据元素个数
    return L.len;
}

Position GetHead(LinkList L)
{
    //返回线性表L中头结点的位置
    return L.head;
}

Position GetLast(LinkList L)
{
    //返回线性表L中最后一个结点的位置
    return L.tail;
}

Position PriorPos(LinkList L, Link p)
{
    //已知p指向线性链表L中的一个结点,返回p所指结点的直接前驱的位置,
    //若无前驱,则返回NULL
    Link q=GetHead(L);
    if(p==q->next)//第一个结点无直接前驱
        return NULL;
    while(q->next!=p)
        q=q->next;
    return q;
}

Position NextPos(LinkList L, Link p)
{
    //已知p指向线性链表L中的一个结点,返回p所指结点的直接后继的位置,
    //若无后继,则返回NULL
    Link q=GetHead(L);
    while(q!=p)
        q=q->next;
    if(q==L.tail)//最后一个结点无直接后继
        return NULL;
    q=q->next;
    return q;
}

Status LocatePos(LinkList L, int i, Link &p)
{
    //返回p指示线性链表L中第i个结点的位置,并返回OK,i值不合法时返回ERROR
    if(i<1||i>L.len)//i值不合法
        return ERROR;
    Link q=GetHead(L);
    while(i--)
    {
        q=q->next;
    }
    p=q;
    return OK;
}

Position LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
    // 在链式线性表L中查找第1个值与e满足compare()的元素的位置
    // 若不存在这样的元素,则返回NULL
    Link p=GetHead(L)->next;
    while(p != L.tail &&(!compare(p->data, e)))
    {
        p = p->next;
    }
    if(p==L.tail)
        return NULL;
    else
        return p;
}

Status ListTraverse(LinkList L, Status (*visit)(ElemType))
{
    //依次对L的每个数据元素调用函数visit().一旦visit()失败，则操作失败
    Link p=GetHead(L);
    int len=ListLength(L);
    while(len--)
    {
        p=p->next;
        visit(p->data);
    }
    return OK;
}

