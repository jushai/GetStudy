#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSTRLEN 255
typedef unsigned char sstring[MAXSTRLEN+1];
/* �ַ�����ֵ,����ֵ�ַ������ȳ�������ֵ�ַ���ʱ��ض�,δ����ʱ�Ƚ����ȴ���T[0],����λ��ֵ */
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
        T[0] = strlen(chars); //p.s.��ʱT[0]�������int���͵�����,��ӡ%sʱ�޷���ʾ
        for (i = 1; i <= T[0]; ++i)
            T[i] = chars[i-1];
        return OK;
    }
}
/* �ַ�������,����ַ�����(���������ȷ�Χ�ڵ�) */
Status StrCopy(sstring T, sstring S)
{
    int i;
    //p.s.�˴�Ҫ��������+1,��S1��\0ͬʱ������ȥ,����T��û��\0
    for (i = 1; i <= S[0]; ++i)
        T[i] = S[i];
    T[0] = S[0];
    return OK;
}
/* �ַ����п�,��S[0]==0ʱΪ�� */
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
/* �����Ӵ����� */
Status StrLength (sstring S)
{
    return S[0];
}
/* ��ӡ�ַ��� */
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
/* ����ַ��� */
Status ClearString(sstring S)
{
    S[0] = 0;
    return OK;
}
/* �ַ�������,ͨ��T���洢���,S2���Ӷ��ɵ��´�,��δ�ض��򷵻�TRUE,�ضϷ���FAlSE,ע���ַ�������Խ������ */
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
    else //�ȴ���S1�е�,�ٴ�S2�е�����,�����ǲ���Խ��
    {
        for (i = 1; i <= S1[0] && i <= MAXSTRLEN - 1; ++i)
            T[i] = S1[i];
        for (i = 1; i <= MAXSTRLEN - S1[0]; ++i)
            T[i + S1[0]] = S2[i];
        T[0] = MAXSTRLEN;
        return FALSE;
    }
}
/* �����Ӵ� */
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
/* ��λ��pos�������Ӵ�T */
Status StrInsert(sstring T, sstring S, int pos)
{
    int i;
	//�ж�pos�ĺϷ���
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
/*�Ӵ� S ��ɾ���� pos ���ַ��𳤶�Ϊ len ���Ӵ���*/
Status StrDelete(sstring S, int pos, int len)
{
    int i;
    if (pos > S[0])
        return ERROR;
    else if (pos + len > S[0])
        len = S[0] - pos + 1;
    S[0] -= len;
}
/* �ַ����Ƚϡ��Ƚ��ַ����Ƿ���ȫ��ͬ,�����ͬ���ж��Ӵ����ڵ�λ�� */
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
   Sub[1��len] = S[pos��pos+len-1]; 
   Sub[0]=len; 
   return OK; 
} // SubString



