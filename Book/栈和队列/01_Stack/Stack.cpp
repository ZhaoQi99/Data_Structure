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
    printf("%d ",e);
    return OK;
}

int main()
{
    SqStack S;
    ElemType e;
    int i;

    printf("*********************************函数InitList测试*********************************\n");
    InitList(S)?printf("初始化顺序栈成功\n"):printf("初始化顺序栈失败\n");

    printf("*********************************函数StackEmpty测试*********************************\n");
    StackEmpty(S)?printf("顺序栈S为空\n"):printf("顺序栈S不为空\n");

    printf("*********************************函数Push测试*********************************\n");
    for(i = 1; i <= 15; i++) //15个数据元素入栈
    {
        e=rand()%300;//随机生成0~399的数
                    //实际为41、167、34、100、269、124、78、258、262、164、5、245、181、27、61
        printf("入栈元素为:\"%d\"\n",e);
        Push(S,e);
    }
    printf("*********************************函数GetTop测试*********************************\n");
    GetTop(S,e);
    printf("此时栈顶元素为:\"%d\"\n",e);

    printf("*********************************函数StackTraverse测试*********************************\n");
    printf("顺序栈S中元素 = ");
    StackTraverse(S, visit);
    printf("\n");

    printf("*********************************函数Pop测试*********************************\n");
    for(i = 1; i <= 10; i++) //10个数据元素出栈
    {
        Pop(S,e);
        printf("出栈元素为:\"%d\"\n",e);
    }

    printf("*********************************函数StackLength测试*********************************\n");
    printf("顺序栈S的长度为:length = %d\n",StackLength(S));

    printf("*********************************函数ClearStack测试*********************************\n");
    printf("重置顺序栈S前：");
    StackEmpty(S)?printf("顺序栈S为空\n"):printf("顺序栈S不为空\n");
    ClearStack(S);
    printf("重置顺序栈S后：");
    StackEmpty(S)?printf("顺序栈S为空\n"):printf("顺序栈S不为空\n");

    printf("*********************************函数DestroyStack测试*********************************\n");
    printf("销毁顺序栈S前：");
    S.base?printf("顺序栈S存在\n"):printf("顺序栈S不存在\n");
    DestroyStack(S);
    printf("销毁顺序栈S后：");
    S.base?printf("顺序栈S存在\n"):printf("顺序栈S不存在\n");

    system("pause");

    return  0;
}
