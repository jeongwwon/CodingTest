#include<bits/stdc++.h>
using namespace std;
int n,a,b,sum;
vector<pair<int, int>>v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	int fir = v[0].first;
	int sec = v[0].second;
	for (int i = 1; i < n; i++) {
		if (v[i].first <= sec) {
			sec = v[i].second;
		}
		else {
			sum += sec - fir;
			fir = v[i].first;
			sec = v[i].second;
		}
	}
	sum += sec - fir;
	cout << sum << "\n";
}