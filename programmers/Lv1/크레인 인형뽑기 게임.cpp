#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
stack<int>st;
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    for(int i=0;i<moves.size();i++){
        int target = moves[i];
        
        for(int j=0;j<board.size();j++){
            if(!board[j][target-1])continue;
            if(!st.empty() && st.top() == board[j][target-1]){
                st.pop();
                answer += 2;
            }else if(st.empty() || st.top() != board[j][target-1]){
                st.push(board[j][target-1]);
            }
            board[j][target-1] = 0;
            break;
        }
    }
    return answer;
}
