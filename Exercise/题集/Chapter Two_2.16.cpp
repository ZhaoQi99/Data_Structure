#include "../template.h"
#include"../Book/线性表/LinkList.h"

Status DeleteAndInsertSub(LinkList *la, LinkList *lb, int i, int j, int len)
{
    if(i<0||j<0||len<0)
        return INFEASIBLE;
    LinkList p,q,s;
    int k;
    p=*la;
    for(k=1;k<i;k++)//p指向la的第i个元素
        p=p->next;
    if(p==NULL)//la中无第i个元素
        return ERROR;
    q=p;
    for(k=1;k<=len;k++)//q指向la的第i+len个元素
        q=q->next;
    if(q==NULL)//la中无第i+len个元素
        return ERROR;
    s=*lb;
    for(k=1;k<j-1;k++)//s指向lb的第j-1个元素
        s=s->next;
    if(s==NULL)//lb中无第j-1个元素
        return ERROR;
    LinkList rs=s->next;
    s->next=p->next;//插入元素
    LinkList rq=q->next;
    q->next=s->next;
    p->next=rq->next;//删除元素
    return OK;
}//DeleteAndInsertSub

//原算法不正确,没有删除la中的元素,第2个while循环的入口不对
/*Status DeleteAndInsertSub (LinkedList la, LinkedList lb, int i, int j, int len)
{
    if(i < 0 || j < 0 || len < 0)
        return	INFEASIBLE;
    p = la;
    k = 1;
    while(k < i)
    {
        p = p->next;
        k++;
    }
    q = p;
    while(k <= len)
    {
        q = q->next;
        k++;
    }
    s = lb;
    k = 1;
    while(k < j)
    {
        s = s->next;
        k++;
    }
    s->next = p;
    q->next = s->next;
    return	OK;
}//DeleteAndInsertSub
*/
