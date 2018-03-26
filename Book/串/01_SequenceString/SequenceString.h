#ifndef SEQUENCESTRING_H_INCLUDED
#define SEQUENCESTRING_H_INCLUDED

#include"../../../template.h"
#include<string.h>

#define MAXSTRLEN 255//�û�����255�����Զ�����󴮳�

typedef unsigned char SString[MAXSTRLEN+1];//0�ŵ�Ԫ��Ŵ��ĳ���

Status StrAssign(SString &T,char *s);
//����һ����ֵ����chars���ַ�������

Status StrCopy(SString &T,SString S);
//�ɴ�S���Ƶõ���T

Status StrEmpty(SString S);
//����SΪ�մ�,�򷵻�TRUE,���򷵻�FALSE

int  StrLength(SString S);
//����S��Ԫ�ظ���,��Ϊ���ĳ���

Status ClearString(SString &S);
//��S��Ϊ�մ�

Status Concat(SString &T,SString S1,SString S2);
//��T������S1��S2���Ӷ��ɵ��´�

Status SubString(SString &Sub,SString S,int pos,int len);
//1<=pos<=StrLength(S)��0<=Len<=StrLength(S)-pos+1
// ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�

int Index(SString S,SString T,int pos);
//1<=pos<=StrLength(S)
//������S�д��ںʹ�Tֵ��ͬ���Ӵ�,�򷵻���������S�е�pos���ַ�֮���һ�γ��ֵ�λ��;������ֵΪ0

Status Replace(SString &S,SString T,SString V);
//T�Ƿǿմ�
//��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ�

Status StrInsert(SString &S,int pos,SString T);
//�ڴ�S�ĵ�pos���ַ�֮ǰ���봮T

Status StrDelete(SString &S,int pos,int len);
//�Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�

Status StrCompare(SString S,SString T);
//�Ƚϴ�S��T,�����ͬ�򷵻�TRUE,���򷵻�FALSE

void Print(SString T);
//����ַ���T

#endif // SEQUENCESTRING_H_INCLUDED
