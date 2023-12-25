#include<bits/stdc++.h>
using namespace std;
int n,m;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		int ret2 = 0, ret5 = 0;
		for (int j = 2; j <= m; j*=2) {
			ret2 += m / j;
		}
		for (int j = 5; j <= m; j *= 5) {
			ret5 += m / j;
		}
		cout << min(ret2, ret5) << "\n";
	}
}