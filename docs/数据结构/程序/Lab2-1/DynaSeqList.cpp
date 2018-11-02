/***
*DynaSeqList.cpp - ��̬˳�����˳���Ķ�̬����ʵ��
*
*
*��Ŀ��ʵ��2-1 ���Ա�Ķ�̬˳��洢ʵ��
*
*�༶��2��
*
*������������
*
*ѧ�ţ�2016011409
*	
****/

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <assert.h>
#include "DynaSeqList.h"

const int LIST_INIT_SIZE = 100;	// ���ʼ�������󳤶�
const int LISTINCREMENT  = 10;	// �����ڴ������

/*------------------------------------------------------------
����Ŀ�ģ�	��ʼ��˳���
��ʼ������	��
���������	����һ���յ����Ա�
����������
		SqList *L	����ʼ�������Ա�
����ֵ��
		bool		�����Ƿ�ɹ�
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
����Ŀ�ģ�	����˳���
��ʼ������	���Ա�L�Ѵ���
���������	�������Ա�L
����������
		SqList *L	�����ٵ����Ա�
����ֵ��
		��
------------------------------------------------------------*/
void DestroyList(SqList *L)
{
	free(L->elem);
	L->length = 0;
	L->listsize = 0;
}

/*------------------------------------------------------------
����Ŀ�ģ�	�ж�˳����Ƿ�Ϊ��
��ʼ������	���Ա�L�Ѵ���
���������	��LΪ�ձ��򷵻�true�����򷵻�false
����������
		SqList L	���жϵ����Ա�
����ֵ��
		bool		�Ƿ�Ϊ��
------------------------------------------------------------*/
bool ListEmpty(SqList L)
{
	if (L.length==0)
		return true;
	else
		return false;
}

/*------------------------------------------------------------
����Ŀ�ģ�	�õ�˳���ĳ���
��ʼ������	���Ա�L�Ѵ���
���������	����L������Ԫ�صĸ���
����������
		SqList L	���Ա�L
����ֵ��
		int			����Ԫ�صĸ���
------------------------------------------------------------*/
int ListLength(SqList L)
{
	return L.length;
}

/*------------------------------------------------------------
����Ŀ�ģ�	�õ�˳���ĵ�i��Ԫ��
��ʼ������	���Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)
���������	��e����L�е�i������Ԫ�ص�ֵ
����������
		SqList L	���Ա�L
		int i		����Ԫ�ص�λ��
		ElemType *e	��i������Ԫ�ص�ֵ
����ֵ��
		bool		�����Ƿ�ɹ�
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
����Ŀ�ģ�	�õ�˳���ָ��Ԫ�ص�λ��
��ʼ������	���Ա�L�Ѵ���
���������	����L�е�һ����e�����ϵcompare()������Ԫ�ص�λ��
			��������Ԫ�ز������򷵻�0��
����������
		SqList L	���Ա�L
		ElemType e	����Ԫ��e
		int (*fp)()	���ڱȽ���ȵĺ���ָ��
����ֵ��
		int			��e�����ϵcompare()������Ԫ�ص�λ��
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
����Ŀ�ģ�	�õ�˳���ָ��Ԫ�ص�ǰ��
��ʼ������	���Ա�L�Ѵ���
���������	��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e����
			����ǰ�����������ʧ�ܣ�pre_e�޶���
����������
		SqList L		���Ա�L
		ElemType cur_e	����Ԫ��cur_e
		ElemType *pre_e	ǰ������Ԫ��
����ֵ��
		bool			�����Ƿ�ɹ�
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
����Ŀ�ģ�	�õ�˳���ָ��Ԫ�صĺ��
��ʼ������	���Ա�L�Ѵ���
���������	��cur_e��L������Ԫ�أ��Ҳ������һ��������nxt_e��
			�����ĺ�̣��������ʧ�ܣ�nxt_e�޶���
����������
		SqList L		���Ա�L
		ElemType cur_e	����Ԫ��cur_e
		ElemType *nxt_e	�������Ԫ��
����ֵ��
		bool				�����Ƿ�ɹ�
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
����Ŀ�ģ�	����˳���
��ʼ������	���Ա�L�Ѵ���
���������	���ζ�L��ÿ��Ԫ�ص��ú���fp
����������
		SqList L		���Ա�L
		void (*fp)()	����ÿ������Ԫ�صĺ���ָ��
����ֵ��
		��
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
����Ŀ�ģ�	���˳���
��ʼ������	���Ա�L�Ѵ���
���������	��L��Ϊ�ձ�
����������
		SqList *L	���Ա�L
����ֵ��
		��
------------------------------------------------------------*/
void ClearList(SqList *L)
{
	L->length = 0;
}

/*------------------------------------------------------------
����Ŀ�ģ�	��˳����ָ��λ�ò����㣬����λ��i��ʾ�ڵ�i��
			Ԫ��֮ǰ����
��ʼ������	���Ա�L�Ѵ��ڣ�1<=i<=ListLength(L) + 1
���������	��L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
����������
		SqList *L	���Ա�L
		int i		����λ��
		ElemType e	�����������Ԫ��
����ֵ��
		bool		�����Ƿ�ɹ�
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
����Ŀ�ģ�	ɾ��˳���ĵ�i�����
��ʼ������	���Ա�L�Ѵ����ҷǿգ�1<=i<=ListLength(L)
���������	ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
����������
		SqList *L	���Ա�L
		int i		ɾ��λ��
		ElemType *e	��ɾ��������Ԫ��ֵ
����ֵ��
		bool		�����Ƿ�ɹ�
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