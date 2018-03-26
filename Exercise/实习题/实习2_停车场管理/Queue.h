#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include"../../../template.h"
#include<stdlib.h>
#include"Car.h"

//typedef int QElemType;

typedef struct QNode
{
    QElemType data;
    struct QNode* next;
}QNode,*QueuePtr;

typedef struct
{
    QueuePtr front;//队头指针
    QueuePtr rear;//队尾指针
}LinkQueue;

Status InitQueue(LinkQueue &Q);
//构造一个空队列Q

Status DestroyQueue(LinkQueue &Q);
//销毁队列Q,Q不再存在

Status ClearQueue(LinkQueue &Q);
//将Q清为空队列

Status QueueEmpty(LinkQueue Q);
//若队列Q为空队列,则返回TRUE;否则返回为FALSE

int QueueLength(LinkQueue Q);
//返回Q的元素个数,即为队列的长度

Status GetHead(LinkQueue Q,QElemType &e);
//若队列不空,则用e返回Q的对头元素,并返回OK;否则返回ERROR

Status EnQueue(LinkQueue &Q,QElemType &e);
//插入元素e为Q的新的队尾元素

Status DeQueue(LinkQueue &Q,QElemType &e);
//若队列不空,则删除Q的队头元素,用e返回其值,并返回OK;
//否则返回ERROR

Status QueueTraverse(LinkQueue Q,Status (*visit()));
//从队头到队尾依次对队列Q中每个元素调用函数visit().一旦visit失败,则操作失败.


#endif // QUEUE_H_INCLUDED
