#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree()/* ÊµÏÖÏ¸½ÚºöÂÔ */
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
        T->Data = ch;
        T->Left = CreatBinTree();
        T->Right = CreatBinTree();
    }
    return T;
}
void PreorderPrintLeaves( BinTree BT )
{
    if(BT)
    {
        if(BT->Left == NULL && BT->Right == NULL)
        printf(" %c",BT->Data);
        PreorderPrintLeaves(BT->Left);
        PreorderPrintLeaves(BT->Right);

    }
}

int main()
{
    BinTree BT = CreatBinTree();
    printf("Leaf nodes are:");
    PreorderPrintLeaves(BT);
    printf("\n");
    return 0;
}
