#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char,int>m;
    
    for(int i=0;i<survey.size();i++){
        char a = survey[i][0];
        char b = survey[i][1];
        
        if(choices[i] < 4){
            m[a] += 4 - choices[i];
        }else if(choices[i] > 4){
            m[b] += choices[i] - 4;
        }
    }
    answer += m['R'] >= m['T'] ? 'R' : 'T';
    answer += m['C'] >= m['F'] ? 'C' : 'F';
    answer += m['J'] >= m['M'] ? 'J' : 'M';
    answer += m['A'] >= m['N'] ? 'A' : 'N';
    
    return answer;
}
