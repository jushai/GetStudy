#include<stdio.h>
#include<stdlib.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;

typedef struct
{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

bool List_insert_order(SqList *L,ElemType e)
{
	ElemType *newspace; 
	ElemType *q,*p;
	int j,i=0;
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