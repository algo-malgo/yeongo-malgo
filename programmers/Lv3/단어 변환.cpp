#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool visit[51]={false,};
int answer = 987654321;
bool checkWord(string cur,string next){
    int cnt = 0;
    for(int i=0;i<cur.size();i++){
        if(cnt > 1)return false;
        if(cur[i] != next[i]){
            cnt++;
        }
    }
    if(cnt == 1)return true; // 딱 한 문자만 달라야 함
    return false; // cur과 똑같은 문자를 여기서 걸러줌
}
void dfs(string target, vector<string> words,string cur,int cnt){
    if(cur == target){
        if(answer > cnt){
            answer = cnt;
        }
        return;
    }
    for(int i=0;i<words.size();i++){
        if(!visit[i]){
            string tmp = "";
            if(checkWord(cur,words[i]) && !visit[i]){
                tmp = words[i];
            }
            if(tmp == "")continue;
            visit[i] = true;
            dfs(target,words,tmp,cnt+1);
            visit[i] = false;
        }
    }
    return;
}
int solution(string begin, string target, vector<string> words) {
    dfs(target,words,begin,0);
    if(answer == 987654321)return 0;
    return answer;
}
