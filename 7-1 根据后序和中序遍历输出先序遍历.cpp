#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree createBinTree(int *post,int *ino,int n)
{
    if(n == 0)
        return NULL;
    BinTree BT;
    BT = new TNode;
    if(BT == NULL)
        return NULL;
    BT->Data = post[n-1];
    int left[20],right[20];
    int ln, rn;
    ln = rn = 0;
    int i = 0;
    for(i = 0; i < n; i++)
    {
        if(i <= ln && ino[i] != post[n-1])
        {
            left[ln] = ino[i];
            ln++;
        }
        else if(ino[i] != post[n-1])
        {
            right[rn++] = ino[i];
        }
    }
//    for(i = 0; i < ln; i++)
//    {
//        cout<<left[i]<<" ";
//    }
//    cout<<endl;
//    for(i = 0; i < rn; i++)
//    {
//        cout<<right[i]<<" ";
//    }
//    cout<<endl;
    int po1[20],po2[20];
    int pn1,pn2;
    pn1 = pn2 = 0;
    for(i = 0; i < n-1; i++)
    {
        if(i < ln)
        {
            po1[pn1++] = post[i];
        }
        else
        {
            po2[pn2++] = post[i];
        }
    }
//    for(i = 0; i < pn1; i++)
//    {
//        cout<<po1[i]<<" ";
//    }
//    cout<<endl;
//    for(i = 0; i < pn2; i++)
//    {
//        cout<<po2[i]<<" ";
//    }
//    cout<<endl;
    BT->Left = createBinTree(po1,left,ln);
    BT->Right = createBinTree(po2,right,rn);
    return BT;

}

void PreorderTraversal(BinTree BT)
{
    if(BT)
    {
        printf(" %d",BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);

    }
}
int main()
{
    int n;
    cin>>n;
    int post[n],ino[n];
    int i;
    for(i = 0; i < n; i++)
    {
        cin>>post[i];
    }
    for(i = 0; i < n; i++)
    {
        cin>>ino[i];
    }
    BinTree BT;
    BT = createBinTree(post,ino,n);
    cout<<"Preorder:";
    PreorderTraversal(BT);
    return 0;
}
