#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED


#include"../../../template.h"
#include"ExtenLinkedList.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>//�ṩtime��������,�����������������,ʹ��ͬʱ�����г���ʱ���ɵ���������Ӳ�ͬ
typedef LinkList polynomial;//�ô�ͷ�ڵ�����������ʾ����ʽ

void CreatPolyn(polynomial &p,int m);
//����m���ϵ����ָ��,������ʾһԪ����ʽ����������P

void DestroyPolyn(polynomial &p);
//����һԪ����ʽ

void PrintPolyn(polynomial p);
//��ӡ���һԪ����ʽP

int PolynLength(polynomial P);
//����һԪ����ʽP�е�����

void AddPolyn(polynomial &Pa,polynomial &Pb);
//��ɶ���ʽ�������,��:Pa=Pa+Pb,������һԪ����ʽPb

void SubtractPolyn(polynomial &Pa,polynomial &Pb);
//��ɶ���ʽ�������,��:Pa=Pa-Pb,������һԪ����ʽPb

void MultiplyPolyn(polynomial &Pa,polynomial &Pb);
//��ɶ���ʽ�������,��:Pa=Pa*Pb,������һԪ����ʽPb

Status LocateElem(LinkList L, ElemType e, Position &q,Status(* compare)(ElemType, ElemType));
//����������L�д�����e�����ж�����compare()ȡֵΪ0��Ԫ��,��qָʾL�е�һ��
//ֵΪe�Ľ���λ��,������TRUE;����ָʾ��һ����e�����ж�����compare()ȡ
//ֵΪ>0��Ԫ�ص�ǰ����λ��,������FALSE

Status OrderInsert(polynomial &L,ElemType e,Status(* compare)(ElemType, ElemType));
//�������ж�����compare()��Լ��,��ֵΪe�Ľ����뵽��������L���ʵ�λ����

int compare(term a,term b);
//��a��ָ��ֵ<(��=)(��>)b��ָ��ֵ,�ֱ𷵻�-1,0��+1

Status Derivation(polynomial Pa,polynomial &Pb);
//�����ʽPa�ĵ�����,����Pb����

void Test(polynomial& P1, polynomial& P2);
#endif // POLYNOMIAL_H_INCLUDED
