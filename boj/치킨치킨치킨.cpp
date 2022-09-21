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
int ans = 0;
int sum = 0;
int arr[31][31] = { 0, };
vector<int>v;
bool visit[31] = { false, };
void solve(int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < n; i++) {
			int tmp = 0;
			for (int j = 0; j < m; j++) {
				if (visit[j]) {
					if (arr[i][j] > tmp) {
						tmp = arr[i][j];
					}
				}
			}
			sum += tmp;
		}
		ans = max(ans, sum);
		sum = 0;
		return;
	}
	for (int i = 0; i < m; i++) {
		if (!visit[i]) {
			visit[i] = true;
			v.push_back(i);
			solve(cnt + 1);
			v.pop_back();
			visit[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	solve(0);
	cout << ans << '\n';
}
