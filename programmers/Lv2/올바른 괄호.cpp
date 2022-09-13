#include<string>
#include <iostream>
#include <stack>

using namespace std;
stack<char>st;
bool solution(string s)
{
    for(int i=0;i<s.size();i++){
        if(s[i] == '('){
            st.push('(');
        }
        else if(s[i] == ')'){
            if(st.empty() || st.top() != '('){
                return false;
            }
            else{
                st.pop();
            }
        }
    }
    if(!st.empty())return false;
    return true;
}
