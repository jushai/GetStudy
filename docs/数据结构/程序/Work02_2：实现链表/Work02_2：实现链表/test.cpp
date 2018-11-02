#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
/************************************************/
/*初始化*/
bool InitList(LinkList *L)
{
	(*L) = (LinkList)malloc(sizeof(LNode));
	if(!(*L))
		return false;
	(*L)->next = NULL;
	return true;
}
/************************************************/
/*查找*/
bool GetElem(LinkList L,int i,ElemType *e)
{
	LinkList p =L->next;
	int j = 1;
	while(p!=NULL&&j<i)
	{
		j++;
		p = p->next;
	}
	if(j>i||!p)
		return false;
	*e = p->data;
	return true;
}
/************************************************/
/*插入*/
bool InsertList(LinkList *L,int i,ElemType e)
{
	LinkList p = *L;
	int j = 0;
	while(p&&j<i-1)
	{
		p = p->next;
		++j;
	}
	if(!p||j>i-1)
		return false;
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
/************************************************/
/*删除*/
bool DeleteList(LinkList *L,int i,ElemType *e)
{
	LinkList p = *L;
	int j = 0;
	while(p&&j<i-1)
	{
		p = p->next;
		++j;
	}
	if(!p||j>i-1)
		return false;
	LinkList q = p->next;
	(*e) = q->data;
	p->next  =q->next;
	free(q);
	return true;
}
/************************************************/
/*逆置*/
bool InverseList(LinkList *L)
{
	LinkList p = (*L)->next;
	LinkList q;
	(*L)->next = NULL;
	while(p)
	{
		q = p;
		p = p->next;
		q->next = (*L)->next;
		(*L)->next = q;
	}
	return true;
}
/************************************************/
/*求长度*/
int LengthList(LinkList L)
{
	LinkList p = L->next;
	int i = 0;
	while(p)
	{
		i++;
		p = p->next;
	}
	return i;
}
/************************************************/
/*排序*/
bool SortList(LinkList L)
{
	int i,j,k;
	LinkList p =L->next;
	int a = LengthList(L);
	for(i = 0;i<a-1;i++)
	{
		p = L->next;
		for(j = 0;j<a-i-1;j++)
		{
			if(p->data > p->next->data)
			{
				k = p->data;
				p->data = p->next->data;
				p->next->data = k;
			}
			p = p->next;
		}
	}
	return true;
}
/************************************************/
/*合并*/
void MergeList_L(LinkList La,LinkList Lb,LinkList Lc)
{
	LinkList pa,pb,pc;
	pa = La->next;pb = Lb->next;
	Lc = pc = La;
	while(pa&&pb)
	{
		if (pa->data<=pb->data)
		{
			pc->next = pa;
			pc =pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc =pb;
			pb = pb->next;
		}
	}
	pc->next = pa?pa:pb;
	free(Lb);
}
/************************************************/
/*头插法*/
bool CreatList(LinkList *L,int n)
{
	LinkList p;
	int i = 0;
	while(i<n)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->next = (*L)->next;
		(*L)->next = p;
		i++;
	}
	return true;
}
/************************************************/
/*遍历*/
void TravesList(LinkList L)
{
	LinkList p  =L->next;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	LinkList l;
	InitList(&l);
	CreatList(&l,6);
	TravesList(l);
	SortList(l);
	TravesList(l);
	return 0;
}