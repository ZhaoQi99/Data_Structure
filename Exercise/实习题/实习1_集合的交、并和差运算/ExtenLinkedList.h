#ifndef EXTENLINKEDLIST_H_INCLUDED
#define EXTENLINKEDLIST_H_INCLUDED

#include"../../../template.h"

typedef char ElemType;
typedef struct LNode
{
    //结点类型
    ElemType data;
    struct LNode* next;
}*Link,*Position;
typedef struct
{
    //链表类型
    Link head,tail;//分别指向线性链表中的头结点和最后一个结点
    int len;//指示线性链表中数据元素的个数
}LinkList;

Status MakeNode(Link &p,ElemType e);
//分配由p指向值为e的结点，并返回OK；若返回失败,则返回ERROR

void FreeNode(Link &p);
//释放p所指结点

Status InitList(LinkList &L);
// 构造一个空的线性表L。

Status DestroyList(LinkList & L);
//销毁线性表L,L不再存在

Status ClearList(LinkList & L);
//将L重置为空表,并释放原链表的结点空间

Status InsFirst(LinkList &L,Link h,Link s);
//已知h指向线性链表的头结点,将s所指结点插入在第一个结点之前

Status DelFirst(LinkList &L,Link h,Link &q);
//已知h指向线性链表的头结点,删除链表中第一个结点并以q返回

Status Append(LinkList &L,Link s);
//将指针s所指(彼此以指针相链)的一串结点链接在线性链表L的最后一个结点
//之后,并改变链表L的尾指针指向新的尾结点

Status Remove(LinkList &L,Link &q);
//删除线性链表L中的尾结点并以q返回,改变链表L的尾指针指向新的尾结点

Status InsBefore(LinkList &L,Link &p,Link s);
//已知p指向线性链表L中的一个结点,将s所指结点插入在p所指结点之前,
//并修改指针p指向新插入的结点

Status InsAfter(LinkList &L,Link &p,Link s);
//已知p指向线性链表L中的一个结点,将s所指结点插入在p所指结点之后,
//并修改指针p指向新插入的结点

Status SetCurElem(Link &p,ElemType e);
//已知p指向线性链表中的一个结点,用e更新p所指结点中数据元素的值

ElemType GetCurElem(Link p);
//已知p指向线性链表中的一个结点,返回p所指结点中数据元素的值

Status ListEmpty(LinkList L);
//若L为空表,则返回TRUE,否则返回FALSE

int ListLength(LinkList L);
//返回L中数据元素个数

Position GetHead(LinkList L);
//返回线性表L中头结点的位置

Position GetLast(LinkList L);
//返回线性表L中最后一个结点的位置

Position PriorPos(LinkList L,Link p);
//已知p指向线性链表L中的一个结点,返回p所指结点的直接前驱的位置,
//若无前驱,则返回NULL

Position NextPos(LinkList L,Link p);
//已知p指向线性链表L中的一个结点,返回p所指结点的直接后继的位置,
//若无后继,则返回NULL

Status LocatePos(LinkList L,int i,Link &p);
//返回p指示线性链表L中第i个结点的位置,并返回OK,i值不合法时返回ERROR

Position LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType));
// 在链式线性表L中查找第1个值与e满足compare()的元素的位置
// 若不存在这样的元素,则返回NULL

Status ListTraverse(LinkList L, Status (*visit)(ElemType));
//依次对L的每个数据元素调用函数visit().一旦visit()失败，则操作失败

Status ListInsert(LinkList &L, int i, ElemType e);
 // 在带头结点的扩展的单链线性表L的第i个元素之前插入元素e

Status visit(ElemType e);

//Status compare(ElemType a, ElemType b);

#endif // EXTENLINKEDLIST_H_INCLUDED
