#include"Polynomial.h"

int main()
{
    polynomial P1, P2, P3;

    printf("*********************************���ж���ʽ�ļӷ�����*********************************\n");
    Test(P1, P2);
    printf("�����Ķ���ʽΪ:\n");
    AddPolyn(P1, P2);
    PrintPolyn(P1);
    system("pause");
    system("cls");

    printf("*********************************���ж���ʽ�ļ�������*********************************\n");
    Test(P1, P2);
    printf("�����Ķ���ʽΪ:\n");
    SubtractPolyn(P1, P2);
    PrintPolyn(P1);
    system("pause");
    system("cls");

    printf("*********************************���ж���ʽ�ĳ˷�����*********************************\n");
    Test(P1, P2);
    printf("�����Ķ���ʽΪ:\n");
    MultiplyPolyn(P1, P2);
    PrintPolyn(P1);
    system("pause");
    system("cls");

    printf("*********************************�����ʽ�ĵ�����*********************************\n");
    Test(P1, P2);
    printf("����ʽP1�ĵ�����Ϊ:\n");
    Derivation(P1, P3);
    PrintPolyn(P3);
    printf("����ʽP2�ĵ�����Ϊ:\n");
    Derivation(P2, P3);
    PrintPolyn(P3);
    system("pause");
    system("cls");

    printf("*********************************����PolynLength����*********************************\n");
    printf("P1��������:%d", PolynLength(P1));
    system("pause");

    return 0;
}
