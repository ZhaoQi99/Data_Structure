#include"../../../template.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int num;//编号
    int password;//密码
} person;

typedef person ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode* next;
} LNode, * LinkList;

Status InitList(LinkList *L)
{
    // 构造一个空的循环链表L。
    *L = (LinkList)malloc(sizeof(LNode));
    if(!*L)//存储分配失败
        return(OVERFLOW);
    (*L)->next = *L;
    return OK;
} // InitList

Status ListInsert(LinkList &L, int i, ElemType e)
{
    // 在带头结点的单链循环链表L的第i个元素之前插入元素e
    LinkList p, s;
    p = L;
    int j = 0;
    while (p && j < i - 1)  // 寻找第i-1个结点
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) return ERROR;    // i小于1或者大于表长
    s = (LinkList)malloc(sizeof(LNode));  // 生成新结点
    s->data = e;
    s->next = p->next;      // 插入L中
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
    printf("出列顺序为:");
    while(L->next != L)
    {
        for(i = 1; i <= m - 2; i++)//使pr指向要出列的人的上一个人
            //要找到出列的人的上一个人,需要将指针向后移动m-2次
        {
            if(pr == L)//若指向头结点,则多进行一次循环
                i--;
            pr = pr->next;
        }
        p = pr->next; //p指向要出列的人
        if(p == L)//若p==L,即要出列的为第一个人,则头结点应指向第二个人
        {
            p = p->next;
            L->next = p->next;
        }
        else//若要出列的不为第一个人,则将要出列的上一个人的next指向要出列的人的next
            pr->next = p->next;
        e = p->data;
        free(p);
        m = e.password;//新密码
        pr = pr->next;//指向第一个开始报数的人
        //由于for循环中pr==L时会多执行一次循环,故若进行该操作后pr指向头结点,不会对程序造成影响
        printf("%d ", e.num);//输出要出列的人的编号
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

