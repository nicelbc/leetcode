//#include<bits/stdc++.h>
#include<stack>
#include<string>
//#include<iostream>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> sta;
        for (int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                sta.push(s[i]);
            else if(s[i] == ')'){
                if(sta.empty() || sta.top() != '('){
                    return false;
                }
                sta.pop();
            } else if(s[i] == ']'){
                if(sta.empty() || sta.top() != '[')
                    return false;
                sta.pop();
            } else if(s[i] == '}'){
                if(sta.empty() || sta.top() != '{')
                    return false;
                sta.pop();
            }
        }
        if(sta.empty())
            return true;
        else
            return false;
    }
};