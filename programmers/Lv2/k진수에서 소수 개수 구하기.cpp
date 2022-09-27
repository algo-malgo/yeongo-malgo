#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
vector<int> convert(int n, int k){
    vector<int>v;
    while(n){
        v.push_back(n % k);
        n /= k;
    }
    reverse(v.begin(),v.end());
    return v;
}
int isPrime(long long n){
    if(n < 2)return 0;
    
    for(long long i=2;i<=sqrt(n);i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}
int solution(int n, int k) {
    int answer = 0;
    vector<int>v = convert(n,k);
    
    long long cur = 0;
    
    for(auto i : v){
        if(i == 0){
            answer += isPrime(cur);
            cur = 0;
            continue;
        }
        cur = 10 * cur + i;
    }
    
    answer += isPrime(cur);
    
    return answer;
}
