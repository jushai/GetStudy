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
/*初识化操作*/
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
/*入栈*/
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
/*出栈*/
bool Pop(SqStack *S,SElemType *e)
{
	if(S->base==S->top)
		return false;
	*e = *--S->top;
	return true;
}
/**************************************************************************************/
/*得到栈顶元素*/
bool GetTop(SqStack *S,SElemType *e)
{
	if(S->base==S->top)
		return false;
	*e = *(S->top-1);
	return true;
}
/**************************************************************************************/
/*判断是否为空*/
bool StackEmpty(SqStack *S)
{
	if(S->top==S->base)
		return true;
	return false;
}
/**************************************************************************************/
/*求长度*/
int StackLength(SqStack S)
{
	return S.top - S.base;
}
/**************************************************************************************/
/*清空*/
bool ClearStack(SqStack *S)
{
	S->top = S->base;
	return true;
}
/**************************************************************************************/
/*销毁*/
bool DestoryStack(SqStack S)
{
	free(S.base);
	S.base = S.top = NULL;
	return true;
}
/**************************************************************************************/
/*遍历*/
void VisitStack(SqStack *S)
{
	SElemType* p;
	p= S->base;
	if(S->base == S->top)
		printf("没有元素!\n");
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
/*主函数测试*/
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