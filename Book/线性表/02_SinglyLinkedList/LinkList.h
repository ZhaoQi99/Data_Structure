#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include<stdio.h>
#include"../../../template.h"
#include<stdlib.h>
#include<math.h>

typedef  int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

Status InitList(LinkList &L);
// ����һ���յ����Ա�L��

Status DestroyList(LinkList & L);
//�������Ա�L

Status ClearList(LinkList & L);
//��L����Ϊ�ձ�

int ListEmpty(LinkList L);
//��LΪ�ձ�,�򷵻�TRUE,���򷵻�FALSE

int ListLength(LinkList L);
//����L������Ԫ�ظ���

Status GetElem_L(LinkList & L, int i, ElemType & e);
// LΪ��ͷ���ĵ������ͷָ�롣
// ����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR

int LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType));
// ����ʽ���Ա�L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
// ���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0��

Status PriorElem(LinkList L, ElemType cur_e, ElemType & pre_e);
//��cur_e��L������Ԫ��,�Ҳ��ǵ�һ��,����pre_e��������ǰ��,�������ʧ��,pre_e�޶���

Status NextELem(LinkList L, ElemType cur_e, ElemType & next_e);
//��cur_e��L������Ԫ��,�Ҳ������һ��,����next_e�������ĺ��,�������ʧ��,next_e�޶���

Status ListInsert_L(LinkList & L, int i, ElemType e);
// �ڴ�ͷ���ĵ������Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e

Status ListDelete_L(LinkList & L, int i, ElemType & e);
// �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ

Status ListTraverse(LinkList L, Status (*visit)(ElemType));
//���ζ�L��ÿ������Ԫ�ص��ú���visit().һ��visit()ʧ�ܣ������ʧ��

void CreateList_L(LinkList & L, int n);
// ��λ�����루���������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L

void MergeList_L(LinkList & La, LinkList & Lb, LinkList & Lc);
// ��֪�������Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ����С�
// �鲢La��Lb�õ��µĵ������Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ����С�

Status visit(ElemType e);

Status compare(ElemType a, ElemType b);

#endif // LINKLIST_H_INCLUDED
