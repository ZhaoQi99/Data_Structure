#ifndef CROSSLIST_H_INCLUDED
#define CROSSLIST_H_INCLUDED

#include"../../../template.h"
#include<stdlib.h>
typedef int ElemType;

struct OLNode
{
    int i, j; // �÷���Ԫ���к����±�
    ElemType e; // ����Ԫ��ֵ
    OLNode *right, *down; // �÷���Ԫ�����б���б�ĺ������
};

typedef OLNode *OLink;

struct CrossList
{
    OLink *rhead, *chead; // �к�������ͷָ��������ַ,��CreatSMatrix_OL()����
    int mu, nu, tu; // ϡ�����������������ͷ���Ԫ����
};

Status CreateSMatrix(CrossList &M);
// ����ϡ�����M

Status DestroySMatrix(CrossList &M);
// ����ϡ�����M

void PrinCrossList(CrossList M);
// ���ϡ�����M

Status CopySMatrix(CrossList M,CrossList &T);
//��ϡ�����M���Ƶõ�T

Status AddSMatrix(CrossList M,CrossList N,CrossList &Q);
// ��ϡ�����ĺ�Q=M+N

Status SubCrossList(CrossList M,CrossList N,CrossList &Q);
// ��ϡ�����Ĳ�Q=M-N

Status MulCrossList(CrossList M,CrossList N,CrossList &Q);
// ��ϡ�����ĳ˻�Q=M*N

#endif // CROSSLIST_H_INCLUDED
