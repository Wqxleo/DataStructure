#include<iostream>
#define Maxnum 10
using namespace std;
typedef struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode, *BSTree;
void InsertBSTree(BSTree &bstree, int tem)
{
    if(bstree == NULL)
    {

//        cout<<"charu"<<endl;
        bstree = new BSTNode;
        bstree->data = tem;
        bstree->left = NULL;
        bstree->right = NULL;
    }
    else
    {
        if(tem < bstree->data)
        {
            InsertBSTree(bstree->left,tem);
        }
        else if(tem > bstree->data)
        {
            InsertBSTree(bstree->right,tem);
        }
    }
}
bool Judge(BSTree IniBSTree, BSTree ComBSTree)
{
    if(IniBSTree == NULL && ComBSTree == NULL)
        return true;
    else if(IniBSTree == NULL && ComBSTree != NULL)
        return false;
    else if(IniBSTree != NULL && ComBSTree == NULL)
        return false;
    else if(IniBSTree->data != ComBSTree->data)
        return false;
    else
    {
        if(Judge(IniBSTree->left, ComBSTree->left))
        {
            return Judge(IniBSTree->right,ComBSTree->right);
        }
    }
}
int main()
{
    int N;
    int L;
    int i;
    int tem;
    while(1)
    {
        cin>>N;
        if(N == 0)
            break;
        cin>>L;
        BSTree IniBSTree = NULL;
        for(i = 0; i < N; i++)
        {
            cin>>tem;
//            cout<<"²åÈëº¯Êý"<<endl;
            InsertBSTree(IniBSTree, tem);
        }
        while(L--)
        {
            BSTree ComBSTree = NULL;
            for(i = 0; i < N; i++)
            {
                cin>>tem;
                InsertBSTree(ComBSTree, tem);
            }
            if(Judge(IniBSTree, ComBSTree))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
}
