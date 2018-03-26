#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED

#include<stdio.h>
#include"../../../template.h"
#include<stdlib.h>
#include<stdio.h>

#define LIST_INIT_SIZE 100//线性表存储空间的初始分配量
#define LISTINCREMENT 10//线性表存储空间的分配增量

typedef  int ElemType;
typedef struct
{
    ElemType *elem;//存储空间基址
    int length;//当前长度
    int listsize;//当前分配的存储容量,以sizeof(EleType)为单位
} SqList;

Status InitList(SqList &L);
// 构造一个空的线性表L。

Status DestroyList(SqList &L);
//销毁线性表L

Status ClearList(SqList & L);
//将L重置为空表

int ListEmpty(SqList L);
//若L为空表,则返回TRUE,否则返回FALSE

int ListLength(SqList L);
//返回L中数据元素个数

Status GetElem(SqList L, int i, ElemType & e);
//用e返回L中第i个元素的值

int LocateElem(SqList L, ElemType e, Status (*compare)(ElemType, ElemType));
// 在顺序线性表L中查找第1个值与e满足compare();的元素的位序。
// 若找到，则返回其在L中的位序，否则返回0。

Status PriorElem(SqList L, ElemType cur_e, ElemType & pre_e);
//若cur_e是L的数据元素,且不是第一个,则用pre_e返回它的前驱,否则操作失败,pre_e无定义

Status NextELem(SqList L, ElemType cur_e, ElemType & next_e);
//若cur_e是L的数据元素,且不是最后一个,则用next_e返回它的后继,否则操作失败,next_e无定义

Status ListInsert(SqList & L, int i, ElemType e);
// 在顺序线性表L的第i个元素之前插入新的元素e，
// i的合法值为1≤i≤ListLength_Sq(L)+1

Status ListDelete(SqList & L, int i, ElemType & e);
// 在顺序线性表L中删除第i个元素，并用e返回其值。
// i的合法值为1≤i≤ListLength_Sq(L)。

Status visit(ElemType e);

Status compare(ElemType a, ElemType b);

Status ListTraverse(SqList L, Status (*visit)(ElemType));
//依次对L的每个数据元素调用函数visit().一旦visit()失败，则操作失败

void MergeList_Sq(SqList La, SqList Lb, SqList & Lc);
// 已知顺序线性表La和Lb的元素按值非递减排列。
// 归并La和Lb得到新的顺序线性表Lc，Lc的元素也按值非递减排列。

#endif // SQLIST_H_INCLUDED
