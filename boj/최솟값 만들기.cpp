#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
    return a > b;
}
int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),cmp);

    long long sum = 0;
    for(int i=0;i<A.size();i++){
        sum += A[i] * B[i];
    }
    return sum;
}
