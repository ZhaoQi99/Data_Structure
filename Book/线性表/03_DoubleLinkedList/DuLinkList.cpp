/*
Problem:��ͷ����˫ͷѭ������
Author:QiZhao
Data:2017-10-12
Description:��ε�������ݽṹ�α�Դ��
Copyright  2017 QiZhao. All rights reserved.
*/
#include"DuLinkList.h"
#include<stdio.h>
#include<stdlib.h>

Status InitList_DuL(DuLinkList &L)
{
    // ����һ���յ����Ա�L��
    L = (DuLinkList)malloc(sizeof(DuLNode));
    if(!L)
        return(OVERFLOW);
    (*L).next = (*L).prior = L;
    return OK;
} // InitList_DuL

Status DestroyList_DuL(DuLinkList &L)
{
    //�������Ա�L
    DuLinkList p = L->next;
    DuLinkList q;
    while(p!=L)
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(L);
    L=NULL;
    return OK;
}//DestroyList_DuL

Status ClearList_DuL(DuLinkList &L)
{
    //��L����Ϊ�ձ�
    DuLinkList p = L->next;
    DuLinkList q;
    while(p != L)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = L->prior = L;
    return OK;
}//ClearList_DuL

int DuLinkListEmpty(DuLinkList L)
{
    //��LΪ�ձ�,�򷵻�TRUE,���򷵻�FALSE
    if(L != NULL && L->next == L && L->prior == L) //���������ͷ����ǰ���ͺ�̾�Ϊ�Լ�
        return TRUE;
    else
        return FALSE;
}//DuLinkListEmpty

int DuLinkListLength(DuLinkList L)
{
    //����L������Ԫ�ظ���
    int i = 0;
    DuLinkList p = L->next;
    while(p != L)
    {
        i++;
        p = p->next;
    }
    return i;
}//DuLinkListLength

DuLinkList GetElem_DuL(DuLinkList va, int i)
{
    // LΪ��ͷ���ĵ������ͷָ�롣
    // ����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
    DuLinkList p;
    p = va->next;
    int j = 1;  // ��ʼ����pָ���һ����㣬jΪ������
    while (p && j < i) //˳ָ�������ң�ֱ��pָ���i��Ԫ�ػ�pΪ��
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return ERROR; // ��i��Ԫ�ز�����
    else return p;
} // GetElem_DuL

int LocateElem_DuL(DuLinkList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
    // ��˫��ѭ�����Ա�L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
    // ���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0��
    DuLinkList p = L->next;
    int i = 1;
    while(p != L && (!(compare(p->data, e))))
    {
        p = p->next;
        i++;
    }
    if(p)
        return i;
    else
        return 0;
} // LocateElem_DuL

Status PriorElem_DuL(DuLinkList L, ElemType cur_e, ElemType &pre_e)
{
    //��cur_e��L������Ԫ��,�Ҳ��ǵ�һ��,����pre_e��������ǰ��,�������ʧ��,pre_e�޶���
    DuLinkList p = L->next;
    if(p->data != cur_e) //��һ���ڵ�û��ǰ��
    {
        while(p != L)
        {
            if(p->data != cur_e)
                p = p->next;
            else
            {
                pre_e = p->prior->data;
                return OK;
            }
        }
    }
    return ERROR;
    }//PriorElem_DuL

Status NextELem_DuL(DuLinkList L, ElemType cur_e, ElemType &next_e)
{
    //��cur_e��L������Ԫ��,�Ҳ������һ��,����next_e�������ĺ��,�������ʧ��,next_e�޶���
    DuLinkList p = L->next;
    while(p->next!=L)//���һ���ڵ�û�к��
    {
        if(p->data != cur_e)
            p = p->next;
        else
        {
            next_e = p->next->data;
            return OK;
        }
    }
    return ERROR;
}//NextELem_DuL

Status ListInsert_DuL(DuLinkList &L, int i, ElemType e)
{
    // �ڴ�ͷ����˫��ѭ�����Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e��
    // i�ĺϷ�ֵΪ1��i�ܱ�+1��
    DuLinkList p, s;
    if (!(p = GetElem_DuL(L, i)))  // ��L��ȷ����i��Ԫ�ص�λ��ָ��p
        return ERROR;                 // p=NULL, ����i��Ԫ�ز�����
    if (!(s = (DuLinkList)malloc(sizeof(DuLNode))))
        return ERROR;
    s->data = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return OK;
}//ListInsert_DuL

