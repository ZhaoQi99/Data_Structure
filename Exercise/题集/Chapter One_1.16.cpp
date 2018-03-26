#include<stdio.h>

void sort()
{
    //自大至小依次输出顺序的三个整数x,y,z的值
    int x,y,z;
    int temp;
    scanf("%d %d %d", &x, &y, &z);
    if(x <= y) //使x>=y
    {
        temp = x;
        x = y;
        y = temp;
    }
    if(y <= z) //使y>=z
    {
        temp = y;
        y = z;
        z = temp;
    }
    if(x <= y) //使x>=y
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
    //自大至小依次输出顺序的三个整数x,y,z的值
    scanf(x, y, z);
    if(x <= y) //使x>=y
    {
        temp = x;
        x = y;
        y = temp;
    }
    if(y <= z) //使y>=z
    {
        temp = y;
        y = z;
        z = temp;
    }
    if(x <= y) //使x>=y
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
