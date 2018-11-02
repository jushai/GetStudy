#include<stdio.h>
#include<stdlib.h>

typedef int QElemType;

typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
/************************************************************************/
/*��ʼ��*/
bool InitQueue(LinkQueue *Q)
{
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
	if(!(*Q).front)
		return false;
	(*Q).front->next = NULL;
	return true;
}
/************************************************************************/
/*���*/
bool EnQueue(LinkQueue *Q,QElemType e)
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p)
		return false;
	p->next = NULL;
	p->data = e;
	(*Q).rear->next = p;
	(*Q).rear = p;
	return true;
}
/************************************************************************/
/*����*/
bool DeQueue(LinkQueue *Q,QElemType *e)
{
	QueuePtr p = (*Q).front->next;
	if((*Q).rear == (*Q).front)
		return false;
	*e = p->data;
	if(p==(*Q).rear)
		(*Q).rear = (*Q).front;
	(*Q).front->next = p->next;
	free(p);
	return true;
}
/************************************************************************/
/*�õ���ͷԪ��*/
bool GetTop(LinkQueue Q,QElemType *e)
{
	if(Q.rear==Q.front)
		return false;
	*e = Q.front->next->data;
	return true;
}
/************************************************************************/
/*�󳤶�*/
int LengthQueue(LinkQueue Q)
{
	QueuePtr p = Q.front->next;
	int i = 0;
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}
	return i;
}
/************************************************************************/
/*�п�*/
bool QueueEmpty(LinkQueue Q)
{
	if(Q.rear == Q.front)
		return true;
	return false;
}
/************************************************************************/
/*���*/
bool ClearQueue(LinkQueue *Q)
{
	while((*Q).front->next)
	{
		(*Q).rear = (*Q).front->next;
		free((*Q).front);
		(*Q).front = (*Q).rear;
	}
	return true;
}
/************************************************************************/
/*����*/
bool DestoryQueue(LinkQueue *Q)
{
	while((*Q).front)
	{
		(*Q).rear = (*Q).front->next;
		free((*Q).front);
		(*Q).front = (*Q).rear;
	}
	return true;
}
/************************************************************************/
/*����*/
void VisitQueue(LinkQueue Q)
{
	QueuePtr p = Q.front->next;
	if(Q.rear == Q.front)
		printf("û��Ԫ��\n");
	else
	{
		while(p!=NULL)
		{
			printf("%d\t",p->data);
			p=p->next;
		}
		printf("\n");
	}
}
/**************************************************************************************/
/*����������*/
int main(void)
{
	LinkQueue s;
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
