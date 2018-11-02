/***
*DynaLnkBiTree.cpp - 动态链式二叉树，即二叉树的动态链式存储实现
*
*
*题目：实验6-1 二叉树的动态链式存储实现
*
*班级：2班
*
*姓名：付子旺
*
*学号：2016011409
*	
****/

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <assert.h>
#include "DynaLnkBiTree.h"

/*------------------------------------------------------------
操作目的：	初始化二叉树
初始条件：	无
操作结果：	构造空二叉树
函数参数：
		BinTree *T	待初始化的二叉树
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool InitBinTree(BinTree *T)
{
	(*T) = NULL;
	return true;
}

/*------------------------------------------------------------
操作目的：	销毁二叉树
初始条件：	二叉树T已存在
操作结果：	销毁二叉树
函数参数：
		BinTree *T	待销毁的二叉树
返回值：
		无
------------------------------------------------------------*/
void DestroyBinTree(BinTree *T)
{
	if(*T)  
    {  
        if((*T)->l)  
        {  
            DestroyBinTree((*T)->l);       
        }  
        if((*T)->r)  
        {  
            DestroyBinTree((*T)->r);       
        }  
  
        free(*T);  
        *T = NULL;  
    }  
}

/*------------------------------------------------------------
操作目的：	创建二叉树
初始条件：	二叉树T已存在
操作结果：	销毁二叉树
函数参数：
		BinTree *T	二叉树T
返回值：
		bool		操作是否成功
参考提示：
			请按照教材131页算法6.4的方式来创建二叉树。
------------------------------------------------------------*/
bool CreateBinTree(BinTree *T)
{
	int ch;  
    scanf("%d",&ch);  
    if (ch == ' ')  
    {  
        *T = NULL;  
        return true;
    }  
    else  
    {  
		*T = (BinTree)malloc(sizeof(BiNode)); 
        if (T == NULL)  
        {  
            return false;
        }  
        else  
        {  
            (*T)->data = ch;  
            CreateBinTree(&((*T)->l));  
            CreateBinTree((&(*T)->r));  
        }
		return true;
    }
}

/*------------------------------------------------------------
操作目的：	清空二叉树
初始条件：	二叉树T已存在
操作结果：	清空二叉树
函数参数：
		BinTree *T	待清空的二叉树
返回值：
		无
------------------------------------------------------------*/
void ClearBinTree(BinTree *T)
{
	if(*T == NULL)
        return;
    ClearBinTree(&(*T)->l);
    ClearBinTree(&(*T)->r);
    free(*T);
	*T = NULL;
}

/*------------------------------------------------------------
操作目的：	二叉树判空
初始条件：	二叉树T已存在
操作结果：	若T为空，则返回true；否则返回false
函数参数：
		BinTree T	二叉树T
返回值：
		bool		二叉树是否为空
------------------------------------------------------------*/
bool BinTreeEmpty(BinTree T)
{
	if(T==NULL)
		return true;
	else
		return false;

}

/*------------------------------------------------------------
操作目的：	二叉树求深度
初始条件：	二叉树T已存在
操作结果：	返回二叉树T的深度
函数参数：
		BinTree T	二叉树T
返回值：
		int			二叉树的深度
------------------------------------------------------------*/
int BinTreeDepth(BinTree T)
{
	int deep = 0;
	int leftdeep,rightdeep;
	if(T!=NULL)
	{
		leftdeep = BinTreeDepth(T->l);
		rightdeep = BinTreeDepth(T->r);
		deep = leftdeep>rightdeep?leftdeep+1:rightdeep+1;
	}
	return deep;
}

/*------------------------------------------------------------
操作目的：	得到二叉树的根结点
初始条件：	二叉树T已存在
操作结果：	返回二叉树T的根结点
函数参数：
		BinTree T	二叉树T
返回值：
		BinTNode*	二叉树的根结点指针
------------------------------------------------------------*/
BinTNode *Root(BinTree T)
{
	return T;
}

/*------------------------------------------------------------
操作目的：	判断结点n是否为树T的合法结点
初始条件：	二叉树T已存在
操作结果：	n为T的结点返回true，否则返回false
函数参数：
		BinTree T	二叉树T
		BinTNode* n	二叉树的结点n
返回值：
		bool		结点n是否存在与二叉树T中
------------------------------------------------------------*/
bool NodeExist(BinTree T, BinTNode* n)
{
	if(T==NULL)
		return false;
	if(T==n)
		return true;
	else if(T->l,n)
		return true;
	else if(T->r,n)
		return true;
	else
		return false;
}

