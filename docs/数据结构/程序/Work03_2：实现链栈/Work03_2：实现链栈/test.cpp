#include<stdio.h>
#include<stdlib.h>

typedef int SElemType;

typedef struct SNode
{
	SElemType data;
	struct SNode *next;
}SNode,*LinkStack;
/**************************************************************************************/
/*��ʶ������*/
bool InitStack(LinkStack *S)
{
	*S = NULL;
	return true;
}
/**************************************************************************************/
/*��ջ*/
bool Push(LinkStack *S,SElemType e)
{
	LinkStack p;
	p = (LinkStack)malloc(sizeof(SNode));
	if(!p)
		return false;
	p->next = *S;
	p->data = e;
	*S = p;
	return true;
}
/**************************************************************************************/
/*��ջ*/
bool Pop(LinkStack *S,SElemType *e)
{
	LinkStack p = *S;
	if(*S==NULL)
		return false;
	*S = p->next;
	*e = p->data;
	free(p);
	return true;
}
/**************************************************************************************/
/*�õ�ջ��Ԫ��*/
bool GetTop(LinkStack S,SElemType *e)
{
	if(S==NULL)
		return false;
	*e = S->data;
	return true;
}
/**************************************************************************************/
/*�ж��Ƿ�Ϊ��*/
bool StackEmpty(LinkStack S)
{
	if(S==NULL)
		return true;
	return false;
}
/**************************************************************************************/
/*�󳤶�*/
int StackLength(LinkStack S)
{
	LinkStack p=S;
	int i = 0;
	while(p!=NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}
/**************************************************************************************/
/*���*/
bool ClearStack(LinkStack *S)
{
	LinkStack p=*S;
	while(p!=NULL)
	{
		*S = (*S)->next;
		free(p);
		p =*S;
	}
	*S = NULL;
	return true;
}
/**************************************************************************************/
/*����*/
void VisitStack(LinkStack S)
{
	LinkStack p=S;
	if(p==NULL)
		printf("û��Ԫ��\n");
	else
	{
		while(p!=NULL)
		{
			printf("%d\t",p->data);
			p = p->next;
		}
		printf("\n");
	}
}
/**************************************************************************************/
/*����������*/
int main(void)
{
	LinkStack s;
	int a;
	InitStack(&s);
	Push(&s,1);
	Push(&s,2);
	Push(&s,3);
	Push(&s,4);
	Push(&s,5);
	VisitStack(s);
	Pop(&s,&a);
	printf("%d\n",a);
	VisitStack(s);
	if(StackEmpty(s)==false)
		a = 0;
	printf("%d\n",a);
	GetTop(s,&a);
	printf("%d\n",a);
	a = StackLength(s);
	printf("%d\n",a);
	if(ClearStack(&s)==true)
		a = 1;
	printf("%d\n",a);
	VisitStack(s);
	system("pause");
	return 0;
}