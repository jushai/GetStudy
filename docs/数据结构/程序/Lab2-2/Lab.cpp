#include <stdio.h>
#include<stdlib.h>
#include "DynaLnkList.h"

int main()
{
	// TODO: Place your test code here
	LinkList ml = NULL;
	InitList(&ml);
	ListInsert(ml,1,5);
	ListInsert(ml,1,3);
	ListInsert(ml,1,2);
	ListInsert(ml,1,1);
	ListInsert(ml,1,4);
	ListTraverse(ml,visit);
	inverse(ml);
	ListTraverse(ml,visit);
 /*   sort_list(ml); 
	ListTraverse(ml,visit);*/
	system("pause");
	return 0;
}