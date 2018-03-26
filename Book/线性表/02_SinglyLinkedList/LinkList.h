#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include<stdio.h>
#include"../../../template.h"
#include<stdlib.h>
#include<math.h>

typedef  int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

Status InitList(LinkList &L);
// 构造一个空的线性表L。

Status DestroyList(LinkList & L);
//销毁线性表L

Status ClearList(LinkList & L);
//将L重置为空表

int ListEmpty(LinkList L);
//若L为空表,则返回TRUE,否则返回FALSE

int ListLength(LinkList L);
//返回L中数据元素个数

Status GetElem_L(LinkList & L, int i, ElemType & e);
// L为带头结点的单链表的头指针。
// 当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR

int LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType));
// 在链式线性表L中查找第1个值与e满足compare()的元素的位序。
// 若找到，则返回其在L中的位序，否则返回0。

Status PriorElem(LinkList L, ElemType cur_e, ElemType & pre_e);
//若cur_e是L的数据元素,且不是第一个,则用pre_e返回它的前驱,否则操作失败,pre_e无定义

Status NextELem(LinkList L, ElemType cur_e, ElemType & next_e);
//若cur_e是L的数据元素,且不是最后一个,则用next_e返回它的后继,否则操作失败,next_e无定义

Status ListInsert_L(LinkList & L, int i, ElemType e);
// 在带头结点的单链线性表L的第i个元素之前插入元素e

Status ListDelete_L(LinkList & L, int i, ElemType & e);
// 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值

Status ListTraverse(LinkList L, Status (*visit)(ElemType));
//依次对L的每个数据元素调用函数visit().一旦visit()失败，则操作失败

void CreateList_L(LinkList & L, int n);
// 逆位序输入（随机产生）n个元素的值，建立带表头结点的单链线性表L

void MergeList_L(LinkList & La, LinkList & Lb, LinkList & Lc);
// 已知单链线性表La和Lb的元素按值非递减排列。
// 归并La和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列。

Status visit(ElemType e);

Status compare(ElemType a, ElemType b);

#endif // LINKLIST_H_INCLUDED
