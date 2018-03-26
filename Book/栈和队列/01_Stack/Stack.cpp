/*
Problem:ջ��˳��洢��ʾ
Author:QiZhao
Data:2017-10-24
Description:��ε�������ݽṹ�α�Դ��
Copyright  2017 QiZhao. All rights reserved.
*/
#include "Stack.h"
#include<stdio.h>

Status InitList(SqStack &S)
{
    //����һ����ջS
    S.base=(ElemType *)malloc(sizeof(ElemType)*STACK_INIT_SIZE);
    if(!S.base)
        exit(OVERFLOW);
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack(SqStack &S)
{
    //����ջS,S���ٴ���
    free(S.base);
    S.top=S.base=NULL;
    S.stacksize=0;
    return OK;
}

Status ClearStack(SqStack &S)
{
    //��S��Ϊ��ջ
    S.top=S.base;
    S.stacksize=0;
    return OK;
}

Status StackEmpty(SqStack S)
{
    //��ջSΪ��ջ,�򷵻�ΪTRUE,���򷵻�FALSE
    if(S.top==S.base)
        return TRUE;
    else
        return FALSE;
}

int StackLength(SqStack S)
{
    //����S��Ԫ�ظ���,��ջ�ĳ���
    return S.top-S.base;
}

Status GetTop(SqStack S,ElemType &e)
{
    //��ջ����,����e����S��ջ��Ԫ��,������OK;���򷵻�ERROR
    if(S.top==S.base)
        return ERROR;
    e=*(S.top-1);
    return OK;
}

Status Push(SqStack &S,ElemType e)
{
    //����Ԫ��eΪ�µ�ջ��Ԫ��
    if(S.top-S.base>=S.stacksize)//ջ��,׷�Ӵ洢�ռ�
    {
        S.base=(ElemType *)realloc(S.base,(S.stacksize+STACK_INIT_SIZE)*sizeof(ElemType));
        if(!S.base)//�洢����ʧ��
            exit(OVERFLOW);
        S.top=S.base+S.stacksize;
        S.stacksize+=STACK_INIT_SIZE;
    }
    *S.top++=e;
    return OK;
}

Status Pop(SqStack &S,ElemType &e)
{
    //��ջ����,��ɾ��S��ջ��Ԫ��,��e������ֵ,������OK;���򷵻�ERROR
    if(S.top==S.base)
        return ERROR;
    e=*(--S.top);
    return OK;
}

Status StackTraverse(SqStack S,Status(*visit)(ElemType e))
{
    //��ջ����ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit().һ��visit()ʧ��,�����ʧ��
    ElemType* p=S.base;
    while(p<S.top)
    {
        visit(*p++);
    }
    return OK;
}

Status visit(ElemType e)
{
    printf("%d ",e);
    return OK;
}

int main()
{
    SqStack S;
    ElemType e;
    int i;

    printf("*********************************����InitList����*********************************\n");
    InitList(S)?printf("��ʼ��˳��ջ�ɹ�\n"):printf("��ʼ��˳��ջʧ��\n");

    printf("*********************************����StackEmpty����*********************************\n");
    StackEmpty(S)?printf("˳��ջSΪ��\n"):printf("˳��ջS��Ϊ��\n");

    printf("*********************************����Push����*********************************\n");
    for(i = 1; i <= 15; i++) //15������Ԫ����ջ
    {
        e=rand()%300;//�������0~399����
                    //ʵ��Ϊ41��167��34��100��269��124��78��258��262��164��5��245��181��27��61
        printf("��ջԪ��Ϊ:\"%d\"\n",e);
        Push(S,e);
    }
    printf("*********************************����GetTop����*********************************\n");
    GetTop(S,e);
    printf("��ʱջ��Ԫ��Ϊ:\"%d\"\n",e);

    printf("*********************************����StackTraverse����*********************************\n");
    printf("˳��ջS��Ԫ�� = ");
    StackTraverse(S, visit);
    printf("\n");

    printf("*********************************����Pop����*********************************\n");
    for(i = 1; i <= 10; i++) //10������Ԫ�س�ջ
    {
        Pop(S,e);
        printf("��ջԪ��Ϊ:\"%d\"\n",e);
    }

    printf("*********************************����StackLength����*********************************\n");
    printf("˳��ջS�ĳ���Ϊ:length = %d\n",StackLength(S));

    printf("*********************************����ClearStack����*********************************\n");
    printf("����˳��ջSǰ��");
    StackEmpty(S)?printf("˳��ջSΪ��\n"):printf("˳��ջS��Ϊ��\n");
    ClearStack(S);
    printf("����˳��ջS��");
    StackEmpty(S)?printf("˳��ջSΪ��\n"):printf("˳��ջS��Ϊ��\n");

    printf("*********************************����DestroyStack����*********************************\n");
    printf("����˳��ջSǰ��");
    S.base?printf("˳��ջS����\n"):printf("˳��ջS������\n");
    DestroyStack(S);
    printf("����˳��ջS��");
    S.base?printf("˳��ջS����\n"):printf("˳��ջS������\n");

    system("pause");

    return  0;
}
