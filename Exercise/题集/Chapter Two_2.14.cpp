Status LENGTH(LinkList L)
{
    //���ͷ���ĵ�����ĳ���
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
