#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, n, m,a,cnt;
vector<ll>v1, v2;
bool check(int i,ll mid) {
	if (v1[i] <= v2[mid])return false;
	return true;
}
int main() {
	cin >> T;
	while (T--) {
		int ret = 0;
		cin >> n >> m;
		vector<int>a(n), b(m);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++)cin >> b[i];
		sort(b.begin(), b.end());
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
			auto pos = lower_bound(b.begin(), b.end(), a[i]);
			ret += (int)(pos - b.begin());
		}
		cout << ret << "\n";
	}
}