#include"../Headers/turtle.h"
#include<graphics.h>
#include<math.h>
#include<stdio.h>

newTurtle turtle;

void StartTurtleGraphics()
{
    //��ʾ��ͼ����,���ڴ�����д�����˵��������ϻ��ź�ʵϰ���
    setinitmode(INIT_RENDERMANUAL);//ȡ���������� logo
    initgraph(640, 480); //��������
    setcolor(RED);//���þ�����ɫ
    setlinestyle(DOTTED_LINE);//���õ�ǰ����Ϊ������
    rectangle(40, 10, 600, 45); //������
    setcolor(YELLOW);//�����ı���ɫ
    setfont(15, 0, "����");//��������,12Ϊ����߶�,�൱��С�������
    outtextxy(60, 20, "����:����"); //д������
    outtextxy(150, 20, "�ϻ���:001"); //д���ϻ���
    outtextxy(250, 20, "ʵϰ���:0.3������ͼ"); //д��ʵϰ���
    outtextxy(430, 20, "���ڲ���:���֮��.mp3");
    setcolor(GREEN);
    rectangle(190, 50, 600, 450);//��ͼ����
    rectangle(40, 50, 180, 450);//�˵�����    Play_Music();
    return;
}

void Paint_Turtle()
{
    //��һֻС�ڹ�
    float x, y;
    setcolor(GREEN);
    circle(turtle.Pos.h, turtle.Pos.v, 15); //��һ��Բ��Ϊ���
    line(turtle.Pos.h - 15.00 / 1.414, turtle.Pos.v - 15.00 / 1.414, turtle.Pos.h - 30.00 / 1.414, turtle.Pos.v - 30.00 / 1.414);//����������Ϊ���ڹ��������
    line(turtle.Pos.h + 15.00 / 1.414, turtle.Pos.v - 15.00 / 1.414, turtle.Pos.h + 30.00 / 1.414, turtle.Pos.v - 30.00 / 1.414);//����������Ϊ���ڹ��������
    line(turtle.Pos.h + 15.00 / 1.414, turtle.Pos.v + 15.00 / 1.414, turtle.Pos.h + 30.00 / 1.414, turtle.Pos.v + 30.00 / 1.414);//����������Ϊ���ڹ��������
    line(turtle.Pos.h - 15.00 / 1.414, turtle.Pos.v + 15.00 / 1.414, turtle.Pos.h - 30.00 / 1.414, turtle.Pos.v + 30.00 / 1.414);//����������Ϊ���ڹ��������
    x = turtle.Pos.h + 20 * cos(turtle.heading * Pi / 180); //��ͷ��Բ�ĵĺ�����
    y = turtle.Pos.v + 20 * sin(turtle.heading * Pi / 180); //��ͷ��Բ�ĵ�������
    circle(x, y, 5); //��һ��Բ��Ϊ�ڹ��ͷ
    return;
}

void StartTurtle()
{
    //��괦����ͼ�ĳ�ʼ״̬,����ʾ��ͼ����,�������궨λ�ڴ�������;
    //�û���״̬Ϊ��ʡ���ͷ����Ϊ0��(��������)��
    turtle.Pos.h = 400;
    turtle.Pos.v = 250;
    turtle.heading = 0; //�ú���ͷ����Ϊx��������
    turtle.color = WHITE; //���û�����ɫ
    turtle.pen = DOWN; //�����ʼ״̬Ϊ���
    Paint_Turtle();//���ڹ�
}

void Menu_List()
{
    //�˵�����
    setcolor(BLUE);//����������ɫ
    outtextxy(50, 55, "Menu :");
    setcolor(GREEN);//����������ɫ
    line(43, 80, 180, 80); //��һ����
    setcolor(YELLOW);//����������ɫ
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
    //ʵʱ��������
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
    //��ʾʵʱ����
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
    //�ı仭��״̬Ϊ̧�ʡ��Ӵ�ʱ�𣬺����ƶ���������Ļ����ͼ��
    turtle.pen = UP;
    Clear_Menu();
    Menu_List();
    Dynamic_Window();
    return;
}

