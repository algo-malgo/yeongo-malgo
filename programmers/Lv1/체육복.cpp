#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int>v(0);
    v.resize(30);
    for(int i=1;i<=n;i++){
        v[i] = 1;
    }
    for(int i=0;i<reserve.size();i++){
        v[reserve[i]]++;
    }
    for(int i=0;i<lost.size();i++){
        v[lost[i]]--;
    }
    
    for(int i=1;i<=n;i++){
        if(v[i] < 1){
            if(v[i-1] > 1){
                v[i-1]--;
                v[i]++;
            }else if(v[i+1] > 1){
                v[i+1]--;
                v[i]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(v[i] > 0){
            answer++;
        }
    }
    return answer;
}
