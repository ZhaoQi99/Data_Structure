/*
Problem:线性表的顺序实现
Author:QiZhao
Data:2017-09-26
Description:严蔚敏版数据结构课本源码
Copyright  2017 QiZhao. All rights reserved.
*/

#include"SqList.h"

Status InitList(SqList &L)
{
    // 构造一个空的线性表L。
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) return ERROR;        // 存储分配失败
    L.length = 0;                  // 空表长度为0
    L.listsize = LIST_INIT_SIZE;   // 初始存储容量
    return OK;
} // InitList

Status DestroyList(SqList &L)
{
    //销毁线性表L
    ElemType *p = L.elem;
    free(p);
    L.elem = NULL; //置空指针
    L.length = 0;
    L.listsize = 0;
    return OK;
}//DestroyList

Status ClearList(SqList &L)
{
    //将L重置为空表
    L.length = 0;
}//ClearList

int ListEmpty(SqList L)
{
    //若L为空表,则返回TRUE,否则返回FALSE
    return L.length == 0 ? TRUE : FALSE;
}//ListEmpty

int ListLength(SqList L)
{
    //返回L中数据元素个数
    return L.length;
}//ListLength

Status GetElem(SqList L, int i, ElemType &e)
{
    //用e返回L中第i个元素的值
    if(i < 1 || i > L.length)
        return ERROR;
    e = L.elem[i - 1];
    return OK;
}//GetElem

int LocateElem(SqList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
    // 在顺序线性表L中查找第1个值与e满足compare()的元素的位序。
    // 若找到，则返回其在L中的位序，否则返回0。
    int i;
    ElemType *p;
    i = 1;        // i的初值为第1个元素的位序
    p = L.elem;   // p的初值为第1个元素的存储位置
    while (i <= L.length && !(*compare)(*p++, e))
        ++i;
    if (i <= L.length) return i;
    else return 0;
} // LocateElem

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
    //若cur_e是L的数据元素,且不是第一个,则用pre_e返回它的前驱,否则操作失败,pre_e无定义
    if(L.elem[0] != cur_e) //第一个节点无前驱
    {
        int i = 1;
        while(L.elem[i] != cur_e)
            i++;
        pre_e = L.elem[i - 1];
        return OK;
    }
    return ERROR;
}//PriorElem

Status NextELem(SqList L, ElemType cur_e, ElemType &next_e)
{
    //若cur_e是L的数据元素,且不是最后一个,则用next_e返回它的后继,否则操作失败,next_e无定义
    int i = 0;
    while(L.elem[i] != cur_e)
        i++;
    if(i < L.length - 1) //最后一个节点没有后继
    {
        next_e = L.elem[i + 1];
        return OK;
    }
    return ERROR;
}//NextELem

Status ListInsert(SqList &L, int i, ElemType e)
{
    // 在顺序线性表L的第i个元素之前插入新的元素e，
    // i的合法值为1≤i≤ListLength_Sq(L)+1
    ElemType *p;
    if (i < 1 || i > L.length + 1) return ERROR; // i值不合法
    if (L.length >= L.listsize)     // 当前存储空间已满，增加容量
    {
        ElemType *newbase = (ElemType *)realloc(L.elem,
                                                (L.listsize + LISTINCREMENT) * sizeof (ElemType));
        if (!newbase) return ERROR;   // 存储分配失败
        L.elem = newbase;             // 新基址
        L.listsize += LISTINCREMENT;  // 增加存储容量
    }
    ElemType *q = &(L.elem[i - 1]); // q为插入位置
    for (p = &(L.elem[L.length - 1]); p >= q; --p)// 插入位置及之后的元素右移
        *(p + 1) = *p;
    *q = e;       // 插入e
    ++L.length;   // 表长增1
    return OK;
} // ListInsert

Status ListDelete(SqList &L, int i, ElemType &e)
{
    // 在顺序线性表L中删除第i个元素，并用e返回其值。
    // i的合法值为1≤i≤ListLength_Sq(L)。
    ElemType *p, *q;
    if (i < 1 || i > L.length) return ERROR; // i值不合法
    p = &(L.elem[i - 1]);                 // p为被删除元素的位置
    e = *p;                               // 被删除元素的值赋给e
    q = L.elem + L.length - 1;            // 表尾元素的位置
    for (++p; p <= q; ++p) *(p - 1) = *p; // 被删除元素之后的元素左移
    --L.length;                           // 表长减1
    return OK;
} // ListDelete

