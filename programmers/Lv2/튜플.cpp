#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool check[100001]={false,};

bool cmp(vector<int>a,vector<int>b){
    return a.size() < b.size();
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>>v;
    vector<int>tmp;
    string str = "";
    for(int i=1;i<s.size()-1;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            str += s[i];
        }
        else if(s[i] == '}'){
            tmp.push_back(stoi(str));
            v.push_back(tmp);
            tmp.clear();
            str = "";
        }
        else if(s[i] == ','){
            if(s[i-1] != '}'){
                tmp.push_back(stoi(str));
                str = "";
            }
        }
    }
    sort(v.begin(),v.end(),cmp);
    
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(check[v[i][j]])continue;
            check[v[i][j]]=true;
            answer.push_back(v[i][j]);
        }
    }
    return answer;
}
