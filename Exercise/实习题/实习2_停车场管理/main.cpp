#include"CarPark.h"

CarPark C;
int main()
{
    system("@title 停车场管理系统");
    char cmd;
    Show_Start();
    cmd=getch();
    Start(C);
    Show_Now();
    while(1)
    {
        ReadCommand(cmd);
        Work(cmd);
    }
    return 0;
}
