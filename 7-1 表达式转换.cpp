#include<iostream>
#include<stack>
#include<stdio.h>
using namespace std;
bool Ischar(char ch)
{
    if(ch=='#'||ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')')
        return true;
    return false;
}
int Precede(char a,char b)
{
    char str[7] = {'+', '-', '*', '/','(', ')', '#'};
    int x,y,i;
    x = y = 0;
    for(i = 0; i < 7; i++)
    {
        if(a == str[i])
        {
            break;
        }
        x++;
    }
    for(i = 0; i < 7; i++)
    {
        if(b == str[i])
        {
            break;
        }
        y++;
    }
    int arr[7][7]= {{1,1,-1,-1,-1,1,1},  {1,1,-1,-1,-1,1,1},  {1,1,1,1,-1,1,1},  {1,1,1,1,-1,1,1},  {-1,-1,-1,-1,-1,0,2},  {1,1,1,1,2,1,1}, {-1,-1,-1,-1,-1,2,0}};
    return arr[x][y];

}
int main()
{
    char ch,tem;
    stack<char> OPND;
    stack<char> OPTR;
    OPTR.push('#');
    cin>>ch;
    if(ch == '+' || ch == '-')
    {
        if(ch == '+')
        {
            ch = getchar();
        }
        else
        {
            cout<<ch;
            ch = getchar();
        }


    }

    int flag = 0;
    int flag1;
    while(ch != '#' || OPTR.top() != '#')
    {
        flag1 = 0;
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            cout<<" ";
            flag1  = 1;
        }

        if(!Ischar(ch))
        {
            if(flag == 0)
            {
                cout<<ch;
                flag = 1;
            }
            else
                cout<<ch;
                ch = getchar();
            if(ch == '\n')
            {
                ch = '#';
            }
        }
        else
        {
            switch(Precede(OPTR.top(),ch))
            {
            case -1:
                OPTR.push(ch);
                tem = getchar();
                if((tem == '+' || tem == '-') && Ischar(ch) && ch != ')')
                {
                    if(tem == '+')
                    {

                    }
                    else
                    {
                        cout<<tem;
                    }

                    ch = getchar();
                    continue;
                }
                else
                    ch = tem;
                if(ch == '\n')
                    ch = '#';
                break;
            case 1:
                if(flag1 == 0)
                    cout<<" "<<OPTR.top();
                else
                    cout<<OPTR.top();
                OPTR.pop();
                break;
            case 0:
                OPTR.pop();
                tem = getchar();
                if((tem == '+' || tem == '-') && Ischar(ch) && ch != ')')
                {
                    if(tem == '+')
                    {

                    }
                    else
                    {
                        cout<<tem;
                    }
                    ch = getchar();
                    continue;
                }
                else
                    ch = tem;
                if(ch == '\n')
                {
                    ch = '#';
                }
                break;
            }
        }
    }
    return 0;
}
