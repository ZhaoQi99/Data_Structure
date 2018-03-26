/*
Problem:单链队列
Author:QiZhao
Data:2017-10-24
Description:严蔚敏版数据结构课本源码
Copyright  2017 QiZhao. All rights reserved.
*/
#include"Queue.h"
#include<stdio.h>

Status InitQueue(LinkQueue &Q)
{
    //构造一个空队列Q
    Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
    if(!Q.front)
        return OVERFLOW;
    Q.front->next=NULL;
    return OK;
}

Status DestroyQueue(LinkQueue &Q)
{
    //销毁队列Q,Q不再存在
    while(Q.front)
    {
        Q.rear=Q.front->next;
        free(Q.front);
        Q.front=Q.rear;
    }
    return OK;
}

Status ClearQueue(LinkQueue &Q)
{
    //将Q清为空队列
    QueuePtr p=Q.front->next;
    while(p)
    {
        Q.rear=p->next;
        free(p);
        p=Q.rear;
    }
    Q.rear=Q.front;
    Q.front->next=NULL;
    return OK;
}

Status QueueEmpty(LinkQueue Q)
{
    //若队列Q为空队列,则返回TRUE;否则返回为FALSE
    if(Q.front==Q.rear)
        return TRUE;
    else
        return FALSE;
}

int QueueLength(LinkQueue Q)
{
    //返回Q的元素个数,即为队列的长度
    int i=0;
    QueuePtr p=Q.front;
    while(p!=Q.rear)
    {
        i++;
        p=p->next;
    }
    return i;
}

Status GetHead(LinkQueue Q,QElemType &e)
{
    //若队列不空,则用e返回Q的队头元素,并返回OK;否则返回ERROR
    if(QueueEmpty(Q))
        return ERROR;
    QueuePtr p=Q.front->next;
    e=p->data;
    return OK;
}

Status EnQueue(LinkQueue &Q,QElemType &e)
{
    //插入元素e为Q的新的队尾元素
    QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
    if(!p)//存储分配失败
        return OVERFLOW;
    p->data=e;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
    return OK;
}

Status DeQueue(LinkQueue &Q,QElemType &e)
{
    //若队列不空,则删除Q的队头元素,用e返回其值,并返回OK;
    //否则返回ERROR
    QueuePtr p;
    if(Q.front==Q.rear)
        return ERROR;
    p=Q.front->next;
    e=p->data;
    Q.front->next=p->next;
    if(Q.rear==p)
        Q.rear=Q.front;
    free(p);
    return OK;
}

Status QueueTraverse(LinkQueue Q,Status(*visit)(QElemType))
{
    //从队头到队尾依次对队列Q中每个元素调用函数visit().一旦visit失败,则操作失败.
    QueuePtr p;
    p=Q.front->next;
    while(p)
    {
        visit(p->data);
        p=p->next;
    }
    return OK;
}
