#include<stdio.h>
#include"../../template.h"
#include<stdlib.h>

struct Complex
{
    float a;
    float b;
};

Status Make(Complex* p)
{
    //输入实部与虚部,生成一个复数,以指针p返回其地址
    float a,b;
    scanf("%f %f",&a,&b);
    Complex* r=NULL;
    r=(Complex*)malloc(sizeof(Complex));
    if(!r)
        return ERROR;//生成失败
    p->a=a;
    p->b=b;
    return OK;
}

void print(Complex x)
{
    //输出一个复数
    if(x.a!=0)
        printf("%f",x.a);
    if(x.b!=0)
    {
        if(x.b>0)
            printf("+i%f",x.b);
        else
            printf("-i%f",-x.b);
    }
    return ;
}

int main()
{
    Complex* p;
    return 0;
}

