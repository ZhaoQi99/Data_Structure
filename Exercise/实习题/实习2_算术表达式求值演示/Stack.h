#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define STACK_INIT_SIZE 100//�洢�ռ��ʼ����
#define STACKINCREMENT 1//�洢�ռ��������
#include"../../../template.h"
#include<stdlib.h>

typedef char ElemType;
typedef struct
{
    ElemType *base;//��ջ����֮ǰ������֮��,base��ֵΪnull
    ElemType *top;//ջ��ָ��
    int stacksize;//��ǰ�ѷ���Ĵ洢�ռ�,��Ԫ��Ϊ��λ
}SqStack;

Status InitList(SqStack &S);
//����һ����ջS

Status DestroyList(SqStack &S);
//����ջS,S���ٴ���

Status ClearList(SqStack &S);
//��S��Ϊ��ջ

Status StackEmpty(SqStack S);
//��ջSΪ��ջ,�򷵻�ΪTRUE,���򷵻�FALSE

int StackLength(SqStack S);
//����S��Ԫ�ظ���,��ջ�ĳ���

Status GetTop(SqStack S,ElemType &e);
//��ջ����,����e����S��ջ��Ԫ��,������OK;���򷵻�ERROR

Status Push(SqStack &S,ElemType e);
//����Ԫ��eΪ�µ�ջ��Ԫ��

Status Pop(SqStack &S,ElemType &e);
//��ջ����,��ɾ��S��ջ��Ԫ��,��e������ֵ,������OK;���򷵻�ERROR

Status StackTraverse(SqStack S,Status(*visit)());
//��ջ����ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit().һ��visit()ʧ��,�����ʧ��

Status visit(ElemType e);

#endif // STACK_H_INCLUDED
