#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, N, M;
int a[1000004], b[1000004];
bool go(int lo, int hi, int k) {
	if (!(lo <= hi))return false;
	int mid = (lo + hi) / 2;
	if (a[mid] == k)return true;
	if(a[mid]<k) return go(mid+1, hi, k);
	else return go(lo, mid-1, k);
}
int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> b[i];
		}
		sort(a, a + N);

		for (int i = 0; i < M; i++) {
			int lo = 0;
			int hi = N - 1;
			if (go(lo, hi, b[i]))cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		fill(a, a+N,0);
		fill(b, b + M, 0);
	}
}