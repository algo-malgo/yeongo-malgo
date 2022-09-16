#include <string>
#include <vector>
#include <stack>

using namespace std;
bool isCorrect(string s){
    stack<char>st;
    
    for(int i=0;i<s.size();i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }else{
            if(s[i] == ')'){
                if(st.empty() || st.top() != '(')return false;
                st.pop();
            }else if(s[i] == ']'){
                if(st.empty() || st.top () != '[')return false;
                st.pop();
            }else if(s[i] == '}'){
                if(st.empty() || st.top() != '{')return false;
                st.pop();
            }
        }
    }
    
    if(st.empty())return true;
    return false;
}
int solution(string s) {
    int answer = 0;
    for(int i=0;i<s.size();i++){
        if(isCorrect(s)){
            answer++;
        }
        s.push_back(s[0]);
        s.erase(0,1);
    }
    return answer;
}
