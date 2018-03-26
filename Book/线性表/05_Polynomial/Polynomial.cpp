/*
Problem:������������һԪ����ʽ��ʵ��
Author:QiZhao
Data:2017-10-23
Description:��ε�������ݽṹ�α�Դ��
Copyright  2017 QiZhao. All rights reserved.
*/

#include<stdio.h>
#include"Polynomial.h"
#define exp 0.0001//���ڱȽ�����������
#include<time.h>

void CreatPolyn(polynomial &P, int m)
{
    //����m���ϵ����ָ��,������ʾһԪ����ʽ����������P
    Link h, q, s;
    ElemType e;
    int i;
    InitList(P);
    h = GetHead(P);
    e.coef = 0.0;
    e.expn = -1;
    SetCurElem(h, e);       // ����ͷ���
    srand((unsigned int)(time(NULL))+rand()%1000);//�������������
    for (i = 1; i <= m; ++i) // ��������m��������
    {
        //scanf ("%f %d\n",&e.coef, &e.expn);
        e.coef = (float)(rand()%90 + rand()%10/10.0);
        e.expn = rand()%600+1;
        if (!LocateElem(P, e, q,compare))  // ��ǰ�����в����ڸ�ָ����
        {
            if (MakeNode(s, e))
                InsFirst(P,q, s); // ���ɽ�㲢��������
            if(q == P.tail)
                P.tail = s;
        }
    }
}

void DestroyPolyn(polynomial &P)
{
    //����һԪ����ʽ
    DestroyList(P);
}

void PrintPolyn(polynomial P)
{
    //��ӡ���һԪ����ʽP
    int i = 0;
    Link q = P.head->next;
    while (q)
    {
        if (fabs(q->data.coef) > exp)
        {
            if (i > 0)
            {
                if (q->data.coef > exp)
                    printf(" + ");
                else
                    printf(" - ");
                printf("%.2f", fabs(q->data.coef));
            }
            else
                printf("%.2f", q->data.coef);
            if (q->data.expn >= 1)
                printf("x");
            if (q->data.expn > 1)
                printf("^%d", q->data.expn);
        }
        q = q->next;
        if (++i % 6 == 0)
            printf("\n     ");
    }
    printf("\n");
}

int PolynLength(polynomial P)
{
    //����һԪ����ʽP�е�����
    return ListLength(P);
}

void AddPolyn(polynomial &Pa, polynomial &Pb)
{
    //��ɶ���ʽ�������,��:Pa=Pa+Pb,������һԪ����ʽPb
    Link ha, hb, qa, qb;
    ElemType a, b, temp;
    float sum;
    ha = GetHead(Pa);      // ha��hb�ֱ�ָ��Pa��Pb��ͷ���
    hb = GetHead(Pb);
    qa = NextPos(Pa, ha);  // qa��qb�ֱ�ָ��Pa��Pb�е�ǰ���
    qb = NextPos(Pb, hb);
    while (qa && qb)       // Pa��Pb���ǿ�
    {
        a = GetCurElem (qa); // a��bΪ�����е�ǰ�Ƚ�Ԫ��
        b = GetCurElem (qb);
        switch (compare(a, b))
        {
        case -1:  // ����ʽPA�е�ǰ����ָ��ֵС
            ha = qa;
            qa = NextPos (Pa, qa);
            break;
        case 0:   // ���ߵ�ָ��ֵ���
            sum = a.coef + b.coef ;
            if (sum != 0.0)    // �޸Ķ���ʽPA�е�ǰ����ϵ��ֵ
            {
                temp.coef = sum;
                temp.expn = a.expn;
                SetCurElem(qa, temp) ;
                ha = qa;
            }
            else      // ɾ������ʽPA�е�ǰ���
            {
                DelFirst(Pa,ha, qa);
                FreeNode(qa);
            }
            DelFirst(Pa,hb, qb);
            FreeNode(qb);
            qb = NextPos(Pb, hb);
            qa = NextPos(Pa, ha);
            break;
        case 1:   // ����ʽPB�е�ǰ����ָ��ֵС
            DelFirst(Pb,hb, qb);
            InsFirst(Pb,ha, qb);
            qb = NextPos(Pb, hb);
            ha = NextPos(Pa, ha);
            break;
        } // switch
    } // while
    if (qb)//�˴�������������д��!ListEmpty(Pb),��ΪPb����Pa���ظ���δ��ɾ��,Pb��ʱ��Ϊ��
        Append(Pa, qb);   // ����Pb��ʣ����
    FreeNode(hb);  // �ͷ�Pb��ͷ���
}

