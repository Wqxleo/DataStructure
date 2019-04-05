#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;
//Ë«Ç×±íÊ¾·¨
typedef struct
{
    string name;
    int parent;
} TNode, *FamilyTree;
int InitFamilyTree(FamilyTree &BT, int n)
{
    if(n <= 1)
        return NULL;
    BT = new TNode[n];
    int i;
    string name;
    getchar();
    for(i = 0; i < n; ++i)
    {
        getline(cin, name);
        BT[i].name = name;
        BT[i].parent = -1;
    }
    return 1;

}
int getspacenum(string name)
{
    int i;
    for(i = 0; i < name.size(); ++i)
    {
        if(name[i] != ' ')
            break;
    }
    return i;
}
bool IsParent(int num, string name)
{
    if(name[num-1] != ' ')
        return true;
}
void BuildFamilyTree(FamilyTree &BT, int n)
{
    int i,j;
    for(i = n-1; i >= 0; --i)
    {
        int temnum = getspacenum(BT[i].name);
        for(j = i-1; j >= 0; --j)
        {
            if(IsParent(temnum,BT[j].name))
            {
                BT[i].parent = j;
                break;
            }
        }
    }
}
string getname(string name)
{
    int i;
    string newname;
    stringstream tem;
    tem.clear();
    tem.str(name);
    tem>>newname;
    return newname;
}
int Getindex(string name, FamilyTree BT, int m)
{
    int i;
    for(i = 0; i < m; ++i)
    {
        if(getname(BT[i].name) == name)
        {
            return i;
        }

    }
    return -1;
}

int main()
{
    int m,n,i;
    string name1,name2,is,theora,relation,of;
    cin>>m>>n;
    FamilyTree BT;
    InitFamilyTree(BT,m);
    BuildFamilyTree(BT,m);
//    for(i = 0; i < m; ++i)
//    {
//        cout<<BT[i].name<<" "<<BT[i].parent<<endl;
//    }
    for(i = 0; i < n; i++)
    {
        cin>>name1>>is>>theora>>relation>>of>>name2;
        if(relation == "child")
        {
            int index = Getindex(name1,BT,m);
            if(BT[index].parent == Getindex(name2,BT,m))
            {
                printf("True\n");
            }
            else
            {
                printf("False\n");
            }

        }
        else if(relation == "parent")
        {
            int index = Getindex(name2,BT,m);
            if(BT[index].parent == Getindex(name1,BT,m))
            {
                printf("True\n");
            }
            else
            {
                printf("False\n");
            }
        }
        else if(relation == "ancestor")
        {
            int index = Getindex(name2,BT,m);
            int flag = 0;
            while(index != -1)
            {
                if(index == 0)
                    break;
                if(getname(BT[BT[index].parent].name) == name1)
                {
                    flag = 1;
                    printf("True\n");
                    break;
                }
                else
                {
                    index = BT[index].parent;
                }
            }
            if(flag == 0)
                printf("False\n");
        }
        else if(relation == "sibling")
        {
            int index1 = Getindex(name1,BT,m);
            int index2 = Getindex(name2,BT,m);
            if(getspacenum(BT[index1].name) == getspacenum(BT[index2].name))
                printf("True\n");
            else
                printf("False\n");
        }
        else if(relation == "descendant")
        {
            int index = Getindex(name1,BT,m);
            int flag = 0;
            while(index != -1)
            {
                if(index == 0)
                    break;
                if(getname(BT[BT[index].parent].name) == name2)
                {
                    flag = 1;
                    printf("True\n");
                    break;
                }
                else
                {
                    index = BT[index].parent;
                }
            }
            if(flag == 0)
                printf("False\n");
        }
    }
    return 0;
}

