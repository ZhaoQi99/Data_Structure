/*
Problem:��չ�Ĵ�ͷ�ڵ����������
Author:QiZhao
Data:2017-10-19
Description:��ε�������ݽṹ�α�Դ��
Copyright  2017 QiZhao. All rights reserved.
*/
#include"ExtenLinkedList.h"
#include<stdio.h>
#include<stdlib.h>

Status MakeNode(Link &p, ElemType e)
{
    //������pָ��ֵΪe�Ľ�㣬������OK��������ʧ��,�򷵻�ERROR
    p = (Link)malloc(sizeof(LNode));
    if(!p)
        return OVERFLOW;
    p->data = e;
    p->next = NULL;
    return OK;
}

void FreeNode(Link &p)
{
    //�ͷ�p��ָ���
    free(p);
    p = NULL;
}

Status InitList(LinkList &L)
{
    // ����һ���յ����Ա�L��
    Link p;
    p = (Link)malloc(sizeof(LNode));
    if(!p)
        return OVERFLOW;
    p->next = NULL;
    L.head = L.tail = p;
    L.len = 0;
    return OK;
}

Status DestroyList(LinkList & L)
{
    //�������Ա�L,L���ٴ���
    Link p = GetHead(L);
    Link q;
    while(p!=GetLast(L))
    {
        q = p->next;
        FreeNode(p);
        p = q;
    }
    FreeNode(L.tail);
    L.len=0;
    L.head=NULL;
    return OK;
}

Status ClearList(LinkList & L)
{
    //��L����Ϊ�ձ�,���ͷ�ԭ����Ľ��ռ�
    Link p = GetHead(L)->next; //pָ���һ�����
    Link q;
    while(p)
    {
        q = p->next;
        FreeNode(p);
        p = q;
    }
    L.len=0;
    L.tail=GetHead(L);
    return OK;
}

Status InsFirst(LinkList &L,Link h, Link s)
{
    //��֪hָ�����������ͷ���,��s��ָ�������ڵ�һ�����֮ǰ
    Link p=h->next;//pָ���һ�����
    s->next=p;
    h->next=s;
    L.len++;
    return OK;
}

Status DelFirst(LinkList &L,Link h, Link &q)
{
    //��֪hָ�����������ͷ���,ɾ�������е�һ����㲢��q����
    q=h->next;
    h->next=q->next;
    L.len--;
    return OK;
}

Status Append(LinkList &L, Link s)
{
    //��ָ��s��ָ(�˴���ָ������)��һ�������������������L�����һ�����
    //֮��,���ı�����L��βָ��ָ���µ�β���
    Link q=L.tail;
    while(s!=NULL)
    {
        q->next=s;
        q=s;
        s=s->next;
        L.len++;
    }
    L.tail=q;//βָ��ָ���µ�β���
    return  OK;
}

Status Remove(LinkList &L, Link &q)
{
    //ɾ����������L�е�β��㲢��q����,�ı�����L��βָ��ָ���µ�β���
    Link p=GetHead(L);
    if(L.head==L.tail)
        return ERROR;
    while(p->next!=L.tail)
        p=p->next;
    L.tail=p;
    p=p->next;
    q->data=p->data;
    //FreeNode(p);
    L.len--;
    return OK;
}

Status InsBefore(LinkList &L, Link &p, Link s)
{
    //��֪pָ����������L�е�һ�����,��s��ָ��������p��ָ���֮ǰ,
    //���޸�ָ��pָ���²���Ľ��
    Link q=GetHead(L);
    while(q->next != p)
        q = q->next;
    s->next=q->next;
    q->next=s;
    if(p==L.head->next)//p��ָ���Ϊ��һ��ʱ
        L.head=p;
    p=s;
    L.len++;
    return OK;
}

Status InsAfter(LinkList &L, Link &p, Link s)
{
    //��֪pָ����������L�е�һ�����,��s��ָ��������p��ָ���֮��,
    //���޸�ָ��pָ���²���Ľ��
    Link q=GetHead(L);
    while(q!=p)
        q=q->next;
    s->next=p->next;
    p->next=s;
    if(p==GetLast(L))
        L.tail=s;
    p=s;
    L.len++;
    return OK;
}

Status ListInsert(LinkList &L, int i, ElemType e)
{
    // �ڴ�ͷ������չ�ĵ������Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e
    Link p, s;
    p = GetHead(L);
    int j = 0;
    if (!p || j > i - 1)
        return ERROR;    // iС��1���ߴ��ڱ�
    while (p && j < i - 1)  // Ѱ�ҵ�i-1�����
    {
        p = p->next;
        ++j;
    }
    if(!MakeNode(s,e))  // �����½��
        return OVERFLOW;
    s->next = p->next;      // ����L��
    p->next = s;
    if(i==ListLength(L)+1)
        L.tail=s;
    L.len++;
    return OK;
}

Status SetCurElem(Link &p, ElemType e)
{
    //��֪pָ�����������е�һ�����,��e����p��ָ���������Ԫ�ص�ֵ
    p->data=e;
    return OK;
}

ElemType GetCurElem(Link p)
{
    //��֪pָ�����������е�һ�����,����p��ָ���������Ԫ�ص�ֵ
    return p->data;
}

Status ListEmpty(LinkList L)
{
    //��LΪ�ձ�,�򷵻�TRUE,���򷵻�FALSE
    if(L.len==0)
        return TRUE;
    else
        return FALSE;
}

int ListLength(LinkList L)
{
    //����L������Ԫ�ظ���
    return L.len;
}

Position GetHead(LinkList L)
{
    //�������Ա�L��ͷ����λ��
    return L.head;
}

Position GetLast(LinkList L)
{
    //�������Ա�L�����һ������λ��
    return L.tail;
}

Position PriorPos(LinkList L, Link p)
{
    //��֪pָ����������L�е�һ�����,����p��ָ����ֱ��ǰ����λ��,
    //����ǰ��,�򷵻�NULL
    Link q=GetHead(L);
    if(p==q->next)//��һ�������ֱ��ǰ��
        return NULL;
    while(q->next!=p)
        q=q->next;
    return q;
}

Position NextPos(LinkList L, Link p)
{
    //��֪pָ����������L�е�һ�����,����p��ָ����ֱ�Ӻ�̵�λ��,
    //���޺��,�򷵻�NULL
    Link q=GetHead(L);
    while(q!=p)
        q=q->next;
    if(q==L.tail)//���һ�������ֱ�Ӻ��
        return NULL;
    q=q->next;
    return q;
}

Status LocatePos(LinkList L, int i, Link &p)
{
    //����pָʾ��������L�е�i������λ��,������OK,iֵ���Ϸ�ʱ����ERROR
    if(i<1||i>L.len)//iֵ���Ϸ�
        return ERROR;
    Link q=GetHead(L);
    while(i--)
    {
        q=q->next;
    }
    p=q;
    return OK;
}

Position LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
    // ����ʽ���Ա�L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
    // ��������������Ԫ��,�򷵻�NULL
    Link p=GetHead(L)->next;
    while(p != L.tail &&(!compare(p->data, e)))
    {
        p = p->next;
    }
    if(p==L.tail)
        return NULL;
    else
        return p;
}

Status ListTraverse(LinkList L, Status (*visit)(ElemType))
{
    //���ζ�L��ÿ������Ԫ�ص��ú���visit().һ��visit()ʧ�ܣ������ʧ��
    Link p=GetHead(L);
    int len=ListLength(L);
    while(len--)
    {
        p=p->next;
        visit(p->data);
    }
    return OK;
}

