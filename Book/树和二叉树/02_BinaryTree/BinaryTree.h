#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include"../../template.h"
typedef char TElemType;

//�������Ķ�������洢��ʾ
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild;//���Һ���ָ��
}

#endif // BINARYTREE_H_INCLUDED
