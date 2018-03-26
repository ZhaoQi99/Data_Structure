/*
Problem:串的堆存储表示
Author:QiZhao
Data:2018-01-31
Description:严蔚敏版数据结构课本源码
Copyright  2018 QiZhao. All rights reserved.
*/
#include<stdio.h>
#include"HeapString.h"

Status StrAssign(HString &T,char *s)
{
    //生成一个其值等于chars的字符串常量
    if(T.ch)
        free(T.ch);//释放T原有空间
    int i;
    char *c;
    for(i=0,c=s;*c;++i,++c);//求s的长度i
    if(!i)
    {
        T.ch=NULL;
        T.length=0;
    }
    else
    {
        if(!(T.ch=(char*)malloc(sizeof(char)*i)))
            exit(OVERFLOW);
        int j;
        for(j=0;j<i;j++)
            T.ch[j]=s[j];
        T.length=i;
    }
    return OK;
}

Status StrCopy(HString &T,HString S)
{
    //由串S复制得到串T
    if(T.ch)
        free(T.ch);
    T.ch=(char *)malloc(S.length*sizeof(char));
    int i;
    int len=S.length;
    for(i=0;i<len;i++)
        T.ch[i]=S.ch[i];
    T.length=S.length;
    return OK;
}

Status StrEmpty(HString S)
{
    //若串S为空串,则返回TRUE,否则返回FALSE
    if(S.length==0)
        return TRUE;
    else
        return FALSE;
}

int  StrLength(HString S)
{
    //返回S的元素个数,称为串的长度
    return S.length;
}

Status ClearString(HString &S)
{
    //将S清为空串
    if(S.ch)
    {
        free(S.ch);
        S.ch=NULL;
    }
    S.length=0;
    return OK;
}

Status Concat(HString &T,HString S1,HString S2)
{
    //用T返回由S1和S2联接而成的新串
    //若取加串之一作为新串,则会出现问题.如：Concat(T,T,S)
    if(T.ch)
        free(T.ch);//释放旧空间
    if(!(T.ch=(char*)malloc((S1.length+S2.length)*sizeof(char))))
        exit(OVERFLOW);
    int i;
    for(i=0;i<S1.length;i++)
        T.ch[i]=S1.ch[i];
    T.length=S1.length+S2.length;
    for(i=S1.length;i<T.length;i++)
        T.ch[i]=S2.ch[i-S1.length];
    return OK;
}

Status SubString(HString &Sub,HString S,int pos,int len)
{
    //1<=pos<=StrLength(S)且0<=Len<=StrLength(S)-pos+1
    // 用Sub返回串S的第pos个字符起长度为len的子串
    if(pos<1||pos>S.length||len<0||len>S.length-pos+1)
        return ERROR;
    if(Sub.ch)
        free(Sub.ch);
    int i;
    if(!len)
    {
        Sub.ch=NULL;
        Sub.length=0;
    }
    else
    {
        Sub.ch=(char*)malloc(sizeof(char)*len);
        for(i=0;i<len;i++)
            Sub.ch[i]=S.ch[pos+i-1];
        Sub.length=len;
    }
    return OK;
}

int Index(HString S,HString T,int pos)
{
    //1<=pos<=StrLength(S)
    //若主串S中存在和串T值相同的子串,则返回它在主串S中第pos个字符之后第一次出现的位置;否则函数值为0
    int i=pos-1,j=0;
    while(i<S.length&&j<T.length)
    {
        if(S.ch[i]==T.ch[j])//继续比较后继字符
        {
            ++i;
            ++j;
        }
        else//指针后退重新开始匹配
        {
            i=i-j+1 ;
            j=0;
        }
    }
    if(j==T.length)
        return i-T.length+1;
    else
        return 0;
}

Status Replace(HString &S, HString T, HString V)
{
    //T是非空串
    //用V替换主串S中出现的所有与T相等的不重叠的子串
    int pos = Index(S, T, 1);
    int i, j;
    if(pos == 0) //S中没有出现与T相等的子串
        return ERROR;
    else
    {
        int temp=1;
        while(pos = Index(S, T, temp))
        {
            if(StrDelete(S, pos, T.length) == ERROR)
                return ERROR;
            if(StrInsert(S, pos, V) == ERROR)
                return ERROR;
            temp=pos+V.length;
        }
    }
    return OK;
}

