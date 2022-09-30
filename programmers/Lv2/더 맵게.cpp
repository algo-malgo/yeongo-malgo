#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
priority_queue<long long,vector<long long>,greater<long long>>pq;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    while(!pq.empty()){
        if(pq.top() >= K)break;
        
        if(pq.size() >= 2){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long tmp = a + b * 2;
            pq.push(tmp);
            answer++;
        }else{
            return -1;
        }
        
    }
    return answer;
}
