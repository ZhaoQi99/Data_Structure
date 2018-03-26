/*
Problem:����˳��洢��ʾ
Author:QiZhao
Data:2017-11-28
Description:��ε�������ݽṹϰϰ�⼯ʵϰ��
Copyright  2017 QiZhao. All rights reserved.
*/
#include"SequenceString.h"
#include<stdio.h>

Status StrAssign(SString &T,char *s)
{
    //����һ����ֵ����chars���ַ�������
    int len=strlen(s);
    if(len>MAXSTRLEN)
        return ERROR;
    T[0]=len;
    int i;
    for(i=1;i<=len;i++)
        T[i]=s[i-1];
    return OK;
}

Status StrCopy(SString &T,SString S)
{
    //�ɴ�S���Ƶõ���T
    int len=StrLength(S);
    T[0]=S[0];
    int i;
    for(i=1;i<=len;i++)
        T[i]=S[i];
    return OK ;
}

Status StrEmpty(SString S)
{
    //����SΪ�մ�,�򷵻�TRUE,���򷵻�FALSE
    int len=StrLength(S);
    if(len==0)
        return TRUE;
    else
        return FALSE;
}

int  StrLength(SString S)
{
    //����S��Ԫ�ظ���,��Ϊ���ĳ���
    int temp=(int)S[0];
    return temp;
}

Status ClearString(SString &S)
{
    //��S��Ϊ�մ�
    S[0]=0;
    return OK;
}

Status Concat(SString &T, SString S1, SString S2)
{
    //��T������S1��S2���Ӷ��ɵ��´�
    int i;
    Status uncut;
    if (S1[0] + S2[0] <= MAXSTRLEN)  // δ�ض�
    {
        for (i = 1; i <= S1[0]; i++) T[i] = S1[i];
        for (i = 1; i <= S2[0]; i++) T[i + S1[0]] = S2[i];
        T[0] = S1[0] + S2[0];
        uncut = TRUE;
    }
    else if (S1[0] < MAXSTRLEN)      // �ض�
    {
        for (i = 1; i <= S1[0]; i++) T[i] = S1[i];
        for (i = S1[0] + 1; i <= MAXSTRLEN; i++) T[i] = S2[i - S1[0]];
        T[0] = MAXSTRLEN;
        uncut = FALSE;
    }
    else                             // �ض�(��ȡS1)
    {
        for (i = 0; i <= MAXSTRLEN; i++) T[i] = S1[i];
        uncut = FALSE;
    }
    return uncut;
}

Status SubString(SString &Sub, SString S, int pos, int len)
{
    //1<=pos<=StrLength(S)��0<=Len<=StrLength(S)-pos+1
    // ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
    int i;
    if (pos < 1 || pos > S[0] || len < 0 || len > S[0] - pos + 1)
        return ERROR;
    for(i = 1; i <= len; i++)
        Sub[i] = S[pos + i - 1];
    Sub[0] = len;
    return OK;
}

int Index(SString S, SString T, int pos=0)
{
    //1<=pos<=StrLength(S)
    //������S�д��ںʹ�Tֵ��ͬ���Ӵ�,�򷵻���������S�е�pos���ַ�֮���һ�γ��ֵ�λ��;������ֵΪ0
    int n, m, i;
    SString sub;
    if (pos > 0)
    {
        n = StrLength(S);
        m = StrLength(T);
        i = pos;
        while (i <= n - m + 1)
        {
            SubString (sub, S, i, m);
            if (StrCompare(sub, T) == 0) ++i;
            else return i;
        }
    }
    return 0;
}

Status Replace(SString &S, SString T, SString V)
{
    //T�Ƿǿմ�
    //��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ�
    int i = 1;
    int len = StrLength(T);
    while(i+len-1 <= StrLength(S))
    {
        SString temp;//����Ӵ�
        SubString(temp, S, i, len);
        if(StrCompare(temp,T)==TRUE)
        {
            int j;
            StrDelete(S,i,len);
            if(i+StrLength(V)<=MAXSTRLEN)
                StrInsert(S,i,V);
            i+=StrLength(V);
        }
        else
            i++;
    }
    return OK;
}

