#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string>v;
    
    for(auto city : cities){
        if(cacheSize == 0){
            answer += 5;
            continue;
        }
        for(int i=0;i<city.size();i++){
            if(city[i] >= 'A' && city[i] <= 'Z'){
                city[i] += 32;
            }
        }
        
        if(v.size() == cacheSize){
            if(find(v.begin(),v.end(),city) != v.end()){ // hit
                auto it = find(v.begin(),v.end(),city)-v.begin();
                v.erase(v.begin() + it);
                v.push_back(city);
                answer += 1;
            }else{ // miss
                v.erase(v.begin());
                v.push_back(city);
                answer += 5;
            }
        }else{
            if(v.size() > 0){
                if(find(v.begin(),v.end(),city) != v.end()){ // hit
                    auto it = find(v.begin(),v.end(),city)-v.begin();
                    v.erase(v.begin() + it);
                    v.push_back(city);
                    answer += 1;
                }else{ // miss
                    v.push_back(city);
                    answer += 5;
                }
            }else{
                v.push_back(city);
                answer += 5;
            }
        }
    }
    return answer;
}
