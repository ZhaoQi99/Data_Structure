/*
Problem:栈的顺序存储表示
Author:QiZhao
Data:2017-10-24
Description:严蔚敏版数据结构课本源码
Copyright  2017 QiZhao. All rights reserved.
*/
#include "Stack.h"
#include<stdio.h>

Status InitList(SqStack &S)
{
    //构造一个空栈S
    S.base=(ElemType *)malloc(sizeof(ElemType)*STACK_INIT_SIZE);
    if(!S.base)
        exit(OVERFLOW);
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack(SqStack &S)
{
    //销毁栈S,S不再存在
    free(S.base);
    S.top=S.base=NULL;
    S.stacksize=0;
    return OK;
}

Status ClearStack(SqStack &S)
{
    //把S置为空栈
    S.top=S.base;
    S.stacksize=0;
    return OK;
}

Status StackEmpty(SqStack S)
{
    //若栈S为空栈,则返回为TRUE,否则返回FALSE
    if(S.top==S.base)
        return TRUE;
    else
        return FALSE;
}

int StackLength(SqStack S)
{
    //返回S的元素个数,即栈的长度
    return S.top-S.base;
}

Status GetTop(SqStack S,ElemType &e)
{
    //若栈不空,则用e返回S的栈顶元素,并返回OK;否则返回ERROR
    if(S.top==S.base)
        return ERROR;
    e=*(S.top-1);
    return OK;
}

Status Push(SqStack &S,ElemType e)
{
    //插入元素e为新的栈顶元素
    if(S.top-S.base>=S.stacksize)//栈满,追加存储空间
    {
        S.base=(ElemType *)realloc(S.base,(S.stacksize+STACK_INIT_SIZE)*sizeof(ElemType));
        if(!S.base)//存储分配失败
            exit(OVERFLOW);
        S.top=S.base+S.stacksize;
        S.stacksize+=STACK_INIT_SIZE;
    }
    *S.top++=e;
    return OK;
}

Status Pop(SqStack &S,ElemType &e)
{
    //若栈不空,则删除S的栈顶元素,用e返回其值,并返回OK;否则返回ERROR
    if(S.top==S.base)
        return ERROR;
    e=*(--S.top);
    return OK;
}

Status StackTraverse(SqStack S,Status(*visit)(ElemType e))
{
    //从栈顶到栈顶依次对栈中每个元素调用函数visit().一旦visit()失败,则操作失败
    ElemType* p=S.base;
    while(p<S.top)
    {
        visit(*p++);
    }
    return OK;
}

Status visit(ElemType e)
{
    printf("%c ",e);
    return OK;
}
