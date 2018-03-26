#include<stdio.h>
#include"stack.h"
#include<string.h>

typedef ElemType OperandType;

OperandType Precede(OperandType a, OperandType b)
{
    //比较两个运算符的优先级
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
    //进行二元运算aΘb
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
    //判断c是否为运算符
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
    //算术表达式求值的算符优先算法。设OPTR和OPND分别为运算符栈和运算数栈，
    //OP为运算符集合。
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
        if(!In(c))//不是运算符则进栈
        {
            Push(OPND, c);
            c = getchar();
        }
        else
        {
            GetTop(OPTR, x);
            switch(Precede(x, c))
            {
            case '<'://栈顶元素优先权低
                Push(OPTR, c);
                c = getchar();
                break;
            case '='://脱括号并接受下一字符
                Pop(OPTR, x);
                c = getchar();
                break;
            case '>'://退栈并将运算结果入栈
                Pop(OPTR, theta);
                Pop(OPND, b);
                Pop(OPND, a );
                Push(OPND, OPerate(a, theta, b));
                break;
            default:
                printf("输入有误!");
                exit(0);
            }//switch
        }//else
    }//while
    GetTop(OPND, x);
    return x;
}//EvaluateExpression

int main()
{
    system("title 计算器");
    char ans;
    printf("请输入要计算的表达式:\n");
    ans = EvaluateExpression()-'0';
    printf("正在计算....请稍候....\n");
    system("pause");
    printf("%d", ans);
    return 0;
}