Status StrInsert(HString &S,int pos,HString T)
{
    //在串S的第pos个字符之前插入串T
    if(pos<=0||pos>S.length)
        return ERROR;
    S.ch=(char *)realloc(S.ch,sizeof(char)*(S.length+T.length));
    if(!S.ch)
        return ERROR;//内存申请失败
    int i,j;
    for(i=S.length+T.length-1,j=S.length-1;j>=pos-1;i--,j--)//将串S的第pos个字符后的所有字符后移
        S.ch[i]=S.ch[j];
    for(i=pos-1,j=0;j<T.length;i++,j++)//插入串T
        S.ch[i]=T.ch[j];
    S.length+=T.length;
    return OK;
}

Status StrDelete(HString &S,int pos,int len)
{
    //从串S中删除第pos个字符起长度为len的子串
    int i;
    if(pos<0||pos>S.length||pos+len>S.length)//参数不合法
        return ERROR;
    for(i=pos-1;i+len<S.length;i++)
        S.ch[i]=S.ch[i+len];
    S.length-=len;
    return OK;
}

Status StrCompare(HString S,HString T)
{
    //比较串S和T,如果相同则返回TRUE,否则返回FALSE
    int i;
    for(i=0;i<S.length&&i<T.length;++i)
    {
        if(S.ch[i]!=T.ch[i])
            return S.ch[i]-T.ch[i];
    }
    return S.length-T.length;
}

void Print(HString T)
{
    //输出字符串T
    int len=T.length;
    int i;
    for(i=0;i<len;i++)
        printf("%c ",T.ch[i]);
    printf("\n");
}

int main()
{
    HString T;
    HString S;
    HString Sub;
    char *s="ABCDEFGHIJKLMN";

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
    if(StrCompare(S,T)==0)
        printf("串S与串T相同！\n");
    else
        printf("串S与串T不相同！\n");

    printf("*********************************StrLength函数测试*********************************\n");
    printf("当前字符串的长度为:%d\n",StrLength(T));

    printf("*********************************Concat函数测试*********************************\n");
    printf("连接前的");Print(T);
    if(Concat(T,S,S)==TRUE)
        printf("字符串连接成功！\n");
    else
        printf("字符串连接失败！\n");
    printf("连接后的");Print(T);

    printf("*********************************SubString函数测试*********************************\n");
    if(SubString(Sub,T,3,6)==TRUE)
        printf("取子串成功！\n");
    else
        printf("取子串失败！\n");
    printf("当前字符串的第三个字符起长度为6的子串的");
    Print(Sub);

    printf("*********************************Index函数测试*********************************\n");
    int pos;
    pos=Index(T,Sub,1);
    if(pos!=0)
        printf("当前字符串中第1个字符之后存在与串Sub相同的子串,且其第一次出现的位置为：%d\n",pos);
    else
        printf("当前字符串中第1个字符之后不存在与串Sub相同的子串!\n");
    pos=Index(T,Sub,18);
    if(pos!=0)
        printf("当前字符串中第18个字符之后存在与串Sub相同的子串,且其第一次出现的位置为：%d\n",pos);
    else
        printf("当前字符串中第18个字符之后不存在与串Sub相同的子串!\n");

    printf("*********************************Replace函数测试*********************************\n");
    HString V;
    char temp[]="6666";
    StrAssign(V,temp);
    printf("被替换的");Print(Sub);
    printf("用来替换的");Print(V);
    printf("替换前的");Print(T);
    Replace(T,Sub,V);
    printf("替换后的");Print(T);

    printf("*********************************StrInsert函数测试*********************************\n");
    printf("插入的");Print(S);
    printf("插入前的");Print(T);
    if(StrInsert(T,3,S)==TRUE)
        printf("字符串插入成功！\n");
    else
        printf("字符串插入失败！\n");
    printf("在第三个字符后插入后");Print(T);

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

