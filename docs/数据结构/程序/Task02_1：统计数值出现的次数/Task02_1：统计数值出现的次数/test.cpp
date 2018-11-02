/*链表数据域是整数，在0--9之间，统计数值出现的次数*/
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

bool CreatList(LinkList *L,int n)
{
	(*L) = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	int i = 0;
	LinkList p;
	LinkList q = (*L);
	while(i<n)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d",&(p->data));
		p->next = NULL;
		q->next = p;
		q = p;
		i++;
	}
	return true;
}
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
bool CalateList(LinkList L)
{
	int a[10] = {0,0,0,0,0,0,0,0,0,0};
	int i = 0;
	LinkList p  =L->next;
	for(;i<10;i++)
	{
		while(p!=NULL)
		{
			if(p->data==i)
				a[i]++;
			p = p->next;
		}
		p = L->next;
	}
	for(i = 0;i<10;i++)
	{
		if(a[i]!=0)
			printf("%d出现了%d次\n",i,a[i]);
	}
	return true;
}
int main()
{
	LinkList l;
	CreatList(&l,6);
	TravesList(l);
	CalateList(l);
	return 0;
}