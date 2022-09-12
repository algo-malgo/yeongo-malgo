#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <regex>
#include <map>
#include <memory.h>
using namespace std;
int n;
int arr[21][21];
bool visit[21] = { false, };
int ans = 987654321;
void solve(int cnt,int idx) {
	if (cnt == n / 2) {
		int start = 0, link = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (visit[i] && visit[j]) {
					start += arr[i][j] + arr[j][i];
				}
				else if (!visit[i] && !visit[j]) {
					link += arr[i][j] + arr[j][i];
				}
			}
		}
		ans = min(ans, abs(start - link));
		return;
	}
	for (int i = idx; i < n; i++) {
		visit[i] = true;
		solve(cnt + 1, i + 1);
		visit[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve(0, 0);
	cout << ans << '\n';
}
