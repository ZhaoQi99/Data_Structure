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
    QueuePtr front;//��ͷָ��
    QueuePtr rear;//��βָ��
}LinkQueue;

Status InitQueue(LinkQueue &Q);
//����һ���ն���Q

Status DestroyQueue(LinkQueue &Q);
//���ٶ���Q,Q���ٴ���

Status ClearQueue(LinkQueue &Q);
//��Q��Ϊ�ն���

Status QueueEmpty(LinkQueue Q);
//������QΪ�ն���,�򷵻�TRUE;���򷵻�ΪFALSE

int QueueLength(LinkQueue Q);
//����Q��Ԫ�ظ���,��Ϊ���еĳ���

Status GetHead(LinkQueue Q,QElemType &e);
//�����в���,����e����Q�Ķ�ͷԪ��,������OK;���򷵻�ERROR

Status EnQueue(LinkQueue &Q,QElemType &e);
//����Ԫ��eΪQ���µĶ�βԪ��

Status DeQueue(LinkQueue &Q,QElemType &e);
//�����в���,��ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK;
//���򷵻�ERROR

Status QueueTraverse(LinkQueue Q,Status (*visit()));
//�Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���visit().һ��visitʧ��,�����ʧ��.


#endif // QUEUE_H_INCLUDED
