#include"../Headers/turtle.h"
#include<graphics.h>
#include<math.h>
#include<stdio.h>

newTurtle turtle;

void StartTurtleGraphics()
{
    //显示作图窗口,并在窗口内写出本人的姓名、上机号和实习题号
    setinitmode(INIT_RENDERMANUAL);//取消开场动画 logo
    initgraph(640, 480); //建立窗口
    setcolor(RED);//设置矩形颜色
    setlinestyle(DOTTED_LINE);//设置当前线型为虚线型
    rectangle(40, 10, 600, 45); //画矩形
    setcolor(YELLOW);//设置文本颜色
    setfont(15, 0, "宋体");//设置字体,12为字体高度,相当于小五号字体
    outtextxy(60, 20, "姓名:赵旗"); //写出姓名
    outtextxy(150, 20, "上机号:001"); //写出上机号
    outtextxy(250, 20, "实习题号:0.3海龟作图"); //写出实习题号
    outtextxy(430, 20, "正在播放:天空之城.mp3");
    setcolor(GREEN);
    rectangle(190, 50, 600, 450);//绘图区域
    rectangle(40, 50, 180, 450);//菜单区域    Play_Music();
    return;
}

void Paint_Turtle()
{
    //画一只小乌龟
    float x, y;
    setcolor(GREEN);
    circle(turtle.Pos.h, turtle.Pos.v, 15); //画一个圆作为龟壳
    line(turtle.Pos.h - 15.00 / 1.414, turtle.Pos.v - 15.00 / 1.414, turtle.Pos.h - 30.00 / 1.414, turtle.Pos.v - 30.00 / 1.414);//画四条线作为的乌龟的四条腿
    line(turtle.Pos.h + 15.00 / 1.414, turtle.Pos.v - 15.00 / 1.414, turtle.Pos.h + 30.00 / 1.414, turtle.Pos.v - 30.00 / 1.414);//画四条线作为的乌龟的四条腿
    line(turtle.Pos.h + 15.00 / 1.414, turtle.Pos.v + 15.00 / 1.414, turtle.Pos.h + 30.00 / 1.414, turtle.Pos.v + 30.00 / 1.414);//画四条线作为的乌龟的四条腿
    line(turtle.Pos.h - 15.00 / 1.414, turtle.Pos.v + 15.00 / 1.414, turtle.Pos.h - 30.00 / 1.414, turtle.Pos.v + 30.00 / 1.414);//画四条线作为的乌龟的四条腿
    x = turtle.Pos.h + 20 * cos(turtle.heading * Pi / 180); //龟头的圆心的横坐标
    y = turtle.Pos.v + 20 * sin(turtle.heading * Pi / 180); //龟头的圆心的纵坐标
    circle(x, y, 5); //画一个圆作为乌龟的头
    return;
}

void StartTurtle()
{
    //令海龟处于作图的初始状态,即显示作图窗口,并将海龟定位在窗口正中;
    //置画笔状态为落笔、龟头朝向为0度(正东方向)。
    turtle.Pos.h = 400;
    turtle.Pos.v = 250;
    turtle.heading = 0; //置海龟头朝向为x轴正方向
    turtle.color = WHITE; //设置画笔颜色
    turtle.pen = DOWN; //海龟初始状态为落笔
    Paint_Turtle();//画乌龟
}

void Menu_List()
{
    //菜单窗口
    setcolor(BLUE);//设置字体颜色
    outtextxy(50, 55, "Menu :");
    setcolor(GREEN);//设置线条颜色
    line(43, 80, 180, 80); //画一条线
    setcolor(YELLOW);//设置字体颜色
    outtextxy(50, 85, "Pen Up");
    outtextxy(50, 105, "Pen Down");
    outtextxy(50, 125, "Move Forward");
    outtextxy(50, 145, "Move Backward");
    outtextxy(50, 165, "New Pos");
    outtextxy(50, 185, "Change Color");
    outtextxy(50, 205, "Turn Angle");
    outtextxy(50, 225, "Turn Degrees");
    outtextxy(50, 247, "Clear");
    outtextxy(50, 270, "Exit");
    setcolor(WHITE);
    outtextxy(160, 85, "1");
    outtextxy(160, 105, "2");
    outtextxy(160, 125, "3");
    outtextxy(160, 145, "4");
    outtextxy(160, 165, "5");
    outtextxy(160, 185, "6");
    outtextxy(160, 205, "7");
    outtextxy(160, 225, "8");
    outtextxy(160, 247, "9");
    outtextxy(153, 270, "Esc");
    setcolor(GREEN);
    line(40, 290, 180, 290);
    return;
}

void Dynamic_Window()
{
    //实时参数窗口
    setcolor(YELLOW);
    outtextxy(50, 300, "Pen:");
    outtextxy(50, 320, "Color:");
    outtextxy(50, 340, "Time:");
    outtextxy(50, 360, "Heading:");
    outtextxy(50, 380, "Pos");
    outtextxy(50, 400, "X:");
    outtextxy(50, 420, "Y:");
    Dynamic_State();
    return;
}

void Dynamic_State()
{
    //显示实时参数
    if(turtle.pen == UP)
        outtextxy(140, 300, "UP");
    else
        outtextxy(140, 300, "DOWN");
    setfillcolor(turtle.color);
    bar(120, 325, 170, 335);
    char str[100];
    float temp = fclock();
    sprintf(str, "%.2f", temp);
    outtextxy(140, 342, str);
    sprintf(str, "%d", turtle.heading);
    outtextxy(140, 362, str);
    sprintf(str, "%.2f", turtle.Pos.h);
    outtextxy(120, 402, str);
    sprintf(str, "%.2f", turtle.Pos.v);
    outtextxy(120, 422, str);
    return;
}

