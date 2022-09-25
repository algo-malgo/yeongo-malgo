#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int>st;
    
    for(int i=0;i<arr.size();i++){
        if(!st.empty() && st.top() == arr[i])continue;
        st.push(arr[i]);
    }
    vector<int>v;
    while(!st.empty()){
        v.push_back(st.top());
        st.pop();
    }
    for(int i=v.size()-1;i>=0;i--){
        answer.push_back(v[i]);
    }
    return answer;
}
