#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;
int main()
{
    string str;
    stack<char> sta;
    int flag = 0;
    while(1)
    {
        int i;
        getline(cin,str);
        if(str == ".")
            break;
        for(i = 0; i < str.size(); i++)
        {
            switch(str[i])
            {
            case '(':
                sta.push(str[i]);
                break;
            case '[':
                sta.push(str[i]);
                break;
            case '{':
                sta.push(str[i]);
                break;
            case '/':
                if(str[i+1] == '*')
                {
                    sta.push(str[i]);
                    i++;
//                    cout<<"×¢ÊÍÈë"<<endl;
                    break;
                }

                break;
            case ')':
                if(!sta.empty()&&sta.top() == '(')
                {
                    sta.pop();
                    break;
                }
                else if(sta.empty())
                {
                    flag = 2;
                    break;
                }
                else
                {
                    flag = 1;
                    break;
                }
            case ']':
                if(!sta.empty()&&sta.top() == '[')
                {
                    sta.pop();
                    break;
                }
                else if(sta.empty())
                {
                    flag = 4;
                    break;
                }
                else
                {
                    flag = 1;
                    break;
                }
            case '}':
                if(!sta.empty()&&sta.top() == '{')
                {
                    sta.pop();
                    break;
                }
                else if(sta.empty())
                {
                    flag = 6;
                    break;
                }
                else
                {
                    flag = 1;
                    break;
                }
            case '*':
                if(str[i+1] == '/')
                {
                    if(!sta.empty() && sta.top() == '/')
                    {
//                        cout<<"×¢ÊÍ³ö"<<endl;
                        sta.pop();
                        break;
                    }
                    else if(sta.empty())
                    {
                        flag = 8;
                        break;
                    }
                    else
                    {
                        flag = 1;
                        break;
                    }
                }

            }
            if(flag != 0)
                break;
//            cout<<str[i];
        }
//        cout<<endl;

    }
    if(sta.empty()&&flag == 0)
    {
        cout<<"YES";
    }
    else if(!sta.empty()||flag == 1)
    {
        cout<<"NO"<<endl;
        if(sta.top() == '/')
        {
            cout<<sta.top()<<"*-?"<<endl;
        }
        else
        {
            cout<<sta.top()<<"-?"<<endl;
        }

    }
    else if(flag == 2)
    {
        cout<<"NO"<<endl;
        cout<<"?-)"<<endl;
    }

    else if(flag == 4)
    {
        cout<<"NO"<<endl;
        cout<<"?-]"<<endl;

    }
    else if(flag == 6)
    {
        cout<<"NO"<<endl;
        cout<<"?-}"<<endl;

    }
    else if(flag == 8)
    {
        cout<<"NO"<<endl;
        cout<<"?-*/"<<endl;
    }

    return 0;
}
