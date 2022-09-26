#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0;i<prices.size();i++){
        int cur = prices[i];
        bool flag = false;
        for(int j=i + 1;j<prices.size();j++){
            int next = prices[j];
            
            if(cur > next){
                answer.push_back(j - i);
                flag = true;
                break;
            }
        }
        if(!flag){
            answer.push_back(prices.size() - i - 1);
        }
    }
    return answer;
}
