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
typedef struct{
    ElemType* elem;   //存储空间基地址
    int length;       //表中元素的个数
    int listsize;     //表容量大小
}SqList;    //顺序表类型定义
//Status ListCreate_Sq(SqList &L);
//void ListReverse_Sq(SqList &L);
Status ListCreate_Sq(SqList &L)
{
    int len;
    scanf("%d",&len);
    L.elem = new ElemType[len];
    L.length = len;
    int i;
    for(i = 0; i < len; i++)
    {
        scanf("%d",&L.elem[i]);
    }
    return OK;
}
void ListReverse_Sq(SqList &L)
{
    ElemType tem;
    int i;
    for(i = 0;i < L.length/2; ++i)
    {
         tem = L.elem[i];
         L.elem[i] = L.elem[L.length-i-1];
         L.elem[L.length-i-1] = tem;
    }


}

int main() {
    SqList L;
    ElemType *p;

    if(ListCreate_Sq(L)!= OK) {
        printf("ListCreate_Sq: 创建失败！！！\n");
        return -1;
    }
    ListReverse_Sq(L);

    if(L.length){
				for(p=L.elem;p<L.elem+L.length-1;++p){
				    printf("%d ",*p);
				}
				printf("%d",*p);
    }
    return 0;
}
