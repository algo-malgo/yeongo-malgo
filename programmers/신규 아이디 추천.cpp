#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

string solution(string new_id) {
    // 1단계
    for(int i=0;i<new_id.size();i++){
        new_id[i] = tolower(new_id[i]);
    }
    // 2단계
    for(int i=0;i<new_id.size();){
        char c = new_id[i];
        if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '-' || c == '_' || c == '.'){
            i++;
        }
        else{
            new_id.erase(i,1);
        }
    }
    // 3단계
    for(int i=0;i<new_id.size();){
        if(new_id[i] == '.' && new_id[i+1] == '.'){
            while(new_id[i+1] == '.'){
                new_id.erase(i+1,1);
            }
        }else{
            i++;
        }
    }
    // 4단계
    if(new_id[0] == '.'){
        new_id.erase(0,1);
    }
    if(new_id[new_id.size()-1] == '.'){
        new_id.erase(new_id.size()-1,1);
    }
    // 5단계
    if(new_id.size() == 0){
        new_id = 'a';
    }
    // 6단계
    if(new_id.size() >= 16){
        new_id = new_id.substr(0,15);
        if(new_id[new_id.size()-1] == '.'){
            new_id.erase(new_id.size()-1,1);
        }
    }
    // 7단계
    if(new_id.size() <= 2){
        while(new_id.size() != 3){
            new_id += new_id[new_id.size()-1];
        }
    }
    return new_id;
}
