#include"Polynomial.h"

int main()
{
    polynomial P1, P2, P3;

    printf("*********************************进行多项式的加法运算*********************************\n");
    Test(P1, P2);
    printf("运算后的多项式为:\n");
    AddPolyn(P1, P2);
    PrintPolyn(P1);
    system("pause");
    system("cls");

    printf("*********************************进行多项式的减法运算*********************************\n");
    Test(P1, P2);
    printf("运算后的多项式为:\n");
    SubtractPolyn(P1, P2);
    PrintPolyn(P1);
    system("pause");
    system("cls");

    printf("*********************************进行多项式的乘法运算*********************************\n");
    Test(P1, P2);
    printf("运算后的多项式为:\n");
    MultiplyPolyn(P1, P2);
    PrintPolyn(P1);
    system("pause");
    system("cls");

    printf("*********************************求多项式的导函数*********************************\n");
    Test(P1, P2);
    printf("多项式P1的导函数为:\n");
    Derivation(P1, P3);
    PrintPolyn(P3);
    printf("多项式P2的导函数为:\n");
    Derivation(P2, P3);
    PrintPolyn(P3);
    system("pause");
    system("cls");

    printf("*********************************函数PolynLength测试*********************************\n");
    printf("P1的项数是:%d", PolynLength(P1));
    system("pause");

    return 0;
}
