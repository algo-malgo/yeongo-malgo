#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero_cnt = 0;
    int correct_cnt = 0;
    for(int i=0;i<lottos.size();i++){
        if(lottos[i] == 0)zero_cnt++;
    }
    for(int i=0;i<6;i++){
        auto it = find(win_nums.begin(),win_nums.end(),lottos[i]);
        if(it != win_nums.end()){
            correct_cnt++;
        }
    }
    
    zero_cnt + correct_cnt < 2 ? answer.push_back(6) : answer.push_back(7 - (zero_cnt + correct_cnt));
    correct_cnt < 2 ? answer.push_back(6) : answer.push_back(7 - correct_cnt);
    return answer;
}
