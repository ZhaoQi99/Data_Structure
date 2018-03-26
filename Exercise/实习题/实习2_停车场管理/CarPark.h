#ifndef CARPARK_H_INCLUDED
#define CARPARK_H_INCLUDED

#include"Stack.h"
#include"Queue.h"
#include<string.h>
#include<time.h>
#include<conio.h>

typedef struct
{
    SqStack S;//停车场
    LinkQueue Q;//便道
    int Max_Size;//停车场最大容量
    int price;//停车场费用单价
}CarPark;

void Show_Start();
//系统初始化界面

void Show_Now();
//显示当前功能

void End();
//退出

Status Start(CarPark &C);
//初始化停车场

Status Arrive_Car(CarPark &C);
//车辆到达

Status Leave_Car(CarPark &C);
//车辆离开

Status Search(CarPark C);
//查询当前停车场所有车位状态

void Time();
//获取当前系统时间

void Work(char cmd);
//解释执行操作命令cmd

void ReadCommand(char &cmd);
//读入操作命令符

#endif // CARPARK_H_INCLUDED

