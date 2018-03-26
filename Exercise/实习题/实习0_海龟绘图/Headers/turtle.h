#ifndef TURTLE_H_INCLUDED
#define TURTLE_H_INCLUDED

#define UP 0
#define DOWN 1
#define Pi 3.1415926
#define Pen_Up 49
#define Pen_Down 50
#define Move_Forward 51
#define Move_BackForward 52
#define New_Pos 53
#define Change_Color 54
#define Turn_Angle 55
#define Turn_Degrees 56
#define Clear 57
#define Exit 27

typedef int penState;//ȡֵUP��DOWN

typedef struct//λ��
{
    float v, h;
} aPoint;

typedef struct
{
    int heading;//��ͷ(����)���򣬼�ƹ�ͷ����
    penState pen;//����״̬,UP̧�ʣ�DOWN���
    int color;//���ʵ�ǰ��ɫ
    aPoint Pos;//���굱ǰλ��
} newTurtle;

void Change_Line_Color();
void Clear_Menu();
void Clear_Draw();
void Dynamic_Window();
void Dynamic_State();
void Menu_List();
void Move(int steps);
void MoveTTo(aPoint newPos);
void StartTurtleGraphics();
void Paint_Turtle();
void PenUp();
void PenDown();
void Play_Music();
void run();
void StartTurtle();
void SetTurtleColor(int color);
void StartTurtleGraphics();
int TurtleHeading();
aPoint* TurtlePos();
void Turn(int degrees);
void TurnTTo(float angle);

#endif // TURTLE_H_INCLUDED
