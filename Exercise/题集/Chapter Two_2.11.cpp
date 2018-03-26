
Status Algo_2_11(SqList &L, ElemType x)
{
    ElemType* newbase;
    int i, j;
    if(L.length == L.listsize) //储存空间不足,重新申请空间
    {
        newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if(!newbase)//内存分配失败
            exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    for(i = L.length - 1; i >= 0; i--) //i为第一个小于或等于x的元素的下标
    {
        if(L.elem[i] <= x)
            break;
    }
    for(j = L.length; j > i; j--) //将第i+1个元素后的所有元素后移一位
        L.elem[j] = L.elem[j - 1];
    L.elem[i + 1] = x;
    L.length++;
    return OK;
}
