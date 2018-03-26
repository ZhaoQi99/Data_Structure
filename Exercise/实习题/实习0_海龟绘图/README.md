 Turtle_Graphics
=================
# [问题描述]
    设计并实现海龟抽象数据类型Turtle，并以此为基础设计一个演示海龟作图的程序。 
# ［基本要求］
    （1）设置海龟类型的基本操作为：
        void StartTurtleGraphlcs()；
          显示作图窗口，并在窗口内写出本人的姓名、上机号和实验题号。
        void StartTurtle()；
          令海龟处于作图的初始状态。即显示作图窗口，并将海龟定位在窗口正中；
          置画笔状态为落笔、龟头朝向为0度（正东方向）。
        void PenUp()；
          改变画笔状态为抬笔。从此时起，海龟移动将不在屏幕上作图。
        void PenDown()；
          改变画笔状态为落笔。从此时起，海龟移动将在屏幕上作图。
        int TurtleHeadins()
          返回海龟头当前朝向的角度。
        aPoint* TurtlePos()
          返回海龟的当前位置。
        void Move(int steps)
          依照海龟头的当前朝向，向前移动海龟steps步。
        voidTurn (int degrees)
          改变海龟头的当前朝向，逆时针旋转degrees度。
        void MoveTTo(aPoint newPos)
          将海龟移动到新的位置 newPos。如果是落笔状态，则同时作图。
        void TurnTTo(float angle)
          改变海龟头的当前朝向为，从正东方向起的angle度。
        void setTurtleColor (int color)
           设置海龟画笔的颜色为color。
    （2）利用上述定义的海龟实现作图命令，以画出任意长度的线段、任意大小的矩形和圆。
# ［测试数据］
     由学生自行指定线段（的长度）、矩形（的长度和宽度）及圆（的半径）等参数。
# ［实现提示］
    （1）海龟的相关类型说明为：
    #define UP 0
    #define DOWN 1
    typedef int penState;//取值UP或DOWN
    typedef struct//位置
    {
      float v, h;
    } aPoint;
    typedef struct
    {
      int heading;//龟头(画笔)方向，简称鬼头朝向
      penState pen;//画笔状态,UP抬笔，DOWN落笔
      int color;//画笔当前颜色
      aPoint Pos;//海龟当前位置
    } newTurtle;
    
