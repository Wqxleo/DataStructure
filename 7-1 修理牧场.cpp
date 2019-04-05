//#include<iostream>
//using namespace std;
//typedef struct
//{
//    int weight;
//    int parent;
//    int lchild;
//    int rchild;
//} HTNode, *HuffmanTree;
//void Select(HuffmanTree HT, int n, int &s1, int &s2)
//{
//    int i;
//    int min1, min2;
//    min1 = min2 = 32767;
//    for(i = 1; i <= n; ++i)
//    {
//        if(HT[i].parent == 0)
//        {
//            if(min1 >= HT[i].weight)
//            {
//                min2 = min1;
//                s2 = s1;
//                min1 = HT[i].weight;
//                s1 = i;
//            }
//            else if(HT[i].weight < min2 && HT[i].weight > min1)
//            {
//                min2 = HT[i].weight;
//                s2 = i;
//            }
//        }
//    }
//}
//int CreateHuffmanTree(HuffmanTree &HT, int n)
//{
//    if(n <= 1)
//        return NULL;
//    int sum = 0;
//    int m = 2*n-1;
//    HT = new HTNode[m+1];
//    int i;
//    for(i = 1; i <= m; ++i)
//    {
//        HT[i].parent = 0;
//        HT[i].lchild = 0;
//        HT[i].rchild = 0;
//    }
//    for(i = 1; i <= n; ++i)
//    {
//        cin>>HT[i].weight;
//    }
//    for(i = n+1; i < m+1; ++i)
//    {
//        int s1,s2;
//        s1 = s2 = 1;
//        Select(HT, i-1, s1, s2);
//        HT[s1].parent = i;
//        HT[s2].parent = i;
//        HT[i].lchild = s1;
//        HT[i].rchild = s2;
//        HT[i].weight = HT[s1].weight + HT[s2].weight;
//        sum += HT[i].weight;
//    }
//    return sum;
//}
//int main()
//{
//    HuffmanTree HT;
//    int N;
//    cin>>N;
//    cout<<CreateHuffmanTree(HT,N);
//
//}
//
//
//
//
//
//
//
//
//
//



#include<iostream>
#include<vector>
using namespace std;
void select(vector<int> &arr,int &min1)
{
    int i,min11;
    min1  = arr[0];
    min11 = 0;
    for(i = 1; i < arr.size(); i++)
    {
        if(min1 > arr[i])
        {

            min1 = arr[i];
            min11 = i;
        }
    }
    arr.erase(arr.begin() + min11);

}
int main()
{
    int n,i,sum,tem;
    cin>>n;
    vector<int> arr;
    sum = 0;
    for(i = 0; i < n; i++)
    {
        cin>>tem;
        arr.push_back(tem);
    }
    while(n>1)
    {
        int min1,min2;
        min1 = min2 = 32767;
        select(arr,min1);
        sum += min1;
        select(arr,min2);

        sum += min2;
//        cout<<sum<<endl;
        arr.push_back(min1 + min2);
//        if(min1 < min2)
//        {
//            arr.erase(arr.begin()+min1);
//            arr.erase(arr.begin()+min2-1);
//        }
//        else
//        {
//            arr.erase(arr.begin()+min2);
//            arr.erase(arr.begin()+min1-1);
//        }
        n--;
    }
    cout<<sum;
    return 0;
}
