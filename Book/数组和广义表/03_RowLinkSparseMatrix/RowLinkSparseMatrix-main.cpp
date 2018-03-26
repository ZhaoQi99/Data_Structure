#include"RowLinkSparseMatrix.cpp"
#include<stdio.h>

int main()
{
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    RLSMatrix M,N,Q;

    CreateSMatrix(M);
    printf("The RLSMatrix  M :\n");
    PrinRLSMatrix(M);
    CreateSMatrix(N);
    printf("The RLSMatrix  N :\n");
    PrinRLSMatrix(N);

    MulRLSMatrix(M,N,Q);
    printf("M X N:\n");
    PrinRLSMatrix(Q);

    return 0;
}
