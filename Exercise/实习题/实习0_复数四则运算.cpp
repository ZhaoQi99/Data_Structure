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
    //����ʵ�����鲿,����һ������,��ָ��p�������ַ
    float a,b;
    scanf("%f %f",&a,&b);
    Complex* r=NULL;
    r=(Complex*)malloc(sizeof(Complex));
    if(!r)
        return ERROR;//����ʧ��
    p->a=a;
    p->b=b;
    return OK;
}

void print(Complex x)
{
    //���һ������
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

