#include<stdio.h>
#include"Polynomial.cpp"
#include"ExtenLinkedList.cpp"

int main()
{
    polynomial P1,P2;
    printf("*********************************进行多项式的加法运算*********************************\n");
    Test(P1,P2);
    printf("运算后的多项式为:\n");
    AddPolyn(P1,P2);
    PrintPolyn(P1);

    printf("*********************************进行多项式的减法运算*********************************\n");
    Test(P1,P2);
    printf("运算后的多项式为:\n");
    SubtractPolyn(P1,P2);
    PrintPolyn(P1);

    printf("*********************************进行多项式的乘法运算*********************************\n");
    Test(P1,P2);
    printf("运算后的多项式为:\n");
    MultiplyPolyn(P1,P2);
    PrintPolyn(P1);

    printf("*********************************函数PolynLength测试*********************************\n");
    printf("P1的项数是:%d",PolynLength(P1));

    return 0;

}