void SubtractPolyn(polynomial &Pa,polynomial &Pb)
{
    //��ɶ���ʽ�������,��:Pa=Pa-Pb,������һԪ����ʽPb
    Link ha, hb, qa, qb;
    ElemType a, b, temp;
    float sum;
    ha = GetHead(Pa);      // ha��hb�ֱ�ָ��Pa��Pb��ͷ���
    hb = GetHead(Pb);
    qa = NextPos(Pa, ha);  // qa��qb�ֱ�ָ��La��Lb�е�ǰ���
    qb = NextPos(Pb, hb);
    while (qa && qb)       // Pa��Pb���ǿ�
    {
        a = GetCurElem (qa); // a��bΪ�����е�ǰ�Ƚ�Ԫ��
        b = GetCurElem (qb);
        switch (compare(a, b))
        {
        case -1:  // ����ʽPA�е�ǰ����ָ��ֵС
            ha = qa;
            qa = NextPos (Pa, qa);
            break;
        case 0:   // ���ߵ�ָ��ֵ���
            sum = a.coef - b.coef ;
            if (sum != 0.0)    // �޸Ķ���ʽPA�е�ǰ����ϵ��ֵ
            {
                temp.coef = sum;
                temp.expn = a.expn;
                SetCurElem(qa, temp) ;
                ha = qa;
            }
            else      // ɾ������ʽPA�е�ǰ���
            {
                DelFirst(Pa,ha, qa);
                FreeNode(qa);
            }
            DelFirst(Pa,hb, qb);
            FreeNode(qb);
            qb = NextPos(Pb, hb);
            qa = NextPos(Pa, ha);
            break;
        case 1:   // ����ʽPB�е�ǰ����ָ��ֵС
            DelFirst(Pb,hb, qb);
            InsFirst(Pb,ha, qb);
            qb = NextPos(Pb, hb);
            ha = NextPos(Pa, ha);
            break;
        } // switch
    } // while
    if (qb)//�˴�������������д��!ListEmpty(Pb),��ΪPb����Pa���ظ���δ��ɾ��,Pb��ʱ��Ϊ��
        Append(Pa, qb);   // ����Pb��ʣ����
    FreeNode(hb);  // �ͷ�Pb��ͷ���
}

void MultiplyPolyn(polynomial &Pa,polynomial &Pb)
{
    //��ɶ���ʽ�������,��:Pa=Pa*Pb,������һԪ����ʽPb
    int la=ListLength(Pa);
    int lb=ListLength(Pb);
    int i,j;
    ElemType ea,eb;
    Link qa,qb,ha,hb;
    polynomial Pa_temp;
    //polynomial Pc;
    InitList(Pa_temp);//���Pa��Pa_temp�Ŀ���
    Link s=GetHead(Pa)->next;
    ElemType e;
    for(i=0;i<ListLength(Pa);i++)
    {
        e=GetCurElem(s);
        OrderInsert(Pa_temp,e,compare);
        s=NextPos(Pa,s);
    }
    DestroyList(Pa);
    InitList(Pa);
    ha=GetHead(Pa_temp); // ha��hb�ֱ�ָ��Pa��Pb��ͷ���
    hb=GetHead(Pb);
    qa=NextPos(Pa_temp,ha);// qa��qb�ֱ�ָ��Pa��Pb�е�ǰ���
    qb=NextPos(Pb,hb);
    for(i=0;i<lb;i++)
    {
        //InitList(Pc);//�����洢bi*A(x)*x^ei
        eb=GetCurElem(qb);
        qa=NextPos(Pa_temp,ha);
        for(j=0;j<la;j++)
        {
            ea=GetCurElem(qa);
            ea.coef=eb.coef*ea.coef;
            ea.expn+=eb.expn;
            OrderInsert(Pa,ea,compare);
            //OrderInsert(Pc,ea,compare);
            qa=NextPos(Pa_temp,qa);
        }
        DelFirst(Pb,hb,qb);
        qb=NextPos(Pb,hb);
        //AddPolyn(Pa,Pc);
    }
    FreeNode(hb);//�ͷ�Pb��ͷ���
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
        if(compare(p->data,e)==-1)
        {
            s=p;
            p=p->next;
        }
        else if(compare(p->data,e)==0)
        {
            q=p;
            return TRUE;
        }
        else
        {
            //LΪ�����,����������ֻ�ô�,�����û�ҵ���e�����ж�����compare()ȡֵΪ0��Ԫ��,��Ӧ����p��ǰ��
            q=s;
            return FALSE;
        }
    }
    if(p==NULL)
    {
        //�������������˴�,����������L������Ԫ�ص�ָ��ֵ����e��ָ��С
        //����p==NULL������whileѭ��
        //��ʱӦ����pָʾ���һ�����
        q=s;
    }
    return FALSE;
}

Status OrderInsert(LinkList &L,ElemType e,Status(* compare)(ElemType, ElemType))
{
    Link p,s;
    if(!LocateElem(L,e,p,compare))//�ҵ���e�����ж�����compare()==0��Ԫ��
    {
        if(!MakeNode(s,e))//������ʧ��
            return ERROR;
        if(p!=GetHead(L))
        {
            Link temp=GetLast(L);
            if(p==temp&&compare(temp->data,e)==-1)//������Ԫ�ص�ָ����С��e��ָ��,��ʱӦ������β���ĺ���
                InsAfter(L,temp,s);
            else
                InsFirst(L,p,s);
        }
        else//������ͷ���ĺ���
            InsAfter(L,p,s);
    }
    else
    {
        p->data.coef+=e.coef;
    }
    return OK;
}

Status compare(term a, term b)
{
    //��a��ָ��ֵ<(��=)(��>)b��ָ��ֵ,�ֱ𷵻�-1,0��+1
    if (a.expn > b.expn)
        return 1;
    else if(a.expn == b.expn)
        return 0;
    else
        return -1;
}

void Test(polynomial &P1,polynomial &P2)
{
    int m1,m2;
    printf("*********************************������Ҫ���ɵĵ�һ������ʽ������*********************************\n");
    scanf("%d",&m1);
    CreatPolyn(P1,m1);
    printf("���ɵĶ���ʽΪ:\n");
    PrintPolyn(P1);
    printf("*********************************������Ҫ���ɵĵڶ�������ʽ������*********************************\n");
    scanf("%d",&m2);
    CreatPolyn(P2,m2);
    PrintPolyn(P2);
}
