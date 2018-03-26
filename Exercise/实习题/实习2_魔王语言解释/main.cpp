/*
Problem:ħ�����ԵĽ���
Author:QiZhao
Data:2017-11-7
Description:��ε�������ݽṹϰ�⼯ʵϰ��
Copyright  2017 QiZhao. All rights reserved.
*/

#include"Stack.h"
#include"Queue.h"
#include<stdio.h>
#include<string.h>

Status Push_Str(SqStack& S, char str[])
{
    //���ַ�����str�е����鵹��ѹ��ջ
    int len = strlen(str);
    int i;
    for(i = len; i > 0; i--)
        Push(S, str[i - 1]);
    return OK;
}

Status Rule_1(SqStack& S)
{
    //����1
    char temp[] = "tAdA";
    Push_Str(S, temp);
    return OK;
}

Status Rule_2(SqStack& S)
{
    //����2
    char temp[] = "sae";
    Push_Str(S, temp);
    return OK;
}

Status Trans(SqStack S, LinkQueue &Q)
{
    //��ħ�����Է���Ϊ��������
    //S�洢ħ��������,Q���ط�������ĸ
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
                //�����ż��Ԫ�����
                Pop(S,e);
                if(e==')')
                    break;
                EnQueue(temp_Q,e);
            }
            while(!QueueEmpty(temp_Q))
            {
                //����ʱ���е�Ԫ��ѹ��ջ
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
            printf("��������,�޷����룡");
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
            printf("��");
            break;
        case 'd':
            printf("��");
            break;
        case 's':
            printf("��");
            break;
        case 'a':
            printf("һֻ");
            break;
        case 'e':
            printf("��");
            break;
        case 'z':
            printf("׷");
            break;
        case 'g':
            printf("��");
            break;
        case 'x':
            printf("��");
            break;
        case 'n':
            printf("��");
            break;
        case 'h':
            printf("��");
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
    printf("������ħ������:");//B(ehnxgz)B
    scanf("%s",str);
    Push_Str(S,str);
    printf("����������Ϊ:\n");
    Trans(S,Q);
    Print_Queue(Q);
    return 0;

}
