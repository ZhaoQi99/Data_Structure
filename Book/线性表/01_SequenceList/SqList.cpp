/*
Problem:���Ա��˳��ʵ��
Author:QiZhao
Data:2017-09-26
Description:��ε�������ݽṹ�α�Դ��
Copyright  2017 QiZhao. All rights reserved.
*/

#include"SqList.h"

Status InitList(SqList &L)
{
    // ����һ���յ����Ա�L��
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) return ERROR;        // �洢����ʧ��
    L.length = 0;                  // �ձ���Ϊ0
    L.listsize = LIST_INIT_SIZE;   // ��ʼ�洢����
    return OK;
} // InitList

Status DestroyList(SqList &L)
{
    //�������Ա�L
    ElemType *p = L.elem;
    free(p);
    L.elem = NULL; //�ÿ�ָ��
    L.length = 0;
    L.listsize = 0;
    return OK;
}//DestroyList

Status ClearList(SqList &L)
{
    //��L����Ϊ�ձ�
    L.length = 0;
}//ClearList

int ListEmpty(SqList L)
{
    //��LΪ�ձ�,�򷵻�TRUE,���򷵻�FALSE
    return L.length == 0 ? TRUE : FALSE;
}//ListEmpty

int ListLength(SqList L)
{
    //����L������Ԫ�ظ���
    return L.length;
}//ListLength

Status GetElem(SqList L, int i, ElemType &e)
{
    //��e����L�е�i��Ԫ�ص�ֵ
    if(i < 1 || i > L.length)
        return ERROR;
    e = L.elem[i - 1];
    return OK;
}//GetElem

int LocateElem(SqList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
    // ��˳�����Ա�L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
    // ���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0��
    int i;
    ElemType *p;
    i = 1;        // i�ĳ�ֵΪ��1��Ԫ�ص�λ��
    p = L.elem;   // p�ĳ�ֵΪ��1��Ԫ�صĴ洢λ��
    while (i <= L.length && !(*compare)(*p++, e))
        ++i;
    if (i <= L.length) return i;
    else return 0;
} // LocateElem

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
    //��cur_e��L������Ԫ��,�Ҳ��ǵ�һ��,����pre_e��������ǰ��,�������ʧ��,pre_e�޶���
    if(L.elem[0] != cur_e) //��һ���ڵ���ǰ��
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
    //��cur_e��L������Ԫ��,�Ҳ������һ��,����next_e�������ĺ��,�������ʧ��,next_e�޶���
    int i = 0;
    while(L.elem[i] != cur_e)
        i++;
    if(i < L.length - 1) //���һ���ڵ�û�к��
    {
        next_e = L.elem[i + 1];
        return OK;
    }
    return ERROR;
}//NextELem

Status ListInsert(SqList &L, int i, ElemType e)
{
    // ��˳�����Ա�L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e��
    // i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)+1
    ElemType *p;
    if (i < 1 || i > L.length + 1) return ERROR; // iֵ���Ϸ�
    if (L.length >= L.listsize)     // ��ǰ�洢�ռ���������������
    {
        ElemType *newbase = (ElemType *)realloc(L.elem,
                                                (L.listsize + LISTINCREMENT) * sizeof (ElemType));
        if (!newbase) return ERROR;   // �洢����ʧ��
        L.elem = newbase;             // �»�ַ
        L.listsize += LISTINCREMENT;  // ���Ӵ洢����
    }
    ElemType *q = &(L.elem[i - 1]); // qΪ����λ��
    for (p = &(L.elem[L.length - 1]); p >= q; --p)// ����λ�ü�֮���Ԫ������
        *(p + 1) = *p;
    *q = e;       // ����e
    ++L.length;   // ����1
    return OK;
} // ListInsert

Status ListDelete(SqList &L, int i, ElemType &e)
{
    // ��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ��
    // i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)��
    ElemType *p, *q;
    if (i < 1 || i > L.length) return ERROR; // iֵ���Ϸ�
    p = &(L.elem[i - 1]);                 // pΪ��ɾ��Ԫ�ص�λ��
    e = *p;                               // ��ɾ��Ԫ�ص�ֵ����e
    q = L.elem + L.length - 1;            // ��βԪ�ص�λ��
    for (++p; p <= q; ++p) *(p - 1) = *p; // ��ɾ��Ԫ��֮���Ԫ������
    --L.length;                           // ����1
    return OK;
} // ListDelete

