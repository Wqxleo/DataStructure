#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct TNode *Position;
typedef Position BinTree;
struct TNode
{
    char data;
    BinTree Left;
    BinTree Right;
};
BinTree CreatBinTree()
{
    BinTree T;
    char ch;
    scanf("%c",&ch);
    getchar();
    if(ch == '#')
    {
        T = NULL;
    }
    else
    {
        T = new TNode;
        T->data = ch;
        T->Left = CreatBinTree();
        T->Right = CreatBinTree();
    }
    return T;
}

//先序遍历
void PreorderTraversal(BinTree BT)
{
    if(BT)
    {
        printf("%c ", BT->data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }

}


//中序遍历
void InorderTraversal(BinTree BT)
{
    if(BT)
    {
        InorderTraversal(BT->Left);
        printf("%c ",BT->data);
        InorderTraversal(BT->Right);
    }
}

//后序遍历
void PostorderTraversal(BinTree BT)
{
    if(BT)
    {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf("%c ",BT->data);
    }
}

//层序遍历
void LevelorderTraversal(BinTree BT)
{
    if(BT)
    {
        BinTree b[100];
        b[0] = BT;
        int first = 0;
        int rear = 1;
        while(first < rear)
        {
            printf("%c ",b[first]->data);
            if(b[first]->Left)
            {
                b[rear++] = b[first]->Left;
            }
            if(b[first]->Right)
            {
                b[rear++] = b[first]->Right;
            }
            first++;
        }

    }
}
int main()
{

}