/*------------------------------------------------------------
操作目的：	得到二叉树指定结点的值
初始条件：	二叉树T已存在，n是二叉树T中的结点
操作结果：	返回结点n的值
函数参数：
		BinTree T	二叉树T
		BinTNode* n	二叉树结点n
返回值：
		ElemType	结点n的值
------------------------------------------------------------*/
ElemType Value(BinTree T, BinTNode* n)
{
	if(n!=NULL)
	{
		if(NodeExist(T,n)==true)
			return n->data;
	}
}

/*------------------------------------------------------------
操作目的：	对二叉树的指定结点赋值
初始条件：	二叉树T已存在，n是二叉树T中的结点
操作结果：	操作成功返回true，操作失败返回false
函数参数：
		BinTree T	二叉树T
		BinTNode* n	二叉树结点n
		ElemType e	结点值
返回值：
		无
------------------------------------------------------------*/
void Assign(BinTree T, BinTNode* n, ElemType e)
{
	if(n!=NULL)
	{
		if(NodeExist(T,n)==true)
			n->data = e;
	}
}

/*------------------------------------------------------------
操作目的：	得到二叉树指定结点的父结点
初始条件：	二叉树T已存在，n是二叉树T中的结点
操作结果：	如果二叉树结点n有父结点则返回父结点指针，否则返回NULL
函数参数：
		BinTree T	二叉树T
		BinTNode* n	二叉树结点n
返回值：
		BinTNode*	父结点指针
------------------------------------------------------------*/
BinTNode* Parent(BinTree T, BinTNode* n)
{
	if(n==T||T==NULL)
		return NULL;
	BinTNode* p = NULL;
	if(T->l == n||T->r == n)
		return T;
	else
	{
		if((p = Parent(T->l,n))!=NULL)
			return p;
		if((p = Parent(T->r,n))!=NULL)
			return p;
	}
}

/*------------------------------------------------------------
操作目的：	得到二叉树指定结点的左孩子
初始条件：	二叉树T已存在，n是二叉树T中的结点
操作结果：	如果二叉树结点n有左孩子则返回左孩子结点指针，否则返回NULL
函数参数：
		BinTree T	二叉树T
		BinTNode* n	二叉树结点n
返回值：
		BinTNode*	左孩子结点指针
------------------------------------------------------------*/
BinTNode* LeftChild(BinTree T, BinTNode* n)
{
	if(n!=NULL)
	{
		if(NodeExist(T,n)==true)
			return n->l;
	}
}

/*------------------------------------------------------------
操作目的：	得到二叉树指定结点的右孩子
初始条件：	二叉树T已存在，n是二叉树T中的结点
操作结果：	如果二叉树结点n有右孩子则返回右孩子结点指针，否则返回NULL
函数参数：
		BinTree T	二叉树T
		BinTNode* n	二叉树结点n
返回值：
		BinTNode*	右孩子结点指针
------------------------------------------------------------*/
BinTNode* RightChild(BinTree T, BinTNode* n)
{
	if(n!=NULL)
	{
		if(NodeExist(T,n)==true)
			return n->r;
	}
}

/*------------------------------------------------------------
操作目的：	得到二叉树指定结点的左兄弟
初始条件：	二叉树T已存在，n是二叉树T中的结点
操作结果：	如果二叉树结点n有左兄弟则返回左兄弟结点指针，否则返回NULL
函数参数：
		BinTree T	二叉树T
		BinTNode* n	二叉树结点n
返回值：
		BinTNode*	左兄弟结点指针
------------------------------------------------------------*/
BinTNode* LeftSibling(BinTree T, BinTNode* n)
{
	if(n!=NULL)
	{
		if(NodeExist(T,n)==true)
		{
			if(Parent(T,n)==NULL)
				return NULL;
			else
			{
				return (Parent(T,n)->l==n)?NULL:Parent(T,n)->l;
			}
		}
	}
}

/*------------------------------------------------------------
操作目的：	得到二叉树指定结点的右兄弟
初始条件：	二叉树T已存在，n是二叉树T中的结点
操作结果：	如果二叉树结点n有右兄弟则返回右兄弟结点指针，否则返回NULL
函数参数：
		BinTree T	二叉树T
		BinTNode* n	二叉树结点n
返回值：
		BinTNode*	右兄弟结点指针
------------------------------------------------------------*/
BinTNode* RightSibling(BinTree T, BinTNode* n)
{
	if(n!=NULL)
	{
		if(NodeExist(T,n)==true)
		{
			if(Parent(T,n)==NULL)
				return NULL;
			else
			{
				return (Parent(T,n)->r==n)?NULL:Parent(T,n)->r;
			}
		}
	}
}

