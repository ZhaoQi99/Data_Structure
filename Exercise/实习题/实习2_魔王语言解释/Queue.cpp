/*
Problem:��������
Author:QiZhao
Data:2017-10-24
Description:��ε�������ݽṹ�α�Դ��
Copyright  2017 QiZhao. All rights reserved.
*/
#include"Queue.h"
#include<stdio.h>

Status InitQueue(LinkQueue &Q)
{
    //����һ���ն���Q
    Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
    if(!Q.front)
        return OVERFLOW;
    Q.front->next=NULL;
    return OK;
}

Status DestroyQueue(LinkQueue &Q)
{
    //���ٶ���Q,Q���ٴ���
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
    //��Q��Ϊ�ն���
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
    //������QΪ�ն���,�򷵻�TRUE;���򷵻�ΪFALSE
    if(Q.front==Q.rear)
        return TRUE;
    else
        return FALSE;
}

int QueueLength(LinkQueue Q)
{
    //����Q��Ԫ�ظ���,��Ϊ���еĳ���
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
    //�����в���,����e����Q�Ķ�ͷԪ��,������OK;���򷵻�ERROR
    if(QueueEmpty(Q))
        return ERROR;
    QueuePtr p=Q.front->next;
    e=p->data;
    return OK;
}

Status EnQueue(LinkQueue &Q,QElemType &e)
{
    //����Ԫ��eΪQ���µĶ�βԪ��
    QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
    if(!p)//�洢����ʧ��
        return OVERFLOW;
    p->data=e;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
    return OK;
}

Status DeQueue(LinkQueue &Q,QElemType &e)
{
    //�����в���,��ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK;
    //���򷵻�ERROR
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
    //�Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���visit().һ��visitʧ��,�����ʧ��.
    QueuePtr p;
    p=Q.front->next;
    while(p)
    {
        visit(p->data);
        p=p->next;
    }
    return OK;
}
