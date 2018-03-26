#include "../template.h"
#include"../Book/���Ա�/LinkList.h"

Status DeleteAndInsertSub(LinkList *la, LinkList *lb, int i, int j, int len)
{
    if(i<0||j<0||len<0)
        return INFEASIBLE;
    LinkList p,q,s;
    int k;
    p=*la;
    for(k=1;k<i;k++)//pָ��la�ĵ�i��Ԫ��
        p=p->next;
    if(p==NULL)//la���޵�i��Ԫ��
        return ERROR;
    q=p;
    for(k=1;k<=len;k++)//qָ��la�ĵ�i+len��Ԫ��
        q=q->next;
    if(q==NULL)//la���޵�i+len��Ԫ��
        return ERROR;
    s=*lb;
    for(k=1;k<j-1;k++)//sָ��lb�ĵ�j-1��Ԫ��
        s=s->next;
    if(s==NULL)//lb���޵�j-1��Ԫ��
        return ERROR;
    LinkList rs=s->next;
    s->next=p->next;//����Ԫ��
    LinkList rq=q->next;
    q->next=s->next;
    p->next=rq->next;//ɾ��Ԫ��
    return OK;
}//DeleteAndInsertSub

//ԭ�㷨����ȷ,û��ɾ��la�е�Ԫ��,��2��whileѭ������ڲ���
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
