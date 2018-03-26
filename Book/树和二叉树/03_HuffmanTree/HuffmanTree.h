#ifndef HUFFMANTREE_H_INCLUDED
#define HUFFMANTREE_H_INCLUDED

#include"../../../template.h"
#include<stdlib.h>//�ṩmalloc��free����
#include<string.h>//�ṩstrcpy����
#include<conio.h>//�ṩgetch����
#include<time.h>//�ṩtime��clock����

//�շ������ͺշ�������Ĵ洢��ʾ
typedef struct
{
    unsigned int weight;
    unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;//��̬������������շ�����
typedef char** HuffmanCode;//��̬��������洢�շ��������

void Select(HuffmanTree HT,int n,int &s1,int &s2);

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,unsigned int *w,int n);
//w���n���ַ���Ȩֵ(��>0),����շ�����HT,�����n���ַ��ĺշ�������HC
void PrintHT(HuffmanTree HC,int n);

void PrintHC(HuffmanCode HC,int n,char* c,unsigned int* w);

#endif // HUFFMANTREE_H_INCLUDED
