#include<bits/stdc++.h>
using namespace std;
int n,m,a[100004],mx,sum,ret=987654321;
bool check(int sum) {
	int temp = sum;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (sum - a[i] < 0) {
			sum = temp;
			cnt++;
		}
		sum -= a[i];
	}
	if (temp != sum)cnt++;
	return cnt <= m;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		sum += a[i];
	}
	int lo = 1;
	int hi = sum;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (check(mid)) {
			ret = min(ret, mid);
			lo = 1;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ret << "\n";
}