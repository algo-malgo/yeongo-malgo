#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
map<string,int>m;
bool isAlreadyCalled(string str){
    auto it = m.find(str);
    if(it != m.end()){
        return m[str] > 1;
    }else{
        return false;
    }
}
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int round = 1;
    int number = 2;
    int idx = 0;
    string prev = words[0];
    bool flag = false;
    
    for(int i=1;i<words.size();i++){
        string cur = words[i];
        m[prev]++;
        m[cur]++;
        
        char last = prev[prev.size()-1];
        char first = cur[0];
        
        if(last != first || cur.size() == 1 || isAlreadyCalled(cur)){
            flag = true;
            answer.push_back(number);
            answer.push_back(round);
            break;
        }
        // init
        prev = words[i];
        if(number == n){
            number = 1;
            round++;
        }
        else{
            number++;
        }
    }
    if(flag){
        return answer;
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}
