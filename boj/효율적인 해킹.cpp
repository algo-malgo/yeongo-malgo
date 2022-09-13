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
int n, m;
vector<int>v[10001];
bool visit[10001] = { false, };
int ans = 0;
int cnt = 0;
vector<pair<int, int>>com;
void dfs(int cur) {
	visit[cur] = true;
	cnt++;
	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (!visit[next]) {
			dfs(next);
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a); // b를 해킹하면 a도 해킹할 수 있음
	}
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		dfs(i);
		if (cnt >= ans) {
			ans = cnt;
			com.push_back({ i,cnt });
		}
		memset(visit, false, sizeof(visit));
	}
	sort(com.begin(), com.end());
	for (int i = 0; i < com.size(); i++) {
		if (ans == com[i].second) {
			cout << com[i].first << ' ';
		}
	}
}
