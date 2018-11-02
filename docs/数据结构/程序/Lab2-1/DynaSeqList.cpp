/***
*DynaSeqList.cpp - 动态顺序表，即顺序表的动态数组实现
*
*
*题目：实验2-1 线性表的动态顺序存储实现
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
#include "DynaSeqList.h"

const int LIST_INIT_SIZE = 100;	// 表初始分配的最大长度
const int LISTINCREMENT  = 10;	// 分配内存的增量

/*------------------------------------------------------------
操作目的：	初始化顺序表
初始条件：	无
操作结果：	构造一个空的线性表
函数参数：
		SqList *L	待初始化的线性表
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool InitList(SqList *L)
{
	L -> elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (NULL == L->elem)
		return  false;
	L -> length = 0;
	L -> listsize = LIST_INIT_SIZE;
	return true;
}

/*------------------------------------------------------------
操作目的：	销毁顺序表
初始条件：	线性表L已存在
操作结果：	销毁线性表L
函数参数：
		SqList *L	待销毁的线性表
返回值：
		无
------------------------------------------------------------*/
void DestroyList(SqList *L)
{
	free(L->elem);
	L->length = 0;
	L->listsize = 0;
}

/*------------------------------------------------------------
操作目的：	判断顺序表是否为空
初始条件：	线性表L已存在
操作结果：	若L为空表，则返回true，否则返回false
函数参数：
		SqList L	待判断的线性表
返回值：
		bool		是否为空
------------------------------------------------------------*/
bool ListEmpty(SqList L)
{
	if (L.length==0)
		return true;
	else
		return false;
}

/*------------------------------------------------------------
操作目的：	得到顺序表的长度
初始条件：	线性表L已存在
操作结果：	返回L中数据元素的个数
函数参数：
		SqList L	线性表L
返回值：
		int			数据元素的个数
------------------------------------------------------------*/
int ListLength(SqList L)
{
	return L.length;
}

/*------------------------------------------------------------
操作目的：	得到顺序表的第i个元素
初始条件：	线性表L已存在，1<=i<=ListLength(L)
操作结果：	用e返回L中第i个数据元素的值
函数参数：
		SqList L	线性表L
		int i		数据元素的位置
		ElemType *e	第i个数据元素的值
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool GetElem(SqList L, int i, ElemType *e)
{
	if (i<=L.length && i>=1)
	{
		*e = L.elem[i-1];
		return true;
	}
	else
	{
		return false;
	}
}

/*------------------------------------------------------------
操作目的：	得到顺序表指定元素的位置
初始条件：	线性表L已存在
操作结果：	返回L中第一个与e满足关系compare()的数据元素的位序。
			若这样的元素不存在则返回0。
函数参数：
		SqList L	线性表L
		ElemType e	数据元素e
		int (*fp)()	用于比较相等的函数指针
返回值：
		int			与e满足关系compare()的数据元素的位序
------------------------------------------------------------*/   
int LocateElem(SqList L, ElemType e, int (*fp)(ElemType, ElemType))
{
	ElemType a;
	ElemType i;
	for( i = 0;i<L.length;i++)
	{
		if (e==L.elem[i])
			break;
	}
	a = i;
	return (*fp)(a,0);
}

/*------------------------------------------------------------
操作目的：	得到顺序表指定元素的前驱
初始条件：	线性表L已存在
操作结果：	若cur_e是L的数据元素，且不是第一个，则用pre_e返回
			它的前驱，否则操作失败，pre_e无定义
函数参数：
		SqList L		线性表L
		ElemType cur_e	数据元素cur_e
		ElemType *pre_e	前驱数据元素
返回值：
		bool			操作是否成功
------------------------------------------------------------*/
bool PriorElem(SqList L, ElemType cur_e, ElemType *pre_e)
{
	int i;
    for (i = 0; i < L.length; i++)
    {
        if (cur_e == L.elem[i])
        {
            if (i != 0)
            {
                *pre_e = L.elem[i - 1];
				return true;
            }
            else
            {
                return false;
            }
        }
    }
    if (i >= L.length)
    {
        return false;
    }
}

