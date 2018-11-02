/***
*DynaLnkList.cpp - ��̬������˳���Ķ�̬��ʽ�洢ʵ��
*
*
*��Ŀ��ʵ��2-2 ���Ա�Ķ�̬��ʽ�洢ʵ��
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
#include "DynaLnkList.h"

/*------------------------------------------------------------
����Ŀ�ģ�	��ʼ������
��ʼ������	��
���������	����һ���յ����Ա�
����������
		LinkList *L	����ʼ�������Ա�
����ֵ��
		bool		�����Ƿ�ɹ�
------------------------------------------------------------*/
bool InitList(LinkList *L)
{
	(*L) = (LinkList)malloc(sizeof(LNode));
	if (!(*L))
		return false;
	(*L) ->next = NULL;	
	return true;
}

/*------------------------------------------------------------
����Ŀ�ģ�	��������
��ʼ������	���Ա�L�Ѵ���
���������	�������Ա�L
����������
		LinkList *L	�����ٵ����Ա�
����ֵ��
		��
------------------------------------------------------------*/
void DestroyList(LinkList *L)
{
	LinkList p;
	p = (*L) ->next;
	while (p->next)
		free(p);
	free(*L);
}

/*------------------------------------------------------------
����Ŀ�ģ�	�ж������Ƿ�Ϊ��
��ʼ������	���Ա�L�Ѵ���
���������	��LΪ�ձ��򷵻�true�����򷵻�false
����������
		LinkList L	���жϵ����Ա�
����ֵ��
		bool		�Ƿ�Ϊ��
------------------------------------------------------------*/
bool ListEmpty(LinkList L)
{
	LinkList p;
	p = L->next;
	if (!p)
		return false;
	return true;
}

/*------------------------------------------------------------
����Ŀ�ģ�	�õ�����ĳ���
��ʼ������	���Ա�L�Ѵ���
���������	����L������Ԫ�صĸ���
����������
		LinkList L	���Ա�L
����ֵ��
		int			����Ԫ�صĸ���
------------------------------------------------------------*/
int ListLength(LinkList L)
{
	int len=0;  
	LinkList p=L->next;  
    while(p!=NULL)  
    {  
        p=p->next;  
        len++;  
    }  
    return len;  
}

/*------------------------------------------------------------
����Ŀ�ģ�	�õ�����ĵ�i��Ԫ��
��ʼ������	���Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)
���������	��e����L�е�i������Ԫ�ص�ֵ
����������
		LinkList L	���Ա�L
		int i		����Ԫ�ص�λ��
		ElemType *e	��i������Ԫ�ص�ֵ
����ֵ��
		bool		�����Ƿ�ɹ�
------------------------------------------------------------*/
bool GetElem(LinkList L, int i, ElemType *e)
{
	LinkList p;
	int j =1;
	p = L->next;
	while (p&&j<i)
	{
		p = p->next;
		j++;
	}
	if (!p||j>i)
		return false;
	*e = p->data;
	return true;
}

/*------------------------------------------------------------
����Ŀ�ģ�	�õ�����ָ��Ԫ�ص�λ��
��ʼ������	���Ա�L�Ѵ���
���������	����L�е�һ����e�����ϵcompare()������Ԫ�ص�λ��
			��������Ԫ�ز������򷵻�0��
����������
		LinkList L	���Ա�L
		ElemType e	����Ԫ��e
		int (*fp)()	���ڱȽ���ȵĺ���ָ��
����ֵ��
		int			��e�����ϵcompare()������Ԫ�ص�λ��
------------------------------------------------------------*/
int LocateElem(LinkList L, ElemType e, int (*fp)(ElemType, ElemType))
{
	return 0;
}

/*------------------------------------------------------------
����Ŀ�ģ�	�õ�����ָ��Ԫ�ص�ǰ��
��ʼ������	���Ա�L�Ѵ���
���������	��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e����
			����ǰ�����������ʧ�ܣ�pre_e�޶���
����������
		LinkList L		���Ա�L
		ElemType cur_e	����Ԫ��cur_e
		ElemType *pre_e	ǰ������Ԫ��
����ֵ��
		bool			�����Ƿ�ɹ�
------------------------------------------------------------*/
bool PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	return true;
}

/*------------------------------------------------------------
����Ŀ�ģ�	�õ�����ָ��Ԫ�صĺ��
��ʼ������	���Ա�L�Ѵ���
���������	��cur_e��L������Ԫ�أ��Ҳ������һ��������nxt_e��
			�����ĺ�̣��������ʧ�ܣ�nxt_e�޶���
����������
		LinkList L		���Ա�L
		ElemType cur_e	����Ԫ��cur_e
		ElemType *nxt_e	�������Ԫ��
����ֵ��
		bool			�����Ƿ�ɹ�
------------------------------------------------------------*/
bool NextElem(LinkList L, ElemType cur_e, ElemType *nxt_e)
{
	return true;
}

