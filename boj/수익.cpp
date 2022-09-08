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
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	while (1) {
		cin >> n;
		if (n == 0)break;

		int sum = 0;
		int ans = -987654321;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if (sum + num > num) {
				sum += num;
			}
			else {
				sum = num;
			}
			ans = max(ans, sum);
		}
		cout << ans << '\n';
	}
}
