#ifndef DULINKLIST_H_INCLUDED
#define DULINKLIST_H_INCLUDED

#include"../../../template.h"
typedef int ElemType;
typedef struct DuLNode
{
    ElemType data;
    struct DuLNode* prior;
    struct DuLNode* next;
}DuLNode,*DuLinkList;

Status InitList_DuL(DuLinkList &L);
//构造一个空的双向链表L

Status ClearList_DuL(DuLinkList &L);
//将L重置为空表

Status DestroyList_DuL(DuLinkList &L);
//销毁线性表L

int ListEmpty_DuL(DuLinkList L);
//若L为空表,则返回TRUE,否则返回FALSE

int ListLength_DuL(DuLinkList L);
//返回双向链表L中数据元素个数

DuLinkList GetElem_DuL(DuLinkList L, int i);
// L为带头结点的双向链表的头指针。
// 当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR

int LocateElem(DuLinkList L, ElemType e, Status (*compare)(ElemType, ElemType));
// 在双向链表L中查找第1个值与e满足compare()的元素的位序。
// 若找到，则返回其在L中的位序，否则返回0。

Status PriorElem(DuLinkList L, ElemType cur_e, ElemType & pre_e);
//若cur_e是L的数据元素,且不是第一个,则用pre_e返回它的前驱,否则操作失败,pre_e无定义

Status NextELem(DuLinkList L, ElemType cur_e, ElemType & next_e);
//若cur_e是L的数据元素,且不是最后一个,则用next_e返回它的后继,否则操作失败,next_e无定义

Status ListInsert_DuL(DuLinkList & L, int i, ElemType e);
// 在带头结点的双向线性表L的第i个元素之前插入元素e

Status ListDelete_L(DuLinkList & L, int i, ElemType & e);
// 在带头结点的双向线性表L中，删除第i个元素，并由e返回其值

Status ListTraverse(DuLinkList L, Status (*visit)(ElemType));
//依次对L的每个数据元素调用函数visit().一旦visit()失败，则操作失败

Status visit(ElemType e);

Status compare(ElemType a, ElemType b);

#endif // DULINKLIST_H_INCLUDED
