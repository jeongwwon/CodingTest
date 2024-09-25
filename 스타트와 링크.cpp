#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n,s[21][21],ret=INF;
int go(vector<int>& a, vector<int>& b) {
	pair<int, int>p;
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			if (i == j)continue;
			p.first += s[a[i]][a[j]];
			p.second += s[b[i]][b[j]];
		}   
	}
	return abs(p.first - p.second);
}
bool count(int x, int num) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (x & (1 << i))count++;
	}
	if (count == num)return true;
	else return false;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	for (int i = 0; i < (1 << n); i++) {
		if (!count(i, n / 2))continue;
		vector<int>start, link;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j))start.push_back(j);
			else link.push_back(j);
		}
		ret=min(ret,go(start, link));
	}
	cout << ret << "\n";
}