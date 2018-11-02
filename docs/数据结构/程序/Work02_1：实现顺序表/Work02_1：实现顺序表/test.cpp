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
/*��ʼ��*/
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
/*����*/
bool InsertList(SqList *L,int i,ElemType e)
{
	//1.�жϲ���λ��ʱ����
	//2.Ųλ��
	//3.���ȥ
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
	for(j = L->length-1;j>=i-1;j--)//һ���ƶ���n-i+1��Ԫ��
	{
		L->elem[j+1] = L->elem[j];
	}
	L->elem[j] = e;
	++L->length;
	return true;
}
/***********************************************************/
/*ɾ��*/
bool DeleteList(SqList *L,int i,ElemType *e)
{
	//1.�ж��ܲ���ɾ
	//2.Ųλ�ø���
	//3.���ȼ�һ
	if(i<1||i>L->length)
		return false;
	*e = L->elem[i-1];
	int j = L->length-1;
	for(;i<j;i++)//һ��ҪŲ��n-i��Ԫ�ص�λ��
	{
		L->elem[i-1] = L->elem[i];
	}
	--L->length;
	return true;
}