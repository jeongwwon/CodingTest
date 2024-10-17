#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int s, c, ret;
ll a[1000004],mid,ch,sum;
bool check(ll mid) {
	ll cnt = 0;
	for (int i = 0; i < s; i++) {
		cnt += a[i] / mid;
	}
	return c<=cnt;
}
int main() {
	cin >> s >> c;
	for (int i = 0; i < s; i++) {
		cin >> a[i];
		sum += a[i];
	}
	ll lo = 1;
	ll hi = 1e9 + 4;
	while (lo<=hi) {
		mid = (lo + hi) / (1LL*2);
		if (check(mid)) {
			ch = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	cout << sum-ch*c << "\n";
}