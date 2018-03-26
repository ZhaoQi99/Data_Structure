#include<stdio.h>
#include"../template.h"

Status Fibonacci(int k, int m, int &e)
{
    //求k阶斐波那契数列的第m项e
    //temp[i]存储数列的每一项
    //根据形参m与k,可分为4种情况
    if(m < 0 || k < 2)//m或k的值不合法
        return ERROR;
    if(m >= 0 && m < k - 1) //0<=m<k-1时的情况
    {
        e = 0;
    }
    if(m == k - 1)//m等于k-1时的情况
    {
        e = 1;
    }
    if(m >= k)//m大于或等于k的情况
    {
        int temp[m+10];
        int i,j,sum;
        for(i=0;i<=k-1;i++)
            temp[i]=0;//k阶斐波那契数列的前k-1项为0
        temp[k-1]=1;//第k项为1
        for(i=k;i<=m;i++)
        {
            sum=0;
            for(j=i-k;j<=i-1;j++)//每一项都是其前k-1项的和
                sum+=temp[j];
            temp[i]=sum;
        }
        e=temp[m];
    }
    return OK;
}
/*
Status Fibonacci(int k, int m, int &e)
{
    //求k阶斐波那契数列的第m项e
    //temp[m]存储数列的每一项
    //根据形参m与k,可分为4种情况
    if(m < 0 || k < 2)//m或k的值不合法
        return ERROR;
    if(m >= 0 && m < k - 1) //0<=m<k-1时的情况
    {
        e = 0;
    }
    if(m == k - 1)//m等于k-1时的情况
    {
        e = 1;
    }
    if(m >= k)//m大于或等于k的情况
    {
        int temp[m+10];
        for(i=0;i<=k-1;i++)
            temp[i]=0;//k阶斐波那契数列的前k-1项为0
        temp[k-1]=1;//第k项为1
        for(i=k;i<=m;i++)
        {
            sum=0;
            for(j=i-k;j<=i-1;j++)//每一项都是其前k-1项的和
                sum+=temp[j];
            temp[i]=sum;
        }
        e=temp[m];
    }
    return OK;
}//Fibonacci
*/
int main()
{
    int e;
    Fibonacci(4,50,e);
    printf("%d",e);
    return 0;
}
