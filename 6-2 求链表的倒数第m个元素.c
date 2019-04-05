#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read()
{
    int n;
    scanf("%d",&n);
    List L;
    L->Next = NULL;
    L->Data = 0;
    int i;
    PtrToNode r = L->Next;
    PtrToNode p = L->Next;
    for (i=1; i<=n; i++) //每次循环都开辟一个新节点，并把新节点拼到尾节点后
    {
        //PtrToNode p;//生成新结点
        scanf("%d",&p->Data);
        p->Next = NULL;  //最后一个节点的next赋空
        r->Next = p;
        r = p;
    }
    return L;
} /* 细节在此不表 */
void Print( List L )
{
     PtrToNode p=L->Next;  //p指向第一个元素结点
    while(p!=NULL)
    {
        if(p->Next!=NULL)
            printf("%c ",p->Data);
        else
            printf("%c",p->Data);
        p=p->Next;
    }
} /* 细节在此不表 */

ElementType Find( List L, int m )
{
    if(L)
    {
        PtrToNode p1,p2;
        p1 = p2 = L->Next;
        int i = 1;
        while(p1->Next && i < m)
        {
            p1 = p1->Next;
            i++;
        }
        while(p1->Next)
        {
            p1 = p1->Next;
            p2 = p2->Next;
        }
        return p2->Data;
    }
}

int main()
{
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L,m));
    Print(L);
    return 0;
}
