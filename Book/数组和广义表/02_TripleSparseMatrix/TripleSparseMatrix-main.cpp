#include<stdio.h>
#include"TripleSparseMatrix.cpp"

int main()
{
//    freopen("in.txt","r",stdin);
    TSMatrix M;
    TSMatrix T;

    CreateSMatrix(M);
    printf("原稀疏矩阵为:\n");
    PrintSMatrix(M);

    printf("转置后的稀疏矩阵为:\n");
    FastTransposeSMatrix(M,T);
    PrintSMatrix(T);

    return 0;
}
