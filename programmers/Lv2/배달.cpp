#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector<pair<int,int>>v[51];
bool visit[51] = {false,};
map<int,bool>m;
void dfs(int cur, int K, int sum){
    visit[cur] = true;
    
    for(int i=0;i<v[cur].size();i++){
        int next = v[cur][i].first;
        int nCost = v[cur][i].second;
        
        if(!visit[next]){
            if(sum + nCost <= K){
                m[next] = true;
                if(sum + nCost == K)continue;
                dfs(next, K, sum + nCost);
                visit[next] = false;
            }
        }
    }
}
int solution(int N, vector<vector<int> > road, int K) {
    for(int i=0;i<road.size();i++){
        v[road[i][0]].push_back({road[i][1],road[i][2]});
        v[road[i][1]].push_back({road[i][0],road[i][2]});
    }
    dfs(1,K,0);

    return m.size() + 1;
}
