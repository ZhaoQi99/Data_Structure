Status Algo_2_22(LinkList L)
{
    //�Դ�ͷ���ĵ�����ʵ�־͵�����
    if(!L||!L->next)//�������ڻ�����Ϊ��
        return ERROR;
    LinkList p,pr;
    p=L->next;
    L->next=NULL;
    while(p)
    {
        pr=p;
        p=p->next;
        pr->next=L->next;//���뵽��ͷ
        L->next=pr;
    }
    return OK;
}
