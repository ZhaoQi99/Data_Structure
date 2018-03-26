/*
Problem:���ϵĽ������Ͳ�����
Author:QiZhao
Data:2017-10-30
Description:��ε�������ݽṹ�⼯ʵϰ��
Copyright  2017 QiZhao. All rights reserved.
*/
#include"Set.h"

Status CreateSet(Set &T,char *s)
{
    //����һ����Str��Сд��ĸ���ɵļ���T
    Link p,q;
    int i;
    if(!InitList(T))
        return ERROR;
    for(i=0;s[i]!='\0';i++)
    {
        if('a'<=s[i]&&s[i]<='z'&&!LocateElem(T,s[i],p,compare))//�ж��Ƿ�ΪСд��ĸ,�����ظ�Ԫ��
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
    //���ټ���T�Ľṹ
    return DestroyList(T);
}

Status Union(Set &T,Set S1,Set S2)
{
    //����һ����S1�ͼ���S2�Ĳ������ɵļ���T
    if(!InitList(T))//�ڴ����ʧ��
        return ERROR;
    if(ListEmpty(S1)||ListEmpty(S2))//����S1��S2��Ϊ��
        return ERROR;
    Link p,q,s;
    int i;
    ElemType e;
    q=GetHead(S1)->next;//qָ���һ�����
    for(i=1;i<=S1.len;i++)//��S1�е�����Ԫ�ؿ�����T
    {
        e=GetCurElem(q);
        if(!MakeNode(p,e))
            return ERROR;
        ListInsert(T,i,e);
        q = q->next;
    }
    q = GetHead(S2)->next;
    for(i = 1; i <= S2.len; i++)//����Ԫ�ز���T��,�����T��
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
    //����һ����S1��S2�Ľ������ɵļ���T
    if(!InitList(T))//�ڴ����ʧ��
        return ERROR;
    if(ListEmpty(S1) || ListEmpty(S2)) //����S1��S2��Ϊ��
        return ERROR;
    int i;
    Link p,q;
    ElemType e;
    p=GetHead(S1)->next;
    for(i = 0; i < S1.len; i++)
    {
        e=GetCurElem(p);
        if(LocateElem(S2,e,q,compare))//��S2�����ҵ���Ԫ��
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
    //����һ����S1��S2�Ĳ���ɵļ���T
    if(!InitList(T))//�ڴ����ʧ��
        return ERROR;
    if(ListEmpty(S1) || ListEmpty(S2)) //����S1��S2��Ϊ��
        return ERROR;
    int i;
    Link p,q;
    ElemType e;
    q=GetHead(S1)->next;
    for(i=0;i<S1.len;i++)//����Ԫ�ز���S2��,�����T��
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
    //����һ����S1��S2����򹹳ɵļ���
    Set temp1,temp2;
    if(!InitList(temp1))//�ڴ����ʧ��
        return ERROR;
    if(!InitList(temp2))//�ڴ����ʧ��
        return ERROR;
    if(ListEmpty(S1) || ListEmpty(S2)) //����S1��S2��Ϊ��
        return ERROR;
    if(!Different(temp1,S1,S2))//S1-S2
        return ERROR;
    if(!Different(temp2,S2,S1))//S2-S1
        return ERROR;
    if(!Union(T,temp1,temp2))//S1��S2=(S1-S2)��(S2-S1)
        return ERROR;
    return OK;
}

void PrintSet(Set T)
{
    //����ĸ����˳����ʾ����T��ȫ��Ԫ��
    //printf("�����е�Ԫ��Ϊ:");
    ListTraverse(T,visit);
    printf("\n");
}

Status LocateElem(LinkList L, ElemType e, Position &q,Status(* compare)(ElemType, ElemType))
{
    //����������L�д�����e�����ж�����compare()ȡֵΪ0��Ԫ��,��qָʾL�е�һ��
    //ֵΪe�Ľ���λ��,������TRUE;����ָʾ��һ����e�����ж�����compare()ȡ
    //ֵΪ>0��Ԫ�ص�ǰ����λ��,������FALSE
    Link p,s;
    p=GetHead(L)->next;
    s=GetHead(L);//ָ��p��ǰ��
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
            //LΪ�����,�������������ô�,�����û�ҵ���e�����ж�����compare()ȡֵΪ0��Ԫ��,��Ӧ����p��ǰ��
            q = s;
            return FALSE;
        }
    }
    if(p==NULL)
    {
        //�������������˴�,����������L������Ԫ�ض���eС
        //����p==NULL������whileѭ��
        //��ʱӦ����pָʾ���һ�����
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


