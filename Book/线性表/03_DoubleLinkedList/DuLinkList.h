#ifndef DULINKLIST_H_INCLUDED
#define DULINKLIST_H_INCLUDED

#include"../../../template.h"
typedef int ElemType;
typedef struct DuLNode
{
    ElemType data;
    struct DuLNode* prior;
    struct DuLNode* next;
}DuLNode,*DuLinkList;

Status InitList_DuL(DuLinkList &L);
//����һ���յ�˫������L

Status ClearList_DuL(DuLinkList &L);
//��L����Ϊ�ձ�

Status DestroyList_DuL(DuLinkList &L);
//�������Ա�L

int ListEmpty_DuL(DuLinkList L);
//��LΪ�ձ�,�򷵻�TRUE,���򷵻�FALSE

int ListLength_DuL(DuLinkList L);
//����˫������L������Ԫ�ظ���

DuLinkList GetElem_DuL(DuLinkList L, int i);
// LΪ��ͷ����˫�������ͷָ�롣
// ����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR

int LocateElem(DuLinkList L, ElemType e, Status (*compare)(ElemType, ElemType));
// ��˫������L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
// ���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0��

Status PriorElem(DuLinkList L, ElemType cur_e, ElemType & pre_e);
//��cur_e��L������Ԫ��,�Ҳ��ǵ�һ��,����pre_e��������ǰ��,�������ʧ��,pre_e�޶���

Status NextELem(DuLinkList L, ElemType cur_e, ElemType & next_e);
//��cur_e��L������Ԫ��,�Ҳ������һ��,����next_e�������ĺ��,�������ʧ��,next_e�޶���

Status ListInsert_DuL(DuLinkList & L, int i, ElemType e);
// �ڴ�ͷ����˫�����Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e

Status ListDelete_L(DuLinkList & L, int i, ElemType & e);
// �ڴ�ͷ����˫�����Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ

Status ListTraverse(DuLinkList L, Status (*visit)(ElemType));
//���ζ�L��ÿ������Ԫ�ص��ú���visit().һ��visit()ʧ�ܣ������ʧ��

Status visit(ElemType e);

Status compare(ElemType a, ElemType b);

#endif // DULINKLIST_H_INCLUDED
