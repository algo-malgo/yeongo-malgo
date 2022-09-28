#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int answer = 0;

int isPrime(int n){
    if(n < 2)return 0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return 0;
    }
    return 1;
}
void solve(vector<int> nums,int cnt,int idx,int sum){
    if(cnt == 3){
        answer += isPrime(sum);
        return;
    }
    for(int i=idx;i<nums.size();i++){
        solve(nums,cnt+1,i+1,sum+nums[i]);
    }
}
int solution(vector<int> nums) {

    sort(nums.begin(),nums.end());
    solve(nums,0,0,0);
    return answer;
}
