#include<bits/stdc++.h>
using namespace std;
int n,ret=1,a,b;
vector<pair<int, int>>v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ b,a });
	}
	sort(v.begin(), v.end());
	int to = v[0].first;
	int from = v[0].second;
	for (int i = 1; i < n; i++) {
		if (v[i].second < to)continue;
		else {
			from = v[i].second;
			to = v[i].first;
			ret++;
		}
	}
	cout << ret << "\n";
}