Status StrInsert(SString &S,int pos,SString T)
{
    //�ڴ�S�ĵ�pos���ַ�֮ǰ���봮T
    int len=StrLength(T);
    if(StrLength(S)+StrLength(T)>MAXSTRLEN)
        return ERROR;
    int i;
    for(i=StrLength(S);i>=pos;i--)
        S[i+len]=S[i];
    for(i=1;i<=len;i++)
        S[pos+i-1]=T[i];
    S[0]+=len;
    return OK;
}

Status StrDelete(SString &S,int pos,int len)
{
    //�Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�
    int length=StrLength(S);
    if(pos+len>length)
        return ERROR;
    int i;
    for(i=pos+len;i<=length;i++)
        S[i-len]=S[i];
    S[0]-=len;
    return OK ;
}

Status StrCompare(SString S,SString T)
{
    //�Ƚϴ�S��T,�����ͬ�򷵻�TRUE,���򷵻�FALSE
    int len1=StrLength(S);
    int len2=StrLength(T);
    if(len1!=len2)
        return FALSE;
    int i;
    for(i=1;i<=len1;i++)
    {
        if(S[i]==T[i])
            continue;
        else
            return FALSE;
    }
    return TRUE;
}

void Print(SString T)
{
    int len=StrLength(T);
    int i;
    printf("�ַ���Ϊ:");
    for(i=1;i<=len;i++)
        printf("%c",T[i]);
    printf("\n");
}

int main()
{
    char s[]="abcdefghijklmn";
    SString T;
    SString S;

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
    if(StrCompare(S,T)==TRUE)
        printf("��S�봮T��ͬ��\n");
    else
        printf("��S�봮T����ͬ��\n");

    printf("*********************************StrLength��������*********************************\n");
    printf("��ǰ�ַ����ĳ���Ϊ:%d\n",StrLength(T));

    printf("*********************************Concat��������*********************************\n");
    printf("����ǰ��");Print(T);
    if(Concat(T,T,S)==TRUE)
        printf("�ַ������ӳɹ���\n");
    else
        printf("�ַ�������ʧ�ܣ�\n");
    printf("���Ӻ��");Print(T);

    printf("*********************************SubString��������*********************************\n");
    if(SubString(S,T,3,6)==TRUE)
        printf("ȡ�Ӵ��ɹ���\n");
    else
        printf("ȡ�Ӵ�ʧ�ܣ�\n");
    printf("��ǰ�ַ����ĵ������ַ��𳤶�Ϊ6���Ӵ���");
    Print(S);

    printf("*********************************Index��������*********************************\n");
    int pos;
    pos=Index(T,S,1);
    if(pos!=0)
        printf("��ǰ�ַ����е�1���ַ�֮������봮S��ͬ���Ӵ�,�����һ�γ��ֵ�λ��Ϊ��%d\n",pos);
    else
        printf("��ǰ�ַ����е�1���ַ�֮�󲻴����봮S��ͬ���Ӵ�!\n");
    pos=Index(T,S,15);
    if(pos!=0)
        printf("��ǰ�ַ����е�15���ַ�֮������봮S��ͬ���Ӵ�,�����һ�γ��ֵ�λ��Ϊ��%d\n",pos);
    else
        printf("��ǰ�ַ����е�15���ַ�֮�󲻴����봮S��ͬ���Ӵ�!\n");

    printf("*********************************Replace��������*********************************\n");
    SString V;
    char temp[]="6666";
    StrAssign(V,temp);
    printf("���滻��");Print(S);
    printf("�����滻��");Print(V);
    printf("�滻ǰ��");Print(T);
    Replace(T,S,V);
    printf("�滻���");Print(T);

    printf("*********************************StrInsert��������*********************************\n");
    printf("�����");Print(S);
    printf("����ǰ��");Print(T);
    if(StrInsert(T,1,S)==TRUE)
        printf("�ַ�������ɹ���\n");
    else
        printf("�ַ�������ʧ�ܣ�\n");
    printf("������");Print(T);

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

