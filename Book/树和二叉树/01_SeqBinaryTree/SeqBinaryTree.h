#ifndef SEQBINARYTREE_H_INCLUDED
#define SEQBINARYTREE_H_INCLUDED

#include"../../../template.h"

#define MAX_TRUE_SIZE 100//�����������ڵ���
typedef char TElemType;
typedef TElemType SqBiTree[MAX_TRUE_SIZE];//0�ŵ�Ԫ�洢���ڵ�

Status InitBiTree(SqBiTree &T);
//�������T

Status DestroyBiTree(SqBiTree &T);
//������T

Status CreateBiTree(SqBiTree &T,definition);
//��definition���������T

Status ClearBiTree(SqBiTree &T);
//����T��Ϊ����

Status BiTreeEmpty(SqBiTree T);
//��TΪ����,�򷵻�true,����false

int BiTreeDepth(SqBiTree T);
//����T�����

TElemType Root(SqBiTree T);
//����T�ĸ�

TElemType Value(SqBiTree T,cur_e);
//����cur_e��ֵ

Status Assign(SqBiTree T,cur_e,TElemType value);
//�����cur_e��ֵΪvalue

TElemType Parent(SqBiTree T,cur_e);
//��cur_e��T�ķǸ����,�򷵻�����˫��,������ֵΪ��

TElemType LeftChild(SqBiTree T,cur_e);
//����cur_e������.��e������,�򷵻ؿ�

TElemType RightChild(SqBiTree T,cur_e);
//����cur_e���Һ���.��e���Һ���,�򷵻ؿ�

TElemType LeftSibling(SqBiTree T,cur_e);
//����cur_e�����ֵ�.��cur_e��T�����ӻ������ֵ�,�򷵻�Ϊ��

TElemType RightSibling(SqBiTree T,cur_e);
//����cur_e�����ֵ�.��cur_e��T���Һ��ӻ������ֵ�,�򷵻�Ϊ��

Status InsertChild(SqBiTree &T,&p,int LR,c);
//����LRΪ0��1,����cΪT��pָ�������������.
//p��ָ����ԭ��������������Ϊc��������

Status DeleteChild(SqBiTree &T,&p,int LR);
//����LRΪ0��1,ɾ��T��p��ָ�������������

Status PreOrderTraverseTree(SqBiTree T,Status(*Visit)(TElemType e));
//�������T,��ÿ�������ú���Visit()һ��������һ�Ρ�
//һ��Visit()ʧ��,�����ʧ��

Status InOrderTraverseTree(SqBiTree T,Status(*Visit)(TElemType e));
//�������T,��ÿ�������ú���Visit()һ��������һ�Ρ�
//һ��Visit()ʧ��,�����ʧ��

Status PostOrderTraverseTree(SqBiTree T,Status(*Visit)(TElemType e));
//�������T,��ÿ�������ú���Visit()һ��������һ�Ρ�
//һ��Visit()ʧ��,�����ʧ��

Status LevelOrderTraverseTree(SqBiTree T,Status(*Visit)(TElemType e));
//�������T,��ÿ�������ú���Visit()һ��������һ�Ρ�
//һ��Visit()ʧ��,�����ʧ��


#endif // SEQBINARYTREE_H_INCLUDED