Status ListDelete_DuL(DuLinkList &L, int i, ElemType &e)
{
    // ɾ����ͷ����˫��ѭ�����Ա�L�ĵ�i��Ԫ�أ�i�ĺϷ�ֵΪ1��i�ܱ�
    DuLinkList p;
    if (!(p = GetElem_DuL(L, i)))  // ��L��ȷ����i��Ԫ�ص�λ��ָ��p
        return ERROR;                 // p=NULL, ����i��Ԫ�ز�����
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
} // ListDelete_DuL

Status ListTraverse(DuLinkList L, Status (*visit)(ElemType))
{
    //���ζ�L��ÿ������Ԫ�ص��ú���visit().һ��visit()ʧ�ܣ������ʧ��
    if(!L)
        return ERROR;
    DuLinkList p = L->next;
    while(p!=L)
    {
        visit(p->data);
        p = p->next;
    }
    return OK;
}

Status visit(ElemType e)
{
    printf("%d ", e);
    return OK;
}//visit

Status compare(ElemType a, ElemType b)
{
    return a > b ? TRUE : FALSE;
}//compare

int main()
{
/******************************************************Test**********************************************************/
    DuLinkList L;
    ElemType e;
    int i;

    printf("*********************************����InitList����*********************************\n");
    InitList_DuL(L) ? printf("��ʼ��˫ѭ������ɹ�\n") : printf("��ʼ��˫ѭ������ʧ��\n");

    printf("*********************************����ListEmpty����*********************************\n");
    DuLinkListEmpty(L) ? printf("˫ѭ������LΪ��\n") : printf("˫ѭ������L��Ϊ��\n");

    printf("*********************************����ListInsert����*********************************\n");
    for(i = 1; i <= 15; i++) //����15������Ԫ��
    {
        e = rand() % 300; //ʵ��Ϊ41��167��34��100��269��124��78��258��262��164��5��245��181��27��61��
        printf("�ڵ�%d��λ�ò���\"%d\"\n", i, e);
        ListInsert_DuL(L, i, e);
    }

    printf("*********************************����ListTraverse����*********************************\n");
    printf("˫ѭ������L��Ԫ�� = ");
    ListTraverse(L, visit);
    printf("\n");

    printf("*********************************����ListDelete����*********************************\n");
    ListDelete_DuL(L, 6, e);
    printf("ɾ��˫ѭ������L�е�6��Ԫ��:\"%d\"\n", e);
    ListTraverse(L, visit);
    printf("\n");

    printf("*********************************����ListLength����*********************************\n");
    printf("˫ѭ������L�ĳ���Ϊ:length = %d\n", DuLinkListLength(L));

    printf("*********************************����GetElem����*********************************\n");
    GetElem_DuL(L, 5);
    printf("˫ѭ������L�е����λ�õ�Ԫ��Ϊ%d\n", e);

    printf("*********************************����LocateElem����*********************************\n");
    i = LocateElem_DuL(L, 15, compare);
    i == 0 ? printf("����15��Ԫ�ز�����\n") : printf("��һ������15��Ԫ�ص�λ��Ϊ%d\n", i);
    i = LocateElem_DuL(L, 999, compare);
    i == 0 ? printf("����999��Ԫ�ز�����\n") : printf("��һ������999��Ԫ�ص�λ��Ϊ%d\n", i);

    printf("*********************************����PriorElem����*********************************\n");
    PriorElem_DuL(L, 100, e);
    printf("Ԫ��\"100\"��ǰ��Ϊ%d\n", e);

    printf("*********************************����NextElem����*********************************\n");
    NextELem_DuL(L, 100, e);
    printf("Ԫ��\"100\"�ĺ��Ϊ%d\n", e);

    printf("*********************************����ClearList����*********************************\n");
    printf("����˫ѭ������Lǰ��");
    DuLinkListEmpty(L) ? printf("˫ѭ������LΪ��\n") : printf("˫ѭ������L��Ϊ��\n");
    ClearList_DuL(L);
    printf("����˫ѭ������L��");
    DuLinkListEmpty(L) ? printf("˫ѭ������LΪ��\n") : printf("˫ѭ������L��Ϊ��\n");

    printf("*********************************����DestroyList����*********************************\n");
    printf("����˫ѭ������Lǰ��");
    L ? printf("˫ѭ������L����\n") : printf("˫ѭ������L������\n");
    DestroyList_DuL(L);
    printf("����˫ѭ������L��");
    L ? printf("˫ѭ������L����\n") : printf("˫ѭ����������\n");

    system("pause");

    return 0;
}
