Status LOCATE(LinkList L,ElemType x)
{
    //�ڴ�ͷ���ĵ�����L�ϲ�������Ԫ��x��λ��
    //��û�ҵ�x,�򷵻�0
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
