//#include<stdio.h>
//#include<stdlib.h>
//
//typedef int ElemType;
//
//typedef struct
//{
//	ElemType *elem;
//	int length;
//}SqList;
//
//bool Initlist(SqList *L,int n)
//{
//	L->elem = (ElemType *)malloc(n*sizeof(int));
//	if (!L->elem) return false;
//	L->length = n;
//	return true;
//}
//void  josephus(ElemType *p,int n,int m)
//{
//	int i,j=0;
//	int q = n;
//    for(i=0;i<n;i++) 
//		p[i]=i+1; 
//	for(i=0;;i++) 
//	{ 
//		if(i==n) 
//			i=0;
//		if(p[i]!=0) 
//			j++;
//		else 
//			continue; 
//		if(j%m==0)
//		{
//			p[i]=0;
//			q--;
//		}
//		if(q==1) 
//			break;
//	} 
//	for(i=0;i<n;i++) 
//	{
//		if(p[i]!=0) 
//			printf("������µ���ԭ���ĵ�%d��\n",p[i]); 
//	}	
//}
//
//int main(void)
//{
//	SqList ml;
//    int n, m;
//    printf("�������˵�������");
//    scanf("%d", &n);
//    printf("�����뱨��ֵ��");
//    scanf("%d", &m);
//	Initlist(&ml,n);
//	josephus(ml.elem,n,m);
//	system("pause");
//    return 0;
//}