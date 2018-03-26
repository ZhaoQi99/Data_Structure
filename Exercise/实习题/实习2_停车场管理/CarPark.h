#ifndef CARPARK_H_INCLUDED
#define CARPARK_H_INCLUDED

#include"Stack.h"
#include"Queue.h"
#include<string.h>
#include<time.h>
#include<conio.h>

typedef struct
{
    SqStack S;//ͣ����
    LinkQueue Q;//���
    int Max_Size;//ͣ�����������
    int price;//ͣ�������õ���
}CarPark;

void Show_Start();
//ϵͳ��ʼ������

void Show_Now();
//��ʾ��ǰ����

void End();
//�˳�

Status Start(CarPark &C);
//��ʼ��ͣ����

Status Arrive_Car(CarPark &C);
//��������

Status Leave_Car(CarPark &C);
//�����뿪

Status Search(CarPark C);
//��ѯ��ǰͣ�������г�λ״̬

void Time();
//��ȡ��ǰϵͳʱ��

void Work(char cmd);
//����ִ�в�������cmd

void ReadCommand(char &cmd);
//������������

#endif // CARPARK_H_INCLUDED

