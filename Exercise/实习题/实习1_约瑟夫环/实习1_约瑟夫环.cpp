#include"../../../template.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int num;//���
    int password;//����
} person;

typedef person ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode* next;
} LNode, * LinkList;

Status InitList(LinkList *L)
{
    // ����һ���յ�ѭ������L��
    *L = (LinkList)malloc(sizeof(LNode));
    if(!*L)//�洢����ʧ��
        return(OVERFLOW);
    (*L)->next = *L;
    return OK;
} // InitList

Status ListInsert(LinkList &L, int i, ElemType e)
{
    // �ڴ�ͷ���ĵ���ѭ������L�ĵ�i��Ԫ��֮ǰ����Ԫ��e
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
} // LinstInsert

void Joseph(LinkList L, int m, int n)
{
    LinkList p, pr;
    ElemType e;
    int i;
    pr = L->next;
    m = m % n;
    printf("����˳��Ϊ:");
    while(L->next != L)
    {
        for(i = 1; i <= m - 2; i++)//ʹprָ��Ҫ���е��˵���һ����
            //Ҫ�ҵ����е��˵���һ����,��Ҫ��ָ������ƶ�m-2��
        {
            if(pr == L)//��ָ��ͷ���,������һ��ѭ��
                i--;
            pr = pr->next;
        }
        p = pr->next; //pָ��Ҫ���е���
        if(p == L)//��p==L,��Ҫ���е�Ϊ��һ����,��ͷ���Ӧָ��ڶ�����
        {
            p = p->next;
            L->next = p->next;
        }
        else//��Ҫ���еĲ�Ϊ��һ����,��Ҫ���е���һ���˵�nextָ��Ҫ���е��˵�next
            pr->next = p->next;
        e = p->data;
        free(p);
        m = e.password;//������
        pr = pr->next;//ָ���һ����ʼ��������
        //����forѭ����pr==Lʱ���ִ��һ��ѭ��,�������иò�����prָ��ͷ���,����Գ������Ӱ��
        printf("%d ", e.num);//���Ҫ���е��˵ı��
    }
    printf("\n");
    return;
}

int main()
{
    LinkList L;
    ElemType e;
    int i;
    //freopen("in.txt", "r", stdin);
    if(!InitList(&L))
    {
        printf("Initialize Error.....\n");
        exit(0);
    }
    int m, n;
    printf("Please input m and n....\n");
    scanf("%d %d", &m, &n);
    printf("Please input n password......\n");
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &e.password);
        e.num = i;
        ListInsert(L, i, e);
    }
    Joseph(L, m, n);
    return 0;
}

