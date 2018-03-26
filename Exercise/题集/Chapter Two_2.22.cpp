Status Algo_2_22(LinkList L)
{
    //对带头结点的单链表实现就地逆置
    if(!L||!L->next)//链表不存在或链表为空
        return ERROR;
    LinkList p,pr;
    p=L->next;
    L->next=NULL;
    while(p)
    {
        pr=p;
        p=p->next;
        pr->next=L->next;//插入到表头
        L->next=pr;
    }
    return OK;
}