/*------------------------------------------------------------
����Ŀ�ģ�	��������
��ʼ������	���Ա�L�Ѵ���
���������	���ζ�L��ÿ��Ԫ�ص��ú���fp
����������
		LinkList L		���Ա�L
		void (*fp)()	����ÿ������Ԫ�صĺ���ָ��
����ֵ��
		��
------------------------------------------------------------*/
void ListTraverse(LinkList L, void (*fp)(ElemType))
{
	LinkList p;
	p = L->next;
	while(p)
	{
		(*fp)(p->data);
		p = p->next;
	}
}

/*------------------------------------------------------------
����Ŀ�ģ�	�������
��ʼ������	���Ա�L�Ѵ���
���������	��L��Ϊ�ձ�
����������
		LinkList L	���Ա�L
����ֵ��
		��
------------------------------------------------------------*/
void ClearList(LinkList L)
{
	LinkList p;
	while(p = L->next)
		free(p);
}

/*------------------------------------------------------------
����Ŀ�ģ�	�������ָ��λ�ò����㣬����λ��i��ʾ�ڵ�i��
			Ԫ��֮ǰ����
��ʼ������	���Ա�L�Ѵ��ڣ�1<=i<=ListLength(L) + 1
���������	��L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
����������
		LinkList L	���Ա�L
		int i		����λ��
		ElemType e	�����������Ԫ��
����ֵ��
		bool		�����Ƿ�ɹ�
------------------------------------------------------------*/
bool ListInsert(LinkList L, int i, ElemType e)
{
	LinkList p,s;
	int j = 0;
	p = L;
	while (p&&j<i-1)
	{
		p = p->next;
		j++;
	}
	if (!p || j>i-1)
		return false;
	s =(LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

/*------------------------------------------------------------
����Ŀ�ģ�	ɾ������ĵ�i�����
��ʼ������	���Ա�L�Ѵ����ҷǿգ�1<=i<=ListLength(L)
���������	ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
����������
		LinkList L	���Ա�L
		int i		ɾ��λ��
		ElemType *e	��ɾ��������Ԫ��ֵ
����ֵ��
		bool		�����Ƿ�ɹ�
------------------------------------------------------------*/
bool ListDelete(LinkList L, int i, ElemType *e)
{
	LinkList p,q;
	int j = 0;
	p =L;
	while (p&&j<i-1)
	{
		p = p->next;
		j++;
	}
	if (!p||j>i-1)
		return false;
	q=p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return true;
}
//β�巨����������  (����)
void CreatList_L(LinkList L,int n)
{
	int i;ElemType temp;
	LinkList p=NULL,q=L;
	for(i=1;i<=n;i++)
	{
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",p->data);
		p->next=NULL;
		q->next=p;
		q=p;
	}
}
//�����������   
bool inverse(LinkList L )
{   
	LinkList p;
	p = L->next->next;//��pָ�����Ա��е�2��Ԫ��a2 
	if(L->next==NULL) 
		return false;  
    L->next->next=NULL;//�����Ա��е�1��Ԫ��a1��nextΪ��  
    while(p)  
    {  
         LNode* q=p->next;  
        //��p���뵽ͷ���֮��  
        p->next=L->next;  
        L->next=p;  
        p=q;//����������һ��Ԫ��  
    } 
	return true;
}
//�����������   
void sort_list(LinkList L)  
{  
    int i,j,t;  
    LinkList p = L->next;      
	for(i=0;i<ListLength(L)-1;i++)  
    {
		p = L->next;
        for(j=0;j<ListLength(L)-i-1;j++)  
        {  
            if(p->data > p->next->data)   //ð�ݷ�������С��ð�ݵ�����������У�   
            {  
                t=p->data;  
                p->data = p->next->data ;  
                p->next->data = t;  
            }  
            p=p->next;      
        }
    }  
}  
//������������кϲ�
void MergeList_L(LinkList La,LinkList Lb,LinkList Lc)
{
	LinkList pa,pb,pc;
	pa = La->next;pb = Lb->next;
	Lc = pc = La;
	while(pa&&pb)
	{
		if (pa->data<=pb->data)
		{
			pc->next = pa;
			pc =pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc =pb;
			pb = pb->next;
		}
	}
	pc->next = pa?pa:pb;
	free(Lb);
}


