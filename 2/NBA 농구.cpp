#include<bits/stdc++.h>
using namespace std;
#define prev jeongwon
string s, prev;
int n, o, A, B, asum, bsum;
string print(int a) {
	string d = "00" + to_string(a/60);
	string z = "00" + to_string(a % 60);
	return d.substr(d.size() - 2, 2) + ":" + z.substr(z.size() - 2, 2);
}
int changeToInt(string a) {
	return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}
void go(int& sum, string s) {
	sum += (changeToInt(s) - changeToInt(prev));
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> o >> s;
		if (A > B) go(asum, s);
		else if (B > A) go(bsum, s);
		o == 1 ? A++ : B++;
		prev = s;
	}
	if (A > B) go(asum, "48:00");
	else if (A < B)go(bsum, "48:00");
	cout << print(asum) << "\n";
	cout << print(bsum) << "\n";
}