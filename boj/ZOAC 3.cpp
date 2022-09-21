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
char sl, sr;
string str;
map<char,pair<int,int>>m;
bool isVowel(char c) {
	if (c == 'y' || c == 'u' || c == 'i' || c == 'o' || c == 'p' || c == 'h' || c == 'j' || c == 'k' || c == 'l' || c == 'b' || c == 'n' || c == 'm') {
		return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> sl >> sr >> str;
	m['z'] = {0,0};
	m['x'] = {0,1};
	m['c'] = {0,2};
	m['v'] = {0,3};
	m['b'] = {0,4};
	m['n'] = {0,5};
	m['m'] = {0,6};

	m['a'] = {1,0};
	m['s'] = {1,1};
	m['d'] = {1,2};
	m['f'] = {1,3};
	m['g'] = {1,4};
	m['h'] = {1,5};
	m['j'] = {1,6};
	m['k'] = {1,7};
	m['l'] = { 1,8 };

	m['q'] = {2,0};
	m['w'] = {2,1};
	m['e'] = {2,2};
	m['r'] = {2,3};
	m['t'] = {2,4};
	m['y'] = {2,5};
	m['u'] = {2,6};
	m['i'] = {2,7};
	m['o'] = {2,8};
	m['p'] = {2,9};

	pair<int, int>cl = m[sl];
	pair<int, int>cr = m[sr];

	int ans = 0;

	for (int i = 0; i < str.size(); i++) {
		pair<int, int>p;
		p = m[str[i]]; // 가야할 곳
		if (isVowel(str[i])) { // 모음인 경우
			ans += abs(cr.first - p.first) + abs(cr.second - p.second) + 1;
			cr = p;
		}
		else {
			ans += abs(cl.first - p.first) + abs(cl.second - p.second) + 1;
			cl = p;
		}
	}
	cout << ans << '\n';
}
