#include<stdio.h>
#include<stdlib.h>

typedef int SElemType;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
/**************************************************************************************/
/*��ʶ������*/
bool InitStack(SqStack *S)
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S->base)
		return false;
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return true;
}
/**************************************************************************************/
/*��ջ*/
bool Push(SqStack *S,SElemType e)
{
	if(S->top-S->base>=S->stacksize)
	{
		S->base = (SElemType *)realloc(S->base,(STACK_INIT_SIZE+STACKINCREMENT)*sizeof(SElemType));
		if(!S->base)
			return false;
		S->top = S->base+S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top ++ = e;
	return true;
}
/**************************************************************************************/
/*��ջ*/
bool Pop(SqStack *S,SElemType *e)
{
	if(S->base==S->top)
		return false;
	*e = *--S->top;
	return true;
}
/**************************************************************************************/
/*�õ�ջ��Ԫ��*/
bool GetTop(SqStack *S,SElemType *e)
{
	if(S->base==S->top)
		return false;
	*e = *(S->top-1);
	return true;
}
/**************************************************************************************/
/*�ж��Ƿ�Ϊ��*/
bool StackEmpty(SqStack *S)
{
	if(S->top==S->base)
		return true;
	return false;
}
/**************************************************************************************/
/*�󳤶�*/
int StackLength(SqStack S)
{
	return S.top - S.base;
}
/**************************************************************************************/
/*���*/
bool ClearStack(SqStack *S)
{
	S->top = S->base;
	return true;
}
/**************************************************************************************/
/*����*/
bool DestoryStack(SqStack S)
{
	free(S.base);
	S.base = S.top = NULL;
	return true;
}
/**************************************************************************************/
/*����*/
void VisitStack(SqStack *S)
{
	SElemType* p;
	p= S->base;
	if(S->base == S->top)
		printf("û��Ԫ��!\n");
	else
	{
		while(p!=S->top)
		{
			printf("%d\t",*p);
			p++;
		}
		printf("\n");
	}
}
/**************************************************************************************/
/*����������*/
int main(void)
{
	SqStack s;
	int a;
	InitStack(&s);
	Push(&s,1);
	Push(&s,2);
	Push(&s,3);
	Push(&s,4);
	Push(&s,5);
	VisitStack(&s);
	Pop(&s,&a);
	printf("%d\n",a);
	VisitStack(&s);
	if(StackEmpty(&s)==false)
		a = 0;
	printf("%d\n",a);
	GetTop(&s,&a);
	printf("%d\n",a);
	a = StackLength(s);
	printf("%d\n",a);
	if(ClearStack(&s)==true)
		a = 1;
	printf("%d\n",a);
	VisitStack(&s);
	system("pause");
	return 0;
}