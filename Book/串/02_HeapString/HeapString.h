#ifndef HEAPSTRING_H_INCLUDED
#define HEAPSTRING_H_INCLUDED

#include"../../../template.h"
#include<stdlib.h>

typedef struct
{
    char *ch;//若是非空串,则按串长分配存储区,否则ch为NULL
    int length;//串长度
}HString;

Status StrAssign(HString &T,char *s);
//生成一个其值等于chars的字符串常量

Status StrCopy(HString &T,HString S);
//由串S复制得到串T

Status StrEmpty(HString S);
//若串S为空串,则返回TRUE,否则返回FALSE

int  StrLength(HString S);
//返回S的元素个数,称为串的长度

Status ClearString(HString &S);
//将S清为空串

Status Concat(HString &T,HString S1,HString S2);
//用T返回由S1和S2联接而成的新串

Status SubString(HString &Sub,HString S,int pos,int len);
//1<=pos<=StrLength(S)且0<=Len<=StrLength(S)-pos+1
// 用Sub返回串S的第pos个字符起长度为len的子串

int Index(HString S,HString T,int pos);
//1<=pos<=StrLength(S)
//若主串S中存在和串T值相同的子串,则返回它在主串S中第pos个字符之后第一次出现的位置;否则函数值为0

Status Replace(HString &S,HString T,HString V);
//T是非空串
//用V替换主串S中出现的所有与T相等的不重叠的子串

Status StrInsert(HString &S,int pos,HString T);
//在串S的第pos个字符之前插入串T

Status StrDelete(HString &S,int pos,int len);
//从串S中删除第pos个字符起长度为len的子串

Status StrCompare(HString S,HString T);
//比较串S和T,如果相同则返回TRUE,否则返回FALSE

void Print(HString T);
//输出字符串T

#endif // HEAPSTRING_H_INCLUDED
