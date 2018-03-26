#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

#include"ExtenLinkedList.h"
#include<stdlib.h>
#include<stdio.h>

typedef LinkList Set;

Status CreateSet(Set &T,char *s);
//生成一个由Str中小写字母构成的集合T

Status DestroySet(Set &T);
//销毁集合T的结构

Status Union(Set &T,Set S1,Set S2);
//生成一个由S1和集合S2的并集构成的集合T

Status Intersection(Set &T,Set S1,Set S2);
//生成一个由S1和S2的交集构成的集合T

Status Different(Set &T,Set S1,Set S2);
//生成一个由S1和S2的差集构成的集合T

Status Xor(Set &T,Set S1,Set S2);
//生成一个由S1和S2的异或构成的集合

void PrintSet(Set T);
//按字母次序顺序显示集合T的全部元素

Status LocateElem(LinkList L, ElemType e, Position &q,Status(* compare)(ElemType, ElemType));
//若有序链表L中存在与e满足判定函数compare()取值为0的元素,则q指示L中第一个
//值为e的结点的位置,并返回TRUE;否则指示第一个与e满足判定函数compare()取
//值为>0的元素的前驱的位置,并返回FALSE

Status visit(ElemType e);

Status compare(ElemType a,ElemType b);


#endif // SET_H_INCLUDED
