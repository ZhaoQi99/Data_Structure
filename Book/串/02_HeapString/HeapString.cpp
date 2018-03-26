/*
Problem:���ĶѴ洢��ʾ
Author:QiZhao
Data:2018-01-31
Description:��ε�������ݽṹ�α�Դ��
Copyright  2018 QiZhao. All rights reserved.
*/
#include<stdio.h>
#include"HeapString.h"

Status StrAssign(HString &T,char *s)
{
    //����һ����ֵ����chars���ַ�������
    if(T.ch)
        free(T.ch);//�ͷ�Tԭ�пռ�
    int i;
    char *c;
    for(i=0,c=s;*c;++i,++c);//��s�ĳ���i
    if(!i)
    {
        T.ch=NULL;
        T.length=0;
    }
    else
    {
        if(!(T.ch=(char*)malloc(sizeof(char)*i)))
            exit(OVERFLOW);
        int j;
        for(j=0;j<i;j++)
            T.ch[j]=s[j];
        T.length=i;
    }
    return OK;
}

Status StrCopy(HString &T,HString S)
{
    //�ɴ�S���Ƶõ���T
    if(T.ch)
        free(T.ch);
    T.ch=(char *)malloc(S.length*sizeof(char));
    int i;
    int len=S.length;
    for(i=0;i<len;i++)
        T.ch[i]=S.ch[i];
    T.length=S.length;
    return OK;
}

Status StrEmpty(HString S)
{
    //����SΪ�մ�,�򷵻�TRUE,���򷵻�FALSE
    if(S.length==0)
        return TRUE;
    else
        return FALSE;
}

int  StrLength(HString S)
{
    //����S��Ԫ�ظ���,��Ϊ���ĳ���
    return S.length;
}

Status ClearString(HString &S)
{
    //��S��Ϊ�մ�
    if(S.ch)
    {
        free(S.ch);
        S.ch=NULL;
    }
    S.length=0;
    return OK;
}

Status Concat(HString &T,HString S1,HString S2)
{
    //��T������S1��S2���Ӷ��ɵ��´�
    //��ȡ�Ӵ�֮һ��Ϊ�´�,����������.�磺Concat(T,T,S)
    if(T.ch)
        free(T.ch);//�ͷžɿռ�
    if(!(T.ch=(char*)malloc((S1.length+S2.length)*sizeof(char))))
        exit(OVERFLOW);
    int i;
    for(i=0;i<S1.length;i++)
        T.ch[i]=S1.ch[i];
    T.length=S1.length+S2.length;
    for(i=S1.length;i<T.length;i++)
        T.ch[i]=S2.ch[i-S1.length];
    return OK;
}

Status SubString(HString &Sub,HString S,int pos,int len)
{
    //1<=pos<=StrLength(S)��0<=Len<=StrLength(S)-pos+1
    // ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
    if(pos<1||pos>S.length||len<0||len>S.length-pos+1)
        return ERROR;
    if(Sub.ch)
        free(Sub.ch);
    int i;
    if(!len)
    {
        Sub.ch=NULL;
        Sub.length=0;
    }
    else
    {
        Sub.ch=(char*)malloc(sizeof(char)*len);
        for(i=0;i<len;i++)
            Sub.ch[i]=S.ch[pos+i-1];
        Sub.length=len;
    }
    return OK;
}

int Index(HString S,HString T,int pos)
{
    //1<=pos<=StrLength(S)
    //������S�д��ںʹ�Tֵ��ͬ���Ӵ�,�򷵻���������S�е�pos���ַ�֮���һ�γ��ֵ�λ��;������ֵΪ0
    int i=pos-1,j=0;
    while(i<S.length&&j<T.length)
    {
        if(S.ch[i]==T.ch[j])//�����ȽϺ���ַ�
        {
            ++i;
            ++j;
        }
        else//ָ��������¿�ʼƥ��
        {
            i=i-j+1 ;
            j=0;
        }
    }
    if(j==T.length)
        return i-T.length+1;
    else
        return 0;
}

Status Replace(HString &S, HString T, HString V)
{
    //T�Ƿǿմ�
    //��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ�
    int pos = Index(S, T, 1);
    int i, j;
    if(pos == 0) //S��û�г�����T��ȵ��Ӵ�
        return ERROR;
    else
    {
        int temp=1;
        while(pos = Index(S, T, temp))
        {
            if(StrDelete(S, pos, T.length) == ERROR)
                return ERROR;
            if(StrInsert(S, pos, V) == ERROR)
                return ERROR;
            temp=pos+V.length;
        }
    }
    return OK;
}

Status StrInsert(HString &S,int pos,HString T)
{
    //�ڴ�S�ĵ�pos���ַ�֮ǰ���봮T
    if(pos<=0||pos>S.length)
        return ERROR;
    S.ch=(char *)realloc(S.ch,sizeof(char)*(S.length+T.length));
    if(!S.ch)
        return ERROR;//�ڴ�����ʧ��
    int i,j;
    for(i=S.length+T.length-1,j=S.length-1;j>=pos-1;i--,j--)//����S�ĵ�pos���ַ���������ַ�����
        S.ch[i]=S.ch[j];
    for(i=pos-1,j=0;j<T.length;i++,j++)//���봮T
        S.ch[i]=T.ch[j];
    S.length+=T.length;
    return OK;
}

