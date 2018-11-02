#include<stdio.h>
#include<stdlib.h>

typedef char TElemType;
typedef struct BiTNode 
{
	TElemType data; 
	struct BiTNode *Lchild, *Rchild;
} BiTNode, *BiTree;

bool CreateBiTree(BiTree &T)
{
	char ch;
	scanf("%c",&ch);
	if(ch == '#')
		T = NULL;
	else
	{
		if(!(T = (BiTNode *)malloc(sizeof(BiTNode))))
			return false;
		T->data = ch;
		CreateBiTree(T->Lchild);
		CreateBiTree(T->Rchild);
	}
	return true;
}
void visit(BiTree T)
{
	if(T)
	{
		printf("%c",T->data);
		visit(T->Lchild);
		visit(T->Rchild);
	}
}

void SearchBST(BiTree T)
{
	if(T)
	{
		if(T->Lchild&&T->Lchild->data < T->data)
		{
			SearchBST(T->Lchild);
		}
		if(T->Rchild&&T->Rchild->data > T->data)
		{
			SearchBST(T->Rchild);
		}
	}
}
int main()
{
	BiTree l;
	CreateBiTree(l);
	visit(l);
	SearchBST(l);
	return 0;
}

