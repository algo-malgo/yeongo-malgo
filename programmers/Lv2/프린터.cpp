#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int>pq;
    queue<pair<int,int>>q;
    for(int i=0;i<priorities.size();i++){
        q.push({priorities[i],i});
        pq.push(priorities[i]);
    }
    while(!q.empty()){
        int val = q.front().first;
        int idx = q.front().second;
        q.pop();
        
        if(pq.top() == val){
            pq.pop();
            answer++;
            if(location == idx)break;
            
        }else{
            q.push({val,idx});
        }
    }
    return answer;
}