Status visit(ElemType e)
{
    printf("%d、",e);
    return OK;
}//visit

Status compare(ElemType a,ElemType b)
{
    return a>b?TRUE:FALSE;
}//compare

Status ListTraverse(SqList L, Status (*visit)(ElemType))
{
    //依次对L的每个数据元素调用函数visit().一旦visit()失败，则操作失败
    int i;
    for(i = 0; i < L.length; i++)
    {
        if(!visit(L.elem[i]))
            return ERROR;
    }
    return OK;
}//ListTraverse

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc)
{
    // 已知顺序线性表La和Lb的元素按值非递减排列。
    // 归并La和Lb得到新的顺序线性表Lc，Lc的元素也按值非递减排列。
    ElemType *pa, *pb, *pc, *pa_last, *pb_last;
    pa = La.elem;
    pb = Lb.elem;
    Lc.listsize = Lc.length = La.length + Lb.length;
    pc = Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
    if (!Lc.elem)
        exit(OVERFLOW);   // 存储分配失败
    pa_last = La.elem + La.length - 1;
    pb_last = Lb.elem + Lb.length - 1;
    while (pa <= pa_last && pb <= pb_last)    // 归并
    {
        if (*pa <= *pb) *pc++ = *pa++;
        else *pc++ = *pb++;
    }
    while (pa <= pa_last) *pc++ = *pa++;      // 插入La的剩余元素
    while (pb <= pb_last) *pc++ = *pb++;      // 插入Lb的剩余元素
} // MergeList

int main()
{
    /******************************************************Test**********************************************************/
    SqList L;
    int i;
    ElemType e;

    printf("*********************************函数InitList测试*********************************\n");
    InitList(L)?printf("初始化顺序表成功\n"):printf("初始化顺序表失败\n");

    printf("*********************************函数ListEmpty测试*********************************\n");
    ListEmpty(L)?printf("顺序表L为空\n"):printf("顺序表L不为空\n");

    printf("*********************************函数ListInsert测试*********************************\n");
    for(i = 1; i <= 15; i++) //插入15个数据元素
    {
        e=rand()%300;//随机生成0~399的数
                    //实际为41、167、34、100、269、124、78、258、262、164、5、245、181、27、61
        printf("在第%d个位置插入\"%d\"\n",i,e);
        ListInsert(L, i , e);
    }

    printf("*********************************函数ListTraverse测试*********************************\n");
    printf("顺序表L中元素 = ");
    ListTraverse(L, visit);
    printf("\n");

    printf("*********************************函数ListDelete测试*********************************\n");
    ListDelete(L,6,e);
    printf("删除顺序表L中第6个元素:\"%d\"\n",e);
    ListTraverse(L,visit);
    printf("\n");

    printf("*********************************函数ListLength测试*********************************\n");
    printf("顺序表L的长度为:length = %d\n",ListLength(L));

    printf("*********************************函数GetElem测试*********************************\n");
    GetElem(L,5,e);
    printf("顺序表L中第五个位置的元素为%d\n",e);

    printf("*********************************函数LocateElem测试*********************************\n");
    i=LocateElem(L,15,compare);
    i==0?printf("大于15的元素不存在\n"):printf("第一个大于15的元素的位置为%d\n",i);
    i=LocateElem(L,999,compare);
    i==0?printf("大于999的元素不存在\n"):printf("第一个大于999的元素的位置为%d\n",i);

    printf("*********************************函数PriorElem测试*********************************\n");
    PriorElem(L,100,e);
    printf("元素\"100\"的前驱为%d\n",e);

    printf("*********************************函数NextElem测试*********************************\n");
    NextELem(L,100,e);
    printf("元素\"100\"的后继为%d\n",e);

    printf("*********************************函数ClearList测试*********************************\n");
    printf("重置顺序表L前：");
    ListEmpty(L)?printf("顺序表L为空\n"):printf("顺序表L不为空\n");
    ClearList(L);
    printf("重置顺序表L后：");
    ListEmpty(L)?printf("顺序表L为空\n"):printf("顺序表L不为空\n");

    printf("*********************************函数DestroyList测试*********************************\n");
    printf("销毁顺序表L前：");
    L.elem?printf("顺序表L存在\n"):printf("顺序表L不存在\n");
    DestroyList(L);
    printf("销毁顺序表L后：");
    L.elem?printf("顺序表L存在\n"):printf("顺序表L不存在\n");

    system("pause");

    return 0;
}
