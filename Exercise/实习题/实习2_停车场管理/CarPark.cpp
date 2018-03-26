/*
Problem:停车场管理
Author:QiZhao
Data:2017-10-31
Description:严蔚敏版数据结构课本源码
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
    //系统初始化界面
    printf("\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
    printf("\t☆\t ***********************停车场管理系统************************\t\t☆\n");
    printf("\t☆\t***************************************************************\t\t☆\n");
    printf("\t☆\t\t\tWelocme To CarPark Management System\t\t\t☆\n");
    printf("\t☆\t***************************************************************\t\t☆\n");
    printf("\t☆\t***********************┊ 开始 ┊***********************\t\t☆\n");
    printf("\t☆\t作者：赵旗\t\t\t 系统时间: %24.24s\t☆\n",s);
    printf("\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
    printf("\n\n");
    printf("请按任意键开始初始化停车场管理系统:\n");
    return;
}

void Show_Now()
{
    char s[30];
    Time(s);
    memset(s+25,'\0',sizeof(char));
    //显示当前功能
    system("cls");
    printf("\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
    printf("\t☆\t ***********************停车场管理系统************************\t\t☆\n");
    printf("\t☆\t***************************************************************\t\t☆\n");
    printf("\t☆\t\t\tWelocme To CarPark Management System\t\t\t☆\n");
    printf("\t☆\t***************************************************************\t\t☆\n");
    printf("\t☆\t***********************┊ <1>进车 ┊***********************\t\t☆\n");
    printf("\t☆\t***********************┊ <2>出车 ┊***********************\t\t☆\n");
    printf("\t☆\t***********************┊ <3>查询 ┊***********************\t\t☆\n");
    printf("\t☆\t***********************┊ <4>退出 ┊***********************\t\t☆\n");
    printf("\t☆\t作者：赵旗\t\t\t 系统时间: %24.24s\t☆\n",s);
    printf("\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
    printf("\n\n");
}

void End()
{
    char s[30];
    Time(s);
    memset(s+25,'\0',sizeof(char));
    //退出
    printf("是否退出停车场管理系统?(Y/N)\n");
    char cmd=getch();
    if(cmd=='y'||cmd=='Y')
        exit(0);
    else
        Show_Now();
}

Status Start(CarPark &C)
{
    //初始化停车场
    int Size;
    int price;
    printf("请输入停车场的最大停车量:");
    scanf("%d",&Size);
    if(!InitList(C.S,Size))
        return ERROR;
    if(!InitQueue(C.Q))
        return ERROR;
    C.Max_Size=Size;
    printf("请输入停车场的停车费用的单价:");
    scanf("%d",&price);
    C.price=price;
    printf("正在进入系统....\n");
    system("pause");
    return OK;
}

Status Arrive_Car(CarPark &C)
{
    //车辆到达
    ElemType e;
    printf("有车到达停车场!!!!\n");
    printf("请输入车牌号码:");
    scanf("%s",e.Id);
    printf("请输入到达时间:");
    scanf("%d",&e.Arrive);
    printf("\n");
    if(StackLength(C.S)==C.Max_Size)//停车场已满
    {
        printf("停车场已满,请将车停在便道等候\n");
        EnQueue(C.Q,e);
        printf("车牌号为%s的车进入便道！\n",e.Id);
        printf("便道上等待车数为:%d\n",QueueLength(C.Q));
    }
    else//停车场尚有空位
    {
        Push(C.S,e);
        printf("停车场尚有空位,即将进入停车场!\n");
        printf("请将车停在%d号车位\n",StackLength(C.S));
        printf("-------------------------------------------\n");
        printf("|车牌号:%s|进入时间:%d|车位号:%d|\n",e.Id,e.Arrive,StackLength(C.S));
        printf("-------------------------------------------\n");
    }
    return OK;
}

Status Leave_Car(CarPark &C)
{
    //车辆离开
    int num;
    int leave_time;
    ElemType e;
    int pay;
    if(StackEmpty(C.S))
    {
        printf("停车场中还没有车哦!\n");
        return OK;
    }
    printf("有车将要离开停车场!!!!\n");
    printf("请输入要离开的车的所在的车位:");
    scanf("%d",&num);
    while(num<1||num>StackLength(C.S))
    {
        printf("输入有误,请重新输入!\n");
        printf("请输入要离开的车的所在的车位:");
        scanf("%d",&num);
    }
    //初始化临时栈
    SqStack S;
    if(!InitList(S,StackLength(C.S)))
        return ERROR;
    //找到停在车位为num的车的信息
    while(StackLength(C.S)!=num)//车位号从1开始
    {
        Pop(C.S,e);
        Push(S,e);
    }
    Pop(C.S,e);
    //输入离开时间,计算费用
    printf("请输入离开时间:");
    scanf("%d",&leave_time);
    while(leave_time<=e.Arrive)//防止出现费用为负数的情况
    {
        printf("离开时间不能小于到达时间,请重新输入.\n");
        scanf("%d",&leave_time);
    }
    pay=(leave_time-e.Arrive)*C.price;
    printf("-------------------------------------------\n");
    printf("|车牌号:%s|进入时间:%d|停车费用:%d|\n",e.Id,e.Arrive,pay);
    printf("-------------------------------------------\n");
    //将停放在临时栈的车停至停车场中
    while(!StackEmpty(S))
    {
        Pop(S,e);
        Push(C.S,e);
    }
    //若便道上有车,则将便道上的第一辆车停进停车场
    if(!QueueEmpty(C.Q))
    {
        DeQueue(C.Q,e);
        int temp;
        printf("停在便道的第一辆车将要进入停车场！！\n");
        printf("请输入此时的时间:");
        scanf("%d",&temp);
        e.Arrive=temp;
        printf("请将车停在%d号车位\n",C.Max_Size);
        printf("-------------------------------------------\n");
        printf("|车牌号:%s|进入时间:%d|车位号:%d|\n",e.Id,e.Arrive,StackLength(C.S));
        printf("-------------------------------------------\n");
        Push(C.S,e);
    }
    return OK;
}

Status Search(CarPark C)
{
    //查询当前停车场所有车位状态
    int i;
    ElemType e;
    SqStack temp;
    int num1=StackLength(C.S);
    int num2=QueueLength(C.Q);
    if(!InitList(temp,num1))
        return ERROR;
    printf("停车场中共有%d个车位,剩余车位:%d,便道上等待车数为:%d\n",C.Max_Size,C.Max_Size-num1,num2);
    //借助一个临时栈,使得可以从1号车位开始遍历停车场中的车
    for(i=1;i<=num1;i++)
    {
        Pop(C.S,e);
        Push(temp,e);
    }
    printf("------------------------------------------------\n");
    printf("停车场:\n");
    for(i=1;i<=num1;)
    {
        Pop(temp,e);
        printf("|车位号:%d|车牌号:%s|到达时间:%d|\n",i,e.Id,e.Arrive);
        if(i++%2==0)
            printf("\n");
    }
    if(!QueueEmpty(C.Q))
    {
        printf("------------------------------------------------\n");
        printf("便道:\n");
    }
    i=1;
    while(!QueueEmpty(C.Q))
    {
        DeQueue(C.Q,e);
        printf("|在队列中的位置:%d|车牌号:%s|到达时间:%d|\n",i,e.Id,e.Arrive);
        i++;
    }
    return OK;
}

void ReadCommand(char &cmd)
{
    //读入操作命令符
    do
    {
        cmd=getch();
    }while((int)(cmd-'0')<1||(int)(cmd-'0')>4);
}

void Work(char cmd)
{
    //解释执行操作命令cmd
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



