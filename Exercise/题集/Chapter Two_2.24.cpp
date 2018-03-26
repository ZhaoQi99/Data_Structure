Status Algo_2_24(LinkList *La, LinkList *Lb, LinkList *Lc)
{
    //已知单链表La和Lb的元素按值递增排列
    //归并La和Lb得到新的单链线性表Lc,Lc的元素按值非递减排列
    *Lc = *La; //利用La的头结点作为Lc的头结点
    if(!(*La) || !*Lb || (!((*La)->next) && (!(*Lb)->next))) //La或Lb不存在或两个表都为空,返回错误
        return ERROR;
    LinkList pa, pb,s;
    pa = (*La)->next;
    pb = (*Lb)->next;
    (*Lc)->next = NULL;
    while(pa && pb) //头插法
    {
        if(pa->data <= pb->data)
        {
            s = pa;
            pa = pa->next;
            s->next = (*Lc)->next;
            (*Lc)->next = s;
        }
        else
        {
            s = pb;
            pb = pb->next;
            s->next = (*Lc)->next;
            (*Lc) ->next = s;
        }
    }
    while(pa)
    {
        s = pa;
        pa = pa->next;
        s->next =( *Lc)->next;
        (*Lc)->next = s;
    }
    while(pb)
    {
        s = pb;
        pb = pb->next;
        s->next = (*Lc)->next;
        (*Lc) -> next = s;
    }
    free(*Lb);
    return OK;
}
