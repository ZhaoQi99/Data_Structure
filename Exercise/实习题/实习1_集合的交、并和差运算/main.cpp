#include"Set.h"
#include<conio.h>
#define MAXSIZE 100

void Test()
{
    printf("*************************************Test*************************************\n");
    Set S1, S2, S3;
    char s[MAXSIZE];
    /********����A����*********/
    printf("�����뼯��A�е�Ԫ��:\n");
    gets(s);//scnafֻ�ܶ���һ��������ַ���
    CreateSet(S1, s);
    printf("����A�е�Ԫ��Ϊ:");
    PrintSet(S1);
    /********����B����*********/
    printf("�����뼯��B�е�Ԫ��:\n");
    gets(s);
    CreateSet(S2, s);
    printf("����B�е�Ԫ��Ϊ:");
    PrintSet(S2);
    printf("��ѡ��Ҫ����Ķ���1:A��B 2:A��B 3:A-B 4:A��B 5:�˳�\n");
    char cmd = '0';
    while(cmd != '5')
    {
        cmd = getch();
        while(cmd < '1' || cmd > '5')
        {
            printf("�������������������\n");
            cmd = getch();
        }
        switch(cmd)
        {
        case '1':
            /********��������*********/
            Union(S3, S1, S2);
            printf("A��B��Ԫ��Ϊ:");
            PrintSet(S3);
            DestroySet(S3);
            break;

        case '2':
            /********��������*********/
            Intersection(S3, S1, S2);
            printf("A��B��Ԫ��Ϊ:");
            PrintSet(S3);
            DestroySet(S3);
            break;

        case '3':
            /********��������*********/
            Different(S3, S1, S2);
            printf("A-B��Ԫ��Ϊ:");
            PrintSet(S3);
            DestroySet(S3);
            break;

        case '4':
            /********���������*********/
            Xor(S3, S1, S2);
            printf("A��B��Ԫ��Ϊ:");
            PrintSet(S3);
            DestroyList(S3);
            break;
        case '5':
            printf("���ڽ�������........\n");
            exit(0);
        }
        printf("��ѡ��Ҫ����Ķ���1:A��B 2:A��B 3:A-B 4:A��B 5:�˳�\n");
    }
}
int main()
{
    system("@title ���ϵĲ������Ͳ�����");
    //freopen("in.txt","r",stdin);
    Test();
    return 0;
}
