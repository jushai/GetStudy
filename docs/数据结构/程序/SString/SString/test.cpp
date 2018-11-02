#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSTRLEN 255
typedef unsigned char sstring[MAXSTRLEN+1];
/* 字符串赋值,当赋值字符串长度超过被赋值字符串时候截断,未超过时先将长度存入T[0],再逐位赋值 */
Status StrAssign(sstring T, char *chars)
{
    int i;
    if (strlen(chars) > MAXSTRLEN)
    {
        for (i = 1; i <= MAXSTRLEN; ++i)
            T[i] = chars[i-1];
        T[0] = MAXSTRLEN;
    }
    else
    {
        T[0] = strlen(chars); //p.s.此时T[0]存入的是int类型的数据,打印%s时无法显示
        for (i = 1; i <= T[0]; ++i)
            T[i] = chars[i-1];
        return OK;
    }
}
/* 字符串拷贝,逐个字符拷贝(仅拷贝长度范围内的) */
Status StrCopy(sstring T, sstring S)
{
    int i;
    //p.s.此处要拷贝长度+1,将S1的\0同时拷贝进去,否则T中没有\0
    for (i = 1; i <= S[0]; ++i)
        T[i] = S[i];
    T[0] = S[0];
    return OK;
}
/* 字符串判空,当S[0]==0时为空 */
Status StrEmpty(sstring S)
{
    if (S[0] == 0)
    {
        printf("String is Empty\n");
        return TRUE;
    }
    else
    {
        printf("String is not Empty\n");
        return FALSE;
    }
}
/* 返回子串长度 */
Status StrLength (sstring S)
{
    return S[0];
}
/* 打印字符串 */
Status StrPrint(sstring T)
{
    int i;
    for (i = 1; i <= T[0]; ++i)
    {
        printf("%c", T[i]);
    }
    printf("\n");
    return OK;
}
/* 清空字符串 */
Status ClearString(sstring S)
{
    S[0] = 0;
    return OK;
}
/* 字符串联接,通过T来存储结果,S2连接而成的新串,若未截断则返回TRUE,截断返回FAlSE,注意字符串数组越界问题 */
Status Concat(sstring T, sstring S1, sstring S2)
{
    int i;
    if (S1[0] + S2[0] <= MAXSTRLEN)
    {
        for (i = 1; i <= S1[0]; ++i)
            T[i] = S1[i];
        for (i = 1; i <= S2[0]; ++i)
            T[i + S1[0]] = S2[i];
        T[0] = S1[0] + S2[0];
        return TRUE;
    }
    else //先存完S1中的,再存S2中的内容,条件是不能越界
    {
        for (i = 1; i <= S1[0] && i <= MAXSTRLEN - 1; ++i)
            T[i] = S1[i];
        for (i = 1; i <= MAXSTRLEN - S1[0]; ++i)
            T[i + S1[0]] = S2[i];
        T[0] = MAXSTRLEN;
        return FALSE;
    }
}
/* 索引子串 */
Status Index(sstring T, sstring S)
{
    int i = 1, j = 1;
    while(j <= T[0] && i <= S[0])
    {
        if (T[j] == S[i])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T[0])
    {
        printf("Position:%d\n", i - j + 1);
        return OK;
    }
    else
    {
        printf("substring is not exist\n");
        return ERROR;
    }
}
/* 在位置pos处插入子串T */
Status StrInsert(sstring T, sstring S, int pos)
{
    int i;
	//判断pos的合法性
    if (S[0] + T[0] <= MAXSTRLEN)
    {
        for (i = S[0] + T[0]; i >= pos + T[0]; --i)
            S[i] = S[i - T[0]];
        for (i = 1; i <= T[0]; ++i)
            S[pos + i - 1] = T[i];
        S[0] = S[0] + T[0];
        return OK;
    }
    else
    {
        for (i = MAXSTRLEN; i >= pos + T[0]; --i)
            S[i] = S[i - T[0]];
        for (i = 1; i <= T[0]; ++i)
            S[pos + i - 1] = T[i];
        S[0] = MAXSTRLEN;
        return ERROR;
    }
}
/*从串 S 中删除第 pos 个字符起长度为 len 的子串。*/
Status StrDelete(sstring S, int pos, int len)
{
    int i;
    if (pos > S[0])
        return ERROR;
    else if (pos + len > S[0])
        len = S[0] - pos + 1;
    S[0] -= len;
}
/* 字符串比较。比较字符串是否完全相同,如果不同则判断子串所在的位置 */
Status StrCompare(sstring S, sstring T)
{
    int i, j;
    for (i = 1; i <= T[0]&&i<=S[0]; ++i)
    {
        if(S[i]!=T[i])
			return S[i]-T[i]
    }
	return S[0]-T[0];
}
Status SubString(sstring &Sub, sstring S, int pos, int len) 
{ if (pos < 1 || pos > S[0] || len < 0 || len > S[0]-pos+1) 
      return ERROR; 
   Sub[1…len] = S[pos…pos+len-1]; 
   Sub[0]=len; 
   return OK; 
} // SubString



