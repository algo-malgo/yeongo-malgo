#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int cnt = 0;
string changeToBinary(int n){
    string s;
    while(n != 1){
       s += to_string(n % 2);
        n /= 2;
    }
    s += '1';
    reverse(s.begin(),s.end());
    return s;
}
int checkOne(string s){
    int n = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '1')n++;
    }
    return n;
}
int solution(int n) {
    int answer = 0;
    cnt = checkOne(changeToBinary(n));
    for(int i=n+1;i<=1000000;i++){
        int tmp = checkOne(changeToBinary(i));
        if(tmp == cnt){
            answer = i;
            break;
        }
    }
    return answer;
}
