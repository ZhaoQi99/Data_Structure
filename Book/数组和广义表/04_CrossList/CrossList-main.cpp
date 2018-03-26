#include<stdio.h>
#include"CrossList.cpp"

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    CrossList M,N,Q;
    CreateSMatrix(M);
    CreateSMatrix(N);

    freopen("CON","r",stdin);
    printf("The CrossList  M :\n");
    PrintSMatrix(M);
    printf("The CrossList  N :\n");
    PrintSMatrix(N);

    AddSMatrix(M,N,Q);
    printf("M + N:\n");
    PrintSMatrix(Q);

    return 0;
}
