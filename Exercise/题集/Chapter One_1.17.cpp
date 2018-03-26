#include<stdio.h>
#include"../template.h"

Status Fibonacci(int k, int m, int &e)
{
    //��k��쳲��������еĵ�m��e
    //temp[i]�洢���е�ÿһ��
    //�����β�m��k,�ɷ�Ϊ4�����
    if(m < 0 || k < 2)//m��k��ֵ���Ϸ�
        return ERROR;
    if(m >= 0 && m < k - 1) //0<=m<k-1ʱ�����
    {
        e = 0;
    }
    if(m == k - 1)//m����k-1ʱ�����
    {
        e = 1;
    }
    if(m >= k)//m���ڻ����k�����
    {
        int temp[m+10];
        int i,j,sum;
        for(i=0;i<=k-1;i++)
            temp[i]=0;//k��쳲��������е�ǰk-1��Ϊ0
        temp[k-1]=1;//��k��Ϊ1
        for(i=k;i<=m;i++)
        {
            sum=0;
            for(j=i-k;j<=i-1;j++)//ÿһ�����ǰk-1��ĺ�
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
    //��k��쳲��������еĵ�m��e
    //temp[m]�洢���е�ÿһ��
    //�����β�m��k,�ɷ�Ϊ4�����
    if(m < 0 || k < 2)//m��k��ֵ���Ϸ�
        return ERROR;
    if(m >= 0 && m < k - 1) //0<=m<k-1ʱ�����
    {
        e = 0;
    }
    if(m == k - 1)//m����k-1ʱ�����
    {
        e = 1;
    }
    if(m >= k)//m���ڻ����k�����
    {
        int temp[m+10];
        for(i=0;i<=k-1;i++)
            temp[i]=0;//k��쳲��������е�ǰk-1��Ϊ0
        temp[k-1]=1;//��k��Ϊ1
        for(i=k;i<=m;i++)
        {
            sum=0;
            for(j=i-k;j<=i-1;j++)//ÿһ�����ǰk-1��ĺ�
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