Status StrDelete(HString &S,int pos,int len)
{
    //�Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�
    int i;
    if(pos<0||pos>S.length||pos+len>S.length)//�������Ϸ�
        return ERROR;
    for(i=pos-1;i+len<S.length;i++)
        S.ch[i]=S.ch[i+len];
    S.length-=len;
    return OK;
}

Status StrCompare(HString S,HString T)
{
    //�Ƚϴ�S��T,�����ͬ�򷵻�TRUE,���򷵻�FALSE
    int i;
    for(i=0;i<S.length&&i<T.length;++i)
    {
        if(S.ch[i]!=T.ch[i])
            return S.ch[i]-T.ch[i];
    }
    return S.length-T.length;
}

void Print(HString T)
{
    //����ַ���T
    int len=T.length;
    int i;
    for(i=0;i<len;i++)
        printf("%c ",T.ch[i]);
    printf("\n");
}

int main()
{
    HString T;
    HString S;
    HString Sub;
    char *s="ABCDEFGHIJKLMN";

    printf("*********************************StrAssign��������*********************************\n");
    if(StrAssign(T,s)==TRUE)
    {
        printf("�ַ������ɳɹ���\n");
        Print(T);
    }
    else
        printf("�ַ�������ʧ��");

    printf("*********************************StrEmpty��������*********************************\n");
    if(StrEmpty(T)==TRUE)
        printf("��ǰ�ַ���Ϊ�գ�\n");
    else
        printf("��ǰ�ַ���Ϊ�ǿգ�\n");

    printf("*********************************StrCopy��������*********************************\n");
    if(StrCopy(S,T)==TRUE)
    {
        printf("�ַ������Ƴɹ���\n");
        Print(S);
    }
    else
        printf("�ַ�������ʧ�ܣ�\n");

    printf("*********************************StrCompare��������*********************************\n");
    if(StrCompare(S,T)==0)
        printf("��S�봮T��ͬ��\n");
    else
        printf("��S�봮T����ͬ��\n");

    printf("*********************************StrLength��������*********************************\n");
    printf("��ǰ�ַ����ĳ���Ϊ:%d\n",StrLength(T));

    printf("*********************************Concat��������*********************************\n");
    printf("����ǰ��");Print(T);
    if(Concat(T,S,S)==TRUE)
        printf("�ַ������ӳɹ���\n");
    else
        printf("�ַ�������ʧ�ܣ�\n");
    printf("���Ӻ��");Print(T);

    printf("*********************************SubString��������*********************************\n");
    if(SubString(Sub,T,3,6)==TRUE)
        printf("ȡ�Ӵ��ɹ���\n");
    else
        printf("ȡ�Ӵ�ʧ�ܣ�\n");
    printf("��ǰ�ַ����ĵ������ַ��𳤶�Ϊ6���Ӵ���");
    Print(Sub);

    printf("*********************************Index��������*********************************\n");
    int pos;
    pos=Index(T,Sub,1);
    if(pos!=0)
        printf("��ǰ�ַ����е�1���ַ�֮������봮Sub��ͬ���Ӵ�,�����һ�γ��ֵ�λ��Ϊ��%d\n",pos);
    else
        printf("��ǰ�ַ����е�1���ַ�֮�󲻴����봮Sub��ͬ���Ӵ�!\n");
    pos=Index(T,Sub,18);
    if(pos!=0)
        printf("��ǰ�ַ����е�18���ַ�֮������봮Sub��ͬ���Ӵ�,�����һ�γ��ֵ�λ��Ϊ��%d\n",pos);
    else
        printf("��ǰ�ַ����е�18���ַ�֮�󲻴����봮Sub��ͬ���Ӵ�!\n");

    printf("*********************************Replace��������*********************************\n");
    HString V;
    char temp[]="6666";
    StrAssign(V,temp);
    printf("���滻��");Print(Sub);
    printf("�����滻��");Print(V);
    printf("�滻ǰ��");Print(T);
    Replace(T,Sub,V);
    printf("�滻���");Print(T);

    printf("*********************************StrInsert��������*********************************\n");
    printf("�����");Print(S);
    printf("����ǰ��");Print(T);
    if(StrInsert(T,3,S)==TRUE)
        printf("�ַ�������ɹ���\n");
    else
        printf("�ַ�������ʧ�ܣ�\n");
    printf("�ڵ������ַ�������");Print(T);

    printf("*********************************StrDelete��������*********************************\n");
    printf("ɾ��ǰ��");Print(T);
    if(StrDelete(T,3,10)==TRUE)
        printf("ɾ����ǰ�ַ�����3���ַ��𳤶�Ϊ10���Ӵ��ɹ���\n");
    else
        printf("ɾ����ǰ�ַ�����3���ַ��𳤶�Ϊ10���Ӵ�ʧ�ܣ�\n");
    printf("ɾ�����");Print(T);

    printf("*********************************ClearString��������*********************************\n");
    if(StrEmpty(T)==TRUE)
        printf("��ǰ�ַ���Ϊ�գ�\n");
    else
        printf("��ǰ�ַ���Ϊ�ǿգ�\n");
    ClearString(T);
    printf("�ַ�����ճɹ���\n");
    if(StrEmpty(T)==TRUE)
        printf("��ǰ�ַ���Ϊ�գ�\n");
    else
        printf("��ǰ�ַ���Ϊ�ǿգ�\n");

    return 0;
}

