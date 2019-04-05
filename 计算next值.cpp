#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;


//课本
void get_next(string T, int next[],int n)
{
    int i = 1;
    next[1] = 0;
    int j = 0;
    while(i <= n)
    {
        if(j==0||T[i-1]==T[j-1])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}



//网上找的
//void get_next(string p,int next[],int n)
//{
//    int j,k;
//    next[1]=0;
//    j=1;
//    k=0;
//    while(j<n-1)
//    {
//        if(k==0||p[j]==p[k])    //匹配的情况下,p[j]==p[k]，next[j+1]=k+1;
//        {
//            j++;
//            k++;
//            next[j]=k;
//        }
//        else                   //p[j]!=p[k]，k=next[k]
//            k=next[k];
//    }
//}

//void get_nextval(String T, int *nextval)
//{
//    int i,j;
//    i=1;
//    j=0;
//    nextval[1]=0;
//    while (i<T[0])  /* 此处T[0]表示串T的长度 */
//    {
//        if(j==0 || T[i]== T[j])     /* T[i]表示后缀的单个字符，T[j]表示前缀的单个字符 */
//    {
//                ++i;
//                ++j;
//        if (T[i]!=T[j])      /* 若当前字符与前缀字符不同 */
//                nextval[i] = j; /* 则当前的j为nextval在i位置的值 */
//            else
//            nextval[i] = nextval[j];    /* 如果与前缀字符相同，则将前缀字符的 */
//                            /* nextval值赋值给nextval在i位置的值 */
//        }
//    else
//        j= nextval[j];          /* 若字符不相同，则j值回溯 */
//    }
//}
int main()
{
    int i;
    string T;
    cin>>T;
    int n = T.size();
    int next[n+1];
    get_next(T,next,n);
    for(i = 1; i <= n; i++)
    {
        printf("%d",next[i]);
    }
}
