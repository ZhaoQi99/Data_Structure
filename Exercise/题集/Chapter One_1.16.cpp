#include<stdio.h>

void sort()
{
    //�Դ���С�������˳�����������x,y,z��ֵ
    int x,y,z;
    int temp;
    scanf("%d %d %d", &x, &y, &z);
    if(x <= y) //ʹx>=y
    {
        temp = x;
        x = y;
        y = temp;
    }
    if(y <= z) //ʹy>=z
    {
        temp = y;
        y = z;
        z = temp;
    }
    if(x <= y) //ʹx>=y
    {
        temp = x;
        x = y;
        y = temp;
    }
    printf("%d %d %d", x, y, z);
}

/*
void sort()
{
    //�Դ���С�������˳�����������x,y,z��ֵ
    scanf(x, y, z);
    if(x <= y) //ʹx>=y
    {
        temp = x;
        x = y;
        y = temp;
    }
    if(y <= z) //ʹy>=z
    {
        temp = y;
        y = z;
        z = temp;
    }
    if(x <= y) //ʹx>=y
    {
        temp = x;
        x = y;
        y = temp;
    }
    printf(x, y, z);
}sort
*/

int main()
{
    sort();
    return 0;
}
