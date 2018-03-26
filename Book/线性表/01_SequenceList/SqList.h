#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED

#include<stdio.h>
#include"../../../template.h"
#include<stdlib.h>
#include<stdio.h>

#define LIST_INIT_SIZE 100//���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10//���Ա�洢�ռ�ķ�������

typedef  int ElemType;
typedef struct
{
    ElemType *elem;//�洢�ռ��ַ
    int length;//��ǰ����
    int listsize;//��ǰ����Ĵ洢����,��sizeof(EleType)Ϊ��λ
} SqList;

Status InitList(SqList &L);
// ����һ���յ����Ա�L��

Status DestroyList(SqList &L);
//�������Ա�L

Status ClearList(SqList & L);
//��L����Ϊ�ձ�

int ListEmpty(SqList L);
//��LΪ�ձ�,�򷵻�TRUE,���򷵻�FALSE

int ListLength(SqList L);
//����L������Ԫ�ظ���

Status GetElem(SqList L, int i, ElemType & e);
//��e����L�е�i��Ԫ�ص�ֵ

int LocateElem(SqList L, ElemType e, Status (*compare)(ElemType, ElemType));
// ��˳�����Ա�L�в��ҵ�1��ֵ��e����compare();��Ԫ�ص�λ��
// ���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0��

Status PriorElem(SqList L, ElemType cur_e, ElemType & pre_e);
//��cur_e��L������Ԫ��,�Ҳ��ǵ�һ��,����pre_e��������ǰ��,�������ʧ��,pre_e�޶���

Status NextELem(SqList L, ElemType cur_e, ElemType & next_e);
//��cur_e��L������Ԫ��,�Ҳ������һ��,����next_e�������ĺ��,�������ʧ��,next_e�޶���

Status ListInsert(SqList & L, int i, ElemType e);
// ��˳�����Ա�L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e��
// i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)+1

Status ListDelete(SqList & L, int i, ElemType & e);
// ��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ��
// i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)��

Status visit(ElemType e);

Status compare(ElemType a, ElemType b);

Status ListTraverse(SqList L, Status (*visit)(ElemType));
//���ζ�L��ÿ������Ԫ�ص��ú���visit().һ��visit()ʧ�ܣ������ʧ��

void MergeList_Sq(SqList La, SqList Lb, SqList & Lc);
// ��֪˳�����Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ����С�
// �鲢La��Lb�õ��µ�˳�����Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ����С�

#endif // SQLIST_H_INCLUDED
