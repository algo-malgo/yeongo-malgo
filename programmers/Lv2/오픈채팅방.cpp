#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;
map<string,string>m;
vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(int i=0;i<record.size();i++){
        stringstream ss;
        ss.str(record[i]);
        string status, id, nickname;
        ss >> status >> id >> nickname;
        if(status == "Enter"){
            m[id] = nickname;
        }else if(status == "Change"){
            m[id] = nickname;
        }
    }
    for(int i=0;i<record.size();i++){
        stringstream ss;
        ss.str(record[i]);
        string status, id, nickname;
        ss >> status >> id >> nickname;
        
        if(status == "Enter"){
            answer.push_back(m[id] + "님이 들어왔습니다.");
        }else if(status == "Leave"){
            answer.push_back(m[id] + "님이 나갔습니다.");
        }
    }
    return answer;
}
