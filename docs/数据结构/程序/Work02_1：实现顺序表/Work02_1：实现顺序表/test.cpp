#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct
{
	ElemType *elem;
	int length;
	int listsize;
}SqList;
/***********************************************************/
/*初始化*/
bool InitList(SqList *L)
{
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L->elem)
		return false;
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return true;
}
/***********************************************************/
/*插入*/
bool InsertList(SqList *L,int i,ElemType e)
{
	//1.判断插入位置时候有
	//2.挪位置
	//3.插进去
	ElemType *newbase;
	int j;
	if(L->length>=L->listsize)
	{
		newbase = (ElemType *)realloc(L->elem,(LIST_INIT_SIZE+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)
			return false;
		L->elem = newbase;
		L->listsize +=LISTINCREMENT;
	}
	for(j = L->length-1;j>=i-1;j--)//一共移动了n-i+1个元素
	{
		L->elem[j+1] = L->elem[j];
	}
	L->elem[j] = e;
	++L->length;
	return true;
}
/***********************************************************/
/*删除*/
bool DeleteList(SqList *L,int i,ElemType *e)
{
	//1.判断能不能删
	//2.挪位置覆盖
	//3.长度简一
	if(i<1||i>L->length)
		return false;
	*e = L->elem[i-1];
	int j = L->length-1;
	for(;i<j;i++)//一共要挪动n-i个元素的位置
	{
		L->elem[i-1] = L->elem[i];
	}
	--L->length;
	return true;
}