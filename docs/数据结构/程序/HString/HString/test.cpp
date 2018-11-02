#include<stdio.h>
#include<stdlib.h>
typedef struct { 
      char *ch;     // 若非空则按串长分配存储区， 否则 ch 为 NULL 
      int length;    //串长度 
} HString; 
//初始化字符串
Status InitString(HString *T) 
{
    //指针指向NULL,长度为0即可
    //p.s.申请内存空间的过程在赋值中完成
    T->ch = NULL;
    T->length = 0;
    return OK;
}
//字符串赋值
Status StrAssign(HString *T, char *p)
{
    //1.判断T是否已有内容,有则释放
    //2.判断赋值的内容是否为空,为空则不赋值
    //3.根据长度向内存申请空间,遍历赋值给T,长度等于字符串长度
    //p.s.在这里赋值不赋\0,在打印时通过长度来判断字符串结尾
    int i,j;
	char *c = p;
    if (T->ch)
        free(T->ch);
	for (i = 0,c = p;*c;++i,++c)//求p的长度
    if (!i)
    {
        T->ch = NULL;
        T->length = 0;
        return ERROR;
    }
    else
    {
        T->ch = (char *)malloc(i * sizeof(char));
        if(!T->ch)
            exit(OVERFLOW);
        for (j = 0; j < len; ++j)
            T->ch[j] = p[j];
        T->length = len;
        return OK;
    }
}
//字符串长度
Status StrLength(HString T) 
{
    return T.length;
}
//字符串判空
Status StrEmpty(HString T) 
{
    if (T.length == 0)
        return TRUE;
    else
        return FALSE;
}
//字符串联接
Status Concat(HString *T, HString S1, HString S2)
{
    //1.申请长度为S1和S2之和的字符串空间
    //2.先将S1的元素逐个赋值到T中
    //3.再将S2的元素逐个赋值到T中
    int i;
    if (T->ch)
        free(T->ch);
    T->ch = (char *)malloc((S1.length + S2.length) * sizeof(char));
    if (!T->ch)
        exit(OVERFLOW);
    for (i = 0; i < S1.length; ++i)
        T->ch[i] = S1.ch[i];
    for (i = 0; i < S2.length; ++i)
        T->ch[i + S1.length] = S2.ch[i];
    T->length = S1.length + S2.length;
	/*T->length = S1.length + S2.length;
	T.ch[0…S1.length-1] = S1.ch[0…S1.length-1];    
    T.ch[S1.length…T.length-1] = S2.ch[0…S2.length-1]; */  
    return OK;
}
//删除字符串中某个位置固定长度的子串
Status StrDelete(HString *T, int pos, int len) 
{
    //pos是字符串中的位置,删除包括pos的len长度
    int i;
    if (pos >= T->length)
        return ERROR;
    else if(pos + len > T->length)
        len = T->length - pos + 1;
    for (i = pos - 1; i < T->length - len; ++i)
        T->ch[i] = T->ch[i + len];
    T->length -= len;
    T->ch = (char *)realloc(T->ch, T->length * sizeof(char));
    if (!T->ch)
        exit(OVERFLOW);
    return OK;
}
//插入操作
Status StrInsert (HString &S,  int pos,  HString T) 
{
   //1、为串 S 重新分配大小等于串 S 和串 T 长度之和 的存储空间； 
   // 2、进行串值的复制。
   if (pos<1 || pos > S.length +1)  return ERROR;  // 插入位置不合法 
   if (T.length)   // T 非空，则为 S 重新分配空间并插入 T 
   {  if (!(S.ch=(char *) realloc(S.ch,(S.length+T.length)*sizeof(char)))) 
          exit(OVERFLOW);
      for (i=S.length-1; i>=pos-1; --i)   //为插入 T 而腾出位置
          S.ch[i+T.length]=S.ch[i];
      S.ch[pos-1…pos+T.length-2]=T.ch[0…T.length-1];  //插入 T 
      S.length+=T.length;
   }
   return OK;
}
//在字符串S中索引位置pos之后的子串t
Status Index(HString S, HString T, int pos)
{
    //同定长顺序存储表示法
    //p.s.传入的pos是字符串的位置,从1开始
    //p.s.初始状态下T为非空串
    if (StrEmpty(T))
        return ERROR;
    int i = pos - 1, j = 0;
    while(i < S.length && j < T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= T.length)
        return i - j + 1;
    else
        return 0;
}
Status Replace(HString *T, HString S1, HString S2) //将字符串T中等于S1的子串替换成为S2
{
    //循环索引子串S1在字符串T中的位置(每次的位置从上一次位置后开始查找)
    //从查找到的位置-1开始替换
    //p.s.初始状态下S1为非空串
    int pos = 0;
    if (StrEmpty(S1))
        return ERROR;
    //当pos存在时循环,当全部索引完毕后pos为0
    //将索引到的该位置对应的子串删除后再插入新的子串
    do
    {
        pos = Index(*T, S1, pos);
        if (pos)
        {
            StrDelete(T, pos, StrLength(S1));
            StrInsert(T, pos, S2);
        }
    }
    while(pos);
    return OK;
}
Status SubString(HString *Sub, HString S, int pos, int len)
{
    int i;
    if (pos < 1 || len > S.length || len < 0 || len > S.length - pos + 1)
        exit(OVERFLOW);
    if (Sub->ch)
        free(Sub->ch);
    //如果查询的长度为0,则子串置空
    if (len == 0)
    {
        Sub->ch = NULL;
        Sub->length = 0;
    }
    else
    {
        Sub->ch = (char *)malloc(len * sizeof(char));
        for (i = 0; i < len; ++i)
            Sub->ch[i] = S.ch[pos + i - 1];
		/*Sub.ch = (char *)malloc(len*sizeof(char)); 
         Sub.ch[0…len-1] = S[pos-1…pos+len-2]; 
         Sub.length = len;  */
        Sub->length = len;
    }
    return OK;
}
// StrCompare
int  StrCompare(HString S, HString T) 
{
	for (i=0;  i<S.length && i<T.length;  ++i) 
		if (S.ch[i]!=T.ch[i])  return  S.ch[i]-T.ch[i];    
	return S.length-T.length; 
} 
//串复制 Strcopy 算法
status Strcopy(HString  &T, HString  S) 
{
	if (T.ch)  free(T.ch); 
	n=S.length; 
    if (n!=0) 
      { T.ch=(char *)malloc(n*sizeof(char));  
	    T.ch[0..n-1]=S.ch[0..n-1]; 
        T. length=S.length; } 
	return OK; 
} 
//清空串 ClearString 算法
status  ClearString(HString  &S) 
{
	//将串 S 清为空串 
    if (S.ch) { free(S.ch);    S.ch=NULL; }   
    S.length=0; 
	return OK;
} 
