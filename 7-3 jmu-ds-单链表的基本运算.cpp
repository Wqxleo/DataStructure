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
typedef int  ElemType; //假设线性表中的元素均为整型

typedef struct LNode
{
    char data;
    struct LNode *next;
} LNode,*LinkList;



Status InitList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
    L->data = 0;
    return OK;
}

Status CreatList(LinkList &L,int n)
{
    L = new LNode;
    L->next = NULL;
    L->data = n;
    int i;
    LNode *r = L;
    LNode *p = L;
    for (int i=1; i<=n; i++) //每次循环都开辟一个新节点，并把新节点拼到尾节点后
    {
        p = new LNode;//生成新结点
        scanf("%c",&p->data);
        getchar();
        p->next = NULL;  //最后一个节点的next赋空
        r->next = p;
        r = p;
    }
    return OK;
}

void ListPrint_L(LinkList &L)
{
//输出单链表
    LNode *p=L->next;  //p指向第一个元素结点
    while(p!=NULL)
    {
        if(p->next!=NULL)
            printf("%c ",p->data);
        else
            printf("%c",p->data);
        p=p->next;
    }
}

//输出指定节点
Status ListPrint(LinkList &L,int n)
{
    if(n > L->data||n < 1)
        return ERROR;
    LNode *p=L->next;  //p指向第一个元素结点
    int i = 1;
    while(p && i < n)
    {
        p = p->next;
        ++i;
    }
    printf("%c\n",p->data);
}

//指定位置插入
Status ListInsert(LinkList &L,char c,int n)
{
    if(n >L->data+1||n < 1)
        return ERROR;
    L->data++;
    int i = 1;
    LNode *p=L->next;  //p指向第一个元素结点
    LNode *TemNode;
    TemNode = new LNode;
    while(p && i < n-1)
    {
        p = p->next;
        ++i;
    }
    TemNode->data = c;
    TemNode->next = p->next;
    p->next = TemNode;
    return OK;
}

//获得链表的长度
int GetLinkListLength(LinkList &L)
{
    return L->data;
}



//定位元素的位置
int LocateLinkList(LinkList &L,char c)
{
    LNode *p=L->next;  //p指向第一个元素结点
    int j = 1;
    int flag = 0;
    while(p)
    {
        if(p->data == c)
        {
            flag = 1;
            break;
        }
        ++j;
        p = p->next;
    }
    if(flag == 0)
        return ERROR;
    return j;
}


//删除节点
Status LinkListDelate(LinkList &L,int n)
{
    if(n > L->data || n < 1)
        return ERROR;
    L->data--;
    LNode *p=L->next;  //p指向第一个元素结点
    int i = 1;
    while(p && i < n-1)
    {
        p = p->next;

        ++i;
    }
    if(!p || i > n-1)
        return ERROR;
    LNode *q;
    q = p->next;
    p->next = q->next;
    delete q;
    return OK;
}

//释放链表
void Free_LinkList(LinkList &L)
{
    LNode *Pointer;

    while (NULL != L)
    {
        Pointer = L;
        L = L->next;  // 下一个节点
        free(Pointer);
    }

    return;
}


int main()
{
    LinkList L;
    int n,i,len;
    InitList(L);
    printf("%d\n",L->next);
    scanf("%d",&n);
    getchar();
    CreatList(L,n);
    ListPrint_L(L);
    printf("\n");
    len = GetLinkListLength(L);
    printf("%d\n",len);
    if(len == 0)
        printf("yes\n");
    else
        printf("no\n");
    ListPrint(L,3);
    printf("%d\n",LocateLinkList(L,'a'));
    if(ListInsert(L,'x',4))
        ListPrint_L(L);
    printf("\n");
    if(LinkListDelate(L,3))
        ListPrint_L(L);
    Free_LinkList(L);
}