Status visit(ElemType e)
{
    printf("%d��",e);
    return OK;
}//visit

Status compare(ElemType a,ElemType b)
{
    return a>b?TRUE:FALSE;
}//compare

Status ListTraverse(SqList L, Status (*visit)(ElemType))
{
    //���ζ�L��ÿ������Ԫ�ص��ú���visit().һ��visit()ʧ�ܣ������ʧ��
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
    // ��֪˳�����Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ����С�
    // �鲢La��Lb�õ��µ�˳�����Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ����С�
    ElemType *pa, *pb, *pc, *pa_last, *pb_last;
    pa = La.elem;
    pb = Lb.elem;
    Lc.listsize = Lc.length = La.length + Lb.length;
    pc = Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
    if (!Lc.elem)
        exit(OVERFLOW);   // �洢����ʧ��
    pa_last = La.elem + La.length - 1;
    pb_last = Lb.elem + Lb.length - 1;
    while (pa <= pa_last && pb <= pb_last)    // �鲢
    {
        if (*pa <= *pb) *pc++ = *pa++;
        else *pc++ = *pb++;
    }
    while (pa <= pa_last) *pc++ = *pa++;      // ����La��ʣ��Ԫ��
    while (pb <= pb_last) *pc++ = *pb++;      // ����Lb��ʣ��Ԫ��
} // MergeList

int main()
{
    /******************************************************Test**********************************************************/
    SqList L;
    int i;
    ElemType e;

    printf("*********************************����InitList����*********************************\n");
    InitList(L)?printf("��ʼ��˳���ɹ�\n"):printf("��ʼ��˳���ʧ��\n");

    printf("*********************************����ListEmpty����*********************************\n");
    ListEmpty(L)?printf("˳���LΪ��\n"):printf("˳���L��Ϊ��\n");

    printf("*********************************����ListInsert����*********************************\n");
    for(i = 1; i <= 15; i++) //����15������Ԫ��
    {
        e=rand()%300;//�������0~399����
                    //ʵ��Ϊ41��167��34��100��269��124��78��258��262��164��5��245��181��27��61
        printf("�ڵ�%d��λ�ò���\"%d\"\n",i,e);
        ListInsert(L, i , e);
    }

    printf("*********************************����ListTraverse����*********************************\n");
    printf("˳���L��Ԫ�� = ");
    ListTraverse(L, visit);
    printf("\n");

    printf("*********************************����ListDelete����*********************************\n");
    ListDelete(L,6,e);
    printf("ɾ��˳���L�е�6��Ԫ��:\"%d\"\n",e);
    ListTraverse(L,visit);
    printf("\n");

    printf("*********************************����ListLength����*********************************\n");
    printf("˳���L�ĳ���Ϊ:length = %d\n",ListLength(L));

    printf("*********************************����GetElem����*********************************\n");
    GetElem(L,5,e);
    printf("˳���L�е����λ�õ�Ԫ��Ϊ%d\n",e);

    printf("*********************************����LocateElem����*********************************\n");
    i=LocateElem(L,15,compare);
    i==0?printf("����15��Ԫ�ز�����\n"):printf("��һ������15��Ԫ�ص�λ��Ϊ%d\n",i);
    i=LocateElem(L,999,compare);
    i==0?printf("����999��Ԫ�ز�����\n"):printf("��һ������999��Ԫ�ص�λ��Ϊ%d\n",i);

    printf("*********************************����PriorElem����*********************************\n");
    PriorElem(L,100,e);
    printf("Ԫ��\"100\"��ǰ��Ϊ%d\n",e);

    printf("*********************************����NextElem����*********************************\n");
    NextELem(L,100,e);
    printf("Ԫ��\"100\"�ĺ��Ϊ%d\n",e);

    printf("*********************************����ClearList����*********************************\n");
    printf("����˳���Lǰ��");
    ListEmpty(L)?printf("˳���LΪ��\n"):printf("˳���L��Ϊ��\n");
    ClearList(L);
    printf("����˳���L��");
    ListEmpty(L)?printf("˳���LΪ��\n"):printf("˳���L��Ϊ��\n");

    printf("*********************************����DestroyList����*********************************\n");
    printf("����˳���Lǰ��");
    L.elem?printf("˳���L����\n"):printf("˳���L������\n");
    DestroyList(L);
    printf("����˳���L��");
    L.elem?printf("˳���L����\n"):printf("˳���L������\n");

    system("pause");

    return 0;
}
