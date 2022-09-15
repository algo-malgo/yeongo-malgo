#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <regex>
#include <map>
#include <cmath>
#include <memory.h>
using namespace std;
int n;
string s;
stack<double>st;
map<char, int>m;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> m['A' + i];
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '*' || s[i] == '-' || s[i] == '/') {
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();

			if (s[i] == '+') {
				st.push(a + b);
			}
			else if (s[i] == '-') {
				st.push(b - a);
			}
			else if (s[i] == '*') {
				st.push(a * b);
			}
			else if (s[i] == '/') {
				st.push(b / a);
			}
		}
		else {
			st.push(m[s[i]]);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << st.top() << '\n';
}
