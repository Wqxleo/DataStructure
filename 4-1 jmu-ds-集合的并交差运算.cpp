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
    //声明一个顺序表
    SqList La,Lb,Lc,Ld,Le;
    //初始化顺序表
    InitList_Sq(La);
    InitList_Sq(Lb);
    InitList_Sq(Lc);
    InitList_Sq(Ld);
    InitList_Sq(Le);
    int na,nb,nc,nd,ne,i,j;
    scanf("%d%d", &na,&nb);
    int tem;
    for(i = 0;i < na; i++)
    {
        scanf("%d",&tem);
        ListInsert_SortedSq(La,tem);
        ListInsert_SortedSq(Lc,tem);
    }
//    ListPrint_Sq(La);

    for(j = 0;j < nb; j++)
    {
        scanf("%d",&tem);
        ListInsert_SortedSq(Lb,tem);
    }
//    ListPrint_Sq(Lb);
    nc = na;
    nd = ne = 0;
    for(j = 0;j < nb; j++)
    {
        int flag = 0;
        for(i = 0; i < na; i++)
        {
            if(Lb.elem[j] == La.elem[i])
            {
                flag = 1;
            }
        }
        if(flag == 0)
        {
           ListInsert_SortedSq(Lc,Lb.elem[j]);
//           ListInsert_SortedSq(Le,Lb.elem[j]);
           nc++;
//           ne++;
        }

    }


    for(j = 0;j < na; j++)
    {
        int flag = 0;
        for(i = 0; i < nb; i++)
        {
            if(Lb.elem[i] == La.elem[j])
            {
                flag = 1;
            }
        }
        if(flag == 0)
        {
           ListInsert_SortedSq(Le,La.elem[j]);
           ne++;
        }
        else
        {
            ListInsert_SortedSq(Ld,La.elem[j]);
            nd++;
        }
    }
    printf("%d ",nc);
    ListPrint_Sq(Lc);
    printf("\n");
    printf("%d ",nd);
    ListPrint_Sq(Ld);
    printf("\n");
    printf("%d ",ne);
    ListPrint_Sq(Le);

    return  0;
}
