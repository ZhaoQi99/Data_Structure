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

Status visit(ElemType e)
{
    printf("%d ",e);
    return OK;
}

Status compare(ElemType a, ElemType b)
{
    return a>b?TRUE:FALSE;
}

int main()
{
    LinkList L;
    ElemType e;
    Link s,p;
    int i;

    printf("*********************************����InitList����*********************************\n");
    InitList(L) ? printf("��ʼ����չ������ɹ�\n") : printf("��ʼ����չ������ʧ��\n");

    printf("*********************************����ListEmpty����*********************************\n");
    ListEmpty(L) ? printf("��չ������LΪ��\n") : printf("��չ������L��Ϊ��\n");

    printf("*********************************����ListInsert����*********************************\n");
    for(i = 1; i <= 15; i++) //����15������Ԫ��
    {
        e = rand() % 300; //ʵ��Ϊ41��167��34��100��269��124��78��258��262��164��5��245��181��27��61��
        printf("�ڵ�%d��λ�ò���\"%d\"\n", i,e);
        ListInsert(L,i,e);
    }

    printf("*********************************����ListTraverse����*********************************\n");
    printf("��չ������L��Ԫ�� = ");
    ListTraverse(L, visit);
    printf("\n");

    printf("*********************************����GetCurElem����*********************************\n");
    s=GetHead(L)->next;//sָ���һ�����
    printf("��һ������Ԫ��Ϊ:%d\n",GetCurElem(s));

    printf("*********************************����SetCurElem����*********************************\n");
    SetCurElem(s,99);
    printf("����һ������Ԫ���޸�Ϊ:\"99\"\n");
    ListTraverse(L,visit);
    printf("\n");

    printf("*********************************����DelFirst����*********************************\n");
    DelFirst(L,GetHead(L),s);
    printf("ɾ����չ������L�е�1��Ԫ��:\"%d\"\n", s->data);
    ListTraverse(L, visit);
    printf("\n");

    printf("*********************************����InsFirst����*********************************\n");
    InsFirst(L,GetHead(L),s);
    printf("����չ������L�ĵ�1��λ��ǰ���Ԫ��:\"%d\"\n", s->data);
    ListTraverse(L, visit);
    printf("\n");

    printf("*********************************����Remove����********************************\n");
    MakeNode(p,0);
    Remove(L,p);
    printf("ɾ����չ�������β���:\"%d\"\n",p->data);
    ListTraverse(L,visit);
    printf("\n");

    printf("*********************************����ListLength����*********************************\n");
    printf("��չ������L�ĳ���Ϊ:length = %d\n", ListLength(L));

    printf("*********************************����LocatePos����*********************************\n");
    LocatePos(L,5,s);
    printf("��չ������L�е����λ�õ�Ԫ��Ϊ%d\n", s->data);

    printf("*********************************����InsAfter����*********************************\n");
    LocatePos(L,4,p);//pָ����ĸ�λ�õ�Ԫ��
    s=(Link)malloc(sizeof(LNode));
    s->data=66;
    InsAfter(L,p,s);
    printf("����չ������L�е��ĸ�λ�õĺ������Ԫ��:%d\n",s->data);
    ListTraverse(L,visit);
    printf("\n");

    printf("*********************************����InsBefore����*********************************\n");
    LocatePos(L,4,p);//pָ����ĸ�λ�õ�Ԫ��
    s=(Link)malloc(sizeof(LNode));
    s->data=88;
    InsBefore(L,p,s);
    printf("����չ������L�е��ĸ�λ�õ�ǰ�����Ԫ��:%d\n",s->data);
    ListTraverse(L,visit);
    printf("\n");

    printf("*********************************����LocateElem����*********************************\n");
    s = LocateElem(L,15,compare);
    s == NULL ? printf("����15��Ԫ�ز�����\n") : printf("��һ������15��Ԫ��Ϊ%d\n", s->data);
    s = LocateElem(L,999,compare);
    s == NULL ? printf("����999��Ԫ�ز�����\n") : printf("��һ������999��Ԫ��Ϊ%d\n", s->data);

    printf("*********************************����PriorPos����*********************************\n");
    s=PriorPos(L, p);
    printf("Ԫ��\"%d\"��ǰ��Ϊ%d\n",p->data,s->data);

    printf("*********************************����NextPos����*********************************\n");
    s=NextPos(L, p);
    printf("Ԫ��\"%d\"�ĺ��Ϊ%d\n",p->data, s->data);

    printf("*********************************����Append����*********************************\n");
    MakeNode(s,0);
    p=s;
    printf("����չ������Ľ�β����һ�����:");
    for(i=0;i<6;i++)//ʹsָ��һ�����
    {
        Link m;
        m=p;
        m->data=rand()%300;
        visit(m->data);
        MakeNode(p,0);
        m->next=p;
    }
    printf("\n");
    Append(L,s);
    ListTraverse(L,visit);
    printf("\n");

    printf("*********************************����ClearList����*********************************\n");
    printf("��������Lǰ��");
    ListEmpty(L) ? printf("����LΪ��\n") : printf("����L��Ϊ��\n");
    ClearList(L);
    printf("��������L��");
    ListEmpty(L) ? printf("����LΪ��\n") : printf("����L��Ϊ��\n");

    printf("*********************************����DestroyList����*********************************\n");
    printf("��������Lǰ��");
    GetHead(L)? printf("����L����\n") : printf("����L������\n");
    DestroyList(L);
    printf("��������L��");
    GetHead(L)? printf("����L����\n") : printf("����L������\n");

    return 0;
}

