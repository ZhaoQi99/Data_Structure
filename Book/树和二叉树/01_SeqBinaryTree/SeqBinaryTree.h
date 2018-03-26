#ifndef SEQBINARYTREE_H_INCLUDED
#define SEQBINARYTREE_H_INCLUDED

#include"../../../template.h"

#define MAX_TRUE_SIZE 100//二叉树的最大节点数
typedef char TElemType;
typedef TElemType SqBiTree[MAX_TRUE_SIZE];//0号单元存储根节点

Status InitBiTree(SqBiTree &T);
//构造空树T

Status DestroyBiTree(SqBiTree &T);
//销毁树T

Status CreateBiTree(SqBiTree &T,definition);
//按definition构造二叉树T

Status ClearBiTree(SqBiTree &T);
//将树T清为空树

Status BiTreeEmpty(SqBiTree T);
//若T为空树,则返回true,否则false

int BiTreeDepth(SqBiTree T);
//返回T的深度

TElemType Root(SqBiTree T);
//返回T的根

TElemType Value(SqBiTree T,cur_e);
//返回cur_e的值

Status Assign(SqBiTree T,cur_e,TElemType value);
//将结点cur_e赋值为value

TElemType Parent(SqBiTree T,cur_e);
//若cur_e是T的非根结点,则返回它的双亲,否则函数值为空

TElemType LeftChild(SqBiTree T,cur_e);
//返回cur_e的左孩子.若e无左孩子,则返回空

TElemType RightChild(SqBiTree T,cur_e);
//返回cur_e的右孩子.若e无右孩子,则返回空

TElemType LeftSibling(SqBiTree T,cur_e);
//返回cur_e的左兄弟.若cur_e是T的左孩子或无左兄弟,则返回为空

TElemType RightSibling(SqBiTree T,cur_e);
//返回cur_e的右兄弟.若cur_e是T的右孩子或无右兄弟,则返回为空

Status InsertChild(SqBiTree &T,&p,int LR,c);
//根据LR为0或1,插入c为T中p指结点的左或右子树.
//p所指结点的原有左或右子树则成为c的右子树

Status DeleteChild(SqBiTree &T,&p,int LR);
//根据LR为0或1,删除T中p所指结点的左或右子树

Status PreOrderTraverseTree(SqBiTree T,Status(*Visit)(TElemType e));
//先序遍历T,对每个结点调用函数Visit()一次且至多一次。
//一旦Visit()失败,则操作失败

Status InOrderTraverseTree(SqBiTree T,Status(*Visit)(TElemType e));
//中序遍历T,对每个结点调用函数Visit()一次且至多一次。
//一旦Visit()失败,则操作失败

Status PostOrderTraverseTree(SqBiTree T,Status(*Visit)(TElemType e));
//后序遍历T,对每个结点调用函数Visit()一次且至多一次。
//一旦Visit()失败,则操作失败

Status LevelOrderTraverseTree(SqBiTree T,Status(*Visit)(TElemType e));
//层序遍历T,对每个结点调用函数Visit()一次且至多一次。
//一旦Visit()失败,则操作失败


#endif // SEQBINARYTREE_H_INCLUDED
