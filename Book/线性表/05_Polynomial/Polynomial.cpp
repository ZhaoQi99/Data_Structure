/*
Problem:抽象数据类型一元多项式的实现
Author:QiZhao
Data:2017-10-23
Description:严蔚敏版数据结构课本源码
Copyright  2017 QiZhao. All rights reserved.
*/

#include<stdio.h>
#include"Polynomial.h"
#define exp 0.0001//用于比较两个浮点数
#include<time.h>

void CreatPolyn(polynomial &P, int m)
{
    //输入m项的系数和指数,建立表示一元多项式的有序链表P
    Link h, q, s;
    ElemType e;
    int i;
    InitList(P);
    h = GetHead(P);
    e.coef = 0.0;
    e.expn = -1;
    SetCurElem(h, e);       // 设置头结点
    srand((unsigned int)(time(NULL))+rand()%1000);//设置随机数种子
    for (i = 1; i <= m; ++i) // 依次输入m个非零项
    {
        //scanf ("%f %d\n",&e.coef, &e.expn);
        e.coef = (float)(rand()%90 + rand()%10/10.0);
        e.expn = rand()%600+1;
        if (!LocateElem(P, e, q,compare))  // 当前链表中不存在该指数项
        {
            if (MakeNode(s, e))
                InsFirst(P,q, s); // 生成结点并插入链表
            if(q == P.tail)
                P.tail = s;
        }
    }
}

void DestroyPolyn(polynomial &P)
{
    //销毁一元多项式
    DestroyList(P);
}

void PrintPolyn(polynomial P)
{
    //打印输出一元多项式P
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
    //返回一元多项式P中的项数
    return ListLength(P);
}

void AddPolyn(polynomial &Pa, polynomial &Pb)
{
    //完成多项式相加运算,即:Pa=Pa+Pb,并销毁一元多项式Pb
    Link ha, hb, qa, qb;
    ElemType a, b, temp;
    float sum;
    ha = GetHead(Pa);      // ha和hb分别指向Pa和Pb的头结点
    hb = GetHead(Pb);
    qa = NextPos(Pa, ha);  // qa和qb分别指向Pa和Pb中当前结点
    qb = NextPos(Pb, hb);
    while (qa && qb)       // Pa和Pb均非空
    {
        a = GetCurElem (qa); // a和b为两表中当前比较元素
        b = GetCurElem (qb);
        switch (compare(a, b))
        {
        case -1:  // 多项式PA中当前结点的指数值小
            ha = qa;
            qa = NextPos (Pa, qa);
            break;
        case 0:   // 两者的指数值相等
            sum = a.coef + b.coef ;
            if (sum != 0.0)    // 修改多项式PA中当前结点的系数值
            {
                temp.coef = sum;
                temp.expn = a.expn;
                SetCurElem(qa, temp) ;
                ha = qa;
            }
            else      // 删除多项式PA中当前结点
            {
                DelFirst(Pa,ha, qa);
                FreeNode(qa);
            }
            DelFirst(Pa,hb, qb);
            FreeNode(qb);
            qb = NextPos(Pb, hb);
            qa = NextPos(Pa, ha);
            break;
        case 1:   // 多项式PB中当前结点的指数值小
            DelFirst(Pb,hb, qb);
            InsFirst(Pb,ha, qb);
            qb = NextPos(Pb, hb);
            ha = NextPos(Pa, ha);
            break;
        } // switch
    } // while
    if (qb)//此处不能用书中所写的!ListEmpty(Pb),因为Pb中与Pa不重复项未被删除,Pb此时不为空
        Append(Pa, qb);   // 链接Pb中剩余结点
    FreeNode(hb);  // 释放Pb的头结点
}

