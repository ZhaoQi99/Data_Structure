#ifndef TRIPLESPARSEMATRIX_H_INCLUDED
#define TRIPLESPARSEMATRIX_H_INCLUDED

#include"../../../template.h"

#define MAXSIZE 100 // ����Ԫ���������ֵ
typedef int ElemType;

typedef struct
{
    int i, j; // ���±�,���±�
    ElemType e; // ����Ԫ��ֵ
} Triple;

typedef struct
{
    Triple data[MAXSIZE + 1]; // ����Ԫ��Ԫ���,data[0]δ��
    int mu, nu, tu; // ����������������ͷ���Ԫ����
} TSMatrix;

Status CreateSMatrix(TSMatrix &M);
// ����ϡ�����M

Status DestroySMatrix(TSMatrix &M);
// ����ϡ�����M

void PrintSMatrix(TSMatrix M);
// ���ϡ�����M

Status CopySMatrix(TSMatrix M,TSMatrix &T);
//��ϡ�����M���Ƶõ�T

Status AddSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q);
// ��ϡ�����ĺ�Q=M+N

Status SubtSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q);
// ��ϡ�����Ĳ�Q=M-N

Status MultSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q);
// ��ϡ�����ĳ˻�Q=M*N

Status TransposeSMatrix(TSMatrix M, TSMatrix &T);
// ������Ԫ��˳���洢��ʾ����ϡ�����M��ת�þ���T

Status  FastTransposeSMatrix(TSMatrix M, TSMatrix &T);
// ������Ԫ��˳���洢��ʾ����ϡ�����M��ת�þ���T

#endif // TRIPLESPARSEMATRIX_H_INCLUDED
