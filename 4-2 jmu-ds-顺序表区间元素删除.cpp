//库函数头文件包含
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

//函数状态码定义
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2

typedef int  Status;

//顺序表的存储结构定义
#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10
typedef int ElemType;  //假设线性表中的元素均为整型
typedef struct
{
    ElemType* elem;   //存储空间基地址
    int length;       //表中元素的个数
    int listsize;     //表容量大小
} SqList;   //顺序表类型定义


//顺序表初始化函数
Status InitList_Sq(SqList &L)
{
    //开辟一段空间
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    //检测开辟是否成功
    if(!L.elem)
    {
        exit(OVERFLOW);
    }
    //赋值
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;

    return OK;
}

//顺序表输出函数
void ListPrint_Sq(SqList L)
{
    ElemType *p = L.elem;//遍历元素用的指针


    for(int i = 0; i < L.length; ++i)
    {
        if(i == L.length - 1)
        {
            printf("%d", *(p+i));
        }
        else
        {
            printf("%d ", *(p+i));
        }
    }
}
Status ListInsert_SortedSq(SqList &L, ElemType e)
{
    if(L.length == L.listsize)
        L.listsize += LISTINCREMENT;
    L.elem[L.length] = e;
    ++L.length;
    return OK;
}
int main()
{
    SqList L;
    InitList_Sq(L);
    int n,i,j,tem,x,y;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%d",&tem);
        ListInsert_SortedSq(L,tem);
    }
//    ListPrint_Sq(L);
    scanf("%d%d",&x,&y);
//    printf("%d%d\n",x,y);
//    for(i = 0; i < n; i++)
//    {
//        if(L.elem[i] >= x && L.elem[i] <= y)
//        {
//
//            for(j = i; j < n; j++)
//            {
//                L.elem[j] = L.elem[j+1];
//            }
//            L.length--;
//            i--;
//        }
//
//    }
    i = 0;
    j = n-1;
    while(i < j)
    {
        if(L.elem[i] >= x && L.elem[i] <= y)
        {
            if(L.elem[j] >= x && L.elem[j] <= y)
            {
                --L.length;
                --j;
            }
            else
            {
                L.elem[i] = L.elem[j];
                --L.length;
                ++i;
                --j;
            }
        }
        else
        {
            ++i;
        }
    }
    ListPrint_Sq(L);

}