void PenDown()
{
    //�ı仭��״̬Ϊ��ʡ��Ӵ�ʱ�𣬺����ƶ�������Ļ����ͼ
    turtle.pen = DOWN;
    Clear_Menu();
    Menu_List();
    Dynamic_Window();
    return;
}

int TurtleHeading()
{
    //���غ���ĵ�ǰ����ĽǶ�
    return turtle.heading;
}

aPoint* TurtlePos()
{
    //���غ���ĵ�ǰλ��
    aPoint* temp = &turtle.Pos;
    return temp;
}

/*
void Clear_Turtle()
{
    //�����ǰ��������
    setfillcolor(BLACK);
    aPoint* temp = TurtlePos();
    Pieslice(temp->h, temp->v, 0, 360, 18);
    return;
}
*/

void Move(int steps)
{
    //���պ���ͷ�ĵ�ǰ����,��ǰ�ƶ�����steps��
    float x, y;
    x = turtle.Pos.h + steps * 10 * cos(turtle.heading * Pi / 180); //10����һ���Ĵ�С
    y = turtle.Pos.v + steps * 10 * sin(turtle.heading * Pi / 180);
    aPoint tempPos;
    tempPos.h = x;
    tempPos.v = y;
    MoveTTo(tempPos);
    return;
}

void Turn(int degrees)
{
    //�ı亣��ͷ�ĵ�ǰ����, ��ʱ����תdegrees��
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
    //�������Ƶ��µ�λ��Pos����������״̬����ͬʱ��ͼ
    if(newPos.h>600||newPos.v>480||newPos.h<190||newPos.v<50)//�µ�λ�õ����겻�Ϸ�
    {
        setcolor(RED);
        outtextxy(300,455,"��������,�밴������˳���");
        getch();
        setfillcolor(BLACK);
        bar(300,455,600,480);
    }
    else//�µ�λ�õ�����Ϸ�
    {
        if(turtle.pen == UP) //̧��״̬
        {
            turtle.Pos.h = newPos.h;
            turtle.Pos.v = newPos.v;
        }
        else//���״̬
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
    //�ı亣��ͷ�ĵ�ǰ����Ϊ,�������������angle��
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
    //���ú��껭�ʵ���ɫΪcolor
    turtle.color = color;
    return;
}

void Clear_Draw()
{
    //�����ͼ����
    setfillcolor(BLACK);
    bar(200, 60, 598, 442);
    StartTurtle();
    return;
}

void Clear_Menu()
{
    //����˵�����
    setfillcolor(BLACK);
    bar(45, 50, 178, 448);
    return;
}

void Play_Music()
{
    //���ű�������
    ege::MUSIC music1;// ����һ��MUSIC
    music1.OpenFile("���֮��.mp3");//���ļ����֮��.mp3
    music1.Play();//��������
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
    for ( ; k != key_esc; ) // key_esc��ege����İ�������
    {
        k = getch();
        int temp = (int)k;
        if(temp == Exit)
        {
            cleardevice();
            setfont(60, 0, "����");
            outtextxy(200, 100, "ллʹ�ã�");
            setcolor(WHITE);
            setfont(30, 0, "����");
            outtextxy(200, 300, "�밴������˳�....");
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
                    printf("�밴�¶�Ӧ��������Ӧ�����ּ�:(1-9)\n");
                    char c = getch();
                    int step = (int)c - 48;
                    Move(step);
                    break;
                }
            case Move_BackForward:
                {
                    printf("�밴�¶�Ӧ��������Ӧ�����ּ�:(1-9)\n");
                    char c = getch();
                    int step = (int)c - 48;
                    Move(-step);
                    break;
                }
            case New_Pos:
                {
                    float a, b;
                    printf("��������Ҫ�������ƶ�����λ��:\n");
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
                    printf("�����뺣��Ҫת�ĽǶ�:\n");
                    scanf("%d", &a);
                    Turn(a);
                    break;
                }
            case Turn_Degrees:
                {
                    float a;
                    printf("�����뺣��Ҫ����ĽǶ�:\n");
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

