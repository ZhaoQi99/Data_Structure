#include<stdio.h>
#include"TripleSparseMatrix.cpp"

int main()
{
//    freopen("in.txt","r",stdin);
    TSMatrix M;
    TSMatrix T;

    CreateSMatrix(M);
    printf("ԭϡ�����Ϊ:\n");
    PrintSMatrix(M);

    printf("ת�ú��ϡ�����Ϊ:\n");
    FastTransposeSMatrix(M,T);
    PrintSMatrix(T);

    return 0;
}
