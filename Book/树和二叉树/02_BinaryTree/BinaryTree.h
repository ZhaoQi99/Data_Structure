#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include"../../template.h"
typedef char TElemType;

//二叉树的二叉链表存储表示
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild;//左右孩子指针
}

#endif // BINARYTREE_H_INCLUDED
