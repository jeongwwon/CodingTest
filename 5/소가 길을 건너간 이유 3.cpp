#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>>v;
int n,a,b;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	int maxi=v[0].first + v[0].second;
	for (int i = 1; i < n; i++) {
		if (v[i].first < maxi) {
			maxi += v[i].second;
		}
		else {
			maxi = v[i].first + v[i].second;
		}
	}
	cout << maxi << "\n";
}