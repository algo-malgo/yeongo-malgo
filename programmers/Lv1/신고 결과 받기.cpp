#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string,vector<string>>m;
    map<string,int>report_m;
    
    for(int i=0;i<report.size();i++){
        stringstream ss;
        ss.str(report[i]);
        string user1,user2;
        ss >> user1 >> user2;
        
        auto it = find(m[user1].begin(),m[user1].end(),user2);
        if(it == m[user1].end()){
            // not exist
            m[user1].push_back(user2);
            report_m[user2]++;
        }
    }
    for(int i=0;i<id_list.size();i++){
        string id = id_list[i];
        int cnt = 0;
        for(int j=0;j<m[id].size();j++){
            if(report_m[m[id][j]] >= k){
                cnt++;
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}
