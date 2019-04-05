#include<iostream>
#include<queue>
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
        bstree = new BSTNode;
        bstree->data = tem;
        bstree->left = NULL;
        bstree->right = NULL;
    }
    else
    {
        if(tem > bstree->data)
        {
            InsertBSTree(bstree->left,tem);
        }
        else if(tem < bstree->data)
        {
            InsertBSTree(bstree->right,tem);
        }
    }
}
void LevelOrderTraverse(BSTree bstree)
{
    queue<BSTree> q;
    if(bstree)
    {
        q.push(bstree);
        cout<<q.front()->data;
        if(q.front()->left != NULL)
            q.push(q.front()->left);
        if(q.front()->right != NULL)
            q.push(q.front()->right);
        q.pop();
        while(!q.empty())
        {
            cout<<" "<<q.front()->data;
            if(q.front()->left != NULL)
                q.push(q.front()->left);
            if(q.front()->right != NULL)
                q.push(q.front()->right);

            q.pop();

        }
    }
}


bool IsCompleteTree(BSTree bstree)
{
    if(bstree == NULL)
        return true;
    if(bstree->left == NULL && bstree->right == NULL)
        return true;
    queue<BSTree> q;
    bool flag = false;
    int num = 0;
    int num1 = 0;
    q.push(bstree);
    while(!q.empty())
    {
        if(q.front()->left != NULL)
            q.push(q.front()->left);
        if(q.front()->right != NULL)
            q.push(q.front()->right);
        //第一次出现空孩子是左孩子为空
        if(q.front()->left == NULL && num == 0)
        {
            flag = true;
            num = 1;//标记出现空孩子
        }
        if((q.front()->left != NULL || q.front()->right != NULL) && num == 1)
            return false;
        if(num == 1 && q.front()->right != NULL)
            return false;
        //第一次出现空孩子是右孩子为空
        if(q.front()->right == NULL && num == 0)
        {
            flag = true;
            num = 1;
//            num1 = 1;
        }
        if((q.front()->right != NULL) && num == 1)
            return false;
        q.pop();
    }
    return flag;
}
int main()
{
    int n;
    int i;
    int tem;
    BSTree bstree = NULL;
    cin>>n;
    for(i = 0; i < n; i++)
    {
        cin>>tem;
        InsertBSTree(bstree, tem);
    }
    LevelOrderTraverse(bstree);
    cout<<endl;
    if(IsCompleteTree(bstree))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
