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

Status visit(QElemType e)
{
    printf("%d ",e);
    return OK;
}

int main()
{
    LinkQueue Q;
    int i;
    QElemType e;

    printf("*********************************函数InitQueue测试*********************************\n");
    InitQueue(Q)?printf("初始化链队列成功\n"):printf("初始化链队列失败\n");

    printf("*********************************函数QueueEmpty测试*********************************\n");
    QueueEmpty(Q)?printf("链队列Q为空\n"):printf("链队列Q不为空\n");

    printf("*********************************函数EnQueue测试*********************************\n");
    for(i = 1; i <= 15; i++) //15个数据元素入队
    {
        e=rand()%300;//随机生成0~399的数
                    //实际为41、167、34、100、269、124、78、258、262、164、5、245、181、27、61
        printf("入队元素为:\"%d\"\n",e);
        EnQueue(Q,e);
    }
    printf("*********************************函数QueueTraverse测试*********************************\n");
    QueueTraverse(Q,visit);
    printf("\n");

    printf("*********************************函数EnQueue测试*********************************\n");
    for(i=1;i<=10;i++)
    {
        DeQueue(Q,e);
        printf("出队元素为:\"%d\"\n",e);
    }

    printf("*********************************函数QueueLength测试*********************************\n");
    printf("链队列Q的长度为:length = %d\n",QueueLength(Q));

    printf("*********************************函数GetHead测试*********************************\n");
    GetHead(Q,e);
    printf("队头元素为:\"%d\"\n",e);

    printf("*********************************函数ClearQueue测试*********************************\n");
    printf("重置链队列L前：");
    QueueEmpty(Q)?printf("链队列Q为空\n"):printf("链队列Q不为空\n");
    ClearQueue(Q);
    printf("重置链队列Q后：");
    QueueEmpty(Q)?printf("链队列Q为空\n"):printf("链队列Q不为空\n");

    printf("*********************************函数DestroyQueue测试*********************************\n");
    printf("销毁链队列Q前：");
    Q.front?printf("链队列Q存在\n"):printf("链队列Q不存在\n");
    DestroyQueue(Q);
    printf("销毁链队列Q后：");
    Q.front?printf("链队列Q存在\n"):printf("链队列Q不存在\n");

    return 0;
}
