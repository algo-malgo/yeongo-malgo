#include<vector>
#include<queue>
#include<iostream>
using namespace std;
int visit[101][101] = {0,};
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n,m;

int bfs(vector<vector<int> > maps){
    queue<pair<int,int>>q;
    q.push({0,0});
    visit[0][0] = 1;
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        if(x == n-1 && y == m-1){
            return visit[n-1][m-1];
        }
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx >=0 && ny >=0 && nx < n && ny < m && maps[nx][ny] == 1 && !visit[nx][ny]){
                q.push({nx,ny});
                visit[nx][ny] = visit[x][y] + 1;
            }
        }
    }
    return -1;
}
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    answer = bfs(maps);
    return answer;
}
