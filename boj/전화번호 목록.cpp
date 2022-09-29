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
int tc, n;
bool solve(vector<string>v) {
	map<string, int>m;
	for (int i = 0; i < v.size(); i++) {
		m[v[i]] = 1;
	}
	for (int i = 0; i < v.size(); i++) {
		string tmp = "";
		for (int j = 0; j < v[i].size() - 1; j++) {
			tmp = v[i].substr(0, j + 1);
			if (m[tmp])return false;
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> tc;
	while (tc--) {
		cin >> n;
		vector<string>v;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			v.push_back(s);
		}
		bool flag = solve(v);
		flag ? cout << "YES\n" : cout << "NO\n";
	}
}
