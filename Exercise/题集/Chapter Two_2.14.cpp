Status LENGTH(LinkList L)
{
    //求带头结点的单链表的长度
    LinkList p;
    int i = 0;
    p = L->next;
    while(p)
    {
        i++;
        p = p->next;
    }
    return i;
}
