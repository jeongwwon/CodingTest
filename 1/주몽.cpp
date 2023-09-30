#include<bits/stdc++.h>
using namespace std;
int arr[15000];
int n, m,q;
int cnt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	if (m >= 200000) {
		cout << 0 << "\n";
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> q;
			arr[i] = q;
		}
		for (int i = 0; i < n-1; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((arr[i] + arr[j]) == m) {
					cnt++;
				}
			}
		}
		cout << cnt;
	}
	return 0;
}