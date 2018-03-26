/*
Problem:��ͷ���ĵ�����
Author:QiZhao
Data:2017-10-01
Description:��ε�������ݽṹ�α�Դ��
Copyright  2017 QiZhao. All rights reserved.
*/

#include"LinkList.h"

Status InitList(LinkList &L)
{
    // ����һ���յ����Ա�L��
    L = (LinkList)malloc(sizeof(LNode));
    if(!L)
        return(OVERFLOW);
    (*L).next = NULL;
    return OK;
} // InitList

Status DestroyList(LinkList &L)
{
    //�������Ա�L
    LinkList p = L;
    while(p)
    {
        L = p->next;
        free(p);
        p = L;
    }
    return OK;
}//DestroyList

Status ClearList(LinkList &L)
{
    //��L����Ϊ�ձ�
    LinkList p = L->next; //����ͷ���
    while(p)
    {
        L->next = p->next;
        free(p);
        p = L->next;
    }
    L->next = NULL; //�ÿ�ͷ���
    return OK;
}//ClearList

int ListEmpty(LinkList L)
{
    //��LΪ�ձ�,�򷵻�TRUE,���򷵻�FALSE
    if(L != NULL && L->next == NULL) //���������ͷ���Ϊ��ʱΪ�ձ�
        return TRUE;
    else
        return ERROR;
}//ListEmpty

int ListLength(LinkList L)
{
    //����L������Ԫ�ظ���
    int i = 0;
    LinkList p = L->next;
    while(p)
    {
        i++;
        p = p->next;
    }
    return i;
}//ListLength

Status GetElem_L(LinkList &L, int i, ElemType &e)
{
    // LΪ��ͷ���ĵ������ͷָ�롣
    // ����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
    LinkList p;
    p = L->next;
    int j = 1;           // ��ʼ����pָ���һ����㣬jΪ������
    while (p && j < i)   // ˳ָ�������ң�ֱ��pָ���i��Ԫ�ػ�pΪ��
    {
        p = p->next;
        ++j;
    }
    if ( !p || j > i ) return ERROR; // ��i��Ԫ�ز�����
    e = p->data;   // ȡ��i��Ԫ��
    return OK;
} // GetElem_L

int LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
    // ��˳�����Ա�L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
    // ���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0��
    LinkList p = L->next;
    int i = 1;
    while(p != NULL && (!(compare(p->data, e))))
    {
        p = p->next;
        i++;
    }
    if(p)
        return i;
    else
        return 0;
} // LocateElem

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e)
{
    //��cur_e��L������Ԫ��,�Ҳ��ǵ�һ��,����pre_e��������ǰ��,�������ʧ��,pre_e�޶���
    LinkList p = L->next;
    if(p->data != cur_e) //��һ���ڵ�û��ǰ��
    {
        while(p->next)
        {
            if(p->next->data != cur_e)
                p = p->next;
            else
            {
                pre_e = p->data;
                return OK;
            }
        }
    }
    return ERROR;
}//PriorElem

Status NextELem(LinkList L, ElemType cur_e, ElemType &next_e)
{
    //��cur_e��L������Ԫ��,�Ҳ������һ��,����next_e�������ĺ��,�������ʧ��,next_e�޶���
    LinkList p = L->next;
    while(p->next)//���һ���ڵ�û�к��
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
}//NextELem

Status ListInsert_L(LinkList &L, int i, ElemType e)
{
    // �ڴ�ͷ���ĵ������Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e
    LinkList p, s;
    p = L;
    int j = 0;
    while (p && j < i - 1)  // Ѱ�ҵ�i-1�����
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) return ERROR;    // iС��1���ߴ��ڱ�
    s = (LinkList)malloc(sizeof(LNode));  // �����½��
    s->data = e;
    s->next = p->next;      // ����L��
    p->next = s;
    return OK;
} // LinstInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e)
{
    // �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
    LinkList p, q;
    p = L;
    int j = 0;
    while (p->next && j < i - 1)  // Ѱ�ҵ�i����㣬����pָ����ǰ��
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1) return ERROR; // ɾ��λ�ò�����
    q = p->next;
    p->next = q->next;           // ɾ�����ͷŽ��
    e = q->data;
    free(q);
    return OK;
} // ListDelete_L

