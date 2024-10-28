#include<bits/stdc++.h>
using namespace std;
int n, m, c, y, x, a[51][51], dp[51][51][51][51];
const int mod = 1000007;
int go(int y, int x, int cnt, int prev) {
	if (y > n || x > m) return 0;
	if (y == n && x == m) {
		if (cnt == 0 && a[y][x] == 0) return 1; // 방문할 cnt를 다 소진하고 배열 값이 오락실이 아닌경우
		if (cnt == 1 && a[y][x] > prev) return 1; // 방문할 cnt가 1개 남아있고(지금 소진) 배열값이 전에 방문한 값보다 큰 경우
		return 0;
	}
	int& ret = dp[y][x][cnt][prev];
	if (ret != -1) return ret;
	ret = 0;
	if (a[y][x] == 0) {
		ret = (go(y + 1, x, cnt, prev) + go(y, x + 1, cnt, prev)) % mod;
	}
	else if (a[y][x] > prev) {
		ret = (go(y + 1, x, cnt - 1, a[y][x]) + go(y, x + 1, cnt - 1, a[y][x])) % mod;
	}
	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> c;
	for (int i = 1; i <= c; i++) {
		cin >> y >> x;
		a[y][x] = i;
	}
	for (int i = 0; i <= c; i++) {
		cout << go(1, 1, i, 0) << " ";
	}
}