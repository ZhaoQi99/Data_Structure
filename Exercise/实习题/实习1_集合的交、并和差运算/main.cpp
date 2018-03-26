#include"Set.h"
#include<conio.h>
#define MAXSIZE 100

void Test()
{
    printf("*************************************Test*************************************\n");
    Set S1, S2, S3;
    char s[MAXSIZE];
    /********读入A集合*********/
    printf("请输入集合A中的元素:\n");
    gets(s);//scnaf只能读入一个连贯的字符穿
    CreateSet(S1, s);
    printf("集合A中的元素为:");
    PrintSet(S1);
    /********读入B集合*********/
    printf("请输入集合B中的元素:\n");
    gets(s);
    CreateSet(S2, s);
    printf("集合B中的元素为:");
    PrintSet(S2);
    printf("请选择要输出的对象：1:A∪B 2:A∩B 3:A-B 4:A⊕B 5:退出\n");
    char cmd = '0';
    while(cmd != '5')
    {
        cmd = getch();
        while(cmd < '1' || cmd > '5')
        {
            printf("输入有误，清楚重新输入\n");
            cmd = getch();
        }
        switch(cmd)
        {
        case '1':
            /********做并运算*********/
            Union(S3, S1, S2);
            printf("A∪B的元素为:");
            PrintSet(S3);
            DestroySet(S3);
            break;

        case '2':
            /********做交运算*********/
            Intersection(S3, S1, S2);
            printf("A∩B的元素为:");
            PrintSet(S3);
            DestroySet(S3);
            break;

        case '3':
            /********做差运算*********/
            Different(S3, S1, S2);
            printf("A-B的元素为:");
            PrintSet(S3);
            DestroySet(S3);
            break;

        case '4':
            /********做异或运算*********/
            Xor(S3, S1, S2);
            printf("A⊕B的元素为:");
            PrintSet(S3);
            DestroyList(S3);
            break;
        case '5':
            printf("正在结束程序........\n");
            exit(0);
        }
        printf("请选择要输出的对象：1:A∪B 2:A∩B 3:A-B 4:A⊕B 5:退出\n");
    }
}
int main()
{
    system("@title 集合的并、交和差运算");
    //freopen("in.txt","r",stdin);
    Test();
    return 0;
}
