#include<bits/stdc++.h>
using namespace std;
int n, m,a[200001],b[200001],cnt1,cnt2;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	for (int i = 0; i < n; i++) {
		int lo = 0;
		int hi = m - 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (b[mid] == a[i]) {
				cnt1++;
				break;
			}
			else if (b[mid] < a[i]) {
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}
	}
	for (int j = 0; j < m; j++) {
		int lo = 0;
		int hi = n - 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (a[mid] == b[j]) {
				cnt2++;
				break;
			}
			else if (a[mid] < b[j]) {
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}
	}
	cout << (n - cnt1) + (m - cnt2) << "\n";
}