/*------------------------------------------------------------
操作目的：	得到顺序表指定元素的后继
初始条件：	线性表L已存在
操作结果：	若cur_e是L的数据元素，且不是最后一个，则用nxt_e返
			回它的后继，否则操作失败，nxt_e无定义
函数参数：
		SqList L		线性表L
		ElemType cur_e	数据元素cur_e
		ElemType *nxt_e	后继数据元素
返回值：
		bool				操作是否成功
------------------------------------------------------------*/
bool NextElem(SqList L, ElemType cur_e, ElemType *nxt_e)
{
	int i;
    for (i = 0; i < L.length; i++)
    {
        if (cur_e == L.elem[i])
        {
            if (i < L.length - 1)
            {
                *nxt_e = L.elem[i + 1];
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    if (i >= L.length)
    {
        return false;
    }
}

/*------------------------------------------------------------
操作目的：	遍历顺序表
初始条件：	线性表L已存在
操作结果：	依次对L的每个元素调用函数fp
函数参数：
		SqList L		线性表L
		void (*fp)()	访问每个数据元素的函数指针
返回值：
		无
------------------------------------------------------------*/
void ListTraverse(SqList L, void (*fp)(ElemType))
{
	int i;
	for (i=0;i<L.length;i++)
	{
		(*fp)(L.elem[i]);
	}
}

/*------------------------------------------------------------
操作目的：	清空顺序表
初始条件：	线性表L已存在
操作结果：	将L置为空表
函数参数：
		SqList *L	线性表L
返回值：
		无
------------------------------------------------------------*/
void ClearList(SqList *L)
{
	L->length = 0;
}

/*------------------------------------------------------------
操作目的：	在顺序表的指定位置插入结点，插入位置i表示在第i个
			元素之前插入
初始条件：	线性表L已存在，1<=i<=ListLength(L) + 1
操作结果：	在L中第i个位置之前插入新的数据元素e，L的长度加1
函数参数：
		SqList *L	线性表L
		int i		插入位置
		ElemType e	待插入的数据元素
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool ListInsert(SqList *L, int i, ElemType e)
{
	ElemType *newbase;
	ElemType *q,*p;
	if (i <1 || i> L->length+1)
		return false;
	if (L->length >= L->listsize)
	{
		newbase = (ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
		if (NULL == newbase)
			return  false;
		L ->elem = newbase;
		L->listsize += LISTINCREMENT;
	}
	q = &(L->elem[i-1]);
	for (p = &(L->elem[L->length - 1]);p>=q;--p)
		*(p+1)=*p;
	*q = e;
	++ L->length;
	return true;
}

/*------------------------------------------------------------
操作目的：	删除顺序表的第i个结点
初始条件：	线性表L已存在且非空，1<=i<=ListLength(L)
操作结果：	删除L的第i个数据元素，并用e返回其值，L的长度减1
函数参数：
		SqList *L	线性表L
		int i		删除位置
		ElemType *e	被删除的数据元素值
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool ListDelete(SqList *L, int i, ElemType *e)
{
	 ElemType *p,*q;
	if (i <1 || i> L->length)
		return false;
	p = &(L->elem[i-1]);
	*e = *p;
	q = L->elem + L->length - 1;
	for (++p;p <= q; ++p)
		*(p-1)=*p;
	--L->length;
	return true;
}




bool List_insert_order(SqList *L,ElemType e)
{
	ElemType *newspace;
	ElemType *q,*p;
	int j,i = 0;
	if (L->length >= L->listsize)
	{
		newspace = (ElemType *)realloc(L->elem,(L->listsize +LISTINCREMENT)*sizeof(ElemType));
		if (!newspace)
			return false;
		L->elem = newspace;
		L->listsize = L->listsize +LISTINCREMENT;
	}
	for (j =0;j<L->length;j++)
	{
		if (e <= L->elem[j])
		{	
			i = j+1;
			break;
		}
	}
	if (i==0)
		i = j;
	q = &(L->elem[i-1]);
	for (p = &(L->elem[L->length - 1]);p>=q;--p)
		*(p+1)=*p;
	*q = e;
	++ L->length;
	return true;
}