/*------------------------------------------------------------
操作目的：	在二叉树中插入结点
初始条件：	二叉树T已存在，p是二叉树T中的结点，n为待插入的结点
操作结果：	在二叉树的p结点之前插入结点n
函数参数：
		BinTree T	二叉树T
		BinTNode* p	二叉树结点p
		LR d		二叉树结点p成为新结点n的左孩子或者右孩子
		BinTNode* p	待插入结点n
返回值：
		无
------------------------------------------------------------*/
void InsertNode(BinTree T, BinTNode* p, LR d, BinTNode* n)
{
	if(n!=NULL||T!=NULL||p!=NULL||n->r==NULL)
	{
		if(NodeExist(T,n)==true)
		{
			if(LEFT==d)
			{
				n->r = p->l;
				p->l = n;
			}
			else
			{
				n->r = p->l;
				p->r = n;
			}
		}
	}
}

/*------------------------------------------------------------
操作目的：	在二叉树中删除结点
初始条件：	二叉树T已存在，p是二叉树T中的结点
操作结果：	删除二叉树的p结点
函数参数：
		BinTree T	二叉树T
		BinTNode* p	二叉树结点p
		LR d		结点p的左孩子或者右孩子来取代p
返回值：
		无
------------------------------------------------------------*/
void DeleteNode(BinTree T, BinTNode* p, LR d)
{
	if(NodeExist(T,p)==true)
	{
		BinTNode * parent = NULL;
		parent = Parent(T,p);
		if(parent==NULL)
		{
			T = p->r;
			DestroyBinTree(&(p->l));
		}
		else if(parent->l == p)
		{
			parent->l = p->r;
			DestroyBinTree(&(p->l));
		}
		else
		{
			parent->r = p->r;
			DestroyBinTree(&(p->l));
		}
	}
}

/*------------------------------------------------------------
操作目的：	先序遍历二叉树
初始条件：	二叉树T已存在
操作结果：	先序的方式，对二叉树的每个结点调用(*fp)一次且仅一次
函数参数：
		BinTree T	二叉树T
		*fp			访问函数指针
返回值：
		无
------------------------------------------------------------*/
void PreOrderTraverse(BinTree T, void (*fp)(ElemType))
{
	if(T)
	{
		visit(T->data);
		PreOrderTraverse(T->l,visit);
		PreOrderTraverse(T->r,visit);
	}
}

/*------------------------------------------------------------
操作目的：	中序遍历二叉树
初始条件：	二叉树T已存在
操作结果：	中序的方式，对二叉树的每个结点调用(*fp)一次且仅一次
函数参数：
		BinTree T	二叉树T
		*fp			访问函数指针
返回值：
		无
------------------------------------------------------------*/
void InOrderTraverse(BinTree T, void (*fp)(ElemType))
{
	if(T)
	{
		InOrderTraverse(T->l,visit);
		visit(T->data);
		InOrderTraverse(T->r,visit);
	}
}

/*------------------------------------------------------------
操作目的：	后序遍历二叉树
初始条件：	二叉树T已存在
操作结果：	后序的方式，对二叉树的每个结点调用(*fp)一次且仅一次
函数参数：
		BinTree T	二叉树T
		*fp			访问函数指针
返回值：
		无
------------------------------------------------------------*/
void PostOrderTraverse(BinTree T, void (*fp)(ElemType))
{
	if(T)
	{
		PostOrderTraverse(T->l,visit);
		PostOrderTraverse(T->r,visit);
		visit(T->data);
	}
}

/*------------------------------------------------------------
操作目的：	层序遍历二叉树
初始条件：	二叉树T已存在
操作结果：	层序的方式，对二叉树的每个结点调用(*fp)一次且仅一次
函数参数：
		BinTree T	二叉树T
		*fp			访问函数指针
返回值：
		无
------------------------------------------------------------*/
void LevelOrderTraverse(BinTree T, void (*fp)(ElemType))
{
	if(T==NULL)
	{
		printf("false");
	}
	BinTree queue[80];
	int front =0;
	int rear = 0;
	BinTree p =T;
	queue[rear++] = T;
	while(rear!=front)
	{
		(*fp)(p->data);
		front = (front +1) %80;
		if(NULL!=p->l)
		{
			queue[rear] = p->l;
			rear = (rear+1)%80;
		}
		if(NULL!=p->r)
		{
			queue[rear] = p->r;
			rear = (rear+1)%80;
		}
		p = queue[front];
	}
}