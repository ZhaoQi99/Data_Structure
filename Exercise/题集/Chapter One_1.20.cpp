#include<stdio.h>
#include"../../template.h"


Status Algorithm_1_20(int a[],int x,int n,int &ans)
{
    //��һԪ����ʽPn(x)=��(ai*x^i)��ֵ,����ans����
    ans=0;
    int i,j;
    if(n<0)//n��ֵ�Ƿ�
        return ERROR;
    for(i=0;i<n;i++)
    {
        int temp=1;
        for(j=0;j<i;j++)//����x^i��ֵ
            temp*=x;
        ans+=a[i]*temp;//����ai*x^i,�����
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
