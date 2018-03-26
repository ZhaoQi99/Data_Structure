
Status Algo_2_11(SqList &L, ElemType x)
{
    ElemType* newbase;
    int i, j;
    if(L.length == L.listsize) //����ռ䲻��,��������ռ�
    {
        newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if(!newbase)//�ڴ����ʧ��
            exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    for(i = L.length - 1; i >= 0; i--) //iΪ��һ��С�ڻ����x��Ԫ�ص��±�
    {
        if(L.elem[i] <= x)
            break;
    }
    for(j = L.length; j > i; j--) //����i+1��Ԫ�غ������Ԫ�غ���һλ
        L.elem[j] = L.elem[j - 1];
    L.elem[i + 1] = x;
    L.length++;
    return OK;
}
