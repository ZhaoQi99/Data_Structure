#ifndef HEAPSTRING_H_INCLUDED
#define HEAPSTRING_H_INCLUDED

#include"../../../template.h"
#include<stdlib.h>

typedef struct
{
    char *ch;//���Ƿǿմ�,�򰴴�������洢��,����chΪNULL
    int length;//������
}HString;

Status StrAssign(HString &T,char *s);
//����һ����ֵ����chars���ַ�������

Status StrCopy(HString &T,HString S);
//�ɴ�S���Ƶõ���T

Status StrEmpty(HString S);
//����SΪ�մ�,�򷵻�TRUE,���򷵻�FALSE

int  StrLength(HString S);
//����S��Ԫ�ظ���,��Ϊ���ĳ���

Status ClearString(HString &S);
//��S��Ϊ�մ�

Status Concat(HString &T,HString S1,HString S2);
//��T������S1��S2���Ӷ��ɵ��´�

Status SubString(HString &Sub,HString S,int pos,int len);
//1<=pos<=StrLength(S)��0<=Len<=StrLength(S)-pos+1
// ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�

int Index(HString S,HString T,int pos);
//1<=pos<=StrLength(S)
//������S�д��ںʹ�Tֵ��ͬ���Ӵ�,�򷵻���������S�е�pos���ַ�֮���һ�γ��ֵ�λ��;������ֵΪ0

Status Replace(HString &S,HString T,HString V);
//T�Ƿǿմ�
//��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ�

Status StrInsert(HString &S,int pos,HString T);
//�ڴ�S�ĵ�pos���ַ�֮ǰ���봮T

Status StrDelete(HString &S,int pos,int len);
//�Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�

Status StrCompare(HString S,HString T);
//�Ƚϴ�S��T,�����ͬ�򷵻�TRUE,���򷵻�FALSE

void Print(HString T);
//����ַ���T

#endif // HEAPSTRING_H_INCLUDED
