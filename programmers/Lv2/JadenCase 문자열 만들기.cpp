#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    for(int i=0;i<s.size();i++){
        if(i == 0)s[i] = toupper(s[i]);
        else if(s[i] == ' ')s[i+1] = toupper(s[i+1]);
        else if(s[i-1] == ' ')continue;
        else s[i] = tolower(s[i]);
    }
    return s;
}
