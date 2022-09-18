#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int gcd(int a,int b){
    int c;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
long long lcm(int a,int b){
    return a * b / gcd(a,b);
}
int solution(vector<int> arr) {
    int answer = 0;
    vector<long long>v;
    for(int i=0;i<arr.size();i++){
        v.push_back(arr[i]);
    }
    while(1){
        sort(v.begin(),v.end(),greater<>());
        if(v.size() == 1){
            answer = v[0];
            break;
        }
        long long a = v[0];
        v.erase(v.begin());
        long long b = v[0];
        v.erase(v.begin());
        v.push_back(lcm(a,b));
    }
    return answer;
}
