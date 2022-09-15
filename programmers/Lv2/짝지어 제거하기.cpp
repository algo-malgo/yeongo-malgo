#include <iostream>
#include<string>
#include<stack>
using namespace std;

stack<char>st;
int solution(string s)
{
    for(int i=0;i<s.size();i++){
        if(!st.empty() && st.top() == s[i]){
            st.pop();
        }else{
            st.push(s[i]);
        }
    }
    
    if(st.empty()) return 1;
    return 0;
}
