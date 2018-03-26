/*
Problem:ͣ��������
Author:QiZhao
Data:2017-10-31
Description:��ε�������ݽṹ�α�Դ��
Copyright  2017 QiZhao. All rights reserved.
*/
#include<stdio.h>
#include"CarPark.h"

extern CarPark C;
void Time(char* s)
{
    time_t timep;
    time(&timep);
    strcpy(s,ctime(&timep));
}

void Show_Start()
{
    char s[30];
    Time(s);
    memset(s+25,'\0',sizeof(char));
    //ϵͳ��ʼ������
    printf("\t������������������������������������������\n");
    printf("\t��\t ***********************ͣ��������ϵͳ************************\t\t��\n");
    printf("\t��\t***************************************************************\t\t��\n");
    printf("\t��\t\t\tWelocme To CarPark Management System\t\t\t��\n");
    printf("\t��\t***************************************************************\t\t��\n");
    printf("\t��\t***********************�� ��ʼ ��***********************\t\t��\n");
    printf("\t��\t���ߣ�����\t\t\t ϵͳʱ��: %24.24s\t��\n",s);
    printf("\t������������������������������������������\n");
    printf("\n\n");
    printf("�밴�������ʼ��ʼ��ͣ��������ϵͳ:\n");
    return;
}

void Show_Now()
{
    char s[30];
    Time(s);
    memset(s+25,'\0',sizeof(char));
    //��ʾ��ǰ����
    system("cls");
    printf("\t������������������������������������������\n");
    printf("\t��\t ***********************ͣ��������ϵͳ************************\t\t��\n");
    printf("\t��\t***************************************************************\t\t��\n");
    printf("\t��\t\t\tWelocme To CarPark Management System\t\t\t��\n");
    printf("\t��\t***************************************************************\t\t��\n");
    printf("\t��\t***********************�� <1>���� ��***********************\t\t��\n");
    printf("\t��\t***********************�� <2>���� ��***********************\t\t��\n");
    printf("\t��\t***********************�� <3>��ѯ ��***********************\t\t��\n");
    printf("\t��\t***********************�� <4>�˳� ��***********************\t\t��\n");
    printf("\t��\t���ߣ�����\t\t\t ϵͳʱ��: %24.24s\t��\n",s);
    printf("\t������������������������������������������\n");
    printf("\n\n");
}

void End()
{
    char s[30];
    Time(s);
    memset(s+25,'\0',sizeof(char));
    //�˳�
    printf("�Ƿ��˳�ͣ��������ϵͳ?(Y/N)\n");
    char cmd=getch();
    if(cmd=='y'||cmd=='Y')
        exit(0);
    else
        Show_Now();
}

Status Start(CarPark &C)
{
    //��ʼ��ͣ����
    int Size;
    int price;
    printf("������ͣ���������ͣ����:");
    scanf("%d",&Size);
    if(!InitList(C.S,Size))
        return ERROR;
    if(!InitQueue(C.Q))
        return ERROR;
    C.Max_Size=Size;
    printf("������ͣ������ͣ�����õĵ���:");
    scanf("%d",&price);
    C.price=price;
    printf("���ڽ���ϵͳ....\n");
    system("pause");
    return OK;
}

Status Arrive_Car(CarPark &C)
{
    //��������
    ElemType e;
    printf("�г�����ͣ����!!!!\n");
    printf("�����복�ƺ���:");
    scanf("%s",e.Id);
    printf("�����뵽��ʱ��:");
    scanf("%d",&e.Arrive);
    printf("\n");
    if(StackLength(C.S)==C.Max_Size)//ͣ��������
    {
        printf("ͣ��������,�뽫��ͣ�ڱ���Ⱥ�\n");
        EnQueue(C.Q,e);
        printf("���ƺ�Ϊ%s�ĳ���������\n",e.Id);
        printf("����ϵȴ�����Ϊ:%d\n",QueueLength(C.Q));
    }
    else//ͣ�������п�λ
    {
        Push(C.S,e);
        printf("ͣ�������п�λ,��������ͣ����!\n");
        printf("�뽫��ͣ��%d�ų�λ\n",StackLength(C.S));
        printf("-------------------------------------------\n");
        printf("|���ƺ�:%s|����ʱ��:%d|��λ��:%d|\n",e.Id,e.Arrive,StackLength(C.S));
        printf("-------------------------------------------\n");
    }
    return OK;
}

