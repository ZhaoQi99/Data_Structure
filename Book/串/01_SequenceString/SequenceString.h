#ifndef SEQUENCESTRING_H_INCLUDED
#define SEQUENCESTRING_H_INCLUDED

#include"../../../template.h"
#include<string.h>

#define MAXSTRLEN 255//用户可在255以内自定义最大串长

typedef unsigned char SString[MAXSTRLEN+1];//0号单元存放串的长度

Status StrAssign(SString &T,char *s);
//生成一个其值等于chars的字符串常量

Status StrCopy(SString &T,SString S);
//由串S复制得到串T

Status StrEmpty(SString S);
//若串S为空串,则返回TRUE,否则返回FALSE

int  StrLength(SString S);
//返回S的元素个数,称为串的长度

Status ClearString(SString &S);
//将S清为空串

Status Concat(SString &T,SString S1,SString S2);
//用T返回由S1和S2联接而成的新串

Status SubString(SString &Sub,SString S,int pos,int len);
//1<=pos<=StrLength(S)且0<=Len<=StrLength(S)-pos+1
// 用Sub返回串S的第pos个字符起长度为len的子串

int Index(SString S,SString T,int pos);
//1<=pos<=StrLength(S)
//若主串S中存在和串T值相同的子串,则返回它在主串S中第pos个字符之后第一次出现的位置;否则函数值为0

Status Replace(SString &S,SString T,SString V);
//T是非空串
//用V替换主串S中出现的所有与T相等的不重叠的子串

Status StrInsert(SString &S,int pos,SString T);
//在串S的第pos个字符之前插入串T

Status StrDelete(SString &S,int pos,int len);
//从串S中删除第pos个字符起长度为len的子串

Status StrCompare(SString S,SString T);
//比较串S和T,如果相同则返回TRUE,否则返回FALSE

void Print(SString T);
//输出字符串T

#endif // SEQUENCESTRING_H_INCLUDED
