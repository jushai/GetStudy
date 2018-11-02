/***
*DynaLnkQueue.cpp - 动态链式队列，即队列的动态链式存储实现
*
*
*题目：实验3-2 队列的动态链式存储实现
*
*班级：2班
*
*姓名：付子旺
*
*学号：2016011409
*	
****/

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <assert.h>
#include "DynaLnkQueue.h"

/*------------------------------------------------------------
操作目的：	初始化队列
初始条件：	无
操作结果：	构造一个空的队列
函数参数：
		LinkQueue *Q	待初始化的队列
返回值：
		bool			操作是否成功
------------------------------------------------------------*/
bool InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
		return false;
	Q->front->next = NULL;
	return true;
}

/*------------------------------------------------------------
操作目的：	销毁队列
初始条件：	队列Q已存在
操作结果：	销毁队列Q
函数参数：
		LinkQueue *Q	待销毁的队列
返回值：
		无
------------------------------------------------------------*/
void DestroyQueue(LinkQueue *Q)
{
	while(Q->front) 
    { 
		Q->rear = Q->front -> next;     　　　
		free (Q->front);     　　　 
		Q->front = Q->rear;
    } 
}

/*------------------------------------------------------------
操作目的：	判断队列是否为空
初始条件：	队列Q已存在
操作结果：	若Q为空队列，则返回true，否则返回false
函数参数：
		LinkQueue Q		待判断的队列
返回值：
		bool			是否为空
------------------------------------------------------------*/
bool QueueEmpty(LinkQueue Q)
{
	if(Q.front == Q.rear)
		return true;
	return false;
}

/*------------------------------------------------------------
操作目的：	得到队列的长度
初始条件：	队列Q已存在
操作结果：	返回Q中数据元素的个数
函数参数：
		LinkQueue Q		队列Q
返回值：
		int				数据元素的个数
------------------------------------------------------------*/
int QueueLength(LinkQueue Q)
{
	int i;
	QueuePtr p = Q.front->next;
	while(p)
	{
		i++;
		p = p->next;
	}
	return i;
}

/*------------------------------------------------------------
操作目的：	得到队列首元素
初始条件：	队列Q已存在
操作结果：	用e返回队列首元素
函数参数：
		LinkQueue Q		队列Q
		ElemType *e		队列首元素的值
返回值：
		bool			操作是否成功
------------------------------------------------------------*/
bool GetHead(LinkQueue Q, ElemType *e)
{
	QueuePtr p;
	p = Q.front->next;
	*e = p->data;
	return true;
}

/*------------------------------------------------------------
操作目的：	遍历队列
初始条件：	队列Q已存在
操作结果：	依次对Q的每个元素调用函数fp
函数参数：
		LinkQueue Q		队列Q
		void (*fp)()	访问每个数据元素的函数指针
返回值：
		无
------------------------------------------------------------*/
void QueueTraverse(LinkQueue Q, void (*fp)(ElemType))
{
	QueuePtr p = Q.front->next;
	while (p)
	{
		(*fp)(p->data);
		p = p->next;
	}
}

/*------------------------------------------------------------
操作目的：	清空队列
初始条件：	队列Q已存在
操作结果：	将队列清空
函数参数：
		LinkQueue *Q	队列Q
返回值：
		无
------------------------------------------------------------*/
void ClearQueue(LinkQueue *Q)
{
	QueuePtr p = Q->front->next;
	while(p == Q->rear)
	{
		free(p);
		p = p->next;
	}
	Q->front = Q->rear;
}

/*------------------------------------------------------------
操作目的：	在队列末尾插入元素e
初始条件：	队列Q已存在
操作结果：	插入元素e作为队列新的尾结点
函数参数：
		LinkQueue *Q		队列Q
		ElemType e		待插入的数据元素
返回值：
		bool			操作是否成功
------------------------------------------------------------*/
bool EnQueue(LinkQueue *Q, ElemType e)
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p)
		return false;
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return true;
}

/*------------------------------------------------------------
操作目的：	删除链式队列的头结点
初始条件：	队列Q已存在
操作结果：	删除链式队列的头结点
函数参数：
		LinkQueue *Q		队列Q
		ElemType *e		待插入的数据元素
返回值：
		bool			操作是否成功
------------------------------------------------------------*/
bool DeQueue(LinkQueue *Q, ElemType *e)
{
	QueuePtr p;
	if(Q->front == Q->rear)
		return false;
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if(Q->rear == p)
		Q->rear = Q->front;
	return true;
}