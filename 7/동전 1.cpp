#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, k, dp[10001], temp,cnt;
int main() {
	cin >> n >> k;
	fill(dp, dp + 10001, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = temp; j <= k; j++) {
			dp[j] +=dp[j - temp];
		}
	}
	cout << dp[k] << "\n";
}