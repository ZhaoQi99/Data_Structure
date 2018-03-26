/*
Problem:串的顺序存储表示
Author:QiZhao
Data:2017-11-28
Description:严蔚敏版数据结构习习题集实习题
Copyright  2017 QiZhao. All rights reserved.
*/
#include"SequenceString.h"
#include<stdio.h>

Status StrAssign(SString &T,char *s)
{
    //生成一个其值等于chars的字符串常量
    int len=strlen(s);
    if(len>MAXSTRLEN)
        return ERROR;
    T[0]=len;
    int i;
    for(i=1;i<=len;i++)
        T[i]=s[i-1];
    return OK;
}

Status StrCopy(SString &T,SString S)
{
    //由串S复制得到串T
    int len=StrLength(S);
    T[0]=S[0];
    int i;
    for(i=1;i<=len;i++)
        T[i]=S[i];
    return OK ;
}

Status StrEmpty(SString S)
{
    //若串S为空串,则返回TRUE,否则返回FALSE
    int len=StrLength(S);
    if(len==0)
        return TRUE;
    else
        return FALSE;
}

int  StrLength(SString S)
{
    //返回S的元素个数,称为串的长度
    int temp=(int)S[0];
    return temp;
}

Status ClearString(SString &S)
{
    //将S清为空串
    S[0]=0;
    return OK;
}

Status Concat(SString &T, SString S1, SString S2)
{
    //用T返回由S1和S2联接而成的新串
    int i;
    Status uncut;
    if (S1[0] + S2[0] <= MAXSTRLEN)  // 未截断
    {
        for (i = 1; i <= S1[0]; i++) T[i] = S1[i];
        for (i = 1; i <= S2[0]; i++) T[i + S1[0]] = S2[i];
        T[0] = S1[0] + S2[0];
        uncut = TRUE;
    }
    else if (S1[0] < MAXSTRLEN)      // 截断
    {
        for (i = 1; i <= S1[0]; i++) T[i] = S1[i];
        for (i = S1[0] + 1; i <= MAXSTRLEN; i++) T[i] = S2[i - S1[0]];
        T[0] = MAXSTRLEN;
        uncut = FALSE;
    }
    else                             // 截断(仅取S1)
    {
        for (i = 0; i <= MAXSTRLEN; i++) T[i] = S1[i];
        uncut = FALSE;
    }
    return uncut;
}

Status SubString(SString &Sub, SString S, int pos, int len)
{
    //1<=pos<=StrLength(S)且0<=Len<=StrLength(S)-pos+1
    // 用Sub返回串S的第pos个字符起长度为len的子串
    int i;
    if (pos < 1 || pos > S[0] || len < 0 || len > S[0] - pos + 1)
        return ERROR;
    for(i = 1; i <= len; i++)
        Sub[i] = S[pos + i - 1];
    Sub[0] = len;
    return OK;
}

int Index(SString S, SString T, int pos=0)
{
    //1<=pos<=StrLength(S)
    //若主串S中存在和串T值相同的子串,则返回它在主串S中第pos个字符之后第一次出现的位置;否则函数值为0
    int n, m, i;
    SString sub;
    if (pos > 0)
    {
        n = StrLength(S);
        m = StrLength(T);
        i = pos;
        while (i <= n - m + 1)
        {
            SubString (sub, S, i, m);
            if (StrCompare(sub, T) == 0) ++i;
            else return i;
        }
    }
    return 0;
}

Status Replace(SString &S, SString T, SString V)
{
    //T是非空串
    //用V替换主串S中出现的所有与T相等的不重叠的子串
    int i = 1;
    int len = StrLength(T);
    while(i+len-1 <= StrLength(S))
    {
        SString temp;//存放子串
        SubString(temp, S, i, len);
        if(StrCompare(temp,T)==TRUE)
        {
            int j;
            StrDelete(S,i,len);
            if(i+StrLength(V)<=MAXSTRLEN)
                StrInsert(S,i,V);
            i+=StrLength(V);
        }
        else
            i++;
    }
    return OK;
}

Status StrInsert(SString &S,int pos,SString T)
{
    //在串S的第pos个字符之前插入串T
    int len=StrLength(T);
    if(StrLength(S)+StrLength(T)>MAXSTRLEN)
        return ERROR;
    int i;
    for(i=StrLength(S);i>=pos;i--)
        S[i+len]=S[i];
    for(i=1;i<=len;i++)
        S[pos+i-1]=T[i];
    S[0]+=len;
    return OK;
}

