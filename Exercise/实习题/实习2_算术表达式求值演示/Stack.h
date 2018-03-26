#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define STACK_INIT_SIZE 100//存储空间初始分量
#define STACKINCREMENT 1//存储空间分配增量
#include"../../../template.h"
#include<stdlib.h>

typedef char ElemType;
typedef struct
{
    ElemType *base;//在栈构造之前和销毁之后,base的值为null
    ElemType *top;//栈顶指针
    int stacksize;//当前已分配的存储空间,以元素为单位
}SqStack;

Status InitList(SqStack &S);
//构造一个空栈S

Status DestroyList(SqStack &S);
//销毁栈S,S不再存在

Status ClearList(SqStack &S);
//把S置为空栈

Status StackEmpty(SqStack S);
//若栈S为空栈,则返回为TRUE,否则返回FALSE

int StackLength(SqStack S);
//返回S的元素个数,即栈的长度

Status GetTop(SqStack S,ElemType &e);
//若栈不空,则用e返回S的栈顶元素,并返回OK;否则返回ERROR

Status Push(SqStack &S,ElemType e);
//插入元素e为新的栈顶元素

Status Pop(SqStack &S,ElemType &e);
//若栈不空,则删除S的栈顶元素,用e返回其值,并返回OK;否则返回ERROR

Status StackTraverse(SqStack S,Status(*visit)());
//从栈顶到栈顶依次对栈中每个元素调用函数visit().一旦visit()失败,则操作失败

Status visit(ElemType e);

#endif // STACK_H_INCLUDED