void SubtractPolyn(polynomial &Pa,polynomial &Pb)
{
    //完成多项式相减运算,即:Pa=Pa-Pb,并销毁一元多项式Pb
    Link ha, hb, qa, qb;
    ElemType a, b, temp;
    float sum;
    ha = GetHead(Pa);      // ha和hb分别指向Pa和Pb的头结点
    hb = GetHead(Pb);
    qa = NextPos(Pa, ha);  // qa和qb分别指向La和Lb中当前结点
    qb = NextPos(Pb, hb);
    while (qa && qb)       // Pa和Pb均非空
    {
        a = GetCurElem (qa); // a和b为两表中当前比较元素
        b = GetCurElem (qb);
        switch (compare(a, b))
        {
        case -1:  // 多项式PA中当前结点的指数值小
            ha = qa;
            qa = NextPos (Pa, qa);
            break;
        case 0:   // 两者的指数值相等
            sum = a.coef - b.coef ;
            if (sum != 0.0)    // 修改多项式PA中当前结点的系数值
            {
                temp.coef = sum;
                temp.expn = a.expn;
                SetCurElem(qa, temp) ;
                ha = qa;
            }
            else      // 删除多项式PA中当前结点
            {
                DelFirst(Pa,ha, qa);
                FreeNode(qa);
            }
            DelFirst(Pa,hb, qb);
            FreeNode(qb);
            qb = NextPos(Pb, hb);
            qa = NextPos(Pa, ha);
            break;
        case 1:   // 多项式PB中当前结点的指数值小
            DelFirst(Pb,hb, qb);
            InsFirst(Pb,ha, qb);
            qb = NextPos(Pb, hb);
            ha = NextPos(Pa, ha);
            break;
        } // switch
    } // while
    if (qb)//此处不能用书中所写的!ListEmpty(Pb),因为Pb中与Pa不重复项未被删除,Pb此时不为空
        Append(Pa, qb);   // 链接Pb中剩余结点
    FreeNode(hb);  // 释放Pb的头结点
}

void MultiplyPolyn(polynomial &Pa,polynomial &Pb)
{
    //完成多项式相乘运算,即:Pa=Pa*Pb,并销毁一元多项式Pb
    int la=ListLength(Pa);
    int lb=ListLength(Pb);
    int i,j;
    ElemType ea,eb;
    Link qa,qb,ha,hb;
    polynomial Pa_temp;
    //polynomial Pc;
    InitList(Pa_temp);//完成Pa至Pa_temp的拷贝
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
    ha=GetHead(Pa_temp); // ha和hb分别指向Pa和Pb的头结点
    hb=GetHead(Pb);
    qa=NextPos(Pa_temp,ha);// qa和qb分别指向Pa和Pb中当前结点
    qb=NextPos(Pb,hb);
    for(i=0;i<lb;i++)
    {
        //InitList(Pc);//用来存储bi*A(x)*x^ei
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
    FreeNode(hb);//释放Pb的头结点
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
            //L为有序表,若程序运行只该处,则代表没找到与e满足判定函数compare()取值为0的元素,故应返回p的前驱
            q=s;
            return FALSE;
        }
    }
    if(p==NULL)
    {
        //若程序运行至此处,则代表有序表L中所有元素的指数值都比e的指数小
        //由于p==NULL而跳出while循环
        //此时应返回p指示最后一个结点
        q=s;
    }
    return FALSE;
}

Status OrderInsert(LinkList &L,ElemType e,Status(* compare)(ElemType, ElemType))
{
    Link p,s;
    if(!LocateElem(L,e,p,compare))//找到与e满足判定函数compare()==0的元素
    {
        if(!MakeNode(s,e))//结点分配失败
            return ERROR;
        if(p!=GetHead(L))
        {
            Link temp=GetLast(L);
            if(p==temp&&compare(temp->data,e)==-1)//若所有元素的指数均小于e的指数,此时应插入在尾结点的后面
                InsAfter(L,temp,s);
            else
                InsFirst(L,p,s);
        }
        else//插入在头结点的后面
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
    //依a的指数值<(或=)(或>)b的指数值,分别返回-1,0和+1
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
    printf("*********************************请输入要生成的第一个多项式的项数*********************************\n");
    scanf("%d",&m1);
    CreatPolyn(P1,m1);
    printf("生成的多项式为:\n");
    PrintPolyn(P1);
    printf("*********************************请输入要生成的第二个多项式的项数*********************************\n");
    scanf("%d",&m2);
    CreatPolyn(P2,m2);
    PrintPolyn(P2);
}
