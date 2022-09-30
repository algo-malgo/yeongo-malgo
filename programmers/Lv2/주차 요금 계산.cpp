#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <cmath>

using namespace std;
map<string,vector<pair<int,string>>>m; // 차량번호, [총 시간, 입출차 상태]
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for(int i=0;i<records.size();i++){
        stringstream ss;
        ss.str(records[i]);
        
        string time, car_number, status;
        ss >> time >> car_number >> status;
        
        int ttime = 60 * stoi(time.substr(0,2)) + stoi(time.substr(3));
        
        m[car_number].push_back({ttime,status});
    }
    for(auto car : m){
        string car_number = car.first;
        int tmp_time = 0;
        bool flag = false; // 출차하면 true
        vector<int>v;
        
        for(int i=0;i<m[car_number].size();i++){
            int t = m[car_number][i].first;
            string status = m[car_number][i].second;
            
            if(status == "IN"){
                tmp_time += t;
                flag = false;
            }else{
                tmp_time = abs(tmp_time - t);
                flag = true;
                v.push_back(tmp_time);
                tmp_time = 0;
            }
        }
        if(!flag){ // 23:59
            tmp_time = abs(tmp_time - 1439);
            v.push_back(tmp_time);
        }
        double total_time = 0;
        for(int i=0;i<v.size();i++){
            total_time += v[i];
        }
        if(total_time <= fees[0]){
            answer.push_back(fees[1]);
        }else
            answer.push_back(fees[1] + ceil((total_time - fees[0]) / fees[2]) * fees[3]);
        }
    }
    return answer;
}
