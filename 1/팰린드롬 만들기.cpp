#include <bits/stdc++.h>
using namespace std;
string str,ret;
char mid;
int cnt[200],flag;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	for (char c : str) {
		cnt[c]++;
	}
	for (int i = 'Z'; 'A'<= i; i--) {
		if (cnt[i]) {
			if (cnt[i] & 1) {
				mid = char(i);flag++;
				cnt[i]--;
			}
			if (flag == 2)break;
			for (int j = 0; j < cnt[i]; j += 2) {
				ret = char(i) + ret;
				ret += char(i);
			}
		}
	}
	if (mid) {
		ret.insert(ret.begin() + ret.size() / 2, mid);
	}
	if (flag == 2) {
		cout << "I'm Sorry Hansoo\n";
	}
	else {
		cout << ret << "\n";
	}

}