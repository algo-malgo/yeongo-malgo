#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool cmp(pair<int,double>a, pair<int,double>b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int,double>>v;
    for(int i=1;i<=N;i++){
        double a = 0, b = 0;
        for(int j=0;j<stages.size();j++){
            if(stages[j] >= i){
                if(stages[j] == i)a++;
                b++;
            }
        }
        if(b == 0)v.push_back({i,0});
        else v.push_back({i,a/b});
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        answer.push_back(v[i].first);
    }
    return answer;
}
