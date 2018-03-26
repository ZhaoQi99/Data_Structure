Status LOCATE(LinkList L,ElemType x)
{
    //在带头结点的单链表L上查找数据元素x的位置
    //若没找到x,则返回0
    int i=1;
    LinkList p=L->next;
    while(p)
    {
        if(p->data==x)
            return i;
        p=p->next;
        i++;
    }
    return 0;
}
