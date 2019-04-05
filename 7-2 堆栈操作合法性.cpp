#include<iostream>
#include<string>
#include<stack>
#include<stdio.h>
using namespace std;

int main()
{
    int n,content,i;
    cin>>n>>content;
    getchar();
    for(i = 0; i < n; i++)
    {
        int flag = 0;
        string str;
        stack<char> small;
        getline(cin,str);
        for(int i=0; i<str.size(); i++)
        {
//            cout<<str[i]<<endl;
            switch(str[i])
            {
            case 'S':
                small.push(str[i]);    //遇到‘（’压进去
                break;
            case 'X':
                if(!small.empty())
                {
                    small.pop();     //遇到‘）’弹出来
                    break;
                }
                if(small.empty())     //循环问结束，若此时为空则失配，
                {
                    flag = 1;
                    break;
                }

            }
            if(small.size() > content)
            {
                flag = 1;
                break;
            }


        }
        if(small.empty()&&flag == 0)   //循环结束后，此时为空则匹配
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        while(!small.empty())
            small.pop();
    }

    return 0;
}
