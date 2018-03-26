#include<stdio.h>
#include"stack.h"
#include<string.h>

typedef ElemType OperandType;

OperandType Precede(OperandType a, OperandType b)
{
    //�Ƚ���������������ȼ�
    if(a == ')' && b == '(')
        return '0';
    if(a == '+' || a == '-')
    {
        if(b == '+' || b == '-' || b == ')' || b == '#')
            return '>';
        else
            return '<';
    }
    if(a == '*' || a == '/')
    {
        if(b == '(')
            return '<';
        else
            return '>';
    }
    if(a == '(')
    {
        if(b == ')')
            return '=';
        else
            return '<';
    }
    if(a == '#')
    {
        if(b == '#')
            return '=';
        else
            return '<';
    }
    return '>';
}

OperandType OPerate(OperandType a, OperandType theta, OperandType b)
{
    //���ж�Ԫ����a��b
    int c, d;
    char cans;
    int ans;
    c = (int)(a - '0');
    d = (int)(b - '0');
    switch(theta)
    {
    case '+':
        ans = c + d;
        break;
    case '-':
        ans = c - d;
        break;
    case '*':
        ans = c * d;
        break;
    case '/':
        ans = c / d;
        break;
    }
    cans = (char)(ans + '0');
    return cans;
}

Status In(OperandType c)
{
    //�ж�c�Ƿ�Ϊ�����
    char str[] = "<>+-*/()#";
    int i;
    for(i = 0; i < 9; i++)
    {
        if(str[i] == c)
            return 1;
    }
    return 0;
}

OperandType EvaluateExpression()
{
    //�������ʽ��ֵ����������㷨����OPTR��OPND�ֱ�Ϊ�����ջ��������ջ��
    //OPΪ��������ϡ�
    SqStack OPTR, OPND;
    OperandType c, x, theta, a, b;
    InitList(OPTR);
    InitList(OPND);
    Push(OPTR, '#');
    c = getchar();
    while(c != '#' || (GetTop(OPTR, x) && x != '#'))
    {
        if(c=='\n')
            c='#';
        if(!In(c))//������������ջ
        {
            Push(OPND, c);
            c = getchar();
        }
        else
        {
            GetTop(OPTR, x);
            switch(Precede(x, c))
            {
            case '<'://ջ��Ԫ������Ȩ��
                Push(OPTR, c);
                c = getchar();
                break;
            case '='://�����Ų�������һ�ַ�
                Pop(OPTR, x);
                c = getchar();
                break;
            case '>'://��ջ������������ջ
                Pop(OPTR, theta);
                Pop(OPND, b);
                Pop(OPND, a );
                Push(OPND, OPerate(a, theta, b));
                break;
            default:
                printf("��������!");
                exit(0);
            }//switch
        }//else
    }//while
    GetTop(OPND, x);
    return x;
}//EvaluateExpression

int main()
{
    system("title ������");
    char ans;
    printf("������Ҫ����ı��ʽ:\n");
    ans = EvaluateExpression()-'0';
    printf("���ڼ���....���Ժ�....\n");
    system("pause");
    printf("%d", ans);
    return 0;
}
