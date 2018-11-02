#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

LinkList Initlist(int n)
{
	LinkList p;
	int i=n;
	LinkList h=NULL;
	while (i>0)
	{
		p=(LinkList)malloc(sizeof(LNode));
		p ->data = i;
		p->next=h;
		h=p;
		i--;
	}
	return h;
}
void  josephus(LinkList L,const int n, const int m)
{
	LinkList p = L;
	int i,k,j=0;
	int q = n;
	for(i=0;;i++) 
	{
		if(i==n) 
			i=0;
		for(k = 0;k<i;k++)
		{
			p = p->next;
		}
		if(p->data!=0) 
			j++;
		else
		{
			p = L;
			continue; 
		}
		if(j%m==0)
		{
			p->data=0;
			q--;
		}
		p = L;
		if(q==1) 
			break;	
	} 
	for(i=0;i<n;i++) 
	{
		if(p->data!=0) 
			printf("最后留下的是原来的第%d号\n",p->data); 
		p = p->next;
	}
}

int main(void)
{
	LinkList p;
    int n, m;
    printf("请输入人的总数：");
    scanf("%d", &n);
    printf("请输入报数值：");
    scanf("%d", &m);
	p = Initlist(n);
	josephus(p,n,m);
	system("pause");
    return 0;
}
