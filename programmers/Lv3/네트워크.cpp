#include <string>
#include <iostream>
#include <vector>

using namespace std;
vector<int>v[201];
bool visit[201]={false,};
void dfs(int cur){
    visit[cur] = true;
    
    for(int i=0;i<v[cur].size();i++){
        int next = v[cur][i];
        if(!visit[next]){
            dfs(next);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<computers.size();i++){
        for(int j=0;j<computers[i].size();j++){
            if(!computers[i][j])continue;
            if(i == j)continue;
            if(computers[i][j] == 1){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(!visit[i]){
            dfs(i);
            answer++;
        }
    }
    return answer;
}
