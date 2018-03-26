Status Algo_2_24(LinkList *La, LinkList *Lb, LinkList *Lc)
{
    //��֪������La��Lb��Ԫ�ذ�ֵ��������
    //�鲢La��Lb�õ��µĵ������Ա�Lc,Lc��Ԫ�ذ�ֵ�ǵݼ�����
    *Lc = *La; //����La��ͷ�����ΪLc��ͷ���
    if(!(*La) || !*Lb || (!((*La)->next) && (!(*Lb)->next))) //La��Lb�����ڻ�������Ϊ��,���ش���
        return ERROR;
    LinkList pa, pb,s;
    pa = (*La)->next;
    pb = (*Lb)->next;
    (*Lc)->next = NULL;
    while(pa && pb) //ͷ�巨
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
