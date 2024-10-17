#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, y,z,ret=-1;
int main() {
	cin >> x >> y;
	z =y*100 / x;
	ll lo = 1;
	ll hi = 1e9 + 4;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if ((y+mid)*100/(x+mid)>z) {
			hi = mid - 1;
			ret = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ret << "\n";
}