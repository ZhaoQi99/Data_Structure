#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED


#include"../../../template.h"
#include"ExtenLinkedList.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>//提供time（）函数,用以设置随机数种子,使不同时间运行程序时生成的随机数种子不同
typedef LinkList polynomial;//用带头节点的有序链表表示多项式

void CreatPolyn(polynomial &p,int m);
//输入m项的系数和指数,建立表示一元多项式的有序链表P

void DestroyPolyn(polynomial &p);
//销毁一元多项式

void PrintPolyn(polynomial p);
//打印输出一元多项式P

int PolynLength(polynomial P);
//返回一元多项式P中的项数

void AddPolyn(polynomial &Pa,polynomial &Pb);
//完成多项式相加运算,即:Pa=Pa+Pb,并销毁一元多项式Pb

void SubtractPolyn(polynomial &Pa,polynomial &Pb);
//完成多项式相减运算,即:Pa=Pa-Pb,并销毁一元多项式Pb

void MultiplyPolyn(polynomial &Pa,polynomial &Pb);
//完成多项式相乘运算,即:Pa=Pa*Pb,并销毁一元多项式Pb

Status LocateElem(LinkList L, ElemType e, Position &q,Status(* compare)(ElemType, ElemType));
//若有序链表L中存在与e满足判定函数compare()取值为0的元素,则q指示L中第一个
//值为e的结点的位置,并返回TRUE;否则指示第一个与e满足判定函数compare()取
//值为>0的元素的前驱的位置,并返回FALSE

Status OrderInsert(polynomial &L,ElemType e,Status(* compare)(ElemType, ElemType));
//按有序判定函数compare()的约定,将值为e的结点插入到有序链表L的适当位置上

int compare(term a,term b);
//依a的指数值<(或=)(或>)b的指数值,分别返回-1,0和+1

Status Derivation(polynomial Pa,polynomial &Pb);
//求多项式Pa的导函数,并以Pb返回

void Test(polynomial& P1, polynomial& P2);
#endif // POLYNOMIAL_H_INCLUDED
