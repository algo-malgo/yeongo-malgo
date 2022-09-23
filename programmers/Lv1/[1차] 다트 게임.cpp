#include <string>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int cur = 0;
    int prev = 0;
    for(int i=0;i<dartResult.size();i++){
        int r = dartResult[i];
        
        if(r >= '0' && r <= '9'){
            prev = cur;
            
            if(dartResult[i+1] == '0'){
                cur = 10;
                i++;
            }else{
                cur = r - '0';
            }
        }
        else if(r == 'S' || r == 'D' || r == 'T'){
            if(r == 'D'){
                cur = pow(cur,2);
            }else if(r == 'T'){
                cur = pow(cur,3);
            }
            
            if(dartResult[i+1] == '*' || dartResult[i+1] == '#'){
                if(dartResult[i+1] == '*'){
                    answer -= prev;
                    prev *= 2;
                    cur *= 2;
                    answer += prev;
                }else if(dartResult[i+1] == '#'){
                    cur *= -1;
                }
                i++;
            }
            answer += cur;
        }
    }
    return answer;
}
