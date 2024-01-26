#include<bits/stdc++.h>
using namespace std;
//antic
int n, k;
int words[50];
string s;

int check(int mask) {
	int cnt = 0;
	for (int word : words) {
		if (word && (mask & word) == word) { cnt++; }
	}
	return cnt;
}
int go(int index, int m, int mask) {
	if (m < 0) return 0;
	if (index == 26) return check(mask);
	int ret=go(index + 1, m - 1, mask | (1<<index)); // mask |= (1<<index) 할당하면 안됨
	if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a') {
		ret = max(ret, go(index + 1, m, mask));
	}
	return ret;
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (char str : s) {
			words[i] |= (1 << str - 'a');
		}
	}
	cout << go(0, k , 0)<<"\n";
}