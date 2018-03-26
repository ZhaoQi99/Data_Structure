int Algo_2_12(SqList A,SqList B)
{
    int i=0;
    while(i<A.length&&i<B.length)
    {
        if(A.elem[i]<B.elem[i])
            return -1;
        else if(A.elem[i]>B.elem[i])
            return 1;
        else
            i++;
    }
    if(i<A.length)//AÓÐÊ£Óà
        return 1;
    else if(i<B.length)//BÓÐÊ£Óà
        return -1;
    else//i=A.length=B.length
        return 0;
}
