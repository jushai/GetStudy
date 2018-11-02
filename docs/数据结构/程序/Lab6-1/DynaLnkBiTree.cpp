/***
*DynaLnkBiTree.cpp - ��̬��ʽ�����������������Ķ�̬��ʽ�洢ʵ��
*
*
*��Ŀ��ʵ��6-1 �������Ķ�̬��ʽ�洢ʵ��
*
*�༶��2��
*
*������������
*
*ѧ�ţ�2016011409
*	
****/

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <assert.h>
#include "DynaLnkBiTree.h"

/*------------------------------------------------------------
����Ŀ�ģ�	��ʼ��������
��ʼ������	��
���������	����ն�����
����������
		BinTree *T	����ʼ���Ķ�����
����ֵ��
		bool		�����Ƿ�ɹ�
------------------------------------------------------------*/
bool InitBinTree(BinTree *T)
{
	(*T) = NULL;
	return true;
}

/*------------------------------------------------------------
����Ŀ�ģ�	���ٶ�����
��ʼ������	������T�Ѵ���
���������	���ٶ�����
����������
		BinTree *T	�����ٵĶ�����
����ֵ��
		��
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
����Ŀ�ģ�	����������
��ʼ������	������T�Ѵ���
���������	���ٶ�����
����������
		BinTree *T	������T
����ֵ��
		bool		�����Ƿ�ɹ�
�ο���ʾ��
			�밴�ս̲�131ҳ�㷨6.4�ķ�ʽ��������������
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
����Ŀ�ģ�	��ն�����
��ʼ������	������T�Ѵ���
���������	��ն�����
����������
		BinTree *T	����յĶ�����
����ֵ��
		��
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
����Ŀ�ģ�	�������п�
��ʼ������	������T�Ѵ���
���������	��TΪ�գ��򷵻�true�����򷵻�false
����������
		BinTree T	������T
����ֵ��
		bool		�������Ƿ�Ϊ��
------------------------------------------------------------*/
bool BinTreeEmpty(BinTree T)
{
	if(T==NULL)
		return true;
	else
		return false;

}

/*------------------------------------------------------------
����Ŀ�ģ�	�����������
��ʼ������	������T�Ѵ���
���������	���ض�����T�����
����������
		BinTree T	������T
����ֵ��
		int			�����������
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
����Ŀ�ģ�	�õ��������ĸ����
��ʼ������	������T�Ѵ���
���������	���ض�����T�ĸ����
����������
		BinTree T	������T
����ֵ��
		BinTNode*	�������ĸ����ָ��
------------------------------------------------------------*/
BinTNode *Root(BinTree T)
{
	return T;
}

/*------------------------------------------------------------
����Ŀ�ģ�	�жϽ��n�Ƿ�Ϊ��T�ĺϷ����
��ʼ������	������T�Ѵ���
���������	nΪT�Ľ�㷵��true�����򷵻�false
����������
		BinTree T	������T
		BinTNode* n	�������Ľ��n
����ֵ��
		bool		���n�Ƿ�����������T��
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
����Ŀ�ģ�	�õ�������ָ������ֵ
��ʼ������	������T�Ѵ��ڣ�n�Ƕ�����T�еĽ��
���������	���ؽ��n��ֵ
����������
		BinTree T	������T
		BinTNode* n	���������n
����ֵ��
		ElemType	���n��ֵ
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
����Ŀ�ģ�	�Զ�������ָ����㸳ֵ
��ʼ������	������T�Ѵ��ڣ�n�Ƕ�����T�еĽ��
���������	�����ɹ�����true������ʧ�ܷ���false
����������
		BinTree T	������T
		BinTNode* n	���������n
		ElemType e	���ֵ
����ֵ��
		��
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
����Ŀ�ģ�	�õ�������ָ�����ĸ����
��ʼ������	������T�Ѵ��ڣ�n�Ƕ�����T�еĽ��
���������	������������n�и�����򷵻ظ����ָ�룬���򷵻�NULL
����������
		BinTree T	������T
		BinTNode* n	���������n
����ֵ��
		BinTNode*	�����ָ��
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
����Ŀ�ģ�	�õ�������ָ����������
��ʼ������	������T�Ѵ��ڣ�n�Ƕ�����T�еĽ��
���������	������������n�������򷵻����ӽ��ָ�룬���򷵻�NULL
����������
		BinTree T	������T
		BinTNode* n	���������n
����ֵ��
		BinTNode*	���ӽ��ָ��
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
����Ŀ�ģ�	�õ�������ָ�������Һ���
��ʼ������	������T�Ѵ��ڣ�n�Ƕ�����T�еĽ��
���������	������������n���Һ����򷵻��Һ��ӽ��ָ�룬���򷵻�NULL
����������
		BinTree T	������T
		BinTNode* n	���������n
����ֵ��
		BinTNode*	�Һ��ӽ��ָ��
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
����Ŀ�ģ�	�õ�������ָ���������ֵ�
��ʼ������	������T�Ѵ��ڣ�n�Ƕ�����T�еĽ��
���������	������������n�����ֵ��򷵻����ֵܽ��ָ�룬���򷵻�NULL
����������
		BinTree T	������T
		BinTNode* n	���������n
����ֵ��
		BinTNode*	���ֵܽ��ָ��
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
����Ŀ�ģ�	�õ�������ָ���������ֵ�
��ʼ������	������T�Ѵ��ڣ�n�Ƕ�����T�еĽ��
���������	������������n�����ֵ��򷵻����ֵܽ��ָ�룬���򷵻�NULL
����������
		BinTree T	������T
		BinTNode* n	���������n
����ֵ��
		BinTNode*	���ֵܽ��ָ��
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
����Ŀ�ģ�	�ڶ������в�����
��ʼ������	������T�Ѵ��ڣ�p�Ƕ�����T�еĽ�㣬nΪ������Ľ��
���������	�ڶ�������p���֮ǰ������n
����������
		BinTree T	������T
		BinTNode* p	���������p
		LR d		���������p��Ϊ�½��n�����ӻ����Һ���
		BinTNode* p	��������n
����ֵ��
		��
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
����Ŀ�ģ�	�ڶ�������ɾ�����
��ʼ������	������T�Ѵ��ڣ�p�Ƕ�����T�еĽ��
���������	ɾ����������p���
����������
		BinTree T	������T
		BinTNode* p	���������p
		LR d		���p�����ӻ����Һ�����ȡ��p
����ֵ��
		��
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
����Ŀ�ģ�	�������������
��ʼ������	������T�Ѵ���
���������	����ķ�ʽ���Զ�������ÿ��������(*fp)һ���ҽ�һ��
����������
		BinTree T	������T
		*fp			���ʺ���ָ��
����ֵ��
		��
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
����Ŀ�ģ�	�������������
��ʼ������	������T�Ѵ���
���������	����ķ�ʽ���Զ�������ÿ��������(*fp)һ���ҽ�һ��
����������
		BinTree T	������T
		*fp			���ʺ���ָ��
����ֵ��
		��
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
����Ŀ�ģ�	�������������
��ʼ������	������T�Ѵ���
���������	����ķ�ʽ���Զ�������ÿ��������(*fp)һ���ҽ�һ��
����������
		BinTree T	������T
		*fp			���ʺ���ָ��
����ֵ��
		��
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
����Ŀ�ģ�	�������������
��ʼ������	������T�Ѵ���
���������	����ķ�ʽ���Զ�������ÿ��������(*fp)һ���ҽ�һ��
����������
		BinTree T	������T
		*fp			���ʺ���ָ��
����ֵ��
		��
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