#include<stdio.h>
#include<stdlib.h>

typedef int SElemType;

typedef struct SNode
{
	SElemType data;
	struct SNode *next;
}SNode,*LinkStack;
/**************************************************************************************/
/*初识化操作*/
bool InitStack(LinkStack *S)
{
	*S = NULL;
	return true;
}
/**************************************************************************************/
/*入栈*/
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
/*出栈*/
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
/*得到栈顶元素*/
bool GetTop(LinkStack S,SElemType *e)
{
	if(S==NULL)
		return false;
	*e = S->data;
	return true;
}
/**************************************************************************************/
/*判断是否为空*/
bool StackEmpty(LinkStack S)
{
	if(S==NULL)
		return true;
	return false;
}
/**************************************************************************************/
/*求长度*/
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
/*清空*/
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
/*遍历*/
void VisitStack(LinkStack S)
{
	LinkStack p=S;
	if(p==NULL)
		printf("没有元素\n");
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
/*主函数测试*/
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