#include<stdio.h>
#include<stdlib.h>
typedef char TElemType;
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
/****************************************************/
bool InitTree(BiTree *T)
{
	*T = NULL;
}

void DestoryTree(BiTree *T)
{
	if(*T==NULL)
		return;
	else
	{
		DestoryTree(&((*T)->lchild));
		DestoryTree(&((*T)->rchild));
		free(*T);
		*T=NULL;
	}
}

void PreVisit(BiTree T)
{
	if(T!=NULL)
	{
		PreVisit(T->lchild);
		printf("%d",&T->data);
		PreVisit(T->rchild);
	}
}
void InVisit(BiTree T)
{
	if(T!=NULL)
	{
		printf("%d",&T->data);
		PreVisit(T->lchild);
		PreVisit(T->rchild);
	}
}
void PostVisit(BiTree T)
{
	if(T!=NULL)
	{
		PreVisit(T->lchild);
		PreVisit(T->rchild);
		printf("%d",&T->data);
	}
}

/*统计树的深度*/
int Length(BiTree T)
{
	int deep;
	int leftdeep,rightdeep;
	if(T!=NULL)
	{
		Length(T->lchild);
		Length(T->rchild);
		deep = leftdeep>rightdeep?leftdeep:rightdeep;
	}
	return deep;
}
int count = 0;
/*统计叶子节点的个数*/
void Count(BiTree T)
{
	if(T!=NULL)
	{
		if((!T->lchild)&&(!T->rchild))
			count++;
		Count(T->lchild);
		Count(T->rchild);
	}
}
/*统计所有的结点*/
int CountNode(BiTree T)
{
	if(T!=NULL)
	{
		return 1+CountNode(T->lchild)+CountNode(T->rchild);
	}
	return 0;
}