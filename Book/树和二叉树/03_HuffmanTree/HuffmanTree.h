#ifndef HUFFMANTREE_H_INCLUDED
#define HUFFMANTREE_H_INCLUDED

#include"../../../template.h"
#include<stdlib.h>//提供malloc、free函数
#include<string.h>//提供strcpy函数
#include<conio.h>//提供getch函数
#include<time.h>//提供time、clock函数

//赫夫曼树和赫夫曼编码的存储表示
typedef struct
{
    unsigned int weight;
    unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;//动态分配数组存数赫夫曼树
typedef char** HuffmanCode;//动态分配数组存储赫夫曼编码表

void Select(HuffmanTree HT,int n,int &s1,int &s2);

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,unsigned int *w,int n);
//w存放n个字符的权值(均>0),构造赫夫曼树HT,并求出n个字符的赫夫曼编码HC
void PrintHT(HuffmanTree HC,int n);

void PrintHC(HuffmanCode HC,int n,char* c,unsigned int* w);

#endif // HUFFMANTREE_H_INCLUDED