Status ListTraverse(LinkList L, Status (*visit)(ElemType))
{
    //���ζ�L��ÿ������Ԫ�ص��ú���visit().һ��visit()ʧ�ܣ������ʧ��
    if(!L)
        return ERROR;
    LinkList p = L->next;
    while(p)
    {
        visit(p->data);
        p = p->next;
    }
    return OK;
}

void CreateList_L(LinkList &L, int n)
{
    // ��λ�����루���������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L
    LinkList p;
    int i;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;              // �Ƚ���һ����ͷ���ĵ�����
    int temp[] = {41, 167, 34, 100, 269, 124, 78, 258, 262, 164, 5, 245, 181, 27, 61};
    int flag = 0;
    for (i = n; i > 0; --i)
    {
        p = (LinkList)malloc(sizeof(LNode));  // �����½��
        //scanf("%d",&p->data);
        p->data = temp[flag++];
        p->next = L->next;
        L->next = p;    // ���뵽��ͷ
    }
} // CreateList_L

void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc)
{
    // ��֪�������Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ����С�
    // �鲢La��Lb�õ��µĵ������Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ����С�
    LinkList pa, pb, pc;
    pa = La->next;
    pb = Lb->next;
    Lc = pc = La;             // ��La��ͷ�����ΪLc��ͷ���
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;  // ����ʣ���
    free(Lb);                 // �ͷ�Lb��ͷ���
} // MergeList_L

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
    LinkList L;
    ElemType e;
    int i;

    printf("*********************************����InitList����*********************************\n");
    InitList(L) ? printf("��ʼ������ɹ�\n") : printf("��ʼ������ʧ��\n");

    printf("*********************************����ListEmpty����*********************************\n");
    ListEmpty(L) ? printf("����LΪ��\n") : printf("����L��Ϊ��\n");

    printf("*********************************����ListInsert����*********************************\n");
    for(i = 1; i <= 15; i++) //����15������Ԫ��
    {
        e = rand() % 300; //ʵ��Ϊ41��167��34��100��269��124��78��258��262��164��5��245��181��27��61��
        printf("�ڵ�%d��λ�ò���\"%d\"\n", i, e);
        ListInsert_L(L, i, e);
    }

    printf("*********************************����ListTraverse����*********************************\n");
    printf("����L��Ԫ�� = ");
    ListTraverse(L, visit);
    printf("\n");

    printf("*********************************����ListDelete����*********************************\n");
    ListDelete_L(L, 6, e);
    printf("ɾ������L�е�6��Ԫ��:\"%d\"\n", e);
    ListTraverse(L, visit);
    printf("\n");

    printf("*********************************����ListLength����*********************************\n");
    printf("����L�ĳ���Ϊ:length = %d\n", ListLength(L));

    printf("*********************************����GetElem����*********************************\n");
    GetElem_L(L, 5, e);
    printf("����L�е����λ�õ�Ԫ��Ϊ%d\n", e);

    printf("*********************************����LocateElem����*********************************\n");
    i = LocateElem(L, 15, compare);
    i == 0 ? printf("����15��Ԫ�ز�����\n") : printf("��һ������15��Ԫ�ص�λ��Ϊ%d\n", i);
    i = LocateElem(L, 999, compare);
    i == 0 ? printf("����999��Ԫ�ز�����\n") : printf("��һ������999��Ԫ�ص�λ��Ϊ%d\n", i);

    printf("*********************************����PriorElem����*********************************\n");
    PriorElem(L, 100, e);
    printf("Ԫ��\"100\"��ǰ��Ϊ%d\n", e);

    printf("*********************************����NextElem����*********************************\n");
    NextELem(L, 100, e);
    printf("Ԫ��\"100\"�ĺ��Ϊ%d\n", e);

    printf("*********************************����ClearList����*********************************\n");
    printf("��������Lǰ��");
    ListEmpty(L) ? printf("����LΪ��\n") : printf("����L��Ϊ��\n");
    ClearList(L);
    printf("��������L��");
    ListEmpty(L) ? printf("����LΪ��\n") : printf("����L��Ϊ��\n");

    printf("*********************************����DestroyList����*********************************\n");
    printf("��������Lǰ��");
    L ? printf("����L����\n") : printf("����L������\n");
    DestroyList(L);
    printf("��������L��");
    L ? printf("����L����\n") : printf("����L������\n");

    printf("*********************************����CreateList_L����*********************************\n");
    LinkList p;
    CreateList_L(p, 15);
    ListTraverse(p, visit);
    printf("\n");

    system("pause");

    return 0;
}
