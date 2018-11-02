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
/*初始化*/
bool InitList(SLinkList *space)
{
	int i = 0;
	for(;i<MAXSIZE-1;i++)
		space[i]->cur = i+1;
	space[MAXSIZE]->cur = 0;
	return true;
}
/****************************************/
/*备用空间*/
int Malloc(SLinkList *space)
{
	int i = space[0]->cur;
	if(space[i]->cur)
		space[0]->cur = space[i]->cur;
	return i;
}
/****************************************/
/*释放空间*/
void Free(SLinkList *space,int k)
{
	space[k]->cur = space[0]->cur;
	space[0]->cur = k;
}
/****************************************/
/*查找*/
int Locate(SLinkList space,ElemType e)
{
	int i = space[0].cur;
	while(i&&space[i].data!=e)
		i = space[i].cur;
	return i;
}