#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

#include"ExtenLinkedList.h"
#include<stdlib.h>
#include<stdio.h>

typedef LinkList Set;

Status CreateSet(Set &T,char *s);
//����һ����Str��Сд��ĸ���ɵļ���T

Status DestroySet(Set &T);
//���ټ���T�Ľṹ

Status Union(Set &T,Set S1,Set S2);
//����һ����S1�ͼ���S2�Ĳ������ɵļ���T

Status Intersection(Set &T,Set S1,Set S2);
//����һ����S1��S2�Ľ������ɵļ���T

Status Different(Set &T,Set S1,Set S2);
//����һ����S1��S2�Ĳ���ɵļ���T

Status Xor(Set &T,Set S1,Set S2);
//����һ����S1��S2����򹹳ɵļ���

void PrintSet(Set T);
//����ĸ����˳����ʾ����T��ȫ��Ԫ��

Status LocateElem(LinkList L, ElemType e, Position &q,Status(* compare)(ElemType, ElemType));
//����������L�д�����e�����ж�����compare()ȡֵΪ0��Ԫ��,��qָʾL�е�һ��
//ֵΪe�Ľ���λ��,������TRUE;����ָʾ��һ����e�����ж�����compare()ȡ
//ֵΪ>0��Ԫ�ص�ǰ����λ��,������FALSE

Status visit(ElemType e);

Status compare(ElemType a,ElemType b);


#endif // SET_H_INCLUDED
