#include<bits/stdc++.h>
using namespace std;

int ret = 987654321;
string s;

int solution(int cnt) {
	int idx = 0, leng = 1;
	string compressed = "", prev = s.substr(0, cnt);
	for (idx = cnt; idx < s.size(); idx += cnt) {
		string current = s.substr(idx, cnt);
		if (prev == current) {
			leng++;
		}
		else {
			if (leng > 1) compressed += to_string(leng);
			compressed += prev;
			prev = current;
			leng = 1;
		}
	}
	if (leng > 1) compressed += to_string(leng);
	compressed += prev;

	if (idx < s.size()) {
		compressed += s.substr(idx);
	}
	return compressed.size();
}
int main() {
	cin >> s;
	for (int i = 1; i < s.size(); i++) {
		ret = min(ret, solution(i));
	}
	cout << ret << "\n";
}