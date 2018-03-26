#include<stdio.h>
#include"../../template.h"
#define arrsize 100
#define MAXINT 65535

Status jiecheng(int i, int a[])
{
    //计算i!*2^k的值并分别存入数组a
    int j;
    if(i < 0 || i > arrsize)//i的值不合法
        return ERROR;
    a[0] = 0;
    a[1] = 2;
    for(j = 2; j <= i; j++)
    {
        if(MAXINT / a[j - 1] < 2 * j)//结果大于计算机中允许的最大值
            return OVERFLOW;
        a[j] = a[j - 1] * 2 * j;
    }
    return OK;
}

int main()
{
    int k;
    int a[arrsize];
    scanf("%d", &k);
    printf("计算%d!*2^%d=", k, k);
    if(jiecheng(k, a) == OK)
        printf("%d", &a[k]);
}
