#include <string>
#include <vector>

using namespace std;
string changeBinary(int n){
    string str = "";
    while(n != 1){
        str += to_string(n % 2);
        n /= 2;
    }
    str += '1';
    reverse(str.begin(),str.end());
    return str;
}
vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int zero = 0;
    while(s != "1"){
        for(int i=0;i<s.size();){
            if(s[i] == '0'){
                zero++;
                s.erase(i,1);
            }
            else{
                i++;
            }
        }
        s = changeBinary(s.size());
        cnt++;
    }
    answer.push_back(cnt);
    answer.push_back(zero);
    return answer;
}