void PenUp()
{
    //改变画笔状态为抬笔。从此时起，海龟移动将不在屏幕上作图。
    turtle.pen = UP;
    Clear_Menu();
    Menu_List();
    Dynamic_Window();
    return;
}

void PenDown()
{
    //改变画笔状态为落笔。从此时起，海龟移动将在屏幕上作图
    turtle.pen = DOWN;
    Clear_Menu();
    Menu_List();
    Dynamic_Window();
    return;
}

int TurtleHeading()
{
    //返回海龟的当前朝向的角度
    return turtle.heading;
}

aPoint* TurtlePos()
{
    //返回海龟的当前位置
    aPoint* temp = &turtle.Pos;
    return temp;
}

/*
void Clear_Turtle()
{
    //清除当前所画海龟
    setfillcolor(BLACK);
    aPoint* temp = TurtlePos();
    Pieslice(temp->h, temp->v, 0, 360, 18);
    return;
}
*/

void Move(int steps)
{
    //依照海龟头的当前朝向,向前移动海龟steps步
    float x, y;
    x = turtle.Pos.h + steps * 10 * cos(turtle.heading * Pi / 180); //10代表一步的大小
    y = turtle.Pos.v + steps * 10 * sin(turtle.heading * Pi / 180);
    aPoint tempPos;
    tempPos.h = x;
    tempPos.v = y;
    MoveTTo(tempPos);
    return;
}

void Turn(int degrees)
{
    //改变海龟头的当前朝向, 逆时针旋转degrees度
    //Clear_Draw();
    turtle.heading += (360-degrees)%360;
    Paint_Turtle();
    Clear_Menu();
    Menu_List();
    Dynamic_Window();
    return;
}

void MoveTTo(aPoint newPos)
{
    //将海龟移到新的位置Pos。如果是落笔状态，则同时作图
    if(newPos.h>600||newPos.v>480||newPos.h<190||newPos.v<50)//新的位置的坐标不合法
    {
        setcolor(RED);
        outtextxy(300,455,"参数错误,请按任意键退出！");
        getch();
        setfillcolor(BLACK);
        bar(300,455,600,480);
    }
    else//新的位置的坐标合法
    {
        if(turtle.pen == UP) //抬笔状态
        {
            turtle.Pos.h = newPos.h;
            turtle.Pos.v = newPos.v;
        }
        else//落笔状态
        {
            setcolor(turtle.color);
            line(turtle.Pos.h, turtle.Pos.v, newPos.h, newPos.v);
            turtle.Pos.h = newPos.h;
            turtle.Pos.v = newPos.v;
        }
    }
    Paint_Turtle();
    Clear_Menu();
    Menu_List();
    Dynamic_Window();
}

void TurnTTo(float angle)
{
    //改变海龟头的当前朝向为,从正东方向起的angle度
    //Clear_Draw();
    turtle.heading = (int)(360-angle)%360;
    Paint_Turtle();
    Clear_Menu();
    Menu_List();
    Dynamic_Window();
    return;
}

void SetTurtleColor(int color)
{
    //设置海龟画笔的颜色为color
    turtle.color = color;
    return;
}

void Clear_Draw()
{
    //清除绘图区域
    setfillcolor(BLACK);
    bar(200, 60, 598, 442);
    StartTurtle();
    return;
}

void Clear_Menu()
{
    //清除菜单区域
    setfillcolor(BLACK);
    bar(45, 50, 178, 448);
    return;
}

void Play_Music()
{
    //播放背景音乐
    ege::MUSIC music1;// 定义一个MUSIC
    music1.OpenFile("天空之城.mp3");//打开文件天空之城.mp3
    music1.Play();//播放音乐
    return;
}

void Change_Line_Color()
{
    SetTurtleColor(EGERGB(random(255), random(255), random(255)));
    Clear_Menu();
    Menu_List();
    Dynamic_Window();
    Dynamic_State();
    return;
}

void run()
{
    char k = 0;
    for ( ; k != key_esc; ) // key_esc是ege定义的按键常数
    {
        k = getch();
        int temp = (int)k;
        if(temp == Exit)
        {
            cleardevice();
            setfont(60, 0, "宋体");
            outtextxy(200, 100, "谢谢使用！");
            setcolor(WHITE);
            setfont(30, 0, "宋体");
            outtextxy(200, 300, "请按任意键退出....");
            getch();
            closegraph();
            exit(0);
        }
        else
        {
            switch(k)
            {
            case Pen_Up:
                PenUp();
                break;
            case Pen_Down:
                PenDown();
                break;
            case Move_Forward:
                {
                    printf("请按下对应步数所对应的数字键:(1-9)\n");
                    char c = getch();
                    int step = (int)c - 48;
                    Move(step);
                    break;
                }
            case Move_BackForward:
                {
                    printf("请按下对应步数所对应的数字键:(1-9)\n");
                    char c = getch();
                    int step = (int)c - 48;
                    Move(-step);
                    break;
                }
            case New_Pos:
                {
                    float a, b;
                    printf("请输入你要将海龟移动到的位置:\n");
                    scanf("%f %f", &a, &b);
                    aPoint tempPos;
                    tempPos.h = a;
                    tempPos.v = b;
                    MoveTTo(tempPos);
                }
                break;
            case Change_Color:
                Change_Line_Color();
                break;
            case Turn_Angle:
                {
                    int a;
                    printf("请输入海龟要转的角度:\n");
                    scanf("%d", &a);
                    Turn(a);
                    break;
                }
            case Turn_Degrees:
                {
                    float a;
                    printf("请输入海龟要朝向的角度:\n");
                    scanf("%f", &a);
                    Turn(a);
                    break;
                }
            case Clear:
                {
                    Clear_Draw();
                    break;
                }
            }
        }
    }
}