Status StrDelete(SString &S,int pos,int len)
{
    //从串S中删除第pos个字符起长度为len的子串
    int length=StrLength(S);
    if(pos+len>length)
        return ERROR;
    int i;
    for(i=pos+len;i<=length;i++)
        S[i-len]=S[i];
    S[0]-=len;
    return OK ;
}

Status StrCompare(SString S,SString T)
{
    //比较串S和T,如果相同则返回TRUE,否则返回FALSE
    int len1=StrLength(S);
    int len2=StrLength(T);
    if(len1!=len2)
        return FALSE;
    int i;
    for(i=1;i<=len1;i++)
    {
        if(S[i]==T[i])
            continue;
        else
            return FALSE;
    }
    return TRUE;
}

void Print(SString T)
{
    int len=StrLength(T);
    int i;
    printf("字符串为:");
    for(i=1;i<=len;i++)
        printf("%c",T[i]);
    printf("\n");
}

int main()
{
    char s[]="abcdefghijklmn";
    SString T;
    SString S;

    printf("*********************************StrAssign函数测试*********************************\n");
    if(StrAssign(T,s)==TRUE)
    {
        printf("字符串生成成功！\n");
        Print(T);
    }
    else
        printf("字符串生成失败");

    printf("*********************************StrEmpty函数测试*********************************\n");
    if(StrEmpty(T)==TRUE)
        printf("当前字符串为空！\n");
    else
        printf("当前字符串为非空！\n");

    printf("*********************************StrCopy函数测试*********************************\n");
    if(StrCopy(S,T)==TRUE)
    {
        printf("字符串复制成功！\n");
        Print(S);
    }
    else
        printf("字符串复制失败！\n");

    printf("*********************************StrCompare函数测试*********************************\n");
    if(StrCompare(S,T)==TRUE)
        printf("串S与串T相同！\n");
    else
        printf("串S与串T不相同！\n");

    printf("*********************************StrLength函数测试*********************************\n");
    printf("当前字符串的长度为:%d\n",StrLength(T));

    printf("*********************************Concat函数测试*********************************\n");
    printf("连接前的");Print(T);
    if(Concat(T,T,S)==TRUE)
        printf("字符串连接成功！\n");
    else
        printf("字符串连接失败！\n");
    printf("连接后的");Print(T);

    printf("*********************************SubString函数测试*********************************\n");
    if(SubString(S,T,3,6)==TRUE)
        printf("取子串成功！\n");
    else
        printf("取子串失败！\n");
    printf("当前字符串的第三个字符起长度为6的子串的");
    Print(S);

    printf("*********************************Index函数测试*********************************\n");
    int pos;
    pos=Index(T,S,1);
    if(pos!=0)
        printf("当前字符串中第1个字符之后存在与串S相同的子串,且其第一次出现的位置为：%d\n",pos);
    else
        printf("当前字符串中第1个字符之后不存在与串S相同的子串!\n");
    pos=Index(T,S,15);
    if(pos!=0)
        printf("当前字符串中第15个字符之后存在与串S相同的子串,且其第一次出现的位置为：%d\n",pos);
    else
        printf("当前字符串中第15个字符之后不存在与串S相同的子串!\n");

    printf("*********************************Replace函数测试*********************************\n");
    SString V;
    char temp[]="6666";
    StrAssign(V,temp);
    printf("被替换的");Print(S);
    printf("用来替换的");Print(V);
    printf("替换前的");Print(T);
    Replace(T,S,V);
    printf("替换后的");Print(T);

    printf("*********************************StrInsert函数测试*********************************\n");
    printf("插入的");Print(S);
    printf("插入前的");Print(T);
    if(StrInsert(T,1,S)==TRUE)
        printf("字符串插入成功！\n");
    else
        printf("字符串插入失败！\n");
    printf("插入后的");Print(T);

    printf("*********************************StrDelete函数测试*********************************\n");
    printf("删除前的");Print(T);
    if(StrDelete(T,3,10)==TRUE)
        printf("删除当前字符串第3个字符起长度为10的子串成功！\n");
    else
        printf("删除当前字符串第3个字符起长度为10的子串失败！\n");
    printf("删除后的");Print(T);

    printf("*********************************ClearString函数测试*********************************\n");
    if(StrEmpty(T)==TRUE)
        printf("当前字符串为空！\n");
    else
        printf("当前字符串为非空！\n");
    ClearString(T);
    printf("字符串清空成功！\n");
    if(StrEmpty(T)==TRUE)
        printf("当前字符串为空！\n");
    else
        printf("当前字符串为非空！\n");

    return 0;
}

