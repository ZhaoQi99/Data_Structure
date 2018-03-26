#include"HuffmanTree.h"
#include<stdio.h>
#include<math.h>

void Select(HuffmanTree HT, int n, int &s1, int &s2)
{
    int i;
    unsigned int temp1 = 0xffff, temp2 = 0xffff;
    int ans1, ans2;
    for(i = 1; i <= n; i++)
    {
        if(HT[i].parent == 0 && HT[i].weight < temp1)
        {
            temp1 = HT[i].weight;
            ans1 = i;
        }
    }
    for(i = 1; i <= n; i++)
    {
        if(HT[i].parent == 0 && HT[i].weight < temp2 && i != ans1)
        {
            temp2 = HT[i].weight;
            ans2 = i;
        }
    }
    s1 = ans1;
    s2 = ans2;
}

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, unsigned int *w, int n)
{
    if(n < 1)
        return;
    int i;
    HuffmanTree p;
    int m = 2 * n - 1;
    HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
    for(p = HT, p++, i = 1; i <= n; i++,p++)
        *p = {*(w+i-1), 0, 0, 0};
    for(i = n; i < m; ++i, ++p)
        *p = {0, 0, 0, 0};
    printf("HT��̬:\n");
    PrintHT(HT, m);
    for(i = n + 1; i <= m; ++i) //���շ�����
    {
        //��HT[1..i-1]ѡ��parentΪ0��weight��С���������,����ŷֱ�Ϊs1��s2
        int s1, s2;
        Select(HT, i - 1, s1, s2);
        printf("select: s1=%d s2=%d\n", s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
        PrintHT(HT, i);
    }
    //��Ҷ�ӵ���������ÿ���ַ��ĺշ�������
    HC = (HuffmanCode)malloc((n + 1) * sizeof(char*)); //����n���ַ������ͷָ������
    char *cd = (char*)malloc(n * sizeof(char)); //���������Ĺ����ռ�
    cd[n - 1] = '\0'; //���������
    for(i = 1; i <= n; ++i) //����ַ���շ�������
    {
        int start = n - 1; //���������λ��
        unsigned int c, f;
        for(c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent) //��Ҷ�ӵ������������
            if(HT[f].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        HC[i] = (char *)malloc((n - start) * sizeof(char)); //Ϊ��i���ַ��������ռ�
        strcpy(HC[i], &cd[start]); //��cd���Ʊ��뵽HC
    }
    free(cd);
}

void PrintHT(HuffmanTree HT, int n)
{
    int i;
    printf("���  weight  parent  lchild  rchild\n");
    for(int i = 1; i <= n; i++)
        printf("%4d%8d%8d%8d%8d\n", i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
    printf("    ������������� ...\n");
//    getch();
}

void PrintHC(HuffmanCode HC, int n, char *c, unsigned int *w)
{
    int i;
    printf("%d���ַ��ĺշ�����������:\n", n);
    long value=0;
    for(i = 1; i <= n; i++)
    {
        value+=strlen(HC[i])*(*w);
        printf("%c(%d) :  %s\n", *c++,*w++, HC[i]);
    }
    printf("��Ȩ·������Ϊ:%ld\n",value);
}

int main()
{
    int i, n;
    HuffmanTree HT;
    HuffmanCode HC;
    printf("������Ҫ���кշ���������ַ��ĸ���:");
    scanf("%d", &n);
//    freopen("out.txt", "w", stdout);
    getchar();
    unsigned int *w = (unsigned int*)malloc(sizeof(unsigned int) * n);
    char *c = (char*)malloc(sizeof(char) * n);
    printf("�����������ַ�����Ȩֵ(��:A4)\n");
    srand((int)time(0));

    clock_t start = 0, finish = 0;
    start = clock();

    for(i = 0; i < n; i++)
    {
//        scanf("%c%d", &c[i], &w[i]);
//        getchar();
        c[i] = (char)(rand() % 128 + 1);
        w[i] = rand() % 1000;
    }
    printf("�շ������Ĺ����������:\n");
    HuffmanCoding(HT, HC, w, n);
    PrintHC(HC, n, c, w);

    finish = clock();

    printf("���ĺշ��������������ʱ��Ϊ: %f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
    printf("***���������������****");
    getch();
    return 0;
}
