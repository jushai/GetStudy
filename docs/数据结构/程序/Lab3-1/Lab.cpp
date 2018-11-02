#include <stdio.h>
#include <stdlib.h>
#include "DynaSeqStack.h"

int main()
{
	// TODO: Place your test code here
	SqStack p;
	int a;
	InitStack(&p);
	a = StackLength(p);
	printf("%d\n",a);
	Push(&p,1);
	Push(&p,2);
	Push(&p,3);
	Push(&p,4);
	Push(&p,5);
	StackTraverse(p,visit);
	a = StackLength(p);
	printf("%d\n",a);
	Pop(&p,&a);
	StackTraverse(p,visit);
	system("pause");
	return 0;
}