/***
*DynaLnkBiTree.h - 动态链式二叉树的定义
*	
****/

#if !defined(DYNALNKBITREE_H)
#define DYNALNKBITREE_H

#include "ElemType.h"

/*------------------------------------------------------------
// 二叉树结构的定义
------------------------------------------------------------*/

typedef struct BiNode
{
	ElemType data;				// 结点数据元素
	struct BiNode *l;			// 结点的左孩子指针
	struct BiNode *r;			// 结点的右孩子指针
} BinTNode, *BinTree;

enum LR {LEFT, RIGHT};


/*------------------------------------------------------------
// 二叉树的基本操作
------------------------------------------------------------*/

bool InitBinTree(BinTree *T);
void DestroyBinTree(BinTree *T);
bool CreateBinTree(BinTree *T);
void ClearBinTree(BinTree *T);
bool BinTreeEmpty(BinTree T);
int  BinTreeDepth(BinTree T);
BinTNode *Root(BinTree T);
bool NodeExist(BinTree T, BinTNode* n);
ElemType Value(BinTree T, BinTNode* n);
void Assign(BinTree T, BinTNode* n, ElemType e);
BinTNode* Parent(BinTree T, BinTNode* n);
BinTNode* LeftChild(BinTree T, BinTNode* n);
BinTNode* RightChild(BinTree T, BinTNode* n);
BinTNode* LeftSibling(BinTree T, BinTNode* n);
BinTNode* RightSibling(BinTree T, BinTNode* n);
void InsertNode(BinTree T, BinTNode* p, LR d, BinTNode* n);
void DeleteNode(BinTree T, BinTNode* p, LR d);
void PreOrderTraverse(BinTree T, void (*fp)(ElemType));
void InOrderTraverse(BinTree T, void (*fp)(ElemType));
void PostOrderTraverse(BinTree T, void (*fp)(ElemType));
void LevelOrderTraverse(BinTree T, void (*fp)(ElemType));

#endif /* DYNALNKBITREE_H */
