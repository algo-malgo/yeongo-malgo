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
int arr[101][101] = { 0, };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visit[101][101] = { false, };
void bfs() {
	queue<pair<int, int>>q;
	q.push({ 0,0 });
	visit[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n&&ny < m && arr[nx][ny] != 0 && !visit[nx][ny]) {
				q.push({ nx,ny });
				arr[nx][ny] = arr[x][y] + 1;
				visit[nx][ny] = true;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	bfs();
	cout << arr[n - 1][m - 1] << '\n';
}
