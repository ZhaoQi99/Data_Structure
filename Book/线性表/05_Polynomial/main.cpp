#include<stdio.h>
#include"Polynomial.cpp"
#include"ExtenLinkedList.cpp"

int main()
{
    polynomial P1,P2;
    printf("*********************************���ж���ʽ�ļӷ�����*********************************\n");
    Test(P1,P2);
    printf("�����Ķ���ʽΪ:\n");
    AddPolyn(P1,P2);
    PrintPolyn(P1);

    printf("*********************************���ж���ʽ�ļ�������*********************************\n");
    Test(P1,P2);
    printf("�����Ķ���ʽΪ:\n");
    SubtractPolyn(P1,P2);
    PrintPolyn(P1);

    printf("*********************************���ж���ʽ�ĳ˷�����*********************************\n");
    Test(P1,P2);
    printf("�����Ķ���ʽΪ:\n");
    MultiplyPolyn(P1,P2);
    PrintPolyn(P1);

    printf("*********************************����PolynLength����*********************************\n");
    printf("P1��������:%d",PolynLength(P1));

    return 0;

}
