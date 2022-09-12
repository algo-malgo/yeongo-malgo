#include <string>
#include <vector>

using namespace std;
int answer = 0;

void solve(vector<int> numbers, int target,int idx,int sum){
    if(idx == numbers.size() && sum == target){
        answer++;
        return;
    }
    if(idx != numbers.size()){
        solve(numbers,target,idx+1,sum+numbers[idx]);
        solve(numbers,target,idx+1,sum-numbers[idx]);
    }
}
int solution(vector<int> numbers, int target) {
    solve(numbers,target,0,0);
    return answer;
}
