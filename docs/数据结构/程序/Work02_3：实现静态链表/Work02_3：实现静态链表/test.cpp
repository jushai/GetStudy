#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 1000
typedef int ElemType;
typedef struct
{
	ElemType data;
	int cur;
}commpent,SLinkList[MAXSIZE];

//(A-B)U(B-A)
/****************************************/
/*��ʼ��*/
bool InitList(SLinkList *space)
{
	int i = 0;
	for(;i<MAXSIZE-1;i++)
		space[i]->cur = i+1;
	space[MAXSIZE]->cur = 0;
	return true;
}
/****************************************/
/*���ÿռ�*/
int Malloc(SLinkList *space)
{
	int i = space[0]->cur;
	if(space[i]->cur)
		space[0]->cur = space[i]->cur;
	return i;
}
/****************************************/
/*�ͷſռ�*/
void Free(SLinkList *space,int k)
{
	space[k]->cur = space[0]->cur;
	space[0]->cur = k;
}
/****************************************/
/*����*/
int Locate(SLinkList space,ElemType e)
{
	int i = space[0].cur;
	while(i&&space[i].data!=e)
		i = space[i].cur;
	return i;
}