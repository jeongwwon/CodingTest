#include<bits/stdc++.h>
using namespace std;
int n, s[12], a, b, c, d;
int ret = -1000000001;
int ret2 = 1000000001;
vector<int>v;
int go2(int start, int end, int num) {
	if (num == 0) return start + s[end];
	if (num == 1) return start - s[end];
	if (num == 2) return start * s[end];
	if (num == 3) return start / s[end];
	return 0;
}
void go(int num, int end) {
	if (end == n) {
		ret = max(ret, num);
		ret2 = min(ret2, num);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (v[i]) {
			d = go2(num, end, i);
			v[i]--;
			go(d, end + 1);
			v[i]++;
		}
		else continue;
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	cin >> a >> b >> c >> d;
	v.push_back(a); v.push_back(b); v.push_back(c); v.push_back(d);

	go(s[0], 1);
	cout << ret << "\n" << ret2 << "\n";
}