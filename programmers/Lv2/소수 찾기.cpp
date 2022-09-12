#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;
map<int,int>m;
bool visit[10]={false,};
string str;

void makeNumbers(string numbers){
    for(int i=0;i<numbers.size();i++){
        if(!visit[i]){
            visit[i] = true;
            str += numbers[i];
            m[stoi(str)] += 1;
            makeNumbers(numbers);
            visit[i] = false;
            str.pop_back();
        }
    }
}
bool isPrime(int num){
    vector<int>v;
    v.resize(num+1);
    
    for(int i=2;i<=num;i++){
        v[i] = i;
    }
    for(int i=2;i<=sqrt(num);i++){
        if(v[i]){
           for(int j=i*i;j<=num;j+=i){
               v[j] = 0;
           } 
        }
    }
    return v[num] != 0;
}
int solution(string numbers) {
    int answer = 0;
    makeNumbers(numbers);
    for(auto i : m){
        if(isPrime(i.first)){
            answer++;
        }
    }
    return answer;
}
