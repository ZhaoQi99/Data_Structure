#include<stdio.h>
#include"../../template.h"


Status Algorithm_1_20(int a[],int x,int n,int &ans)
{
    //求一元多项式Pn(x)=Σ(ai*x^i)的值,并以ans返回
    ans=0;
    int i,j;
    if(n<0)//n的值非法
        return ERROR;
    for(i=0;i<n;i++)
    {
        int temp=1;
        for(j=0;j<i;j++)//计算x^i的值
            temp*=x;
        ans+=a[i]*temp;//计算ai*x^i,并求和
    }
    return OK;
}
int main()
{
    int i,n,x,ans;
    scanf("%d",&n);
    scanf("%d",&x);
    int a[n+1];
    for(i=0;i<=n;i++)
        scanf("%d",a[i]);
    if(Algorithm_1_20(a,x,n,ans)==OK)
        printf("%d",ans);
    return 0;
}
