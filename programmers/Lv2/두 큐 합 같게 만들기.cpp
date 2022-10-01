#include <string>
#include <vector>
#include <iostream>

using namespace std;
long getSum(vector<int>v){
    long sum = 0;
    for(int i=0;i<v.size();i++){
        sum += v[i];
    }
    return sum;
}
int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long target = (getSum(queue1) + getSum(queue2)) / 2;
    vector<int>v;
    for(int i=0;i<queue1.size();i++){
        v.push_back(queue1[i]);
    }
    for(int i=0;i<queue2.size();i++){
        v.push_back(queue2[i]);
    }
    
    int low = 0;
    int high = v.size() - queue1.size();
    long cur = getSum(queue1);
    while(high > low && high < v.size()){
        if(cur == target)return answer;
        if(cur < target){
            cur += v[high++];
        }else if(cur > target){
            cur -= v[low++];
        }
        answer++;
    }
    return -1;
}
