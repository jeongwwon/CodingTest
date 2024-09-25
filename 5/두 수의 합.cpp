#include<bits/stdc++.h>

using namespace std;
long long l, r,n,x,ret;
int main() {
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cin >> x;
	r = n - 1;
	while (l < r) {
		if (a[l] + a[r] == x) { 
			ret++;
			r--;
			l++;
		}
		else if (a[l] + a[r] < x) {
			l++;
		}
		else {
			r--;
		}
	}
	cout << ret << "\n";
}