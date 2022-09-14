#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    for(int i=3;i<=total/2;i++){
        int a = i; // 가로
        int b = total / a; // 세로
        
        // 딱 나누어떨어지지 않으면 패스
        if(total % a != 0)continue;
        // 세로가 가로보다 길면 패스
        if(b > a)continue;
        
        int y = (a - 2) * (b - 2);
        if(y == yellow){
            answer.push_back(a);
            answer.push_back(b);
            break;
        }
    }    
    return answer;
}
