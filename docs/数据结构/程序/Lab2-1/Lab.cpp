#include <stdio.h>
#include<stdlib.h>
#include "DynaSeqList.h"

int main()
{
	// TODO: Place your test code here
	SqList ml;
	ElemType p;
	int b;
	if(InitList(&ml)==true)
		printf("True!\n");
	else
		printf("False!\n");
	printf("长度为：%d\n",ListLength(ml));
	ListInsert(&ml, 1,9);
	ListInsert(&ml, 1,6);
	ListInsert(&ml, 1,3);
	ListTraverse(ml, visit);
	printf("长度为：%d\n",ListLength(ml));
	if (ListEmpty(ml) == true)
		printf("True!\n");
	else
		printf("False!\n");
	GetElem(ml,2,&p);
	printf("%d\n",p);
	b = LocateElem(ml,p, compare);
	printf("%d\n",b);
	PriorElem(ml,p,&b);
	printf("%d\n",b);
	NextElem(ml,p,&b);
	printf("%d\n",b);
	ListInsert(&ml,4,11);
	ListTraverse(ml, visit);
	ListDelete(&ml,4,&b);
	printf("%d\n",b);
	ListTraverse(ml, visit);
	system("pause");
	return 0;
}