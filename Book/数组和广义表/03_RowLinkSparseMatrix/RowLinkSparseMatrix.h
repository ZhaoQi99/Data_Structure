#ifndef ROWLINKSPARSEMATRIX_H_INCLUDED
#define ROWLINKSPARSEMATRIX_H_INCLUDED

#include"../../../template.h"

#define MAXSIZE 100 // ����Ԫ���������ֵ
#define MAXRC 20//���������

typedef int ElemType;

typedef struct
{
    int i, j; // ���±�,���±�
    ElemType e; // ����Ԫ��ֵ
} Triple;

struct RLSMatrix
{
    Triple data[MAXSIZE + 1]; // ����Ԫ��Ԫ���
    int rpos[MAXRC + 1]; // ���е�һ������Ԫ�ص�λ�ñ�
    int mu, nu, tu; // ����������������ͷ���Ԫ����
};

Status CreateSMatrix(RLSMatrix &M);
// ����ϡ�����M

Status DestroySMatrix(RLSMatrix &M);
// ����ϡ�����M

void PrinRLSMatrix(RLSMatrix M);
// ���ϡ�����M

Status CopySMatrix(RLSMatrix M,RLSMatrix &T);
//��ϡ�����M���Ƶõ�T

Status AddSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix &Q);
// ��ϡ�����ĺ�Q=M+N

Status SubRLSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix &Q);
// ��ϡ�����Ĳ�Q=M-N

Status MulRLSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix &Q);
// ��ϡ�����ĳ˻�Q=M*N

#endif // ROWLINKSPARSEMATRIX_H_INCLUDED
