#ifndef EXTENLINKEDLIST_H_INCLUDED
#define EXTENLINKEDLIST_H_INCLUDED

#include"../../../template.h"

typedef char ElemType;
typedef struct LNode
{
    //�������
    ElemType data;
    struct LNode* next;
}*Link,*Position;
typedef struct
{
    //��������
    Link head,tail;//�ֱ�ָ�����������е�ͷ�������һ�����
    int len;//ָʾ��������������Ԫ�صĸ���
}LinkList;

Status MakeNode(Link &p,ElemType e);
//������pָ��ֵΪe�Ľ�㣬������OK��������ʧ��,�򷵻�ERROR

void FreeNode(Link &p);
//�ͷ�p��ָ���

Status InitList(LinkList &L);
// ����һ���յ����Ա�L��

Status DestroyList(LinkList & L);
//�������Ա�L,L���ٴ���

Status ClearList(LinkList & L);
//��L����Ϊ�ձ�,���ͷ�ԭ����Ľ��ռ�

Status InsFirst(LinkList &L,Link h,Link s);
//��֪hָ�����������ͷ���,��s��ָ�������ڵ�һ�����֮ǰ

Status DelFirst(LinkList &L,Link h,Link &q);
//��֪hָ�����������ͷ���,ɾ�������е�һ����㲢��q����

Status Append(LinkList &L,Link s);
//��ָ��s��ָ(�˴���ָ������)��һ�������������������L�����һ�����
//֮��,���ı�����L��βָ��ָ���µ�β���

Status Remove(LinkList &L,Link &q);
//ɾ����������L�е�β��㲢��q����,�ı�����L��βָ��ָ���µ�β���

Status InsBefore(LinkList &L,Link &p,Link s);
//��֪pָ����������L�е�һ�����,��s��ָ��������p��ָ���֮ǰ,
//���޸�ָ��pָ���²���Ľ��

Status InsAfter(LinkList &L,Link &p,Link s);
//��֪pָ����������L�е�һ�����,��s��ָ��������p��ָ���֮��,
//���޸�ָ��pָ���²���Ľ��

Status SetCurElem(Link &p,ElemType e);
//��֪pָ�����������е�һ�����,��e����p��ָ���������Ԫ�ص�ֵ

ElemType GetCurElem(Link p);
//��֪pָ�����������е�һ�����,����p��ָ���������Ԫ�ص�ֵ

Status ListEmpty(LinkList L);
//��LΪ�ձ�,�򷵻�TRUE,���򷵻�FALSE

int ListLength(LinkList L);
//����L������Ԫ�ظ���

Position GetHead(LinkList L);
//�������Ա�L��ͷ����λ��

Position GetLast(LinkList L);
//�������Ա�L�����һ������λ��

Position PriorPos(LinkList L,Link p);
//��֪pָ����������L�е�һ�����,����p��ָ����ֱ��ǰ����λ��,
//����ǰ��,�򷵻�NULL

Position NextPos(LinkList L,Link p);
//��֪pָ����������L�е�һ�����,����p��ָ����ֱ�Ӻ�̵�λ��,
//���޺��,�򷵻�NULL

Status LocatePos(LinkList L,int i,Link &p);
//����pָʾ��������L�е�i������λ��,������OK,iֵ���Ϸ�ʱ����ERROR

Position LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType));
// ����ʽ���Ա�L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
// ��������������Ԫ��,�򷵻�NULL

Status ListTraverse(LinkList L, Status (*visit)(ElemType));
//���ζ�L��ÿ������Ԫ�ص��ú���visit().һ��visit()ʧ�ܣ������ʧ��

Status ListInsert(LinkList &L, int i, ElemType e);
 // �ڴ�ͷ������չ�ĵ������Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e

Status visit(ElemType e);

//Status compare(ElemType a, ElemType b);

#endif // EXTENLINKEDLIST_H_INCLUDED