Status Leave_Car(CarPark &C)
{
    //�����뿪
    int num;
    int leave_time;
    ElemType e;
    int pay;
    if(StackEmpty(C.S))
    {
        printf("ͣ�����л�û�г�Ŷ!\n");
        return OK;
    }
    printf("�г���Ҫ�뿪ͣ����!!!!\n");
    printf("������Ҫ�뿪�ĳ������ڵĳ�λ:");
    scanf("%d",&num);
    while(num<1||num>StackLength(C.S))
    {
        printf("��������,����������!\n");
        printf("������Ҫ�뿪�ĳ������ڵĳ�λ:");
        scanf("%d",&num);
    }
    //��ʼ����ʱջ
    SqStack S;
    if(!InitList(S,StackLength(C.S)))
        return ERROR;
    //�ҵ�ͣ�ڳ�λΪnum�ĳ�����Ϣ
    while(StackLength(C.S)!=num)//��λ�Ŵ�1��ʼ
    {
        Pop(C.S,e);
        Push(S,e);
    }
    Pop(C.S,e);
    //�����뿪ʱ��,�������
    printf("�������뿪ʱ��:");
    scanf("%d",&leave_time);
    while(leave_time<=e.Arrive)//��ֹ���ַ���Ϊ���������
    {
        printf("�뿪ʱ�䲻��С�ڵ���ʱ��,����������.\n");
        scanf("%d",&leave_time);
    }
    pay=(leave_time-e.Arrive)*C.price;
    printf("-------------------------------------------\n");
    printf("|���ƺ�:%s|����ʱ��:%d|ͣ������:%d|\n",e.Id,e.Arrive,pay);
    printf("-------------------------------------------\n");
    //��ͣ������ʱջ�ĳ�ͣ��ͣ������
    while(!StackEmpty(S))
    {
        Pop(S,e);
        Push(C.S,e);
    }
    //��������г�,�򽫱���ϵĵ�һ����ͣ��ͣ����
    if(!QueueEmpty(C.Q))
    {
        DeQueue(C.Q,e);
        int temp;
        printf("ͣ�ڱ���ĵ�һ������Ҫ����ͣ��������\n");
        printf("�������ʱ��ʱ��:");
        scanf("%d",&temp);
        e.Arrive=temp;
        printf("�뽫��ͣ��%d�ų�λ\n",C.Max_Size);
        printf("-------------------------------------------\n");
        printf("|���ƺ�:%s|����ʱ��:%d|��λ��:%d|\n",e.Id,e.Arrive,StackLength(C.S));
        printf("-------------------------------------------\n");
        Push(C.S,e);
    }
    return OK;
}

Status Search(CarPark C)
{
    //��ѯ��ǰͣ�������г�λ״̬
    int i;
    ElemType e;
    SqStack temp;
    int num1=StackLength(C.S);
    int num2=QueueLength(C.Q);
    if(!InitList(temp,num1))
        return ERROR;
    printf("ͣ�����й���%d����λ,ʣ�೵λ:%d,����ϵȴ�����Ϊ:%d\n",C.Max_Size,C.Max_Size-num1,num2);
    //����һ����ʱջ,ʹ�ÿ��Դ�1�ų�λ��ʼ����ͣ�����еĳ�
    for(i=1;i<=num1;i++)
    {
        Pop(C.S,e);
        Push(temp,e);
    }
    printf("------------------------------------------------\n");
    printf("ͣ����:\n");
    for(i=1;i<=num1;)
    {
        Pop(temp,e);
        printf("|��λ��:%d|���ƺ�:%s|����ʱ��:%d|\n",i,e.Id,e.Arrive);
        if(i++%2==0)
            printf("\n");
    }
    if(!QueueEmpty(C.Q))
    {
        printf("------------------------------------------------\n");
        printf("���:\n");
    }
    i=1;
    while(!QueueEmpty(C.Q))
    {
        DeQueue(C.Q,e);
        printf("|�ڶ����е�λ��:%d|���ƺ�:%s|����ʱ��:%d|\n",i,e.Id,e.Arrive);
        i++;
    }
    return OK;
}

void ReadCommand(char &cmd)
{
    //������������
    do
    {
        cmd=getch();
    }while((int)(cmd-'0')<1||(int)(cmd-'0')>4);
}

void Work(char cmd)
{
    //����ִ�в�������cmd
    switch(cmd)
    {
        case '1':
            Arrive_Car(C);
            break;
        case '2':
            Leave_Car(C);
            break;
        case '3':
            Search(C);
            break;
        case '4':
            End();
            break;
    }
    system("pause");
    Show_Now();
}



