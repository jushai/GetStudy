#include<stdio.h>
#include<stdlib.h>

typedef int QElemType;

#define MAXSIZE 100
typedef struct
{
	QElemType *base;
	int front;
	int rear;
}SqQueue;
/************************************************************************/
/*��ʼ��*/
bool InitQueue(SqQueue *Q)
{
	Q->base = (QElemType *)malloc(MAXSIZE*sizeof(QElemType));
	if(!Q->base)
		return false;
	Q->front = Q->rear = 0;
	return true;
}
/************************************************************************/
/*���*/
bool EnQueue(SqQueue *Q,QElemType e)
{
	if((Q->rear+1)%MAXSIZE==Q->front)
		return false;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear+1)%MAXSIZE;
	return true;
}
/************************************************************************/
/*����*/
bool DeQueue(SqQueue *Q,QElemType *e)
{
	if(Q->front==Q->rear)
		return false;
	*e = Q->base[Q->front];
	Q->front = (Q->front+1)%MAXSIZE;
	return true;
}
/************************************************************************/
/*�õ���ͷԪ��*/
bool GetTop(SqQueue Q,QElemType *e)
{
	if(Q.rear==Q.front)
		return false;
	*e = Q.base[Q.front];
	return true;
}
/************************************************************************/
/*�󳤶�*/
int LengthQueue(SqQueue Q)
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}
/************************************************************************/
/*�п�*/
bool QueueEmpty(SqQueue Q)
{
	if(Q.rear == Q.front)
		return true;
	return false;
}
/************************************************************************/
/*���*/
bool ClearQueue(SqQueue *Q)
{
	Q->rear = Q->front;
	return true;
}
/************************************************************************/
/*����*/
bool DestoryQueue(SqQueue *Q)
{
	Q->rear = NULL;
	Q->front = NULL;
	free(Q->base);
	return true;
}
/************************************************************************/
/*����*/
void VisitQueue(SqQueue Q)
{
	int p = Q.front;
	if(Q.rear == Q.front)
		printf("û��Ԫ��!\n");
	else
	{
		while(p%MAXSIZE<Q.rear)
		{
			printf("%d\t",Q.base[p]);
			p = (p+1)%MAXSIZE;
		}
		printf("\n");
	}
}
/**************************************************************************************/
/*����������*/
int main(void)
{
	SqQueue s;
	int a;
	InitQueue(&s);
	EnQueue(&s,1);
	EnQueue(&s,2);
	EnQueue(&s,3);
	EnQueue(&s,4);
	EnQueue(&s,5);
	VisitQueue(s);
	DeQueue(&s,&a);
	printf("%d\n",a);
	VisitQueue(s);
	if(QueueEmpty(s)==false)
		a = 0;
	printf("%d\n",a);
	GetTop(s,&a);
	printf("%d\n",a);
	a = LengthQueue(s);
	printf("%d\n",a);
	if(ClearQueue(&s)==true)
		a = 1;
	printf("%d\n",a);
	VisitQueue(s);
	system("pause");
	return 0;
}
