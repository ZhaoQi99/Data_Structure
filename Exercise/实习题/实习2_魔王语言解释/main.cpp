/*
Problem:魔王语言的解释
Author:QiZhao
Data:2017-11-7
Description:严蔚敏版数据结构习题集实习题
Copyright  2017 QiZhao. All rights reserved.
*/

#include"Stack.h"
#include"Queue.h"
#include<stdio.h>
#include<string.h>

Status Push_Str(SqStack& S, char str[])
{
    //将字符数组str中的数组倒序压入栈
    int len = strlen(str);
    int i;
    for(i = len; i > 0; i--)
        Push(S, str[i - 1]);
    return OK;
}

Status Rule_1(SqStack& S)
{
    //规则1
    char temp[] = "tAdA";
    Push_Str(S, temp);
    return OK;
}

Status Rule_2(SqStack& S)
{
    //规则2
    char temp[] = "sae";
    Push_Str(S, temp);
    return OK;
}

Status Trans(SqStack S, LinkQueue &Q)
{
    //将魔王语言翻译为人类语言
    //S存储魔王的语言,Q返回翻译后的字母
    ElemType e;
    LinkQueue temp_Q;
    int flag=0;
    if(!InitQueue(temp_Q))
        return ERROR;
    if(!InitQueue(Q))
        return ERROR;
    while(!StackEmpty(S))
    {
        Pop(S, e);
        if(e == '(')
        {
            flag=1;
            Pop(S,e);
            ElemType temp=e;
            while(!StackEmpty(S))
            {
                //将括号间的元素入队
                Pop(S,e);
                if(e==')')
                    break;
                EnQueue(temp_Q,e);
            }
            while(!QueueEmpty(temp_Q))
            {
                //将临时队列的元素压入栈
                DeQueue(temp_Q,e);
                Push(S,temp);
                Push(S,e);
            }
            Push(S,temp);
        }
        else if(e == 'A')
        {
            Rule_2(S);
        }
        else if(e == 'B')
        {
            Rule_1(S);
        }
        else if(flag==0&&e==')')
        {
            printf("输入有误,无法翻译！");
            return ERROR;
        }
        else
        {
            EnQueue(Q, e);
            printf("%c",e);
        }
    }
    printf("\n");
    return OK;
}

void Print_Queue(LinkQueue Q)
{
    QueuePtr p;
    p = Q.front->next;
    while(p)
    {
        switch(p->data)
        {
        case 't':
            printf("天");
            break;
        case 'd':
            printf("地");
            break;
        case 's':
            printf("上");
            break;
        case 'a':
            printf("一只");
            break;
        case 'e':
            printf("鹅");
            break;
        case 'z':
            printf("追");
            break;
        case 'g':
            printf("赶");
            break;
        case 'x':
            printf("下");
            break;
        case 'n':
            printf("蛋");
            break;
        case 'h':
            printf("恨");
            break;
        }
        p = p->next;
    }
}

int main()
{
    SqStack S;
    LinkQueue Q;
    char str[100];
    InitList(S);
    printf("请输入魔王语言:");//B(ehnxgz)B
    scanf("%s",str);
    Push_Str(S,str);
    printf("翻译后的语言为:\n");
    Trans(S,Q);
    Print_Queue(Q);
    return 0;

}
