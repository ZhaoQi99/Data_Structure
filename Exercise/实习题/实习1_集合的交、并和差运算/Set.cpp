/*
Problem:集合的交、并和差运算
Author:QiZhao
Data:2017-10-30
Description:严蔚敏版数据结构题集实习题
Copyright  2017 QiZhao. All rights reserved.
*/
#include"Set.h"

Status CreateSet(Set &T,char *s)
{
    //生成一个由Str中小写字母构成的集合T
    Link p,q;
    int i;
    if(!InitList(T))
        return ERROR;
    for(i=0;s[i]!='\0';i++)
    {
        if('a'<=s[i]&&s[i]<='z'&&!LocateElem(T,s[i],p,compare))//判断是否为小写字母,过滤重复元素
        {
            if(!MakeNode(q,s[i]))
                return ERROR;
            InsAfter(T,p,q);
        }
    }
    return OK;
}

Status DestroySet(Set &T)
{
    //销毁集合T的结构
    return DestroyList(T);
}

Status Union(Set &T,Set S1,Set S2)
{
    //生成一个由S1和集合S2的并集构成的集合T
    if(!InitList(T))//内存分配失败
        return ERROR;
    if(ListEmpty(S1)||ListEmpty(S2))//集合S1和S2不为空
        return ERROR;
    Link p,q,s;
    int i;
    ElemType e;
    q=GetHead(S1)->next;//q指向第一个结点
    for(i=1;i<=S1.len;i++)//将S1中的所有元素拷贝至T
    {
        e=GetCurElem(q);
        if(!MakeNode(p,e))
            return ERROR;
        ListInsert(T,i,e);
        q = q->next;
    }
    q = GetHead(S2)->next;
    for(i = 1; i <= S2.len; i++)//若该元素不在T中,则插入T中
    {
        e = GetCurElem(q);
        if(!LocateElem(T, e, p, compare))
        {
            if(!MakeNode(s,e))
            return ERROR;
            InsAfter(T,p,s);
        }
        q=q->next;
    }
    return OK;
}

Status Intersection(Set &T, Set S1, Set S2)
{
    //生成一个由S1和S2的交集构成的集合T
    if(!InitList(T))//内存分配失败
        return ERROR;
    if(ListEmpty(S1) || ListEmpty(S2)) //集合S1和S2不为空
        return ERROR;
    int i;
    Link p,q;
    ElemType e;
    p=GetHead(S1)->next;
    for(i = 0; i < S1.len; i++)
    {
        e=GetCurElem(p);
        if(LocateElem(S2,e,q,compare))//在S2中能找到该元素
        {
            if(!MakeNode(q,e))
            return ERROR;
            InsAfter(T,T.tail,q);
        }
        p=p->next;
    }
    return OK;
}

Status Different(Set &T,Set S1,Set S2)
{
    //生成一个由S1和S2的差集构成的集合T
    if(!InitList(T))//内存分配失败
        return ERROR;
    if(ListEmpty(S1) || ListEmpty(S2)) //集合S1和S2不为空
        return ERROR;
    int i;
    Link p,q;
    ElemType e;
    q=GetHead(S1)->next;
    for(i=0;i<S1.len;i++)//若该元素不在S2中,则插入T中
    {
        e=GetCurElem(q);
        if(!LocateElem(S2,e,p,compare))
        {
            if(!MakeNode(p,e))
                return ERROR;
            InsAfter(T,T.tail,p);
        }
        q=q->next;
    }
    return OK;
}

Status Xor(Set &T,Set S1,Set S2)
{
    //生成一个由S1和S2的异或构成的集合
    Set temp1,temp2;
    if(!InitList(temp1))//内存分配失败
        return ERROR;
    if(!InitList(temp2))//内存分配失败
        return ERROR;
    if(ListEmpty(S1) || ListEmpty(S2)) //集合S1和S2不为空
        return ERROR;
    if(!Different(temp1,S1,S2))//S1-S2
        return ERROR;
    if(!Different(temp2,S2,S1))//S2-S1
        return ERROR;
    if(!Union(T,temp1,temp2))//S1⊕S2=(S1-S2)∪(S2-S1)
        return ERROR;
    return OK;
}

void PrintSet(Set T)
{
    //按字母次序顺序显示集合T的全部元素
    //printf("集合中的元素为:");
    ListTraverse(T,visit);
    printf("\n");
}

Status LocateElem(LinkList L, ElemType e, Position &q,Status(* compare)(ElemType, ElemType))
{
    //若有序链表L中存在与e满足判定函数compare()取值为0的元素,则q指示L中第一个
    //值为e的结点的位置,并返回TRUE;否则指示第一个与e满足判定函数compare()取
    //值为>0的元素的前驱的位置,并返回FALSE
    Link p,s;
    p=GetHead(L)->next;
    s=GetHead(L);//指向p的前驱
    while(p)
    {
        if(compare(p->data, e) == -1)
        {
            s = p;
            p = p->next;
        }
        else if(compare(p->data, e) == 0)
        {
            q = p;
            return TRUE;
        }
        else
        {
            //L为有序表,若程序运行至该处,则代表没找到与e满足判定函数compare()取值为0的元素,故应返回p的前驱
            q = s;
            return FALSE;
        }
    }
    if(p==NULL)
    {
        //若程序运行至此处,则代表有序表L中所有元素都比e小
        //由于p==NULL而跳出while循环
        //此时应返回p指示最后一个结点
        q=s;
    }
    return FALSE;
}

Status visit(ElemType e)
{
    printf("%c",e);
    return OK;
}

Status compare(ElemType a,ElemType b)
{
    if(a > b)
        return 1;
    else if(a == b)
        return 0;
    else
        return -1;
}


