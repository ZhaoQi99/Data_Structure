#include"../template.h"
Status Algo_2_21(SqList &L)
{
    //利用原表的存储空间将顺序表逆置
    if(L.length==0)
        return ERROR;
    int len=L.length;
    int i;
    ElemType temp;
    for(i=0;i<len/2;i++)
    {
        temp=L.elem[i];
        L.elem[i]=L.elem[len-1-i];
        L.elem[len-1-i]=temp;
    }
    return OK;
}
