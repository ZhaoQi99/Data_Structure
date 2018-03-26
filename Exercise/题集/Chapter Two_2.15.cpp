Status Algo_2_15(LinkList ha, LinkList hb, LinkList *hc,int m,int n)
{
    //Ëã·¨¸´ÔÓ¶ÈÎªm¡Ün?O(m):O(n)
    LinkList  pa, pb;
    pa = ha;
    pb = hb;
    if(m<=n)
    {
        while(pa->next)
            pa=pa->next;
        hc=*ha;
        pa->next=pb->next;
    }
    else
    {
        while(pb->next)
            pb=pb->next;
        hc=hb;
        pb->next=pa->next;
    }
    return OK;
}
